#pragma once

#include <brdf.h>

#include <utilities.h>

class LambertianBRDF : public BRDF
{
    public:
        LambertianBRDF();
        virtual glm::vec4 sample(glm::vec4 outDirection, glm::vec4 normal);
        virtual float pdf(glm::vec4 inDirection, glm::vec4 normal);
        virtual ColorDbl eval(ColorDbl albedo, glm::vec4 inDirection, glm::vec4 outDirection, glm::vec4 normal);
};