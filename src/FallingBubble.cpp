#include "FallingBubble.hpp"

FallingBubble::FallingBubble()
{
    b2ParticleSystemDef partSysDef;
    partSysDef.radius = 0.35f;

    b2ParticleSystem* particleSystem = world.CreateParticleSystem(&partSysDef);

    particleSystem->SetMaxParticleCount(10000);

    b2CircleShape partGpCirlce;

    partGpCirlce.m_radius = 30.0f;

    b2ParticleGroupDef partGpDef;

    partGpDef.position.Set(0, 30);
    partGpDef.shape = &partGpCirlce;

    particleSystem->CreateParticleGroup(partGpDef);


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

    #ifdef DEBUG
    std::cout << "particles count : "  << particleSystem->GetParticleCount() << std::endl;
    #endif // DEBUG
}


void FallingBubble::step()
{
    world.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS, PARTICLES_ITERATIONS);
}

