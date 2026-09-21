/*
27. Write a program to execute ls -Rl by the following system calls
    a. execl 
    b. execlp 
    c. execle 
    d. execv
    e. execvp *
*/


#include <stdio.h>
#include <unistd.h>

int main() {

    // Arguments are stored in an array.
    char *args[] = {
        "ls",
        "-Rl",
        NULL
    };

    /*
     - Execute ls by searching for it in PATH.
     - p = searches PATH
     - v = arguments are passed as an array
     */
    execvp("ls", args);

    perror("execvp");

    return 1;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P27$ gcc execvp.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P27$ ./a.out
.:
total 36
-rwxrwxr-x 1 swapnil swapnil 16048 Sep 18 12:31 a.out
-rw-rw-r-- 1 swapnil swapnil   729 Sep 18 12:22 execl.c
-rw-rw-r-- 1 swapnil swapnil   842 Sep 18 12:26 execle.c
-rw-rw-r-- 1 swapnil swapnil   759 Sep 18 12:24 execlp.c
-rw-rw-r-- 1 swapnil swapnil   908 Sep 18 12:30 execv.c
-rw-rw-r-- 1 swapnil swapnil   510 Sep 18 12:31 execvp.c

*/
