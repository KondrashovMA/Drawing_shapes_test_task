#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Shapes.h"

namespace DRAW {

/*!
* ����� ��������� 
*/
class Drawer
{
public:

    /*! ��������� �� ������, � ������� �������� ���������� � ������ ���������� ��� ���������  */
    typedef std::vector<SHAPES::Shape*> Shapes;
    
    /*! ��� ������� ����� ��� ���������  */
    typedef std::vector<sf::VertexArray> SfShapesVector;

    /*! �������� ������ ��� ��������� */
    void addShape(SHAPES::Shape& shape);

    /*!
    * ��������� ���� ����� ���������� ������ �����
    */
    void drawFigures();

private:

    Shapes shapes;

    /*! ������ ������ �����, ������� �������������� � ���� */
    SfShapesVector createSfShapes(const Shapes& shapes);


    /*! ������������ ����, ��������� �� �������� ����� */
    sf::VertexArray createCircle(sf::VertexArray& figure, const SHAPES::Shape& shape);
};
}