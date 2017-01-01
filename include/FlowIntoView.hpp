#ifndef FLOWINTOVIEW_HPP
#define FLOWINTOVIEW_HPP

#include "FlowInto.hpp"

#include "ViewSFML.hpp"


class FlowIntoView : public ViewSFML
{

public:
    FlowIntoView(FlowInto& flowPhys, unsigned int pixelsToMeterRatio=1);

protected:

private:

    FlowInto& flowPhys;
    // steps the physics engine if enough time has passed
    // returns true if physics has been stepped, false otherwise
    bool step();


//    int32 microTimeStep;
//
//    clock::time_point t1;
//    microseconds acc;

};

#endif // FLOWINTOVIEW_HPP