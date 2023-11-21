#include <stdio.h>
#include <mpi.h>
int main() {
    int world_rank, world_size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    if (world_size < 2) {
        printf("World size must be greater than 1\n");
        MPI_Finalize();
        return 0;
    }
    int send_number = world_rank;
    int recv_number;
    // For simplicity, each process communicates with the next process (circularly)
    int target_rank = (world_rank + 1) % world_size;
    int source_rank = (world_rank - 1 + world_size) % world_size;
    // Using MPI_Sendrecv for simultaneous send and receive , no deadlock
    MPI_Sendrecv(&send_number, 1, MPI_INT, target_rank, 0,
                &recv_number, 1, MPI_INT, source_rank, 0,
                MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process %d sent %d to process %d and received %d from process %d\n",
                world_rank, send_number, target_rank, recv_number, source_rank);
    MPI_Finalize();
    return 0;
}