#include "Cat.h"

int main(int argc, char **argv) {
  customCat(argc, argv);

  return 0;
}

int customCat(int argc, char **argv) {
  if (findFlagsError(argc, argv)) {
    return 1;
  }

  flagsParsing(argc, argv);
  fileIteration(argc, argv);

  return 0;
}