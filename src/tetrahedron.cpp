#include <tetrahedron.h>

Tetrahedron::Tetrahedron(Vertex v0, Vertex v1, Vertex v2, Vertex v3, Material material)
{       
//       v0
//       /|\
//      / | \
//  v1 /__|__\v3    (Drawing with text is hard. Hopefully 3d enough)
//     \  |  /
//      \ | /
//       \|/
//        v2
  
    _material = material;
  
    _t0 = new Triangle(v0, v1, v2, material);
    _t1 = new Triangle(v0, v1, v3, material);
    _t2 = new Triangle(v0, v2, v3, material);
    _t3 = new Triangle(v1, v2, v3, material);
}

Tetrahedron::~Tetrahedron()
{
    delete _t0;
    delete _t1;
    delete _t2;
    delete _t3;

}

void Tetrahedron::rayIntersection(Ray &ray)
{
    Triangle *triangles[] = {_t0, _t1, _t2, _t3};

    for(Triangle *triangle : triangles)
        triangle->rayIntersection(ray);
}