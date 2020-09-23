#include <scene.h>

Scene::Scene()
{
    //Sets up our specific scene, Triangle winding order clockwise to (hopefully) make normals point inwards

    /*
        From above  
        
         Left               ^y
       1 _______4           |  
        /       \           | 
       /         \          |
Back  2\         /5 Front    ------->x
        \_______/          /
        3       6         /
        Right            /z
    */

    //Verticies of the room
    Vertex roof1(glm::vec4(0.0f, 6.0f, 5.0f, 1.0f));
    Vertex roof2(glm::vec4(-3.0f, 0.0f, 5.0f, 1.0f));
    Vertex roof3(glm::vec4(0.0f, -6.0f, 5.0f, 1.0f));
    Vertex roof4(glm::vec4(10.0f, 6.0f, 5.0f, 1.0f));
    Vertex roof5(glm::vec4(13.0f, 0.0f, 5.0f, 1.0f));
    Vertex roof6(glm::vec4(10.0f, -6.0f, 5.0f, 1.0f));

    Vertex floor1(glm::vec4(0.0f, 6.0f, -5.0f, 1.0f));
    Vertex floor2(glm::vec4(-3.0f, 0.0f, -5.0f, 1.0f));
    Vertex floor3(glm::vec4(0.0f, -6.0f, -5.0f, 1.0f));
    Vertex floor4(glm::vec4(10.0f, 6.0f, -5.0f, 1.0f));
    Vertex floor5(glm::vec4(13.0f, 0.0f, -5.0f, 1.0f));
    Vertex floor6(glm::vec4(10.0f, -6.0f, -5.0f, 1.0f));

    ColorDbl roomColor(255.0, 255.0, 255.0);

    //Triangles of the room
    //Roof
    Triangle t1(roof1, roof3, roof2, roomColor);
    Triangle t2(roof1, roof4, roof3, roomColor);
    Triangle t3(roof4, roof6, roof3, roomColor);
    Triangle t4(roof4, roof5, roof6, roomColor);
    //Floor
    Triangle t5(floor1, floor3, floor2, roomColor);
    Triangle t6(floor1, floor4, floor3, roomColor);
    Triangle t7(floor4, floor6, floor3, roomColor);
    Triangle t8(floor4, floor5, floor6, roomColor);
    //Back-Left
    Triangle t9(roof1, roof2, floor1, roomColor);
    Triangle t10(floor1, roof2, floor2, roomColor);
    //Back-Right
    Triangle t11(roof2, roof3, floor2, roomColor);
    Triangle t12(floor2, roof3, floor3, roomColor);
    //Left
    Triangle t13(roof1, floor4, roof4, roomColor);
    Triangle t14(roof1, floor1, roof4, roomColor);
    //Right
    Triangle t15(roof3, roof6, floor3, roomColor);
    Triangle t16(roof6, floor6, floor3, roomColor);
    //Front-Left
    Triangle t17(roof5, roof4, floor5, roomColor);
    Triangle t18(floor5, roof4, floor4, roomColor);
    //Front-Right
    Triangle t19(roof6, roof5, floor6, roomColor);
    Triangle t20(floor6, roof5, floor6, roomColor);

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

void Scene::determineIntersections(Ray &ray)
{
    for(Triangle triangle : _triangles)
    {
        triangle.rayIntersection(ray);
    }
}