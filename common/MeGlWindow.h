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
#include "Camera.h"

// define some constants yo
const float X_DELTA = 0.1f ;
const uint NUM_VERTICES_PER_TRI = 3;
const uint NUM_FLOATS_PER_VERTICES = 6 ;
const uint TRIANGLE_BYTE_SIZE = NUM_VERTICES_PER_TRI * NUM_FLOATS_PER_VERTICES * sizeof(float);
const uint MAX_TRIS = 20 ;



class MeGlWindow : public QGLWidget
{

    void sendDataToOpenGL();
    bool checkStatus(GLuint objectID,
                     PFNGLGETSHADERIVPROC objectPropertyGetterFunc,
                     PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
                     GLenum statusType) ;
    bool checkShaderStatus(GLuint shaderID) ;
    bool checkProgramStatus(GLuint programID) ;
    std::string readShaderCode(const char* fileName) ;
    void installShaders();

protected:
    void initializeGL();
    void paintGL();
    void sendAnotherTriToOpenGL() ;

    GLuint programID{} ;
    GLuint numIndices{} ;

    GLint positionLocation ;
    GLint colorLocation ;
    GLint transformLocation ;

    Camera camera;

public:

    MeGlWindow() ;
    ~MeGlWindow() ;


};

#endif //COPENGL_MEGLWINDOW_H
