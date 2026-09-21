/*
8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
   Close the file when end of file is reached 
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd;
    char ch;
    char line[1024];
    int i = 0;
    int n;

    fd = open("file1", O_RDONLY);
    
    if (fd == -1) {
        perror("open");
        return 1;
    }

    
    //Read one character at a time until EOF.
    while ((n = read(fd, &ch, 1)) > 0) {

        line[i++] = ch;

        
        if (ch == '\n') {

            // Display complete line in STDOUT
            write(1, line, i);

            
            // Reset the index to start storing the next line.
            i = 0;
        }
    }

    
    // If the file does not end with '\n', there may still be characters left in the buffer. Display them.
    if (i > 0) {
        write(1, line, i);
    }

    close(fd);

    return 0;
}

/*
Output:
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P8$ echo "Hi!" > file1
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P8$ echo "I am Swapnil Ganguly." >> file1
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P8$ gcc 8.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P8$ ./a.out
Hi!
I am Swapnil Ganguly.

*/
