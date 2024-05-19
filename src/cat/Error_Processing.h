#ifndef ERROR_PROCESSING_H
#define ERROR_PROCESSING_H

#include <stdio.h>

int stringLen(char *string);
int stringsAreEqual(char *string1, char *string2);

int isSimpleFlag(char symbol);
int isGnuFlag(char *arg);

int foundUnidentifiedFlag(char *arg, char *wrong_flag);
int findFlagsError(int argc, char **argv);

int fileExists(char *filename);

#endif