#ifndef GREP_H_
#define GREP_H_

#include "Error_Processing.h"
#include "Flags_selection.h"
#include "Working_with_files.h"

flags options;

int customGrep(int argc, char* argv[], flags* options);

#endif