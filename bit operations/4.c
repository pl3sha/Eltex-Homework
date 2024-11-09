#include <stdio.h>

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
    if ((check != 1) || (num < 0))
    {
        printf("Нужно ввести положительное число'\n");
        return -1;
    }

    printf("Введите целое число для замены (0-255): ");
    check = scanf("%d", &new_num);
    if ((check != 1) || !((new_num >= 0) && (new_num <= 255)))
    {
        printf("Не правильно\n");
        return -1;
    }
    
    fourth_task(num, new_num);       

    return 0;
}