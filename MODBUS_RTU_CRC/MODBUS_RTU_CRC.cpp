// MODBUS_RTU_CRC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "parser.h"


#define MAXSIZE 256 

bool promptExit();

int _tmain(int argc, _TCHAR* argv[])
{
	char *parsedData = NULL;
	char input[MAXSIZE];
	char repeats[10];
	int bytesNumer;
	bool exit = false;

	while (!exit)
	{
		// get input hex string
		printf_s("Podaj sekwencje bajtow w notacji heksadecymalnej:\n");
		fflush(stdin);
		fgets(input, sizeof(input), stdin);
		removeEndLine(input);
		if (!validateHexString(input, strnlen_s(input, MAXSIZE))){
			printf_s("Podany ciag znakow nie jest liczba hex.\n");
			exit = promptExit();
			continue;
		}
		//get input number of elements
		printf_s("Podaj liczbe powtorzen wykonywania algorytmu wyliczania CRC:\n");
		fflush(stdin);
		fgets(repeats, sizeof(repeats), stdin);
		removeEndLine(repeats);
		if (!validateIntString(repeats, strnlen_s(repeats, MAXSIZE))){
			printf_s("Podany ciag znakow nie jest liczba dziesietna.\n");
			exit = promptExit();
			continue;
		}
			
		bytesNumer = convertHexStringToLongData(&parsedData, input, MAXSIZE);
		printf_s("liczba bajtow: %d\n", bytesNumer);
		for (int i = 0; i < bytesNumer; i++)
			printf_s("%02X", parsedData[i] & 0xFF);
		putc('\n', stdout);
		exit = promptExit();
	}
	
	return 0;
}

bool promptExit(){
	char in;
	printf_s("Czy zakonczyc program (T/N)? \n");
	fflush(stdin);
	in = getc(stdin);
	if (in == 'T' || in == 't')
		return true;
	return false;
}

