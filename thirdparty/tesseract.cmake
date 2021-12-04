find_package(PkgConfig REQUIRED)
pkg_search_module(TESSERACT 4.1 REQUIRED QUIET tesseract)
message(STATUS "Tesseract include dirs: ${TESSERACT_INCLUDE_DIRS}")
message(STATUS "Tesseract libs: ${TESSERACT_LIBRARY_DIRS}")
pkg_search_module(LEPTONICA REQUIRED QUIET lept)
message(STATUS "Leptonica include dirs: ${LEPTONICA_INCLUDE_DIRS}")
message(STATUS "Leptonica libs: ${LEPTONICA_LIBRARY_DIRS}")
if(NOT Tesseract_FOUND)
    # ToDo: Make it so that if it can't find tesseract, let it download from git.
endif()

