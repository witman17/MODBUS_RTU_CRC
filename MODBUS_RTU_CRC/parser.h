#ifndef PARSER_H
#define PARSER_H

void removeEndLine(char * string);
bool validateIntString(char *string, const int stringSize);
bool validateHexString(char *string, const int stringSize);

int convertHexStringToLongData(char **dataOut, char *string, const int stringSize);


#endif