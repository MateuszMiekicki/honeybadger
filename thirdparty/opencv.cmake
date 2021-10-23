find_package(OpenCV 4.5 REQUIRED QUIET)
if(NOT OpenCV_FOUND)
    # ToDo: Make it so that if it can't find OpenCV, let it download from git.
    # include(FetchContent)
    # FetchContent_Declare(opencv
    #     GIT_REPOSITORY https://github.com/opencv/opencv.git
    #     GIT_TAG 4.5.4
    # )
    # FetchContent_MakeAvailable(opencv)
endif()
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libs: ${OpenCV_LIBS}")
