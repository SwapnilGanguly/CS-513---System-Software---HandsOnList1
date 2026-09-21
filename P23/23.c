// 23. Write a program to create a Zombie state of the running program.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a child process.
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    else if (pid == 0) {
        /*
         -Child exits immediately.
         -Its process entry remains as a zombie because the parent has not called wait() yet.
         */
        printf("Child process exiting. PID = %d\n", getpid());
        return 0;
    }

    else {
        /*
         -Parent does NOT call wait().
         -It stays alive for 30 seconds, giving us time to observe the child in zombie state.
         */
        printf("Parent PID = %d\n", getpid());
        printf("Child PID  = %d\n", pid);
        printf("Parent sleeping for 30 seconds...\n");

        sleep(30);

        // Parent terminates without collecting the child.
        printf("Parent exiting.\n");
    }

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P23$ gcc 23.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P23$ ./a.out
Parent PID = 40191
Child PID  = 40192
Parent sleeping for 30 seconds...
Child process exiting. PID = 40192
Parent exiting.

In another terminal:
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P23$ ps -el | grep 40192
1 Z  1000   40192   40191  0  80   0 -     0 -      pts/0    00:00:00 a.out

*/
