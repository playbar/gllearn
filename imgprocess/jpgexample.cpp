//// JEPGFile.cpp : Defines the entry point for the console application.
////
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jpgrw.h"

int main(int argc, char *argv[])
{
    read_jpeg_file("./amenemhat.jpg", "./amenemhat.bmp");
    write_jpeg_file("./createJpg.jpg", 2);

    return 0;
}

