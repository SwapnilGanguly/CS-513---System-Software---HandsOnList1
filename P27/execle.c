/*
27. Write a program to execute ls -Rl by the following system calls
    a. execl 
    b. execlp 
    c. execle *
    d. execv
    e. execvp
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    // Custom variable for ls
    char *env[] = {
        "MYVAR=Hello",
        NULL
    };

    /*
     - Execute /bin/ls with a custom environment.
     - e = custom environment
     - l = arguments are passed as a list
     */
    execle("/bin/ls", "ls", "-Rl", (char *)NULL, env);

    perror("execle");

    return 1;
}

/*
Output: 

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P27$ ./a.out
.:
total 28
-rwxrwxr-x 1 swapnil swapnil 16048 Sep 18 12:26 a.out
-rw-rw-r-- 1 swapnil swapnil   729 Sep 18 12:22 execl.c
-rw-rw-r-- 1 swapnil swapnil   527 Sep 18 12:25 execle.c
-rw-rw-r-- 1 swapnil swapnil   759 Sep 18 12:24 execlp.c

*/
