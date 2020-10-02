#pragma once

#include <vector>

#include <glm/glm.hpp>

#include <ray.h>
#include <vertex.h>
#include <triangle.h>
#include <material.h>

class Lightsource
{
    public:
        Lightsource(Vertex pos, float sideLength, Material material);

        void rayIntersection(Ray &ray);

        std::vector<Triangle> _triangles;
        Material _material;
};