#pragma once

class Triangle; //Forward declaration to fix circular dependancy

#include <vertex.h>
#include <colordbl.h>
#include <triangle.h>

class Ray
{
    public:
        Ray(Vertex &start, Vertex &end, ColorDbl &color, Triangle &endTriangle);

        Vertex &start, &end;
        ColorDbl &color;
        Triangle &endTriangle;
};