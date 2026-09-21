/* 19_new. Develop a program to initiate a process in distinct states: 
      a. running 
      b. sleeping  
      c. stopped *
    Confirm the current state of the process using the relevant commands. 
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    printf("Process started. PID = %d\n", getpid());
    printf("Process is running. Press Ctrl+C only after testing.\n");

    // Keeping the process alive.
    while (1) {
        sleep(1);
    }

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19_new$ ./a.out
Process started. PID = 30565
Process is running. Press Ctrl+C only after testing.

[1]+  Stopped                    ./a.out

In another terminal:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19_new$ kill -STOP 30565
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19_new$ ps -o pid,ppid,state,cmd -p 30565
    PID    PPID S CMD
  30565   30545 T ./a.out
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19_new$ kill -CONT 30565
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19_new$ ps -o pid,ppid,state,cmd -p 30565
    PID    PPID S CMD
  30565   30545 S ./a.out  

*/
