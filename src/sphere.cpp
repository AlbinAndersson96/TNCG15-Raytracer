#include <sphere.h>

Sphere::Sphere(Vertex position, Material material, float radius) : _position(position), _material(material), _radius(radius)
{}  

void Sphere::rayIntersection(Ray &ray)
{
    glm::vec4 rayDir = ray._direction;
    float a = glm::dot(rayDir, rayDir);
    float b = glm::dot(2.0f*rayDir, ray._start - _position._location);
    float c = glm::dot((ray._start - _position._location), ray._start - _position._location) - _radius*_radius;

    float dPos = -b/2 + sqrt((b/2)*(b/2) - a*c);
    float dNeg = -b/2 - sqrt((b/2)*(b/2) - a*c);

    if(dPos < dNeg && dPos > 0)
    {
        ray._t = dPos;                                                                                                              
        ray._intersectionPoint = ray._start + dPos*rayDir;
        _normal = glm::normalize(ray._intersectionPoint - _position._location);
        ray._color = _material._color * glm::abs(glm::dot(_normal, ray._direction));
    }
    else if(dPos > dNeg && dNeg > 0)
    {
        ray._t = dNeg;
        ray._intersectionPoint = ray._start + dNeg*rayDir;
        _normal = glm::normalize(ray._intersectionPoint - _position._location);
        ray._color = _material._color * glm::abs(glm::dot(_normal, ray._direction));
    }
}