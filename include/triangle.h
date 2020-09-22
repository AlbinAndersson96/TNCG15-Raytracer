#pragma once

#include <vertex.h>
#include <colordbl.h>
#include <direction.h>
#include <ray.h>

class Triangle
{
    public:
        Triangle(Vertex &v1, Vertex &v2, Vertex &v3, ColorDbl &color, Direction normal);
        Vertex rayIntersection(Ray &ray);

        Vertex &v1, &v2, &v3;
        ColorDbl &color;
        Direction normal;
};