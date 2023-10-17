#include<stdio.h>
#include<omp.h>
int fib(int n)
{
	int i,j;
	if(n<2) return n;
	else {
		#pragma omp task shared(i) firstprivate(n)
		i = fib(n-1);
		#pragma omp task shared(j) firstprivate(n)
		j = fib(n-2);
		#pragma omp taskwait
		return i+j;
	}
}
void main()
{
	int n;
    printf("Enter n value");
    scanf("%d",&n);	
	// omp_set_num_threads(4);
	#pragma omp num_threads(4) parallel shared(n) 
    for(int i=0;i<=n;i++)
	{
		#pragma omp single
		printf("fib(%d) = %d\n",i,fib(i));
	}	
}