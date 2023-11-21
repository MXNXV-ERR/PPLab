# Below shiii is common for all the progs

``` c 
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
# Some really annoying functions
### MPI_Send,MPI_Ssend
```c
MPI_Send,MPI_Ssend same
MPI_Send(*buf,count,mpi_datatype,dest,tag,MPI_COMM_WORLD)

buf : message to be sent
count : size of msg
mpi_datatype : type of data (MPI_Char,MPI_Int.....)
dest : destination
tag : i am still trynna figure it out
```
### MPI_Isend
```c
MPI_Isend(*buf,count,mpi_datatype,dest,tag,MPI_COMM_WORLD,*request)
request : request object , has some request info
```
### MPI_Recv
```c
MPI_Recv(*buf,count,mpi_datatype,src,tag,MPI_COMM_WORLD,*status)

buf : variavle where it has to be recieved
count : siz of msg
mpi_datatype : type of data (MPI_Char,MPI_Int.....)
src : source
tag : i am still trynna figure it out
status : status object , has some status info
```
### MPI_Irecv
```c
MPI_Irecv(*buf,count,mpi_datatype,src,tag,MPI_COMM_WORLD,*request)
request : request object , has some request info
```
### MPI_Wait
```c
MPI_Wait(*request,*status)
status : status object , has some status info
request : request object , has some request info
```
##### MPI_Status stat; this is how status object is declared
##### MPI_Request req; this is how request object is declared


### MPI_Sendrecv
```c
MPI_Sendrecv(*sendbuf, sendcount, send_mpi_datatype,dest,sendtag,
            *recvbuf, recvcount,  recv_mpi_datatype,src,recvtag,
            MPI_COMM_WORLD,*status)
think!!!!!!!
```


# Q1,Q2,Q3,Q4,Q5

### Q1 ,Send and recieve

Simple sending and recieving 

```
if(world_rank==0)
    MPI_Send
else if(world_rank==1)
    MPI_Recv
```

### Q2 show deadlock
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

### Q3 deadlock avoidance using sync
    same as Q2 but MPI_Send -> MPI_Ssend

### Q4 deadlock avoidance using non blocking calls
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

### Q5 use MPI_Sendrecv
    what shit we did in last 4 questions can be done in single line using 
```MPI_Sendrecv```


# Q6 show MPI_Barrier

    6th standard program this is by-heart and go

```
// DO SOMEthing above
MPI_Barrier(MPI_COMM_WORLD); // make sure all above things are completed then only move to below 
// DO SOMEthing below
```


# Q7 Broadcasting from 1 thread
broad cast it seems 

```
MPI_Bcast(*buf,count,mpi_datatype,root,MPI_COMM_WORLD)

buf , count ,mpi_datatype : this u should know by now
root : rank of broadcasting process/thread
```


# Q8,Q9,Q10

### Q8 gather

```c
MPI_Gather( *sendbuf,sendcount,mpi_datatype,
            *recvbuf,recvcount,mpi_datatype,
            root, MPI_COMM_WORLD)
```

### Q9 scatter

```c
MPI_Scatter(*sendbuf, sendcount, mpi_datatype,
            *recvbuf, recvcount, mpi_datatype, 
            root,MPI_COMM_WORLD)
```

### Q10 both together
 above both together


# Q11,Q12

### Q11 MPI_Reduce
```c
MPI_Reduce(*sendbuf, *recvbuf, count, mpi_datatype,
               op,root, MPI_COMM_WORLD)

op : the operation to reduce like mpi_max mpi_min mpi_sum mpi_prod
```
### Q12 MPI_Allreduce
```c
MPI_Allreduce

same syntax as MPI_Reduce , but "root" parameter no reuired as all processes recieve the broadcasted data
```

### MPI_Reduce vs MPI_Allreduce

- Reduce will compute and store in that particular rank
- Allreduce will compute and broadcast to all other ranks in the world

    

