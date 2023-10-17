#include <stdio.h>
#include <omp.h>

void main() {
    int sum = 0;
    int n;
    printf("Enter n value");
    scanf("%d",&n);	
    #pragma omp parallel for 
    for (int i = 1; i <= n; i++) 
        #pragma omp critical
        sum += i;
    
    printf("Sum of the first 100 numbers: %d\n", sum);
}