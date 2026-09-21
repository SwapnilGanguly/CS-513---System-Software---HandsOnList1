// 25. Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid[3];
    int status;

    // Create three child processes.
    for (int i = 0; i < 3; i++) {

        pid[i] = fork();

        if (pid[i] < 0) {
            perror("fork");
            return 1;
        }

        if (pid[i] == 0) {
            // Child process prints its PID and then exits.
            printf("Child %d: PID = %d\n", i + 1, getpid());

            // Sleep for different amounts of time so that the children terminate at different times.
            sleep((i + 1) * 2);

            printf("Child %d exiting.\n", i + 1);
            return 0;
        }
    }

    // Parent waits specifically for Child 2.
    // pid[1] contains the PID of Child 2.
    printf("Parent: Waiting for Child 2 (PID = %d)\n", pid[1]);

    if (waitpid(pid[1], &status, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    printf("Parent: Child 2 has terminated.\n");

    // Wait for the remaining children so that they do not remain as zombies.
    waitpid(pid[0], &status, 0);
    waitpid(pid[2], &status, 0);

    printf("Parent: All children have terminated.\n");

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P25$ gcc 25.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P25$ ./a.out
Child 1: PID = 40942
Child 2: PID = 40943
Parent: Waiting for Child 2 (PID = 40943)
Child 3: PID = 40944
Child 1 exiting.
Child 2 exiting.
Parent: Child 2 has terminated.
Child 3 exiting.
Parent: All children have terminated.

*/
