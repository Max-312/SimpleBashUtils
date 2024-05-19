#ifndef FLAGS_SELECTION_H_
#define FLAGS_SELECTION_H_

#include "Error_Processing.h"

typedef struct {
  int flag_b;
  int flag_e;
  int flag_n;
  int flag_s;
  int flag_t;
  int flag_v;
} flags;

extern flags options;

void initializationOfFlags();
int offFlags();

void simpleFlagsSelection(char *arg);
void simpleFlagsSelection(char *arg);

void flagsParsing(int argc, char **argv);

#endif