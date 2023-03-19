#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace SHAPES {

/*!
* ������� ����� ������, �������� ���, ��� � ���������� ������, ������������ �������� ������������ ������� ���������
* �������� ������ �������������� ����������� � ����� �������� �� ������������ ������� ���������
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

    /*! �������� � �������� ���������� ������ */
    const Coordinates getCoordinates() const {
        return this->coordinates;
    }

    bool setCoordinates(const Coordinates& coordinates);

    /*! ���������� ���� ������������ ������� ��������� */
    const bool isCoordsChecked() const {
        return this->coordsChecked;
    }

    /*! �������� ��� ������ */
    virtual const ShapeType getShapeType() const {
        return ShapeType::SHAPE;
    }

    /*! �������� ��� ������ */
    const std::string getShapeName() const {
        return this->figureName;
    }

    /*! �������� ������ (��� �����) */
    virtual const double getRadius() const {
        return 0.;
    }

protected:
    Coordinates coordinates;

    virtual bool checkCoord(const Coordinates& coordinates) {
        return false;
    };

    /*! ��������� ������� ���������� ������ */
    bool checkSameCoords(const Coordinates& coordinates);

    std::string figureName;

    bool coordsChecked{ false };
};
}