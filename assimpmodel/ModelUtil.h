#ifndef MODELUTIL_H
#define MODELUTIL_H

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <stdio.h>
#include <string>

std::string GetFileName(std::string fileName);

std::string GetDirectoryName(std::string fullFileName);

void PrintGLMMat4(glm::mat4 testMat);

#endif //MISC_H
