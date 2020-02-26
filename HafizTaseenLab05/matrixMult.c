/**
 * Name: Taseen Hafiz
 * Lab/task: Lab 05
 * Date: 03/02/2020
 **/

#include "matrixMult.h"

int main(int argc, char *argv[])
{
	if (freopen(argv[1], "r", stdin) == 0)
		oops("Cannot open the input file.\n", -1);

	int **a1, **b1, **c1, **a2, **b2, **c2; // matrices
	int m1, k1, n1, m2, k2, n2; // dimensions of the matices m x k and k x n

	allocateAndLoadMatrices(&a1, &b1, &c1, &m1, &k1, &n1);
	allocateAndLoadMatrices(&a2, &b2, &c2, &m2, &k2, &n2);

	// the real magic happens in there

	// TODO: implement

	// display results of matrix multiplication

	printf("\nMATRIX A1\n");
	displayMatrix(a1, m1, k1);
	freeMatrix(a1, m1);
	printf("\nMATRIX B1\n");
	displayMatrix(b1, k1, n1);
	freeMatrix(b1, k1);
	printf("\nMATRIX A1 x B1\n");
	displayMatrix(c1, m1, n1);
	freeMatrix(c1, m1);

	printf("\nMATRIX A2\n");
	displayMatrix(a2, m2, k2);
	freeMatrix(a2, m2);
	printf("\nMATRIX B2\n");
	displayMatrix(b2, k2, n2);
	freeMatrix(b2, k2);
	printf("\nMATRIX A2 x B2\n");
	displayMatrix(c2, m2, n2);
	freeMatrix(c2, m2);

	return 0;
}

void *matrixThread(void *param)
{
	// map the parameter onto the structure
	MATRIX_CELL *cell = (MATRIX_CELL *)param;

	// TODO: implement

	free(cell);

	return NULL;
}

void allocateAndLoadMatrices(int ***a, int ***b, int ***c, int *m, int *k, int *n)
	// takes pointers to two-dimensional matrices, so they can be allocated in here
	// and used by the caller
{
	if (scanf("%d %d %d", m, k, n) == 0)
		oops("Cannot read matrix sizes.\n", -2);

	// TODO: implement
	// Allocating all variables

	// First store m, k, n
	
}

void loadMatrix(int ***matrix, int m, int n)
{
	// TODO: implement
}

void freeMatrix(int **matrix, int m)
{
	// TODO: implement
}

pthread_t **multiply(int **a, int **b, int **c, int m, int k, int n)
{
	pthread_t **tids = alloc_tids(m, n);

	// TODO: implement

	return tids;
}

pthread_t **alloc_tids(int m, int n)
{
	pthread_t **tids;

	// TODO: implement

	return tids;
}

void free_tids(pthread_t **tids, int m)
{
	// TODO: implement
}

void join(pthread_t **tids, int m, int n)
{
	// TODO: implement
}

void displayMatrix(int **matrix, int m, int n)
{
	// TODO: implement
}
