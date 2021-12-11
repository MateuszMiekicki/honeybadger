include(CTest)
include(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/googletest.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/coverage/calculator.cmake)
add_executable(honeybadger_test
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cc
        ${calc_path}
        )
target_link_libraries(honeybadger_test
        PRIVATE
        gtest
        gmock
        coverage::test
        )
target_include_directories(honeybadger_test PRIVATE ${CMAKE_SOURCE_DIR}/include/coverage)
target_include_directories(honeybadger_test PRIVATE ${gtest_SOURCE_DIR}/include)
set_target_properties(honeybadger_test
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )

gtest_discover_tests(honeybadger_test)

include(${CMAKE_SOURCE_DIR}/cmake/CompilationFlags.cmake)

option(COVERAGE "Tests with coverage" ON)
if (COVERAGE)
    list(APPEND GCC_FLAGS --coverage -fprofile-arcs -ftest-coverage -fprofile-abs-path -g3 -O0)
    target_link_libraries(honeybadger_test PRIVATE gcov)
else ()
    list(APPEND GCC_FLAGS -O3)
endif ()

if (MSVC)
else ()
    target_compile_options(honeybadger_test PRIVATE ${GCC_FLAGS})
endif ()