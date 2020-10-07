#pragma once

class Ray; //Forward declaration to fix circular dependancy

#include <ray.h>

class Entity
{
    public:
        virtual void rayIntersection(Ray& ray) = 0;
        virtual ~Entity() {};
};