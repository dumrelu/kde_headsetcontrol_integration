
# Easily control the name of the module
set(MODULE_NAME "kde_headsetcontrol_integration")

# All files will be placed in this directory
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME})

# Generate the qmldir file(need to replace the module name with MODULE_NAME)
configure_file(qmldir.in ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME}/qmldir @ONLY)

# Copy QML files
set(QML_FILES BatteryDebug.qml)
foreach(qml_file IN LISTS QML_FILES)
    configure_file(${qml_file} ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME} COPYONLY)
endforeach()

# C++ plugin
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME})

add_library(headsetcontrol SHARED
    headsetcontrol_plugin.h
    headsetcontrol_plugin.cpp
    HeadsetControl.h
    HeadsetControl.cpp
)

target_link_libraries(headsetcontrol Qt5::Core Qt5::Quick)

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME} DESTINATION /usr/lib/qt/qml)
