#ifndef FLOWINTO_HPP
#define FLOWINTO_HPP

#include "Physics.hpp"

#include <random>
#include <vector>

class FlowInto : public Physics
{
public:
    FlowInto();
    static const int32 PARTICLES_ITERATIONS = 1;

    /**
    @return the index of the particle.
    **/
    int32 newParticle();
    void step();
    const b2ParticleSystem* getParticleSystem();
protected:
private:
    b2ParticleDef partDef;
    b2ParticleSystem* particleSystem;

    std::default_random_engine generator;
    std::uniform_real_distribution<float32> distribution;
};

#endif // FLOWINTO_HPP
