#include "FlowInto.hpp"

FlowInto::FlowInto()
{
    b2ParticleSystemDef partSysDef;
    partSysDef.radius = 0.35f;

    b2ParticleSystem* particleSystem = world.CreateParticleSystem(&partSysDef);


    b2BodyDef bowlDef;
    bowlDef.position.Set(0, 0);

    b2Body* bowl = world.CreateBody(&bowlDef);

    b2ChainShape bowlShape;

    std::vector<b2Vec2> vertices;

    vertices.push_back(b2Vec2(-20, 5));
    vertices.push_back(b2Vec2(-15, 0));
    vertices.push_back(b2Vec2(-15, -10));
    vertices.push_back(b2Vec2(15, -10));
    vertices.push_back(b2Vec2(15, 0));
    vertices.push_back(b2Vec2(20, 5));
    bowlShape.CreateChain(vertices.data(), vertices.size());

    bowl->CreateFixture(&bowlShape, 0);
}


void FlowInto::step()
{
    world.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS, PARTICLES_ITERATIONS);
}

