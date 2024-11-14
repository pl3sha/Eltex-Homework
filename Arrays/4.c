#include <stdio.h>

int main() 
{
    int N, check;

    printf("Введите положительное целое чило (2 - 10): ");
    check = scanf("%d", &N);

    if(check != 1)
    {
        printf("Ошибка! Вы ввели не 'положительное целое число'");
        return -1;
    }

    if (!((N >= 2) || (N <= 10)))
    {
        printf("Ошибка! Вы вышли за допустимый диапазон (2 - 10)'");
        return -1;       
    }

    int arr[N][N];

    int up = 0, down = N - 1, right = N - 1, left = 0, value = 1;

    while (value <= N*N)
    {
        for (int i = left; i <= right; i++)
        {
            arr[up][i] = value;
            value++;
        }
        up++;

        for (int i = up; i <= down; i++)
        {
            arr[i][right] = value;
            value++;
        }
        right--;
        
        for (int i = right; i >= left; i--)
        {
            arr[down][i] = value;
            value++;
        }
        down--;

        for (int i = down; i >= up ; i--)
        {
            arr[i][left] = value;
            value++;
        }
        left++;
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}