#pragma once

#include <vertex.h>
#include <colordbl.h>

class Ray
{
    public:
        Ray(Vertex &start, Vertex &end, ColorDbl &color);

        Vertex &start, &end;
        ColorDbl &color;
        
};