include(${CMAKE_SOURCE_DIR}/thirdparty/opencv.cmake)

add_library(color SHARED
        ${CMAKE_SOURCE_DIR}/src/image/preprocessing/Color.cc
        )
add_library(honeybadger::image::preprocessing::color ALIAS color)
target_include_directories(color PRIVATE
        ${CMAKE_SOURCE_DIR}/include/honeybadger/image/preprocessing
        ${OpenCV_INCLUDE_DIRS}
        )
target_link_libraries(color ${OpenCV_LIBS})
set_target_properties(color
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
        list(APPEND GCC_FLAGS -O3 -DNDEBUG)
        target_compile_options(color PRIVATE ${GCC_FLAGS})
    endif ()
else ()
    if (MSVC)
    else ()
        list(APPEND GCC_FLAGS -g3)
        target_compile_options(color PRIVATE ${GCC_FLAGS})
    endif ()
endif ()