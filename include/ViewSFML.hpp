#ifndef VIEWSFML_HPP
#define VIEWSFML_HPP

#ifdef DEBUG
#include <iostream>
#endif

#include "FpsCounter.hpp"
#include "Physics.hpp"
#include "Shape.hpp"
#include "ParticleShape.hpp"

#include <SFML/Graphics.hpp>

#include <chrono>
#include <list>
#include <memory>

using namespace std::chrono;

class ViewSFML
{
    using clock = high_resolution_clock;

public:

    ViewSFML(Physics& phys, unsigned int pixelsToMeterRatio=1);
    void launch(unsigned int windowWidth, unsigned int windowHeight);
    void launch(unsigned int windowWidth, float aspectRatio=16.0f/9.0f);

    /**
    speeds up or slow down the simulation
    for example a factor of 2 will run the simulation at 2 times the real speed
    if you want to view the simulation at max speed, just set fact at a negative value (for ex -1)
    **/
    void setSpeedFactor(float fact);

protected:

    // steps the physics engine if enough time has passed
    // returns true if physics has been stepped, false otherwise
    virtual bool step();
private:

    Physics& phys;
    std::list<Shape> shapes;
    std::list<ParticleShape> particles;

    float aspectRatio;
    unsigned int windowWidth, windowHeight;

    // how much pixels in this representation
    // represent 1 meter in the physical world
    unsigned int pixelsToMeterRatio;

    sf::Vector2f viewCenter;
    float viewHeight, viewWidth;


    float speedFactor;
    int32 microTimeStep;

    clock::time_point t1;
    microseconds acc;

    void launch();

    FpsCounter fps;
};

#endif // VIEWSFML_HPP
