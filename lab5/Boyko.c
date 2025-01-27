#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define L 100

void selection(int *a, int l) {
	for (int i = 0; i < l - 1; i++) {
		int _min = i;
		for (int j = i; j < l; j++) {
			if (a[j] < a[_min]) { _min = j; }
		}
		if (_min != i) {
			int tmp = a[i];
			a[i] = a[_min];
			a[_min] = tmp;
		}
	}
}
void selection_rev(int* a, int l) {
    for (int i = 0; i < l - 1; i++) {
        int _max = i;
        for (int j = i; j < l; j++) {
            if (a[j] > a[_max]) { _max = j; }
        }
        if (_max != i) {
            int tmp = a[i];
            a[i] = a[_max];
            a[_max] = tmp;
        }
    }
}

void print_arr(int* a, int l) {
	for (int i = 0; i < l; i++) { printf("%c", a[i]); }
}

void print_str_arr(int* a, int l) {
    for (int i = 0; i < 7; i++) { printf("%c\n", a[i+(l*7)]); }
}

void insertion(int *a, int l) {
	for (int i = 1; i < l; i++) {
		int tmp = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > tmp) {
			a[j+1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
	}
}

void quicksort(int* a, int l) {
    int i = 0;
    int j = l - 1;
    int mid = a[l/2];
    do {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        quicksort(a, j + 1);
    }
    if (i < l) {
        quicksort(&a[i], l - i);
    }
}

void quicksort_rev(int* a, int l) {
    int i = 0;
    int j = l - 1;
    int mid = a[l / 2];
    do {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        quicksort(a, j + 1);
    }
    if (i < l) {
        quicksort(&a[i], l - i);
    }
}

void merge(int* a, int l) {
    int mid = l / 2;
    if (l % 2 == 1) {
        mid++;
    }
    int h = 1;
    int* c = (int*)malloc(l * sizeof(int));
    int step;
    while (h < l) {
        step = h;
        int i = 0;
        int j = mid;
        int k = 0;
        while (step <= mid) {
            while ((i < step) && (j < l) && (j < (mid + step))) {
                if (a[i] < a[j]) {
                    c[k] = a[i];
                    i++;
                    k++;
                }
                else {
                    c[k] = a[j];
                    j++;
                    k++;
                }
            }
            while (i < step) {
                c[k] = a[i];
                i++;
                k++;
            }
            while ((j < (mid + step)) && (j < l)) {
                c[k] = a[j];
                j++;
                k++;
            }
            step = step + h;
        }
        h = h * 2;
        for (i = 0; i < l; i++) {
            a[i] = c[i];
        }
    }
}

void main() {
    char folders[3][10] = { "f1\tdir\n", "f2\tdir\n", "f3\tdir\n"}; //names
    char f1[22][20] = { "aaa\ttxt", "cat\ttxt", "civs\ttxt", "creep\ttxt", "drg01\tpng", "drg02\tpng", "drg03\tpng", "drg04\tpng", "drg05\tpng", "drg06\tpng", "drg07\tpng", "drg08\tpng", "drg09\tpng", "drg10\tpng", "drg11\tpng", "drg12\tpng", "essay\ttxt", "loop\twav", "pass\ttxt", "song\tmp3","tblade\ttxt", "u_spr\tbmp"};
    int f1_num[22] = { 46, 130, 484, 68, 841728, 895738, 827434, 963790, 841728, 785368, 841224, 897732, 727466, 867090, 840028, 865398, 2466, 12376, 28, 2035696, 1098, 1866 };
    char ff[30] = { "This directory is empty\n" };
    const int l = 5;
    const int len = sizeof(f1_num) / sizeof(int);
    do {
        int break_flag = 1;
        for (int i = 0; i < 3; i++) { printf("%s", folders[i]); }
        printf("\nD:\\>");
        int n = -1;
        char ys[40] = { 0 };
        fgets(ys, 40, stdin);
        fflush(stdin);
        if (strcmp(ys, "f1\n") == 0) {
            
            int f1_flag = 1;
            char ns[40] = { 0 };
            while (strcmp(ns, "cd ..\n") != 0 && break_flag) {
                if (f1_flag) {
                    for (int i = 0; i < len; i++) { printf("%s\t%d\n", f1[i], f1_num[i]); }
                }
                f1_flag = 0;
                ns[0] = '\0';
                printf("\nD:\\f1\\>");
                fgets(ns, 40, stdin);
                fflush(stdin);
                if (strcmp(ns, "cd \\\n") == 0) {
                    break_flag = 0;
                }
                if (strcmp(ns, "cat.txt\n") == 0) {
                    char ss[40] = { 0 };
                    f1_flag = 1;
                    printf("    /\\_____/\\    \n   /  o   o  \\   \n  ( ==  ^  == )  \n   )         (   \n  (           )  \n ( (  )   (  ) )\n(__(__)___(__)__)\n");
                    while (strcmp(ss, "cd ..\n") != 0 && break_flag) {
                        ss[0] = '\0';
                        printf("\nD:\\f1\\cat.txt\\>");
                        fgets(ss, 40, stdin);
                        fflush(stdin);
                        if (strcmp(ss, "cd \\\n") == 0) {
                            break_flag = 0;
                        }
                        if (strcmp(ss, "sort\n") == 0) {
                            printf("'sort' can't be used here\n");
                        }
                    }
                }
                if (strcmp(ns, "sort\n") == 0) {
                    char SS[3] = { 0 };
                    int stop = 1;
                    while (strcmp(SS, "n\n") != 0 || stop) {
                        int comp_flag = 0;
                        int f1_sort[20] = { 0 };
                        for (int i = 0; i < len; i++) {
                            f1_sort[i] = f1_num[i];
                        }
                        
                        int pr_flag = 0;
                        int t_flag = 0;
                        double t_comp;
                        do {
                            clock_t st_t, en_t;
                            double t;
                            SS[0] = '\0';
                            comp_flag = 0;
                            int len = sizeof(f1_num) / sizeof(f1_num[0]);
                            printf("1.1 - selection sort asc\n1.2 - selection sort desc\n2 - insertion sort\n3 - quicksort\n4 - merge sort\nn - go back\n");
                            printf("\nsort>");
                            fgets(SS, 5, stdin);
                            fflush(stdin);
                            if (strcmp(SS, "n\n") == 0) {
                                stop = 0;
                                break;
                            }
                            if (strcmp(SS, "1.1\n") == 0) {
                                comp_flag = 1;
                                pr_flag = 1;
                                st_t = clock();
                                selection(f1_sort, len);
                                /*int j = 0;
                                int k = 0;
                                for (int i = 0; j < 3000000; i++) {
                                    j++;
                                    if (j == 2500000) {
                                        k++;
                                        j = 0;
                                    }
                                    if (k == 1000) break;
                                }
                                */
                                en_t = clock();
                                t = (double)(en_t - st_t) / CLOCKS_PER_SEC;
                                printf("%lf\n", t);
                            }
                            if (strcmp(SS, "1.2\n") == 0) {
                                comp_flag = 1;
                                pr_flag = 1;
                                st_t = clock();
                                selection_rev(f1_sort, len);
                                en_t = clock();
                                t = (double)(en_t - st_t) / CLOCKS_PER_SEC;
                                printf("%lf\n", t);
                            }
                            if (strcmp(SS, "2\n") == 0) {
                                comp_flag = 1;
                                pr_flag = 1;
                                st_t = clock();
                                insertion(f1_sort, len);
                                en_t = clock();
                                t = (double)(en_t - st_t) / CLOCKS_PER_SEC;
                                printf("%lf\n", t);
                            }
                            if (strcmp(SS, "3\n") == 0) {
                                comp_flag = 1;
                                pr_flag = 1;
                                st_t = clock();
                                quicksort(f1_sort, len);
                                en_t = clock();
                                t = (double)(en_t - st_t) / CLOCKS_PER_SEC;
                                printf("%lf\n", t);
                            }
                            if (strcmp(SS, "4\n") == 0) {
                                comp_flag = 1;
                                pr_flag = 1;
                                st_t = clock();
                                merge(f1_sort, len);
                                en_t = clock();
                                t = (double)(en_t - st_t) / CLOCKS_PER_SEC;
                                printf("%lf\n", t);
                            }
                            SS[0] = '\0';
                            if (t_flag) {
                                if (t_comp > t) {
                                    printf("This sorting was faster comparing to a previous one\n");
                                }
                                else if (t_comp < t) {
                                    printf("This sorting was slower comparing to a previous one\n");
                                }
                                else printf("The sortings are nearly identical in time\n");
                            }
                            while (strcmp(SS, "y\n") != 0 && strcmp(SS, "n\n") != 0) {
                                printf("Do you wanna compare the sortings? y/n\n");
                                printf("\nsort>");
                                fgets(SS, 3, stdin);
                                fflush(stdin);
                            }
                            if (strcmp(SS, "y\n") == 0) {
                                t_flag = 1;
                                t_comp = t;
                            }
                            if (strcmp(SS, "n\n") == 0) {
                                comp_flag = 0;
                            }
                            SS[0] = '\0';
                        } while (comp_flag);
                        if (t_flag) {
                            printf("The changes were made according to the last sorting\n");
                        }
                        if (pr_flag) {
                            int skip = -1;
                            for (int i = 0; i < len; i++) {
                                for (int j = 0; j < len; j++) {
                                    if (f1_sort[i] == f1_num[j] && j != skip) {
                                        printf("%s\t%d\n", f1[j], f1_num[j]);
                                        skip = j;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (strcmp(ys, "f2\n") == 0) {
            int f2_flag = 1;
            char ns[40] = { 0 };
            while (strcmp(ns, "cd ..\n") != 0 && break_flag) {
                if (f2_flag) {
                    printf("%s", ff);
                }
                f2_flag = 0;
                ns[0] = '\0';
                printf("\nD:\\f2\\>");
                fgets(ns, 40, stdin);
                fflush(stdin);
                if (strcmp(ns, "cd \\\n") == 0) {
                    break_flag = 0;
                }
                if (strcmp(ns, "sort\n") == 0) {
                    printf("There's nothing to sort\n");
                }
            }
        }
        if (strcmp(ys, "f3\n") == 0) {
            int f3_flag = 1;
            char ns[40] = { 0 };
            while (strcmp(ns, "cd ..\n") != 0 && break_flag) {
                if (f3_flag) {
                    printf("%s", ff);
                }
                f3_flag = 0;
                ns[0] = '\0';
                printf("\nD:\\f3\\>");
                fgets(ns, 40, stdin);
                fflush(stdin);
                if (strcmp(ns, "cd \\\n") == 0) {
                    break_flag = 0;
                }
                if (strcmp(ns, "sort\n") == 0) {
                    printf("There's nothing to sort\n");
                }
            }
        }
        if (strcmp(ys, "shutdown /s\n") == 0) break;
    } while (1);
}
