#include <lightsource.h>

Lightsource::Lightsource(Vertex pos, float sideLength, Material material) : _material(material)
{
/*
    From above                              
    ^y
    |  
    | 
    |
    ------->x
   /
  /
 /z

  v0 _______v2
    |       |
    |  pos  |
  v1|_______|v3
*/


Vertex v0Top(glm::vec4(pos._location.x - sideLength/2, pos._location.y + sideLength/2, pos._location.z + sideLength/2, 1.0f));
Vertex v1Top(glm::vec4(pos._location.x - sideLength/2, pos._location.y - sideLength/2, pos._location.z + sideLength/2, 1.0f));
Vertex v2Top(glm::vec4(pos._location.x + sideLength/2, pos._location.y + sideLength/2, pos._location.z + sideLength/2, 1.0f));
Vertex v3Top(glm::vec4(pos._location.x + sideLength/2, pos._location.y - sideLength/2, pos._location.z + sideLength/2, 1.0f));

Vertex v0Bot(glm::vec4(pos._location.x - sideLength/2, pos._location.y + sideLength/2, pos._location.z - sideLength/2, 1.0f));
Vertex v1Bot(glm::vec4(pos._location.x - sideLength/2, pos._location.y - sideLength/2, pos._location.z - sideLength/2, 1.0f));
Vertex v2Bot(glm::vec4(pos._location.x + sideLength/2, pos._location.y + sideLength/2, pos._location.z - sideLength/2, 1.0f));
Vertex v3Bot(glm::vec4(pos._location.x + sideLength/2, pos._location.y - sideLength/2, pos._location.z - sideLength/2, 1.0f));

Triangle back0(v0Top, v1Top, v0Bot, material);
Triangle back1(v1Top, v1Bot, v0Bot, material);
Triangle left0(v0Top, v0Bot, v2Top, material);
Triangle left1(v0Bot, v2Bot, v2Top, material);
Triangle front0(v2Top, v2Bot, v3Top, material);
Triangle front1(v2Bot, v3Bot, v3Top, material);
Triangle right0(v1Top, v3Top, v3Bot, material);
Triangle right1(v3Bot, v1Bot, v1Top, material);
Triangle top0(v0Top, v3Top, v1Top, material);
Triangle top1(v0Top, v2Top, v3Top, material);
Triangle bot0(v0Bot, v1Bot, v3Bot, material);
Triangle bot1(v0Bot, v3Bot, v2Bot, material);

_triangles.push_back(back0);
_triangles.push_back(back1);
_triangles.push_back(left0);
_triangles.push_back(left1);
_triangles.push_back(front0);
_triangles.push_back(front1);
_triangles.push_back(right0);
_triangles.push_back(right1);
_triangles.push_back(top0);
_triangles.push_back(top1);
_triangles.push_back(bot0);
_triangles.push_back(bot1);
}

void Lightsource::rayIntersection(Ray &ray)
{
    for(Triangle triangle : _triangles)
        triangle.rayIntersection(ray);
}