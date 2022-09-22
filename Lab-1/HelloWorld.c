#include <omp.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	printf("\nExecution Without Parallel running...\n");
    omp_set_num_threads(8);
    double start; 
    double end; 
    start = omp_get_wtime();
	//#pragma omp parallel
	{
		printf("Hello World... from thread = %d\n", omp_get_thread_num());
	}
	//Ending of parallel region
    end = omp_get_wtime(); 
    printf("Time taken: %f\n", end - start);
}

