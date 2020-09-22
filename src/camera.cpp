#include <camera.h>

Camera::Camera(Vertex &eyepointOne, Vertex &eyepointTwo) : eyepointOne(eyepointOne), eyepointTwo(eyepointTwo)
{
    for(int x = 0; x<800; x++)
    {
        std::vector<Pixel> tempRow;
        for(int y = 0; y<800; y++)
        {
            Pixel pixel;
            tempRow.push_back(pixel);
        }
        pixels.push_back(tempRow);
    }
}

Camera::~Camera()
{}

void Camera::render()
{
    //TODO: Implement render()
    for(int x = 0; x<800; x++)
    {
        for(int y = 0; y<800; y++)
        {
            std::cout << pixels[x][y].color.r << std::endl;
        }
    }
}

void Camera::createImage()
{
    //TODO: Implement createImage()
}
