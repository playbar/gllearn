add_subdirectory(FreeImage)
add_subdirectory(squish)

add_definitions(-DFREEIMAGE_LIB)

include_directories(
        "FreeImage/"
        )

add_executable(LoadFromHandle
        Examples/Generic/LoadFromHandle.cpp
        )
target_link_libraries(LoadFromHandle
        freeimage)