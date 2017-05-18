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
	char elem[2];
	int  i;
	int  uneven = strnlen_s(string, stringSize) % 2;
	int  bytesNumber = strnlen_s(string, stringSize) / 2 + uneven;
	dataOut[0] = (char *)malloc(sizeof(*dataOut) * bytesNumber);
	if (!*dataOut)
		return 0;
	for (i = 0; i < bytesNumber; i++){
		elem[0] = *string++;
		elem[1] = *string++;		
		//printf_s("%c\n", *dataOut[i]);
		dataOut[0][i] = (char)strtol(elem, NULL, 16);
	}
	if (uneven)
		dataOut[0][--i] <<= 4;
	return bytesNumber;
}


