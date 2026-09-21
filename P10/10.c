/*
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
    a. check the return value of lseek
    b. open the file with od and check the empty spaces in between the data.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd;
    ssize_t n;  // Signed integer to store the number of bytes read/written or -1 on error
    off_t position;
    
    /*
      off_t lseek(int fd, off_t offset, int whence);
      
      fd       - file descriptor
      offset   - how far to move
      whence   - reference point
      
      lseek() returns the resulting file offset from the beginning of the file.
    */
    
    fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write the first 10 bytes.
    n = write(fd, "ABCDEFGHIJ", 10);
    
    // Check whether all 10 bytes were written. 
    if (n != 10) {
        perror("write");
        close(fd);
        return 1;
    }

    // Move the file pointer 10 bytes forward from its current position.
    position = lseek(fd, 10, SEEK_CUR); // lseek() returns the new file offset on success else it returns -1

    // Check the return value of lseek(), as required by the question.
    if (position == (off_t)-1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("New file pointer position = %ld\n", (long)position);

    
    // Write another 10 bytes starting at byte 20.
    n = write(fd, "KLMNOPQRST", 10);

    // Check whether all 10 bytes were written. 
    if (n != 10) {
        perror("write");
        close(fd);
        return 1;
    }

    /*
     * Close the file after completing the operation.
     */
    close(fd);

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P10$ gcc 10.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P10$ ./a.out
New file pointer position = 20
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P10$ od -c test.txt
0000000   A   B   C   D   E   F   G   H   I   J  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   K   L   M   N   O   P   Q   R   S   T
0000036
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P10$ ls -l test.txt
-rw-r--r-- 1 swapnil swapnil 30 Sep 17 21:46 test.txt

*/
