//
// Created by hou guoli on 2019/5/7.
//

#ifndef IMAGELIB_CFILE_H
#define IMAGELIB_CFILE_H

#include "CFileBase.h"


class CFile : public CFileBase
{
public:
    CFile();
    CFile(std::string name);
    std::string getPath() const;
    std::string getSuffix() const;

    CFileData *readAll();

private:

};


#endif //IMAGELIB_CFILE_H
