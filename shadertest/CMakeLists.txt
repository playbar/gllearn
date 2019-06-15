include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/common
        ${PROJECT_SOURCE_DIR}/glm
        ${PROJECT_SOURCE_DIR}/glfw/include
        ${PROJECT_SOURCE_DIR}/glew/include)

link_libraries(glfw)

file(GLOB COMMON_SRC
        common/glad.c
        common/stb_image.cpp)

add_executable(advanced_lighting
        lighting/advanced_lighting.cpp
        ${COMMON_SRC}
        )
