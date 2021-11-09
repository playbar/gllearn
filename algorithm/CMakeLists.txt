include_directories(${glfw_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../glm
        )

add_executable(CalNormalVector
        CalNormalVector.cpp)

add_executable(pointtest
        pionttest.cpp
       )

add_executable(octree
        octree.cpp)

add_executable(mainoctree
        mainoctree.cpp)

add_executable(psimpl_test
        psimpl_test.cpp)

add_executable(clipper_console_demo
        clipper_console_demo.cpp
        clipper.cpp)
