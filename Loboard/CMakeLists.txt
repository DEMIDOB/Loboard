cmake_minimum_required(VERSION 3.23)
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
        Devices/Wire.cpp
        Devices/Wire.hpp
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
        main.cpp Interfaces/CLI/Commands/Command.cpp Interfaces/CLI/Commands/Command.hpp Interfaces/CLI/Commands/ListdCommand.cpp Interfaces/CLI/Commands/ListdCommand.hpp Interfaces/CLI/Commands/ExitCommand.cpp Interfaces/CLI/Commands/ExitCommand.hpp Interfaces/CLI/Commands/NewdCommand.cpp Interfaces/CLI/Commands/NewdCommand.hpp Interfaces/CLI/Commands/StateCommand.cpp Interfaces/CLI/Commands/StateCommand.hpp Interfaces/CLI/Commands/CommandArgs.hpp)
