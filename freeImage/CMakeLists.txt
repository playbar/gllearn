add_subdirectory(Source)

add_definitions(-DFREEIMAGE_LIB)
include_directories(
        "Source"
        )

add_executable(LoadFromHandle
        Examples/Generic/LoadFromHandle.cpp
        )
target_link_libraries(LoadFromHandle
        freeimage)