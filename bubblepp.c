#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;

}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i;i<n;i++)
		a[i]=rand()%n;
	double s=omp_get_wtime();
	#pragma omp parallel
	for(int pass=0;pass<n;++pass)
	{
		int i;
		if(pass%2==0)
		{
			#pragma omp parallel for default(none) shared(a,n) private(i)
			for(i=1;i<n;i+=2)
				if(a[i-1]>a[i])
					swap(&a[i-1],&a[i]);
		}
		else
		{
			#pragma omp parallel for default(none) shared(a,n) private(i)
			for(i=1;i<n-1;i+=2)
				if(a[i]>a[i+1])
					swap(&a[i],&a[i+1]);
		}

	}
	double e=omp_get_wtime();
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\nTime =%lfsec \n",e-s);
	

}
