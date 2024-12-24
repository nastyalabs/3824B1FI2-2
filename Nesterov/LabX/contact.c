#include "contact.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_string.h"
#include "utility.h"

typedef unsigned int u32_t;


void free_contact(Contact_t contact) {
  free_string(contact.surname);
  free_string(contact.name);
  free_string(contact.midname);
  free_string(contact.phone_number);
  free_string(contact.email);
  free_string(contact.organization);
  free_string(contact.position);
}

void free_contacts(Contact_t* contacts, size_t contacts_size) {
  for (size_t i = 0; i < contacts_size; i++) {
    free_contact(contacts[i]);
  }
  free(contacts);
}

Contact_t create_empty_contact() {
  Contact_t result;
  result.surname      = create_empty_string();
  result.name         = create_empty_string();
  result.midname      = create_empty_string();
  result.phone_number = create_empty_string();
  result.email        = create_empty_string();
  result.organization = create_empty_string();
  result.position     = create_empty_string();
  return result;
}

Contact_t create_contact_from_string(char* str) {
  Contact_t result = create_empty_contact();

  size_t length         = strlen(str);
  str[length++]         = '_';
  str[length]           = '\0';
  size_t current_index  = 1;
  size_t previous_index = 0;

  size_t tokens_size = 0;
  String_t* tokens   = calloc(NUMBER_OF_CONTACT_FIELD, sizeof(String_t));
  for (int i = 0; i < NUMBER_OF_CONTACT_FIELD; i++) {
    tokens[i] = create_empty_string();
  }
  while (current_index < length) {
    if (str[current_index++] == '_') {
      String_t token = create_string_by_capacity(current_index - previous_index);

      if (token.capacity == 0) {
        continue;
      }

      strncpy(token.data, str + previous_index, token.capacity - 1);

      previous_index = current_index;
      if (token.data[0] != ' ') {
        string_copy(&(tokens[tokens_size]), &token);
      }

      tokens_size++;
      free_string(token);
    }
  }

  string_copy(&result.surname, &tokens[0]);
  string_copy(&result.name, &tokens[1]);
  string_copy(&result.phone_number, &tokens[3]);

  if (tokens[2].capacity != 0) {
    string_copy(&result.midname, &tokens[2]);
  }

  if (tokens[4].capacity != 0) {
    string_copy(&result.email, &tokens[4]);
  }
  if (tokens[5].capacity != 0) {
    string_copy(&result.organization, &tokens[5]);
  }

  if (tokens[6].capacity != 0) {
    string_copy(&result.position, &tokens[6]);
  }

  for (int i = 0; i < tokens_size; i++) {
    free_string(tokens[i]);
  }
  free(tokens);

  return result;
}

void print_contact(Contact_t contact) {
  String_t fullname = get_fullname(contact);
  printf("%s +%s", fullname.data, contact.phone_number.data);

  if (contact.email.data != NULL) {
    printf(" %s", contact.email.data);
  }

  if (contact.organization.data != NULL) {
    printf(" %s", contact.organization.data);
  }

  if (contact.position.data != NULL) {
    printf(" %s", contact.position.data);
  }
  printf("\n");

  free_string(fullname);
}

String_t create_string_from_contact(Contact_t contact) {
  size_t capacity = contact.surname.capacity + contact.name.capacity +
                    contact.midname.capacity + contact.phone_number.capacity +
                    contact.email.capacity + contact.organization.capacity +
                    contact.position.capacity + 11;

  String_t result = create_string_by_capacity(capacity);

  strcpy(result.data, contact.surname.data);

  strcat(result.data, "_");
  strcat(result.data, contact.name.data);
  strcat(result.data, "_");
  if (contact.midname.data != NULL) {
    strcat(result.data, contact.midname.data);
    strcat(result.data, "_");
  } else {
    strcat(result.data, " _");
  }
  strcat(result.data, contact.phone_number.data);
  strcat(result.data, "_");
  if (contact.email.data != NULL) {
    strcat(result.data, contact.email.data);
    strcat(result.data, "_");
  } else {
    strcat(result.data, " _");
  }
  if (contact.organization.data != NULL) {
    strcat(result.data, contact.organization.data);
    strcat(result.data, "_");
  } else {
    strcat(result.data, " _");
  }
  if (contact.position.data != NULL) {
    strcat(result.data, contact.position.data);
  } else {
    strcat(result.data, " ");
  }

  return result;
}

String_t get_fullname(Contact_t contact) {
  size_t capacity = contact.surname.capacity + contact.name.capacity +
                    contact.midname.capacity + 2;
  String_t result = create_string_by_capacity(capacity);

  strcpy(result.data, contact.surname.data);
  strcat(result.data, " ");
  strcat(result.data, contact.name.data);
  if (contact.midname.data != NULL) {
    strcat(result.data, " ");
    strcat(result.data, contact.midname.data);
  }

  result.size = strlen(result.data);

  return result;
}

int insert_contact(Contact_t** contacts, size_t* contacts_size,
                   Contact_t new_contact) {
  if (*contacts_size == 0) {
    free(*contacts);
    *contacts = calloc(1, sizeof(Contact_t));
    if (contacts == NULL) {
      return EXIT_FAILURE;
    }
    contact_copy(&(*contacts)[0], &new_contact);
    (*contacts_size)++;
    return EXIT_SUCCESS;
  }
  if (*contacts_size == 1) {
    if (strcmp((*contacts)[0].phone_number.data, new_contact.phone_number.data) ==
        0) {
      printf("Contact with this number already exists\n");
      return 0;
    }
    Contact_t* new_contacts =
        realloc(*contacts, sizeof(Contact_t) * ((*contacts_size) + 1));

    if (new_contacts == NULL) {
      return EXIT_FAILURE;
    }

    String_t arr_contact_fullname = get_fullname(new_contacts[0]);
    String_t new_contact_fullname = get_fullname(new_contact);
    int cmp_result = strcmp(arr_contact_fullname.data, new_contact_fullname.data);

    if (cmp_result < 0) {
      contact_copy(&new_contacts[1], &new_contact);
    } else {
      contact_copy(&new_contacts[1], &new_contacts[0]);
      contact_copy(&new_contacts[0], &new_contact);
    }

    *contacts = new_contacts;

    free_string(arr_contact_fullname);
    free_string(new_contact_fullname);
    (*contacts_size)++;
    return EXIT_SUCCESS;
  }


  size_t left  = 0;
  size_t right = *contacts_size;

  while (left + 1 < right) {
    size_t mid                    = ((right - left) / 2) + left;
    String_t mid_contact_fullname = get_fullname((*contacts)[mid]);
    String_t new_contact_fullname = get_fullname(new_contact);

    int cmp_result = strcmp(mid_contact_fullname.data, new_contact_fullname.data);
    if (cmp_result < 0) {
      left = mid;
    } else if (cmp_result > 0) {
      right = mid;
    } else {
      free_string(mid_contact_fullname);
      free_string(new_contact_fullname);
      left = mid - 1;
      break;
    }

    free_string(mid_contact_fullname);
    free_string(new_contact_fullname);
  }
  if (left + 1 < *contacts_size && strcmp((*contacts)[left + 1].phone_number.data,
                                          new_contact.phone_number.data) == 0) {
    printf("Contact with this number already exists\n");
    return 0;
  }

  Contact_t* new_contacts =
      realloc(*contacts, sizeof(Contact_t) * ((*contacts_size) + 1));

  if (new_contacts == NULL) {
    return EXIT_FAILURE;
  }

  size_t swap_index = *contacts_size;
  while (swap_index > left + 1) {
    contact_copy(&new_contacts[swap_index], &new_contacts[swap_index - 1]);
    swap_index--;
  }

  contact_copy(&new_contacts[left + 1], &new_contact);

  *contacts = new_contacts;
  (*contacts_size)++;

  return EXIT_SUCCESS;
}

Contact_t create_new_contact() {
  Contact_t result = create_empty_contact();

  char* buffer = malloc(sizeof(char) * BUFFER_SIZE);

  clear_input_buffer();
  do {
    printf("Surname: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    if (buffer[0] == '\n') {
      printf("It's mandatory field\n");
    }
  } while (buffer[0] == '\n');
  clear_from_newline_symbol(buffer);
  result.surname = create_string_from_ptr(buffer, strlen(buffer));
  do {
    printf("Name: ");
    /*clear_input_buffer();*/
    fgets(buffer, BUFFER_SIZE, stdin);
    if (buffer[0] == '\n') {
      printf("It's mandatory field\n");
    }
  } while (buffer[0] == '\n');
  clear_from_newline_symbol(buffer);
  result.name = create_string_from_ptr(buffer, strlen(buffer));
  printf("Middle name[enter to skip]: ");
  /*clear_input_buffer();*/
  fgets(buffer, BUFFER_SIZE, stdin);
  if (buffer[0] != '\n') {
    clear_from_newline_symbol(buffer);
    result.midname = create_string_from_ptr(buffer, strlen(buffer));
  } else {
    result.midname = create_empty_string();
  }
  do {
    printf("Phone number: ");
    /*clear_input_buffer();*/
    fgets(buffer, BUFFER_SIZE, stdin);
    if (buffer[0] == '\n') {
      printf("It's mandatory field\n");
    }
  } while (buffer[0] == '\n');
  clear_from_newline_symbol(buffer);
  result.phone_number = create_string_from_ptr(buffer, strlen(buffer));
  printf("Email[enter to skip]: ");
  /*clear_input_buffer();*/
  fgets(buffer, BUFFER_SIZE, stdin);
  if (buffer[0] != '\n') {
    clear_from_newline_symbol(buffer);
    result.email = create_string_from_ptr(buffer, strlen(buffer));
  } else {
    result.email = create_empty_string();
  }
  printf("Organization[enter to skip]: ");
  /*clear_input_buffer();*/
  fgets(buffer, BUFFER_SIZE, stdin);
  if (buffer[0] != '\n') {
    clear_from_newline_symbol(buffer);
    result.organization = create_string_from_ptr(buffer, strlen(buffer));
  } else {
    result.organization = create_empty_string();
  }
  printf("Position[enter to skip]: ");
  /*clear_input_buffer();*/
  fgets(buffer, BUFFER_SIZE, stdin);
  if (buffer[0] != '\n') {
    clear_from_newline_symbol(buffer);
    result.position = create_string_from_ptr(buffer, strlen(buffer));
  } else {
    result.position = create_empty_string();
  }

  free(buffer);

  return result;
}

Slice_t search_by_fullname(Contact_t* contacts, size_t contacts_size,
                           String_t fullname) {
  size_t left  = 0;
  size_t right = contacts_size;

  while (left + 1 < right) {
    size_t mid                = ((right - left) / 2) + left;
    String_t contact_fullname = get_fullname(contacts[mid]);
    int cmp_result            = strcmp(contact_fullname.data, fullname.data);
    if (cmp_result < 0) {
      left = mid;
    } else if (cmp_result > 0) {
      right = mid;
    } else {
      left = mid;
      free_string(contact_fullname);
      break;
    }
    free_string(contact_fullname);
  }
  Slice_t result = {left, ULONG_MAX};

  for (size_t i = left; i < contacts_size; i++) {
    String_t contact_fullname = get_fullname(contacts[i]);
    if (strcmp(contact_fullname.data, fullname.data) == 0) {
      result.end = i;
    } else {
      free_string(contact_fullname);
      break;
    }
    free_string(contact_fullname);
  }

  return result;
}

size_t search_by_phone_number(Contact_t* contacts, size_t contacts_size,
                              String_t phone_number) {
  size_t result = ULONG_MAX;
  for (int i = 0; i < contacts_size; i++) {
    if (strcmp(contacts[i].phone_number.data, phone_number.data) == 0) {
      result = i;
      break;
    }
  }

  return result;
}

size_t* search_by_initial_letters(Contact_t* contacts, size_t contacts_size,
                                  String_t initial_letters, size_t* result_size) {
  size_t* result = malloc(sizeof(size_t) * contacts_size);
  size_t last    = 0;

  char* slice = malloc(sizeof(char) * initial_letters.capacity);
  for (size_t i = 0; i < contacts_size; i++) {
    String_t fullname = get_fullname(contacts[i]);
    strncpy(slice, fullname.data, initial_letters.capacity - 1);
    slice[initial_letters.capacity - 1] = '\0';

    int cmp_result = strcmp(initial_letters.data, slice);
    if (cmp_result == 0) {
      result[last++] = i;
    }
    free_string(fullname);
  }

  *result_size = last;

  free(slice);
  return result;
}

void contact_copy(Contact_t* dest, const Contact_t* src) {
  string_copy(&(dest->surname), &(src->surname));
  string_copy(&(dest->name), &(src->name));
  string_copy(&(dest->midname), &(src->midname));
  string_copy(&(dest->phone_number), &(src->phone_number));
  string_copy(&(dest->email), &(src->email));
  string_copy(&(dest->organization), &(src->organization));
  string_copy(&(dest->position), &(src->position));
}

size_t* search_by_initial_digits(const Contact_t* contacts,
                                 const size_t contacts_size, String_t initial_digits,
                                 size_t* result_size) {
  size_t* result = malloc(sizeof(size_t) * contacts_size);
  size_t last    = 0;

  char* slice = malloc(sizeof(char) * initial_digits.capacity);
  for (size_t i = 0; i < contacts_size; i++) {
    strncpy(slice, contacts[i].phone_number.data, initial_digits.capacity - 1);
    slice[initial_digits.capacity - 1] = '\0';

    int cmp_result = strcmp(initial_digits.data, slice);
    if (cmp_result == 0) {
      result[last++] = i;
    }
  }

  *result_size = last;

  free(slice);

  return result;
}
