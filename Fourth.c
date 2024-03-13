//
// Created by bogdan on 12.03.24.
//
#include <stdio.h>
#include <string.h>

#define MAX_ABONENTS 100
#define SIZE_NAME 10
#define SIZE_TEL 10

struct abonent {
    char name[SIZE_NAME];
    char second_name[SIZE_NAME];
    char tel[SIZE_TEL];
};

static struct abonent directory[MAX_ABONENTS];
int count_abonent = 0;

void add_subscriber() {
    if (count_abonent >= MAX_ABONENTS) {
        printf("Directory overflow.\n");
        return;
    }
    printf("Enter name: ");
    fgets(directory[count_abonent].name, sizeof(directory[count_abonent].name), stdin);
    printf("Enter second name: ");
    fgets(directory[count_abonent].second_name, sizeof(directory[count_abonent].second_name), stdin);
    printf("Enter telephone number: ");
    fgets(directory[count_abonent].tel, sizeof(directory[count_abonent].tel), stdin);
    count_abonent++;
}

void delete_subscriber() {
    char name[SIZE_NAME];
    printf("Enter name of the subscriber to delete: ");
    fgets(name, sizeof(name), stdin);

    for (int i = 0; i < count_abonent; i++) {
        if (strcmp(directory[i].name, name) == 0) {
            memset(&directory[i], 0, sizeof(directory[i]));
            printf("Subscriber deleted successfully.\n");
            return;
        }
    }
    printf("Subscriber not found.\n");
}

void search_abonents() {
    char name[SIZE_NAME];
    printf("Enter the name to search: ");
    fgets(name, sizeof(name), stdin);
    int found = 0;
    for (int i = 0; i < count_abonent; i++) {
        if (strcmp(directory[i].name, name) == 0) {
            printf("Name: %s\n, Second Name: %s\n, Telephone: %s\n",
                   directory[i].name,
                   directory[i].second_name,
                   directory[i].tel);
            found = 1;
        }
    }
    if (!found) {
        printf("No abonents found with the given name.\n");
    }
}

void display_all_abonents() {
    if (count_abonent == 0) {
        printf("No abonents in the directory.\n");
        return;
    }

    for (int i = 0; i < count_abonent; i++) {
        if (directory[i].name[0] != '\0') {
            printf("Name: %s\n, Second Name: %s\n, Telephone: %s\n",
                   directory[i].name,
                   directory[i].second_name,
                   directory[i].tel);
        }
    }
}

int main() {
    int switcher;
    while (1) {
        printf("\n--- Subscription Directory Menu ---\n");
        printf("1) Add a subscriber\n");
        printf("2) Delete the subscriber\n");
        printf("3) Search for abonents by name\n");
        printf("4) Output of all records\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &switcher);
        getchar();
        switch (switcher) {
            case 1:
                add_subscriber();
                break;
            case 2:
                delete_subscriber();
                break;
            case 3:
                search_abonents();
                break;
            case 4:
                display_all_abonents();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid switcher. Please try again.\n");
        }
    }
}