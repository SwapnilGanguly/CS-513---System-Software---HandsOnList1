/*
9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {

    struct stat st;
    char *filename = "file1.txt";

    if (stat(filename, &st) == -1) {     // Get file metadata
        perror("stat");
        return 1;
    }

    printf("Inode number       : %lu\n", st.st_ino);       // Inode number
    printf("Hard links         : %lu\n", st.st_nlink);     // Number of hard links
    printf("UID                : %u\n", st.st_uid);        // User ID
    printf("GID                : %u\n", st.st_gid);        // Group ID
    printf("Size               : %ld bytes\n", st.st_size); // File size
    printf("Block size         : %ld bytes\n", st.st_blksize); // Block size
    printf("Number of blocks   : %ld\n", st.st_blocks);    // Number of blocks
    printf("Last access        : %s", ctime(&st.st_atime)); // Last access time
    printf("Last modification  : %s", ctime(&st.st_mtime)); // Last modification
    printf("Last status change : %s", ctime(&st.st_ctime)); // Last metadata change

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P9$ echo "Hello" > file1.txt
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P9$ gcc 9.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P9$ ./a.out
Inode number       : 3557611
Hard links         : 1
UID                : 1000
GID                : 1000
Size               : 6 bytes
Block size         : 4096 bytes
Number of blocks   : 8
Last access        : Thu Sep 17 21:34:53 2026
Last modification  : Thu Sep 17 21:34:53 2026
Last status change : Thu Sep 17 21:34:53 2026


*/
