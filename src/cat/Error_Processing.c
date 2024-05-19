#include "Error_Processing.h"

int stringLen(char *string) {
  size_t i = 0;

  while (string[i]) i++;

  return i;
}

int stringsAreEqual(char *string1, char *string2) {
  size_t i = 0;

  if (stringLen(string1) != stringLen(string2)) return 0;

  while (string1[i]) {
    if (string1[i] != string2[i]) return 0;

    i++;
  }

  return 1;
}

int isSimpleFlag(char symbol) {
  char *flags = "benstvET";
  size_t i = 0;
  int found = 0;

  while (flags[i]) {
    if (symbol == flags[i]) found = 1;

    i++;
  }

  return found;
}

int isGnuFlag(char *arg) {
  return (stringsAreEqual(arg, "--number-nonblank") ||
          stringsAreEqual(arg, "--number") ||
          stringsAreEqual(arg, "--squeeze-blank"));
}

int foundUnidentifiedFlag(char *arg, char *wrong_flag) {
  int i = 1;
  int found_illegal = 0;

  while (arg[i]) {
    if (!isSimpleFlag(arg[i])) {
      found_illegal = 1;
      *wrong_flag = arg[i];
    }

    i++;
  }

  if (isGnuFlag(arg)) found_illegal = 0;
  return found_illegal;
}

int findFlagsError(int argc, char **argv) {
  int i = 1;
  char wrong_flag;

  while (i < argc && argv[i][0] == '-') {
    // GNU flags
    if (argv[i][1] == '-' && foundUnidentifiedFlag(argv[i], &wrong_flag)) {
      fprintf(stderr, "cat: illegal option -- %s\n", argv[i]);

      return 1;
    }
    // SIMPLE flags
    else if (foundUnidentifiedFlag(argv[i], &wrong_flag)) {
      fprintf(stderr, "cat: illegal option -- %c\n", wrong_flag);
      fprintf(stderr, "usage: cat [-benstuv] [file ...]\n");

      return 1;
    }

    i++;
  }

  return 0;
}

int fileExists(char *filename) {
  FILE *file;

  int is_exists = 0;
  file = fopen(filename, "r");

  if (file) {
    fclose(file);
    is_exists = 1;
  }

  return is_exists;
}