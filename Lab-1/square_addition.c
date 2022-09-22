#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
	printf("\nExecution Without Parallel running...\n");

    //omp_set_num_threads(8);
    double start; 
    double end; 
    start = omp_get_wtime();
    //program to add square of the numbers
    int number = 0;
    long long int addittion = 0;
    //#pragma omp parallel for reduction(+:addittion)
    for(int i = 0 ; i <= 1000000; i++)
    {
        //printf("\tSquare of %d: %d", i, i*i);
        addittion += i*i;
    }

    printf("\nAddition of first 1000 squares: %lld\n", addittion);
    end = omp_get_wtime(); 
    printf("Time taken: %f\n", end - start);
}