/*
  26. Write a program to execute an executable program.
      a. use some executable program *
      b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    printf("Executing hello program...\n");

    // execl() replaces the current process with the executable "hello".
    
    // The arguments are:  path, argv[0], argv[1], ..., NULL
    execl("./prog", "prog", NULL);

    // This line executes only if execl() fails.
    perror("execl");

    return 1;
}

/*
Output:

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P26$ gcc prog.c -o prog
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P26$ gcc execute.c -o execute
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P26$ ./execute
Executing hello program...
Hello! This is the executable program.

*/
