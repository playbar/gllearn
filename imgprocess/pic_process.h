#ifndef PICPROCESS_H
#define PICPROCESS_H


#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string>


int path_is_directory (const char* path);
void enum_dir_img_files(const char *inDir, const char *outDir);
void img_proce(const char *inImg, const char *outImg);

#endif //MODELASSIMP_H
