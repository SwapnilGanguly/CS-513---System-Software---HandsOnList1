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

    // Open the file in read-only mode.
    fd = open("records.dat", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Calculate the starting position of the record.
    off_t offset = (record_no - 1) * sizeof(struct record);

    /*
     Set a read lock only on the selected record.
     F_RDLCK allows multiple readers to access the same record simultaneously.
     */
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = sizeof(struct record);

    // Wait until the record can be read safely.
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Read lock acquired for record %d.\n", record_no);

    // Move to the selected record and read it.
    lseek(fd, offset, SEEK_SET);
    read(fd, &r, sizeof(r));

    printf("Record: ID=%d Name=%s Marks=%d\n",
           r.id, r.name, r.marks);

    // Release the read lock.
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Read lock released.\n");

    close(fd);

    return 0;
}

/*
Output: 
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P18$ gcc read_records.c -o read_records
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P18$ ./write_records 3
Write lock acquired for record 3.
Current: ID=3 Name=Charlie Marks=95
Updated: ID=3 Name=Charlie Marks=100
Write lock released.

*/
