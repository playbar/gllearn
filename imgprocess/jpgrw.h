#ifndef __JPGREADWRITE_H__
#define __JPGREADWRITE_H__


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jpeglib.h"

#ifdef __cplusplus
extern "C"{
#endif

void write_bmp_header(j_decompress_ptr cinfo, FILE *output_file);

void write_pixel_data(j_decompress_ptr cinfo, unsigned char *output_buffer, FILE *output_file);


/*读JPEG文件相当于解压文件*/

int read_jpeg_file(const char *input_filename, const char *output_filename);

int write_jpeg_file(char * filename, int quality);


#ifdef __cplusplus
}
#endif


#endif
