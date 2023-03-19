#include "Circle.h"

namespace SHAPES {
    bool Circle::checkCoord(const Coordinates& coordinates) {
        if (coordinates.size() != 1 || this->radius == 0.) return false;
        return true;
    };
}