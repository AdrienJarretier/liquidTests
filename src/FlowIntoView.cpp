#include "FlowIntoView.hpp"

FlowIntoView::FlowIntoView(unsigned int pixelsToMeterRatio)
    :flowPhys(new FlowInto), ViewSFML(*flowPhys, pixelsToMeterRatio)
{
    //ctor
}

bool FlowIntoView::step()
{
    #ifdef DEBUG
    std::cout  << "step" << std::endl;
    #endif // DEBUG

    return ViewSFML::step();
}
