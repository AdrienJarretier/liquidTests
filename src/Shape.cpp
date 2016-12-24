#include "Shape.hpp"

sf::Vector2f Shape::convert(const b2Vec2& vec)
{
    return sf::Vector2f(vec.x, vec.y);
}

Shape::Shape(const b2Fixture* fixt, unsigned int pixelsToMeterRatio)
    :pixelsToMeterRatio(pixelsToMeterRatio), fixt(fixt),  type(fixt->GetType())
{
    update();
}

sf::Shape& Shape::getSfShape()
{
    return *sfShape;
}

void Shape::update()
{
    if(type == b2Shape::e_circle)
    {
        std::cerr << "e_circle not handled" << std::endl;
    }
    else if(type == b2Shape::e_edge)
    {
        std::cerr << "e_edge not handled" << std::endl;

    }
    else if(type == b2Shape::e_polygon)
    {
        const b2PolygonShape* shape = (const b2PolygonShape*)fixt->GetShape();

        int32 vertexCount = shape->GetVertexCount();

        std::unique_ptr<sf::ConvexShape> cs(new sf::ConvexShape(vertexCount));


        const b2Body* bod = fixt->GetBody();
        const b2Vec2& b2VecBod = bod->GetPosition();
        for (int32 i=0; i<vertexCount; ++i)
        {
            const b2Vec2& b2Vec = shape->GetVertex(i);

            // the position of this vertex
            sf::Vector2f sfVec((b2Vec.x+b2VecBod.x)*pixelsToMeterRatio, (b2Vec.y+b2VecBod.y)*pixelsToMeterRatio);
            cs->setPoint(i, sfVec);
        }

        sfShape = std::move(cs);


        sfShape->setOutlineColor(OUTLINE_COLOR);
        sfShape->setOutlineThickness(OUTLINE_THICKNESS);
        sfShape->setFillColor(FILL_COLOR);
    }
    else if(type == b2Shape::e_chain)
    {
        std::cerr << "e_chain not handled" << std::endl;

    }
    else if(type == b2Shape::e_typeCount)
    {
        std::cerr << "e_typeCount not handled" << std::endl;

    }
}






