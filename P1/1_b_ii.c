/*
1. Create the following types of a files using (i) shell command (ii) system call
    a. soft link (symlink system call)
    b. hard link (link system call) *
    c. FIFO (mkfifo Library Function or mknod system call)
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    if (link("original.txt", "hardlink.txt") == -1) {
        perror("link");
        return 1;
    }

    printf("Hard link created successfully.\n");

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P1$ ls
1_a_i.txt  1_a_ii.c  1_b_ii.c  a.out  original.txt  softlink.txt
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P1$ gcc 1_b_ii.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P1$ ./a.out
Hard link created successfully.

*/
