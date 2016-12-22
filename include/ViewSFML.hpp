#ifndef VIEWSFML_HPP
#define VIEWSFML_HPP

#ifdef DEBUG
#include <iostream>
#endif

#include "Physics.hpp"
#include "Shape.hpp"

#include <SFML/Graphics.hpp>

#include <list>
#include <memory>

class ViewSFML
{
    public:
        ViewSFML(Physics& phys);
    protected:
    private:
        Physics& phys;
};

#endif // VIEWSFML_HPP
