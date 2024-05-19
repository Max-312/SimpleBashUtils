
#ifndef FLAGS_SELECTION_H_
#define FLAGS_SELECTION_H_

#include <getopt.h>
#include <stdlib.h>
#include <string.h>

#include "Error_Processing.h"

typedef struct {
  int flag_e;
  int flag_i;
  int flag_v;
  int flag_c;
  int flag_l;
  int flag_n;
  int flag_h;
  int flag_s;
  int flag_f;
  int flag_o;
  int files_count;
  int is_matched;
} flags;

extern flags options;

void initializationOfFlags(flags* options);

void simpleFlagsSelection(char option, char** template, int* flag,
                          flags* options, size_t* template_size,
                          int* temp_count);
void flagsParsing(int argc, char* argv[], char** template, int* flag,
                  flags* options, size_t* template_size);

void appendOption(char** template, size_t* template_size, const char* option);
void appendSeparator(char** template, size_t* template_size);

void flagEWork(int* temp_count, char** template, size_t* template_size,
               const char* optarg);
int flagFWork(int* temp_count, char** template, size_t* template_size);

#endif