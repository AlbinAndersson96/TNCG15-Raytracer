#include <material.h>

Material::Material(ColorDbl color, bool isEmitting, BRDF *brdf) : _color(color), _isEmitting(isEmitting), _brdf(brdf)
{}

Material::Material(): _color(ColorDbl(0.0, 0.0, 0.0)), _isEmitting(false), _brdf(nullptr)
{}