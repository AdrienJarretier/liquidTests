#include "Physics.hpp"
#include "ViewSFML.hpp"

#include <iostream>

using namespace std;

int main()
{
    Physics phys;

    ViewSFML view(phys);

//    view.setSpeedFactor(3);

    view.launch(540);

}
