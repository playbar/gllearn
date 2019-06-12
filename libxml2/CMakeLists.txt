include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/coders

)

file(GLOB MAGICK_CODERS_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/coders/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/coders/*.h
        )
add_library(xml2 STATIC
        ${MAGICK_CODERS_SRC}
        )


add_executable(magick_test
        tests/drawtest.c
        )

target_link_libraries(magick_test
        magick)


