#include <stdio.h>

int main() 
{
    int arr[10], num = 1;
    int* ptr = arr;

    for (int i = 0; i < 10; i++)
    {
        arr[i] = num++;
        printf("%d ", *ptr++);
    }

    printf("\n");

    return 0;
}