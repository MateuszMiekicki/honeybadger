find_package(GTest 1.11.0 QUIET)
if (NOT GTest_FOUND)
<<<<<<< HEAD
    message(STATUS "No google test found. Downloading from the repository.")
=======
    message(STATUS "Not found for gtest version at least 1.11. ")
>>>>>>> ci_test
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
<<<<<<< HEAD
include(GoogleTest)
=======
include(GoogleTest)
>>>>>>> ci_test
