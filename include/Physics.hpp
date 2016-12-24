#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#ifdef DEBUG
#include <iostream>
#endif

#include <Box2D/Box2D.h>

#include <list>
#include <sstream>
#include <string>

class Physics
{

public:
    static std::string toStr(const b2Vec2& vec2);

    static constexpr float32 TIME_STEP = 1.0f / 60.0f;

    static const int32 VELOCITY_ITERATIONS = 8;
    static const int32 POSITION_ITERATIONS = 3;
    static const int32 PARTICLES_ITERATIONS = 1;

    Physics();
    virtual ~Physics() = 0;

    const b2World& getWorld() const;

    void step();

//    const b2Vec2& getGroundPos();
protected:
    b2Vec2 gravity;
    b2World world;
private:

};

#endif // PHYSICS_HPP
