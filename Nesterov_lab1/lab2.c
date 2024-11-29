#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point {
  int x;
  int y;
};

int main() {
  unsigned int chess_piece = 255;
  printf("Choose your chess piece:\n0: King\n1: Queen\n2: Rook\n3: Bishop\n4: "
         "Knight\n");
  scanf("%d", &chess_piece);

  if (chess_piece > 4) {
    printf("You didn't choose your chess piece\n");
    return 0;
  }

  struct Point start = {0, 0};
  printf("Enter start x and y for the start\n");
  scanf("%d %d", &start.x, &start.y);

  if (start.x > 8 || start.x <= 0 || start.y > 8 || start.x <= 0) {
    printf("Impossible coordinates\n");
    return 0;
  }

  struct Point end = {0, 0};
  printf("Enter start x and y for the end\n");
  scanf("%d %d", &end.x, &end.y);

  if (end.x > 8 || end.x <= 0 || end.y > 8 || end.x <= 0) {
    printf("Impossible coordinates\n");
    return 0;
  }

  int x_diff = abs(end.x - start.x);
  int y_diff = abs(end.y - start.y);

  if (chess_piece == 0) {
    if (x_diff <= 1 && y_diff <= 1) {
      printf("Yes, king can do it\n");
    } else {
      printf("No, king can't do it\n");
      if ((x_diff == 0 || y_diff == 0) || (x_diff == y_diff)) {
        printf("Queen can do it\n");
      }
      if (x_diff == y_diff) {
        printf("Bishop can do it\n");
      }
      if ((x_diff == 0) || (y_diff == 0)) {
        printf("Rook can do it\n");
      }
      if ((x_diff == 1 && y_diff == 2) || (x_diff == 2 && y_diff == 1)) {
        printf("Knight can do it\n");
      }
    }
  } else if (chess_piece == 1) {
    if ((x_diff == 0 || y_diff == 0) || (x_diff == y_diff)) {
      printf("Yes, queen can do it\n");
    } else {
      printf("No, queen can't do it\n");
      if (x_diff <= 1 && y_diff <= 1) {
        printf("King can do it\n");
      }
      if (x_diff == y_diff) {
        printf("Bishop can do it\n");
      }
      if ((x_diff == 0) || (y_diff == 0)) {
        printf("Rook can do it\n");
      }
      if ((x_diff == 1 && y_diff == 2) || (x_diff == 2 && y_diff == 1)) {
        printf("Knight can do it\n");
      }
    }
  } else if (chess_piece == 2) {
    if ((x_diff == 0) || (y_diff == 0)) {
      printf("Yes, rook can do it\n");
    } else {
      printf("No, rook can't do it\n");
      if (x_diff <= 1 && y_diff <= 1) {
        printf("King can do it\n");
      }
      if ((x_diff == 0 || y_diff == 0) || (x_diff == y_diff)) {
        printf("Queen can do it\n");
      }
      if (x_diff == y_diff) {
        printf("Bishop can do it\n");
      }
      if ((x_diff == 1 && y_diff == 2) || (x_diff == 2 && y_diff == 1)) {
        printf("Knight can do it\n");
      }
    }
  } else if (chess_piece == 3) {
    if (x_diff == y_diff) {
      printf("Yes, bishop can do it\n");
    } else {
      printf("No, bishop can't do it\n");
      if (x_diff <= 1 && y_diff <= 1) {
        printf("King can do it\n");
      }
      if ((x_diff == 0 || y_diff == 0) || (x_diff == y_diff)) {
        printf("Queen can do it\n");
      }
      if ((x_diff == 0) || (y_diff == 0)) {
        printf("Rook can do it\n");
      }
      if ((x_diff == 1 && y_diff == 2) || (x_diff == 2 && y_diff == 1)) {
        printf("Knight can do it\n");
      }
    }
  } else {
    if ((x_diff == 1 && y_diff == 2) || (x_diff == 2 && y_diff == 1)) {
      printf("Yes, Knight can do it\n");
    } else {
      printf("No, Knight can't do it\n");
      if (x_diff <= 1 && y_diff <= 1) {
        printf("King can do it\n");
      }
      if ((x_diff == 0 || y_diff == 0) || (x_diff == y_diff)) {
        printf("Queen can do it\n");
      }
      if (x_diff == y_diff) {
        printf("Bishop can do it\n");
      }
      if ((x_diff == 0) || (y_diff == 0)) {
        printf("Rook can do it\n");
      }
    }
  }

  /*if (x_diff <= 1 && y_diff <= 1) {*/
  /*  printf("King can do it\n");*/
  /*}*/
  /*if ((x_diff == 0 || y_diff == 0) || (x_diff == y_diff)) {*/
  /*  printf("Queen can do it\n");*/
  /*}*/
  /*if (x_diff == y_diff) {*/
  /*  printf("Bishop can do it\n");*/
  /*}*/
  /*if ((x_diff == 0) || (y_diff == 0)) {*/
  /*  printf("Rook can do it\n");*/
  /*}*/
  /*if ((x_diff == 1 && y_diff == 2) || (x_diff == 2 && y_diff == 1)) {*/
  /*  printf("Knight can do it\n");*/
  /*}*/

  return 0;
}
