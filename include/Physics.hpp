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
public:
    static std::string toStr(const b2Vec2& vec2);

    Physics();
    const b2World& getWorld() const;

    void step();
//    const b2Vec2& getGroundPos();
protected:
private:
    milliseconds acc;
    steady_clock::time_point t1;

    b2Vec2 gravity;
    b2World world;

    const float32 TIME_STEP = 1.0f / 60.0f;
    const duration<float32> DUR_TIME_STEP;

    const int32 VELOCITY_ITERATIONS = 8;
    const int32 POSITION_ITERATIONS = 3;
};

#endif // PHYSICS_HPP
