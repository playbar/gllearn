//
// Created by hou guoli on 2019/5/31.
//

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "vector"

int pointInPoly(std::vector< glm::vec2>&verts, float testx, float testy)
{
    int i, j, c = 0;
    int nvert = verts.size();
    for (i = 0, j = nvert-1; i < nvert; j = i++)
    {
        if ( ((verts[i].y>testy) != (verts[j].y>testy)) &&
             (testx < (verts[j].x-verts[i].x) * (testy-verts[i].y) /
                              (verts[j].y-verts[i]).y + verts[i].x) )
            c = !c;
    }
    return c;
}


bool pointIPloy1(std::vector< glm::vec2>&verts, float testx, float testy)
{
    bool bin = false;
    for( int i = 0; i < verts.size(); ++i )
    {
        if( )
    }
    return bin;
}

int main(int argc, char** argv)
{
    std::vector< glm::vec2> verts;
    verts.emplace_back(glm::vec2(2.0, 2.0));
    verts.emplace_back(glm::vec2(2.0, -2.0));
    verts.emplace_back(glm::vec2(-2.0, -2.0));
    verts.emplace_back(glm::vec2(-2.0, 2.0));

    bool bin = pointInPoly(verts, 3.0, 1.0);

    return 0;
}