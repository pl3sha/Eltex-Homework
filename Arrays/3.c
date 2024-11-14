#include <stdio.h>

int main() 
{
    int N, check;

    printf("Введите положительное целое чило(2 - 10): ");
    check = scanf("%d", &N);

    if(check != 1)
    {
        printf("Ошибка! Вы ввели не 'положительное целое число'");
        return -1;
    }

    if (!((N >= 2) && (N <= 10)))
    {
        printf("Ошибка! Вы вышли за допустимый диапазон (2 - 10)'");
        return -1;       
    }

    int arr[N][N], index = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            arr[i][j] = 0;
            index = j;
            printf("%d ", arr[i][j]);
        }

        for (int k = 0; k < i + 1; k++)
        {
            arr[i][index] = 1;
            printf("%d ", arr[i][index]);
            index++;
        }
        printf("\n");
    }

    return 0;
}