//
// Created by ryanm on 2/1/2021.
//
/// Source code as part of Jamie King's opengl youtube playlist

#include <GL/glew.h>
#include "MeGlWindow.h"

void MeGlWindow::initializeGL()
{
    glewInit() ;

    GLfloat verts[] =
        {
            +0.0f, +0.0f, /// position vertex
            +0.0, +0.0, +0.0, /// color

            +1.0f, +1.0f,
            +0.0, +0.0, +0.0,

            -1.0f, +1.0f,
            +0.0, +0.0, +0.0,

            -1.0f, -1.0f,
            +0.0, +0.0, +0.0,

            +1.0f, -1.0f,
            +0.0, +0.0, +0.0,
        };

    GLuint vertexBufferID ;
    glGenBuffers(1, &vertexBufferID) ;
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID) ;
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW) ;
    glEnableVertexAttribArray(0);

    /// attribute 0 is position
    /// third arguement defines the stride for any given attribute (i.e., position, color, etc.)
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*5, 0);
    /// attribute 1 is color
    glEnableVertexAttribArray(1);
    /// the GL_FALSE arguement is a glbool for normalization
    /// final arguement is where the first row of data for given attribute starts
    /// in our case the color data starts at the third float element
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float)*5, (char*)(sizeof(float)*2));

    // using a short to optimize the usage of detotated wam, especially since we are using modest wam
    GLushort indices[] = {0,1,2, 0,3,4};
    GLuint indexBufferID;
    glGenBuffers(1, &indexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}

void MeGlWindow::paintGL()
{
    /// modify the viewing matrix.  This will ensure that the viewing plane always stretches to the screen.
    glViewport(0, 0, width(), height());
    //glDrawArrays(GL_TRIANGLES, 0, 6) ;
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
}
