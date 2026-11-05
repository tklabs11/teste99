cmake_minimum_required(VERSION 3.22)

project(SporeLiftingHarness LANGUAGES CXX)

add_library(lifting_harness_arm64 OBJECT lifting_harness.cpp)
target_compile_features(lifting_harness_arm64 PUBLIC cxx_std_17)
target_compile_options(lifting_harness_arm64 PRIVATE -Wall -Wextra -Wpedantic -O2)

enable_testing()
