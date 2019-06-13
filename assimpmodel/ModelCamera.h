
#ifndef MODELCAMERA_H
#define MODELCAMERA_H

#include <vector>
#include "ModelUtil.h"

// sensitivity coefficients for translating gestures to model's movements
#define SCALE_TO_Z_TRANSLATION  20
#define TRANSLATION_TO_ANGLE    5
#define XY_TRANSLATION_FACTOR   10

class ModelCamera {
public:
    ModelCamera();
    void        SetModelPosition();
    void        SetAspectRatio(float aspect);
    glm::mat4   GetMVP(){ return mvpMat; }
    void        RotateModel(float distanceX, float distanceY, float endPositionX, float endPositionY);
    void        ScaleModel(float scaleFactor);
    void        TranslateModel(float distanceX, float distanceY);

private:
    void        ComputeMVPMatrix();

    float       mModelDefaultPosition[6];
    float       FOV;
    float       nearPlaneDistance, farPlaneDistance;

    glm::mat4   projectionViewMat;
    glm::mat4   rotateMat;
    glm::mat4   translateMat;
    glm::mat4   modelMat;
    glm::mat4   viewMat;
    glm::mat4   mvpMat;     // ModelViewProjection: obtained by multiplying Projection, View, & Model

    // six degrees-of-freedom of the model contained in a quaternion and x-y-z coordinates
    glm::quat   modelQuaternion;
    float       deltaX, deltaY, deltaZ;
};

#endif //GLCAMERA_H
