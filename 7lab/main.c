#include <stdio.h>
#include "calc.h"

int main() {

    int a, b, input = 0;

    while(1) {
        printf("1) Сложение\n2) Вычитание\n3) Умножение\n4) Деление\n5) Выход\n");

        printf("Введите номер операции: ");
        if(scanf("%d", &input) != 1) {
            printf("Ошибка: введите число\n");
            while (getchar() != '\n');
            continue;
        }
        if (input == 5) {
            printf("Выход\n");
            return 0;
        }

        if (input >= 1 && input <= 4) {
            printf("Введите a: ");
            if(scanf("%d", &a) != 1) {
                printf("Ошибка: введите число\n");
                while (getchar() != '\n');
                continue;
            }
            printf("Введите b: ");
            if(scanf("%d", &b) != 1) {
                printf("Ошибка: введите число\n");
                while (getchar() != '\n');
                continue;
            }
        }
        else {
            printf("Неправильно набран номер\n");
            continue;
        }

        switch (input) {
        case 1:
            printf("Result: %d\n", add(a, b));
            break;
        case 2:
            printf("Result: %d\n", sub(a, b));
            break;
        case 3:
            printf("Result: %d\n", mul(a, b));
            break;
        case 4:
            if(b == 0) {
                printf("На ноль делить нельзя!\n");
                continue;
            }
            printf("Result: %d\n", div(a, b));
            break;
        }
    }   

    return 0;
}   