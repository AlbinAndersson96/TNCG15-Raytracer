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

    glm::vec3 u = glm::normalize(glm::cross(glm::vec3(normal/normal.w), glm::vec3(majorAxis)));
    glm::vec3 v = cross(glm::vec3(normal/normal.w), u);
    glm::vec3 w = normal/normal.w;

    return glm::vec4(u*coords.x/coords.w + v*coords.y/coords.w + w*coords.z/coords.w, 1.0f);
}