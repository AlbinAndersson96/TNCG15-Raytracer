#include <ray.h>

Ray::Ray(Vertex &start, Vertex &end, ColorDbl &color, Triangle &endTriangle) : start(start), end(end), color(color), endTriangle(endTriangle)
{}