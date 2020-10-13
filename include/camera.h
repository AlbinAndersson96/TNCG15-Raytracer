#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <thread>
#include <functional>
#include <time.h>

#include <glm/glm.hpp>

#include <vertex.h>
#include <pixel.h>
#include <ray.h>
#include <scene.h>
#include <material.h>
#include <threadpool.h>

class Camera
{
    public:
        Camera(int raysPerPixel, int eyePoint);
        ~Camera();
        void render(Scene &scene);
        void renderPixel(int x, int y, Scene &scene, int &nrCompleted);
        void fireRay(int x, int y, Ray &ray, Scene &scene, int depth, int baseRayNr);
        glm::vec4 sampleHemisphere(glm::vec4 normal);
        void createImage();

        Vertex _eyePoint;
        std::vector<std::vector<Pixel>> _pixels; 
        int _raysPerPixel;
};