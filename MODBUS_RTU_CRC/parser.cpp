#include "stdafx.h"
#include "parser.h"
#include "ctype.h"

//removes last endLine
void removeEndLine(char * string){
	char *p = strrchr(string, '\n');
	if (p != NULL) *p = '\0';
	return;
}

bool validateIntString(char *string, const int stringSize){
	int x = strspn(string, "0123456789");
	if (strspn(string, "0123456789") < stringSize)
		return false;

	return true;
}

bool validateHexString(char *string, const int stringSize){
	int x = strspn(string, "0123456789abcdefABCDEF");
	if (strspn(string, "0123456789abcdefABCDEF") < stringSize)
		return false;

	return true;
}

    // Adds additional 0 hex to the end when string characters are uneven
int convertHexStringToLongData(char **dataOut, char * string, const int stringSize){
	int bytesNumber = strnlen_s(string, stringSize) / 2 + strnlen_s(string, stringSize) % 2;
	dataOut[0] = (char *)malloc(sizeof(*dataOut) * bytesNumber);
	if (!*dataOut)
		return 0;
	for (int i = 0; i < bytesNumber; i++){
		char elem[2];
		elem[0] = *string++;
		elem[1] = *string++;		
		//printf_s("%c\n", *dataOut[i]);
		dataOut[0][i] = (char)strtol(elem, NULL, 16);
		if ((i == bytesNumber - 1) && !elem[1])
			dataOut[0][i] <<= 4;
	}
	return bytesNumber;
}


