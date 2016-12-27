#ifndef FPSCOUNTER_HPP
#define FPSCOUNTER_HPP

#include <SFML/Graphics.hpp>

#include <chrono>
#include <sstream>

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

using namespace std::chrono;

class FpsCounter
{
    using clock = high_resolution_clock;

public:

    static sf::Font textFont;
    static bool init();

    FpsCounter();
    void countFps(sf::RenderWindow& window);
protected:
private:

    clock::time_point fpsT1;
    static const unsigned int FPS_COUNTER_UPDATES_PER_SEC = 3;
    static constexpr unsigned int FPS_COUNTER_UPDATE_TIME = 1000000/FPS_COUNTER_UPDATES_PER_SEC;
    unsigned int framesCount, fps;
    sf::Text fpsText;
};

#endif // FPSCOUNTER_HPP
