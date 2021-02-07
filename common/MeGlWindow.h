//
// Created by ryanm on 2/1/2021.
//
// source code as part of Jamie King's opengl playlist

#ifndef COPENGL_MEGLWINDOW_H
#define COPENGL_MEGLWINDOW_H

//#include <GLFW/glfw3.h>
#include <QApplication>
#include <QtOpenGL/QGLWidget>



class MeGlWindow : public QGLWidget
{
protected:
    void initializeGL();
    void paintGL();
public:

};

#endif //COPENGL_MEGLWINDOW_H
