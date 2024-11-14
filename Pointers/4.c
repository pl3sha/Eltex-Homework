#include <stdio.h>
#include <string.h>

int main()
{
    char str[50], substr[4] = "are";
    char* point;

    printf("Введите сторку: ");
    scanf("%s", str);

    point = strstr(str, substr);
    if (point == NULL)
    {
        printf("Ничего не нашлось(((\n");
        return -1;
    }
    
    printf("%s\n", point);

    return 0;
}