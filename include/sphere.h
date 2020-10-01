#pragma once

#include <glm/glm.hpp>

#include <entity.h>

#include <material.h>
#include <ray.h>
#include <vertex.h>
#include <direction.h>

class Sphere : public Entity
{
    public:
        Sphere(Vertex position, Material material, float radius);

        virtual void rayIntersection(Ray &ray);

        Vertex _position;
        Material _material;
        float _radius;
};