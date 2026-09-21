// 29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).

#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main() {
    int policy;
    struct sched_param param;

    // Get the current scheduling policy of this process.
    policy = sched_getscheduler(0);

    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    // Display the current scheduling policy.
    printf("Current Scheduling Policy: ");

    if (policy == SCHED_OTHER)
        printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO)
        printf("SCHED_FIFO\n");
    else if (policy == SCHED_RR)
        printf("SCHED_RR\n");
    else
        printf("Unknown\n");

    // Set a valid real-time priority. Priority 10 is within the usual 1-99 range.
    param.sched_priority = 10;

    // Change the scheduling policy to SCHED_FIFO.
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Scheduling policy changed to SCHED_FIFO.\n");

    // Get the policy again to verify the change.
    policy = sched_getscheduler(0);

    if (policy == SCHED_FIFO)
        printf("New Scheduling Policy: SCHED_FIFO\n");

    // Now change the policy to SCHED_RR.
    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Scheduling policy changed to SCHED_RR.\n");

    // Verify the new scheduling policy.
    policy = sched_getscheduler(0);

    if (policy == SCHED_RR)
        printf("New Scheduling Policy: SCHED_RR\n");

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P29$ gcc 29.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P29$ sudo ./a.out
Current Scheduling Policy: SCHED_OTHER
Scheduling policy changed to SCHED_FIFO.
New Scheduling Policy: SCHED_FIFO
Scheduling policy changed to SCHED_RR.
New Scheduling Policy: SCHED_RR

*/
