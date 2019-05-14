#include "TgaLoader.h"

TgaLoader::TgaLoader(void)
{
}

STexture * TgaLoader::load(string fname){
    TgaHeader header;
    memset(&header, 0, sizeof(TgaHeader));
    STexture *texture;
    FILE *fd;
    long int offset = 4*sizeof(char)+4*sizeof(short int);

    texture = (STexture *)malloc(sizeof(STexture));
    memset(texture, 0, sizeof(STexture));

    fd = fopen(fname.c_str(),"rb");
    if(!fd){
        printf("File %s not found\n",fname.c_str());
        exit(-1);
    }

    /*Fill our header.*/
    /*Skip useless stuff*/
    fseek(fd,offset,SEEK_SET);

    fread(&header.width,sizeof(short),1,fd);
    fread(&header.height,sizeof(short),1,fd);
    fread(&header.bitsperpixel,sizeof(char),1,fd);
    fread(&header.imagedescriptor,sizeof(char),1,fd);

    texture->w = header.width;
    texture->h = header.height;

    texture->bpp = header.bitsperpixel;
    texture->bytesperpixel=header.bitsperpixel/8;
    switch(header.bitsperpixel){
        case 24:
            texture->texFormat = GL_RGB;
            break;
        case 32:
            texture->texFormat = GL_RGBA ;
            break;
        case 16:
            texture->texFormat = GL_RGB565;
            break;
        default:
            printf("Unsupported BPP\n");
            break;
    }

    /*Allocate memory*/
    texture->length = texture->w * texture->h * texture->bytesperpixel * sizeof(TGA_BYTE);
    texture->texels = (TGA_BYTE *) malloc(texture->length);

    int pixnum = header.width * header.height;

    /*Start reading our image!*/
    int i = 0;
    if(header.bitsperpixel == 32){
        for(i=0;i<pixnum;i++){
            /*BGRA --> RGBA*/
            texture->texels[i*4+2]=fgetc(fd);
            texture->texels[i*4+1]=fgetc(fd);
            texture->texels[i*4+0]=fgetc(fd);
            texture->texels[i*4+3]=fgetc(fd);
        }
    }
    if(header.bitsperpixel == 24){
        for(i=0;i<pixnum;i++){
            texture->texels[i*3+2]=fgetc(fd);
            texture->texels[i*3+1]=fgetc(fd);
            texture->texels[i*3+0]=fgetc(fd);
        }
    }
    if(header.bitsperpixel == 16){
        for(i=0;i<pixnum;i++){
            texture->texels[i*2+1]=fgetc(fd);
            texture->texels[i*2+0]=fgetc(fd);
        }
    }

    fclose(fd);

    printf("Loaded %i bit TGA file'\n",header.bitsperpixel);

    mTexture = texture;
    return texture;
}

GLuint TgaLoader::newTex2d(string fname)
{
    GLuint name;
    //t_texture *tex;
    mTexture = load(fname);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &name);
    glBindTexture(GL_TEXTURE_2D,name);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

//    glTexImage2D(GL_TEXTURE_2D, 0, mTexture->texFormat,
//                 mTexture->w, mTexture->h, 0, mTexture->texFormat,
//                 GL_UNSIGNED_SHORT_5_6_5, mTexture->texels);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 mTexture->w, mTexture->h, 0, GL_RGB,
                 GL_UNSIGNED_SHORT_5_6_5, mTexture->texels);

    /*The texture is now inside OpenGL*/
    return name;
}

TgaLoader::~TgaLoader(void)
{
    if(mTexture!=NULL){
        if(mTexture->texels)
            free(mTexture->texels);
        free(mTexture);
    }
}
