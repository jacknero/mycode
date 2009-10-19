/*
 * =====================================================================================
 *
 *       Filename:  hello.c
 *
 *    Description:  CURSOR>open mpi test
 *
 *        Version:  1.0
 *        Created:  2009年09月04日 16時09分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <mpi.h>
int main(int argc, char *argv[])
{
  int rank;
  MPI_Status status;
  char buf[256];
  char data[] = "Hello";
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if (rank == 0) {
    MPI_Send(data, 5, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
  } else if (rank == 1) {
    MPI_Recv(buf, 5, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
    printf("%s\n",buf);
  }
  MPI_Finalize();
}
