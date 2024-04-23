//
// Created by bogdan on 12.03.24.
//
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>

/*
gcc add.c -fpic -c
gcc sub.c -fpic -c
gcc mul.c -fpic -c
gcc myDiv.c -fpic -c
gcc --shared add.o sub.o mul.o myDiv.o -o libcalc.so
gcc main.c -o main -ldl

*/
void handleCheck(void *ptr) {
    if (ptr == NULL) {
        printf("%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
}

const int sizeInput = 100;

int main() {
    int switcher, a, b;
    void *handle = NULL;
    int (*add)(int, int)=NULL, (*sub)(int, int)=NULL, (*mul)(int, int)=NULL, (*div)(int, int)=NULL;
    char *error = NULL;
    char lineLibraries[sizeInput];
    printf("\n Enter names of operation, you must enter 0 in the end input\n");
    handle = dlopen("./libcalc.so", RTLD_LAZY);
    handleCheck(handle);
    fgets(lineLibraries, sizeInput, stdin);
    while (strcmp(lineLibraries, "0\n")!=0) {
        if (strcmp(lineLibraries,"add\n") == 0 && !add) {
            add = dlsym(handle, "add");
        } else if (strcmp(lineLibraries,"sub\n") == 0 && !sub) {
            sub = dlsym(handle, "sub");
        } else if (strcmp(lineLibraries,"mul\n") == 0 && !mul) {
            mul = dlsym(handle, "mul\n");
        } else if (strcmp(lineLibraries,"div\n") == 0 && !div) {
            div = dlsym(handle, "div");
        } else {
            printf("Incorrect name operation{add,sub,mul,div}\n");
        }
        error = dlerror();
        if (error != NULL) {
            printf("%s dlopen||dlsym error\n", error);
            exit(EXIT_FAILURE);
        }
        fgets(lineLibraries, sizeInput, stdin);
    }
    while (1) {
        printf("\n--- Calculator Menu ---\n");
        if (add) printf("1) Add\n");
        if (sub) printf("2) Sub\n");
        if (mul)printf("3) Mul\n");
        if (div) printf("4) Div\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &switcher);
        switch (switcher) {
            case 1:
                scanf("%d %d", &a, &b);
                printf("%d\n", add(a, b));
                break;
            case 2:
                scanf("%d %d", &a, &b);
                printf("%d\n", sub(a, b));
                break;
            case 3:
                scanf("%d %d", &a, &b);
                printf("%d\n", mul(a, b));
                break;
            case 4:
                scanf("%d %d", &a, &b);
                if (b == 0) {
                    printf("Second value must be non zero\n");
                    break;
                }
                printf("%d\n", div(a, b));
                break;
            case 5:
                printf("Exiting program.\n");
                dlclose(handle);
                return 0;
            default:
                printf("Invalid switcher. Please try again.\n");
        }
    }
}