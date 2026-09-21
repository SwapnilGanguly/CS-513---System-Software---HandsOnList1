/*
11. Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
    a. use dup *
    b. use dup2
    c. use fcntl
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd1, fd2;

    fd1 = open("file.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);

    if (fd1 == -1) {
        perror("open");
        return 1;
    }

    printf("Original FD = %d\n", fd1);


    fd2 = dup(fd1); // dup() returns the lowest available file descriptor. The new descriptor refers to the same open file description as fd1.

    if (fd2 == -1) {
        perror("dup");
        close(fd1);
        return 1;
    }

    printf("Duplicated FD = %d\n", fd2);

    write(fd1, "Written using FD1\n", 18); // Writing using the original file descriptor.

    // Writing using the duplicated file descriptor.
    write(fd2, "Written using FD2\n", 18);

    close(fd1);
    close(fd2);

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ gcc 11.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ ./a.out
Original FD = 3
Duplicated FD = 4
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ cat file.txt
Written using FD1
Written using FD2
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ ./a.out
Original FD = 3
Duplicated FD = 4
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ cat file.txt
Written using FD1
Written using FD2
Written using FD1
Written using FD2

*/
