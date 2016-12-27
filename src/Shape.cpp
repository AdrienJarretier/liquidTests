#include "Shape.hpp"

sf::Vector2f Shape::convert(const b2Vec2& vec)
{
    return sf::Vector2f(vec.x, vec.y);
}

const sf::Color Shape::OUTLINE_COLOR = sf::Color::Red;
const sf::Color Shape::FILL_COLOR = sf::Color::Black;

Shape::Shape(const b2Fixture* fixt, float pixelsToMeterRatio)
    :pixelsToMeterRatio(pixelsToMeterRatio), fixt(fixt),  type(fixt->GetType())
{
//    update();
}

sf::Shape& Shape::getSfShape()
{
    return *sfShape;
}

void Shape::update(sf::RenderWindow& window)
{
    if(type == b2Shape::e_circle)
    {
//#ifdef DEBUG
//        std::cout << "fixt : " << fixt << std::endl;
//        std::cout << "pos : " << Physics::toStr(fixt->GetBody()->GetPosition()) << std::endl;
//#endif // DEBUG
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

        window.draw(*sfShape);
    }
    else if(type == b2Shape::e_chain)
    {
        const b2ChainShape* shape = (const b2ChainShape*)fixt->GetShape();

        int32 vertexCount = shape->m_count;

//#ifdef DEBUG
//        std::cout << "vertexCount : " << vertexCount << std::endl;
//#endif // DEBUG

        sf::VertexArray vertices(sf::LineStrip);

        const b2Body* bod = fixt->GetBody();
        const b2Vec2& b2VecBod = bod->GetPosition();
        for (int32 i=0; i<vertexCount; ++i)
        {
            const b2Vec2& b2Vec = shape->m_vertices[i];

            // the position of this vertex
            sf::Vector2f sfVec((b2Vec.x+b2VecBod.x)*pixelsToMeterRatio, (b2Vec.y+b2VecBod.y)*pixelsToMeterRatio);
            vertices.append(sf::Vertex(sfVec, sf::Color::White));
        }



        window.draw(vertices);
    }
    else if(type == b2Shape::e_typeCount)
    {
        std::cerr << "e_typeCount not handled" << std::endl;

    }
}




