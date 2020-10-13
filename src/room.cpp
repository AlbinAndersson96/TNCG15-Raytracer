#include <room.h>

Room::Room()
{
    //Sets up our specific scene, Triangle winding order clockwise to (hopefully) make normals point inwards

    /*
        From above  
                        
         Left               ^y
       1 _______4           |  
        /       \           | /z
       /         \          |/
Back  2\         /5 Front   |------->x
        \_______/          
        3       6         
        Right            
    */

    //Verticies of the room
    Vertex roof1(glm::vec4(0.0f, 6.0f, -5.0f, 1.0f));
    Vertex roof2(glm::vec4(-3.0f, 0.0f, -5.0f, 1.0f));
    Vertex roof3(glm::vec4(0.0f, -6.0f, -5.0f, 1.0f));
    Vertex roof4(glm::vec4(10.0f, 6.0f, -5.0f, 1.0f));
    Vertex roof5(glm::vec4(13.0f, 0.0f, -5.0f, 1.0f));
    Vertex roof6(glm::vec4(10.0f, -6.0f, -5.0f, 1.0f));

    Vertex floor1(glm::vec4(0.0f, 6.0f, 5.0f, 1.0f));
    Vertex floor2(glm::vec4(-3.0f, 0.0f, 5.0f, 1.0f));
    Vertex floor3(glm::vec4(0.0f, -6.0f, 5.0f, 1.0f));
    Vertex floor4(glm::vec4(10.0f, 6.0f, 5.0f, 1.0f));
    Vertex floor5(glm::vec4(13.0f, 0.0f, 5.0f, 1.0f));
    Vertex floor6(glm::vec4(10.0f, -6.0f, 5.0f, 1.0f));

    ColorDbl cyan(0.0, 1.0, 1.0);

    //TODO: Leaks memory, fix later
    LambertianBRDF *brdf = new LambertianBRDF();
    Material cyanMat(cyan, false, brdf);

    //Triangles of the room, colored Cyan
    //Roof
    Triangle t1(roof1, roof3, roof2, cyanMat);
    Triangle t2(roof1, roof4, roof3, cyanMat);
    Triangle t3(roof4, roof6, roof3, cyanMat);
    Triangle t4(roof4, roof5, roof6, cyanMat);
    //Floor
    Triangle t5(floor1, floor3, floor2, cyanMat);
    Triangle t6(floor1, floor4, floor3, cyanMat);
    Triangle t7(floor4, floor6, floor3, cyanMat);
    Triangle t8(floor4, floor5, floor6, cyanMat);
    //Back-Left
    Triangle t9(roof1, roof2, floor1, cyanMat);
    Triangle t10(floor1, roof2, floor2, cyanMat);
    //Back-Right
    Triangle t11(roof2, roof3, floor2, cyanMat);
    Triangle t12(floor2, roof3, floor3, cyanMat);
    //Left
    Triangle t13(roof1, floor4, roof4, cyanMat);
    Triangle t14(roof1, floor1, roof4, cyanMat);
    //Right
    Triangle t15(roof3, roof6, floor3, cyanMat);
    Triangle t16(roof6, floor6, floor3, cyanMat);
    //Front-Left
    Triangle t17(roof5, roof4, floor5, cyanMat);
    Triangle t18(floor5, roof4, floor4, cyanMat);
    //Front-Right
    Triangle t19(roof6, roof5, floor6, cyanMat);
    Triangle t20(floor6, roof5, floor5, cyanMat);

    //There must exist an easier way to do this... can't bother to look for it tho
    _triangles.push_back(t1);
    _triangles.push_back(t2);
    _triangles.push_back(t3);
    _triangles.push_back(t4);
    _triangles.push_back(t5);
    _triangles.push_back(t6);
    _triangles.push_back(t7);
    _triangles.push_back(t8);
    _triangles.push_back(t9);
    _triangles.push_back(t10);
    _triangles.push_back(t11);
    _triangles.push_back(t12);
    _triangles.push_back(t13);
    _triangles.push_back(t14);
    _triangles.push_back(t15);
    _triangles.push_back(t16);
    _triangles.push_back(t17);
    _triangles.push_back(t18);
    _triangles.push_back(t19);
    _triangles.push_back(t20);
}

Room::~Room()
{}

void Room::rayIntersection(Ray &ray)
{
    for(Triangle &triangle : _triangles)
        triangle.rayIntersection(ray);
}