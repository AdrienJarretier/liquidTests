#include "ParticleShape.hpp"

ParticleShape::ParticleShape(const b2ParticleSystem* partSys, int32 particleIndex, float pixelsToMeterRatio)
    : partSys(partSys), particleIndex(particleIndex), pixelsToMeterRatio(pixelsToMeterRatio)
{
    std::unique_ptr<sf::CircleShape> cs(new sf::CircleShape(partSys->GetRadius()*pixelsToMeterRatio));

    const b2Vec2& b2PartPos = partSys->GetPositionBuffer()[particleIndex];

    cs->setPosition(Shape::convert(b2PartPos)*pixelsToMeterRatio);

    sfShape = std::move(cs);


    sfShape->setOutlineColor(Shape::OUTLINE_COLOR);
    sfShape->setOutlineThickness(Shape::OUTLINE_THICKNESS);
    sfShape->setFillColor(Shape::FILL_COLOR);

    sfShape->setOrigin(partSys->GetRadius()*pixelsToMeterRatio, partSys->GetRadius()*pixelsToMeterRatio);
}

sf::CircleShape& ParticleShape::getSfShape()
{
    return *sfShape;
}

void ParticleShape::update(sf::RenderWindow& window)
{
    const b2Vec2& b2PartPos = partSys->GetPositionBuffer()[particleIndex];

    sfShape->setPosition(Shape::convert(b2PartPos)*pixelsToMeterRatio);

    window.draw(*sfShape);
}


