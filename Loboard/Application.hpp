//
//  Application.hpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#ifndef Application_hpp
#define Application_hpp

#define SAVE_FILE_MAX_LENGTH 8192

#include <iostream>

#include "Logger.hpp"
#include "Board.hpp"

#include "Interfaces/Interface.hpp"
#include "Interfaces/CLI/CommandLineInterface.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "Loboard"

class Application {
protected:
    int argc;
    const char** argv;

    Application(int argc, const char** argv);
    bool recordCurrentSession;
    bool running;

public:
    ~Application();
    
    Application(Application& other) = delete;
    void operator=(const Application&) = delete;
    
    static Application* getInstance(int argc, const char** argv);
    static Application* getInstance();
    void run(bool dontRecordCurrentSessionSetting = false);
    
private:
    Board* m_Board;
    Interface* interface;
};

#endif /* Application_hpp */
