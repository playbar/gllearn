//
// Created by hou guoli on 2019/5/31.
//

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "vector"

int pointInPoly(std::vector< glm::vec2>&verts, glm::vec2 &point)
{
    int i, j, c = 0;
    int nvert = verts.size();
    for (i = 0, j = nvert-1; i < nvert; j = i++)
    {
        if ( ((verts[i].y > point.y) != (verts[j].y > point.y)) &&
             (point.x < (verts[j].x-verts[i].x) * (point.y-verts[i].y) /
                              (verts[j].y-verts[i]).y + verts[i].x) )
            c = !c;
    }
    return c;
}


/*
向量的点乘:a * b
公式：a * b = |a| * |b| * cosθ 点乘又叫向量的内积、数量积，是一个向量和它在另一个向量上的投影的长度的乘积；是标量。
 点乘反映着两个向量的“相似度”，两个向量越“相似”，它们的点乘越大。
向量的叉乘：a ∧ b

a ∧ b = |a| * |b| * sinθ 向量积被定义为： 模长：（在这里θ表示两向量之间的夹角(共起点的前提下)（0° ≤ θ ≤ 180°），
 它位于这两个矢量所定义的平面上。） 方向：a向量与b向量的向量积的方向与这两个向量所在平面垂直，且遵守右手定则。
 （一个简单的确定满足“右手定则”的结果向量的方向的方法是这样的：若坐标系是满足右手定则的，当右手的四指从a以不超过180度的转角转向b时，
 竖起的大拇指指向是c的方向。c = a ∧ b）
 */

bool pointIPloy1(std::vector< glm::vec2>&verts, glm::vec2 &point)
{
    bool bin = false;
    int i = 0;
    float total = 0.0f;
    for( i = 0; i < verts.size(); ++i )
    {
        glm::vec2 v1 = glm::normalize(verts[i]);
        glm::vec2 v2 = glm::normalize(point);
        float re = glm::dot(v1, v2);
        total += re;
//        if(re <= 0)
//        {
//            break;
//        }
    }
    if( total > -0.000001 && total < 0.000001)
//    if( i == verts.size() )
    {
        bin = true;
    }
    return bin;
}

bool testDotCroos()
{
    std::vector<glm::vec3> verts3;
    std::vector< glm::vec2> verts;
//    verts.emplace_back(glm::vec2(2.0, 2.0));
//    verts.emplace_back(glm::vec2(2.0, -2.0));
//    verts.emplace_back(glm::vec2(-2.0, -2.0));
//    verts.emplace_back(glm::vec2(-2.0, 2.0));

    verts.emplace_back(glm::vec2(1.0, 1.0));
    verts.emplace_back(glm::vec2(3.0, 1.0));
    verts.emplace_back(glm::vec2(3.0, 3.0));
    verts.emplace_back(glm::vec2(1.0, 3.0));

    for( int i = 0; i < 4; ++i )
    {
        glm::vec2 &first = verts[i];
        glm::vec2 &second = verts[(i+ 1) & 3];
        glm::vec2 temp = second - first;
        glm::vec2 diff = glm::normalize(temp);
        glm::vec3 val3 = glm::vec3(-diff.y, diff.x, (first.x * diff.y - first.y * diff.x) );
        verts3.emplace_back(val3);
    }

    glm::vec3 point1( 1.5, 1.5, 1.0);

    float r0 = glm::dot(verts3[0], point1);
    float r1 = glm::dot(verts3[1], point1);
    float r2 = glm::dot(verts3[2], point1);
    float r3 = glm::dot(verts3[3], point1);

    return true;
}

int main(int argc, char** argv)
{
    testDotCroos();
    std::vector< glm::vec2> verts;
    verts.emplace_back(glm::vec2(2.0, 2.0));
    verts.emplace_back(glm::vec2(3.0, 0.0));
    verts.emplace_back(glm::vec2(2.0, -2.0));
    verts.emplace_back(glm::vec2(-2.0, -2.0));
    verts.emplace_back(glm::vec2(-2.0, 2.0));
    glm::vec2 point(0.1, 0.1);

    bool binploy = pointInPoly(verts, point);

    binploy = pointIPloy1(verts, point);

    return 0;
}