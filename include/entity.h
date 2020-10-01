#pragma once

#include <ray.h>

class Entity
{
    public:
        virtual void rayIntersection(Ray& ray) = 0;
        virtual ~Entity() {};
};