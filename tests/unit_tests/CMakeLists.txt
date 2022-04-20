project(unit_tests_${CMAKE_PROJECT_NAME} LANGUAGES CXX)

include(image/preprocessing/preprocessing_test.cmake)
message(${PREPROCESSING_SOURCE_TEST_FILE})

add_executable(${PROJECT_NAME}
        ${PREPROCESSING_SOURCE_TEST_FILE}
        )
target_link_libraries(${PROJECT_NAME}
        PRIVATE GTest::gtest
        PRIVATE GTest::gmock_main
        PRIVATE GTest::gtest_main
        PRIVATE GTest::gmock
        PRIVATE honeybadger::image::preprocessing::color
        )
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${gtest_SOURCE_DIR}/include)
set_target_properties(${PROJECT_NAME}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )

gtest_discover_tests(${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)