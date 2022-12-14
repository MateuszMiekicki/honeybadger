cmake_minimum_required(VERSION 3.18)
project(honeybadger VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" ON)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

string(TIMESTAMP NOW "%Y-%m-%dT%H:%M:%SZ")
set(CURRENT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}-${NOW}")
message(STATUS "version: ${CURRENT_VERSION}")

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif ()

if (NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_BUILD_TYPE Release)
elseif (CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_DEBUG_POSTFIX "-debug")
    option(ENABLE_CODE_COVERAGE "If ON code coverage can be measured" ON)
    if (ENABLE_CODE_COVERAGE)
        include(CodeCoverage)
    else ()
        message(STATUS "Skipping code coverage")
    endif ()
else ()
    message(FATAL_ERROR "Available build types: Debug or Release.")
endif ()

option(ENABLE_TESTS "Enable tests" ON)
if (ENABLE_TESTS)
    include(CTest)
    enable_testing()
    if (MSVC)
        file(COPY tests/test_data DESTINATION ${CMAKE_BINARY_DIR}/bin/Debug)
    else ()
        file(COPY tests/test_data DESTINATION ${CMAKE_BINARY_DIR}/bin)
    endif ()
    add_subdirectory(tests)
endif ()

option(ENABLE_BENCHMARK "Enable benchmark" ON)
if (ENABLE_BENCHMARK)
    add_subdirectory(benchmark)
endif ()

option(ENABLE_EXAMPLE "Enable example" ON)
if (ENABLE_EXAMPLE)
    add_subdirectory(example)
endif ()

option(ENABLE_DOC "Enable documentation" ON)
if (ENABLE_DOC)
    add_subdirectory(${CMAKE_SOURCE_DIR}/docs)
endif ()

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

include(CPackConfig)