//
// Created by hou guoli on 2019/5/7.
//

#include "CFileBase.h"

CFileBase::CFileBase()
{

}

CFileType CFileBase::getType()
{
    return mFileType;
}

std::string CFileBase::getName() const
{
    return mFileName;
}

void CFileBase::rewind()
{
    fseek(mpFile, 0, SEEK_SET);
}

void CFileBase::write(const uchar *data, size_t len)
{
    fwrite(data, len, 1, mpFile);
}

bool CFileBase::read(const uchar *data, size_t len, size_t *num)
{
    int count = fread((void*)data, len, 1, mpFile);
    if(num != NULL )
    {
        *num = count;
    }
    return true;
}

void CFileBase::close()
{
    fclose(mpFile);
}



