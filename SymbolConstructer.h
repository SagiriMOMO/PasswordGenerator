#pragma once
#include "ConfigInfor.h"



static const int SYMBOL_ARRAY_COUNT = 4;



class SymbolConstructer
{
public:
	SymbolConstructer();
	~SymbolConstructer();

	const int* SymbolCount =
		new int[SYMBOL_ARRAY_COUNT] {10, 26, 26, 32};

	const int* SymbolSpawn =
		new int[SYMBOL_ARRAY_COUNT] {11, 27, 27, 33};

	WCHAR** SymbolArray =
		new WCHAR * [SYMBOL_ARRAY_COUNT]
	{
		new WCHAR[SymbolSpawn[0]]
		{

			'0',	'1',	'2',	'3',	'4',
			'5',	'6',	'7',	'8',	'9',

		},
		new WCHAR[SymbolSpawn[1]]
		{

			'a',	'b',	'c',	'd',	'e',
			'f',	'g',	'h',	'i',	'j',
			'k',	'l',	'm',	'n',	'o',
			'p',	'q',	'r',	's',	't',
			'u',	'v',	'w',	'x',	'y',
			'z',

		},
		new WCHAR[SymbolSpawn[2]]
		{

			'A',	'B',	'C',	'D',	'E',
			'F',	'G',	'H',	'I',	'J',
			'K',	'L',	'M',	'N',	'O',
			'P',	'Q',	'R',	'S',	'T',
			'U',	'V',	'W',	'X',	'Y',
			'Z',

		},
		new WCHAR[SymbolSpawn[3]]
		{

			'!',	'@',	'#',	'$',	'%',
			'^',	'&',	'*',	'(',	')',
			'_',	'+',	'{',	'}',	'|',
			':',	'\"',	'<',	'>',	'?',
			'-',	'=',	'[',	']',	'\\',
			';',	'\'',	',',	'.',	'/',
			'`',	'~',

		}
	};

	WCHAR* SymbolBuffer;

	int BufferSize;

	bool RefreshBufferSize(ConfigInfor& inInfor);

	bool RefreshSymbolBuffer(ConfigInfor& inInfor);

};