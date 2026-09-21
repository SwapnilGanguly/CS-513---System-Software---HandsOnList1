/*
27. Write a program to execute ls -Rl by the following system calls
    a. execl 
    b. execlp *
    c. execle
    d. execv
    e. execvp
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    /*
     - Execute ls using the PATH environment variable.
     - p = searches for "ls" in PATH.
     - l = arguments are passed as a list.
     */
    execlp("ls", "ls", "-Rl", (char *)NULL);

    perror("execlp");

    return 1;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P27$ gcc execlp.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P27$ ./a.out
.:
total 24
-rwxrwxr-x 1 swapnil swapnil 16000 Sep 18 12:23 a.out
-rw-rw-r-- 1 swapnil swapnil   729 Sep 18 12:22 execl.c
-rw-rw-r-- 1 swapnil swapnil   436 Sep 18 12:23 execlp.c

*/
