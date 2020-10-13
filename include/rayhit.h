#pragma once

#include <material.h>

class RayHit
{
    public:
        RayHit(glm::vec4 hitSurfaceNormal, Material _hitSurfaceMaterial);

        glm::vec4 _hitSurfaceNormal;
        Material _hitSurfaceMaterial;
        bool hasHit;
};