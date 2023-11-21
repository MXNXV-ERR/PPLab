#include <stdio.h>
#include <mpi.h>
int main() {
    MPI_Init(NULL, NULL);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    // Phase 1: Each process performs a task (e.g., prints its rank)
    printf("Phase 1, Process %d of %d\n", world_rank, world_size);
    // Synchronize all processes before moving to the next phase
    MPI_Barrier(MPI_COMM_WORLD); // think of real world barrier
    // Phase 2: Another task after synchronization
    printf("Phase 2, Process %d of %d\n", world_rank, world_size);
    MPI_Finalize();
    return 0;
}
