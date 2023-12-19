///////////Math.h don`t forget -lm during compilation//////////////////////
///////// this code need no cmd line args //////////////////////
#include<stdio.h>
#include<omp.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int thread_count,itr;
	double sum=0;
	double start,end;
	printf("Enter thread count");
	scanf("%d",&thread_count);
	printf("No of iteration for pi");
	scanf("%d",&itr);



	start = omp_get_wtime();
	for(int i=0;i<itr;i++)
		sum+=(pow(-1,i)/(2*i+1));
	end = omp_get_wtime();
	printf("Sum=%f in serial took %fs\n",4*sum,end-start);

	sum=0;
	start = omp_get_wtime();
#pragma omp parallel for num_threads(thread_count) reduction(+:sum)
	for(int i=0;i<itr;i++)
		sum+=(pow(-1,i)/(2*i+1));
	end = omp_get_wtime();

	printf("Sum=%f in parallel took %fs\n",4*sum,end-start);
}
//timing logic is added it is jus repeateed again it is not difficult