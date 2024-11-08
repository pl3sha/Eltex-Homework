#include <stdio.h>

void third_task(unsigned int num)
{
    int size = sizeof(num) * 8, count = 0;
    
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
}

int main()
{   
    int check;
    unsigned int num;
    
    printf("Введите целое положительное число: ");
    check = scanf("%d", &num);
    if (check != 1)
    {
        printf("Вы ввели не целое положительное число !\n");
        return -1;
    }
    third_task(num);

    return 0;
}