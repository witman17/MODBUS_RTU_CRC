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
		printf_s("Podaj liczbe powtorzen wykonywania algorytmu wyliczania CRC:\n");
		fflush(stdin);
		fgets(repeats, sizeof(repeats), stdin);
		
		if (!validateHexString(input, strnlen_s(input, MAXSIZE))){
			printf_s("Podany ciag znakow nie jest liczba hex.\n");
			exit = promptExit();
			continue;
		}
		if (!validateIntString(repeats, strnlen_s(input, MAXSIZE))){
			printf_s("Podany ciag znakow nie jest liczba dziesietna.\n");
			exit = promptExit();
			continue;
		}
			

		bytesNumer = convertHexStringToLongData(parsedData, input, MAXSIZE);
		printf_s("liczba bajtow: %d", bytesNumer);
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

