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

void Camera::render(Scene &scene)
{
    float pixelSideLength = 1.0f/800.0f;

    //TODO: Implement render()
    for(int x = 0; x<800; x++)
    {
        for(int y = 0; y<800; y++)
        {
            std::cout << "\r" << "Rendering pixel: " << x << " " << y << std::flush;
            //std::cout << "Rendering pixel: " << x << " " << y << std::endl;

            Pixel &pixel = _pixels[x][y];
            
            //float deltaY = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            //float deltaZ = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            glm::vec3 rayPixelIntersect(0.0f, static_cast<float>(y-401)*pixelSideLength, static_cast<float>(x-401)*pixelSideLength);

            ColorDbl rayColor(0.0, 0.0, 0.0);

            Vertex phV(glm::vec4(0.0f, 0.0f, 0.0f, 0.0f));
            Triangle triangle(phV, phV, phV, rayColor); //Have to feed an empty placeholder into Triangle to construct

            Ray ray(_eyepointTwo._location, glm::vec4(rayPixelIntersect, 1.0f), rayColor, &triangle);

            scene.determineIntersections(ray);

            //pixel._rays.push_back(ray);

            pixel._color = ray._color;
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
