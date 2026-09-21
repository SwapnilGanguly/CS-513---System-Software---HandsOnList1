// 7. Write a program to copy file1 into file2 ($cp file1 file2)

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd1, fd2;
    char buffer[1024];
    int n;

    fd1 = open("file1", O_RDONLY); // Open file1 in read-only mode.

    // Check whether file1 was opened successfully.
    if (fd1 == -1) {
        perror("Error opening file1");
        return 1;
    }

    fd2 = open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd2 == -1) {
        perror("Error opening file2");

        // Since file1 was already opened, close it before terminating the program.
        close(fd1);

        return 1;
    }

    /*
     * Read file1 in chunks of at most 1024 bytes.
     *
     * read() returns the actual number of bytes read.
     * When it returns 0, we have reached the end of file.
     */
    while ((n = read(fd1, buffer, sizeof(buffer))) > 0) {

        // Write exactly 'n' bytes into file2.
        if (write(fd2, buffer, n) != n) {
            perror("Error writing to file2");

            close(fd1);
            close(fd2);

            return 1;
        }
    }

    
    if (n == -1) {
        perror("Error reading file1");
    }

    close(fd1);
    close(fd2);

    return 0;
}

/* Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P7$ echo "This is file1." > file1
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P7$ gcc 7.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P7$ ./a.out
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P7$ cat file2
This is file1.

*/

