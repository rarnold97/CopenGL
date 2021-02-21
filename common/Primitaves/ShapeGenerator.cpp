//
// Created by ryanm on 2/20/2021.
//

#include "ShapeGenerator.h"


ShapeData ShapeGenerator::makeTriangle()
{
    ShapeData ret;

    Vertex myTri[] =
    {
            glm::vec3(+0.0f, +1.0f, +0.0f),
            glm::vec3(+1.0f, +0.0f, +0.0f),

            glm::vec3(-1.0f, -1.0f, +0.0f),
            glm::vec3(+0.0f, +1.0f, +0.0f),

            glm::vec3(+1.0f, -1.0f, +0.0f),
            glm::vec3(+0.0f, +0.0f, +1.0f),
    };
    // get data off stack to heap so that it is not prematurely deleted
    ret.numVertices = sizeof(myTri) / sizeof(*myTri);
    ret.vertices = new Vertex[ret.numVertices];
    memcpy(ret.vertices, myTri, sizeof(myTri));

    GLushort indices[] = {0, 1, 2};
    ret.numIndices = sizeof(indices) / sizeof(*indices);
    ret.indices = new GLushort[ret.numIndices];
    memcpy(ret.indices, indices, sizeof(indices));

    return ret;
}