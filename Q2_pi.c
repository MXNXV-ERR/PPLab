#include<stdio.h>
#include<omp.h>
#include<math.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	int t_c=strtol(argv[1],NULL,10);
	double sum=0;
#pragma omp parallel for num_threads(t_c) reduction(+:sum)
	for(int i=0;i<strtol(argv[2],NULL,10);i++)
		sum+=(pow(-1,i)/(2*i+1));

	printf("Sum=%f",4*sum);
}
