#pragma once

class Ray; //Forward declaration to fix circular dependancy

#include <glm/glm.hpp>

#include <vertex.h>
#include <material.h>
#include <direction.h>
#include <ray.h>

class Triangle
{
    public:
        Triangle(Vertex v0, Vertex v1, Vertex v2, Material material);
        ~Triangle();
        bool rayIntersection(Ray& ray);

        Vertex _v0, _v1, _v2;
        Material _material;
        Direction *_normal;
};