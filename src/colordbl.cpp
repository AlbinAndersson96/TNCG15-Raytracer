#include <colordbl.h>

ColorDbl::ColorDbl(double r, double g, double b) : _r(r), _g(g), _b(b)
{}

ColorDbl::ColorDbl() : _r(0.0), _g(0.0), _b(0.0)
{}

ColorDbl& ColorDbl::operator+(ColorDbl& rhs)
{
    this->_r += rhs._r;
    this->_g += rhs._g;
    this->_b += rhs._b;
    return *this;
}

ColorDbl& ColorDbl::operator-(ColorDbl& rhs)
{    
    this->_r += rhs._r;
    this->_g += rhs._g;
    this->_b += rhs._b;
    return *this;
}

ColorDbl& ColorDbl::operator/(double divisor)
{
    this->_r /= divisor;
    this->_g /= divisor;
    this->_b /= divisor;
    return *this;
}

ColorDbl& ColorDbl::operator*(double factor)
{
    this->_r *= factor;
    this->_g *= factor;
    this->_b *= factor;
    return *this;
}

ColorDbl& ColorDbl::operator*(const ColorDbl& rhs)
{
    this->_r *= rhs._r;
    this->_g *= rhs._g;
    this->_b *= rhs._b;
    return *this;
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