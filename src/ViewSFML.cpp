#include "ViewSFML.hpp"

ViewSFML::ViewSFML(Physics& phys)
:phys(phys)
{
    #ifdef DEBUG
        std::cout << "ground pos from ViewSFML : ";
        std::cout << Physics::toStr(phys.getWorld().GetBodyList()->GetPosition()) << std::endl;
    #endif // DEBUG
}
