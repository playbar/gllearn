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

std::string CFile::getSuffix() const
{
    int pos = mFileName.find_last_of('.');
    std::string suffix = mFileName.substr(pos + 1, mFileName.length() - (pos + 1));
    return suffix;
}

CFileData *CFile::readAll()
{
    CFileData *pdat = new CFileData();
    pdat->mlength = getSize();
    pdat->mpdata = new uchar[pdat->mlength + 1 ];
    pdat->mpdata[pdat->mlength] = '\0';
    fread(pdat->mpdata, pdat->mlength, 1, mpFile );
    return pdat;
}

