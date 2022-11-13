//
// Created by Dan Demidov on 13.11.22.
//

#include "SessionVariables.hpp"
#include "../CommandLineInterface.hpp"

void SessionVariablesSet::set(std::string &v_name, std::string &value)
{
    if (!SessionVariablesSet::IsValidName(v_name))
    {
        CLI_OUT(v_name << " is not a valid name for a variable!");
        return;
    }

    variables[v_name] = value;
}

bool SessionVariablesSet::Has(std::string &v_name)
{
    return (bool) variables.count(v_name);
}

std::string SessionVariablesSet::Get(std::string &v_name)
{
    if (!SessionVariablesSet::IsValidName(v_name))
    {
        CLI_OUT(v_name << " is not a valid name for a variable!");
        return "";
    }

    if (this->Has(v_name))
        return variables[v_name];
    else
        return "";
}

bool SessionVariablesSet::IsValidName(std::string &v_name)
{
    return !v_name.empty() /*&& v_name[0] == '$'*/;
}
