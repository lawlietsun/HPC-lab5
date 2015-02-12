#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) 
{

    int size, rank, tag=0;
    int myarray[3];
    int result_array[3];
    int count;

    MPI_Status status;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 0)
    {
        myarray[0] = 1; 
        myarray[1] = 2; 
        myarray[2] = 3;
        
        MPI_Send(myarray, 3, MPI_INT, 1, tag, MPI_COMM_WORLD);

        printf("array to send: \n");
        for(int i = 0; i <=2; i++)
        {
            printf("%d ", myarray[i]);
        }

        printf("\n");
        printf("send tag = %d\n", status.MPI_TAG);
    } 
    else 
    {
        MPI_Recv(result_array, 3, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);

        printf("receive tag = %d\n", status.MPI_TAG);
        printf("source = %x\n", status.MPI_SOURCE);

        printf("array received: \n");
        for(int i = 0; i <=2; i++)
        {
            printf("%d ", result_array[i]);
        }
        printf("\n");
        
        MPI_Get_count(&status, MPI_INT, &count);
        printf("massage size = %d\n", count);
    }

    MPI_Finalize();

    return 0;

}