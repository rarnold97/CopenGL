//
// Created by ryanm on 2/20/2021.
//

#ifndef COPENGL_VERTEX_H
#define COPENGL_VERTEX_H

#include <glm.hpp>

const unsigned int NUM_FLOATS_PER_VERTICE = 6;
const unsigned int VERTEX_BYTE_SIZE = NUM_FLOATS_PER_VERTICE * sizeof(float) ;

struct Vertex
{
    glm::vec3 position;
    glm::vec3 color;
};





#endif //COPENGL_VERTEX_H
