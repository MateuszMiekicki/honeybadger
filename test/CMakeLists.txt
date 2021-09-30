include(FetchContent)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/googletest.cmake)

add_executable(${PROJECT_NAME}_test
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cc
)
target_link_libraries(${PROJECT_NAME}_test
    PRIVATE
    gtest
    gmock
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
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(MSVC)
    else()
        target_compile_options(${PROJECT_NAME}_test PRIVATE -O3 -Wall -Wextra -pedantic -Werror)
    endif()
else()
    if(MSVC)
    else()
        target_compile_options(${PROJECT_NAME}_test PRIVATE -O3 -g3 -Wall -Wextra -pedantic -Werror)
    endif()
endif()
