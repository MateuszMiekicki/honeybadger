include(CTest)
include(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/googletest.cmake)
<<<<<<< HEAD

include(${CMAKE_CURRENT_SOURCE_DIR}/image/preprocessing/preprocessing_test.cmake)

add_executable(${PROJECT_NAME}_test
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cc
        ${PREPROCESSING_SOURCE_TEST_FILE}
        )
message(${PREPROCESSING_SOURCE_TEST_FILE})
target_link_libraries(${PROJECT_NAME}_test
        PRIVATE
        gtest
        gmock
        honeybadger::image::preprocessing::color
=======
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
>>>>>>> ci_test
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

<<<<<<< HEAD
gtest_discover_tests(${PROJECT_NAME}_test)
=======
gtest_discover_tests(honeybadger_test)

include(${CMAKE_SOURCE_DIR}/cmake/CompilationFlags.cmake)

option(COVERAGE "Tests with coverage" ON)
if (COVERAGE)
    list(APPEND GCC_FLAGS --coverage -fprofile-arcs -ftest-coverage -fprofile-abs-path -g3 -O0)
    target_link_libraries(honeybadger_test PRIVATE gcov)
    find_program(GCOV_PATH gcov)
    if (NOT GCOV_PATH)
        message(FATAL_ERROR "gcov not found! Aborting...")
    endif ()
    add_custom_target(gcov_report
            COMMAND ${CMAKE_COMMAND} -P path_to_script
            )
else ()
    list(APPEND GCC_FLAGS -O3)
endif ()

if (MSVC)
else ()
    target_compile_options(honeybadger_test PRIVATE ${GCC_FLAGS})
endif ()
>>>>>>> ci_test
