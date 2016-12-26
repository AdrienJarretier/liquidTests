#ifndef PARTICLESHAPE_HPP
#define PARTICLESHAPE_HPP

#include "Shape.hpp"


class ParticleShape
{
public:

    ParticleShape(const b2ParticleSystem* partSys, int32 particleIndex, unsigned int pixelsToMeterRatio);

    sf::CircleShape& getSfShape();

    void update(sf::RenderWindow& window);

protected:
private:

    const b2ParticleSystem* partSys;
    int32 particleIndex;
    unsigned int pixelsToMeterRatio;

    std::unique_ptr<sf::CircleShape> sfShape;
};

#endif // PARTICLESHAPE_HPP
