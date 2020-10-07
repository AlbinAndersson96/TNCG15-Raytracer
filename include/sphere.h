#pragma once

#include <glm/glm.hpp>

#include <ray.h>
#include <entity.h>
#include <material.h>
#include <vertex.h>

class Sphere : public Entity
{
    public:
        Sphere(Vertex position, Material material, float radius);

        virtual void rayIntersection(Ray &ray);

        Vertex _position;
        Material _material;
        float _radius;
        glm::vec4 _normal;
};