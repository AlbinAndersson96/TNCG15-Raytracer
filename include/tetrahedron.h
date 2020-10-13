#pragma once

#include <entity.h>

#include <vertex.h>
#include <triangle.h>
#include <material.h>
#include <ray.h>

class Tetrahedron : public Entity
{
    public:
        Tetrahedron(Vertex v0, Vertex v1, Vertex v2, Vertex v3, Material material);
        ~Tetrahedron();

        virtual void rayIntersection(Ray &ray);

        Triangle *_t0, *_t1, *_t2, *_t3;
};