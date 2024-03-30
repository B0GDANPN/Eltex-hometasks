//
// Created by bogdan on 12.03.24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ABONENTS 100
#define SIZE_NAME 10
#define SIZE_TEL 10

void nullCheck(void *ptr) {
    if (ptr == NULL)
        exit(0);
}

typedef struct {
    char name[SIZE_NAME];
    char second_name[SIZE_NAME];
    char tel[SIZE_TEL];
} abonent;
typedef struct {
    int ind;
    int capacity;
    abonent *abonents;
} dyn_array;


void clearArray(dyn_array *arr) {
    arr->ind = -1;
    arr->capacity = 0;
    free(arr->abonents);
}

void initArray(dyn_array *arr) {
    abonent *ptr = (abonent *) malloc(sizeof(abonent));
    nullCheck(ptr);
    arr->abonents = ptr;
    arr->ind = -1;//указывает на последнего существующего абонента, при добавлении
    // нужно увеличивать ind, затем запись
    arr->capacity = 1;
}

void add_abonent(dyn_array *arr) {
    if (arr->ind >= MAX_ABONENTS - 1) {
        printf("Directory overflow.\n");
        return;
    }
    arr->ind++;
    if (arr->ind == arr->capacity) {
        arr->capacity *= 2;
        arr->abonents = (abonent *) realloc(arr->abonents, sizeof(abonent) * arr->capacity);
        nullCheck(arr->abonents);
    }
    printf("Enter name: ");
    //arr->abonents[arr->ind].name = (char *) malloc(sizeof(char) * SIZE_NAME);
    fgets(arr->abonents[arr->ind].name, SIZE_NAME, stdin);
    printf("Enter second name: ");
    fgets(arr->abonents[arr->ind].second_name, SIZE_NAME, stdin);
    printf("Enter telephone number: ");
    fgets(arr->abonents[arr->ind].tel, SIZE_TEL, stdin);
}

void delete_abonent(dyn_array *arr) {
    char *name = (char *) malloc(sizeof(char) * SIZE_NAME);
    nullCheck(name);
    printf("Enter name of the abonent to delete: ");
    fgets(name, SIZE_NAME, stdin);

    for (int i = 0; i <= arr->ind; i++) {
        if (strcmp(arr->abonents[i].name, name) == 0) {
            abonent tmp = arr->abonents[i];
            for (int j = i + 1; j <= arr->ind; j++) {
                arr->abonents[j - 1] = arr->abonents[j];
            }
            arr->abonents[arr->ind] = tmp;
            arr->ind--;
            printf("Abonent deleted successfully.\n");
            free(name);
            return;
        }
    }
    if ((arr->ind!=-1)&& (arr->ind * 4< arr->capacity)){
        arr->capacity/=4;
        arr->abonents = (abonent *) realloc(arr->abonents, sizeof(abonent) * arr->capacity);
        nullCheck(arr->abonents);
    }
    free(name);
    printf("Abonent not found.\n");
}

void search_abonents(dyn_array *arr) {
    char *name = (char *) malloc(sizeof(char) * SIZE_NAME);
    nullCheck(name);
    printf("Enter the name to search: ");
    fgets(name, SIZE_NAME, stdin);
    int found = 0;
    for (int i = 0; i <= arr->ind; i++) {
        if (strcmp(arr->abonents[i].name, name) == 0) {
            printf("Name: %s\n, Second Name: %s\n, Telephone: %s\n",
                   arr->abonents[i].name,
                   arr->abonents[i].second_name,
                   arr->abonents[i].tel);
            found = 1;
        }
    }
    free(name);
    if (!found) {
        printf("No abonents found with the given name.\n");
    }
}

void display_all_abonents(dyn_array *arr) {
    if (arr->ind == -1) {
        printf("No abonents in the directory.\n");
        return;
    }
    for (int i = 0; i <= arr->ind; i++) {
        if (arr->abonents[i].name[0] != '\0') {
            printf("Name: %s\n, Second Name: %s\n, Telephone: %s\n",
                   arr->abonents[i].name,
                   arr->abonents[i].second_name,
                   arr->abonents[i].tel);
        }
    }
}

int main() {
    int switcher;
    dyn_array arr;
    initArray(&arr);
    while (1) {
        printf("\n--- Subscription Directory Menu ---\n");
        printf("1) Add a abonent\n");
        printf("2) Delete the abonent\n");
        printf("3) Search for abonents by name\n");
        printf("4) Output of all records\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &switcher);
        getchar();
        switch (switcher) {
            case 1:
                add_abonent(&arr);
                break;
            case 2:
                delete_abonent(&arr);
                break;
            case 3:
                search_abonents(&arr);
                break;
            case 4:
                display_all_abonents(&arr);
                break;
            case 5:
                printf("Exiting program.\n");
                clearArray(&arr);
                return 0;
            default:
                printf("Invalid switcher. Please try again.\n");
        }
    }
}