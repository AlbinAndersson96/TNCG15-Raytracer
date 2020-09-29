#include <camera.h>
#include <glm/glm.hpp>

Camera::Camera(Vertex &eyepointOne, Vertex &eyepointTwo, int raysPerPixel) : _eyepointOne(eyepointOne), _eyepointTwo(eyepointTwo), _currentEyepoint(1), _raysPerPixel(raysPerPixel)
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

void Camera::render(Scene &scene)
{
    std::cout << "Starting render with " << _raysPerPixel << " rays per pixel." << std::endl;

    float pixelSideLength = 1.0f/800.0f;

    for(int x = 0; x<800; x++)
    {
        for(int y = 0; y<800; y++)
        {
            std::cout << "\r" << "Rendering pixel: " << x << " x " << y << std::flush;
            Pixel &pixel = _pixels[x][y];

            ColorDbl accumulativeColor(0.0, 0.0, 0.0);

            for(int rayNr = 0; rayNr < _raysPerPixel; rayNr++)
            {                
                float deltaY = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                float deltaZ = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                glm::vec3 rayPixelIntersect(0.0f, static_cast<float>(y-401 + deltaY)*pixelSideLength, static_cast<float>(x-401 + deltaZ)*pixelSideLength);
    
                ColorDbl rayColor(0.0, 0.0, 0.0);
    
                Vertex phV(glm::vec4(0.0f, 0.0f, 0.0f, 0.0f));
                Triangle triangle(phV, phV, phV, rayColor); //Have to feed an empty placeholder into Triangle to construct
    
                Ray ray(_eyepointTwo._location, glm::vec4(rayPixelIntersect, 1.0f), rayColor, &triangle);
    
                scene.determineIntersections(ray);
                accumulativeColor += ray._color;
            }

            pixel._color = accumulativeColor / _raysPerPixel;
        }
    }
}

void Camera::createImage()
{
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
