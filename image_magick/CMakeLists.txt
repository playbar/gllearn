link_libraries(libpng)
include_directories(
        ${PROJECT_SOURCE_DIR}/libxml2/include
        ${PROJECT_SOURCE_DIR}/opencv/3rdparty/libpng
        ${PROJECT_SOURCE_DIR}/freetype/include
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/coders

)

file(GLOB MAGICK_CODERS_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/coders/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/coders/*.h
        )
file(GLOB MAGICK_MAGICKCORE_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/MagickCore/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/MagickCore/*.h)

add_library(magick STATIC
        ${MAGICK_CODERS_SRC}
        ${MAGICK_MAGICKCORE_SRC}
        )


add_executable(magick_test
        tests/drawtest.c
        )

target_link_libraries(magick_test
        magick
        freetype
        xml2
        bzip
        z)


