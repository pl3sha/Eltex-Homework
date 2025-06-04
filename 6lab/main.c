#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef struct abonent {
    char name[10];
    char second_name[10];
    char tel[10]; 
    struct abonent* prev;
    struct abonent* next;
} abonent; 

void free_list(abonent** arr_abonent) {
    abonent* temporary_pointer = *arr_abonent;
    abonent* next_node;

    while (temporary_pointer != NULL) {
        next_node = temporary_pointer->next;  
        free(temporary_pointer);              
        temporary_pointer = next_node;        
    }

    *arr_abonent = NULL;  
}

abonent* create_abonent() {
    abonent* new_abonent = (abonent *)malloc(sizeof(abonent));
    if (new_abonent == NULL) {   
        printf("Не удалось выделить память !\n");
        return NULL;
    }
    
    printf("Ведите имя: ");
    scanf("%9s", new_abonent->name);

    printf("Ведите фамилию: ");
    scanf("%9s", new_abonent->second_name);

    printf("Ведите номер: ");
    scanf("%9s", new_abonent->tel);

    printf("\n");

    new_abonent->next = NULL;
    new_abonent->prev = NULL;

    return new_abonent;
}

int add(abonent** arr_abonent) {

    struct abonent* new_node = create_abonent();
    if (new_node == NULL) {
        return 0;
    }
    
    struct abonent* temporary_pointer = *arr_abonent;

    if (*arr_abonent == NULL) {
        new_node->next = NULL;
        new_node->prev = NULL;
        *arr_abonent = new_node;
    }
    else {
        while (temporary_pointer->next != NULL) {
            temporary_pointer = temporary_pointer->next;
        }

        new_node->prev = temporary_pointer;
        temporary_pointer->next = new_node;
    }

    return 0;
}

int delete(abonent** arr_abonent) {
    int flag = 0;
    char search_name[10];
    char search_second_name[10];
    char search_tel[10];
    abonent* temporary_pointer = *arr_abonent;

    if (temporary_pointer != NULL) {
        printf("Ведите имя: ");
        scanf("%9s", search_name);

        printf("Ведите фамилию: ");
        scanf("%9s", search_second_name);
    
        printf("Ведите номер: ");
        scanf("%9s", search_tel);

        printf("\n");

        while (temporary_pointer != NULL) {
            if (strcmp(temporary_pointer->name, search_name) == 0 && strcmp(temporary_pointer->second_name, search_second_name) == 0 && strcmp(temporary_pointer->tel, search_tel) == 0) {
                flag = 1;
                if (temporary_pointer->next != NULL) {
                    temporary_pointer->next->prev = temporary_pointer->prev;
                }
                if (temporary_pointer->prev != NULL) {
                    temporary_pointer->prev->next = temporary_pointer->next;   
                } else {
                    *arr_abonent = temporary_pointer->next;
                }
                free(temporary_pointer);
                break;
            }
            temporary_pointer = temporary_pointer->next;
        }
        if (flag != 1) {
            printf("ПОЛЬЗОВАТЕЛЬ НЕ НАЙДЕН !\n\n");
            return 0;
        }   
    }
    else {
        printf("CПИСОК ПУСТ !\n\n");
        return 0;           
    }
    
    return 0;
}

int search(abonent** arr_abonent) {

    abonent* temporary_pointer = *arr_abonent;
    char search_name[10];
    int flag = 0;

    printf("Введите имя: ");
    scanf("%9s", search_name);
    printf("\n");

    if (*arr_abonent != NULL) {
        while(temporary_pointer != NULL) {
            if (!(strcmp(temporary_pointer->name, search_name))) {
                printf("Name: %s\nsecond_name: %s\ntel: %s\n", temporary_pointer->name, temporary_pointer->second_name, temporary_pointer->tel);
                flag = 1;
            }
            temporary_pointer = temporary_pointer->next;
        }
        if (flag != 1) {
            printf("ПОЛЬЗОВАТЕЛЬ НЕ НАЙДЕН !\n");
            return 0;
        }
    }
    else {
        printf("Список пуст !\n");
        return 0;
    }
    
    return 0;
}

int print(abonent** arr_abonent) {

    abonent* temporary_pointer = *arr_abonent;
    if (*arr_abonent == NULL) {
        printf("Список пуст !\n");
        return 0;
    }
            
    while (temporary_pointer != NULL) {
        printf("Name: %s\nsecond_name: %s\ntel: %s\n", temporary_pointer->name, temporary_pointer->second_name, temporary_pointer->tel);
        temporary_pointer = temporary_pointer->next;
    }
            
    return 0;
}

int main()
{
    abonent* arr_abonent = NULL;

    int input;

    while(1) {
        printf("1) Добавить абонента\n2) Удалить абонента\n3) Поиск абонентов по имени\n4) Вывод всех записей\n5) Выход\nBвeдитe: ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            add(&arr_abonent);
            break;
        case 2: 
            delete(&arr_abonent);
            break;
        case 3:
            search(&arr_abonent);
            break;
        case 4:
            print(&arr_abonent);
            break;
        case 5:
            free_list(&arr_abonent);
            printf("Вы вышли из программы...\n");
            return 0;
            break;

        default:
            printf("Неверный ввод !\n");
        }
    }

    return 0;
}