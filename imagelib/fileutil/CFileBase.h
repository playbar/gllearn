//
// Created by hou guoli on 2019/5/7.
//

#ifndef IMAGELIB_CFILEBASE_H
#define IMAGELIB_CFILEBASE_H

#include "string"
#include "CFileType.h"

typedef unsigned char uchar;



class CFileData
{
public:
    CFileData();
    ~CFileData();
    unsigned char *getData();
public:
    unsigned char *mpdata;
    unsigned int mlength;
};

class CFileBase {
public:
    CFileBase();
    CFileType getType();
    std::string getName() const;
    std::string getBase();
    void rewind();
    void write(const uchar *data, size_t len);
    void write(std::string str );
    bool read(const uchar *data, size_t len, size_t *num = NULL);
    bool readLine(std::string &strline);
    char getC();
    void close();
    unsigned int getSize();
    unsigned int getPos();


protected:
    CFileType mFileType;
    std::string mFileName;
    FILE *mpFile;
};


#endif //IMAGELIB_CFILEBASE_H
