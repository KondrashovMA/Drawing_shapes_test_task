#pragma once
#include "Shape.h"

namespace SHAPES {
class Circle : public Shape
{
public:
    Circle(std::string figureName, double radius) :
        radius{ radius },
        Shape{ figureName }{
    }

    const ShapeType getShapeType() const {
        return ShapeType::CIRCLE;
    }

    bool checkCoord(const Coordinates& coordinates);

    const double getRadius() const {
        return radius;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }

private:
    double radius{ 0. };
    std::pair<double, double> center{ std::pair<double, double>(0., 0.)};
};
}
