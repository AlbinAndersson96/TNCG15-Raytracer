#pragma once

class Entity; //Forward declaration to fix circular dependancy

#include <glm/glm.hpp>

#include <vertex.h>
#include <colordbl.h>
#include <entity.h>

class Ray
{
    public:
        Ray(glm::vec4 start, glm::vec4 direction, ColorDbl color);

        glm::vec4 _start, _direction;
        ColorDbl _color;
        Entity *_endEntity;
        glm::vec4 _intersectionPoint;
        float _t;
};