#include <lambertianbrdf.h>

LambertianBRDF::LambertianBRDF(){}

glm::vec4 LambertianBRDF::sample(glm::vec4 outDirection, glm::vec4 normal)
{
    /*//Helper, random vector not paralell to normal
    glm::vec4 helper = normal + glm::vec4(1.0f, 1.0f, 1.0f, 0.0f);
    glm::vec4 tangent = glm::vec4(glm::normalize(glm::cross(glm::vec3(normal/normal.w), glm::vec3(helper/helper.w))), 1.0f);

    //Angles randomized on a scale of 0.0f to 1.0f
    float inclination = acos(sqrt(static_cast <float> (rand()) / static_cast <float> (RAND_MAX)));
    float azimuth = 2 * M_PI * static_cast <float> (rand()) / static_cast <float> (RAND_MAX);;

    glm::vec4 sampleVec = normal/normal.w;
    sampleVec = glm::vec4(glm::normalize(glm::rotate(glm::vec3(sampleVec), inclination, glm::vec3(tangent)) * glm::rotate(glm::vec3(sampleVec), azimuth, glm::vec3(tangent))), 1.0f);

    return sampleVec;*/

    float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float r = std::sqrt(random);
    float theta = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * 2.0f * M_PI;

    float x = r * std::cos(theta);
    float y = r * std::sin(theta);
    float z = std::sqrt(1.0f - x*x - y*y);

    return glm::normalize(localToWorldTransform(glm::vec4(x, y, z, 1.0f), normal));
}

float LambertianBRDF::pdf(glm::vec4 inDirection, glm::vec4 normal)
{
    return glm::dot(inDirection, normal) * M_1_PI;
}

ColorDbl LambertianBRDF::eval(ColorDbl albedo, glm::vec4 inDirection, glm::vec4 outDirection, glm::vec4 normal)
{
    return albedo * glm::dot(inDirection, normal) * M_1_PI;
}