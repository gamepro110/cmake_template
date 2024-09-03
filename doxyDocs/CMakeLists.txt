option(BUILD_DOXYGEN_DOCS "build documentation" ON)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN "./Doxyfile.in")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/DOCS/Doxyfile")

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message(STATUS "[Doxygen] Generating Docs")

    add_custom_target(
        GenerateDocs
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/"
        COMMENT "Generating API docs with Doxygen"
        VERBATIM
    )

    set_target_properties(
        GenerateDocs
        PROPERTIES
        FOLDER ${PROJECT_NAME}
    )

else(DOXYGEN_FOUND)
    message(WARNING "Doxygen not installed yet.")
endif(DOXYGEN_FOUND)
