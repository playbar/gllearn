//
// Created by hou guoli on 2019/5/7.
//

#include "CFile.h"

CFile::CFile()
{

}

CFile::CFile(std::string name)
{
    mFileName = name;
}

std::string CFile::getPath()const
{
    int pos = mFileName.find_last_of('/');
    std::string path = mFileName.substr(0, pos - 1 );
    return path;
}

std::string CFile::getName() const
{
    return mFileName;
}

void CFile::write(const uchar *data, size_t len)
{
    fwrite(data, len, 1, mpFile);
}

void CFile::close()
{
    fclose(mpFile);
}