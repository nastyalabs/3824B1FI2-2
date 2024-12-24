#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"
#include "my_string.h"
#include "utility.h"

#define MAXIMUM_MODES    9
#define EXIT             0
#define DISPLAY_CONTACTS 1
#define VIEW_CONTACT     2
#define NEW_CONTACT      3
#define FULL_NAME        4
#define PHONE_NUMBER     5
#define INITIAL_LETTERS  6
#define INITIAL_DIGITS   7
#define EDITING_CONTACT  8
#define DELETING_CONTACT 9


typedef unsigned int u32_t;
typedef unsigned char u8_t;

size_t count_lines(FILE* file) {
  size_t lines_counter = 0;
  char* buffer         = malloc(sizeof(char) * BUFFER_SIZE);

  while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
    lines_counter++;
  }

  free(buffer);

  fseek(file, 0, SEEK_SET);
  return lines_counter;
}

Contact_t* load_contacts_from_file(size_t* size) {
  FILE* input_file = fopen("contacts.txt", "r");
  if (input_file == NULL) {
    fprintf(stderr, "Can't open contacts.txt");
    fclose(input_file);
    return NULL;
  }

  size_t contacts_size = count_lines(input_file);
  Contact_t* contacts  = calloc(contacts_size, sizeof(Contact_t));
  char* buffer         = malloc(sizeof(char) * BUFFER_SIZE);
  for (int i = 0; i < contacts_size; i++) {
    fgets(buffer, BUFFER_SIZE, input_file);
    clear_from_newline_symbol(buffer);
    contacts[i] = create_contact_from_string(buffer);
  }
  free(buffer);
  fclose(input_file);

  *size = contacts_size;
  return contacts;
}

int dump_contacts_to_file(Contact_t* contacts, size_t contacts_size) {
  FILE* output_file = fopen("contacts.txt", "w");
  if (output_file == NULL) {
    fprintf(stderr, "Can't open contacts.txt");

    free_contacts(contacts, contacts_size);
    fclose(output_file);
    return EXIT_FAILURE;
  }

  for (int i = 0; i < contacts_size; i++) {
    String_t line = create_string_from_contact(contacts[i]);
    fprintf(output_file, "%s\n", line.data);
    free_string(line);
  }


  free_contacts(contacts, contacts_size);

  fclose(output_file);

  return EXIT_SUCCESS;
}

void display_contacts(Contact_t* contacts, size_t contacts_size) {
  for (size_t i = 0; i < contacts_size; i++) {
    printf("%zu) ", i + 1);
    String_t fullname = get_fullname(contacts[i]);
    printf("%s +%s\n", fullname.data, contacts[i].phone_number.data);
    free_string(fullname);
  }
}

int add_new_contact(Contact_t** contacts, size_t* contacts_size) {
  Contact_t new_contact = create_new_contact();
  int result            = insert_contact(contacts, contacts_size, new_contact);
  free_contact(new_contact);
  if (result == EXIT_FAILURE) {
    fprintf(stderr, "Not enough memory to work\n");
    free_contacts(*contacts, *contacts_size);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

size_t get_id(size_t contacts_size) {
  size_t contact_id = 0;
  do {
    printf("Input contact id: ");
    scanf("%zd", &contact_id);

    if (contact_id - 1 >= contacts_size) {
      fprintf(stderr, "Invalid id\n");
    }
  } while (contact_id - 1 >= contacts_size);
  return contact_id - 1;
}


int delete_contact(Contact_t** contacts, size_t* contacts_size,
                   const size_t contact_id) {
  Contact_t* new_contacts = calloc((*contacts_size) - 1, sizeof(Contact_t));

  if (new_contacts == NULL) {
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < contact_id; i++) {
    contact_copy(&new_contacts[i], &(*contacts)[i]);
  }
  for (size_t i = contact_id + 1; i < *contacts_size; i++) {
    contact_copy(&new_contacts[i - 1], &(*contacts)[i]);
  }

  free_contacts(*contacts, *contacts_size);

  (*contacts_size)--;
  *contacts = new_contacts;

  return EXIT_SUCCESS;
}

void edit_contact(Contact_t** contacts, size_t* contacts_size,
                  const size_t contact_id) {
  print_contact((*contacts)[contact_id]);

  delete_contact(contacts, contacts_size, contact_id);
  Contact_t edited_contact = create_new_contact();
  insert_contact(contacts, contacts_size, edited_contact);

  free_contact(edited_contact);
}

int main() {
  size_t contacts_size = 0;
  Contact_t* contacts  = load_contacts_from_file(&contacts_size);

  if (contacts == NULL) {
    return EXIT_FAILURE;
  }

  while (true) {
    printf("Choose mode:\n"
           "0) Exit\n"
           "1) Display contacts\n"
           "2) Viewing the selected contact\n"
           "3) Adding a new contact\n"
           "4) Search for a contact by full name\n"
           "5) Search for a contact by phone number\n"
           "6) Selection of contacts by initial letters of surname\n"
           "7) Selecting contacts based on the initial digits of the phone number\n"
           "8) Editing a contact\n"
           "9) Deleting a contact\n");

    u8_t mode = UCHAR_MAX;

    do {
      scanf("%hhd", &mode);
      if (mode > MAXIMUM_MODES) {
        printf("Choose correct option, please\n");
      }
    } while (mode > MAXIMUM_MODES);

    if (mode == EXIT) {
      break;
    }

    if (mode == DISPLAY_CONTACTS) {
      display_contacts(contacts, contacts_size);
      continue;
    }


    if (mode == VIEW_CONTACT) {
      size_t contact_id = 0;
      printf("Input contact id: ");
      scanf("%zd", &contact_id);

      if (contact_id - 1 >= contacts_size) {
        fprintf(stderr, "Invalid id\n");
      } else {
        print_contact(contacts[contact_id - 1]);
      }

      continue;
    }

    if (mode == NEW_CONTACT) {
      int result = add_new_contact(&contacts, &contacts_size);
      if (result == EXIT_FAILURE) {
        return EXIT_FAILURE;
      }
      continue;
    }
    if (mode == FULL_NAME) {
      printf("Fullname: ");
      clear_input_buffer();
      char* querry = malloc(sizeof(char) * BUFFER_SIZE);

      fgets(querry, BUFFER_SIZE, stdin);

      clear_from_newline_symbol(querry);
      String_t fullname = create_string_from_ptr(querry, strlen(querry));

      Slice_t result = search_by_fullname(contacts, contacts_size, fullname);

      free_string(fullname);

      if (result.end == ULONG_MAX) {
        printf("Not found\n");
        free(querry);
        continue;
      }
      for (size_t i = result.start; i <= result.end; i++) {
        printf("%zu) ", i + 1);
        String_t fullname = get_fullname(contacts[i]);
        printf("%s\n", fullname.data);
        free_string(fullname);
      }

      free(querry);
      continue;
    }
    if (mode == PHONE_NUMBER) {
      printf("Phone number: ");
      clear_input_buffer();
      char* querry = malloc(sizeof(char) * BUFFER_SIZE);

      fgets(querry, BUFFER_SIZE, stdin);
      clear_from_newline_symbol(querry);
      String_t phone_number = create_string_from_ptr(querry, strlen(querry));

      size_t result = search_by_phone_number(contacts, contacts_size, phone_number);

      free_string(phone_number);

      if (result == ULONG_MAX) {
        printf("Not found\n");
        free(querry);
        continue;
      }

      printf("%zu) ", result + 1);
      print_contact(contacts[result]);


      free(querry);
      continue;
    }
    if (mode == INITIAL_LETTERS) {
      printf("Fullname letters: ");
      clear_input_buffer();
      char* querry = malloc(sizeof(char) * BUFFER_SIZE);

      fgets(querry, BUFFER_SIZE, stdin);
      clear_from_newline_symbol(querry);
      String_t initial_letters = create_string_from_ptr(querry, strlen(querry));

      size_t result_size = 0;
      size_t* result     = search_by_initial_letters(contacts, contacts_size,
                                                     initial_letters, &result_size);

      free_string(initial_letters);

      if (result_size == 0) {
        printf("Not found\n");
        free(result);
        free(querry);
        continue;
      }

      size_t last = 0;
      for (size_t i = 0; i < contacts_size && last < result_size; i++) {
        if (result[last] == i) {
          printf("%zu) ", i + 1);
          String_t fullname = get_fullname(contacts[i]);
          printf("%s\n", fullname.data);
          free_string(fullname);
          last++;
        }
      }


      free(result);
      free(querry);
      continue;
    }
    if (mode == INITIAL_DIGITS) {
      printf("Phone numbers: ");
      clear_input_buffer();
      char* querry = malloc(sizeof(char) * BUFFER_SIZE);

      fgets(querry, BUFFER_SIZE, stdin);
      clear_from_newline_symbol(querry);
      String_t initial_letters = create_string_from_ptr(querry, strlen(querry));

      size_t result_size = 0;
      size_t* result     = search_by_initial_digits(contacts, contacts_size,
                                                    initial_letters, &result_size);

      free_string(initial_letters);

      if (result_size == 0) {
        printf("Not found\n");
        free(result);
        free(querry);
        continue;
      }

      size_t last = 0;
      for (size_t i = 0; i < contacts_size; i++) {
        if (result[last] == i) {
          printf("%zu) ", i + 1);
          print_contact(contacts[i]);
          last++;
        }
      }

      free(result);

      free(querry);
      continue;
    }
    if (mode == EDITING_CONTACT) {
      display_contacts(contacts, contacts_size);
      size_t contact_id = get_id(contacts_size);

      edit_contact(&contacts, &contacts_size, contact_id);

      continue;
    }
    if (mode == DELETING_CONTACT) {
      display_contacts(contacts, contacts_size);
      size_t contact_id = get_id(contacts_size);

      delete_contact(&contacts, &contacts_size, contact_id);

      continue;
    }
  }


  return dump_contacts_to_file(contacts, contacts_size);
}
