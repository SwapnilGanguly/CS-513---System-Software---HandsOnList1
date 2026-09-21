// 22. Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    /*
    Create a child process.
    The child inherits the file descriptor.
     */
    pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd);
        return 1;
    }

    else if (pid == 0) {
        // Child writes to the file.
        write(fd, "Written by Child\n", 17);
    }

    else {
        //Parent writes to the same file.
        write(fd, "Written by Parent\n", 18);
    }

    // Both processes close their copy of the file descriptor.
    close(fd);

    return 0;
}

/*
Output: 
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P22$ gcc 22.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P22$ ./a.out
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P22$ cat output.txt
Written by Parent
Written by Child
*/
