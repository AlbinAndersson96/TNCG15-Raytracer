#include <ray.h>

Ray::Ray(glm::vec4 start, glm::vec4 direction) : _start(start), _direction(direction), _t(100000)
{
    _rayHit = new RayHit(glm::vec4(0.0f, 0.0f, 0.0f, 0.0f), Material());
}