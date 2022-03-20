find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_CONFIGURE ${CMAKE_SOURCE_DIR}/docs/Doxyfile)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/docs)
    doxygen_add_docs(Doxygen
            ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include
            ALL
            COMMENT "Generation of documentation for versions ${CMAKE_PROJECT_VERSION}."
            )
else ()
    message(FATAL_ERROR "Doxygen need to be installed to generate the doxygen documentation")
endif ()
