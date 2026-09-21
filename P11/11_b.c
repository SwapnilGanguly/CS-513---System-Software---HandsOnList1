/*
11. Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
    a. use dup
    b. use dup2 *
    c. use fcntl
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd1, fd2;

  
    fd1 = open("file_b.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);

    if (fd1 == -1) {
        perror("open");
        return 1;
    }

    printf("Original FD = %d\n", fd1);

    fd2 = dup2(fd1, 10); // dup2() lets us choose the new file descriptor number.

    if (fd2 == -1) {
        perror("dup2");
        close(fd1);
        return 1;
    }

    printf("Duplicated FD = %d\n", fd2);

    write(fd1, "Written using FD1\n", 18); // Writing using the original file descriptor.
 
    write(fd2, "Written using FD2\n", 18); // Write using the descriptor created by dup2().

    close(fd1);
    close(fd2);

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ gcc 11_b.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ ./a.out
Original FD = 3
Duplicated FD = 10
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ cat file_b.txt
Written using FD1
Written using FD2
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ gcc 11_b.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ ./a.out
Original FD = 3
Duplicated FD = 10
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ cat file_b.txt
Written using FD1
Written using FD2
Written using FD1
Written using FD2

*/
