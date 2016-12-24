#include "FlowInto.hpp"

FlowInto::FlowInto()
{
    b2ParticleSystemDef partSysDef;
    partSysDef.radius = 0.35f;

    particleSystem = world.CreateParticleSystem(&partSysDef);

    b2CircleShape partGpCirlce;

    partGpCirlce.m_radius = 10.0f;

    b2ParticleGroupDef partGpDef;

    partGpDef.position.Set(0, 30);
    partGpDef.shape = &partGpCirlce;

    particleSystem->CreateParticleGroup(partGpDef);

}
