#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

double calcArea(double a,double b,int n);
inline static double f(double x);

int main(int argc,char *argv[])
{
	double g_area=0.0,a,b;
	int n;double la;
	int thread_count=strtol(argv[1],NULL,10);
	if(thread_count%2!=0)
	{
		printf("Enter even num threads");
		return 0;
	}
	
	
	
	printf("Enter a b n ra");
	scanf("%lf %lf %d",&a,&b,&n);
	#pragma omp parallel num_threads(thread_count)
       		la=calcArea(a,b,n);	
		#pragma omp critical
		g_area+=la;
	
	printf("For %d trapezoid,area under the curve\n",n);
	printf("between %lf and %lf is %lf\n",a,b,g_area);
}

inline static double f(double x)
{
	return x*x;
}

double calcArea(double a,double b,int n)
{
	double la,lb;
	int ln;
	int my_rank=omp_get_thread_num();
	int thread_count=omp_get_num_threads();

	double h=(b-a)/n,x;

	ln=n/thread_count;
	la=a+ln*h*my_rank;
	lb=la+ln*h;

	double area=(f(la)+f(lb))/2.0;
	for (int i = 0; i < ln-1; i++)
	{
		x=la+i*h;
		area+=f(x);
	}

	return area*h;
	
}
