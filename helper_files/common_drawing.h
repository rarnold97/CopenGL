//
// Created by ryanm on 1/28/2021.
//

#ifndef COPENGL_COMMON_DRAWING_H
#define COPENGL_COMMON_DRAWING_H
#include "LoadShaders.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdio.h>
#include <string.h>



/// just need to pass in the color here
void setColor(char* color);

/// overload for the standard rgb
void setColor(const float r, const float g, const float b);

/// Page 41 of red book
void reshape(int w, int h) ;

// define those rad enums, yo
/*
enum VAO_IDs { Triangles, NumVAOs};
enum Buffer_IDs {ArrayBuffer, NumBuffers};
enum Attribs_IDs { vPosition = 0};

GLuint VAOs[NumVAOs] ;
GLuint Buffers[NumBuffers];
const GLuint NumVertices = 6 ;
*/
#endif //COPENGL_COMMON_DRAWING_H
