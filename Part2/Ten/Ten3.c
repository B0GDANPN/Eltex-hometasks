#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_COUNT 100

void parse_input(char* input, char** args)
{
    int i = 0;
    char* token = strtok(input, " ");
    while (token != NULL && i < MAX_ARG_COUNT)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // Обозначаем конец массива аргументов
}

int main()
{
    char input[MAX_INPUT_SIZE];
    char* args[MAX_ARG_COUNT];
    int status;

    while (1)
    {
        printf("mysh> ");
        if (!fgets(input, MAX_INPUT_SIZE, stdin)) break;

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0)
            break;

        parse_input(input, args);
        pid_t child;
        switch (child = fork())
        {
        case -1:
            perror("fork error");
            exit(EXIT_FAILURE);
        case 0:
            if (execvp(args[0], args) < 0)
            {
                perror("execvp error");
                exit(EXIT_FAILURE);
            }
        default:
            waitpid(child, &status, 0);
            printf("exit child status: %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}
