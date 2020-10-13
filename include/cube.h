#pragma once

#include <vector>

#include <glm/glm.hpp>

#include <ray.h>
#include <vertex.h>
#include <triangle.h>
#include <material.h>
#include <entity.h>

class Cube : public Entity
{
    public:
        Cube(Vertex pos, float sideLength, Material material);

        virtual void rayIntersection(Ray &ray);

        std::vector<Triangle> _triangles;
};