//
// Created by hou guoli on 2019/5/7.
//

#ifndef IMAGELIB_CFILEBASE_H
#define IMAGELIB_CFILEBASE_H

#include "string"
#include "CFileType.h"

typedef unsigned char uchar;

class CFileBase {
public:
    CFileBase();
    CFileType getType();
    std::string getName() const;
    void rewind();
    void write(const uchar *data, size_t len);
    bool read(const uchar *data, size_t len, size_t *num = NULL);
    void close();

protected:
    CFileType mFileType;
    std::string mFileName;
    FILE *mpFile;
};


#endif //IMAGELIB_CFILEBASE_H
