#include "HelloWorld.hpp"

HelloWorld::HelloWorld()
{
    init();
}

void HelloWorld::init()
{
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
