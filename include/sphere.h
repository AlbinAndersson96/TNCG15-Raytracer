#pragma once

#include <glm/glm.hpp>
#include <material.h>
#include <ray.h>
#include <direction.h>

class Sphere
{
    public:
        Sphere(glm::vec3 position, Material material, float radius);

        bool rayIntersection(Ray& ray);

        glm::vec3 _position;
        Material _material;
        float _radius;
};