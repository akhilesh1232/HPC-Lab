#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("With parallel execution\n");
    omp_set_num_threads(8);
    double start; 
    double end; 
    start = omp_get_wtime();
    long long int n = 100000, i;
    long long int arr1[n], arr2[n], answer[n];
    for(i = 0; i < n; i++){
        arr1[i] = rand()%100000;
        arr2[i] = rand()%100000;
    }    
    #pragma omp parallel for shared(arr1, arr2, answer) schedule(static)
    for(i = 0; i < n; i++)
    {
        answer[i] = arr1[i] + arr2[i];
    }
    end = omp_get_wtime(); 
    printf("Time taken: %lf\n", end - start);
    return 0;
}