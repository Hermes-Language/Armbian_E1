add_library(storagemanager STATIC storagemanager.cpp)
add_library(audiorecorder STATIC audiorecorder.cpp)
add_library(hardwarekeymanager STATIC hardwarekeymanager.cpp)

target_link_libraries(storagemanager PRIVATE Qt6::Core Qt6::Qml)
target_link_libraries(audiorecorder PRIVATE Qt6::Core Qt6::Qml Qt6::Multimedia)
target_link_libraries(hardwarekeymanager PRIVATE Qt6::Core Qt6::Qml)