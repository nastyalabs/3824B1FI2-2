#include <ctype.h>
#include <stdio.h>

int main() {
  printf("Enter your text (must end with new line symbol)\n");

  char ch = -1;
  int words = 0;
  int numbers = 0;
  int is_word = 0;
  int is_number = 0;
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch) != 0) {
      if (is_word == 0) {
        words++;
        is_word = 1;
      }
    } else if (isdigit(ch) != 0 || ch == '-') {
      if (is_number == 0) {
        numbers++;
        is_number = 1;
      }
    } else {
      is_word = 0;
      is_number = 0;
    }
  }

  printf("Words: %d\n", words);
  printf("Numbers: %d\n", numbers);

  return 0;
}
