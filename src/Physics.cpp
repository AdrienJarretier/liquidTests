#include "Physics.hpp"

std::string Physics::toStr(const b2Vec2& vec2)
{
    std::stringstream ss;

    ss << "( " << vec2.x << " , " << vec2.y << " )";

    return ss.str();
}

Physics::Physics()
    :gravity(0.0f, -10.0f), world(gravity)
{
}

Physics::~Physics()
{

}

const b2World& Physics::getWorld() const
{
    return world;
}

void Physics::step()
{
    world.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}

//
//const b2Vec2& Physics::getGroundPos()
//{
//    return ground->GetPosition();
//}
