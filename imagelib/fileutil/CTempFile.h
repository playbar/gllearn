//
// Created by hou guoli on 2019/5/7.
//

#ifndef IMAGELIB_CTEMPFILE_H
#define IMAGELIB_CTEMPFILE_H

#include "CFile.h"

class CTempFile {
public:
    CTempFile();
    CFile *getFile();

private:
    CFile mFile;

};


#endif //IMAGELIB_CTEMPFILE_H
