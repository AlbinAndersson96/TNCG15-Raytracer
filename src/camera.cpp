#include <camera.h>
#include <glm/glm.hpp>

Camera::Camera(Vertex &eyepointOne, Vertex &eyepointTwo) : _eyepointOne(eyepointOne), _eyepointTwo(eyepointTwo), _currentEyepoint(1)
{
    for(int x = 0; x<800; x++)
    {
        std::vector<Pixel> tempRow;
        for(int y = 0; y<800; y++)
        {
            Pixel pixel;
            tempRow.push_back(pixel);
        }
        _pixels.push_back(tempRow);
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
            Pixel &pixel = _pixels[x][y];
            pixel._color._r = y*(255.0/800.0);
            pixel._color._g = 0.0;
            pixel._color._b = x*(255.0/800.0);
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
            outFile << (int)_pixels[x][y]._color._r << " " << (int)_pixels[x][y]._color._g << " " << (int)_pixels[x][y]._color._b << "\n";
        }
    }
    outFile.close();
}
