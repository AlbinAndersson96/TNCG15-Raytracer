#include <triangle.h>

Triangle::Triangle(Vertex &v1, Vertex &v2, Vertex &v3, ColorDbl &color) : _v1(v1), _v2(v2), _v3(v3), _color(color)
{
    // Calculate surface normal by crossing 2 edges of triangle, converted from homogenous to cartesian coordinates for safety
    glm::vec3 surfaceNormal = glm::cross(
                                glm::vec3(glm::vec3(v1._location.x/v1._location.w, v1._location.y/v1._location.w, v1._location.z/v1._location.w)) - glm::vec3(glm::vec3(v3._location.x/v3._location.w, v3._location.y/v3._location.w, v3._location.z/v3._location.w)),
                                glm::vec3(glm::vec3(v3._location.x/v3._location.w, v3._location.y/v3._location.w, v3._location.z/v3._location.w)) - glm::vec3(glm::vec3(v2._location.x/v2._location.w, v2._location.y/v2._location.w, v2._location.z/v2._location.w))
                            );
    _normal = new Direction(glm::vec4(surfaceNormal, 1.0f));
}

Triangle::~Triangle()
{
    delete _normal;
}

Vertex Triangle::rayIntersection(Ray& ray)
{
    //TODO: Implement Möller-Trumbore algorithm for intersections
    Vertex intersection{glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)};

    //TODO: Pass intersection point to ray

    return intersection;
}