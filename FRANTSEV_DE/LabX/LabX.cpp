#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void zamena(char a[], char b[], char buff[], size_t size) {
    strcpy_s(buff, size, b);
    strcpy_s(b, size, a);
    strcpy_s(a, size, buff);
}

int main()
{
    setlocale(LC_ALL, "rus");
    char** list_of_names;
    list_of_names = (char**)calloc(30, 200);
    char** list_of_phones;
    list_of_phones = (char**)calloc(30, 30);
    char** list_of_email;
    list_of_email = (char**)calloc(30, 100);
    char** list_of_org;
    list_of_org = (char**)calloc(30, 100);
    char** list_of_dolz;
    list_of_dolz = (char**)calloc(30, 100);

    int mem1 = 200, mem2 = 30, mem3 = 100, mem4 = 100, mem5 = 100;

    int mode = 6, size_kont = 0;
    while (mode != 0) {
        //sortirovka blinbuba
        if (size_kont > 1) { 
            for (int i = 1; i < size_kont; i++) {
                char buffer[100] = { 0 };
                for (int j = i + 1; j < size_kont + 1; j++) {
                    int razr = 0;
                    for (int k = 0; k < 100; k++) {
                        if (list_of_names[j][k] < list_of_names[i][k]) {
                            razr = 1;
                            break;
                        }
                        else if (list_of_names[j][k] > list_of_names[i][k]) {
                            break;
                        }
                    }
                    
                    if (razr == 1) {
                        zamena(list_of_names[j], list_of_names[i], buffer, 100);
                        zamena(list_of_phones[j], list_of_phones[i], buffer, 30);
                        zamena(list_of_email[j], list_of_email[i], buffer, 100);
                        zamena(list_of_org[j], list_of_org[i], buffer, 100);
                        zamena(list_of_dolz[j], list_of_dolz[i], buffer, 100);
                    }
                }
            }
        }
        //end of sortirovka aboba
        mode = 6;
        printf("Вы вошли в приложение <Контакты> вашего Смартфон Vivo.\nСписок контактов:\n");
        if (size_kont == 0) { printf("=\nЗдесь пока ничего нет.\n=\n\n"); }
        else 
        {
            
            for (int i = 1; i < size_kont+1; i++) {
                printf("=\n\n");
                printf("#%d\n\n", i);
                printf("ФИО: ");
                puts(list_of_names[i]);
                printf("Номер телефона: ");
                puts(list_of_phones[i]);
                printf("Электронная почта: ");
                puts(list_of_email[i]);
                printf("Организация: ");
                puts(list_of_org[i]);
                printf("Должность: ");
                puts(list_of_dolz[i]);
                printf("=\n");
            }
        }
        while (mode > 5 ||mode < 0) {
            printf("Что вы хотите сделать?\n1 - Создание нового контакта\n2 - Редактирование контакта\n3 - Удаление контакта\n4 - Поиск контакта\n0 - Выход из приложения\n");
            scanf_s("%d", &mode);
        }
        if (mode == 1) {
            size_kont += 1;
            char buffer[100] = { 0 };
            while (getchar() != '\n');
            
            printf("---СОЗДАНИЕ НОВОГО КОНТАКТА---\n");
            do {
                printf("Введите ФИО*:");
                fgets(buffer, 100, stdin);
            } while (buffer[0] == '\n');
            list_of_names[size_kont] = (char*)malloc(100 * 2);
            strcpy_s(list_of_names[size_kont],100, buffer);
            do {
            printf("Введите номер телефона*: ");
            fgets(buffer, 30, stdin);
            } while (buffer[0] == '\n');
            list_of_phones[size_kont] = (char*)malloc(15 * 2);
            strcpy_s(list_of_phones[size_kont], 30, buffer);
            
            printf("Введите электронную почту: ");
            fgets(buffer, 50, stdin);
            list_of_email[size_kont] = (char*)malloc(50 * 2);
            strcpy_s(list_of_email[size_kont],50, buffer);
            printf("Введите организацию: ");
            fgets(buffer, 50, stdin);
            list_of_org[size_kont] = (char*)malloc(50 * 2);
            strcpy_s(list_of_org[size_kont],50, buffer);
            printf("Введите должность: ");
            fgets(buffer, 30, stdin);
            list_of_dolz[size_kont] = (char*)malloc(50 * 2);
            strcpy_s(list_of_dolz[size_kont],50, buffer);
            printf("Успешно! Нажмите Enter для продолжения:");
            fgets(buffer, 2, stdin);
            system("cls");

        }
        else if (mode == 4) {
            char buffer[100] = { 0 };
            while (getchar() != '\n');
            printf("Введите часть ФИО, номера телефона, почты, организации или должности: ");
            fgets(buffer, 100, stdin);
            int finded = 0;
            for (int i = 0; i < 100; i++) {
                if (buffer[i] == '\n') {
                    buffer[i] = '\0';
                }
            }
            for (int j = 1; j < size_kont+1; j++) {
                if (strstr(list_of_names[j], buffer) != NULL || strstr(list_of_phones[j], buffer) != NULL || strstr(list_of_email[j], buffer) != NULL || strstr(list_of_org[j], buffer) != NULL || strstr(list_of_dolz[j], buffer) != NULL ) {
                    printf("=\n\n");
                    printf("#%d\n\n", j);
                    printf("ФИО: ");
                    puts(list_of_names[j]);
                    printf("Номер телефона: ");
                    puts(list_of_phones[j]);
                    printf("Электронная почта: ");
                    puts(list_of_email[j]);
                    printf("Организация: ");
                    puts(list_of_org[j]);
                    printf("Должность: ");
                    puts(list_of_dolz[j]);
                    printf("=\n");
                    finded += 1;
                }
            }
            if (finded == 0) {
                printf("\n=\nНет совпадений. Нажмите Enter для продолжения: ");
            }
            else {
                printf("Успешно! Нажмите Enter для продолжения: ");
            }
            fgets(buffer, 2, stdin);
            system("cls");
        }
        else if (mode == 3) {
            int num_death;
            printf("Введите номер контакта, который вы хотите удалить: ");
            scanf_s("%d", &num_death);
            char buffer[100] = { 0 };
            for (int j = num_death; j < size_kont; j++) {
                zamena(list_of_names[j], list_of_names[j+1], buffer, 100);
                zamena(list_of_phones[j], list_of_phones[j+1], buffer, 30);
                zamena(list_of_email[j], list_of_email[j+1], buffer, 100);
                zamena(list_of_org[j], list_of_org[j+1], buffer, 100);
                zamena(list_of_dolz[j], list_of_dolz[j+1], buffer, 100);
            }
            free(list_of_names[size_kont]);
            free(list_of_phones[size_kont]);
            free(list_of_email[size_kont]);
            free(list_of_org[size_kont]);
            free(list_of_dolz[size_kont]);
            size_kont -= 1;
            printf("Успешно! Нажмите Enter для продолжения: ");
            while (getchar() != '\n');
            fgets(buffer, 2, stdin);
            system("cls");
        }
        else if (mode == 5) {
            printf("Секретная служебная информация! size_kont = %d\n\nПАСХАЛКО\nВКЛЮЧАЕМ ВЕНТИЛЯТОРЫ\n1488148814881488148814881488148814881488148814881488148814881488148814881488148814881488148814881488148814881488148814881488148814881488148814881488\n", size_kont);
            char buffer[30] = { 0 };
            while (getchar() != '\n');
            fgets(buffer, 8, stdin);
            system("cls");
        }
        else if (mode == 2) {
            int num_red = 0;
            do {
                if (num_red > size_kont) { printf("У вас нет контакта с таким номером!\n"); }
                printf("Введите номер контакта, который вы хотите редактировать (при введении * поле останется неизменным): ");
                scanf_s("%d", &num_red);
            } while (num_red>size_kont || num_red < 0);
            if (num_red == 0){}
            else {
                char buffer[100] = { 0 };
                while (getchar() != '\n');
                printf("Старое ФИО: ");
                puts(list_of_names[num_red]);
                do {
                    printf("Новое ФИО: ");
                    fgets(buffer, 100, stdin);
                } while (buffer[0] == '\n');
                if (buffer[0] == '*' && buffer[1] == '\n') {/*do nothing*/ }
                else { strcpy_s(list_of_names[num_red], 100, buffer); }
                printf("Старый номер телефона: ");
                puts(list_of_phones[num_red]);
                do {
                    printf("Новый номер телефона: ");
                    fgets(buffer, 100, stdin);
                } while (buffer[0] == '\n');
                if (buffer[0] == '*' && buffer[1] == '\n') {/*do nothing*/ }
                else { strcpy_s(list_of_phones[num_red], 30, buffer); }
                printf("Старая почта: ");
                puts(list_of_email[num_red]);
                printf("Новая почта: ");
                fgets(buffer, 100, stdin);
                if (buffer[0] == '*' && buffer[1] == '\n') {/*do nothing*/ }
                else { strcpy_s(list_of_email[num_red], 100, buffer); }
                printf("Старая организация: ");
                puts(list_of_org[num_red]);
                printf("Новая организация: ");
                fgets(buffer, 100, stdin);
                if (buffer[0] == '*' && buffer[1] == '\n') {/*do nothing*/ }
                else { strcpy_s(list_of_org[num_red], 100, buffer); }
                printf("Старая должность: ");
                puts(list_of_dolz[num_red]);
                printf("Новая должность: ");
                fgets(buffer, 100, stdin);
                if (buffer[0] == '*' && buffer[1] == '\n') {/*do nothing*/ }
                else { strcpy_s(list_of_dolz[num_red], 100, buffer); }
                printf("Успешно! Нажмите Enter для продолжения: ");
                fgets(buffer, 2, stdin);
                system("cls");
            }
        }
    }
}