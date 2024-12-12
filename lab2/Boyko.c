#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void last3holder(int t1, int t2, int arr[3], int n) {
    t1 = arr[0];
    t2 = arr[1];
    arr[0] = n;
    arr[1] = t1;
    arr[2] = t2;
}
int main()
{
    int rnd, pl, flag1 = 0, tries = 0;
    srand(time(NULL));
    do {
        printf("choose mode: ");
        int mode;
        scanf_s("%d", &mode);
        switch (mode) {
            case 1: {
                rnd = rand() % 1000 + 1;
                printf("take a guess\n");
                int yours = -1;
                while (1) {
                    tries++;
                    scanf_s("%d", &yours);
                    if (yours > rnd) {
                        printf("lower\n");
                    }
                    else if (yours < rnd) {
                        printf("higher\n");
                    }
                    else {
                        break;
                    }
                }
                printf("it is\n");
                flag1 = 1;
                break;
            }
            case 2: {
                int flag2 = 0;
                do {
                    int pc = rand() % 1000 + 1;
                    int tmp_up = 1000, tmp_down = 0;
                    int tmp[3] = { 0 };
                    printf("%d\n", pc);
                    while (1) {
                        int br_flag = 0;
                        char cl = getchar();
                        if (cl == '=') {
                            tries++;
                            flag2 = 1;
                            break;
                        }
                        if (cl == '>') {
                            if (pc > tmp_down) tmp_down = pc;
                            pc = pc + ((tmp_up - pc + 1) / 2);
                            if (pc > 1000) pc = 1000;
                            tries++;
                            int tmp_int1 = 0, tmp_int2 = 0;
                            last3holder(tmp_int1, tmp_int2, tmp, pc);
                            if (tmp[0] == tmp[1] || tmp[0] == tmp[2]) {
                                printf("i got confused\ntry again\n\n");
                                tries = 0;
                                break;
                            }
                            printf("%d\n", pc);
                        }
                        if (cl == '<') {
                            if (pc < tmp_up) tmp_up = pc;
                            pc = tmp_down + ((pc - tmp_down) / 2);
                            tries++;
                            int tmp_int1 = 0, tmp_int2 = 0;
                            last3holder(tmp_int1, tmp_int2, tmp, pc);
                            if (tmp[0] == tmp[1] || tmp[0] == tmp[2]) {
                                printf("i got confused\ntry again\n\n");
                                tries = 0;
                                break;
                            }
                            printf("%d\n", pc);
                        }

                    }
                } while (!flag2);
                flag1 = 1;
                break;
            }
            default: {
                while (getchar() != '\n');
                printf("again\n");
                break;
            }
        }
    } while (!flag1);
    printf("tries - %d", tries);
}