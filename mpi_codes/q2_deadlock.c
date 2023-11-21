#include<stdio.h>
#include<mpi.h>
void main(){
    int rank,size,root=0,dest=1,source=0,tag1=1,tag2=2;
    int out =77,in;
    MPI_Init(NULL,NULL);
    MPI_Status stat;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    //no deadlock
    if(rank==0){
        dest = 1;
        source = 1;
        MPI_Send(&out,1,MPI_INT,dest,tag1,MPI_COMM_WORLD);
        MPI_Recv(&in,1,MPI_INT,source,tag2,MPI_COMM_WORLD,&stat);
    }
    else if(rank==1){  
        dest = 0;
        source = 0;
        MPI_Recv(&in,1,MPI_INT,source,tag2,MPI_COMM_WORLD,&stat);//change tags here for deadlock
        MPI_Send(&out,1,MPI_INT,dest,tag1,MPI_COMM_WORLD); //once tags changes no output
   }
    printf("rank %d msg %d with tag %d from task %d\n",rank,in,stat.MPI_TAG,stat.MPI_SOURCE);
    MPI_Finalize();
}