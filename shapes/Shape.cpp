#include "Shape.h"

namespace SHAPES {
    bool Shape::setCoordinates(const Coordinates& coordinates) {
        if (!checkCoord(coordinates)) {
            std::cout << "Figure " + figureName + " has incorrect coordinates" << std::endl;
            return false;
        }
        this->coordinates = coordinates;
        coordsChecked = true;
        return true;
    }

    bool Shape::checkSameCoords(const Coordinates& coordinates) {
        for (int i = 0; i < coordinates.size(); i++) {
            auto& pair = coordinates.at(i);
            for (int k = 0; k < coordinates.size(); k++) {
                if (i != k && pair == coordinates.at(k)) {
                    return true;
                }
            }
        }
        return false;
    }
}