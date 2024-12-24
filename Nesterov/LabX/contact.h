#pragma once
#ifndef CONTACT_H
#define CONTACT_H
#include "my_string.h"

#define NUMBER_OF_CONTACT_FIELD 7
#define BUFFER_SIZE             500

typedef struct Contact {
  String_t surname;
  String_t name;
  String_t midname;
  String_t phone_number;
  String_t email;
  String_t organization;
  String_t position;
} Contact_t;

typedef struct Slice {
  size_t start;
  size_t end;
} Slice_t;

Contact_t create_contact_from_string(char* string);

String_t create_string_from_contact(Contact_t contact);

void print_contact(Contact_t contact);

Contact_t create_empty_contact();

String_t get_fullname(Contact_t contact);

int insert_contact(Contact_t** contacts, size_t* contacts_size,
                   Contact_t new_contact);
Contact_t create_new_contact();

void clear_input_buffer();

void free_contacts(Contact_t* contacts, size_t contacts_size);

Slice_t search_by_fullname(Contact_t* contacts, size_t contacts_size,
                           String_t fullname);

void clear_from_newline_symbol(char* buffer);

size_t search_by_phone_number(Contact_t* contacts, size_t contacts_size,
                              String_t phone_number);

size_t* search_by_initial_letters(Contact_t* contacts, size_t contacts_size,
                                  String_t initial_letters, size_t* result_size);

void free_contact(Contact_t contact);

void contact_copy(Contact_t* dest, const Contact_t* src);

size_t* search_by_initial_digits(const Contact_t* contacts,
                                 const size_t contacts_size, String_t initial_digits,
                                 size_t* result_size);

#endif  // CONTACT_H
