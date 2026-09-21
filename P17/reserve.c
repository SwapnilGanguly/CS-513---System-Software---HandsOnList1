#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int ticket;
    struct flock lock;


    // Open the ticket file in read-write mode.
    fd = open("ticket.txt", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    /*
     * Create a write lock for the entire file.
     *
     * F_WRLCK  -> exclusive/write lock
     * SEEK_SET -> start from beginning of file
     * l_start=0 and l_len=0 -> entire file
     */
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    // F_SETLKW waits until the write lock is available.
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    // Read the current ticket number.
    if (read(fd, &ticket, sizeof(ticket)) != sizeof(ticket)) {
        perror("read");
        close(fd);
        return 1;
    }

    ticket++; // Increment the ticket number to reserve the next ticket.

    // Move the file pointer back to the beginning before writing the updated ticket number.
    lseek(fd, 0, SEEK_SET);

    
    // Store the updated ticket number.
    if (write(fd, &ticket, sizeof(ticket)) != sizeof(ticket)) {
        perror("write");
        close(fd);
        return 1;
    }

    //Print the newly reserved ticket number.
    printf("Ticket reserved successfully. Ticket number: %d\n", ticket);

    // Release the write lock.
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);

    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P17$ gcc init_ticket.c -o init_ticket
gcc reserve.c -o reserve
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P17$ ./init_ticket
Initial ticket number stored: 100
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P17$ ./reserve
Ticket reserved successfully. Ticket number: 101
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P17$ ./reserve
Ticket reserved successfully. Ticket number: 102
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P17$ ./reserve
Ticket reserved successfully. Ticket number: 103
*/
