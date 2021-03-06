#ifndef FLOWINTOVIEW_HPP
#define FLOWINTOVIEW_HPP

#include "FlowInto.hpp"

#include "ViewSFML.hpp"

class FlowIntoView : public ViewSFML
{

public:

    static constexpr float32 PI = 3.141592654;

    // the flow of the faucet (particle area / microsec)
    static constexpr float32 FLOW_RATE = 70./1000000.;

    FlowIntoView(FlowInto& flowPhys, unsigned int pixelsToMeterRatio=1);

    void launch(unsigned int windowWidth);

protected:

private:

    FlowInto& flowPhys;
    // steps the physics engine if enough time has passed
    // returns true if physics has been stepped, false otherwise
    bool step();

    float32 particleArea;

    clock::time_point t1;
    float32 flowAcc;
    microseconds acc;

};

#endif // FLOWINTOVIEW_HPP
