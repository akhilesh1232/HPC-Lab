#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    omp_set_num_threads(8);
    double start; 
    double end; 
    start = omp_get_wtime();
    int n = 200, i ,j=99;
    int arr1[n], answer[n];
    for(i = 0; i < n; i++){
        arr1[i] = rand()%100;
    }    
    #pragma omp parallel for schedule(static,20) shared(arr1, answer,j) private(i)
    for(i = 0; i < n; i++)
    {
        answer[i] = arr1[i] + j;
    }
    // printf("\nArray 1: \n");
    // for(i = 0; i < n; i++){
    //     printf("\t %d", arr1[i]);
    // }
    // printf("\nAnswer: \n");
    // for(i = 0; i < n; i++){
    //     printf("\t %d", answer[i]);
    // }
    end = omp_get_wtime(); 
    printf("Time taken: %f\n", end - start);
    return 0;
}