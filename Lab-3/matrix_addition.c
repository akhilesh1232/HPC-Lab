#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 250

int main()
{
	int tid, nthreads, i, j;
	int a[N][N], b[N][N], c[N][N];
	omp_set_num_threads(8);
	double time = omp_get_wtime();

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = i + j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			b[i][j] = i + j;

#pragma omp parallel shared(a, b, c, nthreads) private(tid, i, j)
	{
		#pragma omp for private(j) collapse(2)
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
				c[i][j] = a[i][j] + b[i][j];
		}
	}
	//  printf("\nResultant Matrix:\n");
	//  for (i=0; i<N; i++)
	//  {
	//  	for (j=0; j<N; j++)
	//  		//printf("%d ", c[i][j]);
	//  	//printf("\n");
	// }

	printf("\nDone In %f Seconds", omp_get_wtime() - time);
	printf("\n Using %d Threads", omp_get_max_threads());

	return (0);
}