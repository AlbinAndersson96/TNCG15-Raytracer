#pragma once

#include <vector>

#include <colordbl.h>
#include <ray.h>

class Pixel
{
    public:
        Pixel();

        ColorDbl _color;
        ColorDbl _throughput;
        std::vector<Ray> _rays;
};