#include <stdio.h>
#include <limits.h>

int main()
{   
    int check, num;
    
    printf("Введите целое отрицательное число число: ");
    check = scanf("%d", &num);
    
    if ((check != 1))
    {
        printf("Вы ввели не 'целое отрицательное число'");
        return -1;
    }

    if ((num >= 0) || (num < INT_MIN))
    {
        printf("Ошибка! Вы вышли за допустимый диапазон ((%d) - (-1))\n", INT_MIN);
        return -1;
    }

    int size = sizeof(num) * 8; 
    
    printf("В двоичном виде: ");
    while (size > 0)
    {
        printf("%u", num >> (size - 1) & 1);
        size--;
    }
    printf("\n");

    return 0;
}