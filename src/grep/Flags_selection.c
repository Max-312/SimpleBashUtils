#include "Flags_selection.h"

void initializationOfFlags(flags* options) {
  options->flag_e = 0;
  options->flag_i = 0;
  options->flag_v = 0;
  options->flag_c = 0;
  options->flag_l = 0;
  options->flag_n = 0;
  options->flag_h = 0;
  options->flag_s = 0;
  options->flag_f = 0;
  options->flag_o = 0;
  options->files_count = 0;
  options->is_matched = 0;
}

void appendSeparator(char** template, size_t* template_size) {
  *template = realloc(*template, *template_size + 2);
  strcat(*template, "|");
  *template_size += 2;
}

void appendOption(char** template, size_t* template_size, const char* option) {
  *template = realloc(*template, *template_size + strlen(option) + 1);
  strcat(*template, option);
  *template_size += strlen(option);
}

void flagEWork(int* temp_count, char** template, size_t* template_size,
               const char* optarg) {
  if (*temp_count) {
    appendSeparator(template, template_size);
  }

  appendOption(template, template_size, optarg);
  (*temp_count)++;
}

int flagFWork(int* temp_count, char** template, size_t* template_size) {
  int flag = 1;
  FILE* file = NULL;
  char* str = NULL;
  size_t line_buffer_size = 0;

  if ((file = fopen(optarg, "r"))) {
    while (getline(&str, &line_buffer_size, file) != -1) {
      if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = 0;
      if ((*temp_count) > 0) {
        appendSeparator(template, template_size);
      }

      *template = realloc(*template, *template_size + strlen(str) + 1);
      strcat(*template, str);
      *template_size += strlen(str);
      (*temp_count)++;
    }
    fclose(file);
  }

  else {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", optarg);
    flag = 0;
  }

  if (str != NULL) {
    free(str);
  }

  return flag;
}

void simpleFlagsSelection(char option, char** template, int* flag,
                          flags* options, size_t* template_size,
                          int* temp_count) {
  switch (option) {
    case 'e':
      options->flag_e = 1;
      flagEWork(temp_count, template, template_size, optarg);
      break;
    case 'i':
      options->flag_i = 1;
      break;
    case 'v':
      options->flag_v = 1;
      break;
    case 'c':
      options->flag_c = 1;
      break;
    case 'l':
      options->flag_l = 1;
      break;
    case 'n':
      options->flag_n = 1;
      break;
    case 'h':
      options->flag_h = 1;
      break;
    case 's':
      options->flag_s = 1;
      break;
    case 'f':
      options->flag_f = 1;
      *flag = flagFWork(temp_count, template, template_size);
      break;
    case 'o':
      options->flag_o = 1;
      break;
    case '?':
    default:
      *flag = 0;
  }
}

void flagsParsing(int argc, char* argv[], char** template, int* flag,
                  flags* options, size_t* template_size) {
  int option_index = -1, temp_count = 0;
  char ch = ' ';
  const char* optstring = "e:ivclnhsf:o";

  while ((ch = getopt_long(argc, argv, optstring, NULL, &option_index)) != -1 &&
         *flag) {
    simpleFlagsSelection(ch, template, flag, options, template_size,
                         &temp_count);
  }

  if (!options->flag_e && !options->flag_f) {
    *template = realloc(*template, *template_size + strlen(argv[optind]) + 1);
    strcat(*template, argv[optind]);
    *template_size += strlen(argv[optind++]);
  }

  if (options->flag_o && options->flag_e) options->flag_e = 0;
  if (options->flag_o && options->flag_v) options->flag_o = 0;
}