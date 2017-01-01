#include "FlowIntoView.hpp"

FlowIntoView::FlowIntoView(FlowInto& flowPhys, unsigned int pixelsToMeterRatio)
    :ViewSFML(flowPhys, pixelsToMeterRatio), flowPhys(flowPhys)
{
#ifdef DEBUG
    std::cout  << "FlowIntoView constr" << std::endl;
#endif // DEBUG
}

bool FlowIntoView::step()
{
//#ifdef DEBUG
//    std::cout  << "step" << std::endl;
//#endif // DEBUG

    particles.push_back(ParticleShape(flowPhys.getParticleSystem(), flowPhys.newParticle(), pixelsToMeterRatio));

    return ViewSFML::step();
}
