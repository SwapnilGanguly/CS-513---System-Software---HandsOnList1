// 28. Write a program to get maximum and minimum real time priority

#include <stdio.h>
#include <sched.h>

int main() {
    int min_priority;
    int max_priority;

    // Find the minimum real-time priority for SCHED_RR.
    min_priority = sched_get_priority_min(SCHED_RR);

    if (min_priority == -1) {
        perror("sched_get_priority_min");
        return 1;
    }

    // Find the maximum real-time priority for SCHED_RR.
    max_priority = sched_get_priority_max(SCHED_RR);

    if (max_priority == -1) {
        perror("sched_get_priority_max");
        return 1;
    }

    printf("Scheduling Policy : SCHED_RR\n");
    printf("Minimum Priority  : %d\n", min_priority);
    printf("Maximum Priority  : %d\n", max_priority);

    return 0;
}

/*
Output:

wapnil@swapnil-Latitude-5400:~/SoftwareSystems/P28$ gcc 28.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P28$ ./a.out
Scheduling Policy : SCHED_RR
Minimum Priority  : 1
Maximum Priority  : 99

*/
