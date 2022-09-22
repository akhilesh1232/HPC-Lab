#include <stdio.h>
#include <time.h>
#include <omp.h>
int fib(int n)
{
    int a[n + 2];
    int i;
    a[0] = 0;
    a[1] = 1;

#pragma omp parallel 
    {
        #pragma omp single
        for (i = 2; i <= n; i++)
        {
            a[i] = a[i - 2] + a[i - 1];
            //printf("id of thread involved in the computation of fib no %d is=%d\n", i + 1, omp_get_thread_num());
        }
    }
    return a[n];
}
int main()
{
    printf("Parallel Execution of fibonaci series.");
    long long int n = 100000;
    omp_set_num_threads(8);
    double time1 = omp_get_wtime();
    long long int ans = fib(n);
    printf("%d\n", ans);
    double time2 = omp_get_wtime();
    double time_requried = time2-time1;
    printf("Time for parallel execution: %lf\n", time_requried);
    return 0;
}

