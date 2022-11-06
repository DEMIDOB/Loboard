//
//  Logger.hpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#ifndef Logger_hpp
#define Logger_hpp

#include <iostream>

#ifdef DEBUG
    #define LOG(x) std::cout << "[ INFO ] " << x << std::endl;
    #define ERR(x) std::cerr << "[ERROR!] " << x << std::endl;
    #define F_ERR(x) std::cerr << "[ERROR!] " << x << std::endl; std::exit(-1);
#else
    #define LOG(x)
    #define ERR(x)
#endif

#endif /* Logger_hpp */
