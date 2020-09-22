#pragma once

#include <vector>

#include <colordbl.h>
#include <ray.h>

class Pixel
{
    public:
        Pixel();

        ColorDbl color;
        std::vector<Ray> rays;
};