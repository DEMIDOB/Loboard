//
//  Interface.hpp
//  Loboard
//
//  Created by Dan Demidov on 04.11.22.
//

#ifndef Interface_hpp
#define Interface_hpp

#include "../Board.hpp"
#include "../Devices/Device.hpp"

class Interface
{
protected:
    Board* board;
public:
    explicit Interface(Board* board);
    ~Interface();
    
    Board* GetBoard() const;
    
    virtual bool Update() = 0;
};

#endif /* Interface_hpp */
