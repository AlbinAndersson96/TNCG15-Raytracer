#include <vertex.h>
#include <camera.h>

int main()
{
    Vertex eyepointOne(0.0f, 0.0f, 0.0f, 0.0f);
    Vertex eyepointTwo(0.0f, -1.0f, 0.0f, 0.0f);

    Camera camera(eyepointOne, eyepointTwo);
    camera.render();

    return 0; 
}