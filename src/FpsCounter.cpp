#include "FpsCounter.hpp"

sf::Font FpsCounter::textFont;

bool loaded = FpsCounter::init();

bool FpsCounter::init()
{
    bool fontLoaded = textFont.loadFromFile 	( 	"resources/fonts/RHINOFON.TTF"	);
#ifdef DEBUG
    std::cout << "fontLoaded : " << fontLoaded << std::endl;
#endif // DEBUG

    return fontLoaded;
}

FpsCounter::FpsCounter()
{
    fpsT1 = clock::now();
    framesCount = 0;
    fps=0;

    fpsText.setFont(textFont);
    fpsText.setFillColor(sf::Color::White);
}

void FpsCounter::countFps(sf::RenderWindow& window)
{
    clock::time_point fpsT2(clock::now());
    microseconds fpsDt = duration_cast<microseconds>(fpsT2 - fpsT1);
    if(fpsDt.count() >= FPS_COUNTER_UPDATE_TIME)
    {
#ifdef DEBUG
        std::cout << "framesCount : " << framesCount << std::endl;
#endif // DEBUG
        fps = framesCount*FPS_COUNTER_UPDATES_PER_SEC;
        framesCount = 0;
        fpsT1 = fpsT2;
    }

    std::stringstream ss;

    ss << "fps : " << fps;

    fpsText.setString(ss.str());


    window.setView(window.getDefaultView());

    window.draw(fpsText);

    ++framesCount;
}
