#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib_string.h"

void test_concat() {
  printf("concat: \t");

  char *string = strdup("ola ");
  char *new_value = ls_concat(string, "mundo");

  int result = strcmp(new_value, "ola mundo");

  if (result == 0) {
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  free(string);
  free(new_value);
}

void test_replace() {
  printf("replace: \t");

  char *string = strdup("any w");
  char *new_value = ls_replace(string, "w", "lorem ipsum dolor");

  int result = strcmp(new_value, "any lorem ipsum dolor");

  if (result == 0) {
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  free(string);
  free(new_value);
}

void test_includes() {
  printf("includes: \t");

  char *string = strdup("any value");
  int result = ls_includes(string, "value");

  if (result == 1) {
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }

  free(string);
}

int main() {
  printf("-------- Tests --------\n");
  test_concat();
  test_replace();
  test_includes();
  return 0;
}
