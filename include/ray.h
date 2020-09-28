#pragma once

class Triangle; //Forward declaration to fix circular dependancy

#include <glm/glm.hpp>

#include <vertex.h>
#include <colordbl.h>
#include <triangle.h>

class Ray
{
    public:
        Ray(glm::vec4 start, glm::vec4 end, ColorDbl color, Triangle *_endTriangle);

        glm::vec4 _start, _end;
        ColorDbl _color;
        Triangle *_endTriangle;
        glm::vec4 _intersectionPoint;
};