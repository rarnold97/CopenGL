//
// Created by ryanm on 2/20/2021.
//

#ifndef COPENGL_SHAPEGENERATOR_H
#define COPENGL_SHAPEGENERATOR_H

#include "ShapeData.h"
#include "Vertex.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a)

class ShapeGenerator
{
public:
    static ShapeData makeTriangle();
    static ShapeData makeCube();
};


#endif //COPENGL_SHAPEGENERATOR_H
