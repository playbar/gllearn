#https://www.shadertoy.com/browse

link_libraries(assimp)
link_libraries(libglew_static)


file(GLOB SOIL_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/soil/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/soil/*.h
        )

add_library(shsoil STATIC
        ${SOIL_SRC})

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)


#link_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(
        ${PROJECT_SOURCE_DIR}/glm
        ${PROJECT_SOURCE_DIR}/glfw/include
        ${PROJECT_SOURCE_DIR}/glew/include
        ${CMAKE_CURRENT_SOURCE_DIR}/soil
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

if(WIN32)
  set(LIBS glfw3 opengl32 glew32s SOIL assimp)
elseif(UNIX AND NOT APPLE)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
  find_package(OpenGL REQUIRED)
  add_definitions(${OPENGL_DEFINITIONS})
  find_package(X11 REQUIRED)
  # note that the order is important for setting the libs
  # use pkg-config --libs $(pkg-config --print-requires --print-requires-private glfw3) in a terminal to confirm
  set(LIBS ${GLFW3_LIBRARY} X11 Xrandr Xinerama Xi Xxf86vm Xcursor GL dl pthread GLEW SOIL assimp)
elseif(APPLE)
  INCLUDE_DIRECTORIES(/System/Library/Frameworks)
  FIND_LIBRARY(COCOA_LIBRARY Cocoa)
  FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
  FIND_LIBRARY(IOKit_LIBRARY IOKit)
  FIND_LIBRARY(CoreVideo_LIBRARY CoreVideo)
  MARK_AS_ADVANCED(COCOA_LIBRARY OpenGL_LIBRARY)
  SET(APPLE_LIBS ${COCOA_LIBRARY} ${IOKit_LIBRARY} ${OpenGL_LIBRARY})
  SET(APPLE_LIBS ${APPLE_LIBS} glfw assimp shsoil)
  set(LIBS ${LIBS} ${APPLE_LIBS})
else()
  set(LIBS )
endif(WIN32)

set(CHAPTERS
    advanced
    test1
)

set(advanced
        advanced_lighting
        cubemaps_skybox
        rimshader
        rimshader_normalize
        stencil_testing
        textures_vague
)

set(test1
        00skeleton
        01shader_vbo1
        01shader_vbo2
        02indexed_vbo
        03texture
        04perspective
        05fbo_fxaa
        06instancing1
        06instancing2_buffer_texture
        06instancing3_uniform_buffer
        07geometry_shader_blending
        08map_buffer
        09transform_feedback
        10queries_conditional_render
        11tesselation
        12shader_image_load_store
        13compute_shader_nbody
)


# first create relevant static libraries requried for other projects
add_library(stbimg "src/stb_image.cpp" "src/fps.cpp")
set(LIBS ${LIBS} stbimg)

add_library(gladlib "src/glad.c")
set(LIBS ${LIBS} gladlib)

macro(makeLink src dest target)
  add_custom_command(TARGET ${target} POST_BUILD COMMAND ${CMAKE_COMMAND} -E create_symlink ${src} ${dest}  DEPENDS  ${dest} COMMENT "mklink ${src} -> ${dest}")
endmacro()

# then create a project file per tutorial
foreach(CHAPTER ${CHAPTERS})
    foreach(DEMO ${${CHAPTER}})
        file(GLOB SOURCE
            "src/${CHAPTER}/${DEMO}/*.h"
            "src/${CHAPTER}/${DEMO}/*.cpp"
            "src/${CHAPTER}/${DEMO}/*.vs"
            "src/${CHAPTER}/${DEMO}/*.fs"
            "src/${CHAPTER}/${DEMO}/*.gs"
        )
        set(NAME "${CHAPTER}_${DEMO}")
        add_executable(${NAME} ${SOURCE})
        target_link_libraries(${NAME} ${LIBS})
        if(WIN32)
            set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CHAPTER}")
        elseif(UNIX AND NOT APPLE)
            set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/${CHAPTER}")
        elseif(APPLE)
            set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/${CHAPTER}")
            set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/bin/${CHAPTER}")
            set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/bin/${CHAPTER}")
        endif(WIN32)
        # copy shader files to build directory
        file(GLOB SHADERS
                 "src/${CHAPTER}/${DEMO}/*.vs"
                 # "src/${CHAPTER}/${DEMO}/*.frag"
                 "src/${CHAPTER}/${DEMO}/*.fs"
                 "src/${CHAPTER}/${DEMO}/*.gs"
        )
        foreach(SHADER ${SHADERS})
            if(WIN32)
                # configure_file(${SHADER} "test")
                add_custom_command(TARGET ${NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SHADER} $<TARGET_FILE_DIR:${NAME}>)
            elseif(UNIX AND NOT APPLE)
                file(COPY ${SHADER} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin/${CHAPTER})
            elseif(APPLE)
                # create symbolic link for *.vs *.fs *.gs
                get_filename_component(SHADERNAME ${SHADER} NAME)
                makeLink(${SHADER} ${CMAKE_CURRENT_BINARY_DIR}/bin/${CHAPTER}/${SHADERNAME} ${NAME})
            endif(WIN32)
        endforeach(SHADER)
        # if compiling for visual studio, also use configure file for each project (specifically to set up working directory)
        if(MSVC)
            configure_file(${CMAKE_SOURCE_DIR}/configuration/visualstudio.vcxproj.user.in ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.vcxproj.user @ONLY)
        endif(MSVC)
    endforeach(DEMO)
endforeach(CHAPTER)


