#ifndef WORKING_WITH_FILES_H_
#define WORKING_WITH_FILES_H_

#include <stdio.h>

#include "Flags_selection.h"

void printFile(int argc, char* argv[], char* template, flags* options);
void printLine(flags* options, char* argv[], char* line, int number_rows,
               regmatch_t match_array[], regex_t* regex);

void implementationOfFlags(char* argv[], char* template, FILE* file,
                           flags* options);
void implementationOfRegexFlags(char* argv[], int* number_equal_rows,
                                flags* options, FILE* file, char* template);

#endif