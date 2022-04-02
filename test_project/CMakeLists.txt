add_executable(test_project 
    main.cpp
    qml.qrc
)

target_compile_options(test_project PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_link_libraries(test_project PRIVATE Qt5::Core Qt5::Quick)