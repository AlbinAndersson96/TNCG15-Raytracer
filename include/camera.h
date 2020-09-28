#pragma once

#include <vector>
#include <fstream>
#include <iostream>

#include <glm/glm.hpp>

#include <vertex.h>
#include <pixel.h>
#include <ray.h>
#include <scene.h>


class Camera
{
    public:
        Camera(Vertex &eyepointOne, Vertex &eyepointTwo, int raysPerPixel);
        ~Camera();
        void render(Scene &scene);
        void createImage();

        Vertex &_eyepointOne, &_eyepointTwo;
        std::vector<std::vector<Pixel>> _pixels; 
        int _currentEyepoint;
        int _raysPerPixel;
};