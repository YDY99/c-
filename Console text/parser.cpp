#include "pser.h"
#include <vector>
#include <iostream>



Consoletextcommand Parsecommand()
{

    Consoletextcommand command = ();
    command, commandtype = commandtypenone;

    const unsigned int INPUTVHARLIMIT = 256;
    char inputstr[INPUTVHARLIMIT];

    char* inputvalue = fgets(inputstr, INPUTVHARLIMIT, stdin);
    char* token = strtok_s(inputstr, "¡¬t¡¬n", &nexttoken);
    std::vector<std::string> tokens;
    char* nextToken = nullptr;
    
    
    
    
    
    
    
    while (token) 
    {
        tokens.push_back(token);
        token = strtok_s(nullptr, " \t\n", &nextToken);








    }

    if (tokens.size()  >= 1)
    {
        std::string parsedata = tokens[0];

        for (unsigned int i = 0; i < parsedata.size(); i++) 
        {
            parsedata[i] = tolower(parsedata[i]); 
            {







            }

            if (parseData == "w" || parseData == "north" || parseData == "up")
            {
                command.commandType = CommandTypeNorth;
            }
            else if (parseData == "s" || parseData == "south" || parseData == "down")
            {
                command.commandType = CommandTypeSouth;
            }
            else if (parseData == "a" || parseData == "west" || parseData == "left")
            {
                command.commandType = CommandTypeWest;
            }
            else if (parseData == "d" || parseData == "east" || parseData == "right")
            {
                command.commandType = CommandTypeEast;
            }












        }
    
    
    
    
    
    
    }





    return Consoletextcommand();
}
