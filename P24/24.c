// 24. Write a program to create an orphan process.

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Create a child process.
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    else if (pid == 0) {
        // Child sleeps so that the parent can terminate first.
        printf("Child: PID = %d\n", getpid());
        printf("Child: Initial Parent PID = %d\n", getppid());

        sleep(10);
        
        // getppid() returns the current parent PID.
        // After the parent terminates, the child becomes an orphan and gets adopted by another process.
        printf("Child: New Parent PID = %d\n", getppid());
    }

    else {
        /*
          -Parent exits immediately.
          -This makes the child an orphan.
         */
        printf("Parent: PID = %d\n", getpid());
        printf("Parent exiting...\n");
        return 0;
    }

    return 0;
}


/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P24$ ./a.out
Parent: PID = 10926
Parent exiting...
Child: PID = 10927
Child: Initial Parent PID = 10926
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P24$ Child: New Parent PID = 3447

*/
