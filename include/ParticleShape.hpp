#ifndef PARTICLESHAPE_HPP
#define PARTICLESHAPE_HPP

#include "Shape.hpp"


class ParticleShape : public Shape
{
public:

    ParticleShape(const b2ParticleSystem* partSys, int32 particleIndex, unsigned int pixelsToMeterRatio);

    void update();

protected:
private:

    const b2ParticleSystem* partSys;
    int32 particleIndex;
};

#endif // PARTICLESHAPE_HPP
