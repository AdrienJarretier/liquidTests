#include "Physics.hpp"
#include "Shape.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <list>
#include <memory>

using namespace std;

int main()
{
    Physics phys;

    const b2Vec2& groundP = phys.getWorld().GetBodyList()->GetPosition();

    cout << "ground : " << Physics::toStr(groundP) << endl;


    const b2Body* bod = phys.getWorld().GetBodyList();

    list<Shape> shapes;

    while(bod != 0)
    {
        const b2Fixture* fixt = bod->GetFixtureList();

        while(fixt != 0)
        {
            shapes.push_back(Shape(fixt));

            fixt = fixt->GetNext();
        }

        bod = bod->GetNext();
    }


    sf::RenderWindow window(sf::VideoMode(960, 540), "SFML works!");

    const sf::Vector2f VIEW_CENTER(0.0f, 0.0f);
    const float VIEW_WIDTH = 200;
    const float VIEW_HEIGHT = VIEW_WIDTH*9.0f/16.0f;

    cout << "VIEW_HEIGHT : " << VIEW_HEIGHT << endl;

    sf::View view(sf::FloatRect(-VIEW_WIDTH/2.0f + VIEW_CENTER.x, VIEW_HEIGHT/2.0f + VIEW_CENTER.y, VIEW_WIDTH, -VIEW_HEIGHT));

    window.setView(view);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for(std::list<Shape>::iterator it=shapes.begin() ; it!=shapes.end() ; ++it)
        {
            it->update();
            window.draw(it->getSfShape());
        }

        window.display();

        phys.step();
    }
}