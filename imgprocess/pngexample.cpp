#include <stdio.h>
#include <png.h>
#include <stdlib.h>
#include "pngrw.h"

int main(int argc, char **argv)
{
    pic_data data = {0};
    detect_png("./amenemhat.png", &data);
    write_png_file("./test.png", &data);
    free(data.rgba);
    printf("process success");
    return 0;
}