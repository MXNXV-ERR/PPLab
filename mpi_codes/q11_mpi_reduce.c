#include <stdio.h>
#include <mpi.h>
int main() {
    int world_rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    // Each process will use its rank as the data
    int data = world_rank;
    int max_val, min_val, sum, prod;
    // Reduce to find the maximum value
    MPI_Reduce(&data, &max_val, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    // Reduce to find the minimum value
    MPI_Reduce(&data, &min_val, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    // Reduce to find the sum of all values
    MPI_Reduce(&data, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    // Reduce to find the product of all values
    MPI_Reduce(&data, &prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
    // The root process prints the results
    if (world_rank == 0) {
        printf("Max value: %d\n", max_val);
        printf("Min value: %d\n", min_val);
        printf("Sum of all ranks: %d\n", sum);
        printf("Product of all ranks: %d\n", prod);
    }
    MPI_Finalize();
    return 0;
}