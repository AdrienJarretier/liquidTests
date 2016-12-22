#ifndef VIEWSFML_HPP
#define VIEWSFML_HPP

#ifdef DEBUG
#include <iostream>
#endif

#include "Physics.hpp"
#include "Shape.hpp"

#include <SFML/Graphics.hpp>

#include <list>
#include <memory>

class ViewSFML
{
public:

    ViewSFML(Physics& phys);
    void launch(unsigned int windowWidth, unsigned int windowHeight);
    void launch(unsigned int windowWidth, float aspectRatio=16.0f/9.0f);

protected:
private:

    Physics& phys;
    std::list<Shape> shapes;

    float aspectRatio;
    unsigned int windowWidth, windowHeight;

    sf::Vector2f viewCenter;
    float viewHeight, viewWidth;

    void launch();

};

#endif // VIEWSFML_HPP
