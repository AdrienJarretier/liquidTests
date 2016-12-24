#ifndef PARTICLESHAPE_HPP
#define PARTICLESHAPE_HPP

#include "Shape.hpp"


class ParticleShape : public Shape
{
public:
    ParticleShape(int32 particleIndex, unsigned int pixelsToMeterRatio);
protected:
private:

    int32 particleIndex;
};

#endif // PARTICLESHAPE_HPP
