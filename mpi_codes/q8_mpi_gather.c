#include <mpi.h>
#include <stdio.h>
int main() {
    int world_rank, world_size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    // Each process will send its rank
    int send_data = world_rank;
    // The root process will collect all ranks
    int recv_data[world_size];
    // Gather data from all processes to root (rank 0)
    MPI_Gather(&send_data, 1, MPI_INT, 
                recv_data, 1, MPI_INT, 
                0, MPI_COMM_WORLD);
    // Root process prints the gathered data
    if (world_rank == 0) {
        printf("Gathered data at root: ");
        for (int i = 0; i < world_size; i++) 
            printf("%d \t", recv_data[i]);
    }
    MPI_Finalize();
    return 0;
}
