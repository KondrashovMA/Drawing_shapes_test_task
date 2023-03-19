#include "shapes/Shapes.h"
#include "Drawer.h"


int main()
{
    /*!
    * ��������� ��������� �����, ������� �� ���������� ������. 
    * ���� �������� �� ������� ���������� ������ (������ triangle2 �� ����� ��������)
    */

    // ���������� �����
    SHAPES::Circle circle1("circle1", 100);
    SHAPES::Circle circle2("circle2", 50);
    SHAPES::Triangle triangle1("triangle1");
    SHAPES::Triangle triangle2("triangle2");
    SHAPES::Rectangle quad1("quad1");
    SHAPES::Rectangle quad2("quad2");

    // ������� ��������� �����
    SHAPES::Shape::Coordinates circleCoord1;
    circleCoord1.push_back(std::pair<double, double>(100, 100));
    SHAPES::Shape::Coordinates circleCoord2;
    circleCoord2.push_back(std::pair<double, double>(350, 50));
    SHAPES::Shape::Coordinates triangleCoords1;
    triangleCoords1.push_back(std::pair<double, double>(400, 350));
    triangleCoords1.push_back(std::pair<double, double>(400, 150));
    triangleCoords1.push_back(std::pair<double, double>(200, 250));
    SHAPES::Shape::Coordinates triangleCoords2;
    triangleCoords2.push_back(std::pair<double, double>(400, 350));
    triangleCoords2.push_back(std::pair<double, double>(400, 350)); // �� ���������, ��������� ������� ���������� ���������� ������
    triangleCoords2.push_back(std::pair<double, double>(200, 250));
    SHAPES::Shape::Coordinates quadCoords1;
    quadCoords1.push_back(std::pair<double, double>(700, 350));
    quadCoords1.push_back(std::pair<double, double>(700, 450));
    quadCoords1.push_back(std::pair<double, double>(900, 450));
    quadCoords1.push_back(std::pair<double, double>(900, 350));
    SHAPES::Shape::Coordinates quadCoords2;
    quadCoords2.push_back(std::pair<double, double>(50, 300));
    quadCoords2.push_back(std::pair<double, double>(50, 350));
    quadCoords2.push_back(std::pair<double, double>(100, 350));
    quadCoords2.push_back(std::pair<double, double>(100, 300));

    circle1.setCoordinates(circleCoord1);
    circle2.setCoordinates(circleCoord2);
    triangle1.setCoordinates(triangleCoords1);
    triangle2.setCoordinates(triangleCoords2);
    quad1.setCoordinates(quadCoords1);
    quad2.setCoordinates(quadCoords2);

    DRAW::Drawer drawer;
    drawer.addShape(circle1);
    drawer.addShape(circle2);
    drawer.addShape(triangle1);
    drawer.addShape(triangle2);
    drawer.addShape(quad1);
    drawer.addShape(quad2);

    drawer.drawFigures();

    return 0;
}