#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int number = 1 + (rand() % 10);
    setlocale (LC_ALL,"Russian");
    int our_number = 11,k = 0;
    while (our_number!=number){
        printf("Введи номер\n");
        scanf_s("%d",&our_number);
        k++;
        if (our_number!=number){
            if (our_number > number){
            printf("Номер меньше\n");}

            
            else
            printf("Номер больше\n");}
        
        
        }
            printf("Победа\n");
            printf("Попыток-%d",k);
        return 0;
    }