#pragma once



using std::string;
using std::fstream;
using std::ios;
using std::to_string;



class Loger
{
public:
	Loger();
	~Loger();

	const char* logPath = 
		new char[MAX_PATH] { ".\\log.txt" };

	fstream fsLog;

	SYSTEMTIME iTime;

	string logLine;

	bool OutALog(
		WCHAR* inLog,
		bool lineTime = true,
		char divider[] = "\t\t");

	void SysTimeToString(
		SYSTEMTIME time,
		string& StdStr,
		char head[] = "[",
		char divider[] = "-",
		char end[] = "]");

	INT32 ui64toi32(UINT64 var);

};

