/*
1. Create the following types of a files using (i) shell command (ii) system call
    a. soft link (symlink system call)
    b. hard link (link system call)
    c. FIFO (mkfifo Library Function or mknod system call) *
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    if (mkfifo("myfifo", 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO created successfully.\n");

    return 0;
}

/*
Output:
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P1$ gcc 1_c_ii.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P1$ ./a.out
FIFO created successfully.
swapnil@swapnil-Latitude-5400:~/SoftwareSystemssswapnil@swapnil-Latitude-5400:~/SoftwareSystems/P1$ ls
1_a_i.txt  1_b_ii.c  hardlink.txt   original.txt
1_a_ii.c   1_c_ii.c  hardlink1.txt  softlink.txt

*/
