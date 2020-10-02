#pragma once

#include <vector>

#include <glm/glm.hpp>

#include <ray.h>
#include <vertex.h>
#include <triangle.h>
#include <material.h>
#include <entity.h>

class Lightsource : public Entity
{
    public:
        Lightsource(Vertex pos, float sideLength, Material material);

        virtual void rayIntersection(Ray &ray);

        std::vector<Triangle> _triangles;
        Material _material;
};