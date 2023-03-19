#include "Rectangle.h"

namespace SHAPES {
bool Rectangle::checkCoord(const Coordinates & coordinates) {
    if (coordinates.size() != 4) return false;
    if (this->checkSameCoords(coordinates)) return false;
    return true;
};
}