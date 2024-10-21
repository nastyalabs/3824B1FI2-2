#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *make_correct_number(int length) {
  srand(time(NULL));

  int rand_slice = 100;

  for (int i = 2; i < length; i++) {
    rand_slice *= 10;
  }

  int *number = (int *)malloc(5 * sizeof(int));
  for (int i = 0; i < 5; i++) {
    number[i] = -1;
  }

  bool is_correct_guess = false;

  while (!is_correct_guess) {
    int candidate_number = rand() % rand_slice + 1;

    for (int i = 1; candidate_number > 0; i++) {
      number[length - i] = candidate_number % 10;
      candidate_number /= 10;
    }

    bool is_correct = true;
    for (int i = 0; i < length; i++) {
      for (int j = i + 1; j < length; j++) {
        if (number[i] == number[j]) {
          is_correct = false;
          break;
        }
      }
      if (!is_correct) {
        break;
      }
    }

    if (number[0] == -1) {
      is_correct = false;
    }

    if (is_correct) {
      is_correct_guess = true;
    }
  }

  return number;
}

bool guess_is_correct(int guess, int length) {
  if (length == 2) {
    return 10 <= guess && guess <= 99;
  }
  if (length == 3) {
    return 100 <= guess && guess <= 999;
  }
  if (length == 4) {
    return 1000 <= guess && guess <= 9999;
  }
  return 10000 <= guess && guess <= 99999;
}

bool is_equal_numbers(const int *guess, const int *number, int length) {
  bool all_match = true;
  for (int i = 0; i < length; i++) {
    if (guess[i] != number[i]) {
      all_match = false;
      break;
    }
  }

  return all_match;
}

int count_cows(const int *guess, const int *number, int length) {
  int cows = 0;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (i == j) {
        continue;
      }
      if (guess[i] == number[j]) {
        cows++;
      }
    }
  }

  return cows;
}

int count_bulls(const int *guess, const int *number, int length) {
  int bulls = 0;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (i == j && guess[i] == number[j]) {
        bulls++;
      }
    }
  }

  return bulls;
}

int main() {
  printf("Please, choose number length (from 2 to 5 digits): ");

  int length = 2;
  do {
    scanf("%d", &length);
    if (length < 2 || length > 5) {
      printf("Give correct length, please. Length: ");
    }
  } while (length < 2 || length > 5);

  int *number = make_correct_number(length);
  /*for (int i = 0; i < 5; i++) {*/
  /*  printf("%d ", guess[i]);*/
  /*}*/

  int guess[5];
  for (int i = 0; i < 5; i++) {
    guess[i] = -1;
  }

  while (!is_equal_numbers(guess, number, length)) {
    printf("Make u guess: ");
    int guess_number = -1;

    do {
      scanf("%d", &guess_number);

      if (!guess_is_correct(guess_number, length)) {
        printf("Your guess and the length don't match! Make a guess again: ");
      }
    } while (!guess_is_correct(guess_number, length));
    for (int i = 1; guess_number > 0; i++) {
      guess[length - i] = guess_number % 10;
      guess_number /= 10;
    }

    int cows = count_cows(guess, number, length);
    int bulls = count_bulls(guess, number, length);

    printf("Cows: %d\tBulls: %d\n", cows, bulls);
  }

  printf("Yahoooo! U guessed it\n");
  printf("Guessed number: ");
  for (int i = 0; i < length; i++) {
    printf("%d", number[i]);
  }
  printf("\n");

  free(number);

  return 0;
}
