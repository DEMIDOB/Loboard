//
// Created by Dan Demidov on 20.11.22.
//

#ifndef LOBOARD_STRINGOUTPUTISSUED_HPP
#define LOBOARD_STRINGOUTPUTISSUED_HPP

#include <exception>
#include <string>
#include <utility>

namespace DeviceExceptions
{
    class StringOutputIssued: std::exception
    {
    private:
        const std::string _output;
    public:
        explicit StringOutputIssued(std::string output) : _output(std::move(output)) {}

        std::string GetOutput() const { return _output; }
    };
}

#endif //LOBOARD_STRINGOUTPUTISSUED_HPP
