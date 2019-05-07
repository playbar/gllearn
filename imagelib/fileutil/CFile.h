//
// Created by hou guoli on 2019/5/7.
//

#ifndef IMAGELIB_CFILE_H
#define IMAGELIB_CFILE_H

#include "CFileBase.h"

#include "string"
typedef unsigned char uchar;

class CFile : public CFileBase
{
public:
    CFile();
    CFile(std::string name);
    std::string getPath() const;
    std::string getName() const;

    void write(const uchar *data, size_t len);
    void close();

private:
    std::string mFileName;
    FILE *mpFile;
};


#endif //IMAGELIB_CFILE_H
