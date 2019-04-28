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

protected:
    std::vector<struct MeshInfo> modelMeshes;       // contains one struct for every mesh in model
    Assimp::Importer *importerPtr;
    Assimp::Exporter *exporterPtr;
    const aiScene* scene;                           // assimp's output data structure
    bool isObjectLoaded;

    std::map<std::string, GLuint> textureNameMap;   // (texture filename, texture name in GL)

    GLuint  vertexAttribute, vertexUVAttribute;     // attributes for shader variables
    GLuint  shaderProgramID;
    GLint   mvpLocation, textureSamplerLocation;    // location of MVP in the shader
};

#endif //ASSIMPLOADER_H
