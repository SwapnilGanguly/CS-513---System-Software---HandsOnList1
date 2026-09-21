/*
  26. Write a program to execute an executable program.
      a. use some executable program
      b. pass some input to an executable program. (for example execute an executable of $./a.out name) *
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    // Execute the "name" executable and pass "Swapnil" as its command-line argument.
    // It is equivalent to: ./name Swapnil
    execl("./name", "name", "Swapnil", NULL);

    //This executes only if execl() fails.
    perror("execl");

    return 1;
}

/*
Output: 

swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P26$ gcc execute_name.c -o execute_name
swapnil@swapnil-Latitude-5400:~/SoftwareSystems/P26$ ./execute_name
Hello, Swapnil!

*/
