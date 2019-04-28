link_libraries(glfw)
link_libraries(assimp)
link_libraries(opencv_core)
link_libraries(opencv_imgproc)
link_libraries(opencv_imgcodecs)

include_directories(${glfw_INCLUDE_DIRS}
        "${GLFW_SOURCE_DIR}/deps"
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../glm
        ${CMAKE_CURRENT_SOURCE_DIR}/../assimp/include
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv
        )

if (MATH_LIBRARY)
    link_libraries("${MATH_LIBRARY}")
endif()


if (WIN32)
    set(ICON glfw.rc)
elseif (APPLE)
    set(ICON glfw.icns)
    set_source_files_properties(glfw.icns PROPERTIES
        MACOSX_PACKAGE_LOCATION "Resources")
endif()

set(GLAD "${GLFW_SOURCE_DIR}/deps/glad/glad.h"
         "${GLFW_SOURCE_DIR}/deps/glad.c")
set(GETOPT "${GLFW_SOURCE_DIR}/deps/getopt.h"
           "${GLFW_SOURCE_DIR}/deps/getopt.c")
set(TINYCTHREAD "${GLFW_SOURCE_DIR}/deps/tinycthread.h"
                "${GLFW_SOURCE_DIR}/deps/tinycthread.c")


add_executable(assimpmodel
        glfwmodel.cpp
        AssimpLoader.cpp
        AssimpModel.cpp
        misc.cpp
        myGLCamera.cpp
        myShader.cpp
        ${ICON}
        ${GLAD})


if (APPLE)
    set_target_properties(assimpmodel PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "assimpmodel")
endif()

