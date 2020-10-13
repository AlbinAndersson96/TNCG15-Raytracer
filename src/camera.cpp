#include <camera.h>

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
            Pixel pixel(raysPerPixel);
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

    int nrCompleted = 0;

    for(int y = 0; y<800; y++)
    {
        for(int z = 0; z<800; z++)
        {
            std::function<void()> job = std::bind(&Camera::renderPixel, this, y, z, scene, nrCompleted);
            pool.addJob(job);
        }
    }

    pool.start();

    duration = difftime(time(0), start);

    std::cout << "Render finished in " << duration << " seconds. Writing resulting image to file...";
}

void Camera::renderPixel(int y, int z, Scene &scene, int &nrCompleted)
{
    float pixelSideLength = 1.0f/800.0f;

    Pixel &pixel = _pixels[y][z];

    for(int rayNr = 0; rayNr < _raysPerPixel; rayNr++)
    {
        float deltaY = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float deltaZ = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        glm::vec3 rayPixelIntersect(0.0f, static_cast<float>(401-y + deltaY)*pixelSideLength, static_cast<float>(z-401 + deltaZ)*pixelSideLength);
        
        Ray ray(_eyePoint._location, glm::normalize(glm::vec4(rayPixelIntersect - glm::vec3(_eyePoint._location/_eyePoint._location.w), 1.0f)));
        fireRay(y, z, ray, scene, 0, rayNr);
    }
}

void Camera::fireRay(int y, int z, Ray &ray, Scene &scene, int depth, int baseRayNr)
{
    Pixel &pixel = _pixels[y][z];

    scene.determineIntersections(ray);

    if(ray._rayHit->hasHit && depth < 20)
    {
        Material *material = &ray._rayHit->_hitSurfaceMaterial;
        if(material->_isEmitting)
            *pixel._colors[baseRayNr] += *pixel._throughputs[baseRayNr];

        glm::vec4 wo = -ray._direction;
        glm::vec4 wi = material->_brdf->sample(wo, ray._rayHit->_hitSurfaceNormal);
        float pdf = material->_brdf->pdf(wi, ray._rayHit->_hitSurfaceNormal);

        *pixel._throughputs[baseRayNr] = *pixel._throughputs[baseRayNr] * material->_brdf->eval(material->_color, wi, wo, ray._rayHit->_hitSurfaceNormal) / pdf;

        ray._t = 100000;
        ray._start = ray._intersectionPoint;
        ray._direction = wi;
        ray._rayHit->hasHit = false;
        fireRay(y, z, ray, scene, ++depth, baseRayNr);
    }
    else
    {
        //std::cout << "miss\n";
    }
    
}

void Camera::createImage()
{
    std::ofstream outFile;
    outFile.open("out.ppm");
    outFile << "P3\n800 800\n255\n";

    for(int z = 0; z<800; z++)
    {
        for(int y = 0; y<800; y++)
        {
            ColorDbl accumulativeColor;
            for(int i = 0; i < _raysPerPixel; i++)
            {
                accumulativeColor += *_pixels[y][z]._colors[i];
            }
            ColorDbl pixelColor = accumulativeColor/static_cast<double>(_raysPerPixel);

            double brightestColor = pixelColor._r;
            if(pixelColor._g > brightestColor)
                brightestColor = pixelColor._g;
            if(pixelColor._b > brightestColor)
                brightestColor = pixelColor._b;

            if(brightestColor == 0.0)
                brightestColor = 1.0;

            outFile << static_cast<int>(255.0*pixelColor._r) << " " << static_cast<int>(255.0*pixelColor._g) << " " << static_cast<int>(255.0*pixelColor._b) << "\n";
        }
    }
    outFile.close();
}