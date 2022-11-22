cmake_minimum_required(VERSION 3.20)
project(Loboard)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Devices)
include_directories(Devices/Gates)
include_directories(Interfaces)

add_compile_definitions(DEBUG)

add_executable(Loboard
        Devices/Gates/AndGateDevice.cpp
        Devices/Gates/AndGateDevice.hpp
        Devices/Gates/GateDevice.cpp
        Devices/Gates/GateDevice.hpp
        Devices/Gates/OrGateDevice.cpp
        Devices/Gates/OrGateDevice.hpp
        Devices/Device.cpp
        Devices/Device.hpp
        Devices/Devices.hpp
        Devices/GroundDevice.cpp
        Devices/GroundDevice.hpp
        Devices/PowerDevice.cpp
        Devices/PowerDevice.hpp
        Devices/DirectionalWire.cpp
        Devices/DirectionalWire.hpp
        Interfaces/CLI/CommandLineInterface.cpp
        Interfaces/CLI/CommandLineInterface.hpp
        Interfaces/Interface.cpp
        Interfaces/Interface.hpp
        Application.cpp
        Application.hpp
        Board.cpp
        Board.hpp
        LBVector.cpp
        LBVector.hpp
        Logger.cpp
        Logger.hpp
        main.cpp Interfaces/CLI/Commands/CommandHandler.cpp Interfaces/CLI/Commands/CommandHandler.hpp Interfaces/CLI/Commands/LsCommand.cpp Interfaces/CLI/Commands/LsCommand.hpp Interfaces/CLI/Commands/ExitCommand.cpp Interfaces/CLI/Commands/ExitCommand.hpp Interfaces/CLI/Commands/NewdCommand.cpp Interfaces/CLI/Commands/NewdCommand.hpp Interfaces/CLI/Commands/StateCommand.cpp Interfaces/CLI/Commands/StateCommand.hpp Interfaces/CLI/Commands/CommandArgs.hpp Interfaces/CLI/Commands/WireCommand.cpp Interfaces/CLI/Commands/WireCommand.hpp Interfaces/CLI/Commands/RemoveCommand.cpp Interfaces/CLI/Commands/RemoveCommand.hpp Interfaces/CLI/Commands/CommandReturn.hpp Interfaces/CLI/Session/SessionVariables.cpp Interfaces/CLI/Session/SessionVariables.hpp Devices/Gates/XorGateDevice.cpp Devices/Exceptions/StringOutputIssued.hpp Devices/Gates/NandGateDevice.cpp Devices/Gates/NandGateDevice.hpp Devices/Gates/NorGateDevice.cpp Devices/Gates/NorGateDevice.hpp)
