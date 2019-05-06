#ifndef PICPROCESS_H
#define PICPROCESS_H


#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string>

#ifdef __cplusplus
extern "C"{
#endif

int path_is_directory (const char* path);
void enum_dir_img_files(const char *inDir, const char *outDir);
void img_proce(const char *inImg, const char *outImg);

#ifdef __cplusplus
}
#endif

#endif //MODELASSIMP_H
