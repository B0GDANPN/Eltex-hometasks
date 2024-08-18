#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("main pid = %d, Parent pid = %d\n", getpid(), getppid());
    pid_t process1, process2;
    switch (process1 = fork())
    {
    case -1:
        perror("process1 fork error");
        exit(EXIT_FAILURE);
    case 0: // process1\
        printf("process1 pid = %d, Parent pid = %d\n", getpid(), getppid());
        pid_t process3, process4;
        switch (process3 = fork())
        {
        case -1:
            perror("process3 fork error");
            exit(EXIT_FAILURE);
        case 0: // process3
            printf("process3 pid = %d, Parent pid = %d\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        default:
            switch (process4 = fork())
            {
            case -1:
                perror("process4 fork error");
                exit(EXIT_FAILURE);
            case 0: // process4
                printf("process4 pid = %d, Parent pid = %d\n", getpid(), getppid());
                exit(EXIT_SUCCESS);
            }
            waitpid(process3, NULL, 0);
            waitpid(process4, NULL, 0);
        }
        exit(EXIT_SUCCESS);
    default:
        switch (process2 = fork())
        {
        case -1:
            perror("process2 fork error");
            exit(EXIT_FAILURE);
        case 0: // process2
            printf("process2 pid = %d, Parent pid = %d\n", getpid(), getppid());
            pid_t process5;
            switch (process5 = fork())
            {
            case -1:
                perror("process5 fork error");
                exit(EXIT_FAILURE);
            case 0: // process5
                printf("Process5 pid = %d, Parent pid = %d\n", getpid(), getppid());
                exit(EXIT_SUCCESS);
            default:
                waitpid(process5, NULL, 0);
            }
            exit(EXIT_SUCCESS);
        default:
            waitpid(process1, NULL, 0);
            waitpid(process2, NULL, 0);
            break;
        }
        break;
    }
    return 0;
}
