//
//  main.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include <iostream>
#include "Application.hpp"

int main(int argc, const char * argv[])
{
    Application* app = Application::getInstance();
    app->run();
    delete app;
    return 0;
}
