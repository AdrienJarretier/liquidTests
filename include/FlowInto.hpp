#ifndef FLOWINTO_HPP
#define FLOWINTO_HPP

#include "Physics.hpp"

#include <vector>

class FlowInto : public Physics
{
public:
    FlowInto();
    static const int32 PARTICLES_ITERATIONS = 1;
    void step();
protected:
private:
};

#endif // FLOWINTO_HPP
