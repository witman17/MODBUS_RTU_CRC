#ifndef PARSER_H
#define PARSER_H

bool validateIntString(char *string, const int stringSize);
bool validateHexString(char *string, const int stringSize);

int convertHexStringToLongData(char *dataOut, char *string, const int stringSize);


#endif