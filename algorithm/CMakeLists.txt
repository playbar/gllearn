include_directories(${glfw_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../glm
        )

add_executable(pointtest
        pionttest.cpp
       )

add_executable(octree
        octree.cpp)

add_executable(mainoctree
        mainoctree.cpp)

add_executable(psimpl_test
        psimpl_test.cpp)