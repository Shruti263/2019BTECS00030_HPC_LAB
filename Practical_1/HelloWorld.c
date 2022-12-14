// OpenMP header
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int nthreads, tid ,n;

	// Begin of parallel region
	#pragma omp parallel private(tid)
	{
		// Getting thread number
		tid = omp_get_thread_num();
		printf("Hello World from thread = %d\n",
			tid);
	}
}
