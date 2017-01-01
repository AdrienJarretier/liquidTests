#include "FlowIntoView.hpp"

FlowIntoView::FlowIntoView(FlowInto& flowPhys, unsigned int pixelsToMeterRatio)
    :ViewSFML(flowPhys, pixelsToMeterRatio), flowPhys(flowPhys)
//    ,t1(clock::now())
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
