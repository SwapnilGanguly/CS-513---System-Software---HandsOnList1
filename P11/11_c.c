/*
11. Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
    a. use dup
    b. use dup2 
    c. use fcntl *
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd1, fd2;

    
    fd1 = open("file_c.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);

    if (fd1 == -1) {
        perror("open");
        return 1;
    }

    printf("Original FD = %d\n", fd1);
     
    /*
      F_DUPFD -> duplicate the file descriptor
      0        -> new FD must be >= 0
      
      fcntl() returns the newly created file descriptor.
    */
    fd2 = fcntl(fd1, F_DUPFD, 0);

    if (fd2 == -1) {
        perror("fcntl");
        close(fd1);
        return 1;
    }

    printf("Duplicated FD = %d\n", fd2);

    write(fd1, "Written using FD1\n", 18); // Write using the original descriptor.
    
    write(fd2, "Written using FD2\n", 18); // Write using the duplicated descriptor.

    close(fd1);
    close(fd2);

    return 0;
}

/*
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ gcc 11_c.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ ./a.out
Original FD = 3
Duplicated FD = 4
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ cat file_c.txt
Written using FD1
Written using FD2
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ gcc 11_c.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ ./a.out
Original FD = 3
Duplicated FD = 4
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P11$ cat file_c.txt
Written using FD1
Written using FD2
Written using FD1
Written using FD2

*/
