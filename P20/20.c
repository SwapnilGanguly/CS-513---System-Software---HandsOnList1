// 20. Find out the priority of your running program. Modify the priority with nice command.

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int priority;

    /*
      Get the nice value of the current process.
      PRIO_PROCESS means we are referring to a process.
      0 means the current process.
     */
    priority = getpriority(PRIO_PROCESS, 0);

    printf("Process ID: %d\n", getpid());
    printf("Current nice value: %d\n", priority);

    // Keep the program running so that we can modify its priority from another terminal.
    printf("Program is running. Press Ctrl+C to stop.\n");

    while (1) {
        sleep(1);
    }

    return 0;
}

/*
Output:
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P20$ gcc 20.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P20$ ./a.out
Process ID: 38882
Current nice value: 0
Program is running. Press Ctrl+C to stop.


In a different terminal: 

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P20$ ps -o pid,ni,cmd -p 38882
    PID  NI CMD
  38882   0 ./a.out
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P20$ renice 5 -p 38882
38882 (process ID) old priority 0, new priority 5
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P20$ ps -o pid,ni,cmd -p 38882
    PID  NI CMD
  38882   5 ./a.out

*/
