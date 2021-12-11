add_library(coverage SHARED
        ${CMAKE_SOURCE_DIR}/src/coverage/calculator.cc
        )
add_library(coverage::test ALIAS coverage)
target_include_directories(coverage PRIVATE
        ${CMAKE_SOURCE_DIR}/include/coverage
        )
set_target_properties(coverage
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )

include(${CMAKE_SOURCE_DIR}/cmake/CompilationFlags.cmake)
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    if (MSVC)
    else ()
        target_compile_options(coverage PRIVATE ${GCC_FLAGS})
    endif ()
else ()
    if (MSVC)
    else ()
        list(APPEND GCC_FLAGS -g3 -O0 )
        target_compile_options(coverage PRIVATE ${GCC_FLAGS})
    endif ()
endif ()

message("coverage flag " ${GCC_FLAGS})