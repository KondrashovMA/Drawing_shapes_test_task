#include "Drawer.h"

namespace DRAW {
    void Drawer::addShape(SHAPES::Shape& shape) {
        if (shape.isCoordsChecked()) {
            shapes.push_back(&shape);
            return;
        }
        std::cout << "Wrong coordinates in figure " + shape.getShapeName() + "; please enter correct the coordinates " << std::endl;
    }

    void Drawer::drawFigures() {
        sf::RenderWindow window(sf::VideoMode(1100, 1100), "Figures");
        SfShapesVector sfShapes = createSfShapes(this->shapes);
        if (sfShapes.size() == 0) return;

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            for (auto& it : sfShapes) {
                window.draw(it);
            }

            window.display();
        }
    };

    DRAW::Drawer::SfShapesVector Drawer::createSfShapes(const Shapes& shapes) {
        SfShapesVector sf_shapes;

        for (auto& shape : shapes) {
            sf::VertexArray figure;

            switch (shape->getShapeType()) {
            case SHAPES::Shape::ShapeType::CIRCLE:
                sf_shapes.push_back(createCircle(figure, *shape));
                break;
            case SHAPES::Shape::ShapeType::RECTANGLE:
                figure.setPrimitiveType(sf::Quads);
                figure.resize(4);

                figure[0].position = sf::Vector2f(shape->getCoordinates().at(0).first, shape->getCoordinates().at(0).second);
                figure[1].position = sf::Vector2f(shape->getCoordinates().at(1).first, shape->getCoordinates().at(1).second);
                figure[2].position = sf::Vector2f(shape->getCoordinates().at(2).first, shape->getCoordinates().at(2).second);
                figure[3].position = sf::Vector2f(shape->getCoordinates().at(3).first, shape->getCoordinates().at(3).second);

                figure[0].color = sf::Color::Red;
                figure[1].color = sf::Color::Red;
                figure[2].color = sf::Color::Red;
                figure[3].color = sf::Color::Red;

                sf_shapes.push_back(figure);

                break;
            case SHAPES::Shape::ShapeType::TRIANGLE:
                figure.setPrimitiveType(sf::Triangles);
                figure.resize(3);
                figure[0].position = sf::Vector2f(shape->getCoordinates().at(0).first, shape->getCoordinates().at(0).second);
                figure[1].position = sf::Vector2f(shape->getCoordinates().at(1).first, shape->getCoordinates().at(1).second);
                figure[2].position = sf::Vector2f(shape->getCoordinates().at(2).first, shape->getCoordinates().at(2).second);

                figure[0].color = sf::Color::Blue;
                figure[1].color = sf::Color::Blue;
                figure[2].color = sf::Color::Blue;


                sf_shapes.push_back(figure);
                break;
            }
        }
        return sf_shapes;
    }

    sf::VertexArray Drawer::createCircle(sf::VertexArray& figure, const SHAPES::Shape& shape) {
        int numberOfSides = 1000;
        figure.setPrimitiveType(sf::TrianglesFan);
        figure.resize(numberOfSides);

        for (int i = 0; i < numberOfSides; i++)
        {
            sf::Vector2f position;
            sf::Vector2f vertexPosition;

            float x = shape.getCoordinates().at(0).first;
            float y = shape.getCoordinates().at(0).second;

            const float angle{ static_cast<float>(i) / numberOfSides * 2.f * 3.14159265358979f };

            position = { (std::cos(angle)), (std::sin(angle)) };
            vertexPosition = { position.x * (float)shape.getRadius() + x, position.y * (float)shape.getRadius() + y };

            figure[i].position = vertexPosition;
            figure[i].color = sf::Color::Green;
        }
        return figure;
    }
}