#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace SHAPES {

/*!
* Базовый класс фигуры, хранящий имя, тип и координаты фигуры, осуществляет проверку корреткности задания координат
* Дочерние классы переопределяют конструктор и метод проверки на правильность задания координат
*/
    class Shape {
    public:
        enum class ShapeType {
            SHAPE,
            RECTANGLE,
            CIRCLE,
            TRIANGLE
        };

        typedef std::vector<std::pair<double, double>> Coordinates;

        Shape(std::string figureName) :
                figureName{ figureName } {
        }

        /*! Добавить и получить координаты фигуры */
        const Coordinates getCoordinates() const {
            return this->coordinates;
        }

        bool setCoordinates(const Coordinates& coordinates);

        /*! Возвращает флаг корректности задания координат */
        const bool isCoordsChecked() const {
            return this->coordsChecked;
        }

        /*! Получить тип фигуры */
        virtual const ShapeType getShapeType() const {
            return ShapeType::SHAPE;
        }

        /*! Получить имя фигуры */
        const std::string getShapeName() const {
            return this->figureName;
        }

        /*! Получить радиус (для круга) */
        virtual const double getRadius() const {
            return 0.;
        }

    protected:
        Coordinates coordinates;

        virtual bool checkCoord(const Coordinates& coordinates) {
            return false;
        };

        /*! Проверить наличие одинаковых вершин */
        bool checkSameCoords(const Coordinates& coordinates);

        std::string figureName;

        bool coordsChecked{ false };
    };
}