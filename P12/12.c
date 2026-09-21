// 12. Write a program to find out the opening mode of a file. Use fcntl.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd;
    int flags;
    int mode;

    // Opening the file in Read Write mode
    fd = open("file.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    
    // F_GETFL retrieves the file status flags associated with the given file descriptor.
    flags = fcntl(fd, F_GETFL);

    // Check whether fcntl() was successful.
    if (flags == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    /*
     Extract only the access mode.
     O_ACCMODE masks out other flags such as O_CREAT, O_APPEND, O_TRUNC, etc.
     */
    mode = flags & O_ACCMODE;

    // Determine how the file was opened.
    if (mode == O_RDONLY) {
        printf("File is opened in READ ONLY mode.\n");
    }
    else if (mode == O_WRONLY) {
        printf("File is opened in WRITE ONLY mode.\n");
    }
    else if (mode == O_RDWR) {
        printf("File is opened in READ-WRITE mode.\n");
    }

    close(fd);

    return 0;
}

/*
Output

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P12$ ./a.out
File is opened in READ-WRITE mode.
*/
