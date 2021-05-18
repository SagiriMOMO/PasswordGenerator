#pragma once



static const int CHAR_CB_COUNT = 4;



class ConfigInfor
{
public:
	ConfigInfor();

    /*
	CButton CheckNum;0
	CButton CheckLowCase;1
	CButton CheckUpCase;2
	CButton CheckSymbol;3
	*/

	bool SymbolCheckState[CHAR_CB_COUNT]; 

	bool copy;
	bool log;
	int digit;

};
