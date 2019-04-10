link_libraries(glfw)
link_libraries(assimp)

include_directories(${glfw_INCLUDE_DIRS}
        "${GLFW_SOURCE_DIR}/deps"
        ${CMAKE_CURRENT_SOURCE_DIR}/../assimp/include
        ${CMAKE_CURRENT_SOURCE_DIR})

if (MATH_LIBRARY)
    link_libraries("${MATH_LIBRARY}")
endif()

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

if (GLFW_USE_OSMESA)
    add_definitions(-DUSE_NATIVE_OSMESA)
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
        simple.cpp
        assimpLoader.cpp
        misc.cpp
        myGLCamera.cpp
        myGLFunctions.cpp
        myShader.cpp
        modelAssimp.cpp
        ${ICON}
        ${GLAD})


if (MSVC)
    # Tell MSVC to use main instead of WinMain for Windows subsystem executables
    set_target_properties(${WINDOWS_BINARIES} PROPERTIES
                          LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

if (APPLE)
    set_target_properties(assimpmodel PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "assimpmodel")
endif()

