#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int a[1000],n=1000;
	int sum=0;

	if(argc==1)
	{
		printf("usage: .\\name thread_count\n");
		exit(0);
	}

	int thread_count=strtol(argv[1],NULL,10);
	for(int i=0;i<n;i++)
		a[i]=i;
	
#pragma omp parallel for num_threads(thread_count) reduction(+:sum)
	for(int i=0;i<n;i++)
		sum+=a[i];

	printf("Sum=%d",sum);

	int t=0;
#pragma omp parallel for num_threads(thread_count) reduction(-:t)
	for(int i=1;i<=4;i++)
		t-=i;

	printf("T=%d",t);
}


