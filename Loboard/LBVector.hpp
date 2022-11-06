//
//  LBVector.hpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#ifndef LBVector_hpp
#define LBVector_hpp

typedef struct LBVector LBVector;

struct LBVector
{
    int x = 0;
    int y = 0;
};

LBVector nullLBVector();

#endif /* LBVector_hpp */
