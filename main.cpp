#include "ViewSFML.hpp"

#include "HelloWorld.hpp"

#include <iostream>

using namespace std;

int main()
{
    HelloWorld phys;

    ViewSFML view(phys, 10);

//    view.setSpeedFactor(3);

    view.launch(900);

}
