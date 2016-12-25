#include "ParticleShape.hpp"

ParticleShape::ParticleShape(const b2ParticleSystem* partSys, int32 particleIndex, unsigned int pixelsToMeterRatio)
    : partSys(partSys), particleIndex(particleIndex), pixelsToMeterRatio(pixelsToMeterRatio)
{
    update();
}

sf::CircleShape& ParticleShape::getSfShape()
{
    return *sfShape;
}

void ParticleShape::update()
{
    std::unique_ptr<sf::CircleShape> cs(new sf::CircleShape(partSys->GetRadius()*pixelsToMeterRatio));

    const b2Vec2& b2PartPos = partSys->GetPositionBuffer()[particleIndex];

    cs->setPosition(Shape::convert(b2PartPos)*(float)pixelsToMeterRatio);

    sfShape = std::move(cs);


    sfShape->setOutlineColor(Shape::OUTLINE_COLOR);
    sfShape->setOutlineThickness(Shape::OUTLINE_THICKNESS);
    sfShape->setFillColor(Shape::FILL_COLOR);
}


