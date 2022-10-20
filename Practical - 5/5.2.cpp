#include <mpi.h>
#include <stdio.h>


int main( int argc, char *argv[] )
{
    int rank, size;
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );

    int color = rank / 2;
    MPI_Comm row_comm;
    MPI_Comm_split(MPI_COMM_WORLD, color, rank, &row_comm);

    int row_rank, row_size;
    MPI_Comm_rank(row_comm, &row_rank);
    MPI_Comm_size(row_comm, &row_size);

    printf("WORLD RANK/SIZE: %d/%d \t ROW RANK/SIZE: %d/%d\n", rank, size, row_rank, row_size);

    MPI_Comm_free(&row_comm);
    MPI_Finalize();
    return 0;
}