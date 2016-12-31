#ifndef FALLINGBUBBLE_HPP
#define FALLINGBUBBLE_HPP

#include "Physics.hpp"

#include <vector>

class FallingBubble : public Physics
{
public:
    FallingBubble();
    static const int32 PARTICLES_ITERATIONS = 1;
    void step();
protected:
private:
};

#endif // FALLINGBUBBLE_HPP
