#include <glm/glm.hpp>

#include <vertex.h>
#include <colordbl.h>
#include <triangle.h>
#include <camera.h>

int main()
{
    //Verticies of the room
    Vertex r1(glm::vec4(-3.0f, 0.0f, 5.0f, 1.0f));
    Vertex r2(glm::vec4(-3.0f, 0.0f, -5.0f, 1.0f));
    Vertex r3(glm::vec4(0.0f, 6.0f, 5.0f, 1.0f));
    Vertex r4(glm::vec4(0.0f, 6.0f, -5.0f, 1.0f));
    Vertex r5(glm::vec4(0.0f, -6.0f, -5.0f, 1.0f));
    Vertex r6(glm::vec4(0.0f, -6.0f, -5.0f, 1.0f));
    Vertex r7(glm::vec4(10.0f, 6.0f, 5.0f, 1.0f));
    Vertex r8(glm::vec4(10.0f, 6.0f, -5.0f, 1.0f));
    Vertex r9(glm::vec4(10.0f, -6.0f, 5.0f, 1.0f));
    Vertex r10(glm::vec4(10.0f, -6.0f, -5.0f, 1.0f));
    Vertex r11(glm::vec4(13.0f, 0.0f, 5.0f, 1.0f));
    Vertex r12(glm::vec4(13.0f, 0.0f, -5.0f, 1.0f));

    ColorDbl roomColor(255.0, 255.0, 255.0);

    //Triangles of the room
    

    Vertex eyepointOne(glm::vec4(-2.0f, 0.0f, 0.0f, 1.0f));
    Vertex eyepointTwo(glm::vec4(-1.0f, 0.0f, 0.0f, 1.0f));

    Camera camera(eyepointOne, eyepointTwo);
    camera._currentEyepoint = 1; //First eyepoint 1, second 2
    camera.render();
    camera.createImage();

    return 0; 
}