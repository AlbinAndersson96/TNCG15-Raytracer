#include <glm/glm.hpp>

#include <vertex.h>
#include <camera.h>
#include <scene.h>

int main()
{
    Scene scene;

    Vertex eyepointOne(glm::vec4(-2.0f, 0.0f, 0.0f, 1.0f));
    Vertex eyepointTwo(glm::vec4(-1.0f, 0.0f, 0.0f, 1.0f));

    Camera camera(eyepointOne, eyepointTwo, 10);
    camera._currentEyepoint = 2; //First eyepoint 1, second 2
    camera.render(scene);
    camera.createImage();

    return 0; 
}