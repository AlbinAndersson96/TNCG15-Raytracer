#include <colordbl.h>

ColorDbl::ColorDbl(double r, double g, double b) : _r(r), _g(g), _b(b)
{}

ColorDbl operator+(ColorDbl& color1, ColorDbl& color2)
{
    return ColorDbl(color1._r + color2._r, color1._g + color2._g, color1._b + color2._b);
}

ColorDbl operator-(ColorDbl& color1, ColorDbl& color2)
{
    return ColorDbl(color1._r - color2._r, color1._g - color2._g, color1._b - color2._b);
}

ColorDbl operator/(ColorDbl& color, double divisor)
{
    return ColorDbl(color._r/divisor, color._g/divisor, color._b/divisor);
}

ColorDbl operator*(ColorDbl& color, double factor)
{
    return ColorDbl(color._r*factor, color._g*factor, color._b*factor);
}

ColorDbl& ColorDbl::operator+=(const ColorDbl& rhs)
{
    this->_r += rhs._r;
    this->_g += rhs._g;
    this->_b += rhs._b;
    return *this;
}

ColorDbl& ColorDbl::operator-=(const ColorDbl& rhs)
{
    this->_r -= rhs._r;
    this->_g -= rhs._g;
    this->_b -= rhs._b;
    return *this;
}