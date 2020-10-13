#pragma once

#include <vector>

#include <entity.h>

#include <ray.h>
#include <triangle.h>
#include <lambertianbrdf.h>

class Room : public Entity
{
    public:
        Room();
        ~Room();

        virtual void rayIntersection(Ray &ray);

        std::vector<Triangle> _triangles;
};