#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
    char prod[5][15] = {"milk", "eggs", "butter", "apple\njuice", "cheese"}; //names
    char price[5][5] = {"80p", "90p", "300p", "120p", "200p"};//price
    char dsc[5][5] = {"5%", "10%", "25%", "40%", "8%"};
    //int n_price[5] = {80, 90, 300, 120, 200};
    int n_price[5] = { 76, 81, 225, 72, 184 };
    //char c[5][40] = {"1178", "2532", "2779", "3006", "3734"}; codes
    int cnt[5] = { 0 };
    int presum[5] = { 0 };
    printf("enter the code numbers\nwhen you are done, type in 'end' to get to the summary\n");
    do {
        char ys[4] = { 0 };
        for (int i = 0; i < 4; i++) {
            char c = getchar();
            ys[i] = c;
        }
        if ((ys[0] == 'e') && (ys[1] == 'n') && (ys[2] == 'd')) {
            break;
        }
        int yn = 0;
        int dv = 1;
        for (int i = 0; i < 4; i++) {
            yn += (ys[3 - i] - 48) * dv;
            dv *= 10;
        }
        while (getchar() != '\n');
        switch (yn) {
            case 1178: {
                cnt[0]++;
                presum[0] += n_price[0];
                printf("%s\t%s\t%d pc\t%s\t%dp\n", prod[0], price[0], cnt[0], dsc[0], presum[0]);
                break;
            }
            case 2532: {
                cnt[1]++;
                presum[1] += n_price[1];
                printf("%s\t%s\t%d pc\t%s\t%dp\n", prod[1], price[1], cnt[1], dsc[1], presum[1]);
                break;
            }
            case 2779: {
                cnt[2]++;
                presum[2] += n_price[2];
                printf("%s\t%s\t%d pc\t%s\t%dp\n", prod[2], price[2], cnt[2], dsc[2], presum[2]);
                break;
            }
            case 3006: {
                cnt[3]++;
                presum[3] += n_price[3];
                printf("%s\t%s\t%d pc\t%s\t%dp\n", prod[3], price[3], cnt[3], dsc[3], presum[3]);
                break;
            }
            case 3734: {
                cnt[4]++;
                presum[4] += n_price[4];
                printf("%s\t%s\t%d pc\t%s\t%dp\n", prod[4], price[4], cnt[4], dsc[4], presum[4]);
                break;
            }
            default: {
                printf("undefined\n");
                break;
            }
        }
    } while (1);
    //printf("enter a discount\n");
    /*float discount = 0;
    do {
        scanf_s("%f", &discount);
        if (discount > 50 || discount < 1) {
            printf("the number have to be from 1 to 50: ");
        }
    } while (discount > 50 || discount < 1);*/
    for (int i = 0; i < 5; i++) {
        if (cnt[i] > 0) {
            printf("%s\t%s\t%d pc\t%s\t%dp\n", prod[i], price[i], cnt[i], dsc[i], presum[i]);
        }
    }
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += presum[i];
    }
    //int pretty_disc = discount;
    //printf("summary: %dp\ndiscount: %d%%\n", sum, pretty_disc);
    //sum = sum - (sum * (discount / 100));
    printf("in total: %dp", sum);
}