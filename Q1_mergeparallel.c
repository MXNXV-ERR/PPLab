#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void combine(int a[],int l,int m,int h){
    int temp[h],i=l,j=m+1,k=l;
	while(i<=m&&j<=h)
		temp[k++]=a[i]<=a[j]?a[i++]:a[j++];	
	while(i<=m)
		temp[k++]=a[i++];
	while(j<=h)
		temp[k++]=a[j++];
	for(int i=l;i<=h;i++)
		a[i]=temp[i];
}

void mergesortParallel(int a[],int l,int h){
    if(l<h){
        int mid = (l+h)>>1;
        #pragma omp parallel sections
        {
            #pragma omp section
            mergesortParallel(a,l,mid);
            #pragma omp section
            mergesortParallel(a,mid+1,h);
        }
        combine(a,l,mid,h);
    }
}

void mergesortSerial(int a[],int l,int h){
    if(l<h){
        int mid = (l+h)>>1;
        mergesortSerial(a,l,mid);
        mergesortSerial(a,mid+1,h);
        combine(a,l,mid,h);
    }
}

void main(){
    int num,i;
	printf("Enter number:");
	scanf("%d",&num);
	int a[num];

    for(i=0;i<num;i++)a[i]= rand()%100;
    //for(i =0;i<num;i++) printf("%d ",a[i]);

	double start = omp_get_wtime();
	mergesortSerial(a,0,num-1);
	double end = omp_get_wtime();
	double val = end - start;
	printf("\nTime for serial is:%f\n",val);

    //for(i =0;i<num;i++) printf("%d ",a[i]);

    start = omp_get_wtime();
    mergesortParallel(a,0,num-1);
    end = omp_get_wtime();
    val = end-start;
    printf("Time for parallel execution is %f\n",val);
}   