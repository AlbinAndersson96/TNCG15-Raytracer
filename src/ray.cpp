#include <ray.h>

Ray::Ray(glm::vec4 start, glm::vec4 end, ColorDbl color, Triangle *endTriangle) : _start(start), _end(end), _color(color), _endTriangle(endTriangle), _t(100000)
{}