// MODBUS_RTU_CRC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "parser.h"
#include "crc.h"


#define MAXSIZE 256 

bool promptExit();

int _tmain(int argc, _TCHAR* argv[])
{
	char *parsedData = NULL;
	char input[MAXSIZE];
	char repeatInput[10];
	int  bytesNumer;
	unsigned long repeat;
	short crc;
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
		fgets(repeatInput, sizeof(repeatInput), stdin);
		removeEndLine(repeatInput);
		if (!validateIntString(repeatInput, strnlen_s(repeatInput, MAXSIZE))){
			printf_s("Podany ciag znakow nie jest liczba dziesietna.\n");
			exit = promptExit();
			continue;
		}
			
		bytesNumer = convertHexStringToLongData(&parsedData, input, MAXSIZE);
		repeat = strtoul(repeatInput, NULL, 10);
		printf_s("liczba bajtow: %d\n", bytesNumer);
		for (int i = 0; i < bytesNumer; i++)
			printf_s("%02X", parsedData[i] & 0xFF);
		putc('\n', stdout);
		crc = generateCRC(parsedData, bytesNumer);
		printf_s("CRC: %X\n", crc & 0xFFFF);
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

