#include <stdio.h>

void second_task(int num)
{
    int size = sizeof(num) * 8;
    
    printf("В двоичном виде: ");
    while (size > 0)
    {
        printf("%u", num >> (size - 1) & 1);
        size--;
    }
    printf("\n");
}

int main()
{   
    int check, num;
    
    printf("Введите целое отрицательное число число: ");
    check = scanf("%d", &num);
    if ((num >= 0) || (check != 1))
    {
        printf("Вы ввели не 'целое отрицательное число'\n");
        return -1;
    }
    second_task(num);

    return 0;
}