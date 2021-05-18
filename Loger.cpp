#include "pch.h"
#include "Loger.h"



Loger::Loger()
{
	GetLocalTime(&iTime);
}

Loger::~Loger()
{
	delete[]logPath;
}

bool Loger::OutALog(
	WCHAR* inLog,
	bool lineTime,
	char divider[])
{
	logLine.clear();
	
	if (lineTime)
	{
		GetLocalTime(&iTime);
		SysTimeToString(iTime, logLine);
		logLine += divider;
	}

	int size =
		ui64toi32(wcslen(inLog) * sizeof(inLog[0]) + 1);

	char* outPass = new char[size] { '\0' };

	WideCharToMultiByte(CP_UTF8, 0,//encode type
		inLog,//in str
		ui64toi32(wcslen(inLog)),//in str length
		outPass,//out str
		size,//out str size
		0, 0);//other pramer

	logLine.append(outPass);

	delete[]outPass;

	logLine += "\n";

	fsLog.open(logPath,
		ios::out | ios::app);

	if (!fsLog.is_open())
	{
		return false;
	}
	else
	{
		fsLog << logLine.c_str();
		fsLog.close();
		return true;
	}

}

void Loger::SysTimeToString(
	SYSTEMTIME time,
	string& StdStr,
	char head[],
	char divider[],
	char end[])
{
	StdStr += head;
	StdStr.append(to_string(time.wYear));
	StdStr += divider;
	StdStr.append(to_string(time.wMonth));
	StdStr += divider;
	StdStr.append(to_string(time.wDay));
	StdStr += divider;
	StdStr.append(to_string(time.wHour));
	StdStr += divider;
	StdStr.append(to_string(time.wMinute));
	StdStr += divider;
	StdStr.append(to_string(time.wSecond));
	StdStr += end;

	return;
}

INT32 Loger::ui64toi32(UINT64 var)
{
	INT32 ret;

	if (var <= INT_MAX)
	{
		ret = (INT)var;
	}
	else
	{
		ret = INT_ERROR;
	}

	return ret;

}
