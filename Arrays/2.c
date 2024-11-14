#include <stdio.h>

int main() 
{
    int N, count = 1, check;

    printf("Введите положительное целое число (2 - 10): ");
    check = scanf("%d", &N);

    if(check != 1)
    {
        printf("Ошибка! Вы ввели не 'положительное целое число'");
        return -1;
    }

    if (!((N >= 2) && (N <= 10)))
    {
        printf("Ошибка! Вы вышли за допустимый диапазон (2 - 100)");
        return -1;       
    }

    int arr[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = count;
        printf("%d ", arr[i]);
        count++;
    }

    printf("\n");
    
    for (int i = 0; i < N; i++)
    {
        count -= 2;
        arr[i] += count;
        printf("%d ", arr[i]);
    }

    printf("\n");
    
    return 0;
}