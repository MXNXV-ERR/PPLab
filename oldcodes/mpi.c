#include<stdio.h>
#include<string.h>
#include<mpi.h>
int main()
{
    MPI_Init(NULL,NULL);
    int communicator_size;
    MPI_Comm_size( MPI_COMM_WORLD , &communicator_size);
    int my_rank;
    MPI_Comm_rank( MPI_COMM_WORLD , &my_rank);
    printf("Hello from process %d of %d \n",my_rank,communicator_size);
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_length;
    MPI_Get_processor_name(processor_name, &name_length);
    //printf("processor_name: %s\n",processor_name);
    char my_msg1[100];
    char my_msg[]="Hello from MXNXV-ERR";
    int number;
    // if (my_rank==0)
    // {
    //     number=1;
        
    //     MPI_Send(&my_msg , strlen(my_msg) , MPI_CHAR , 1 , 0 , MPI_COMM_WORLD);
    // }else if (my_rank==1)
    // {
    //     MPI_Recv(&my_msg1 , strlen(my_msg) , MPI_CHAR , 0 , 0 , MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    //     printf("Recieved number %s from processor 0\n",my_msg1);
    // }
    

    if(my_rank!=0)
    {
        sprintf(my_msg,"hello from %d",my_rank);
        MPI_Send(&my_msg , strlen(my_msg) , MPI_CHAR , 0 , 0 , MPI_COMM_WORLD);
    }else
    {
        for (int i = 1; i < communicator_size; i++)
        {
            MPI_Recv(&my_msg1 , strlen(my_msg) , MPI_CHAR , MPI_ANY_SOURCE , 0 , MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            printf("Recieved number %s from processor 0\n",my_msg1);
        }
        
    }
    

    MPI_Finalize();
}

