#include <stdio.h>
#include <limits.h>

int main()
{   
    int check, num;
    
    printf("Введите целое отрицательное число число: ");
    check = scanf("%d", &num);
    if ((check != 1) || (num >= 0) || (num < INT_MIN))
    {
        printf("Вы ввели не 'целое отрицательное число' или слишком блольшое, макс: %d\n", INT_MIN);
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