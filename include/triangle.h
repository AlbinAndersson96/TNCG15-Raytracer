#pragma once

class Ray; //Forward declaration to fix circular dependancy

#include <glm/glm.hpp>

#include <vertex.h>
#include <colordbl.h>
#include <direction.h>
#include <ray.h>

class Triangle
{
    public:
        Triangle(Vertex &v1, Vertex &v2, Vertex &v3, ColorDbl &color);
        ~Triangle();
        bool rayIntersection(Ray& ray);

        Vertex &_v1, &_v2, &_v3;
        ColorDbl &_color;
        Direction *_normal;
};