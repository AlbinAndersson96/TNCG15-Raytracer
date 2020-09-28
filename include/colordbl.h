#pragma once

class ColorDbl
{
    public:
        ColorDbl(double r, double g, double b);
        
        double _r, _g, _b;

        ColorDbl& operator+=(const ColorDbl&);
        ColorDbl& operator-=(const ColorDbl&);
};

ColorDbl operator+(ColorDbl&, ColorDbl&);
ColorDbl operator-(ColorDbl&, ColorDbl&);
ColorDbl operator/(ColorDbl&, double);
ColorDbl operator*(ColorDbl&, double);