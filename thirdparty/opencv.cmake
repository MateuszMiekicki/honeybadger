find_package(OpenCV 4.5 REQUIRED QUIET)
if(NOT OpenCV_FOUND)
    # ToDo: Make it so that if it can't find OpenCV, let it download from git.
endif()
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libs: ${OpenCV_LIBS}")
