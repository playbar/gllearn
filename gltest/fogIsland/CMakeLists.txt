include_directories(
        ${PROJECT_SOURCE_DIR}/glm
        ${PROJECT_SOURCE_DIR}/glfw/include
        ${PROJECT_SOURCE_DIR}/glew/include
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_CURRENT_SOURCE_DIR}/soil
)
INCLUDE_DIRECTORIES(/System/Library/Frameworks)
FIND_LIBRARY(COCOA_LIBRARY Cocoa)
FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
FIND_LIBRARY(IOKit_LIBRARY IOKit)
FIND_LIBRARY(CoreVideo_LIBRARY CoreVideo)
MARK_AS_ADVANCED(COCOA_LIBRARY OpenGL_LIBRARY)
SET(APPLE_LIBS ${COCOA_LIBRARY} ${IOKit_LIBRARY} ${OpenGL_LIBRARY})
SET(APPLE_LIBS ${APPLE_LIBS} glfw assimp)
set(LIBS ${LIBS} ${APPLE_LIBS})

link_libraries(assimp)
link_libraries(libglew_static)

link_directories (${OPENGLEXAMPLES_BINARY_DIR}/bin)
 
add_executable (fogIsland Fog.cpp
        Light.cpp
        main.cpp
        ResourceManager.cpp
        shader.cpp
        Skybox.cpp
        Terrain.cpp
        Texture2D.cpp
        Water.cpp
        soil/image_DXT.c
        soil/image_helper.c
        soil/SOIL.c
        soil/stb_image_aug.c
        )
target_link_libraries(fogIsland ${LIBS})
target_include_directories(fogIsland PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_CURRENT_SOURCE_DIR}/soil)

