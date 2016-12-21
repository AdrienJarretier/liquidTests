#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#ifdef DEBUG
#include <iostream>
#endif

#include <Box2D/Box2D.h>

#include <chrono>
#include <sstream>
#include <string>

using namespace std::chrono;

class Physics
{
    using clock = high_resolution_clock;

public:
    static std::string toStr(const b2Vec2& vec2);

    Physics();
    const b2World& getWorld() const;

    void step();
//    const b2Vec2& getGroundPos();
protected:
private:
    b2Vec2 gravity;
    b2World world;

    const float32 TIME_STEP = 1.0f / 60.0f;

    const int32 VELOCITY_ITERATIONS = 8;
    const int32 POSITION_ITERATIONS = 3;

    const int32 MICROSECONDS_TIME_STEP;

    clock::time_point t1;
    microseconds acc;


};

#endif // PHYSICS_HPP
