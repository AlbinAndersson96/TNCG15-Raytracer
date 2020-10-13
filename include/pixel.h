#pragma once

#include <vector>

#include <colordbl.h>
#include <ray.h>

class Pixel
{
    public:
        Pixel(int nrOfRays);
        ~Pixel();

        std::vector<ColorDbl*> _colors;
        std::vector<ColorDbl*> _throughputs;
};