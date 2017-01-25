## Description

tests of [LiquidFun](https://github.com/google/liquidfun)

display rendering is done with [SFML](https://github.com/SFML/SFML)


The base class for all tests is the Physics class ([header](include/Physics.hpp) / [implementation](src/Physics.cpp))

### Build instructions

I'll be talking about **linux**( Ubuntu 16 ) and **Windows**( 7 ) here

            |       |
---         | ---
**Linux**   | If you have installed the sfml library you shouldn't have anything to do, the compiler will find the include and lib files on the system
**Windows** | <ol><li>Once you have a working SFML lib you have to indicate to Code::Blocks where to find the SFML header directory, go into the **compiler settings**, and under **Search directorie** for the "Compiler" add your SFML include dir</li><li>Still under **Search directorie** for the **Linker** now indicate your sfml lib directory</li></ol>
