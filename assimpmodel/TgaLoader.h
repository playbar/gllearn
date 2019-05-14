#pragma once

#include <cstdio>
#include<stdlib.h>
#include<string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;
#define _WITH_GL

#ifdef _WITH_GL
#define TGA_BYTE GLubyte
#endif

#ifndef _WITH_GL
#define TGA_BYTE char
#define GL_RGB
#endif

typedef struct {
	char  idlength;
	char  colourmaptype;
	char  datatypecode;
	short int colourmaporigin;
	short int colourmaplength;
	char  colourmapdepth;
	short int x_origin;
	short int y_origin;
	short width;
	short height;
	char bitsperpixel;
	char imagedescriptor;
}TgaHeader;

typedef struct{
	int w,h;
	int texFormat;
	int bpp; //bits per pixel
	int length;
	int bytesperpixel;
	TGA_BYTE *texels;
} STexture;

class TgaLoader
{
public:
	STexture* mTexture;
	TgaLoader(void);
	GLuint newTex2d(string fname);
	STexture* load(string fname);
	~TgaLoader(void);
};
