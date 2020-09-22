#include <triangle.h>

Triangle::Triangle(Vertex &v1, Vertex &v2, Vertex &v3, ColorDbl &color, Direction normal) : v1(v1), v2(v2), v3(v3), color(color), normal(normal)
{}

Vertex Triangle::rayIntersection(Ray& ray)
{
    //TODO: Implement Möller-Trumbore algorithm for intersections
    Vertex intersection{0.0f, 0.0f, 0.0f, 0.0f};

    //TODO: Pass intersection point to ray

    return intersection;
}