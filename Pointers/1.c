#include <stdio.h>
#include <limits.h>

int main() 
{   
    int check, num, new_num;
    unsigned char* ptr = (unsigned char *)&num;
    
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

    printf("Введите новое значение для третьего байта (0-255): ");
    check = scanf("%d", &new_num);

    if ((check != 1))
    {
        printf("Ошибка! Вы ввели не 'целое положительное число'\n");
        return -1;
    }

    if (!((new_num >= 0) && (new_num <= 255)))
    {
        printf("Ошибка! Вы вышли за допустимый диапазон (0 - 255)\n");
        return -1;
    }

    printf("Было: %d\n", num);

    for (int i = 0; i < sizeof(int); i++)
    {
        printf("%3d ", ptr[i]);
    }
    printf("\n");
    
    ptr[2] = new_num;

    for (int i = 0; i < sizeof(int); i++)
    {
        printf("%3d ", ptr[i]);
    }
    printf("\n");

    printf("Стало:%d\n", num);

    return 0;
}