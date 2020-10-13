#pragma once

class Entity; //Forward declaration to fix circular dependancy

#include <glm/glm.hpp>

#include <vertex.h>
#include <colordbl.h>
#include <rayhit.h>

class Ray
{
    public:
        Ray(glm::vec4 start, glm::vec4 direction);

        glm::vec4 _start, _direction;
        RayHit *_rayHit;
        glm::vec4 _intersectionPoint;
        float _t;
};