#include "FlowInto.hpp"

FlowInto::FlowInto()
    :distribution(-2,2)
{
#ifdef DEBUG
    std::cout  << "FlowInto constr" << std::endl;
#endif // DEBUG
    b2ParticleSystemDef partSysDef;
    partSysDef.radius = 0.35f;

    particleSystem = world.CreateParticleSystem(&partSysDef);
//    particleSystem->SetMaxParticleCount(300);

    partDef.position.y = 20;
    partDef.velocity.Set(0, -30);

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

int32 FlowInto::newParticle()
{

    float32 x = distribution(generator);

//#ifdef DEBUG
////    std::cout << "x : " << x << std::endl;
//    std::cout << "particles count : "  << particleSystem->GetParticleCount() << std::endl;
//#endif // DEBUG
    partDef.position.x = x;
    return particleSystem->CreateParticle(partDef);
}


void FlowInto::step()
{
    world.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS, PARTICLES_ITERATIONS);
}

const b2ParticleSystem* FlowInto::getParticleSystem()
{
    return particleSystem;
}
