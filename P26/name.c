/*
  26. Write a program to execute an executable program.
      a. use some executable program
      b. pass some input to an executable program. (for example execute an executable of $./a.out name) *
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

    // argv[1] contains the name passed from the command line.
    if (argc != 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    printf("Hello, %s!\n", argv[1]);

    return 0;
}
