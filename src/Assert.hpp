#ifndef Assert_hpp
#define Assert_hpp

#include <iostream>
#include <stdio.h>

#define __SHORT_NAME__ strrchr("/" __FILE__, '/') + 1

#define LOG(x) \
    std::cout << "[trace-it-now::" << __SHORT_NAME__ << "::" << __LINE__ << "]" << x << std::endl;

#endif /* Assert_hpp */