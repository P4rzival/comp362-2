/**
 * Name: Taseen Hafiz
 * Lab/task: Lab 03 - Task 2
 * Date: 02/17/2020
 **/
// To run with cmake:	$ cmake ..
//						$ make

// For post-mortem debugging: $ ulimit -c unlimited

#include	<stdio.h>
#include	<unistd.h>
#include    <errno.h>
#include    <sys/types.h>
#include    <sys/wait.h>

int main(int argc, char *argv[])
{
   printf("Process %s pid is: %d\n", argv[1], getpid());

   int i = 0;
   while (i == 0) /* NOTE: this is an endless loop; use gdb to change the value of i and continue */
      ;

    /* wait for the children to complete (if any) */
    if (waitpid(-1, NULL, 0) < 0)
        printf("ERROR: -1 from wait() with errno = %d in process %s\n", errno, argv[1]);

   printf("Process %s is terminating\n", argv[1]);
}
