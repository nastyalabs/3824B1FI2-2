#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void insertion(int* a, int min, int max)
{
    if ((max - min) >= 2) {

        int* b = (int*)malloc((max - min) * sizeof(int));

        int choosed = ((max - min) / 2) + min, k = 0, ne_null = 0;;

        /*  for (int i = min; i < max; i++) {
              printf("%d ", a[i]);
          }
          printf(" - got a - %d - %d\n", a[choosed], choosed);*/
        for (int i = min; i < max; i++) {
            if (a[i] <= a[choosed] && (i != choosed)) {
                b[k] = a[i];
                k += 1;
            }
        }
        //printf("\n");

        b[k] = a[choosed];
        int kukold = k;

        k += 1;
        for (int i = min; i < max; i++) {
            if (a[i] > a[choosed] && i != choosed) {
                b[k] = a[i];
                k += 1;
            }
        }
        /*for (int i = 0; i < k; i++) {
            printf("%d ", b[i]);
        }
        printf(", %d - choosed\n", a[choosed]);
        */for (int i = 0; i < k; i++) {
            a[min + i] = b[i];
        }


        /*  for (int i = min; i < max; i++) {
              printf("%d ", a[i]);
          }
          printf(" - did a\n");*/
        free(b);
        if (kukold - min != max - min) {
            insertion(a, min, min + kukold);
            insertion(a, min + kukold, max);
        }
    }
}
void bubble(int* a, int n, char (*b)[40])
{
    int buff;
    
    for (int i = 0; i < n; i++) {
        
        for (int j = i; j < n; j++) {
            char buffer[256] = { 0 };
            if (a[i] > a[j]) {
                buff = a[j];
                a[j] = a[i];
                a[i] = buff;
                for (int l = 0; l < 40; l++){
                    buffer[l] = b[j][l];
                    
                }
                
                for (int l = 0; l < 40; l++) {
                    b[j][l] = b[i][l];

                }
                
                
                for (int l = 0; l < 40; l++) {
                    b[i][l] = buffer[l];
                }
            }
        }
    }
    
}
int main()
{
    setlocale(LC_ALL, "rus");
    FILE* file;
    errno_t err = fopen_s(&file, "examples.txt", "r");
    if (file == NULL) {
        printf("DILDO");
        return 0;
    }
    if (err != 0) {
        printf("Ya tvoi file mother shatal\n");
        return 0;
    }
    int ages[20] = { 0 };
    char names[20][40] = { 0 };
    char buffer[256] = { 0 };
    int numstr = -1;
    while ((fgets(buffer, 256, file) != NULL))
    {
        numstr++;
        int i = 0;
        int lengthnum = 0;
        for (i = 0; i < 256; i++) {
            if (buffer[i] > 47 && buffer[i] < 58) { lengthnum++; }
            if (buffer[i] == '\n')
            {
                int popitka = 1;
                for (int j = i - 1; j > i - 1 - lengthnum; j--) {
                    
                    ages[numstr] += (buffer[j] - 48) * popitka;
                    popitka *= 10;
                }
                if (popitka > 1) { break; }
            }
            
        }
        
        for (int j = 0; j < i  - lengthnum; j++) {
            names[numstr][j] = buffer[j];        
        }

    }
    int poryadok[20] = { 0 };
    for (int i = 0; i < 20; i++) {
        poryadok[i] = i;
    }
    printf("Выберите сортировку:\n1 - Пузырёк\n2 - Insertion\n");
    int mode = 0;
    scanf_s("%d", &mode);
    
    if (mode == 1) {
        bubble(ages, numstr + 1, names);

        for (int i = 0; i < numstr + 1; i++) {
            printf("%s %d\n", names[i], ages[i]);
        }
    }
    else if (mode == 2) {
        printf("Вы разрешили мне не делать 2 сортировку :)");
    }
    else printf("bebra\n");
    
    fclose(file);
    
    
   
}
