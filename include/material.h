#pragma once

#include <colordbl.h>

class Material
{
    public:
        Material(ColorDbl color, bool isEmitting);

        ColorDbl _color;
        bool _isEmitting; 
};