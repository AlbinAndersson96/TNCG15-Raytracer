#pragma once

class ColorDbl
{
    public:
        ColorDbl(double r, double g, double b);
        ColorDbl();
        
        double _r, _g, _b;

        ColorDbl& operator+(ColorDbl&);
        ColorDbl& operator-(ColorDbl&);
        ColorDbl& operator/(double);
        ColorDbl& operator*(const double);
        ColorDbl& operator*(const ColorDbl&);
        ColorDbl& operator+=(const ColorDbl&);
        ColorDbl& operator-=(const ColorDbl&);
};