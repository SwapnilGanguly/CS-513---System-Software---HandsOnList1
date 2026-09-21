/*
  16. Write a program to perform mandatory locking.
      a. Implement write lock *
      b. Implement read lock 
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    struct flock lock;

    fd = open("test.txt", O_RDWR | O_CREAT, 0660);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    /*
      -Set up a write lock for the entire file.
     
      -F_WRLCK -> exclusive/write lock
      -SEEK_SET -> start from beginning of file
      -l_start = 0, l_len = 0 -> entire file
     */
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    // F_SETLKW waits until the lock can be acquired.
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Write lock acquired.\n");
    printf("File is locked. Press Enter to release the lock...\n");
    getchar();

    // Remove the lock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Write lock released.\n");

    close(fd);
    return 0;
}

/*
Output:
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P16$ ./write_lock
Write lock acquired.
File is locked. Press Enter to release the lock...

Write lock released.

In another terminal:

Write lock acquired.
File is locked. Press Enter to release the lock...

Write lock released.

*/
