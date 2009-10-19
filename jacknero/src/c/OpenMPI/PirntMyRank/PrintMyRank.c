/*
 * =====================================================================================
 *
 *       Filename:  PrintMyRank.c
 *
 *    Description:  CURSOR>this is print my rank in mpi
 *
 *        Version:  1.0
 *        Created:  2009年09月04日 16時54分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <mpi.h>
int main(int argc, char **argv)
{
  int numprocs;
    int myrank;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    printf("My rank is %d in %d\n",myrank,numprocs);
  MPI_Finalize();
  return 0;
}
