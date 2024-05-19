#include "Grep.h"

int customGrep(int argc, char* argv[], flags* options) {
  int error = 0;

  if (argc <= 1) {
    printUsageMessage();
    error = 1;
    return error;
  }

  size_t template_size = 2;
  char* template = (char*)malloc(sizeof(char) * template_size);
  if (template == NULL) {
    memoryAllocationError();
    error = 1;
    return error;
  }
  *template = '\0';

  int flag = 1;
  flagsParsing(argc, argv, &template, &flag, options, &template_size);
  if (!flag) {
    OptionsInputError();
    error = 1;
    free(template);
    return error;
  }

  printFile(argc, argv, template, options);
  free(template);

  return error;
}

int main(int argc, char* argv[]) {
  initializationOfFlags(&options);
  int status = customGrep(argc, argv, &options);
  return status;
}