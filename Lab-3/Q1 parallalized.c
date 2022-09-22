#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

int sort(int arr[],long long  int n)
{
    long long int i, j;
    omp_set_num_threads(8);
    #pragma omp parallel for
    for (i = 0; i < n-1; i++)
    {
        //parallel loop for the sorting
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

int sort_des(int arr[],long long int n) 
{
    long long int i,j;
    omp_set_num_threads(8);
    #pragma omp parallel for
    for (i = 0; i < n; ++i) 
    {
        //parallel loop for the sort in reverse order
        for (j = i + 1; j < n; ++j) 
        {
            if (arr[i] < arr[j]) 
            {
                int a = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = a;
            }
        }
    }
}



int main()
{
    printf("******* without using parallel");
    omp_set_num_threads(8);
    double start; 
    double end; 

    long long int n = 10000; 
    int arr1[n], arr2[n]; 
    long long int i;
    for(i = 0; i < n ; i++)
    {
        arr1[i] = rand()%100;
    }
    for(i = 0; i < n ; i++)
    {
        arr2[i] = rand()%100;
    }
    start = omp_get_wtime();
    //parallel sorting
    sort(arr1, n); 
    //parallel sorting in reverse order
    sort_des(arr2, n); 
    long int sum = 0;
    #pragma parallel for reduction(+ : sum) shared(arr1, arr2, sum) 
    for(i = 0; i < n ; i++)     
    {
        sum = sum + (arr1[i] * arr2[i]); 
    }
    printf("\n Sum: %lld\n",sum);
    end = omp_get_wtime(); 
    printf("Time taken: %lf\n", end - start);
    return 0; 
}
