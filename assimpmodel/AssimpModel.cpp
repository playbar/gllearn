#include "myShader.h"
#include "AssimpModel.h"


#include "assimp/Importer.hpp"
#include <opencv2/opencv.hpp>

/**
 * Class constructor
 */
AssimpModel::AssimpModel() {

    printf("AssimpModel::AssimpModel");
    initsDone = false;

    // create MyGLCamera object and set default position for the object
    myGLCamera = new MyGLCamera();
    float pos[]={0.0, -10.0, -10.0, 0.0, 0.0, 0.0};
    std::copy(&pos[0], &pos[5], std::back_inserter(modelDefaultPosition));
    myGLCamera->SetModelPosition(modelDefaultPosition);

    modelObject = NULL;
}

AssimpModel::~AssimpModel() {

    printf("AssimpModel::AssimpModelssimp");
    if (myGLCamera) {
        delete myGLCamera;
    }
    if (modelObject) {
        delete modelObject;
    }
}

/**
 * Perform inits and load the triangle's vertices/colors to GLES
 */
void AssimpModel::PerformGLInits() {

    printf("AssimpModel::PerformGLInits");

    MyGLInits();

    modelObject = new AssimpLoader();

    // extract the OBJ and companion files from assets
//    std::string objFilename, texFilename;

    // load obj model
//    bool isFilesPresent  =
//            gHelperObject->ExtractAssetReturnFilename("amenemhat/amenemhat.obj", objFilename) &&
//            gHelperObject->ExtractAssetReturnFilename("amenemhat/amenemhat.mtl", mtlFilename) &&
//            gHelperObject->ExtractAssetReturnFilename("amenemhat/amenemhat.jpg", texFilename);

//    // load dae model
//    bool isFilesPresent  =
//            gHelperObject->ExtractAssetReturnFilename("astroboy/astroboy_walk.dae", objFilename) &&
//            gHelperObject->ExtractAssetReturnFilename("astroboy/seymour.jpg", texFilename);
//    if( !isFilesPresent ) {
//        printf("Model %s does not exist!", objFilename.c_str());
//        return;
//    }

    std::string objFilename = "amenemhat/amenemhat.obj";
//    std::string objFilename = "astroboy/astroboy_walk.dae";
//    std::string objFilename = "astroboy/test.obj";

    std::string outFileName = "amenemhat/test.obj";



    modelObject->Load3DModel(objFilename);

    modelObject->Export3DModel(outFileName);

    CheckGLError("AssimpModel::PerformGLInits");
    initsDone = true;
}


/**
 * Render to the display
 */
void AssimpModel::Render() {

    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 mvpMat = myGLCamera->GetMVP();
    modelObject->Render3DModel(&mvpMat);

    CheckGLError("AssimpModel::Render");

}

/**
 * set the viewport, function is also called when user changes device orientation
 */
void AssimpModel::SetViewport(int width, int height) {

    screenHeight = height;
    screenWidth = width;
    glViewport(0, 0, width, height);
    CheckGLError("Cube::SetViewport");

    myGLCamera->SetAspectRatio((float) width / height);
}


/**
 * reset model's position in double-tap
 */
void AssimpModel::DoubleTapAction() {

    myGLCamera->SetModelPosition(modelDefaultPosition);
}

/**
 * rotate the model if user scrolls with one finger
 */
void AssimpModel::ScrollAction(float distanceX, float distanceY, float positionX, float positionY) {

    myGLCamera->RotateModel(distanceX, distanceY, positionX, positionY);
}

/**
 * pinch-zoom: move the model closer or farther away
 */
void AssimpModel::ScaleAction(float scaleFactor) {

    myGLCamera->ScaleModel(scaleFactor);
}

/**
 * two-finger drag: displace the model by changing its x-y coordinates
 */
void AssimpModel::MoveAction(float distanceX, float distanceY) {

    myGLCamera->TranslateModel(distanceX, distanceY);
}