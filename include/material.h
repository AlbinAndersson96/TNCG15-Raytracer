#pragma once

#include <colordbl.h>
#include <brdf.h>
#include <lambertianbrdf.h>

class Material
{
    public:
        Material(ColorDbl color, bool isEmitting, BRDF *brdf);
        Material();

        ColorDbl _color;
        BRDF *_brdf;
        bool _isEmitting; 
};