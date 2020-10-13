#include <rayhit.h>

RayHit::RayHit(glm::vec4 hitSurfaceNormal, Material hitSurfaceMaterial) : _hitSurfaceNormal(hitSurfaceNormal), _hitSurfaceMaterial(hitSurfaceMaterial), hasHit(false)
{}