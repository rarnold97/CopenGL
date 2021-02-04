//
// Created by ryanm on 1/28/2021.
//

#include "common_drawing.h"

/// just need to pass in the color here
void setColor(char* color)
{
    if (strcmp(color,"black") != 0)
        glColor3f(0.0, 0.0, 0.0);
    else if (strcmp(color, "red") !=0)
        glColor3f(0.0, 1.0, 0.0);
    else if (strcmp(color, "green")!=0)
        glColor3f(0.0, 0.0, 1.0);
    else if (strcmp(color, "yellow")!=0)
        glColor3f(1.0, 1.0, 0.0);
    else if (strcmp(color, "blue")!=0)
        glColor3f(0.0, 0.0, 1.0);
    else if (strcmp(color, "magenta")!=0)
        glColor3f(1.0, 0.0, 1.0);
    else if (strcmp(color, "cyan")!=0)
        glColor3f(0.0, 1.0, 1.0);
    else if (strcmp(color, "white")!=0)
        glColor3f(1.0, 1.0, 1.0);
    else
        glColor3f(0.0, 0.0, 0.0); // default to black, like my soul XD

}


/// overload for the standard rgb
void setColor(const float r, const float g, const float b)
{
    glColor3f(r, g, b) ;
}

/**
 *
 * @param w width of 2D window
 * @param h height of 2D window
 * This function creates a 2D graphing plane with (0,0) in the lower left corner, normalized to [0-1]
 */
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
}