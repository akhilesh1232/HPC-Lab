#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("With parallel execution\n");
    omp_set_num_threads(8);
    double start, end;
    start = omp_get_wtime(); 
    long int n = 1000000, i;
    int arr1[n], k, answer[n];
    for(i = 0; i < n; i++){
        arr1[i] = rand()%100;
        k = rand()%100;
    }    
    #pragma omp parallel for shared(arr1,k,answer) private(i) firstprivate(k)
    for(i = 0; i < n; i++)
    {
        answer[i] = arr1[i] + k;
    }
    end = omp_get_wtime(); 
    printf("Time taken: %lf\n", end - start);
    return 0;
}