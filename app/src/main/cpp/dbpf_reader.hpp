#pragma once

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace spore {

struct Tgi {
    std::uint32_t type{};
    std::uint32_t group{};
    std::uint32_t instance{};

    bool operator==(const Tgi& other) const noexcept {
        return type == other.type && group == other.group &&
               instance == other.instance;
    }
};

struct DbpfEntry {
    Tgi key;
    std::uint64_t offset{};
    std::uint32_t stored_size{};
    std::uint32_t memory_size{};
    std::uint16_t compression{};
    bool saved{};

    bool is_compressed() const noexcept { return compression == 0xFFFF; }
};

struct DbpfHeader {
    std::uint32_t major_version{};
    std::uint32_t minor_version{};
    std::uint32_t entry_count{};
    std::uint32_t index_size{};
    std::uint32_t index_minor_version{};
    std::uint64_t index_offset{};
};

class DbpfPackage {
public:
    explicit DbpfPackage(const std::filesystem::path& path);

    const DbpfHeader& header() const noexcept { return header_; }
    const std::vector<DbpfEntry>& entries() const noexcept { return entries_; }
    const std::filesystem::path& path() const noexcept { return path_; }

    std::vector<std::uint8_t> read_entry(
        std::size_t entry_index,
        std::uint64_t max_output_bytes = 512ULL * 1024ULL * 1024ULL);

    std::size_t find(const Tgi& key) const noexcept;

private:
    std::vector<std::uint8_t> read_at(std::uint64_t offset, std::size_t size);
    void parse();

    std::filesystem::path path_;
    std::ifstream file_;
    std::uint64_t file_size_{};
    DbpfHeader header_;
    std::vector<DbpfEntry> entries_;
};

std::vector<std::uint8_t> decompress_refpack(
    const std::vector<std::uint8_t>& input,
    std::uint64_t expected_size,
    std::uint64_t max_output_bytes = 512ULL * 1024ULL * 1024ULL);

std::uint32_t fnv1_ascii_lower(const std::string& text);
std::uint32_t fnv1a_ascii_lower(const std::string& text);
std::string hex32(std::uint32_t value);

}  // namespace spore
