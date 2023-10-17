#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int isPrime(int n){
  if(n < 2)
    return 0;
  for(int i = 2; i <= n/2; i++)
    if(n%i == 0)
      return 0;
  return 1;
}

int main(){
	int n;
	printf("Enter n value");
	scanf("%d",&n);	

	//parallel
	double start = omp_get_wtime();
	#pragma omp parallel for
	for(int i = 1; i <= n;i++)
		if(isPrime(i))
			printf("process : %d , %d \n",omp_get_thread_num(),i);
	double end = omp_get_wtime();
	double para = end-start;

	//serial
	start = omp_get_wtime();
	for(int i = 1; i <= n;i++)
		if(isPrime(i))
			printf("process : %d , %d \n",omp_get_thread_num(),i);
	end = omp_get_wtime();
	double seri = end -start;

	//print times
	printf("The time taken for parallel is %lf\n\n ",para);
	printf("The time taken for serial is %lf ",seri);
}