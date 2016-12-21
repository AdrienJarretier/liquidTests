#include "Physics.hpp"

std::string Physics::toStr(const b2Vec2& vec2)
{
    std::stringstream ss;

    ss << "( " << vec2.x << " , " << vec2.y << " )";

    return ss.str();
}

Physics::Physics()
    :t1(steady_clock::now()), gravity(0.0f, -10.0f), world(gravity), DUR_TIME_STEP(TIME_STEP)
{
#ifdef DEBUG
//    steady_clock::time_point t2(steady_clock::now());
    std::cout << acc.count() << std::endl;
#endif

    b2BodyDef groundBodyDef;

    groundBodyDef.position.Set(0, -10);

    b2Body* ground = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(100, 10);

    ground->CreateFixture(&groundBox, 0);


    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 40.0f);

    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    body->CreateFixture(&fixtureDef);
}

const b2World& Physics::getWorld() const
{
    return world;
}

void Physics::step()
{
    steady_clock::time_point t2(steady_clock::now());

    milliseconds time_span = duration_cast<milliseconds>(t2 - t1);

//    acc += time_span;
//
//    t1 = t2;

    #ifdef DEBUG
//    steady_clock::time_point t2(steady_clock::now());
    std::cout << time_span.count() << std::endl;
#endif

//    if(acc.count() > TIME_STEP)
//    {
//        world.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
////        acc -= duration_cast<seconds>(DUR_TIME_STEP);
//    }
}

//
//const b2Vec2& Physics::getGroundPos()
//{
//    return ground->GetPosition();
//}
