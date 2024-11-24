#include <stdio.h>
#include <string.h>

char* substring_search(char* str, char* strsub)
{
    char* start = strsub;
    char* point;

    while(*str != '\0')
    {
        point = str;

        while(*str == *strsub && *strsub != '\0')
        {
            str++;
            strsub++;
        }

        if (*strsub == '\0')
        {
            return point;
        }
        strsub = start;
        str++;
    }
    return NULL;
}

int main()
{
    char str[51], substr[6];
    char* point;

    printf("Введите сторку: ");
    scanf("%s", str);

    printf("Введите подстроку: ");
    scanf("%s", substr);

    point = substring_search(str, substr);

    if (point == NULL)
    {
        printf("Ничего не нашлось(((\n");
        return -1;
    }
    
    printf("%s\n", point);

    return 0;
}