#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#ifdef DEBUG
#include "Physics.hpp"
#endif // DEBUG

#include <iostream>
#include <memory>
#include <vector>

class Shape
{
public:
    static sf::Vector2f convert(const b2Vec2& vec);

    Shape(const b2Fixture* fixt, unsigned int pixelsToMeterRatio);

    sf::Shape& getSfShape();

    void update(sf::RenderWindow& window);

    static const sf::Color OUTLINE_COLOR;
    static constexpr float OUTLINE_THICKNESS = -1.0f;
    static const sf::Color FILL_COLOR;

protected:

    unsigned int pixelsToMeterRatio;
    std::unique_ptr<sf::Shape> sfShape;
private:
    const b2Fixture* fixt;
    b2Shape::Type type;

};

#endif // SHAPE_HPP
