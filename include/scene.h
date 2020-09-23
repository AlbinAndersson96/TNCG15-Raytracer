#pragma once

#include <vector>

#include <triangle.h>

class Scene
{
    public:
        Scene();
        void determineIntersections(Ray &ray);

        std::vector<Triangle> _triangles;
};