#pragma once

#include <iostream>
#include <vector>

#include <colordbl.h>
#include <triangle.h>
#include <material.h>
#include <entity.h>
#include <lightsource.h>

class Scene
{
    public:
        Scene();
        void determineIntersections(Ray &ray);

        std::vector<Entity*> _entities;
};