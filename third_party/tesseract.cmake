find_package(Tesseract 5 REQUIRED)
if (NOT Tesseract_FOUND)
    # ToDo: Make it so that if it can't find tesseract, let it download from git.
endif ()
include_directories(${Tesseract_INCLUDE_DIRS})

