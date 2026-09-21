/*
14. Write a program to find the type of a file.
    a. Input should be taken from command line.
    b. program should be able to identify any type of a file
*/

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat st;

    
    // Check whether a filename was provided through the command line.
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // stat() gets information about the given file.
    if (stat(argv[1], &st) == -1) {
        perror("stat");
        return 1;
    }

    
    if (S_ISREG(st.st_mode))
        printf("%s : Regular file\n", argv[1]);

    else if (S_ISDIR(st.st_mode))
        printf("%s : Directory\n", argv[1]);

    else if (S_ISCHR(st.st_mode))
        printf("%s : Character device\n", argv[1]);

    else if (S_ISBLK(st.st_mode))
        printf("%s : Block device\n", argv[1]);

    else if (S_ISFIFO(st.st_mode))
        printf("%s : FIFO (Named Pipe)\n", argv[1]);

    else if (S_ISLNK(st.st_mode))
        printf("%s : Symbolic link\n", argv[1]);

    else if (S_ISSOCK(st.st_mode))
        printf("%s : Socket\n", argv[1]);

    else
        printf("%s : Unknown file type\n", argv[1]);

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P14$ echo "Hello!" > file1.txt
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P14$ gcc 14.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P14$ ./a.out file1.txt
file1.txt : Regular file
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P14$ ./a.out /home
/home : Directory

*/
