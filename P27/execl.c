/*
27. Write a program to execute ls -Rl by the following system calls
    a. execl *
    b. execlp
    c. execle
    d. execv
    e. execvp
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    /*
     - Execute /bin/ls with arguments "ls", "-Rl".
     - l = arguments are passed as a list.
     */
    execl("/bin/ls", "ls", "-Rl", (char *)NULL);

    perror("execl");

    return 1;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P27$ gcc execl.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P27$ ./a.out
.:
total 20    // total disk blocks used by the files listed in that directory,
-rwxrwxr-x 1 swapnil swapnil 16000 Sep 18 12:16 a.out
-rw-rw-r-- 1 swapnil swapnil   394 Sep 18 12:16 execl.c

*/
