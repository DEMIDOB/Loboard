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
private:
    std::vector<std::string> currentSessionHistory;

protected:
    Board* board;

    void addCommandToSessionHistory(std::string cmd);
public:
    explicit Interface(Board* board);
    ~Interface();
    
    Board* GetBoard() const;
    const std::vector<std::string>& GetCurrentSessionHistory() const { return currentSessionHistory; }

    virtual bool Update() = 0;
};

#endif /* Interface_hpp */
