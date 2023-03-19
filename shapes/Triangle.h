#pragma once
#include "Shape.h"
#include <iostream>

namespace SHAPES {
class Triangle : public Shape 
{
public:
    Triangle(std::string shapeName):
        Shape{shapeName}{
    }

    const ShapeType getShapeType() const {
        return ShapeType::TRIANGLE;
    }

    bool checkCoord(const Coordinates& coordinates);
};
}