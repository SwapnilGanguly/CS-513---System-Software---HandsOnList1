// 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

#include <unistd.h>

int main() {

    char buffer[100];
    int n;

    n = read(0, buffer, sizeof(buffer));

    if (n < 0) {
        return 1;
    }

    write(1, buffer, n);

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P6$ gcc 6.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P6$ ./a.out
Hi! This is Swapnil Ganguly.
Hi! This is Swapnil Ganguly.

*/
