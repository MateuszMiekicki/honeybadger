include(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/googletest.cmake)

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
        )
target_include_directories(${PROJECT_NAME}_test PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME}_test PRIVATE ${gtest_SOURCE_DIR}/include)
set_target_properties(${PROJECT_NAME}_test
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )

gtest_discover_tests(${PROJECT_NAME}_test)
