#include <glm/glm.hpp>

#include <vertex.h>
#include <material.h>
#include <colordbl.h>
#include <tetrahedron.h>
#include <sphere.h>
#include <cube.h>
#include <room.h>
#include <camera.h>
#include <scene.h>
#include <lambertianbrdf.h>

int main()
{
    Scene scene;

    Room room;

    LambertianBRDF brdf;

    Vertex tetraV0(glm::vec4(10.0f, 2.0f, -1.0f, 1.0f));
    Vertex tetraV1(glm::vec4(10.0f, 3.0f, 1.0f, 1.0f));
    Vertex tetraV2(glm::vec4(9.0f, 2.0f, 1.0f, 1.0f));
    Vertex tetraV3(glm::vec4(10.0f, 1.0f, 1.0f, 1.0f));
    ColorDbl tetraColor(1.0, 1.0, 0.0);
    Material tetraMat(tetraColor, false, &brdf);
    Tetrahedron tetrahedron(tetraV0, tetraV1, tetraV2, tetraV3, tetraMat);

    Vertex tetra2V0(glm::vec4(10.0f, -2.0f, -1.0f, 1.0f));
    Vertex tetra2V1(glm::vec4(10.0f, -3.0f, 1.0f, 1.0f));
    Vertex tetra2V2(glm::vec4(9.0f, -2.0f, 1.0f, 1.0f));
    Vertex tetra2V3(glm::vec4(10.0f, -1.0f, 1.0f, 1.0f));
    Tetrahedron tetrahedron2(tetra2V0, tetra2V1, tetra2V2, tetra2V3, tetraMat);
    
    Vertex sphereV(glm::vec4(10.0f, -1.0f, 0.0f, 1.0f));
    ColorDbl sphereColor(1.0, 0.0, 0.0);
    Material sphereMat(sphereColor, false, &brdf);
    Sphere sphere(sphereV, sphereMat, 1.0f);

    Vertex lightV(glm::vec4(10.0f, 0.0f, -6.0f, 1.0f));
    ColorDbl lightColor(1.0, 1.0, 1.0);
    Material lightMat(lightColor, true, &brdf);
    Cube lightSource(lightV, 4.0f, lightMat);

    scene._entities.push_back(&room);
    scene._entities.push_back(&tetrahedron);
    scene._entities.push_back(&lightSource);

    Camera camera(5, 2);
    camera.render(scene);
    camera.createImage();

    return 0; 
}