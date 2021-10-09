find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_CONFIFGURE ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc)
    doxygen_add_docs(Doxygen
        ALL
        ${DOXYGEN_CONFIFGURE}
        COMMENT "Generation of documentation for versions ${CMAKE_PROJECT_VERSION}."
    )
else()
    message("Doxygen need to be installed to generate the doxygen documentation")
endif()
