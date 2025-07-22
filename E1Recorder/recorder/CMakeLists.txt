add_library(recorder STATIC
    recorder.cpp
    recorder.h
)
target_link_libraries(recorder PRIVATE Qt6::Core) 