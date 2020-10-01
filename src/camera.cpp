#include <camera.h>
#include <glm/glm.hpp>

Camera::Camera(int raysPerPixel, int eyePoint) :_raysPerPixel(raysPerPixel), _eyePoint(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f))
{
    if(eyePoint == 1)
        _eyePoint = glm::vec4(-2.0f, 0.0f, 0.0f, 1.0f);
    else if(eyePoint == 2)
        _eyePoint = glm::vec4(-1.0f, 0.0f, 0.0f, 1.0f);


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
    unsigned int numThreads = std::thread::hardware_concurrency();
    std::cout << "Rendering image with " << _raysPerPixel << " rays per pixel using " << numThreads << " thread(s)..." << std::endl;

    time_t start = time(0);
    double duration;

    Threadpool pool(numThreads);

    for(int x = 0; x<800; x++)
    {
        for(int y = 0; y<800; y++)
        {
            std::function<void()> job = std::bind(&Camera::renderPixel, this, x, y, scene);
            pool.addJob(job);
        }
    }

    pool.start();

    duration = difftime(time(0), start);

    std::cout << "Render finished in " << duration << " seconds. Writing resulting image to file...";
}

void Camera::renderPixel(int x, int y, Scene &scene)
{
    float pixelSideLength = 1.0f/800.0f;

    //std::cout << "\r" << "Rendering pixel: " << x << " x " << y << std::flush;
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
    
        Ray ray(_eyePoint._location, glm::vec4(rayPixelIntersect, 1.0f), rayColor, &triangle);
    
        scene.determineIntersections(ray);
        accumulativeColor += ray._color;
    }

    pixel._color = accumulativeColor / _raysPerPixel;
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
            double brightestColor = _pixels[x][y]._color._r;
            if(_pixels[x][y]._color._g > brightestColor)
                brightestColor = _pixels[x][y]._color._g;
            if(_pixels[x][y]._color._b > brightestColor)
                brightestColor = _pixels[x][y]._color._b;

            outFile << (int)(255.99*_pixels[x][y]._color._r/brightestColor) << " " << (int)(255.99*_pixels[x][y]._color._g/brightestColor) << " " << (int)(255.99*_pixels[x][y]._color._b/brightestColor) << "\n";
        }
    }
    outFile.close();
}