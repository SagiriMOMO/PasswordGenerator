#include "pch.h"
#include "PGenerator.h"



PGenerator::PGenerator()
{
	iConfiger.GetConfigFromFile(iInfor);
}

PGenerator::~PGenerator()
{
	iConfiger.SaveConfigToFile(iInfor);
	delete[]PassWord;
}

void PGenerator::setNumState(bool inState)
{
	iInfor.SymbolCheckState[0] = inState;
	iConfiger.ConfigIsDirt = true;

	return;
}

void PGenerator::setLowCaseState(bool inState)
{
	iInfor.SymbolCheckState[1] = inState;
	iConfiger.ConfigIsDirt = true;

	return;
}

void PGenerator::setUpCaseState(bool inState)
{
	iInfor.SymbolCheckState[2] = inState;
	iConfiger.ConfigIsDirt = true;

	return;
}

void PGenerator::setSymbolState(bool inState)
{
	iInfor.SymbolCheckState[3] = inState;
	iConfiger.ConfigIsDirt = true;

	return;
}

void PGenerator::setCopyState(bool inState)
{
	iInfor.copy = inState;
	iConfiger.ConfigIsDirt = true;

	return;
}

void PGenerator::setLogState(bool inState)
{
	iInfor.log = inState;
	iConfiger.ConfigIsDirt = true;

	return;
}

void PGenerator::setDigit(int inDiget)
{
	iInfor.digit = inDiget;
	iConfiger.ConfigIsDirt = true;

	return;
}

bool PGenerator::IsDirt()
{
	return iConfiger.ConfigIsDirt;
}

void PGenerator::setDirt(bool inDirt)
{
	iConfiger.ConfigIsDirt = inDirt;
}

bool PGenerator::getNumState()
{
	return iInfor.SymbolCheckState[0];
}

bool PGenerator::getLowCaseStata()
{
	return iInfor.SymbolCheckState[1];
}

bool PGenerator::getUpCaseState()
{
	return iInfor.SymbolCheckState[2];
}

bool PGenerator::getSymbolState()
{
	return iInfor.SymbolCheckState[3];
}

bool PGenerator::getCopyState()
{
	return iInfor.copy;
}

bool PGenerator::getLogState()
{
	return iInfor.log;
}

int PGenerator::getDigit()
{
	return iInfor.digit;
}

WCHAR* PGenerator::GenAPass()
{
	if (!iSymbol.RefreshSymbolBuffer(iInfor))
	{
		delete[]PassWord;

		PassWord =
			new WCHAR[]{ L"!!empty!!" };

		return PassWord;
	}

	delete[]PassWord;

	PassWord =
		new WCHAR[(INT64)iInfor.digit + 1]{ '\0' };

	LARGE_INTEGER cpuTime;
	WCHAR charC[2]{ '\0' };

	int local = 0;
	while (local < iInfor.digit)
	{
		QueryPerformanceCounter(&cpuTime);
		srand(cpuTime.LowPart);

		charC[0] = iSymbol.SymbolBuffer[rand() %
			iSymbol.BufferSize];

		if (!FindSameW(PassWord,
			charC[0], local - 1,
			iInfor.digit / 2 < iSymbol.BufferSize / 2 ?
			iInfor.digit / -2 : iSymbol.BufferSize / -2) &&
			charC[0] != NULL &&
			charC[0] != '\0'
			)
		{
			PassWord[local++] = charC[0];
		}
	}

	if (iInfor.copy)
	{
		SendToClipboard(PassWord);
	}

	if (iInfor.log)
	{
		iLoger.OutALog(PassWord);
	}

	return PassWord;
}

bool PGenerator::SendToClipboard(WCHAR* inWSTR)
{
	bool retVar = FALSE;

	if (OpenClipboard(AfxGetMainWnd()->GetSafeHwnd()))
	{
		EmptyClipboard();

		// 分配内存
		HGLOBAL hGlobalData = GlobalAlloc
		(GMEM_MOVEABLE | GMEM_DDESHARE,
			(lstrlenW(inWSTR) + (u_int64)1)
			* sizeof(TCHAR));

		if (hGlobalData != NULL)
		{
			LPTSTR strData =
				(LPTSTR)::GlobalLock(hGlobalData);
			if (strData != 0)
			{
				lstrcpyW(strData, inWSTR);
			}
			GlobalUnlock(hGlobalData);

#ifdef _UNICODE
			retVar = (SetClipboardData(
				CF_UNICODETEXT, hGlobalData) != NULL);
#else
			retVar = (SetClipboardData(
				CF_TEXT, hGlobalData) != NULL);
#endif	//_UNICODE   
		}

		CloseClipboard();
	}

	return retVar;
}

bool PGenerator::FindSameW(
	WCHAR* Target, 
	WCHAR SameAs, 
	int Current, 
	int Range)
{

	if (Current < _msize(Target) / sizeof(Target[0]))
	{
		int i = Current, opera = Range < 0 ? -1 : 1;
		do
		{
			if (Target[i] == SameAs)
			{
				return true;
			}

			i += opera;
		} while (i >= 0 && 
			Range != 0 &&
			i != Current + Range &&
			i < _msize(Target) / sizeof(Target[0]));

	}
	
	return false;
}
