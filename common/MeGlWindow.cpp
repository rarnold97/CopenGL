//
// Created by ryanm on 2/1/2021.
//
/// Source code as part of Jamie King's opengl youtube playlist

#include <GL/glew.h>
#include "MeGlWindow.h"
#include <iostream>
#include "common/Primitaves/Vertex.h"
#include "common/Primitaves/ShapeGenerator.h"
#include <gtx/transform.hpp>


MeGlWindow::MeGlWindow()
{
}

MeGlWindow::~MeGlWindow()
{
    glUseProgram(0) ;
    glDeleteProgram(programID);
}


bool MeGlWindow::checkStatus(GLuint objectID,
                 PFNGLGETSHADERIVPROC objectPropertyGetterFunc,
                 PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
                 GLenum statusType)
{
    GLint status ;
    objectPropertyGetterFunc(objectID, statusType, &status) ;
    if (status != GL_TRUE)
    {
        GLint infoLogLength ;
        objectPropertyGetterFunc(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* buffer = new GLchar[infoLogLength];

        GLsizei bufferSize;
        getInfoLogFunc(objectID, infoLogLength, &bufferSize, buffer);
        std::cout << buffer << std::endl;

        delete [] buffer;
        return false;
    }
    return true;
}

bool MeGlWindow::checkShaderStatus(GLuint shaderID)
{
    return checkStatus(shaderID, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS) ;
}


bool MeGlWindow::checkProgramStatus(GLuint programID)
{
    return checkStatus(programID, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);
}

std::string MeGlWindow::readShaderCode(const char* fileName)
{
    std::ifstream meInput(fileName);
    if ( ! meInput.good())
    {
        std::cout << "File failed to load ..." << fileName;
        exit(1) ;
    }
    return std::string(
            std::istreambuf_iterator<char>(meInput),
                    std::istreambuf_iterator<char>()
            );

}

void MeGlWindow::installShaders()
{
    // going to use gl shading language
    GLuint vertexShaderID =  glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    const GLchar* adapter[1];
    std::string vertexCode = readShaderCode("shaders/VertexShaderCode.glsl") ;
    std::string fragmentCode = readShaderCode("shaders/FragmentShaderCode.glsl") ;
    ///@todo eventually add a qt openfiledialog for this
    adapter[0] = vertexCode.c_str() ;
    glShaderSource(vertexShaderID, 1, adapter, 0);
    adapter[0] = fragmentCode.c_str();
    glShaderSource(fragmentShaderID, 1, adapter, 0);

    glCompileShader(vertexShaderID);
    glCompileShader(fragmentShaderID);

    if (!checkShaderStatus(vertexShaderID) || !checkShaderStatus(fragmentShaderID))
        return ;

    //GLuint programID{} = glCreateProgram() ;
    programID = glCreateProgram() ;
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glBindAttribLocation(programID, 0, "position") ;
    glLinkProgram(programID) ;

    if (! checkProgramStatus(programID))
        return ;

    positionLocation = glGetAttribLocation(programID, "position") ;
    colorLocation = glGetAttribLocation(programID, "vertexColor") ;
    transformLocation = glGetAttribLocation(programID, "fullTransformMatrix") ;

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    glUseProgram(programID);
}

void MeGlWindow::initializeGL()
{
    glewInit() ;
    // enable depth buffer for z-axis data
    glEnable(GL_DEPTH_TEST);
    // member functions
    installShaders();
    sendDataToOpenGL();


}

//define constant
uint numTris = 0 ;
void MeGlWindow::sendAnotherTriToOpenGL()
{
    if (numTris == MAX_TRIS)
        return ;

    const GLfloat THIS_TRI_X = -1 + numTris * X_DELTA ;
    GLfloat thisTri[] =
            {
                THIS_TRI_X, 1.0f, 0.0f,
                1.0f, 0.0f, 0.0f,  //RED

                THIS_TRI_X + X_DELTA, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f,  //RED

                THIS_TRI_X, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f,  //RED
            };
    glBufferSubData(GL_ARRAY_BUFFER, numTris * TRIANGLE_BYTE_SIZE, TRIANGLE_BYTE_SIZE, thisTri);
    numTris++ ;
}


void MeGlWindow::sendDataToOpenGL()
{
    ShapeData shape = ShapeGenerator::makeCube() ;
    // we need to write shaders to change the colors of the triangles
    /// primarily concerned with vertex and fragment shaders
    GLuint vertexBufferID ;
    glGenBuffers(1, &vertexBufferID) ;
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID) ;
    glBufferData(GL_ARRAY_BUFFER, shape.vertexBufferSize(), shape.vertices, GL_STATIC_DRAW) ;
    glEnableVertexAttribArray(positionLocation);

    /// attribute 0 is position
    /// third arguement defines the stride for any given attribute (i.e., position, color, etc.)
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, VERTEX_BYTE_SIZE, 0);
    /// attribute 1 is color
    glEnableVertexAttribArray(colorLocation);
    /// the GL_FALSE arguement is a glbool for normalization
    /// final arguement is where the first row of data for given attribute starts
    /// in our case the color data starts at the third float element
    glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, VERTEX_BYTE_SIZE, (char*)(sizeof(float)*3));

    // using a short to optimize the usage of detotated wam, especially since we are using modest wam

    GLuint indexArrayBufferID;
    glGenBuffers(1, &indexArrayBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, shape.indexBufferSize(), shape.indices, GL_STATIC_DRAW);
    numIndices = shape.numIndices ;
    // manage heap memory
    shape.cleanup();

    GLuint transformationMatrixBufferID;
    glGenBuffers(1, &transformationMatrixBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, transformationMatrixBufferID) ;

    // attribute 2 is transformation, according to our shader code
    // recall that transformation is 16 floats (4x4 array)
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.0f), ((float)width()) / height(), 0.1f, 10.0f) ;
    glm::mat4 fullTransforms[] =
    {
        // First Instance
        projectionMatrix * camera.getWorldToViewMatrix() * glm::translate(glm::vec3(-1.0f, 0.0f, -5.0f)) * glm::rotate(glm::radians(36.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
        // Second Instance
        projectionMatrix * camera.getWorldToViewMatrix() * glm::translate(glm::vec3(1.0f, 0.0f, -5.75f)) * glm::rotate(glm::radians(126.0f), glm::vec3(0.0f, 1.0f, 0.0f))
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(fullTransforms), fullTransforms, GL_STATIC_DRAW);
    // first arguement is the attribute in the shader code
    // eventually put this into a loop
    glVertexAttribPointer(transformLocation , 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float)*0)) ;
    glVertexAttribPointer(transformLocation + 1, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float)*4)) ;
    glVertexAttribPointer(transformLocation + 2, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float)*8)) ;
    glVertexAttribPointer(transformLocation + 3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float)*12)) ;

    glEnableVertexAttribArray(transformLocation);
    glEnableVertexAttribArray(transformLocation +1);
    glEnableVertexAttribArray(transformLocation +2);
    glEnableVertexAttribArray(transformLocation +3);

    glVertexAttribDivisor(transformLocation, 1);
    glVertexAttribDivisor(transformLocation +1, 1);
    glVertexAttribDivisor(transformLocation +2, 1);
    glVertexAttribDivisor(transformLocation +3, 1);


}


void MeGlWindow::paintGL()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT) ;
    glViewport(0, 0, width()*devicePixelRatio(), height()*devicePixelRatio());
    glDrawElementsInstanced(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, 0, 2) ;

    /// triangles example
    //glDrawArrays(GL_TRIANGLES, 0, 6) ;
    //sendAnotherTriToOpenGL();
    //glDrawArrays(GL_TRIANGLES, (numTris-1) * NUM_VERTICES_PER_TRI, NUM_VERTICES_PER_TRI);

    /// colors example
    /*
    dominatingColor.r = 0;
    dominatingColor.b = 1;
    glUniform3fv(dominatingColorUniformLocation, 1, &dominatingColor[0]);
    glUniform1f(yFlipUniformLocation, -1.0f) ;
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0) ;
     */
}
