#pragma once
#ifndef STRING_H
#define STRING_H
#include <stddef.h>
#include <stdlib.h>

typedef struct String {
  char* data;
  size_t capacity;
  size_t size;
} String_t;

String_t create_string_from_ptr(char* string, size_t length);

String_t create_empty_string();

void free_string(String_t str);

String_t create_string_by_capacity(size_t capacity);

int string_copy(String_t* dest, const String_t* src);


#endif  // STRING_H
