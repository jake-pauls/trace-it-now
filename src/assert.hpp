#ifndef assert_hpp
#define assert_hpp

#include <iostream>
#include <cstring>

#define __SHORT_NAME__ strrchr("/" __FILE__, '/') + 1

#define LOG(x) \
    std::cout << "[trace-it-now::" << __SHORT_NAME__ << "::" << __LINE__ << "] " << x << std::endl;

#define ELOG(x) \
    std::cerr << "[trace-it-now::e::" << __SHORT_NAME__ << "::" << __LINE__ << "] " << x << "\n" << std::flush;

#endif /* assert_hpp */