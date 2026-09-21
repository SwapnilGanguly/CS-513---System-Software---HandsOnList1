// 19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.

#include <stdio.h>
#include <unistd.h>

/*
  Read the CPU Time Stamp Counter (TSC).
  RDTSC returns the current CPU cycle count.
*/
unsigned long long rdtsc() {
    unsigned int low, high;

    // EDX:EAX contains the 64-bit TSC value.
    __asm__ volatile (
        "rdtsc"
        : "=a"(low), "=d"(high)
    );

    return ((unsigned long long)high << 32) | low;
}

int main() {
    unsigned long long start, end, cycles;
    pid_t pid;

    // Read TSC before executing getpid().
    start = rdtsc();

    // System call whose execution time we want to measure.
    pid = getpid();

    // Read TSC after executing getpid().
    end = rdtsc();
    
    // Difference gives the approximate number of CPU cycles taken.
    cycles = end - start;

    printf("Process ID = %d\n", pid);
    printf("Time taken by getpid() = %llu CPU cycles\n", cycles);

    return 0;
}

/*
Output:
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19$ gcc 19.c 
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P19$ ./a.out
Process ID = 38448
Time taken by getpid() = 21042 CPU cycles

*/
