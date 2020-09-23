#include <scene.h>

Scene::Scene()
{}

void Scene::determineIntersections(Ray &ray)
{
    for(Triangle triangle : _triangles)
    {
        triangle.rayIntersection(ray);
    }
}