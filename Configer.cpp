#include "pch.h"
#include "Configer.h"



Configer::Configer()
{
	ConfigIsDirt = false;
}

Configer::~Configer()
{
	delete[]configPath;
}

bool Configer::GetConfigFromFile(ConfigInfor& inInfor)
{
	fsConfig.open(configPath,
		ios::in | ios::binary);

	if (!fsConfig.is_open())
	{
		SaveConfigToFile(inInfor);
		return false;
	}
	else
	{
		fsConfig.seekg(0, fsConfig.end);
		UINT64 size = fsConfig.tellg(),
			iSize = sizeof(inInfor);

		if (size != iSize)
		{
			fsConfig.close();
			SaveConfigToFile(inInfor);
			return false;
		}
		else
		{
			fsConfig.seekg(0, fsConfig.beg);//reset position
			fsConfig.read((char*)&inInfor, iSize);
			fsConfig.close();
			return true;
		}
	}
}

bool Configer::SaveConfigToFile(ConfigInfor& inInfor)
{
	if (ConfigIsDirt)
	{
		fsConfig.open(configPath,
			ios::out | ios::binary | ios::trunc);

		if (!fsConfig.is_open())
		{
			return false;
		}
		else
		{
			fsConfig.write(
				(char*)&inInfor,
				sizeof(inInfor));

			fsConfig.close();

			ConfigIsDirt = false;
			return true;
		}
	}
	return true;
}
