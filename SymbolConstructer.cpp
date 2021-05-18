#include "pch.h"
#include "SymbolConstructer.h"



SymbolConstructer::SymbolConstructer()
{
	SymbolBuffer = new WCHAR[2]{ '\0' };
	BufferSize = 0;
}

SymbolConstructer::~SymbolConstructer()
{
	delete[]SymbolCount;
	delete[]SymbolSpawn;

	for (int i = 0; i < SYMBOL_ARRAY_COUNT; i++)
	{
		delete[]SymbolArray[i];
	}delete[]SymbolArray;

	delete[]SymbolBuffer;
}

bool SymbolConstructer::RefreshBufferSize(
	ConfigInfor& inInfor)
{
	int size = 0;

	for (int i = 0; i < SYMBOL_ARRAY_COUNT; i++)
	{
		if (inInfor.SymbolCheckState[i])
		{
			size += SymbolCount[i];
		}
	}

	BufferSize = size + 1;

	if (size != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SymbolConstructer::RefreshSymbolBuffer(
	ConfigInfor& inInfor)
{
	if (RefreshBufferSize(inInfor))
	{
		delete[]SymbolBuffer;
		SymbolBuffer =
			new WCHAR[BufferSize]{ '\0' };

		int local = 0;

		for (int i = 0; i < SYMBOL_ARRAY_COUNT; i++)
		{
			if (inInfor.SymbolCheckState[i])
			{
				for (int j = 0;
					j < SymbolCount[i] &&
					local < BufferSize;
					j++)
				{
					SymbolBuffer[local++] =
						SymbolArray[i][j];
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
