#include <ray.h>

Ray::Ray(glm::vec4 start, glm::vec4 direction, ColorDbl color, Triangle *endTriangle) : _start(start), _direction(direction), _color(color), _endTriangle(endTriangle), _t(100000)
{}