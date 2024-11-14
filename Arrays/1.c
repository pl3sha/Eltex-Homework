#include <stdio.h>

int main()
{
    int N, count = 1, check;
    
    printf("Введите целоe положительное число (2 - 10): ");
    check = scanf("%d", &N);

    if ((check != 1))
    {
        printf("Вы ввели не целое положительное число\n");
        return -1;
    }

    if (!((N >= 2) && (N <= 10)))
    {
        printf("Вы не попали в допустимый диапазон (2 - 10)\n");
        return -1;
    }

    int arr[N][N];    

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = count;
            count++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf(("%2d "), arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}