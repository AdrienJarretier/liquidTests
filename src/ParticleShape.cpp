#include "ParticleShape.hpp"

ParticleShape::ParticleShape(const b2ParticleSystem* partSys, int32 particleIndex, unsigned int pixelsToMeterRatio)
    : Shape(pixelsToMeterRatio), partSys(partSys), particleIndex(particleIndex)
{
    //ctor
}

void ParticleShape::update()
{
    std::unique_ptr<sf::CircleShape> cs(new sf::CircleShape(partSys->GetRadius()*pixelsToMeterRatio));

    const b2Vec2& b2PartPos = partSys->GetPositionBuffer()[particleIndex];

    cs->setPosition(convert(b2PartPos)*(float)pixelsToMeterRatio);

    sfShape = std::move(cs);


    sfShape->setOutlineColor(OUTLINE_COLOR);
    sfShape->setOutlineThickness(OUTLINE_THICKNESS);
    sfShape->setFillColor(FILL_COLOR);
}


