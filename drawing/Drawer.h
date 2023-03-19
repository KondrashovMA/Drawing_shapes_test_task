#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Shapes.h"

namespace DRAW {

/*!
* Класс отрисовки
*/
    class Drawer
    {
    public:

        /*! Указатели на фигуры, в которых хранятся координаты и другая информация для отрисовки  */
        typedef std::vector<SHAPES::Shape*> Shapes;

        /*! Тип вектора фигур для отрисовки  */
        typedef std::vector<sf::VertexArray> SfShapesVector;

        /*! Добавить фигуру для отрисовки */
        void addShape(SHAPES::Shape& shape);

        /*!
        * Отрисовка всех ранее переданных методу фигур
        */
        void drawFigures();

    private:

        Shapes shapes;

        /*! Создаёт вектор фигур, которые отрисовываются в окне */
        SfShapesVector createSfShapes(const Shapes& shapes);


        /*! Отрисовывает круг, состоящий из массивов точек */
        sf::VertexArray createCircle(sf::VertexArray& figure, const SHAPES::Shape& shape);
    };
}