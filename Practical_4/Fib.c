// Fib
#include <stdio.h>
#include <time.h>
#include <omp.h>
int fib(int n)
{
   /* Declare an array to store Fibonacci numbers. */
   int a[n + 2];
   // 1 extra to handle case, n = 0
   int i;
   /* 0th and 1st number oa the series are 0 and 1*/
   a[0] = 0;
   a[1] = 1;

   #pragma omp parallel shared(i)
   {
      #pragma omp single
      for (i = 2; i <= n; i++)
      {
            a[i] = a[i - 2] + a[i - 1];
            printf("id of thread involved in the computation of fib no %d is=%d\n", i + 1, omp_get_thread_num());
      }
   }
    return a[n];
}
int main()
{
    int n = 10;
    clock_t begin = clock();
    int ans = fib(n);
    double time1 = omp_get_wtime();
    printf("%d\n", ans);
    double time2 = omp_get_wtime();
    double time_requried = time2-time1;
    printf("%lf\n", time_requried);
    return 0;
}