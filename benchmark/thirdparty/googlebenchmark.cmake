find_package(benchmark 1.6.0 QUIET)
if (NOT benchmark_FOUND)
    message(STATUS "No google benchmark found. Downloading from the repository.")
    include(FetchContent)
    FetchContent_Declare(googlebenchmark
            GIT_REPOSITORY https://github.com/google/benchmark.git
            GIT_TAG v1.6.0
            )
    set(BENCHMARK_ENABLE_TESTING OFF)
    FetchContent_MakeAvailable(googlebenchmark)
endif ()