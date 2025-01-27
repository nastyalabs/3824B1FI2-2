#include "my_string.h"

#include <stdlib.h>
#include <string.h>

String_t create_string_from_ptr(char* string, size_t length) {
  String_t result = create_empty_string();

  result.capacity = length + 1;
  result.size     = length;
  result.data     = malloc(sizeof(char) * result.capacity);

  strcpy(result.data, string);

  return result;
}

String_t create_empty_string() { return (String_t){NULL, 0, 0}; }

void free_string(String_t str) {
  if (str.data != NULL || str.capacity != 0) {
    free(str.data);
  }
}

String_t create_string_by_capacity(size_t capacity) {
  String_t result = create_empty_string();
  if (capacity == 0) {
    return result;
  }

  result.data     = calloc(capacity, sizeof(char));
  result.capacity = capacity;
  result.size     = 0;

  return result;
}

int string_copy(String_t* dest, const String_t* src) {
  if (src->data == NULL || src->capacity == 0) {
    dest->data     = NULL;
    dest->capacity = 0;
    dest->size     = 0;
    return 0;
  }

  if (dest->capacity != 0) {
    if (dest->data != NULL) {
      free(dest->data);
    }
  }

  dest->capacity = src->capacity;
  dest->size     = src->size;


  dest->data = calloc(src->capacity, sizeof(char));
  if (dest->data == NULL) {
    return 1;
  }

  strcpy(dest->data, src->data);

  return 0;
}
