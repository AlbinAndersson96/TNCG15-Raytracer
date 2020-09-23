#include <ray.h>

Ray::Ray(Vertex &start, Vertex &end, ColorDbl &color, Triangle &endTriangle) 
: _start(start), _end(end), _color(color), _endTriangle(endTriangle)
{}