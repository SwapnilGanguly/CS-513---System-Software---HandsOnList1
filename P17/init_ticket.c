/*
17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int ticket = 100;

    /*
     Create/open the ticket file.
     O_TRUNC removes the old contents so that the ticket number starts again from 100.
     */
    fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Store the initial ticket number in the file.
    if (write(fd, &ticket, sizeof(ticket)) != sizeof(ticket)) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Initial ticket number stored: %d\n", ticket);

    close(fd);

    return 0;
}
