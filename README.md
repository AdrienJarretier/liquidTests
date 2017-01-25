## Description

tests of [LiquidFun](https://github.com/google/liquidfun)

display rendering is done with [SFML](https://github.com/SFML/SFML)


The base class for all tests is the Physics class ([header](include/Physics.hpp) / [implementation](src/Physics.cpp))

### Build instructions

I'll be talking about **linux**( Ubuntu 16 ) and **Windows**( 7 ) here

            |       |
---         | ---
**Linux**   | <ol><li>I made a modif in the project build options see [f44a0db](https://github.com/AdrienJarretier/liquidTests/commit/f44a0db7aba93f02b26a74646d329dddf8575feb) , so it works on Windows but it's probably broken for Linux, just revert those 2 lines from Windows to Linux </li><li>If you have installed the sfml library you shouldn't have anything to do, the compiler will find the include and lib files on the system</li></ol>
**Windows** | <ol><li>Once you have a working SFML lib you have to indicate to Code::Blocks where to find the SFML header directory, go into the **compiler settings**, and under **Search directorie** for the "Compiler" add your SFML include dir</li><li>Still under **Search directorie** for the **Linker** now indicate your sfml lib directory</li><li>Now, at this point you should be able to compile</li><li>last step, as long as you run the program through code::blocks it should work because the sfml dlls are at the project root, if you run without code::blocks, move the dlls either with your exec file or in your system if you know where to</li></ol>
