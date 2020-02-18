/**
 * Name: Taseen Hafiz
 * Lab/task: Lab 03 - Task 2
 * Date: 02/17/2020
 **/
// To run with cmake:	$ cmake ..
//						$ make

// For post-mortem debugging: $ ulimit -c unlimited

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <unistd.h>
#include    <errno.h>
#include    <sys/types.h>
#include    <sys/wait.h>

#define oops(m) {perror(m); exit(EXIT_FAILURE);}

int main() {
	pid_t pid;
	
    // Used so proc_hier only exits when its children terminate
	pid_t pid11;
	pid_t pid12;

	// fork child process (1.1)
	pid11 = fork();

	if (pid11 < 0) // error occurred
		oops("Fork Failed!");

	if (pid11 == 0) // child (1.1)
	{
		printf("I am the child 1.1, my pid is %d, I will make my children before I morph\n", getpid());

		// fork child process (1.1.1)
		pid = fork();

		if (pid < 0) // error occurred
			oops("Fork Failed!");

		if (pid == 0) // child (1.1.1)
		{
			printf("I am the child 1.1.1, my pid is %d, I will now morph\n", getpid());
			if (execlp("./iam", "iam", "1.1.1", NULL) < 0) 
				oops("Execlp Failed!");
		}

		// fork child process (1.1.2)
		pid = fork();

		if (pid < 0) // error occurred
			oops("Fork Failed!");

		if (pid == 0) // child (1.1.2)
		{
			printf("I am the child 1.1.2, my pid is %d, I will now morph\n", getpid());
			if (execlp("./iam", "iam", "1.1.2", NULL) < 0) 
				oops("Execlp Failed!");
		}	

		// pid > 0 ==> must be parent (1.1)
		printf("I am the parent 1.1, my pid is %d\n", getpid());

		printf("Parent 1.1 will now morph\n");

		if (execlp("./iam", "iam", "1.1", NULL) < 0) 
			oops("Execlp Failed!");
	}

	// fork child process(1.2)
	pid12 = fork();

	if (pid12 < 0) // error occurred
		oops("Fork Failed!");

	if (pid12 == 0) // child (1.2)
	{
		printf("I am the child 1.2, my pid is %d, I will make my children before I morph\n", getpid());

		// fork child process (1.2.1)
		pid = fork();

		if (pid < 0) // error occurred
			oops("Fork Failed!");

		if (pid == 0) // child (1.2.1)
		{
			printf("I am the child 1.2.1, my pid is %d, I will now morph\n", getpid());
			if (execlp("./iam", "iam", "1.2.1", NULL) < 0) 
				oops("Execlp Failed!");
		}

		// fork child process (1.2.2)
		pid = fork();

		if (pid < 0) // error occurred
			oops("Fork Failed!");

		if (pid == 0) // child (1.2.2)
		{
			printf("I am the child 1.2.2, my pid is %d, I will now morph\n", getpid());
			if (execlp("./iam", "iam", "1.2.2", NULL) < 0) 
				oops("Execlp Failed!");
		}	

		// pid > 0 ==> must be parent (1.2)
		printf("I am the parent 1.2, my pid is %d\n", getpid());

		printf("Parent 1.2 will now morph\n");

		if (execlp("./iam", "iam", "1.2", NULL) < 0) 
			oops("Execlp Failed!");
	}

	// pid > 0 ==> must be parent 1
	printf("I am the parent 1, my pid is %d\n", getpid());

	/* parent 1 will wait for the children to complete */

	if (waitpid(-1, NULL, 0) < 0)
		printf("-1 from wait() with errno = %d\n", errno);

	waitpid(pid11, NULL, 0);

	waitpid(pid12, NULL, 0);
	
	printf("Children 1.1 and 1.2 have both been terminated; parent exiting\n");

	exit(EXIT_SUCCESS);
}
