#include <camera.h>
#include <glm/glm.hpp>

Camera::Camera(Vertex &eyepointOne, Vertex &eyepointTwo) : eyepointOne(eyepointOne), eyepointTwo(eyepointTwo), currentEyepoint(1)
{
    for(int x = 0; x<800; x++)
    {
        std::vector<Pixel> tempRow;
        for(int y = 0; y<800; y++)
        {
            Pixel pixel;
            pixel.color.r = y*(255.0/800.0);
            pixel.color.g = 0.0;
            pixel.color.b = x*(255.0/800.0);
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
            
        }
    }
}

void Camera::createImage()
{
    //TODO: Implement createImage()
    std::ofstream outFile;
    outFile.open("out.ppm");
    outFile << "P3\n800 800\n255\n";

    for(int x = 0; x<800; x++)
    {
        for(int y = 0; y<800; y++)
        {
            outFile << (int)pixels[x][y].color.r << " " << (int)pixels[x][y].color.g << " " << (int)pixels[x][y].color.b << "\n";
        }
    }
    outFile.close();
}
