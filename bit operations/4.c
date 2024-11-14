#include <stdio.h>
#include <limits.h>

void fourth_task(int num, int new_num)
{
    int size = sizeof(num) * 8;

    printf("было :");
    for(int i = size, j = 1; i > 0; i--, j++)
    {
        printf("%d", num >> (i - 1) & 1);
        if (j%8 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");

    num = (num & 0xFF00FFFF) | (new_num << 16);

    printf("Стало:");
    for(int i = size, j = 1; i > 0; i--, j++)
    {
        printf("%d", num >> (i - 1) & 1);
        if (j%8 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");

} 

int main() 
{   
    int check, num, new_num;
    
    printf("Введите целое положительное число: ");
    check = scanf("%d", &num);

    if ((check != 1)) 
    {
        printf("Вы ввели не 'целое положительное число'\n");
        return -1;
    }

    if ((num < 0) || (num > INT_MAX))
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
    
    fourth_task(num, new_num);       

    return 0;
}