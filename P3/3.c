/*
3 Write a program to create a file and print the file descriptor value. Use creat ( ) system cal
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = creat("test.txt", 0644);

    if (fd == -1) {
        perror("creat");
        return 1;
    }

    printf("File descriptor = %d\n", fd);

    close(fd);

    return 0;
}

/*
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P3$ gcc 3.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P3$ ./a.out
File descriptor = 3
*/
