#include "Working_with_files.h"

void printTabWithNumber(int number) { printf("%6d\t", number); }

int isTab(char symbol) { return (symbol == '\t'); }

int isNewLine(char symbol) { return (symbol == '\n'); }

int isEmptyLine(FILE *file) {
  int empty = 0;
  char d = getc(file);

  if (isNewLine(d)) {
    empty = 1;
  }

  ungetc(d, file);

  return empty;
}

void printInvisibleChar(unsigned char symbol) {
  if (options.flag_v) {
    if (isTab(symbol) && !options.flag_t) {
      printf("%c", symbol);
    }

    else if (symbol < 32) {
      symbol += 64;
      printf("^%c", symbol);
    }

    else if (symbol == 127) {
      printf("^?");
    }

    else if (symbol > 127 && symbol < 160) {
      symbol -= 64;
      printf("M-^%c", symbol);
    }

    else if (symbol >= 160 && symbol <= 192) {
      symbol -= 128;
      printf("M-%c", symbol);
    }

    else {
      printf("%c", symbol);
    }
  }

  else {
    printf("%c", symbol);
  }
}

void printLine(int *i, int *first_symbol, unsigned char symbol) {
  if (offFlags()) {
    printf("%c", symbol);
  } else {
    if (*first_symbol) {
      *first_symbol = 0;
      if (options.flag_b || options.flag_n) {
        printTabWithNumber(*i);
        (*i)++;
      }

      if (isTab(symbol) && options.flag_t) {
        printf("^I");
      } else {
        printInvisibleChar(symbol);
      }

    } else {
      if (isTab(symbol) && options.flag_t) {
        printf("^I");
      } else {
        printInvisibleChar(symbol);
      }
    }
  }
}

void printEndOfLine(int *i, int *first_symbol, unsigned char symbol,
                    FILE *file) {
  unsigned char d;

  if (*first_symbol && options.flag_s) {
    while (isEmptyLine(file)) symbol = fgetc(file);
  }

  if (*first_symbol && options.flag_b) {
    d = getc(file);
    if (!isNewLine(d)) {
    }

    ungetc(d, file);

  } else if (*first_symbol && options.flag_n) {
    printTabWithNumber(*i);
    (*i)++;
  }

  if (options.flag_e) {
    if (*first_symbol && options.flag_b) {
      printf("%6s\t$", "");
    } else {
      printf("$");
    }
  }

  printf("%c", symbol);
}

void printFile(char *filename) {
  FILE *file;
  int i = 1;

  int first_symbol;

  file = fopen(filename, "r");
  char symbol = fgetc(file);

  while (symbol != EOF) {
    first_symbol = 1;
    while (symbol != EOF && !isNewLine(symbol)) {
      printLine(&i, &first_symbol, symbol);
      symbol = fgetc(file);
    }

    if (symbol != EOF) {
      printEndOfLine(&i, &first_symbol, symbol, file);
      symbol = fgetc(file);
    }
  }

  fclose(file);
}

void fileIteration(int argc, char **argv) {
  int i = 1;

  while (i < argc && argv[i][0] == '-') {
    i++;
  }

  while (i < argc) {
    if (!fileExists(argv[i])) {
      fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
    } else {
      printFile(argv[i]);
    }

    i++;
  }
}
