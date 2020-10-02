#include <glm/glm.hpp>

#include <vertex.h>
#include <material.h>
#include <colordbl.h>
#include <tetrahedron.h>
#include <sphere.h>
#include <lightsource.h>
#include <camera.h>
#include <scene.h>

int main()
{
    Scene scene;

    Vertex tetraV0(glm::vec4(10.0f, 0.0f, 1.0f, 1.0f));
    Vertex tetraV1(glm::vec4(10.0f, -1.0f, -1.0f, 1.0f));
    Vertex tetraV2(glm::vec4(9.0f, 0.0f, -1.0f, 1.0f));
    Vertex tetraV3(glm::vec4(10.0f, 1.0f, -1.0f, 1.0f));
    ColorDbl tetraColor(1.0, 1.0, 0.0);
    Material tetraMat(tetraColor);
    Tetrahedron tetrahedron(tetraV0, tetraV1, tetraV2, tetraV3, tetraMat);
    
    Vertex sphereV(glm::vec4(10.0f, -2.0f, 0.0f, 1.0f));
    ColorDbl sphereColor(1.0, 1.0, 1.0);
    Material sphereMat(sphereColor);
    Sphere sphere(sphereV, sphereMat, 1.0f);

    Vertex lightV(glm::vec4(10.0f, 2.0f, 0.0f, 1.0f));
    ColorDbl lightColor(1.0, 0.0, 1.0);
    Material lightMat(lightColor);
    Lightsource lightSource(lightV, 1.0f, lightMat);

    scene._entities.push_back(&tetrahedron);
    scene._entities.push_back(&sphere);

    scene._lightSources.push_back(lightSource);

    Camera camera(1, 2);
    camera.render(scene);
    camera.createImage();

    return 0; 
}