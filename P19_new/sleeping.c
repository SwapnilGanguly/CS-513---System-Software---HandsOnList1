/* 19_new. Develop a program to initiate a process in distinct states: 
      a. running 
      b. sleeping * 
      c. stopped 
    Confirm the current state of the process using the relevant commands. 
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    printf("Process started. PID = %d\n", getpid());
    printf("Process is going to sleep for 60 seconds.\n");

    sleep(60);

    printf("Process woke up.\n");

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19_new$ ./a.out
Process started. PID = 30277
Process is going to sleep for 60 seconds.

In another terminal:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19_new$ ps -o pid,ppid,state,cmd -p 30277
    PID    PPID S CMD
  30277   29779 S ./a.out

*/
