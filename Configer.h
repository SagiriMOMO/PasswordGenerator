#pragma once
#include "ConfigInfor.h"



using std::fstream;
using std::ios;
using std::string;



static const int PATH_MAX = 260;



class Configer
{
public:
	Configer();
	~Configer();

	const char* configPath =
		new char[PATH_MAX] { ".\\congfig.bin" };

	fstream fsConfig;

	bool ConfigIsDirt;

	bool GetConfigFromFile(ConfigInfor& inInfor);
	
	bool SaveConfigToFile(ConfigInfor& inInfor);
};