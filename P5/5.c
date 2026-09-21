/* 
Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd[5];

    fd[0] = open("file1.txt", O_CREAT | O_RDWR, 0644);
    fd[1] = open("file2.txt", O_CREAT | O_RDWR, 0644);
    fd[2] = open("file3.txt", O_CREAT | O_RDWR, 0644);
    fd[3] = open("file4.txt", O_CREAT | O_RDWR, 0644);
    fd[4] = open("file5.txt", O_CREAT | O_RDWR, 0644);


    for (int i = 0; i < 5; i++) {
        if (fd[i] == -1) {
            perror("open");
            return 1;
        }

        printf("file%d.txt -> File Descriptor = %d\n", i + 1, fd[i]);
    }

    /*
     * Infinite loop.
     *
     * We intentionally do NOT close the files here.
     * Therefore, their file descriptors remain in
     * /proc/<PID>/fd/.
     */

    while (1) {
        sleep(1);
    }

    return 0;
}

/*
Output: 

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P5$ gcc 5.c
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P5$ ./a.out &
[2] 24067
file1.txt -> File Descriptor = 3
file2.txt -> File Descriptor = 4
file3.txt -> File Descriptor = 5
file4.txt -> File Descriptor = 6
file5.txt -> File Descriptor = 7
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P5$ ls -l /proc/24067/fd
total 0
lrwx------ 1 swapnil swapnil 64 Sep 17 20:41 0 -> /dev/pts/0
lrwx------ 1 swapnil swapnil 64 Sep 17 20:41 1 -> /dev/pts/0
lrwx------ 1 swapnil swapnil 64 Sep 17 20:41 2 -> /dev/pts/0
lrwx------ 1 swapnil swapnil 64 Sep 17 20:41 3 -> /home/swapnil/SoftwareSystems/P5/file1.txt
lrwx------ 1 swapnil swapnil 64 Sep 17 20:41 4 -> /home/swapnil/SoftwareSystems/P5/file2.txt
lrwx------ 1 swapnil swapnil 64 Sep 17 20:41 5 -> /home/swapnil/SoftwareSystems/P5/file3.txt
lrwx------ 1 swapnil swapnil 64 Sep 17 20:41 6 -> /home/swapnil/SoftwareSystems/P5/file4.txt
lrwx------ 1 swapnil swapnil 64 Sep 17 20:41 7 -> /home/swapnil/SoftwareSystems/P5/file5.txt

*/
