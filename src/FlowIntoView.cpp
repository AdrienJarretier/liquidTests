#include "FlowIntoView.hpp"

FlowIntoView::FlowIntoView(unsigned int pixelsToMeterRatio)
    :ViewSFML(flowPhys, pixelsToMeterRatio)
{
#ifdef DEBUG
    std::cout  << "FlowIntoView constr" << std::endl;
#endif // DEBUG
}

bool FlowIntoView::step()
{
#ifdef DEBUG
    std::cout  << "step" << std::endl;
#endif // DEBUG

    return ViewSFML::step();
}
