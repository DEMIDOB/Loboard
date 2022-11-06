//
//  Application.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include "Application.hpp"

Application::Application()
    : m_Board(new Board()), interface(new CommandLineInterface(m_Board)), running(false)
{

}

Application::~Application()
{
    
}

Application* Application::getInstance()
{
    static Application* shared_;
    
    if (shared_ == nullptr)
    {
        LOG("New Application instance created");
        shared_ = new Application();
    }
    
    return shared_;
}

void Application::run()
{
    if (running)
    {
        return;
    }
    else
    {
        running = true;
        
        while (running)
        {
            running = interface->Update();
        }
    }
}
