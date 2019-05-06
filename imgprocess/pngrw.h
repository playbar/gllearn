#ifndef __PNG_READ_WRITE_H__
#define __PNG_READ_WRITE_H__


#include <stdio.h>
#include <png.h>
#include <stdlib.h>

/******************************图片数据*********************************/

typedef struct pic_header
{
    int width;
    int height;
    int bit_depth;
};

typedef struct _pic_data
{
    int width, height; /* 尺寸 */
    int bit_depth;  /* 位深 */
    int flag;   /* 一个标志，表示是否有alpha通道 */
    unsigned char *rgba; /* 图片数组 */
}pic_data;



/**********************************************************************/
#define PNG_BYTES_TO_CHECK 4
#define HAVE_ALPHA 1
#define NO_ALPHA 0

#ifdef __cplusplus
extern "C"{
#endif

/* 用于解码png图片 */
int detect_png(char *filepath, pic_data *out);

/* 功能：将LCUI_Graph结构中的数据写入至png文件 */
int write_png_file(char *file_name , pic_data *graph);

int write_png565_file(char *file_name , pic_data *graph);

#ifdef __cplusplus
}
#endif

#endif
