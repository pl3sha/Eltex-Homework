#include <stdio.h>
#include <limits.h>

int main()
{   
    int check, num;
    
    printf("Введите целое положительное число: ");
    check = scanf("%d", &num);

    if ((check != 1))
    {
        printf("Вы ввели не 'целое положительное число'\n");
        return -1;
    }

    if (!(num >= 0) && (num <= INT_MAX))
    {
        printf("Вы вышли за допустимый диапазон (0 - %d)\n", INT_MAX);
        return -1;
    }

    int size = sizeof(num) * 8;
    
    printf("В двоичном виде: ");
    while (size > 0)
    {
        printf("%d", num >> (size - 1) & 1);
        size--;
    }
    printf("\n");       

    return 0;
}