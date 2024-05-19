#ifndef ERROR_PROCESSING_H
#define ERROR_PROCESSING_H

#include <regex.h>
#include <stdio.h>

void printUsageMessage();

void memoryAllocationError();
void OptionsInputError();

void regexCompilationError(int error, regex_t* regex);
void regexExecutionError(int error, regex_t* regex);

#endif