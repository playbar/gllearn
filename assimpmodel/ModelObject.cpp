#include "ModelShader.h"
#include "ModelObject.h"
#include "TinyObjLoader.h"


#include "assimp/Importer.hpp"
#include <opencv2/opencv.hpp>

/**
 * Class constructor
 */
ModelObject::ModelObject() {

    printf("ModelObject::ModelObject\n");
    initsDone = false;

    // create MyGLCamera object and set default position for the object
    mModelCamera = new ModelCamera();
    mModelCamera->SetModelPosition();

    mModelLoader = NULL;
}

ModelObject::~ModelObject() {

    printf("ModelObject::ModelObjectssimp\n");
    if (mModelCamera) {
        delete mModelCamera;
    }
    if (mModelLoader) {
        delete mModelLoader;
    }
}

/**
 * Perform inits and load the triangle's vertices/colors to GLES
 */
void ModelObject::PerformGLInits() {

    printf("ModelObject::PerformGLInits\n");

    MyGLInits();

//    mModelLoader = new AssimpLoader();
    mModelLoader = new TinyObjLoader();
    std::string objFilename = "tinyobj.obj";
    mModelLoader->Load3DModel(objFilename);

//    std::string outFileName = "amenemhat/test.obj";
//    mModelLoader->Export3DModel(outFileName);

    CheckGLError("ModelObject::PerformGLInits");
    initsDone = true;
}


/**
 * Render to the display
 */
void ModelObject::Render() {

    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 mvpMat = mModelCamera->GetMVP();
    mModelLoader->Render3DModel(&mvpMat);

    CheckGLError("ModelObject::Render");

}

/**
 * set the viewport, function is also called when user changes device orientation
 */
void ModelObject::SetViewport(int width, int height) {

    screenHeight = height;
    screenWidth = width;
    glViewport(0, 0, width, height);
    CheckGLError("Cube::SetViewport");

    mModelCamera->SetAspectRatio((float) width / height);
}


/**
 * reset model's position in double-tap
 */
void ModelObject::DoubleTapAction() {

    mModelCamera->SetModelPosition();
}

/**
 * rotate the model if user scrolls with one finger
 */
void ModelObject::ScrollAction(float distanceX, float distanceY, float positionX, float positionY) {

    mModelCamera->RotateModel(distanceX, distanceY, positionX, positionY);
}

/**
 * pinch-zoom: move the model closer or farther away
 */
void ModelObject::ScaleAction(float scaleFactor) {

    mModelCamera->ScaleModel(scaleFactor);
}

/**
 * two-finger drag: displace the model by changing its x-y coordinates
 */
void ModelObject::MoveAction(float distanceX, float distanceY) {

    mModelCamera->TranslateModel(distanceX, distanceY);
}