// 4.Write a program to open an existing file with read write mode. Try O_EXCL flag also.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = open("test.txt", O_RDWR| O_CREAT | O_EXCL, 0644);
    // If we use O_CREAT | O_EXCL, it works exclusively, meaning fd will return -1 due to file being present, else if file does not exist, it creates new file and return fd. If used O_CREAT without O_EXCL, it will return fd whether file is present or not

    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("File opened successfully.\n");
    printf("File descriptor = %d\n", fd);

    close(fd);

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P4$ gcc 4.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P4$ ./a.out
open: No such file or directory
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P4$ gcc 4.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P4$ ./a.out
File opened successfully.
File descriptor = 3
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P4$ ./a.out
open: File exists

*/
