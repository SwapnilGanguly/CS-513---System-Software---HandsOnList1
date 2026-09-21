/* 
18. Write a program to perform Record locking.
    a. Implement write lock
    b. Implement read lock
    Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct record {
    int id;
    char name[20];
    int marks;
};

int main() {
    int fd;

    struct record r1 = {1, "Alice", 90};
    struct record r2 = {2, "Bob", 85};
    struct record r3 = {3, "Charlie", 95};

    // Create the file and remove any old contents.
    fd = open("records.dat", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write three records into the file.
    write(fd, &r1, sizeof(r1));
    write(fd, &r2, sizeof(r2));
    write(fd, &r3, sizeof(r3));

    printf("Three records created successfully.\n");

    close(fd);

    return 0;
}

/*
Output:
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P18$ gcc create_records.c -o create_records
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P18$ ./create_records
Three records created successfully.
*/
