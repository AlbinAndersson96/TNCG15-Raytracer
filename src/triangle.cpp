#include <triangle.h>

Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2, Material material) : _v0(v0), _v1(v1), _v2(v2), _material(material)
{
    // Calculate surface normal by crossing 2 edges of triangle
    glm::vec4 U = v1._location/v1._location.w - v0._location/v0._location.w;
    glm::vec4 V = v2._location/v2._location.w - v0._location/v0._location.w;
    glm::vec3 surfaceNormal = glm::normalize(glm::cross(glm::vec3(U), glm::vec3(V)));
    _normal = glm::vec4(surfaceNormal, 1.0f);
    
}

void Triangle::rayIntersection(Ray& ray)
{
    const float EPSILON = 0.0000001f;
    glm::vec3 v0 = _v0._location/_v0._location.w;
    glm::vec3 v1 = _v1._location/_v1._location.w;
    glm::vec3 v2 = _v2._location/_v2._location.w;

    glm::vec3 rayDir = ray._direction/ray._direction.w;

    glm::vec3 e1, e2, h, s, q;
    float a, f, u, v;

    e1 = v1 - v0;
    e2 = v2 - v0;

    h = glm::cross(rayDir, e2);
    a = glm::dot(e1, h);

    if(a > -EPSILON && a < EPSILON)
        return;

    f = 1.0f/a;
    s = glm::vec3(ray._start/ray._start.w) - v0;
    u = f * glm::dot(s, h);

    if(u < 0.0f || u > 1.0f)
        return;

    q = glm::cross(s, e1);
    v = f * glm::dot(rayDir, q);

    if(v < 0.0f || u+v > 1.0f)
        return;

    float t = f * glm::dot(e2, q);
    if(t > EPSILON)
    {
        if(t < ray._t)
        {
            ray._t = t;
            ray._intersectionPoint = ray._start + t * glm::vec4(rayDir, 1);
            
            ray._rayHit->hasHit = true;
            ray._rayHit->_hitSurfaceMaterial = _material;
            ray._rayHit->_hitSurfaceNormal = _normal;
        }
        return;
    }
    else
        return;
}