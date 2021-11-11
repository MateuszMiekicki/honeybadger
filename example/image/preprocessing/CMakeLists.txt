project(${PROJECT_NAME}_example_preprocessing)
add_executable(color_example
        ${CMAKE_CURRENT_SOURCE_DIR}/colorConvert.cc
        )
target_link_libraries(color_example
        PRIVATE
        honeybadger::image::preprocessing::color
        )
target_include_directories(color_example PRIVATE ${CMAKE_SOURCE_DIR}/include
        ${OpenCV_INCLUDE_DIRS}
        )
set_target_properties(color_example
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )

if (MSVC)
else ()
    target_compile_options(color_example PRIVATE -O3 -Wall -Wextra -pedantic -Werror)
endif ()
