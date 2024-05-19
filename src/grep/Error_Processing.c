#include "Error_Processing.h"

#include "Flags_selection.h"

void memoryAllocationError() { fprintf(stderr, "Memory Error\n"); }

void OptionsInputError() { fprintf(stderr, "Options Error\n"); }

void printUsageMessage() {
  fprintf(stderr,
          "usage: grep [-abcdDEFGHhIiJLlMmnOopqRSsUVvwXxZz] [-A num] [-B "
          "num] [-C[num]] [-e pattern] "
          "[-f file] [--binary-files=value] [--color=when] [--context[=num]] "
          "[--directories=action] "
          "[--label] [--line-buffered] [--null] [pattern] [file ...]\n");
}

void regexCompilationError(int error, regex_t* regex) {
  char error_message[100];
  regerror(error, regex, error_message, sizeof(error_message));
  fprintf(stderr, "Regex compilation error: %s\n", error_message);
}

void regexExecutionError(int error, regex_t* regex) {
  char error_message[100];
  regerror(error, regex, error_message, sizeof(error_message));
  fprintf(stderr, "Regex execution error: %s\n", error_message);
}