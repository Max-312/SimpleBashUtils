#include "Working_with_files.h"

void printFile(int argc, char* argv[], char* template, flags* options) {
  options->files_count = argc - optind;
  for (; optind < argc; optind++) {
    FILE* file = NULL;
    if ((file = fopen(argv[optind], "r")) != NULL) {
      implementationOfFlags(argv, template, file, options);
      fclose(file);
    } else {
      if (!options->flag_s)
        fprintf(stderr, "s21_grep: No such file or directory\n");
    }
  }
}

void implementationOfFlags(char* argv[], char* template, FILE* file,
                           flags* options) {
  int number_equal_rows = 0;
  implementationOfRegexFlags(argv, &number_equal_rows, options, file, template);

  if (options->flag_c) {
    if (options->files_count > 1 && !options->flag_h)
      printf("%s:", argv[optind]);

    if (options->flag_l && number_equal_rows)
      fprintf(stdout, "1\n");
    else
      fprintf(stdout, "%d\n", number_equal_rows);
  }
  if (options->flag_l && number_equal_rows)
    fprintf(stdout, "%s\n", argv[optind]);
}

void printLine(flags* options, char* argv[], char* line, int number_rows,
               regmatch_t match_array[], regex_t* regex) {
  if (!options->flag_c && !options->flag_l) {
    if (options->files_count > 1 && !options->flag_h)
      fprintf(stdout, "%s:", argv[optind]);

    if (options->flag_n && !options->flag_o)
      fprintf(stdout, "%d:", number_rows);

    if (options->flag_o && !options->flag_v) {
      char* point = line;
      int is_matched = regexec(regex, point, 1, match_array, 0);

      while (!is_matched) {
        if (match_array[0].rm_eo == match_array[0].rm_so) break;
        if (options->flag_n) fprintf(stdout, "%d:", number_rows);
        fprintf(stdout, "%.*s\n",
                (int)(match_array[0].rm_eo - match_array[0].rm_so),
                point + match_array[0].rm_so);
        point += match_array[0].rm_eo;
        is_matched = regexec(regex, point, 1, match_array, REG_NOTBOL);
      }
    }

    if (!options->flag_o) fprintf(stdout, "%s", line);
    if (line[strlen(line) - 1] != '\n') fprintf(stdout, "\n");
  }
}

void implementationOfRegexFlags(char* argv[], int* number_equal_rows,
                                flags* options, FILE* file, char* template) {
  size_t line_buffer_size = 0;
  regex_t regex;
  regmatch_t match_array[1] = {0};
  int flag_ext = REG_EXTENDED | (options->flag_i ? REG_ICASE : 0);
  int number_rows = 1;

  int reg_comp_result = regcomp(&regex, template, flag_ext);
  if (reg_comp_result != 0) {
    regexCompilationError(reg_comp_result, &regex);
    return;
  }

  char* line = NULL;
  while (getline(&line, &line_buffer_size, file) != -1) {
    options->is_matched = regexec(&regex, line, 1, match_array, 0);

    if (options->is_matched != 0 && options->is_matched != REG_NOMATCH) {
      regexExecutionError(options->is_matched, &regex);
      break;
    }

    if (options->flag_v) {
      options->is_matched = !options->is_matched;
    }

    if (options->is_matched != REG_NOMATCH) {
      printLine(options, argv, line, number_rows, match_array, &regex);
      (*number_equal_rows)++;
    }
    number_rows++;
  }

  free(line);
  regfree(&regex);
}