#include<stdio.h>
#include<mpi.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	int world_size,world_rank;
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
	MPI_Status stat;
	
	char inmsg[100],outmsg[100] = "welcome to ise!";
	int dest,source,count,tag=1;
	if(world_rank==0){
		dest = 1; //setting dest as rank 1
		MPI_Send(&outmsg,strlen(outmsg),MPI_CHAR,dest,tag,MPI_COMM_WORLD); 
	}
	else if(world_rank==1){
		source=0; // mentioning source as rank 0
		MPI_Recv(&inmsg,strlen(outmsg),MPI_CHAR,source,tag,MPI_COMM_WORLD,&stat);
	}
	MPI_Get_count(&stat,MPI_CHAR,&count);
	printf("TASK %d, received %d char(s) task from %d with tag %d and msg is %s\n",world_rank,count,stat.MPI_SOURCE,stat.MPI_TAG,inmsg);
	MPI_Finalize();
}