#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

class Shape
{
    public:
        static sf::Vector2f convert(const b2Vec2& vec);

        Shape(const b2Fixture* fixt, unsigned int pixelsToMeterRatio);

        sf::Shape& getSfShape();

        void update();
    protected:

        Shape(unsigned int pixelsToMeterRatio);

        const sf::Color OUTLINE_COLOR = sf::Color::Red;
        const float OUTLINE_THICKNESS = -1.0f;
        const sf::Color FILL_COLOR = sf::Color::Black;
        unsigned int pixelsToMeterRatio;
        std::unique_ptr<sf::Shape> sfShape;
    private:
        const b2Fixture* fixt;
        b2Shape::Type type;


};

#endif // SHAPE_HPP
