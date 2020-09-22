#include <vertex.h>
#include <camera.h>

int main()
{
    Vertex eyepointOne(-2.0f, 0.0f, 0.0f, 1.0f);
    Vertex eyepointTwo(-1.0f, 0.0f, 0.0f, 1.0f);

    Camera camera(eyepointOne, eyepointTwo);
    camera.createImage();

    return 0; 
}