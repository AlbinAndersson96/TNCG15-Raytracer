#pragma once

#include <iostream>
#include <vector>

#include <colordbl.h>
#include <triangle.h>
#include <material.h>

class Scene
{
    public:
        Scene();
        void determineIntersections(Ray &ray);

        std::vector<Triangle> _triangles;
};