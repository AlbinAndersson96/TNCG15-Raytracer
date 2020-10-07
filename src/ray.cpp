#include <ray.h>

Ray::Ray(glm::vec4 start, glm::vec4 direction, ColorDbl color) : _start(start), _direction(direction), _color(color), _endEntity(nullptr), _t(100000)
{}