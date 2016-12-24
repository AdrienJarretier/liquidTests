#ifndef FLOWINTO_HPP
#define FLOWINTO_HPP

#include "Physics.hpp"


class FlowInto : public Physics
{
public:
    FlowInto();
protected:
private:
    b2ParticleSystem* particleSystem;
};

#endif // FLOWINTO_HPP
