
# Easily control the name of the module
set(MODULE_NAME "kde_headsetcontrol_integration")

# All files will be placed in this directory
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME})

# Generate the qmldir file(need to replace the module name with MODULE_NAME)
configure_file(qmldir.in ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME}/qmldir @ONLY)

# Copy QML files
set(QML_FILES TestType.qml)
foreach(qml_file IN LISTS QML_FILES)
    configure_file(${qml_file} ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME} COPYONLY)
endforeach()
