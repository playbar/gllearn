link_libraries(glfw)
link_libraries(assimp)
link_libraries(opencv_core)
link_libraries(opencv_imgproc)
link_libraries(opencv_imgcodecs)
link_libraries(opencv_highgui)
link_libraries(libpng)
link_libraries(libjpeg-turbo)


include_directories(${glfw_INCLUDE_DIRS}
        "${GLFW_SOURCE_DIR}/deps"
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../glm
        ${CMAKE_CURRENT_SOURCE_DIR}/../pb
        ${CMAKE_CURRENT_SOURCE_DIR}/../assimp/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/3rdparty/libpng
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/3rdparty/libjpeg-turbo
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/calib3d/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/core/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/dnn/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/features2d/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/flann/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/highgui/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/imgcodecs/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/imgproc/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/ml/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/objdetect/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/photo/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/shape/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/stitching/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/superres/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/videoio/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/video/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../opencv/modules/videostab/include
        )

if (MATH_LIBRARY)
    link_libraries("${MATH_LIBRARY}")
endif()


set_source_files_properties(glfw.icns PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

set(GLAD "${GLFW_SOURCE_DIR}/deps/glad/glad.h"
         "${GLFW_SOURCE_DIR}/deps/glad.c")
set(GETOPT "${GLFW_SOURCE_DIR}/deps/getopt.h"
           "${GLFW_SOURCE_DIR}/deps/getopt.c")
set(TINYCTHREAD "${GLFW_SOURCE_DIR}/deps/tinycthread.h"
                "${GLFW_SOURCE_DIR}/deps/tinycthread.c")


add_library(imagelib STATIC
        cutil/CRegExp.cpp
        cutil/CRGBName.cpp
        fileutil/CFile.cpp
        fileutil/CFileBase.cpp
        fileutil/CFileUtil.cpp
        fileutil/CImageFileUtil.cpp
        fileutil/CSoundFileUtil.cpp
        fileutil/CTextFileUtil.cpp
        src/CImage.cpp
        src/CImageAnim.cpp
        src/CImageColorDef.cpp
        src/CImageConvert.cpp
        src/CImageFile.cpp
        src/CImageFilter.cpp
        src/CImageGen.cpp
        src/CImageGIF.cpp
        src/CImageMgr.cpp
        src/CImageState.cpp
        src/CImageXBM.cpp
        src/CImageXPM.cpp
        strutil/CPrintF.cpp
        strutil/CStrUtil.cpp
        )

target_include_directories(imagelib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_CURRENT_SOURCE_DIR}/cmath
        ${CMAKE_CURRENT_SOURCE_DIR}/cutil
        ${CMAKE_CURRENT_SOURCE_DIR}/fileutil
        ${CMAKE_CURRENT_SOURCE_DIR}/regex/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/strutil
        )

add_executable(CImageColorReplace
        test/CImageColorReplace.cpp
        ${GLAD})

target_link_libraries(CImageColorReplace imagelib)




