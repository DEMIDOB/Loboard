//
//  Application.cpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#include <string>
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

Application* Application::GetInstance(int argc, const char** argv)
{
    static Application* shared_;
    
    if (shared_ == nullptr)
    {
        LOG("New Application instance created\n");
        shared_ = new Application(argc, argv);
    }
    
    return shared_;
}

Application *Application::GetInstance()
{
    static Application* shared_;

    if (shared_ != nullptr)
    {
        return shared_;
    }

    LOG("Could not get an application instance: this method should at first be called with argc and argv provided!")
    return nullptr;
}

void Application::Run(bool dontRecordCurrentSessionSetting)
{
    // prevent from entering the main loop multiple times
    
    if (running)
    {
        return;
    }

    running = true;


    // load saved session if passed as an argument -f
    // and detect if user explicitly asked not to record current session

    const char* currentSessionFile = "lastLoboardSession.lbs";
    const char* fileArgMark = "-f";
    const char* dontRecordSessionMark = "--no-backup";
    bool dontRecordCurrentSession = dontRecordCurrentSessionSetting;

    unsigned int backupFileInitializationMode = std::ios::out;

    for (int ai = 1; ai < argc; ++ai)
    {
        if (argv[ai] == nullptr)
        {
            continue;
        }

        if (strcmp(fileArgMark, argv[ai]) == 0 && ai + 1 < argc)
        {
            const char* saveFPath = argv[ai + 1];
            char* fileDataBuffer = (char*) calloc(SAVE_FILE_MAX_LENGTH, SAVE_FILE_MAX_LENGTH);

            std::fstream saveFile;
            saveFile.open(saveFPath, std::ios::in);
            saveFile.read(fileDataBuffer, SAVE_FILE_MAX_LENGTH);
            saveFile.close();

            running = ((CommandLineInterface*) interface)->HandleCommand(&fileDataBuffer);
            delete fileDataBuffer;

            if (strcmp(saveFPath, currentSessionFile) == 0)
                backupFileInitializationMode = std::ios::app;
        }

        dontRecordCurrentSession = dontRecordCurrentSession || strcmp(argv[ai], dontRecordSessionMark) == 0;
    }

    this->recordCurrentSession = !dontRecordCurrentSession;

    std::fstream sessionBackupFile;

    if (recordCurrentSession)
    {
        sessionBackupFile.open(currentSessionFile, backupFileInitializationMode);
        sessionBackupFile.write("", 0);
        sessionBackupFile.close();
    }


    // main loop

    while (running)
    {
        running = interface->Update();

        if (recordCurrentSession && running)
        {
            sessionBackupFile.open(currentSessionFile, std::ios::app);
            std::string lastCommand = interface->GetCurrentSessionHistory().back();
            lastCommand.append("\n");
            sessionBackupFile.write(lastCommand.c_str(), lastCommand.size());
            sessionBackupFile.close(); // closed in order for the file to stay closed even in case of
                                       // some unexpected exception in interface->Update()
        }
    }
}
