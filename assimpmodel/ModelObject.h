#ifndef MODELOBJECT_H
#define MODELOBJECT_H

#include "ModelShader.h"
#include "ModelCamera.h"
#include "AssimpLoader.h"
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string>


class ModelObject {
public:
    ModelObject();
    ~ModelObject();
    void    PerformGLInits();
    void    Render();
    void    SetViewport(int width, int height);
    void    DoubleTapAction();
    void    ScrollAction(float distanceX, float distanceY, float positionX, float positionY);
    void    ScaleAction(float scaleFactor);
    void    MoveAction(float distanceX, float distanceY);
    int     GetScreenWidth() const { return screenWidth; }
    int     GetScreenHeight() const { return screenHeight; }

private:
    bool    initsDone;
    int     screenWidth, screenHeight;

    ModelCamera * mModelCamera;
    ModelLoader * mModelLoader;
};

#endif //MODELASSIMP_H
