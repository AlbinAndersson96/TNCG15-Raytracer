#pragma once

class Ray; //Forward declaration to fix circular dependancy

#include <glm/glm.hpp>

#include <ray.h>
#include <material.h>

class Entity
{
    public:
        virtual void rayIntersection(Ray& ray) = 0;
        virtual ~Entity() {};

        Material _material;
};