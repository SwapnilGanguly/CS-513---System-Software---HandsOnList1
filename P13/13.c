// 13.Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds; // set of file descriptors that we want to monitor for read readiness
    struct timeval timeout;
    int result;

    FD_ZERO(&readfds); // clears the descriptor set.
    FD_SET(STDIN_FILENO, &readfds); // adds descriptor for STDIN , i.e., 0 to the set.

    // Set timeout to 10 seconds.
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    
    //Wait until STDIN is ready for reading or the 10-second timeout expires.
    result = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select");
        return 1;
    }

   // select() returns 0 when the timeout expires without any data becoming available.      
    if (result == 0) {
        printf("No data available on STDIN within 10 seconds.\n");
    }
    else if (FD_ISSET(STDIN_FILENO, &readfds)) {
        printf("Data is available on STDIN within 10 seconds.\n");
    }

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P13$ gcc 13.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P13$ ./a.out
No data available on STDIN within 10 seconds.
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P13$ ./a.out
Hello!
Data is available on STDIN within 10 seconds.
*/
