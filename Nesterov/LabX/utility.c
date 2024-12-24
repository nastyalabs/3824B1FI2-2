#include "utility.h"

#include <stdio.h>
#include <string.h>

void clear_input_buffer() {
  int buffer = 0;
  while ((buffer = getchar()) != '\n' && buffer != EOF) {}
}

void clear_from_newline_symbol(char* buffer) {
  size_t size      = strlen(buffer);
  buffer[size - 1] = '\0';
}
