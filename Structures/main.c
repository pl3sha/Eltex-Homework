#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100
#define CLEAR_SCREEN do { if (system("clear") == -1) { system("cls"); } } while(0)

typedef struct {
    char name[10];
    char second_name[10];
    char tel[10];  
}abonent; 

int add(abonent* arr_abonent, int count_abonent) {

    CLEAR_SCREEN;

    printf("Ведите имя: ");
    if (scanf("%9s", arr_abonent[count_abonent].name) != 1) {
        return -1;
    }

    printf("Ведите фамилию: ");
    if (scanf("%9s", arr_abonent[count_abonent].second_name) != 1) {
        return -2;
    }

    printf("Ведите номер: ");
    if (scanf("%9s", arr_abonent[count_abonent].tel) != 1) {
        return -3;
    }

    return ++count_abonent;
}

int delete(abonent* arr_abonent, int count_abonent) {

    CLEAR_SCREEN;

    count_abonent--;

    int number_abonent;

    printf("Введите под каким номер находится абонент в списке(1 - %d): ", count_abonent + 1);
    scanf("%d", &number_abonent);
    memset(&arr_abonent[number_abonent - 1], 0, sizeof(abonent));

    if (number_abonent == SIZE) {   
        memset(&arr_abonent[count_abonent], 0, sizeof(abonent));
        return 0;
    }

    for (int i = number_abonent - 1; i < count_abonent; i++) {
        arr_abonent[i] = arr_abonent[i + 1];
    }

    memset(&arr_abonent[count_abonent], 0, sizeof(abonent));
    
    return count_abonent;
}

int search(abonent* arr_abonent, int count_abonent) {

    CLEAR_SCREEN;

    int j = 0;
    char search_name[10];
    
    printf("Введите имя: ");
    scanf("%9s", search_name);
    printf("\n");

    for (int i = 0; i < count_abonent; i++) {
        if(!(strcasecmp(arr_abonent[i].name, search_name))) {
            printf("Name: %s\nsecond_name: %s\ntel: %s\n\n", arr_abonent[i].name, arr_abonent[i].second_name, arr_abonent[i].tel);
            j++;
        }
    }

    if (j == 0) {
        return -1;
    }
    
    return 0;
}

int Print(abonent* arr_abonent, int count_abonent) {

    CLEAR_SCREEN;

    if (count_abonent == 0) {
        return -1;
    }
            
    for (int i = 0; i < count_abonent; i++) {
        printf("Abonent Number (%d)\nName: %s\nsecond_name: %s\ntel: %s\n\n\n", i + 1, arr_abonent[i].name, arr_abonent[i].second_name, arr_abonent[i].tel);
    }
            
    return 0;
}

int main()
{
    abonent arr_abonent[SIZE];

    int input, count_abonent = 0, check;

    while(1) {
        printf("1) Добавить абонента\n2) Удалить абонента\n3) Поиск абонентов по имени\n4) Вывод всех записей\n5) Выход\nBвeдитe: ");
        scanf("%d", &input);

        if (input == 1) {
            check = add(arr_abonent, count_abonent);
            CLEAR_SCREEN;

            if (check == -1) {
                printf("\n\nОШИБКА ВВОДА ИМЕНИ !\n\n");
            }
            else if (check == -2) {
                printf("\n\nОШИБКА ВВОДА ФАМИЛИИ !\n\n");
            }
            else if (check == -3) {
                printf("\n\nОШИБКА ВВОДА НОМЕРА !\n\n");
            }        
            else {
                count_abonent = check;
            }
        }

        if (input == 2) {
            count_abonent = delete(arr_abonent, count_abonent);
            CLEAR_SCREEN;
        }

        if (input == 3) {
            CLEAR_SCREEN;
            check = search(arr_abonent, count_abonent);

            if (check == -1) {
                printf("\n\nОШИБКА ! ПОЛЬЗОВАТЕЛЬ С ТАКИМ ИМЕНЕМ НЕ НАЙДЕН !\n\n");
            }
        }

        if (input == 4) {   
            CLEAR_SCREEN;
            check = Print(arr_abonent, count_abonent);
            
            if (check == -1) {
                printf("\n\nСПИСОК ПУСТ !\n\n");
            }
            
        }

        if (input == 5) {
            CLEAR_SCREEN;
            printf("Вы вышли из программы...\n");
            break;
        }
        
    }

    return 0;
} 