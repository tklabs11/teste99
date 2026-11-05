#include <jni.h>

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "dbpf_reader.hpp"
#include "spore_string_table.hpp"

namespace {

constexpr std::uint32_t kImageBase = 0x00400000;
constexpr std::uint32_t kTableAddress = 0x0150c050;
constexpr std::uint32_t kTableCountAddress = 0x013ec430;
constexpr std::uint32_t kUnknownStringAddress = 0x013eecec;
constexpr std::uint32_t kExpectedTableCount = 91;
constexpr std::size_t kMaxImageBytes = 64U * 1024U * 1024U;
constexpr std::size_t kMaxStringBytes = 4096;
constexpr std::uint64_t kMaxDbpfResourceBytes = 64ULL * 1024ULL * 1024ULL;

struct Section {
    std::uint32_t virtual_address;
    std::uint32_t raw_size;
    std::uint32_t raw_offset;
};

using GuestRecord = spore::string_table::Record;

std::uint16_t readU16(const std::vector<std::uint8_t>& bytes, std::size_t offset) {
    if (offset > bytes.size() || bytes.size() - offset < sizeof(std::uint16_t)) {
        throw std::runtime_error("Truncated PE header");
    }
    std::uint16_t value;
    std::memcpy(&value, bytes.data() + offset, sizeof(value));
    return value;
}

std::uint32_t readU32(const std::vector<std::uint8_t>& bytes, std::size_t offset) {
    if (offset > bytes.size() || bytes.size() - offset < sizeof(std::uint32_t)) {
        throw std::runtime_error("Truncated PE data");
    }
    std::uint32_t value;
    std::memcpy(&value, bytes.data() + offset, sizeof(value));
    return value;
}

class SporePe32Image {
public:
    explicit SporePe32Image(std::vector<std::uint8_t> bytes)
        : bytes_(std::move(bytes)) {
        if (bytes_.size() < 64 || readU16(bytes_, 0) != 0x5a4d) {
            throw std::runtime_error("SporeApp.exe has no DOS header");
        }

        const std::size_t pe_offset = readU32(bytes_, 0x3c);
        if (readU32(bytes_, pe_offset) != 0x00004550) {
            throw std::runtime_error("SporeApp.exe has no PE signature");
        }

        const std::size_t file_header = pe_offset + 4;
        const std::uint16_t section_count = readU16(bytes_, file_header + 2);
        const std::uint16_t optional_header_size = readU16(bytes_, file_header + 16);
        const std::size_t optional_header = file_header + 20;
        if (section_count == 0 || section_count > 96
                || optional_header_size < 64
                || readU16(bytes_, file_header) != 0x014c
                || readU16(bytes_, optional_header) != 0x010b
                || readU32(bytes_, optional_header + 28) != kImageBase) {
            throw std::runtime_error("SporeApp.exe is not the supported PE32 image");
        }

        image_size_ = readU32(bytes_, optional_header + 56);
        headers_size_ = readU32(bytes_, optional_header + 60);
        if (image_size_ == 0 || image_size_ > kMaxImageBytes
                || headers_size_ > bytes_.size()) {
            throw std::runtime_error("Invalid PE32 image dimensions");
        }

        const std::size_t section_table = optional_header + optional_header_size;
        if (section_table > bytes_.size()
                || bytes_.size() - section_table
                    < static_cast<std::size_t>(section_count) * 40) {
            throw std::runtime_error("Truncated PE section table");
        }
        sections_.reserve(section_count);
        for (std::size_t index = 0; index < section_count; ++index) {
            const std::size_t section_offset = section_table + index * 40;
            sections_.push_back({
                readU32(bytes_, section_offset + 12),
                readU32(bytes_, section_offset + 16),
                readU32(bytes_, section_offset + 20)
            });
        }
    }

    std::uint32_t readAtAddress(std::uint32_t address) const {
        return readU32(bytes_, fileOffset(address));
    }

    std::string readCString(std::uint32_t address) const {
        std::string value;
        value.reserve(32);
        for (std::size_t index = 0; index < kMaxStringBytes; ++index) {
            const std::uint64_t current =
                static_cast<std::uint64_t>(address) + index;
            if (current > std::numeric_limits<std::uint32_t>::max()) {
                throw std::runtime_error("String address overflow in SporeApp.exe");
            }
            const std::uint8_t character = bytes_[fileOffset(
                static_cast<std::uint32_t>(current))];
            if (character == 0) {
                return value;
            }
            value.push_back(static_cast<char>(character));
        }
        throw std::runtime_error("Unterminated string in SporeApp.exe");
    }

private:
    std::size_t fileOffset(std::uint32_t address) const {
        if (address < kImageBase) {
            throw std::runtime_error("Invalid guest address in SporeApp.exe");
        }
        const std::uint32_t rva = address - kImageBase;
        if (rva < headers_size_ && rva < bytes_.size()) {
            return rva;
        }

        for (const Section& section : sections_) {
            if (rva < section.virtual_address) {
                continue;
            }
            const std::uint32_t delta = rva - section.virtual_address;
            if (delta < section.raw_size) {
                const std::uint64_t offset =
                    static_cast<std::uint64_t>(section.raw_offset) + delta;
                if (offset < bytes_.size()) {
                    return static_cast<std::size_t>(offset);
                }
            }
        }
        throw std::runtime_error("Guest address is not file-backed in SporeApp.exe");
    }

    std::vector<std::uint8_t> bytes_;
    std::vector<Section> sections_;
    std::uint32_t image_size_ = 0;
    std::uint32_t headers_size_ = 0;
};

std::string sporeLookup461520(
    const SporePe32Image& image, std::uint32_t key) {
    const std::uint32_t count = image.readAtAddress(kTableCountAddress);
    if (count != kExpectedTableCount) {
        throw std::runtime_error("Unexpected Spore string-table length");
    }

    std::vector<GuestRecord> records;
    records.reserve(count);
    for (std::uint32_t index = 0; index < count; ++index) {
        const std::uint32_t record_address =
            kTableAddress + index * sizeof(GuestRecord);
        records.push_back({
            image.readAtAddress(record_address),
            image.readAtAddress(record_address + 4),
            image.readAtAddress(record_address + 8)
        });
    }
    const std::vector<GuestRecord> original_records = records;

    std::size_t original_order_inversions = 0;
    for (std::size_t index = 1; index < records.size(); ++index) {
        if (records[index - 1].key > records[index].key) {
            ++original_order_inversions;
        }
    }
    if (original_order_inversions != 16) {
        throw std::runtime_error("Unexpected Spore string-table original ordering");
    }

    spore::string_table::sort(records.data(), records.data() + records.size());
    for (std::size_t index = 1; index < records.size(); ++index) {
        if (records[index - 1].key >= records[index].key) {
            throw std::runtime_error(
                "Spore table sort is not strictly ordered or contains duplicate keys");
        }
    }

    GuestRecord* const end = records.data() + records.size();
    std::size_t verified_lookups = 0;
    for (const GuestRecord& expected : original_records) {
        GuestRecord* const found = spore::string_table::lowerBound(
            records.data(), end, &expected.key);
        if (found == end
                || found->key != expected.key
                || found->value_address != expected.value_address
                || found->reserved != expected.reserved) {
            throw std::runtime_error(
                "Recompiled lookup did not reproduce an original table record");
        }
        ++verified_lookups;
    }

    constexpr std::uint32_t missing_key = 0xdeadbeef;
    for (const GuestRecord& record : original_records) {
        if (record.key == missing_key) {
            throw std::runtime_error(
                "Missing-key validation key unexpectedly exists in Spore table");
        }
    }
    GuestRecord* const missing_result = spore::string_table::lowerBound(
        records.data(), end, &missing_key);
    if (missing_result != end && missing_result->key <= missing_key) {
        throw std::runtime_error(
            "Recompiled lookup failed to identify an absent table key");
    }
    const std::string unknown_string = image.readCString(kUnknownStringAddress);
    if (unknown_string != "unknown") {
        throw std::runtime_error("Unexpected Spore missing-key fallback string");
    }

    GuestRecord* result = spore::string_table::lowerBound(
        records.data(), end, &key);
    if (result == end || key < result->key) {
        return image.readCString(kUnknownStringAddress);
    }
    std::ostringstream message;
    message << "FUN_00461520 recompilada em ARM64: PASS\n"
            << "Tabela PE original: " << records.size() << " registros; "
            << original_order_inversions << " inversoes antes da ordenacao\n"
            << "FUN_004274A0 -> FUN_0042B2D0/FUN_0042B4E0 -> FUN_00422430\n"
            << "Lookups originais verificados: " << verified_lookups << "/"
            << original_records.size() << "; chave ausente: "
            << unknown_string << "\n"
            << "Chave 0x" << std::hex << key << std::dec
            << " (indice " << (result - records.data()) << "): "
            << image.readCString(result->value_address);
    return message.str();
}

std::vector<std::uint8_t> readImage(const char* path) {
    std::ifstream input(path, std::ios::binary | std::ios::ate);
    if (!input) {
        throw std::runtime_error("Cannot open imported SporeApp.exe");
    }
    const std::streamoff size = input.tellg();
    if (size <= 0 || static_cast<std::uint64_t>(size) > kMaxImageBytes) {
        throw std::runtime_error("Invalid SporeApp.exe file size");
    }
    std::vector<std::uint8_t> bytes(static_cast<std::size_t>(size));
    input.seekg(0);
    input.read(reinterpret_cast<char*>(bytes.data()), size);
    if (!input) {
        throw std::runtime_error("Cannot read imported SporeApp.exe");
    }
    return bytes;
}

}  // namespace

extern "C" JNIEXPORT jstring JNICALL
Java_dev_sporeport_cellstage_MainActivity_nativeRuntimeInfo(
    JNIEnv* environment, jclass) {
    return environment->NewStringUTF(
        "Núcleo JNI ARM64 carregado. Use o botão abaixo para abrir o teste SDL2.");
}

extern "C" JNIEXPORT jstring JNICALL
Java_dev_sporeport_cellstage_MainActivity_nativeSporeLookup(
    JNIEnv* environment, jclass, jstring executable_path, jint key) {
    const char* path = environment->GetStringUTFChars(executable_path, nullptr);
    if (path == nullptr) {
        return nullptr;
    }

    std::string result;
    try {
        SporePe32Image image(readImage(path));
        result = sporeLookup461520(image, static_cast<std::uint32_t>(key));
    } catch (const std::exception& error) {
        environment->ReleaseStringUTFChars(executable_path, path);
        jclass exception_class = environment->FindClass("java/lang/IllegalStateException");
        if (exception_class != nullptr) {
            environment->ThrowNew(exception_class, error.what());
        }
        return nullptr;
    }
    environment->ReleaseStringUTFChars(executable_path, path);

    return environment->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_sporeport_cellstage_MainActivity_nativeSporeNameHash(
    JNIEnv* environment, jclass, jstring name) {
    if (name == nullptr) {
        jclass exception_class =
            environment->FindClass("java/lang/IllegalArgumentException");
        if (exception_class != nullptr) {
            environment->ThrowNew(exception_class, "Spore resource name is null");
        }
        return 0;
    }

    const char* text = environment->GetStringUTFChars(name, nullptr);
    if (text == nullptr) {
        return 0;
    }

    std::uint32_t hash;
    try {
        hash = spore::fnv1_ascii_lower(text);
    } catch (const std::exception& error) {
        environment->ReleaseStringUTFChars(name, text);
        jclass exception_class =
            environment->FindClass("java/lang/IllegalArgumentException");
        if (exception_class != nullptr) {
            environment->ThrowNew(exception_class, error.what());
        }
        return 0;
    }
    environment->ReleaseStringUTFChars(name, text);
    return static_cast<jlong>(hash);
}

extern "C" JNIEXPORT jbyteArray JNICALL
Java_dev_sporeport_cellstage_MainActivity_nativeReadDbpfResource(
    JNIEnv* environment,
    jclass,
    jstring package_path,
    jint type,
    jint group,
    jint instance) {
    const char* path = environment->GetStringUTFChars(package_path, nullptr);
    if (path == nullptr) {
        return nullptr;
    }

    std::vector<std::uint8_t> payload;
    try {
        spore::DbpfPackage package(path);
        const spore::Tgi key{
            static_cast<std::uint32_t>(type),
            static_cast<std::uint32_t>(group),
            static_cast<std::uint32_t>(instance)
        };
        const std::size_t entry_index = package.find(key);
        if (entry_index == package.entries().size()) {
            throw std::runtime_error("TGI was not found in the DBPF package");
        }
        payload = package.read_entry(entry_index, kMaxDbpfResourceBytes);
    } catch (const std::exception& error) {
        environment->ReleaseStringUTFChars(package_path, path);
        jclass exception_class =
            environment->FindClass("java/lang/IllegalStateException");
        if (exception_class != nullptr) {
            environment->ThrowNew(exception_class, error.what());
        }
        return nullptr;
    }
    environment->ReleaseStringUTFChars(package_path, path);

    if (payload.size() > static_cast<std::size_t>(
            std::numeric_limits<jsize>::max())) {
        jclass exception_class =
            environment->FindClass("java/lang/IllegalStateException");
        if (exception_class != nullptr) {
            environment->ThrowNew(
                exception_class, "Decoded DBPF resource exceeds JNI array limits");
        }
        return nullptr;
    }

    jbyteArray result =
        environment->NewByteArray(static_cast<jsize>(payload.size()));
    if (result == nullptr) {
        return nullptr;
    }
    if (!payload.empty()) {
        environment->SetByteArrayRegion(
            result,
            0,
            static_cast<jsize>(payload.size()),
            reinterpret_cast<const jbyte*>(payload.data()));
    }
    return result;
}
