file(GLOB BOX2D_COLLISOIN_SRC ./Box2D/Collision/*.cpp)
file(GLOB BOX2D_COLLISOIN_SHAPES_SRC ./Box2D/Collision/Shapes/*.cpp)
file(GLOB BOX2D_COMMON_SRC ./Box2D/Common/*.cpp)
file(GLOB BOX2D_DYNSMICS_SRC ./Box2D/Dynamics/*.cpp)
file(GLOB BOX2D_DYNSMICS_CONTACTS_SRC ./Box2D/Dynamics/Contacts/*.cpp)
file(GLOB BOX2D_DYNSMICS_JOINTS_SRC ./Box2D/Dynamics/Joints/*.cpp)
file(GLOB BOX2D_ROPE_SRC ./Box2D/Dynamics/*.cpp)



include_directories(
        ./
        ./Box2D
        ./Box2D/Collision
        )

add_library(box2d
        ${BOX2D_COLLISOIN_SRC}
        ${BOX2D_COLLISOIN_SHAPES_SRC}
        ${BOX2D_COMMON_SRC}
        ${BOX2D_DYNSMICS_SRC}
        ${BOX2D_DYNSMICS_CONTACTS_SRC}
        ${BOX2D_DYNSMICS_JOINTS_SRC}
        ${BOX2D_ROPE_SRC}
        )


add_executable(box2d_helloworld
        HelloWorld/HelloWorld.cpp
       )

target_link_libraries(box2d_helloworld
        box2d)

