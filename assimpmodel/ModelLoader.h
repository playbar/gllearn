#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <map>
#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>
#include "ModelUtil.h"

// info used to render a mesh
struct MeshInfo {
    GLuint  textureIndex;
    int     numberOfFaces;
    GLuint  faceBuffer;
    GLuint  vertexBuffer;
    GLuint  textureCoordBuffer;
};

class ModelLoader {

public:
    ModelLoader();
    ~ModelLoader();

    virtual void Render3DModel(glm::mat4 *MVP) = 0;
    virtual bool Load3DModel(std::string modelFilename) = 0;
    virtual bool Export3DModel(std::string modelFilename);
    virtual void Delete3DModel();

};

#endif //ASSIMPLOADER_H
