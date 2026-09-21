#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct record {
    int id;
    char name[20];
    int marks;
};

int main(int argc, char *argv[]) {
    int fd;
    int record_no;
    struct record r;
    struct flock lock;


    // Take the record number from the command line.
    if (argc != 2) {
        printf("Usage: %s <record_number>\n", argv[0]);
        return 1;
    }

    record_no = atoi(argv[1]);

    // Open the file in read-write mode.
    fd = open("records.dat", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    /*
     Calculate the starting position of the record.
     Record numbers are 1, 2, 3...
     */
    off_t offset = (record_no - 1) * sizeof(struct record);

    // Set a write lock only on the selected record.
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = sizeof(struct record);
     
    // Wait until the selected record becomes available.
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Write lock acquired for record %d.\n", record_no);

    // Move to the selected record and read it.
    lseek(fd, offset, SEEK_SET);
    read(fd, &r, sizeof(r));

    printf("Current: ID=%d Name=%s Marks=%d\n",
           r.id, r.name, r.marks);

    // Modify the record.
    r.marks += 5;

    // Move back to the beginning of the record and write the modified record.
    lseek(fd, offset, SEEK_SET);
    write(fd, &r, sizeof(r));

    printf("Updated: ID=%d Name=%s Marks=%d\n",
           r.id, r.name, r.marks);

    // Release the record lock.
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Write lock released.\n");

    close(fd);

    return 0;
}

/*
Output:
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P18$ gcc write_records.c -o write_records
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P18$ ./write_records 2
Write lock acquired for record 2.
Current: ID=2 Name=Bob Marks=85
Updated: ID=2 Name=Bob Marks=90
Write lock released.
*/
