//
// Created by ryanm on 2/1/2021.
//
// source code as part of Jamie King's opengl playlist

#ifndef COPENGL_MEGLWINDOW_H
#define COPENGL_MEGLWINDOW_H

//#include <GLFW/glfw3.h>
#include <QApplication>
#include <QtOpenGL/QGLWidget>
#include <iostream>
#include <string>
#include <fstream>

// define some constants yo
const float X_DELTA = 0.1f ;
const uint NUM_VERTICES_PER_TRI = 3;
const uint NUM_FLOATS_PER_VERTICES = 6 ;
const uint TRIANGLE_BYTE_SIZE = NUM_VERTICES_PER_TRI * NUM_FLOATS_PER_VERTICES * sizeof(float);
const uint MAX_TRIS = 20 ;



class MeGlWindow : public QGLWidget
{
protected:
    void initializeGL();
    void sendDataToOpenGL();
    void installShaders();
    std::string readShaderCode(const char* fileName) ;
    void sendAnotherTriToOpenGL() ;
public:
    void paintGL();
};

#endif //COPENGL_MEGLWINDOW_H
