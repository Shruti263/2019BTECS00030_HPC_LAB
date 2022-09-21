#include <stdio.h>
#include <omp.h>

int main()
{
    int arr[100];
    
    int sum = 0;
    #pragma omp parallel for reduction(+: sum) private(arr)
        for (int i = 0; i < 100; i++)
        {
            sum = sum + ((i + 1) * (i + 1));
        }

    printf("\n%d\n", sum);
    return 0;
}