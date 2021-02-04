//
// Created by ryanm on 1/28/2021.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <GL/freeglut.h>
#include <iostream>
#include "common_drawing.h"

void renderWhiteRectangle();
void renderColorfulTriangle(GLFWwindow *w);
void display();
void init();

int CreateAWindow()
{

    GLFWwindow * window;

    // Initialize the library
    if (!glfwInit())
        return -1 ;

    // Create a windowed mode window and its OpenGL Context
    window = glfwCreateWindow(800, 600, "Test OpenGl Window", NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        return -1;
    }
    // make the window's context current
    glfwMakeContextCurrent(window);


    // loop until the user closes the window, (event loop)
    while(!glfwWindowShouldClose(window))
    {
        //Render stuff here
        //glClear(GL_COLOR_BUFFER_BIT);

        renderColorfulTriangle(window) ;

        //Swap front and back buffers
        glfwSwapBuffers(window);
        //poll for and process events
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}


void renderWhiteRectangle()
{
    glClearColor(0.0, 0.0, 0.0, 0.0) ;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON) ;
        glVertex3f(0.25, 0.25, 0.0);
        glVertex3f(0.75, 0.25, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glVertex3f(0.25, 0.75, 0.0);
    glEnd();
    //glFlush();

}

void renderColorfulTriangle(GLFWwindow *window)
{
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
}