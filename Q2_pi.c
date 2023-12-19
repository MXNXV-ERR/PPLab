#include<stdio.h>
#include<omp.h>
#include<math.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	int t_c=strtol(argv[1],NULL,10);
	double sum=0;
	double start,end;

	start = omp_get_wtime();
	for(int i=0;i<strtol(argv[2],NULL,10);i++)
		sum+=(pow(-1,i)/(2*i+1));
	end = omp_get_wtime();
	printf("Sum=%f in serial took %fs\n",4*sum,end-start);

	start = omp_get_wtime();
#pragma omp parallel for num_threads(t_c) reduction(+:sum)
	for(int i=0;i<strtol(argv[2],NULL,10);i++)
		sum+=(pow(-1,i)/(2*i+1));
	end = omp_get_wtime();

	printf("Sum=%f in parallel took %fs\n",4*sum,end-start);
}
//timing logic is added it is jus repeateed again it is not difficult