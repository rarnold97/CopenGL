//
// Created by ryanm on 3/11/2021.
//

#ifndef COPENGL_CAMERA_H
#define COPENGL_CAMERA_H

#include <glm.hpp>

class Camera
{
    glm::vec3 position ;
    glm::vec3 viewDirection ;
    const glm::vec3 UP ;

public:
    Camera() ;
    ~Camera() ;

    glm::mat4 getWorldToViewMatrix() const ;
};


#endif //COPENGL_CAMERA_H
