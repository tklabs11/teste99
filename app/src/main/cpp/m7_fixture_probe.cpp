#include <jni.h>
#include <android/log.h>

#include "BatchStaticLiftRuntime.hpp"
#include "m7_cfg_data.hpp"

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>

BatchLiftStatus spore_lift_00a23570(BatchLiftMemory&, BatchLiftState&);

namespace {

constexpr std::uint32_t kObject = 0x20000000u;
constexpr std::uint32_t kInput = 0x20010000u;
constexpr std::uint32_t kBuffer = 0x20010100u;
constexpr std::uint32_t kBoundary = 0x00a221fcu;

std::string run_fixture() {
    BatchLiftMemory memory;
    std::array<std::uint8_t, 0x20000> object{};
    auto initial = kM7CfgInitialFloat;
    auto scale = kM7CfgScaleFloat;
    auto table = kM7CfgLookupTable;
    auto correction = kM7CfgCorrection;
    if (!memory.map_region(kObject, object.data(), object.size(), true) ||
        !memory.map_region(0x01485718u, initial.data(), initial.size(), false) ||
        !memory.map_region(0x01470f14u, scale.data(), scale.size(), false) ||
        !memory.map_region(0x0143d850u, table.data(), table.size(), false) ||
        !memory.map_region(0x013f4fd0u, correction.data(), correction.size(), false)) {
        return "MARCO7_FIXTURE_FAIL map_region";
    }
    if (!memory.store32(kInput, kBuffer) ||
        !memory.store32(kInput + 0x14u, 0x12345678u)) {
        return "MARCO7_FIXTURE_FAIL input";
    }
    BatchLiftState state{};
    state.regs[0] = 0x87654321u;
    state.regs[1] = kObject;
    state.regs[2] = 0x12345678u;
    state.regs[3] = 0x11223344u;
    state.regs[4] = BatchLiftMemory::kEntryEsp;
    state.regs[5] = 0x55667788u;
    state.regs[6] = 0x99aabbccu;
    state.regs[7] = 0xddeeff00u;
    state.eflags = 0x202u;
    state.eip = 0x00a23570u;
    const auto entry_esp = state.regs[4];
    if (!memory.store32(entry_esp, BatchLiftMemory::kReturnSentinel)) {
        return "MARCO7_FIXTURE_FAIL stack";
    }
    for (std::uint32_t offset = 4; offset <= 24; offset += 4) {
        if (!memory.store32(entry_esp + offset, offset == 4 ? 2u : 0u)) {
            return "MARCO7_FIXTURE_FAIL stack";
        }
    }
    if (!memory.store32(entry_esp + 28u, kInput)) {
        return "MARCO7_FIXTURE_FAIL stack";
    }

    const auto status = spore_lift_00a23570(memory, state);
    if (status != BatchLiftStatus::unsupported_dependency ||
        state.eip != kBoundary) {
        char message[128];
        std::snprintf(message, sizeof(message),
                      "MARCO7_FIXTURE_FAIL status=%u eip=0x%08x",
                      static_cast<unsigned>(status), state.eip);
        return message;
    }
    const std::array<std::uint32_t, 8> kExpectedRegs{
        0x20010100u, kObject, 0x2001010cu, 0x20000010u,
        entry_esp - 44u, 0x20010a60u, kBuffer, 0x00000008u,
    };
    for (std::size_t index = 0; index < kExpectedRegs.size(); ++index) {
        if (state.regs[index] != kExpectedRegs[index]) {
            char message[128];
            std::snprintf(message, sizeof(message),
                          "MARCO7_FIXTURE_FAIL register=%u actual=0x%08x",
                          static_cast<unsigned>(index), state.regs[index]);
            return message;
        }
    }
    if ((state.eflags & 0x8d5u) != 0x4u) {
        return "MARCO7_FIXTURE_FAIL flags";
    }
    constexpr std::array<std::uint32_t, 14> kExpectedFields{
        0u, 0u, 2u, 0u, 0x3f800000u, 0x40000000u, 2u,
        0x2001010cu, 0u, kBuffer, 0x20010a60u, 0xcu,
        0x12345678u, 0u,
    };
    for (std::size_t index = 0; index < kExpectedFields.size(); ++index) {
        std::uint32_t actual = 0;
        std::memcpy(&actual, object.data() + 4 * index, 4);
        if (actual != kExpectedFields[index]) {
            char message[128];
            std::snprintf(message, sizeof(message),
                          "MARCO7_FIXTURE_FAIL field=%u actual=0x%08x",
                          static_cast<unsigned>(index), actual);
            return message;
        }
    }
    constexpr std::array<std::uint32_t, 8> kExpectedBuffer{
        0x2001010cu, 0u, 0u, 0x20010118u,
        0u, 0u, 0x20010124u, 0u,
    };
    for (std::size_t index = 0; index < kExpectedBuffer.size(); ++index) {
        std::uint32_t actual = 0;
        std::memcpy(&actual, object.data() + 0x10100 + 4 * index, 4);
        if (actual != kExpectedBuffer[index]) {
            char message[128];
            std::snprintf(message, sizeof(message),
                          "MARCO7_FIXTURE_FAIL buffer=%u actual=0x%08x",
                          static_cast<unsigned>(index), actual);
            return message;
        }
    }
    return "MARCO7_FIXTURE_PASS boundary=0x00a221fc "
           "functions=00a23570,00921260,00921300,00921360,00a221b0 "
           "source=PE_verified_generated_data fixture=isolated_not_game_boot";
}

}  // namespace

extern "C" JNIEXPORT jstring JNICALL
Java_dev_sporeport_cellstage_MainActivity_nativeMarco7Fixture(
    JNIEnv* environment, jclass) {
    const std::string result = run_fixture();
    __android_log_print(result.find("MARCO7_FIXTURE_PASS") == 0
                            ? ANDROID_LOG_INFO : ANDROID_LOG_ERROR,
                        "SporeMarco7", "%s", result.c_str());
    return environment->NewStringUTF(result.c_str());
}
