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

bool Triangle::rayIntersection(Ray& ray)
{
    //This particular implementation of Möller-Trumbore was found on Stackoverflow and rewritten to fit this program

    float epsilon = 0.000001f;
    glm::vec3 v1v2 = _v2._location - _v1._location;
    glm::vec3 v1v3 = _v3._location - _v1._location;
    //NOTE: No conversion from homogenous to cartesian, only discarding W. Will be wrong if perspective transformed
    glm::vec3 p = glm::cross(glm::vec3(ray._end), glm::vec3(v1v3));

    float det = glm::dot(glm::vec3(v1v2), p);

    if(det < epsilon && det > -epsilon)
        return false;

    float inverseDet = 1.0f/det;

    glm::vec3 t = ray._start - _v1._location;

    float u = glm::dot(t, p) * inverseDet;
    if(u < 0 || u > 1)
        return false;

    glm::vec3 q = glm::cross(t, v1v2);

    float v = glm::dot(glm::vec3(ray._end - ray._start), q) * inverseDet;
    if(v < 0 || v > 1)
        return false;

    float t = glm::dot(v1v3, q) * inverseDet;

    //TODO: Pass intersection point to ray

    glm::vec3 intersection = glm::vec3(_v1._location) + u*v1v3+ + v*v1v2;

    ray._endTriangle = this;
    ray._intersectionPoint = glm::vec4(intersection, 1.0f);

    return true;
}