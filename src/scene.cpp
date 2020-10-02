#include <scene.h>

Scene::Scene()
{}

void Scene::determineIntersections(Ray &ray)
{
    for(Entity *entity : _entities)
        entity->rayIntersection(ray);
}