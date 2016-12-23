#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#ifdef DEBUG
#include <iostream>
#endif

#include <Box2D/Box2D.h>

#include <sstream>
#include <string>

class Physics
{

public:
    static std::string toStr(const b2Vec2& vec2);

    static constexpr float32 TIME_STEP = 1.0f / 60.0f;

    static const int32 VELOCITY_ITERATIONS = 8;
    static const int32 POSITION_ITERATIONS = 3;

    Physics();
    const b2World& getWorld() const;

    void step();

//    const b2Vec2& getGroundPos();
protected:
private:
    b2Vec2 gravity;
    b2World world;

};

#endif // PHYSICS_HPP
