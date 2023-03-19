#pragma once
#include "Shape.h"

namespace SHAPES {
class Rectangle : public Shape
{
public:
    Rectangle(std::string shapeName) :
        Shape{ shapeName } {
    }

    const ShapeType getShapeType() const {
        return ShapeType::RECTANGLE;
    }

    bool checkCoord(const Coordinates& coordinates);
};
}


