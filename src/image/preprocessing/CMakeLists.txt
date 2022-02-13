project(preprocessing VERSION 0.1.0 LANGUAGES CXX)

include(${CMAKE_SOURCE_DIR}/thirdparty/opencv.cmake)
aux_source_directory(. SOURCE)
add_library(${PROJECT_NAME}
        ${SOURCE}
        )
set_target_properties(${PROJECT_NAME}
        PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )
add_library(honeybadger::image::preprocessing::color ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_SOURCE_DIR}/include/honeybadger/image/preprocessing
        PUBLIC ${OpenCV_INCLUDE_DIRS}
        )
add_dependencies(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS})

include(CompilationFlags)
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    if (MSVC)
    else ()
        target_compile_options(${PROJECT_NAME} PRIVATE ${GCC_FLAGS})
    endif ()
else ()
    if (MSVC)
    else ()
        list(APPEND GCC_FLAGS -g3 -DNDEBUG)
        target_compile_options(${PROJECT_NAME} PRIVATE ${GCC_FLAGS})
    endif ()
endif ()