#ifndef WORKING_WITH_FILES_H_
#define WORKING_WITH_FILES_H_

#include <stdio.h>

#include "Flags_selection.h"

int isTab(char symbol);
void printTabWithNumber(int number);

int isNewLine(char symbol);
int isEmptyLine(FILE *file);
void printLine(int *i, int *first_symbol, unsigned char symbol);
void printEndOfLine(int *i, int *first_symbol, unsigned char symbol,
                    FILE *file);

void fileIteration(int argc, char **argv);
void printFile(char *filename);
void printInvisibleChar(unsigned char symbol);

#endif