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

ShapeData ShapeGenerator::makeCube()
{
    ShapeData ret;
    Vertex stackVerts[] =
    {
        glm::vec3(-1.0f, +1.0f, +1.0f), // 0
        glm::vec3(-1.0f, +0.0f, +0.0f), // Color
        glm::vec3(+1.0f, +1.0f, +1.0f), // 1
        glm::vec3(0.0f, +1.0f, +0.0f), // Color
        glm::vec3(+1.0f, +1.0f, -1.0f), // 2
        glm::vec3(+0.0f, +0.0f, +1.0f), // Color
        glm::vec3(-1.0f, +1.0f, -1.0f), // 3
        glm::vec3(+1.0f, +1.0f, +1.0f), // Color

        glm::vec3(-1.0f, +1.0f, -1.0f), // 4
        glm::vec3(+1.0f, +0.0f, +1.0f), // Color
        glm::vec3(+1.0f, +1.0f, -1.0f), // 5
        glm::vec3(+0.0f, +0.5f, +0.2f), // Color
        glm::vec3(+1.0f, -1.0f, -1.0f), // 6
        glm::vec3(+0.8f, +0.6f, +0.4f), // Color
        glm::vec3(-1.0f, -1.0f, -1.0f), // 7
        glm::vec3(+0.3f, +1.0f, +0.5f), // Color

        glm::vec3(+1.0f, +1.0f, -1.0f), // 8
        glm::vec3(+0.2f, +0.5f, +0.2f), // Color
        glm::vec3(+1.0f, +1.0f, +1.0f), // 9
        glm::vec3(+0.9f, +0.3f, +0.7f), // Color
        glm::vec3(+1.0f, -1.0f, +1.0f), // 10
        glm::vec3(+0.3f, +0.7f, +0.5f), // Color
        glm::vec3(+1.0f, -1.0f, -1.0f), // 11
        glm::vec3(+0.5f, +0.7f, +0.5f), // Color

        glm::vec3(-1.0f, +1.0f, +1.0f), // 12
        glm::vec3(+0.7f, +0.8f, +0.2f), // Color
        glm::vec3(-1.0f, +1.0f, -1.0f), // 13
        glm::vec3(+0.5f, +0.7f, +0.3f), // Color
        glm::vec3(-1.0f, -1.0f, -1.0f), // 14
        glm::vec3(+0.4f, +0.7f, +0.7f), // Color
        glm::vec3(-1.0f, -1.0f, +1.0f), // 15
        glm::vec3(+0.2f, +0.5f, +1.0f), // Color

        glm::vec3(+1.0f, +1.0f, +1.0f), // 16
        glm::vec3(+0.6f, +1.0f, +0.7f), // Color
        glm::vec3(-1.0f, +1.0f, +1.0f), // 17
        glm::vec3(+0.6f, +0.4f, +0.8f), // Color
        glm::vec3(-1.0f, -1.0f, +1.0f), // 18
        glm::vec3(+0.2f, +0.8f, +0.7f), // Color
        glm::vec3(+1.0f, -1.0f, +1.0f), // 19
        glm::vec3(+0.2f, +0.7f, +1.0f), // Color

        glm::vec3(+1.0f, -1.0f, -1.0f), // 20
        glm::vec3(+0.8f, +0.3f, +0.7f), // Color
        glm::vec3(-1.0f, -1.0f, -1.0f), // 21
        glm::vec3(+0.8f, +0.9f, +0.5f), // Color
        glm::vec3(-1.0f, -1.0f, +1.0f), // 22
        glm::vec3(+0.5f, +0.8f, +0.5f), // Color
        glm::vec3(+1.0f, -1.0f, +1.0f), // 23
        glm::vec3(+0.9f, +1.0f, +0.2f), // Color
    };

    ret.numVertices = NUM_ARRAY_ELEMENTS(stackVerts) ;
    ret.vertices = new Vertex[ret.numVertices] ;
    memcpy(ret.vertices, stackVerts, sizeof(stackVerts));

    unsigned short stackIndices[] = {
            0, 1, 2, 0, 2, 3, //Top
            4, 5, 6, 4, 6, 7, //Front
            8, 9, 10, 8, 10, 11, //Right
            12, 13, 14, 12, 14, 15, //Left
            16, 17, 18, 16, 18, 19, //Back
            20, 22, 21, 20, 23, 22, //Bottom
    };

    ret.numIndices = NUM_ARRAY_ELEMENTS(stackIndices);
    ret.indices = new GLushort[ret.numIndices] ;
    memcpy(ret.indices, stackIndices, sizeof(stackIndices)) ;

    return ret ;
}