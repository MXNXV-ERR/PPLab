# Below shiii is common for all the progs

```
#include <stdio.h>
#include <mpi.h>
void main() {
    int world_size,world_rank; //any other variable declarations
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    (optinal) MPI_Status stat; // required only if using mp_recv(), last arg
    //this if condition not compulsory
    
    if (world_size < 2) {
        printf("World size must be greater than 1\n");
        MPI_Finalize();
        return 0;
    }

    //
    // here u have to fill shit for the respective program
    //
    
    MPI_Finalize();
}
```


# Q1,Q2,Q3,Q4,Q5

### Q1
```
if(world_rank==0)
    MPI_Send
else if(world_rank==1)
    MPI_Recv
```

### Q2
```
if(world_rank==0)
{   MPI_Send
    MPI_Recv
}
else if(world_rank==1)
{   MPI_Recv
    MPI_send
}
```

### Q3
    same as Q2 but MPI_Send -> MPI_Ssend

### Q4
```
if (world_rank == 0) {
    MPI_Isend
    MPI_Wait
    MPI_Irecv
    MPI_Wait
} else if (world_rank == 1) {
    MPI_Irecv
    MPI_Wait
    MPI_Isend
    MPI_Wait
}
```

### Q5
    what shit we did in last 4 questions can be done in single line using 
```MPI_Sendrecv```


# Q6

    6th standard program this is by-heart and go

```
// DO SOMEthing above
MPI_Barrier(MPI_COMM_WORLD) // make sure all above things are completed then only move to below 
// DO SOMEthing below
```


# Q7
 broad cast it seems 

 ```MPI_Bcast```


# Q8,Q9,Q10

### Q8

```MPI_Gather```

### Q9

```MPI_Scatter```

### Q10
 above both together


# Q11,Q12

### Q11
```MPI_Reduce```
### Q12
```MPI_Allreduce```

    

