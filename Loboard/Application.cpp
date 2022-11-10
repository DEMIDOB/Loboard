//
//  Application.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include <fstream>
#include "Application.hpp"

Application::Application(int argc, const char** argv)
    : argc(argc), argv(argv), m_Board(new Board()),
      interface(new CommandLineInterface(m_Board)), running(false)
{

}

Application::~Application()
{
    
}

Application* Application::getInstance(int argc, const char** argv)
{
    static Application* shared_;
    
    if (shared_ == nullptr)
    {
        LOG("New Application instance created\n");
        shared_ = new Application(argc, argv);
    }
    
    return shared_;
}

Application *Application::getInstance()
{
    static Application* shared_;

    if (shared_ != nullptr)
    {
        return shared_;
    }

    LOG("Could not get an application instance: this method should at first be called with argc and argv provided!")
    return nullptr;
}

void Application::run()
{

    if (running)
    {
        return;
    }

    running = true;
    const char* fileArgMark = "-f";

    for (int ai = 1; ai < argc; ++ai)
    {
        if (argv[ai] != nullptr && strcmp(fileArgMark, argv[ai]) == 0 && ai + 1 < argc)
        {
            const char* saveFPath = argv[ai + 1];
            char* fileDataBuffer = (char*) calloc(SAVE_FILE_MAX_LENGTH, SAVE_FILE_MAX_LENGTH);

            std::fstream saveFile;
            saveFile.open(saveFPath, std::ios::in);
            saveFile.read(fileDataBuffer, SAVE_FILE_MAX_LENGTH);
            saveFile.close();

            running = ((CommandLineInterface*) interface)->HandleCommand(&fileDataBuffer);
            delete fileDataBuffer;
        }
    }



    while (running)
    {
        running = interface->Update();
    }
}
