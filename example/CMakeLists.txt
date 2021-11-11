option(IMAGE_EXAMPLE "Image example" ON)
if (IMAGE_EXAMPLE)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/image)
endif ()