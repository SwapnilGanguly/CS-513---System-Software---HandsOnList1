/* 19_new. Develop a program to initiate a process in distinct states: 
      a. running *
      b. sleeping 
      c. stopped 
    Confirm the current state of the process using the relevant commands. 
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    printf("Process started. PID = %d\n", getpid());
    printf("Process is continuously running.\n");

    /*
     - Infinite loop keeps the process continuously active.
     - sleep not used here because sleep() would put the process into the sleeping state.
     */
    while (1) {
        // Perform some computation so the process continuously uses the CPU.
        volatile long i;

        for (i = 0; i < 100000000; i++);
    }

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19_new$ gcc running.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19_new$ ./a.out
Process started. PID = 29839
Process is continuously running.

In another terminal: 

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19_new$ ps -o pid,ppid,state,cmd -p 29839
    PID    PPID S CMD
  29839   29779 R ./a.out

*/
