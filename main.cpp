#include "FlowIntoView.hpp"

#include "tests.hpp"

#include <iostream>

using namespace std;

int main()
{

    FlowInto phys;

//    cout << "part iterations : " << phys.getWorld().CalculateReasonableParticleIterations(Physics::TIME_STEP) << endl;
//
    FlowIntoView view(phys, 10);

    view.setSpeedFactor(1);

    view.launch(720);

}
