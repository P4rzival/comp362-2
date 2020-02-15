/**
 * Name: Taseen Hafiz
 * Lab/task: Lab 03 - Task 1
 * Date: 02/17/2020
 **/
// To run with cmake:	$ cmake ..
//						$ make

// For post-mortem debugging: $ ulimit -c unlimited

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

// Rune size

int error_type;
char *error_msg = "ERROR";

int main(int argc, char **argv)
{
	int *val;
	val = (int *) malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++)
		val[i] = i;
	return EXIT_SUCCESS;
}
