#include "FlowIntoView.hpp"

FlowIntoView::FlowIntoView(FlowInto& flowPhys, unsigned int pixelsToMeterRatio)
    :ViewSFML(flowPhys, pixelsToMeterRatio), flowPhys(flowPhys)
//    ,t1(clock::now())
{
    float32 r = flowPhys.getParticleSystem()->GetRadius();
    particleArea = PI * r * r;

#ifdef DEBUG
    std::cout  << "FlowIntoView constr, particleArea : " << particleArea << std::endl;
#endif // DEBUG
}

void FlowIntoView::launch(unsigned int windowWidth)
{
    t1 = clock::now();
    ViewSFML::launch(windowWidth);
}

bool FlowIntoView::step()
{
//#ifdef DEBUG
//    std::cout  << "step" << std::endl;
//#endif // DEBUG

    particles.push_back(ParticleShape(flowPhys.getParticleSystem(), flowPhys.newParticle(), pixelsToMeterRatio));

    return ViewSFML::step();
}
