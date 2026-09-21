/*
1. Create the following types of a files using (i) shell command (ii) system call
    a. soft link (symlink system call) *
    b. hard link (link system call)
    c. FIFO (mkfifo Library Function or mknod system call)
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    if (symlink("original.txt", "softlink.txt") == -1) {
        perror("symlink");
        return 1;
    }

    printf("Soft link created successfully.\n");

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P1$ gcc 1_a_ii.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P1$ ./a.out
symlink: File exists

*/
