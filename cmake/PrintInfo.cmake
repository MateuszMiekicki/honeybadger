function(print_info_about_project)
    message(STATUS "Project name:${PROJECT_NAME}")
    message(STATUS "Project version: ${PROJECT_VERSION}")
    message(STATUS "Project description: ${PROJECT_DESCRIPTION}")
    message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
    message(STATUS "Shared library: ${BUILD_SHARED_LIBS}")
    message(STATUS "Binary dir: ${PROJECT_BINARY_DIR}")
    message(STATUS "Source dir: ${PROJECT_SOURCE_DIR}")
endfunction()