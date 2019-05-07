//
// Created by hou guoli on 2019/5/7.
//

#include "CFileBase.h"

CFileData::CFileData()
{
    mpdata = NULL;
    mlength = 0;
}

CFileData::~CFileData()
{
    if( mpdata != NULL )
    {
        delete []mpdata;
        mpdata = NULL;
    }
    mlength = 0;
}

unsigned char *CFileData::getData()
{
    return mpdata;
}

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

std::string CFileBase::getBase()
{
    assert(false);
    return "";
}

void CFileBase::rewind()
{
    fseek(mpFile, 0, SEEK_SET);
}

void CFileBase::write(const uchar *data, size_t len)
{
    fwrite(data, len, 1, mpFile);
}

void CFileBase::write(std::string str )
{
    fwrite(str.c_str(), str.length(), 1, mpFile);
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

bool CFileBase::readLine(std::string &strline)
{
    char buf[2048];
    fgets( buf, 2048, mpFile );
    strline = buf;
    return true;
}

char CFileBase::getC()
{
    char ch = 0;
    fread(&ch, 1, 1, mpFile);
    return ch;
}

void CFileBase::close()
{
    fclose(mpFile);
}

unsigned int CFileBase::getSize()
{
    fseek(mpFile, 0, SEEK_END );
    unsigned int len = ftell(mpFile);
    fseek(mpFile, 0, SEEK_SET );
    return len;
}

unsigned int CFileBase::getPos()
{
    unsigned int pos = ftell(mpFile);
    return pos;
}




