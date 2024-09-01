#pragma once
#include <string>



enum commandtype 
{
	commandtyprnone,




	CommandTypeNorth,
	CommandTypeSouth,
	CommandTypeEast,
	CommandTypeWest,


	commandtypequit,
	commandtypeget,
	commandtypeinventory,
	commandtypehelp,
	commandtypeunfo


};
class Consoletextcommand 
{
public:
	commandtype Commandtype;
	std::string parameter;


};


Consoletextcommand()

Consoletextcommand parsecommand();
