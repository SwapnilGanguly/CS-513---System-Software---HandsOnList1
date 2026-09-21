/*
  16. Write a program to perform mandatory locking.
      a. Implement write lock 
      b. Implement read lock *
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    struct flock lock;

    fd = open("test.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    /*
      - Set up a read lock for the entire file.
      - F_RDLCK -> shared/read lock
     */
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
     
    // Wait until the read lock can be acquired.
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Read lock acquired.\n");
    printf("File is locked. Press Enter to release the lock...\n");
    getchar();

    // Remove the lock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Read lock released.\n");

    close(fd);
    return 0;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P16$ ./read_lock
Read lock acquired.
File is locked. Press Enter to release the lock...

Read lock released.

In another terminal:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P16$ ./read_lock
Read lock acquired.
File is locked. Press Enter to release the lock...

Read lock released.

*/
