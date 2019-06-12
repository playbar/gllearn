add_definitions(-DLIBXML_THREAD_ENABLED)
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB XML2_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
        )

file(GLOB EXCLUDE_FILE "testThreadsWin32.c")
foreach(item ${EXCLUDE_FILE})
    list(REMOVE_ITEM XML2_SRC "${item}")
endforeach()


add_library(xml2 STATIC
        ${XML2_SRC}
        )


add_executable(xml2_test
        example/gjobread.c
        )

target_link_libraries(xml2_test
        xml2
        z
        lzma)


