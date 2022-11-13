//
// Created by Dan Demidov on 13.11.22.
//

#ifndef LOBOARD_SESSIONVARIABLES_HPP
#define LOBOARD_SESSIONVARIABLES_HPP

#include <map>
#include <string>

class CommandLineInterface;

class SessionVariablesSet
{
private:
    std::map<std::string, std::string> variables;
    void set(std::string& v_name, std::string& value);
public:
    static bool IsValidName(std::string& v_name);
    bool Has(std::string& v_name);
    std::string Get(std::string& v_name);

    friend class CommandLineInterface;
};

#endif //LOBOARD_SESSIONVARIABLES_HPP
