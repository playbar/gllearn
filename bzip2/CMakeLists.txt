
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/
)


add_library(bzip STATIC
        blocksort.c
        bzip2.c
        bzlib.c
        compress.c
        crctable.c
        decompress.c
        huffman.c
        randtable.c
        unzcrash.c
        )



