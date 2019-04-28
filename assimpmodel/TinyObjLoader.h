#ifndef TINYOBJLOADER_H
#define TINYOBJLOADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <map>
#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>

#include "ModelUtil.h"
#include "ModelShader.h"
#include "ModelLoader.h"
#include "tiny_obj_loader.h"


class TinyObjLoader : public ModelLoader
{

public:
    TinyObjLoader();
    ~TinyObjLoader();

    void Render3DModel(glm::mat4 *MVP);
    bool Load3DModel(std::string modelFilename);
    bool Export3DModel(std::string modelFilename);
    void Delete3DModel();

private:
    void GenerateGLBuffers();
    bool LoadTexturesToGL(std::string modelFilename);

    void PrintInfo();


    std::vector<struct MeshInfo> modelMeshes;       // contains one struct for every mesh in model
    bool isObjectLoaded;

    std::map<std::string, GLuint> textureNameMap;   // (texture filename, texture name in GL)

    GLuint  vertexAttribute, vertexUVAttribute;     // attributes for shader variables
    GLuint  shaderProgramID;
    GLint   mvpLocation, textureSamplerLocation;    // location of MVP in the shader


    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

};

#endif //ASSIMPLOADER_H
