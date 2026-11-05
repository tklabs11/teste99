#include "dbpf_reader.hpp"

#include <algorithm>
#include <array>
#include <limits>
#include <sstream>
#include <stdexcept>

namespace spore {
namespace {

constexpr std::size_t kDbpfHeaderSize = 0x60;
constexpr std::uint32_t kMaxEntries = 0x7FFFFFFF;
constexpr std::uint32_t kKnownIndexFlags = 0x7;
constexpr std::uint16_t kUncompressed = 0;
constexpr std::uint16_t kRefPack = 0xFFFF;

std::uint16_t read_u16(const std::vector<std::uint8_t>& bytes,
                       std::size_t offset) {
    if (offset > bytes.size() || bytes.size() - offset < 2) {
        throw std::runtime_error("truncated 16-bit field");
    }
    return static_cast<std::uint16_t>(bytes[offset]) |
           (static_cast<std::uint16_t>(bytes[offset + 1]) << 8);
}

std::uint32_t read_u32(const std::vector<std::uint8_t>& bytes,
                       std::size_t offset) {
    if (offset > bytes.size() || bytes.size() - offset < 4) {
        throw std::runtime_error("truncated 32-bit field");
    }
    return static_cast<std::uint32_t>(bytes[offset]) |
           (static_cast<std::uint32_t>(bytes[offset + 1]) << 8) |
           (static_cast<std::uint32_t>(bytes[offset + 2]) << 16) |
           (static_cast<std::uint32_t>(bytes[offset + 3]) << 24);
}

std::uint64_t read_u64(const std::vector<std::uint8_t>& bytes,
                       std::size_t offset) {
    const auto low = read_u32(bytes, offset);
    const auto high = read_u32(bytes, offset + 4);
    return static_cast<std::uint64_t>(low) |
           (static_cast<std::uint64_t>(high) << 32);
}

std::uint32_t read_be_u24(const std::vector<std::uint8_t>& bytes,
                          std::size_t offset) {
    if (offset > bytes.size() || bytes.size() - offset < 3) {
        throw std::runtime_error("truncated RefPack 24-bit size");
    }
    return (static_cast<std::uint32_t>(bytes[offset]) << 16) |
           (static_cast<std::uint32_t>(bytes[offset + 1]) << 8) |
           static_cast<std::uint32_t>(bytes[offset + 2]);
}

std::uint32_t read_be_u32(const std::vector<std::uint8_t>& bytes,
                          std::size_t offset) {
    if (offset > bytes.size() || bytes.size() - offset < 4) {
        throw std::runtime_error("truncated RefPack 32-bit size");
    }
    return (static_cast<std::uint32_t>(bytes[offset]) << 24) |
           (static_cast<std::uint32_t>(bytes[offset + 1]) << 16) |
           (static_cast<std::uint32_t>(bytes[offset + 2]) << 8) |
           static_cast<std::uint32_t>(bytes[offset + 3]);
}

std::uint8_t read_byte(const std::vector<std::uint8_t>& input,
                       std::size_t& cursor) {
    if (cursor >= input.size()) {
        throw std::runtime_error("truncated RefPack command stream");
    }
    return input[cursor++];
}

std::uint32_t ascii_lower(std::uint8_t c) {
    if (c >= 'A' && c <= 'Z') {
        return static_cast<std::uint32_t>(c - 'A' + 'a');
    }
    if (c >= 0x80) {
        throw std::invalid_argument(
            "hash helpers accept ASCII only; Unicode case folding is unverified");
    }
    return c;
}

}  // namespace

std::vector<std::uint8_t> decompress_refpack(
    const std::vector<std::uint8_t>& input,
    std::uint64_t expected_size,
    std::uint64_t max_output_bytes) {
    if (expected_size > max_output_bytes ||
        expected_size > static_cast<std::uint64_t>(
                            std::numeric_limits<std::size_t>::max())) {
        throw std::runtime_error("RefPack output exceeds configured limit");
    }
    if (input.size() < 5) {
        throw std::runtime_error("RefPack input shorter than header");
    }
    if (input[1] != 0xFB) {
        throw std::runtime_error("unsupported RefPack signature");
    }

    std::size_t cursor = 2;
    std::uint64_t declared_size = 0;
    if (input[0] == 0x10 || input[0] == 0x50) {
        declared_size = read_be_u24(input, cursor);
        cursor += 3;
    } else if (input[0] == 0x90) {
        declared_size = read_be_u32(input, cursor);
        cursor += 4;
    } else {
        throw std::runtime_error("unsupported RefPack header mode");
    }
    if (declared_size != expected_size) {
        throw std::runtime_error("RefPack header size differs from DBPF index");
    }

    std::vector<std::uint8_t> output;
    output.reserve(static_cast<std::size_t>(expected_size));
    std::size_t command_count = 0;

    while (output.size() < expected_size) {
        if (++command_count > input.size()) {
            throw std::runtime_error("RefPack command-count limit exceeded");
        }

        const std::uint8_t control = read_byte(input, cursor);
        std::size_t literals = 0;
        std::size_t copy_length = 0;
        std::size_t copy_offset = 0;

        if (control >= 0xFC) {
            literals = control & 0x03;
        } else if (control >= 0xE0) {
            literals = ((control & 0x1F) << 2) + 4;
        } else if (control >= 0xC0) {
            const auto first = read_byte(input, cursor);
            const auto second = read_byte(input, cursor);
            const auto third = read_byte(input, cursor);
            literals = control & 0x03;
            copy_length = ((control & 0x0C) << 6) + third + 5;
            copy_offset = ((control & 0x10) << 12) +
                          (static_cast<std::size_t>(first) << 8) +
                          second + 1;
        } else if (control >= 0x80) {
            const auto first = read_byte(input, cursor);
            const auto second = read_byte(input, cursor);
            literals = (first & 0xC0) >> 6;
            copy_length = (control & 0x3F) + 4;
            copy_offset = ((first & 0x3F) << 8) + second + 1;
        } else {
            const auto next = read_byte(input, cursor);
            literals = control & 0x03;
            copy_length = ((control & 0x1C) >> 2) + 3;
            copy_offset = ((control & 0x60) << 3) + next + 1;
        }

        if (literals > input.size() - cursor ||
            literals > static_cast<std::size_t>(expected_size) - output.size()) {
            throw std::runtime_error("RefPack literal run exceeds input/output");
        }
        output.insert(output.end(), input.begin() + cursor,
                      input.begin() + cursor + literals);
        cursor += literals;

        if (copy_length > static_cast<std::size_t>(expected_size) - output.size()) {
            throw std::runtime_error("RefPack back-reference exceeds output size");
        }
        if (copy_length != 0) {
            if (copy_offset == 0 || copy_offset > output.size()) {
                throw std::runtime_error("invalid RefPack back-reference offset");
            }
            for (std::size_t i = 0; i < copy_length; ++i) {
                output.push_back(output[output.size() - copy_offset]);
            }
        }
    }

    return output;
}

DbpfPackage::DbpfPackage(const std::filesystem::path& path)
    : path_(path), file_(path, std::ios::binary) {
    if (!file_) {
        throw std::runtime_error("cannot open package: " + path.string());
    }
    file_.seekg(0, std::ios::end);
    const auto end = file_.tellg();
    if (end < 0) {
        throw std::runtime_error("cannot determine package size");
    }
    file_size_ = static_cast<std::uint64_t>(end);
    parse();
}

std::vector<std::uint8_t> DbpfPackage::read_at(std::uint64_t offset,
                                               std::size_t size) {
    if (offset > file_size_ || size > file_size_ - offset) {
        throw std::runtime_error("read range exceeds package file");
    }
    if (offset > static_cast<std::uint64_t>(
                     std::numeric_limits<std::streamoff>::max())) {
        throw std::runtime_error("file offset cannot be represented by streamoff");
    }

    std::vector<std::uint8_t> bytes(size);
    file_.clear();
    file_.seekg(static_cast<std::streamoff>(offset), std::ios::beg);
    if (!file_) {
        throw std::runtime_error("seek failed while reading package");
    }
    if (size != 0) {
        file_.read(reinterpret_cast<char*>(bytes.data()),
                   static_cast<std::streamsize>(size));
        if (file_.gcount() != static_cast<std::streamsize>(size)) {
            throw std::runtime_error("short read while reading package");
        }
    }
    return bytes;
}

void DbpfPackage::parse() {
    if (file_size_ < kDbpfHeaderSize) {
        throw std::runtime_error("file is shorter than the DBPF header");
    }
    const auto bytes = read_at(0, kDbpfHeaderSize);
    if (bytes[0] != 'D' || bytes[1] != 'B' ||
        bytes[2] != 'P' || bytes[3] != 'F') {
        throw std::runtime_error("invalid DBPF signature");
    }

    header_.major_version = read_u32(bytes, 4);
    header_.minor_version = read_u32(bytes, 8);
    header_.entry_count = read_u32(bytes, 0x24);
    header_.index_size = read_u32(bytes, 0x2C);
    header_.index_minor_version = read_u32(bytes, 0x3C);
    header_.index_offset = read_u64(bytes, 0x40);

    if (header_.major_version != 3 || header_.minor_version != 0) {
        throw std::runtime_error("only DBPF 3.0 is supported");
    }
    if (header_.entry_count > kMaxEntries) {
        throw std::runtime_error("entry count exceeds supported DBPF limit");
    }
    if (header_.index_offset < kDbpfHeaderSize ||
        header_.index_offset > file_size_ ||
        header_.index_size > file_size_ - header_.index_offset) {
        throw std::runtime_error("DBPF index range exceeds package file");
    }

    const auto index = read_at(header_.index_offset, header_.index_size);
    if (index.size() < 4) {
        throw std::runtime_error("DBPF index header is truncated");
    }
    std::size_t cursor = 0;
    const auto flags = read_u32(index, cursor);
    cursor += 4;
    if ((flags & ~kKnownIndexFlags) != 0) {
        throw std::runtime_error("unknown DBPF index flag bits");
    }

    const bool has_shared_type = (flags & 0x1) != 0;
    const bool has_shared_group = (flags & 0x2) != 0;
    const bool has_unknown_word = (flags & 0x4) != 0;
    std::uint32_t shared_type = 0;
    std::uint32_t shared_group = 0;
    if (has_shared_type) {
        shared_type = read_u32(index, cursor);
        cursor += 4;
    }
    if (has_shared_group) {
        shared_group = read_u32(index, cursor);
        cursor += 4;
    }
    if (has_unknown_word) {
        (void)read_u32(index, cursor);
        cursor += 4;
    }

    const std::uint64_t minimum_entry_bytes =
        20 + (has_shared_type ? 0 : 4) + (has_shared_group ? 0 : 4);
    if (header_.entry_count >
        (index.size() - cursor) / minimum_entry_bytes) {
        throw std::runtime_error("DBPF entry count cannot fit in index");
    }
    entries_.reserve(header_.entry_count);

    for (std::uint32_t i = 0; i < header_.entry_count; ++i) {
        DbpfEntry entry;
        entry.key.type = has_shared_type ? shared_type : read_u32(index, cursor);
        if (!has_shared_type) cursor += 4;
        entry.key.group = has_shared_group ? shared_group : read_u32(index, cursor);
        if (!has_shared_group) cursor += 4;
        entry.key.instance = read_u32(index, cursor);
        cursor += 4;

        entry.offset = read_u32(index, cursor);
        cursor += 4;
        const auto stored_with_flag = read_u32(index, cursor);
        cursor += 4;
        entry.stored_size = stored_with_flag & 0x7FFFFFFF;
        entry.memory_size = read_u32(index, cursor);
        cursor += 4;
        entry.compression = read_u16(index, cursor);
        cursor += 2;
        const auto saved = index[cursor++];
        (void)index[cursor++];
        if (saved > 1) {
            throw std::runtime_error("invalid DBPF saved flag");
        }
        entry.saved = saved != 0;

        if (entry.compression != kUncompressed &&
            entry.compression != kRefPack) {
            throw std::runtime_error("unsupported DBPF compression label");
        }
        if (!entry.is_compressed() &&
            entry.stored_size != entry.memory_size) {
            throw std::runtime_error(
                "uncompressed DBPF entry has inconsistent sizes");
        }
        if (entry.offset < kDbpfHeaderSize ||
            entry.offset > header_.index_offset ||
            entry.stored_size > header_.index_offset - entry.offset) {
            throw std::runtime_error("DBPF resource range exceeds data area");
        }
        entries_.push_back(entry);
    }

    if (cursor != index.size()) {
        throw std::runtime_error("DBPF index has unparsed trailing bytes");
    }
}

std::vector<std::uint8_t> DbpfPackage::read_entry(
    std::size_t entry_index, std::uint64_t max_output_bytes) {
    if (entry_index >= entries_.size()) {
        throw std::out_of_range("DBPF entry index out of range");
    }
    const auto& entry = entries_[entry_index];
    if (entry.memory_size > max_output_bytes) {
        throw std::runtime_error("DBPF entry exceeds configured output limit");
    }
    const auto payload = read_at(entry.offset, entry.stored_size);
    if (!entry.is_compressed()) {
        return payload;
    }
    return decompress_refpack(payload, entry.memory_size, max_output_bytes);
}

std::size_t DbpfPackage::find(const Tgi& key) const noexcept {
    const auto it = std::find_if(entries_.begin(), entries_.end(),
                                 [&key](const DbpfEntry& entry) {
                                     return entry.key == key;
                                 });
    if (it == entries_.end()) {
        return entries_.size();
    }
    return static_cast<std::size_t>(it - entries_.begin());
}

std::uint32_t fnv1_ascii_lower(const std::string& text) {
    std::uint32_t hash = 0x811C9DC5;
    for (const auto raw : text) {
        hash *= 0x01000193;
        hash ^= ascii_lower(static_cast<std::uint8_t>(raw));
    }
    return hash;
}

std::uint32_t fnv1a_ascii_lower(const std::string& text) {
    std::uint32_t hash = 0x811C9DC5;
    for (const auto raw : text) {
        hash ^= ascii_lower(static_cast<std::uint8_t>(raw));
        hash *= 0x01000193;
    }
    return hash;
}

std::string hex32(std::uint32_t value) {
    std::ostringstream stream;
    stream << "0x";
    stream.setf(std::ios::hex, std::ios::basefield);
    stream.fill('0');
    stream.width(8);
    stream << value;
    return stream.str();
}

}  // namespace spore
