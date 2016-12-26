#include "ViewSFML.hpp"

sf::Font ViewSFML::textFont;

bool loaded = ViewSFML::init();

bool ViewSFML::init()
{
    bool fontLoaded = textFont.loadFromFile 	( 	"resources/fonts/RHINOFON.TTF"	);
#ifdef DEBUG
    std::cout << "fontLoaded : " << fontLoaded << std::endl;
#endif // DEBUG

    return fontLoaded;
}

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

    const b2ParticleSystem * partSys = phys.getWorld().GetParticleSystemList();

    while(partSys != 0)
    {
#ifdef DEBUG
        std::cout << "particle system here" << std::endl;
#endif // DEBUG

        for(int32 i=0; i<partSys->GetParticleCount(); ++i)
        {
            this->particles.push_back(ParticleShape(partSys,i,pixelsToMeterRatio));
        }

        partSys = partSys->GetNext();
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

    clock::time_point fpsT1(clock::now());

    unsigned int framesThisSecond = 0, fps=0;

    while (window.isOpen())
    {
        window.setView(sfView);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for(std::list<Shape>::iterator it=shapes.begin() ; it!=shapes.end() ; ++it)
        {
            it->update(window);
        }

        for(std::list<ParticleShape>::iterator it=particles.begin() ; it!=particles.end() ; ++it)
        {
            it->update(window);
        }


        clock::time_point fpsT2(clock::now());
        microseconds fpsDt = duration_cast<microseconds>(fpsT2 - fpsT1);
        if(fpsDt.count() >= 1000000)
        {
            #ifdef DEBUG
            std::cout << "framesThisSecond : " << framesThisSecond << std::endl;
            #endif // DEBUG
            fps = framesThisSecond;
            framesThisSecond = 0;
            fpsT1 = fpsT2;
        }

        std::stringstream ss;

        ss << "fps : " << fps;

        sf::Text fpsText(ss.str(), textFont);

        fpsText.setFillColor(sf::Color::White);

//        window.setDe

        window.setView(window.getDefaultView());

        window.draw(fpsText);

        window.display();

        ++framesThisSecond;

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
