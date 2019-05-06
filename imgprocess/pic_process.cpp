#include "pic_process.h"
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <sys/stat.h>

using namespace cv;

static int imageCount = 0;

int path_is_directory (const char* path)
{
    struct stat s_buf;

    if (stat(path, &s_buf))
        return 0;

    return S_ISDIR(s_buf.st_mode);
}

void enum_dir_img_files(const char *inDir, const char *outDir)
{
    struct dirent*  ep;
    DIR *dp;
    DIR *outdp;
    char p_buf[512] = {0};
    char p_outbuf[512] = {0};

    dp = opendir(inDir);
    if (dp == NULL)
    {
        return;
    }

    outdp = opendir( outDir);
    if( outdp == NULL){
        mkdir(outDir,  S_IRWXU|S_IRGRP|S_IROTH);
    }

    while ((ep = readdir(dp)) != NULL)
    {
        sprintf(p_buf, "%s/%s", inDir, ep->d_name);
        sprintf(p_outbuf, "%s/%s", outDir, ep->d_name);
        if (strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0)
        {
            continue;
        }
        else if (path_is_directory(p_buf))
        {
            enum_dir_img_files(p_buf, p_outbuf);
        }
        else
        {
            int ilen = strlen( ep->d_name);
            char exName[5] = {0};
            strcpy(exName, ep->d_name + ilen-4);
            if( strcmp(exName, ".png" ) == 0)
            {
//                ilen = strlen( p_outbuf);
//                p_outbuf[ilen - 3] = 'j';
//                p_outbuf[ilen - 2] = 'p';
//                p_outbuf[ilen - 1] = 'g';
                img_proce(p_buf, p_outbuf);
            }

        }
    }

    closedir(dp);
}


void img_proce(const char *inImg, const char *outImg)
{
    printf("%s \n", __FUNCTION__ );
    printf("inImg:  %s\n", inImg);
    printf("outImg: %s\n", outImg);

    cv::Mat textureImage = cv::imread(inImg, cv::IMREAD_UNCHANGED);

    int channal = textureImage.channels();
    float scale = 1.0;
    int width = textureImage.cols * scale;
    int heigth = textureImage.rows * scale;

    int type = CV_8UC4;
    if( channal == 4 )
    {
        type = CV_8UC4;
    }
    if( 3 == channal )
    {
        type = CV_8UC3;
    }
    if( 2 == channal )
    {
        type = CV_8UC2;
    }
    if( 1 == channal )
    {
        type = CV_8UC1;
    }
    Mat mat(width, heigth, type);
    cv::resize(textureImage, mat, cv::Size(width, heigth));

//    Mat outMat(width, heigth, CV_8UC2);
//    cvtColor(mat, outMat, COLOR_BGRA2BGR565);

//    imshow("outmat", outMat);
//    waitKey(0);

////    int outChannel = outMat.channels();
//
    std::vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);
    imwrite(outImg, mat, compression_params);

//    ++imageCount;
//    printf("imageCount = %d, channel = %d\n", imageCount, channal);
//
//    cv::imshow("outimg", mat);
//    cv::waitKey(0);
    return;
}