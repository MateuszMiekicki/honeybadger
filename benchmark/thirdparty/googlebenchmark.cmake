find_package(benchmark 1.6.0 QUIET)
if (NOT benchmark_FOUND)
    message(STATUS "Not found for benchmark version at least 1.6. ")
    include(FetchContent)
    FetchContent_Declare(googlebenchmark
            GIT_REPOSITORY https://github.com/google/benchmark.git
            GIT_TAG v1.6.0
            )
    set(BENCHMARK_ENABLE_TESTING OFF)
    FetchContent_MakeAvailable(googlebenchmark)
endif ()