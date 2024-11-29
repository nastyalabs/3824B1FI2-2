#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Choose mode:\n");
  printf("0 - you make a number\n1 - you guess a number\n");

  int mode = -1;
  do {
    scanf("%d", &mode);
    if (mode != 0 && mode != 1) {
      printf("Give correct mode pls\n");
    }
  } while (mode != 0 && mode != 1);

  if (mode == 1) {
    srand(time(NULL));

    int my_rand = rand() % 1000 + 1;

    printf("Ok, I make the number in [1, 1000]\n");
    printf("Give me a guess: ");

    int guess = -1;

    int counter = 1;

    while (guess != my_rand) {
      do {
        scanf("%d", &guess);

        if (guess < 1 || guess > 1000) {
          printf("Give me a correct guess (from [1, 1000])\n");
        }

      } while (guess < 1 || guess > 1000);

      if (my_rand > guess) {
        printf("My number is bigger\n");
        counter++;
      } else if (my_rand < guess) {
        printf("My number is smaller\n");
        counter++;
      } else {
        printf("You are right, my number is: %d\n", my_rand);
        printf("You made it with %d steps\n", counter);
      }
    }

  } else {
    printf("Ok, give me a try\n");
    printf("Write > if your number is bigger, < if it's smaller, and = if it's "
           "equal\n");

    char res = -1;
    int counter = 1;
    while (res != '=') {

      int l = 0;
      int r = 1001;
      while (l < r - 1) {
        int m = (r - l) / 2 + l;
        printf("%d?\n", m);

        do {
          scanf("%s", &res);
          if (res != '>' && res != '<' && res != '=') {
            printf("I can't understand\n");
          }
        } while (res != '>' && res != '<' && res != '=');

        if (res == '>') {
          l = m;
          counter++;
        } else if (res == '<') {
          r = m;
          counter++;
        } else {
          break;
        }
      }
    }
    printf("Yes, I made it with %d steps!\n", counter);
  }

  return 0;
}
