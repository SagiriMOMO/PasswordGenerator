#include "pch.h"
#include "ConfigInfor.h"



ConfigInfor::ConfigInfor()
{
	SymbolCheckState[0] = true;
	SymbolCheckState[1] = false;
	SymbolCheckState[2] = true;
	SymbolCheckState[3] = false;

	copy = true;
	log = true;
	digit = 8;
}
