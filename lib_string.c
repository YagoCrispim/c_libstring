#include <stdlib.h>
#include <string.h>

#include "lib_string.h"

int ls_includes(char *string, char *to_find) {
  char *result = strstr(string, to_find);
  if (!result) {
    return 0;
  }
  return 1;
}

char *ls_concat(char *string, char *val_to_concat) {
  long concat_len = strlen(val_to_concat);
  long str_len = strlen(string);
  long new_size = concat_len + str_len; // +1 == null terminator
  char *new_string = malloc(sizeof(char) * new_size);

  for (long i = 0; i < str_len; i++) {
    new_string[i] = string[i];
  }

  long concat_counter = 0;
  for (long i = str_len; i < new_size; i++) {
    new_string[i] = val_to_concat[concat_counter];
    concat_counter++;
  }
  new_string[new_size] = '\0';

  return new_string;
}

char* ls_replace(char *string, char *pattern, char *new_value) {
  char *temp = strstr(string, pattern);

  if (!temp) {
    return string;
  }

  long str_len = strlen(string);
  long pattern_len = strlen(pattern);
  long pattern_position = temp - string;
  long replace_len = strlen(new_value);
  long new_len = str_len + replace_len - pattern_len;
  char *new_string = malloc(sizeof(char) * new_len);

  for (int i = 0; i < pattern_position; i++) {
    new_string[i] = string[i];
  }

  long concat_counter = 0;
  for (long i = pattern_position; i < new_len; i++) {
    new_string[i] = new_value[concat_counter];
    concat_counter++;
  }
  new_string[new_len] = '\0';

  return new_string;
}
