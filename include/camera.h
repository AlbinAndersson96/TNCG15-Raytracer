#pragma once

#include <vector>
#include <fstream>

#include <vertex.h>
#include <pixel.h>

class Camera
{
    public:
        Camera(Vertex &eyepointOne, Vertex &eyepointTwo);
        ~Camera();
        void render();
        void createImage();

        Vertex &_eyepointOne, &_eyepointTwo;
        std::vector<std::vector<Pixel>> _pixels; 
        int _currentEyepoint;
};