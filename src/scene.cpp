#include <scene.h>

Scene::Scene()
{}

void Scene::determineIntersections(Ray &ray)
{
    for(Triangle triangle : triangles)
    {
        triangle.rayIntersection(ray);
    }
}