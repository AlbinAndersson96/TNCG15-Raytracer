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

        Vertex &eyepointOne, &eyepointTwo;
        std::vector<std::vector<Pixel>> pixels; 
        int currentEyepoint;
};