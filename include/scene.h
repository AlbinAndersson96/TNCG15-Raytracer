#pragma once

#include <vector>

#include <colordbl.h>
#include <triangle.h>

class Scene
{
    public:
        Scene();
        void determineIntersections(Ray &ray);

        std::vector<Triangle> _triangles;
};