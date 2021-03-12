//
// Created by ryanm on 3/11/2021.
//

#include "Camera.h"
#include <gtx/transform.hpp>

// looking down z-direction
Camera::Camera() :
    viewDirection(0.0f, 0.0f, -1.0f),
    UP(0.0f, 1.0f, 0.0f),
    position(0.0f, 0.0f, 0.0f)
{
}

Camera::~Camera() {}

glm::mat4 Camera::getWorldToViewMatrix() const
{
    return glm::lookAt(position, position + viewDirection, UP) ;
}

