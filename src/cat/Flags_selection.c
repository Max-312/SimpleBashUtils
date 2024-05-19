#include "Flags_selection.h"

void initializationOfFlags() {
  options.flag_b = 0;
  options.flag_e = 0;
  options.flag_n = 0;
  options.flag_s = 0;
  options.flag_t = 0;
  options.flag_v = 0;
}

int offFlags() {
  return (options.flag_b == 0 && options.flag_e == 0 && options.flag_n == 0 &&
          options.flag_s == 0 && options.flag_t == 0 && options.flag_v == 0);
}

void simpleFlagsSelection(char *arg) {
  size_t i = 1;

  while (arg[i]) {
    switch (arg[i]) {
      case 'b':
        options.flag_b = 1;
        break;
      case 'e':
        options.flag_e = 1;
        options.flag_v = 1;
        break;
      case 'n':
        options.flag_n = 1;
        break;
      case 's':
        options.flag_s = 1;
        break;
      case 't':
        options.flag_t = 1;
        options.flag_v = 1;
        break;
      case 'v':
        options.flag_v = 1;
        break;
      case 'E':
        options.flag_e = 1;
        break;
      case 'T':
        options.flag_t = 1;
        break;
    }

    i++;
  }
}

void gnuFlagsSelection(char *arg) {
  if (stringsAreEqual(arg, "--number")) {
    options.flag_n = 1;
  }

  if (stringsAreEqual(arg, "--squeeze-blank")) {
    options.flag_s = 1;
  }

  if (stringsAreEqual(arg, "--number-nonblank")) {
    options.flag_b = 1;
  }
}

void flagsParsing(int argc, char **argv) {
  int i = 1;

  initializationOfFlags();

  while (i < argc && argv[i][0] == '-') {
    if (isGnuFlag(argv[i])) {
      gnuFlagsSelection(argv[i]);
    } else {
      simpleFlagsSelection(argv[i]);
    }

    i++;
  }
}