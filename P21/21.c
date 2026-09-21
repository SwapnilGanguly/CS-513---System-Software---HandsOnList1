// 21. Write a program, call fork and print the parent and child process id.

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // fork() creates a new child process.
    pid = fork();

    if (pid < 0) {
        //fork() failed.
        perror("fork");
        return 1;
    }

    else if (pid == 0) {

        // This code executes only in the child process.
        printf("Child Process:\n");
        printf("Child PID  = %d\n", getpid());
        printf("Parent PID = %d\n", getppid());
    }

    else {
        //  This code executes only in the parent process.
        // pid contains the child's process ID.
        printf("Parent Process:\n");
        printf("Parent PID = %d\n", getpid());
        printf("Child PID  = %d\n", pid);
    }

    return 0;
}

/*
Output: 
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P21$ gcc 21.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P21$ ./a.out
Parent Process:
Parent PID = 39514
Child PID  = 39515
Child Process:
Child PID  = 39515
Parent PID = 39514

*/
