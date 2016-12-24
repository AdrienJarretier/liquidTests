#include "ViewSFML.hpp"

ViewSFML::ViewSFML(Physics& phys, unsigned int pixelsToMeterRatio)
    :phys(phys), pixelsToMeterRatio(pixelsToMeterRatio),
     t1(clock::now())
{
    const b2Body* bod = phys.getWorld().GetBodyList();

    // instanciates a Shape object for each fixture of each physics body
    while(bod != 0)
    {
        const b2Fixture* fixt = bod->GetFixtureList();

        while(fixt != 0)
        {
            this->shapes.push_back(Shape(fixt, pixelsToMeterRatio));

            fixt = fixt->GetNext();
        }

        bod = bod->GetNext();
    }

    setSpeedFactor(1);
}

void ViewSFML::launch(unsigned int windowWidth, unsigned int windowHeight)
{
    this->aspectRatio = (float)windowWidth / (float)windowHeight;
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    launch();
}

void ViewSFML::launch(unsigned int windowHeight, float aspectRatio)
{

    this->aspectRatio = aspectRatio;
    this->windowWidth = windowHeight*aspectRatio;
    this->windowHeight = windowHeight;
    launch();
}

void ViewSFML::launch()
{
#ifdef DEBUG
    std::cout << "window : " << windowWidth << " x " << windowHeight << std::endl;
#endif // DEBUG

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");

    viewHeight = windowHeight;
    viewWidth = viewHeight * aspectRatio;

#ifdef DEBUG
    std::cout << "view : " << viewWidth << " x " << viewHeight << " (" << viewCenter.x << "," << viewCenter.y << ")" << std::endl;
#endif // DEBUG

    sf::View sfView(sf::FloatRect(-viewWidth/2.0f + viewCenter.x, viewHeight/2.0f + viewCenter.y, viewWidth, -viewHeight));

    window.setView(sfView);

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

        step();
    }
}

void ViewSFML::setSpeedFactor(int32 fact)
{
    speedFactor = fact;
    microTimeStep = Physics::TIME_STEP*1000000/speedFactor;
}

void ViewSFML::step()
{
    clock::time_point t2(clock::now());

    microseconds dt = duration_cast<microseconds>(t2 - t1);;

    acc += dt;

    t1 = t2;

    if(acc.count() > microTimeStep)
    {

#ifdef DEBUG
//        std::cout << acc.count() << std::endl;
#endif
        phys.step();
        acc -= microseconds(microTimeStep);
    }
}
