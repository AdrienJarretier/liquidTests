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

    clock::time_point t2(clock::now());

    microseconds dt = duration_cast<microseconds>(t2 - t1);;

    acc += dt;

    t1 = t2;

    while(flowAcc/(float32)acc.count() < FLOW_RATE)
    {
        flowAcc += particleArea;

        int32 partId = flowPhys.newParticle();

        if(flowPhys.getParticleSystem()->GetMaxParticleCount() <= 0 || (int32)particles.size() < flowPhys.getParticleSystem()->GetMaxParticleCount())
            particles.push_back(ParticleShape(flowPhys.getParticleSystem(), partId, pixelsToMeterRatio));
    }

    return ViewSFML::step();
}
