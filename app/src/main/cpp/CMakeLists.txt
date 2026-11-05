cmake_minimum_required(VERSION 3.22)
project(spore_native_runtime LANGUAGES C CXX)

set(SDL_SHARED ON CACHE BOOL "" FORCE)
set(SDL_STATIC OFF CACHE BOOL "" FORCE)
set(SDL_TEST_ENABLED_BY_DEFAULT OFF CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_CCACHE OFF CACHE BOOL "" FORCE)
add_subdirectory(SDL)

set(DXVK_NATIVE_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/dxvk-native")
set(DXVK_GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/dxvk-native-generated")
set(DXVK_SHADER_HEADER_GENERATOR
    "${CMAKE_CURRENT_LIST_DIR}/../../../../tools/generate_dxvk_spirv_header.py")

if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    set(DXVK_SHADER_HOST "windows-x86_64")
    set(DXVK_SHADER_EXECUTABLE "glslc.exe")
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    set(DXVK_SHADER_HOST "linux-x86_64")
    set(DXVK_SHADER_EXECUTABLE "glslc")
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin")
    set(DXVK_SHADER_HOST "darwin-x86_64")
    set(DXVK_SHADER_EXECUTABLE "glslc")
else()
    message(FATAL_ERROR "Unsupported host for DXVK shader generation: ${CMAKE_HOST_SYSTEM_NAME}")
endif()

set(DXVK_GLSLC "${CMAKE_ANDROID_NDK}/shader-tools/${DXVK_SHADER_HOST}/${DXVK_SHADER_EXECUTABLE}")
if(NOT EXISTS "${DXVK_GLSLC}")
    message(FATAL_ERROR "The Android NDK shader compiler was not found: ${DXVK_GLSLC}")
endif()

find_package(Python3 REQUIRED COMPONENTS Interpreter)
find_package(Threads REQUIRED)
find_library(VULKAN_LIB vulkan REQUIRED)
find_library(ANDROID_LIB android REQUIRED)
find_library(ANDROID_LOG_LIB log REQUIRED)

file(GLOB DXVK_SHADER_SOURCES CONFIGURE_DEPENDS
    "${DXVK_NATIVE_SOURCE_DIR}/src/d3d9/shaders/*.comp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/shaders/*.comp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/shaders/*.frag"
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/shaders/*.geom"
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/shaders/*.vert"
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/hud/shaders/*.frag"
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/hud/shaders/*.vert")
file(GLOB DXVK_SHADER_INCLUDE_FILES CONFIGURE_DEPENDS
    "${DXVK_NATIVE_SOURCE_DIR}/src/d3d9/shaders/*.h"
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/shaders/*.h"
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/hud/shaders/*.h")

set(DXVK_SHADER_INCLUDE_ARGS
    "-I${DXVK_NATIVE_SOURCE_DIR}/src/d3d9/shaders"
    "-I${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/shaders"
    "-I${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/hud/shaders")
set(DXVK_GENERATED_SHADERS)
foreach(DXVK_SHADER IN LISTS DXVK_SHADER_SOURCES)
    get_filename_component(DXVK_SHADER_NAME "${DXVK_SHADER}" NAME_WE)
    set(DXVK_SHADER_SPIRV "${DXVK_GENERATED_DIR}/${DXVK_SHADER_NAME}.spv")
    set(DXVK_SHADER_HEADER "${DXVK_GENERATED_DIR}/${DXVK_SHADER_NAME}.h")
    add_custom_command(
        OUTPUT "${DXVK_SHADER_HEADER}"
        BYPRODUCTS "${DXVK_SHADER_SPIRV}"
        COMMAND "${CMAKE_COMMAND}" -E make_directory "${DXVK_GENERATED_DIR}"
        COMMAND "${DXVK_GLSLC}" --target-env=vulkan1.0
                ${DXVK_SHADER_INCLUDE_ARGS}
                -o "${DXVK_SHADER_SPIRV}" "${DXVK_SHADER}"
        COMMAND "${Python3_EXECUTABLE}"
        "${DXVK_SHADER_HEADER_GENERATOR}"
                --input "${DXVK_SHADER_SPIRV}"
                --output "${DXVK_SHADER_HEADER}"
                --symbol "${DXVK_SHADER_NAME}"
        DEPENDS
            "${DXVK_SHADER}"
            ${DXVK_SHADER_INCLUDE_FILES}
            "${DXVK_SHADER_HEADER_GENERATOR}"
        VERBATIM)
    list(APPEND DXVK_GENERATED_SHADERS "${DXVK_SHADER_HEADER}")
endforeach()
add_custom_target(dxvk_spirv_headers DEPENDS ${DXVK_GENERATED_SHADERS})

file(GLOB DXVK_D3D9_SOURCES CONFIGURE_DEPENDS
    "${DXVK_NATIVE_SOURCE_DIR}/src/d3d9/*.cpp")
file(GLOB DXVK_DXSO_SOURCES CONFIGURE_DEPENDS
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxso/*.cpp")
file(GLOB DXVK_DXVK_SOURCES CONFIGURE_DEPENDS
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/*.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/hud/*.cpp")
list(REMOVE_ITEM DXVK_DXVK_SOURCES
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/dxvk_openvr.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/dxvk_openxr.cpp")
file(GLOB DXVK_UTIL_SOURCES CONFIGURE_DEPENDS
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/*.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/com/*.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/config/*.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/log/*.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/sha1/*.c"
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/sha1/*.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/sync/*.cpp")
list(REMOVE_ITEM DXVK_UTIL_SOURCES
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/util_gdi.cpp")
list(APPEND DXVK_UTIL_SOURCES
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/platform/thread_native.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/platform/util_env_linux.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/platform/util_luid_linux.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/util/platform/util_string_linux.cpp")
file(GLOB DXVK_SPIRV_SOURCES CONFIGURE_DEPENDS
    "${DXVK_NATIVE_SOURCE_DIR}/src/spirv/*.cpp")
file(GLOB DXVK_VULKAN_SOURCES CONFIGURE_DEPENDS
    "${DXVK_NATIVE_SOURCE_DIR}/src/vulkan/*.cpp")

set(VCS_TAG "native-1.9.2b-android")
configure_file(
    "${DXVK_NATIVE_SOURCE_DIR}/version.h.in"
    "${DXVK_GENERATED_DIR}/version.h"
    @ONLY)

add_library(dxvk_d3d9 SHARED
    ${DXVK_D3D9_SOURCES}
    ${DXVK_DXSO_SOURCES}
    ${DXVK_DXVK_SOURCES}
    ${DXVK_UTIL_SOURCES}
    ${DXVK_SPIRV_SOURCES}
    ${DXVK_VULKAN_SOURCES}
    "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/platform/dxvk_sdl2_exts.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/wsi/sdl2/wsi_mode_sdl2.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/wsi/sdl2/wsi_monitor_sdl2.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/wsi/sdl2/wsi_presenter_sdl2.cpp"
    "${DXVK_NATIVE_SOURCE_DIR}/src/wsi/sdl2/wsi_window_sdl2.cpp"
    ${DXVK_GENERATED_SHADERS}
    "${DXVK_GENERATED_DIR}/version.h")
add_dependencies(dxvk_d3d9 dxvk_spirv_headers)
target_compile_features(dxvk_d3d9 PRIVATE cxx_std_17)
target_compile_definitions(dxvk_d3d9 PRIVATE
    NOMINMAX
    _WIN32_WINNT=0xa00
    DXVK_NATIVE
    DXVK_WSI_SDL2
    DXVK_PLATFORM_LINUX
    _FILE_OFFSET_BITS=64)
target_compile_options(dxvk_d3d9 PRIVATE -Wno-deprecated-declarations)
target_include_directories(dxvk_d3d9
    PUBLIC
        "${DXVK_NATIVE_SOURCE_DIR}/include/native"
        "${DXVK_NATIVE_SOURCE_DIR}/include/native/windows"
        "${DXVK_NATIVE_SOURCE_DIR}/include/native/directx"
    PRIVATE
        "${DXVK_NATIVE_SOURCE_DIR}/include"
        "${DXVK_NATIVE_SOURCE_DIR}/src/d3d9"
        "${DXVK_NATIVE_SOURCE_DIR}/src/dxso"
        "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk"
        "${DXVK_NATIVE_SOURCE_DIR}/src/dxvk/hud"
        "${DXVK_NATIVE_SOURCE_DIR}/src/spirv"
        "${DXVK_NATIVE_SOURCE_DIR}/src/util"
        "${DXVK_NATIVE_SOURCE_DIR}/src/vulkan"
        "${DXVK_NATIVE_SOURCE_DIR}/src/wsi"
        "${DXVK_GENERATED_DIR}")
target_link_libraries(dxvk_d3d9 PRIVATE SDL2 ${VULKAN_LIB} Threads::Threads ${ANDROID_LOG_LIB})

add_library(spore_native_runtime SHARED
    native_runtime.cpp
    dbpf_reader.cpp)
target_compile_features(spore_native_runtime PRIVATE cxx_std_17)
target_include_directories(spore_native_runtime
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(spore_native_runtime
    PRIVATE
        ${ANDROID_LIB}
        ${ANDROID_LOG_LIB})

add_library(spore_sdl_main SHARED
    sdl_test.cpp
    sdl_vulkan_test.cpp
    sdl_d3d9_test.cpp
    spore_d3d9_bridge.cpp
    spore_translated_graphics.cpp
    sdl_event_loop.cpp
    spore_canvas_adapter.cpp)
set_target_properties(spore_sdl_main PROPERTIES OUTPUT_NAME main)
target_compile_features(spore_sdl_main PRIVATE cxx_std_17)
target_include_directories(spore_sdl_main
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}"
        ${SDL2_INCLUDE_DIRS})
target_link_libraries(spore_sdl_main
    PRIVATE
        SDL2
        dxvk_d3d9
        spore_native_runtime
        ${VULKAN_LIB})
