#ifndef color_hpp
#define color_hpp

#include <iostream>

#include "vec3.hpp"

void WriteColorToStream(std::ostream &out, color pixelColor)
{
    out << static_cast<int>(255.999 * pixelColor.r()) << " "
        << static_cast<int>(255.999 * pixelColor.g()) << " "   
        << static_cast<int>(255.999 * pixelColor.b()) << "\n";
}

#endif /* color_hpp */