#include "Triangle.h"

namespace SHAPES {
bool Triangle::checkCoord(const Coordinates& coordinates) {
    if (coordinates.size() != 3) return false;
    if (this->checkSameCoords(coordinates)) return false;
    return true;
};
}
