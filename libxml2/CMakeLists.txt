
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB XML2_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
        )
add_library(xml2 STATIC
        ${XML2_SRC}
        )


add_executable(xml2_test
        example/gjobread.c
        )

target_link_libraries(xml2_test
        xml2)


