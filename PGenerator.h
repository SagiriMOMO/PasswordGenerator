#pragma once



#include "ConfigInfor.h"
#include "Configer.h"
#include "SymbolConstructer.h"
#include "Loger.h"



class PGenerator
{
private:
    ConfigInfor iInfor;
    Configer iConfiger;
    SymbolConstructer iSymbol;
    Loger iLoger;

    /*
    CButton CheckNum;0
    CButton CheckLowCase;1
    CButton CheckUpCase;2
    CButton CheckSymbol;3
    */

    WCHAR* PassWord = new WCHAR[2]{ '\0' };

public://construct
    PGenerator();
    ~PGenerator();

#pragma region for config infor
    
public:

    bool getNumState();
    bool getLowCaseStata();
    bool getUpCaseState();
    bool getSymbolState();
    bool getCopyState();
    bool getLogState();
    int getDigit();

    void setNumState(bool inState);
    void setLowCaseState(bool inState);
    void setUpCaseState(bool inState);
    void setSymbolState(bool inState);
    void setCopyState(bool inState);
    void setLogState(bool inState);
    void setDigit(int inDiget);

    bool IsDirt();
    void setDirt(bool inDirt);
#pragma endregion

#pragma region main function

public:

    WCHAR* GenAPass();

#pragma endregion

#pragma region private other

private:

    bool SendToClipboard(WCHAR* inWSTR);

    bool FindSameW(
        WCHAR* Target,
        WCHAR SameAs,
        int Current,
        int Range);

#pragma endregion

};