#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main(){
    int n,i,itern[8];
    printf("enter iterns:");
    scanf("%d",&n);
    

    #pragma omp parallel for schedule(static,3)
    for(i=1; i<=n; i++)
        printf("thread %d itern %d value: %d\n",omp_get_thread_num(),itern[omp_get_thread_num()]++,i);
        
}