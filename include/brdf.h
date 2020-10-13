#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include <math.h>

#include <colordbl.h>

class BRDF
{
    public:
        virtual glm::vec4 sample(glm::vec4 outDirection, glm::vec4 normal) = 0;
        virtual float pdf(glm::vec4 inDirection, glm::vec4 normal) = 0;
        virtual ColorDbl eval(ColorDbl albedo, glm::vec4 inDirection, glm::vec4 outDirection, glm::vec4 normal) = 0;

        virtual ~BRDF() {};
 };