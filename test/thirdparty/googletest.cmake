find_package(GTest 1.11.0 QUIET)
if (NOT GTest_FOUND)
    message(STATUS "Not found for gtest version at least 1.11. ")
    include(FetchContent)
    FetchContent_Declare(googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG release-1.11.0
            )
    if (MSVC)
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    endif ()
    FetchContent_MakeAvailable(googletest)
endif ()
include(GoogleTest)