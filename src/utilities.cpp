#include <utilities.h>

glm::vec4 localToWorldTransform(glm::vec4 coords, glm::vec4 normal)
{
    glm::vec4 majorAxis;
    if(glm::abs(normal.x) < (1/sqrt(3)))
        majorAxis = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    else if(glm::abs(normal.y) < (1/sqrt(3)))
        majorAxis = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
    else
        majorAxis = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);

    glm::vec3 u = glm::normalize(glm::cross(glm::vec3(normal), glm::vec3(majorAxis)));
    glm::vec3 v = cross(glm::vec3(normal), u);
    glm::vec3 w = normal;

    return glm::vec4(u*coords.x + v*coords.y + w*coords.z, 1.0f);
}