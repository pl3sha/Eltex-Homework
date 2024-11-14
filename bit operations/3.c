#include <stdio.h>
#include <limits.h>

int main()
{   
    int check, num, count = 0;
    
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
    
    int size = sizeof(num) * 8;
    
    while(size > 0)
    {
        if(num & 1)
        {
            count++;
        }
        num >>= 1;

        size--;   
    }
    
    printf("количество единиц: %d\n", count);

    return 0;
}