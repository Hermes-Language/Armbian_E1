cmake_minimum_required(VERSION 3.14)
project(E1Recorder LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Quick Qml Multimedia REQUIRED)

add_subdirectory(src)

qt_add_executable(E1Recorder
    main.cpp
    qml/Main.qml
    qml/ModernRecordingScreen.qml
    qml/DeviceSettingsScenarioPage.qml
    qml/FileListScreen.qml
    qml/FileListItem.qml
    resources/qml.qrc
)

target_include_directories(E1Recorder PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(E1Recorder PRIVATE Qt6::Core Qt6::Quick Qt6::Qml Qt6::Multimedia storagemanager audiorecorder hardwarekeymanager)