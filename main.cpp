#include "ViewSFML.hpp"

#include "tests.hpp"

#include <iostream>

using namespace std;

int main()
{
    FlowInto phys;

    ViewSFML view(phys, 10);

    view.setSpeedFactor(1);

    view.launch(900);

}
