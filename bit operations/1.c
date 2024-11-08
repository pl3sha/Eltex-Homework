#include <stdio.h>

void first_task(unsigned int num)
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
    int check;
    unsigned int num;
    
    printf("Введите целое положительное число: ");
    check = scanf("%u", &num);
    if (check != 1)
    {
        printf("Вы ввели не 'целое положительное число'\n");
        return -1;
    }
    first_task(num);       

    return 0;
}