#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t сhildPid, ownPid, parentPid;
    switch (сhildPid = fork())
    {
    case -1:
        perror("fork error");
        exit(EXIT_FAILURE);
    case 0: // child
        ownPid = getpid();
        parentPid = getppid();
        printf("ownPid = %d\n", ownPid);
        printf("parentPid = %d\n", parentPid);
        exit(EXIT_SUCCESS);
    default:
        int childStatus;
        ownPid = getpid();
        parentPid = getppid();
        printf("ownPid = %d\n", ownPid);
        printf("parentPid = %d\n", parentPid);
        wait(&childStatus);
        printf("child exit status = %d\n", WEXITSTATUS(childStatus));
        break;
    }
    return 0;
}
