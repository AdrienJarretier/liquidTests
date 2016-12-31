#ifndef FLOWINTO_HPP
#define FLOWINTO_HPP

#include "Physics.hpp"

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
protected:
private:
    b2ParticleDef partDef;
    b2ParticleSystem* particleSystem;
};

#endif // FLOWINTO_HPP
