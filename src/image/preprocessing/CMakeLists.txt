include(${CMAKE_SOURCE_DIR}/thirdparty/opencv.cmake)

set(LIB_NAME preprocessing)
aux_source_directory(. SOURCE)
add_library(${LIB_NAME} SHARED
        ${SOURCE}
        )
add_library(honeybadger::image::preprocessing::color ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME}
        PUBLIC ${CMAKE_SOURCE_DIR}/include/honeybadger/image/preprocessing
        PUBLIC ${OpenCV_INCLUDE_DIRS}
        )
add_dependencies(${LIB_NAME} ${OpenCV_LIBS})
target_link_libraries(${LIB_NAME} PUBLIC ${OpenCV_LIBS})
set_target_properties(${LIB_NAME}
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
        #        target_compile_options(${LIB_NAME} PRIVATE ${GCC_FLAGS})
    endif ()
else ()
    if (MSVC)
    else ()
        #        list(APPEND GCC_FLAGS -g3 -DNDEBUG)
        #        target_compile_options(${LIB_NAME} PRIVATE ${GCC_FLAGS})
    endif ()
endif ()