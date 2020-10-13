#include <pixel.h>

Pixel::Pixel(int nrOfRays)
{
    for(int i = 0; i < nrOfRays; i++)
    {
        _colors.push_back(new ColorDbl(0.0, 0.0, 0.0));
        _throughputs.push_back(new ColorDbl(1.0, 1.0, 1.0));
    }
}

Pixel::~Pixel()
{
    /*for(int i = 0; i < _colors.size(); i++)
    {
        delete _colors[i];
        delete _throughputs[i];
    }*/
}