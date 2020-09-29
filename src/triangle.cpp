#include <triangle.h>

Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2, Material material) : _v0(v0), _v1(v1), _v2(v2), _material(material)
{
    // Calculate surface normal by crossing 2 edges of triangle, converted from homogenous to cartesian coordinates for safety
    glm::vec3 surfaceNormal = glm::normalize(glm::cross(
                                glm::vec3(glm::vec3(v1._location.x/v0._location.w, v0._location.y/v0._location.w, v0._location.z/v1._location.w)) - glm::vec3(glm::vec3(v2._location.x/v2._location.w, v2._location.y/v2._location.w, v2._location.z/v2._location.w)),
                                glm::vec3(glm::vec3(v2._location.x/v2._location.w, v2._location.y/v2._location.w, v2._location.z/v2._location.w)) - glm::vec3(glm::vec3(v1._location.x/v1._location.w, v1._location.y/v1._location.w, v1._location.z/v1._location.w))
                            ));
    _normal = new Direction(glm::vec4(surfaceNormal, 1.0f));
}

Triangle::~Triangle()
{
    //delete _normal;
}

bool Triangle::rayIntersection(Ray& ray)
{
    const float EPSILON = 0.0000001f;
    glm::vec3 v0 = _v0._location;
    glm::vec3 v1 = _v1._location;
    glm::vec3 v2 = _v2._location;

    glm::vec3 rayDir = ray._end - ray._start;

    glm::vec3 e1, e2, h, s, q;
    float a, f, u, v;

    e1 = v1 - v0;
    e2 = v2 - v0;

    h = glm::cross(rayDir, e2);
    a = glm::dot(e1, h);

    if(a > -EPSILON && a < EPSILON)
        return false;

    f = 1.0f/a;
    s = glm::vec3(ray._start) - v0;
    u = f * glm::dot(s, h);

    if(u < 0.0f || u > 1.0f)
        return false;

    q = glm::cross(s, e1);
    v = f * glm::dot(rayDir, q);

    if(v < 0.0f || u+v > 1.0f)
        return false;

    float t = f * glm::dot(e2, q);
    if(t > EPSILON)
    {
        ray._intersectionPoint = ray._start + t * glm::vec4(rayDir, 1);
        ray._color = _material._color;
        return true;
    }
    else
        return false;
}