#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_TOP           1000
#define MAX_FILE_NAME_SIZE 30
#define AMOUNT_OF_FILES    15

struct File {
  char name[MAX_FILE_NAME_SIZE];
  unsigned int size;
};

unsigned int generate_random_file_size() { return 1 + rand() % RAND_TOP; }
void print_files(struct File files[]) {
  for (int i = 0; i < AMOUNT_OF_FILES; i++) {
    printf("%s\t%d\tbytes\n", files[i].name, files[i].size);
  }
}
bool greater_compare(unsigned int left, unsigned int right) { return left > right; }
bool less_compare(unsigned int left, unsigned int right) { return left < right; }


void bubble_sort(struct File *files, unsigned int size,
                 bool (*compare)(unsigned int, unsigned int)) {
  for (int i = 1; i < size; i++) {
    bool flag = true;
    for (int j = 0; j < size - i; j++) {
      if (compare(files[j].size, files[j + 1].size)) {
        struct File buffer = files[j];

        files[j]     = files[j + 1];
        files[j + 1] = buffer;

        flag = false;
      } else {
      }
    }
    if (flag) { break; }
  }
}

void insertion_sort(struct File *files, unsigned int size,
                    bool (*compare)(unsigned int, unsigned int)) {
  for (int i = 1; i < size; i++) {
    struct File comparing = files[i];

    int j = i - 1;  // NOLINT
    while (j >= 0 && compare(files[j].size, comparing.size)) {
      files[j + 1] = files[j];
      j--;
    }
    files[j + 1] = comparing;
  }
}
struct File *merge_sort(struct File *arr, struct File *buff, unsigned int left,
                        unsigned int right,
                        bool (*compare)(unsigned int, unsigned int)) {
  if (left == right) {
    buff[left] = arr[right];
    return buff;
  }

  unsigned int middle = (right - left) / 2 + left;

  struct File *l_buff = merge_sort(arr, buff, left, middle, compare);
  struct File *r_buff = merge_sort(arr, buff, middle + 1, right, compare);

  struct File *res = l_buff == arr ? buff : arr;

  unsigned int l_cur = left;
  unsigned int r_cur = middle + 1;

  for (unsigned int i = left; i <= right; i++) {
    if (l_cur <= middle && r_cur <= right) {
      if (compare(l_buff[l_cur].size, r_buff[r_cur].size)) {
        res[i] = l_buff[l_cur++];
      } else {
        res[i] = r_buff[r_cur++];
      }
    } else if (l_cur <= middle) {
      res[i] = l_buff[l_cur++];
    } else {
      res[i] = r_buff[r_cur++];
    }
  }

  return res;
}

int main() {
  struct File files1[AMOUNT_OF_FILES];
  struct File files2[AMOUNT_OF_FILES];
  struct File files3[AMOUNT_OF_FILES];
  struct File files4[AMOUNT_OF_FILES];
  // NOLINTBEGIN(*-magic-*)
  files1[0]  = (struct File){"excitement.txt", 0};
  files1[1]  = (struct File){"tour.doc", 0};
  files1[2]  = (struct File){"coffee.png", 0};
  files1[3]  = (struct File){"demand.txt", 0};
  files1[4]  = (struct File){"advertising.pub", 0};
  files1[5]  = (struct File){"menu.doc", 0};
  files1[6]  = (struct File){"function.cpp", 0};
  files1[7]  = (struct File){"discussion.log", 0};
  files1[8]  = (struct File){"peace.png", 0};
  files1[9]  = (struct File){"stuff.mp4", 0};
  files1[10] = (struct File){"secretary.txt", 0};
  files1[11] = (struct File){"enthusiasm.mp3", 0};
  files1[12] = (struct File){"status.txt", 0};
  files1[13] = (struct File){"matter.doc", 0};
  files1[14] = (struct File){"importance.png", 0};
  files2[0]  = (struct File){"highway.png", 0};
  files2[1]  = (struct File){"agent.ssh", 0};
  files2[2]  = (struct File){"ticket.pdf", 0};
  files2[3]  = (struct File){"request.txt", 0};
  files2[4]  = (struct File){"guarantee.png", 0};
  files2[5]  = (struct File){"ambition.txt", 0};
  files2[6]  = (struct File){"relation.doc", 0};
  files2[7]  = (struct File){"share.html", 0};
  files2[8]  = (struct File){"mistake.djvu", 0};
  files2[9]  = (struct File){"ability.txt", 0};
  files2[10] = (struct File){"bar.png", 0};
  files2[11] = (struct File){"link.svg", 0};
  files2[12] = (struct File){"debt.txt", 0};
  files2[13] = (struct File){"bird.jpg", 0};
  files2[14] = (struct File){"glass.psd", 0};
  files3[0]  = (struct File){"level.txt", 0};
  files3[1]  = (struct File){"life.md", 0};
  files3[2]  = (struct File){"base.xml", 0};
  files3[3]  = (struct File){"solution.pdf", 0};
  files3[4]  = (struct File){"example.txt", 0};
  files3[5]  = (struct File){"style.css", 0};
  files3[6]  = (struct File){"complaint.txt", 0};
  files3[7]  = (struct File){"relation.xml", 0};
  files3[8]  = (struct File){"sugar.djvu", 0};
  files3[9]  = (struct File){"line.pdf", 0};
  files3[10] = (struct File){"bar.png", 0};
  files3[11] = (struct File){"height.txt", 0};
  files3[12] = (struct File){"mode.log", 0};
  files3[13] = (struct File){"confusion.doc", 0};
  files3[14] = (struct File){"mission.xls", 0};
  files4[0]  = (struct File){"union.txt", 0};
  files4[1]  = (struct File){"information.pub", 0};
  files4[2]  = (struct File){"bird.svg", 0};
  files4[3]  = (struct File){"schedule.xls", 0};
  files4[4]  = (struct File){"text.doc", 0};
  files4[5]  = (struct File){"farmer.png", 0};
  files4[6]  = (struct File){"collection.txt", 0};
  files4[7]  = (struct File){"database.db", 0};
  files4[8]  = (struct File){"study.md", 0};
  files4[9]  = (struct File){"month.xls", 0};
  files4[10] = (struct File){"population.txt", 0};
  files4[11] = (struct File){"height.txt", 0};
  files4[12] = (struct File){"depth.txt", 0};
  files4[13] = (struct File){"hour.log", 0};
  files4[14] = (struct File){"user.txt", 0};
  // NOLINTEND(*-magic-*)
  for (int i = 0; i < AMOUNT_OF_FILES; i++) {
    files1[i].size = generate_random_file_size();
  }
  for (int i = 0; i < AMOUNT_OF_FILES; i++) {
    files2[i].size = generate_random_file_size();
  }
  for (int i = 0; i < AMOUNT_OF_FILES; i++) {
    files3[i].size = generate_random_file_size();
  }
  for (int i = 0; i < AMOUNT_OF_FILES; i++) {
    files4[i].size = generate_random_file_size();
  }

  bool user_ans = true;
  while (user_ans == true) {
    srand(time(NULL));
    printf("Directory of C:\\Users\\User:\n"
           "0)\tExit\n"
           "1)\t<DIR>\tLesson 1\n"
           "2)\t<DIR>\tLesson 2\n"
           "3)\t<DIR>\tLesson 3\n"
           "4)\t<DIR>\tLesson 4\n");

    printf("Choose dir: ");

    unsigned int dir_number = UINT_MAX;
    do {
      scanf("%d", &dir_number);

      if (dir_number > 4) { printf("Incorrect dir number. Pls repeat\n"); }
    } while (dir_number > 4);

    if (dir_number == 0) { break; }

    struct File *cur_files = NULL;
    if (dir_number == 1) {
      cur_files = files1;
    } else if (dir_number == 2) {
      cur_files = files2;
    } else if (dir_number == 3) {
      cur_files = files3;
    } else {
      cur_files = files4;
    }


    print_files(cur_files);

    printf("\n");

    bool user_sort_ans = true;
    while (user_sort_ans == true) {
      printf("Choose sort:\n"
             "0)\tExit\n"
             "1)\tBuuble sort\n"
             "2)\tInsertion sort\n"
             "3)\tMerge sort\n");

      unsigned int sort_alg = UINT_MAX;
      do {
        scanf("%d", &sort_alg);

        if (sort_alg > 3) { printf("Incorrect sort alg. Pls repeat\n"); }
      } while (sort_alg > 3);
      if (sort_alg == 0) { break; }

      printf("Choose compare type:\n"
             "1)\tMin on top\n"
             "2)\tMax on top\n");

      unsigned int compare_type = 0;
      do {
        scanf("%d", &compare_type);

        if (compare_type > 2) { printf("Incorrect compare type. Pls repeat\n"); }
      } while (compare_type > 2);

      printf("\n");
      double cpu_time_used = 0;
      if (sort_alg == 1) {
        clock_t start = clock();
        if (compare_type == 1) {
          bubble_sort(cur_files, AMOUNT_OF_FILES, greater_compare);
        } else {
          bubble_sort(cur_files, AMOUNT_OF_FILES, less_compare);
        }
        clock_t end = clock();


        print_files(cur_files);
        printf("\n");
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
      } else if (sort_alg == 2) {
        clock_t start = clock();
        if (compare_type == 1) {
          insertion_sort(cur_files, AMOUNT_OF_FILES, greater_compare);
        } else {
          insertion_sort(cur_files, AMOUNT_OF_FILES, less_compare);
        }
        clock_t end = clock();


        print_files(cur_files);
        printf("\n");
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
      } else {
        struct File *res                    = NULL;
        struct File buffer[AMOUNT_OF_FILES] = {
            {"example.txt", 0}
        };
        clock_t start = clock();
        if (compare_type == 2) {
          res =
              merge_sort(cur_files, buffer, 0, AMOUNT_OF_FILES - 1, greater_compare);
        } else {
          res = merge_sort(cur_files, buffer, 0, AMOUNT_OF_FILES - 1, less_compare);
        }
        clock_t end = clock();

        print_files(res);
        printf("\n");
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
      }

      printf("Estimated time: %lf\n", cpu_time_used);

      printf("\n");
    }
  }

  return 0;
}
