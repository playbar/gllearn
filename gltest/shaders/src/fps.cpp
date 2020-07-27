#include "fps.h"
#include "chrono"
#include "stdio.h"

static double timeSum = 0;//单位:秒
static unsigned long long timeCount = 0;

void beginFPS(){
    auto timeStart = std::chrono::high_resolution_clock::now();
}
void endFPS(){
    auto timeStart = std::chrono::high_resolution_clock::now();
    auto timeEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timeInterval = timeEnd - timeStart;
    timeSum += timeInterval.count();
    ++timeCount;
    double avgFPS = 1.0f / (timeSum / (double)timeCount);
    char buf[64] = "";
    snprintf(buf, sizeof(buf) - 1, "%.3f", avgFPS);
    printf("avgFps : %.3f", avgFPS);

}
void printFPS(){

}

uint64_t GetTimeNano()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    uint64_t result = t.tv_sec * 1000000000LL + t.tv_nsec;
    return result;
}

void ShowFPS()
{
#define INTERVALTIME 100
    static unsigned int prevTimeMs = GetTimeNano();
    static unsigned int lastTimeMS = GetTimeNano();
    static unsigned int frameCounter = 0;
    static float maxTime = 0;
    static float minTime = 0;

    unsigned int currentTimeMs = GetTimeNano();
    float everyInterTime = (float)(currentTimeMs - lastTimeMS) * 1e-6;
    if( everyInterTime > maxTime ){
        maxTime = everyInterTime;
    }
    if( everyInterTime < minTime )
    {
        minTime = everyInterTime;
    }
    lastTimeMS = currentTimeMs;
    frameCounter++;
    float totalTime = (currentTimeMs - prevTimeMs) * 1e-6;
    if (totalTime > INTERVALTIME)
    {
        float elapsedSec = (float)totalTime / 1000.0f;
        float currentFPS = (float)frameCounter / elapsedSec;
//        LOGI("submit, FPS: %0.2f, maxIntervalTime: %0.2f, minIntervalTime: %0.2f",  currentFPS, maxTime, minTime);
        printf( "AvgFPS = %06.2f , Frame = [%06.2f , %06.2f] (ms) \n", currentFPS, minTime, maxTime);

        minTime = currentFPS;
        maxTime = currentFPS;
        frameCounter = 0;
        prevTimeMs = currentTimeMs;
    }
}
