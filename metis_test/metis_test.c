# include <stdio.h>
# include <time.h>

# include <metis.h>

int main ( );
void partgraphrecursive_test ( );
void partgraphkway_test ( );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    METIS_TEST tests the METIS library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2017
-
  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "METIS_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the METIS library for graph partitioning.\n" );

  partgraphrecursive_test ( );
  partgraphkway_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "METIS_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void partgraphrecursive_test ( )

/******************************************************************************/
/*
  Purpose:

    PARTGRAPHRECURSIVE_TEST tests PARTGRAPHRECURSIVE.

  Discussion:

    The graph has the following form:

      0 --- 1 --- 2
      |     |     |
      3 --- 4 --- 5

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2017

  Author:

    John Burkardt
*/
{
# define NVTXS 6
/*
  The number of vertices.
*/
  idx_t nvtxs = NVTXS;
/*
 Number of balancing constraints, which must be at least 1.
*/
  idx_t ncon = 1;
/*
  Pointers to initial entries in adjacency array.
*/
  idx_t xadj[NVTXS+1] = { 0, 2, 5, 7, 9, 12, 14 };
/*
  Adjacent vertices in consecutive index order.
*/
# define NEDGES 7
  idx_t adjncy[2 * NEDGES] = {1,3,0,4,2,1,5,0,4,3,1,5,4,2};
/*
  The number of parts requested for the partition.
*/
  idx_t nParts = 2;
/*
  On return, the edge cut volume of the partitioning solution.
*/
  idx_t objval;
/*
  On return, the partition vector for the graph.
*/
  idx_t part[NVTXS];

  printf ( "\n" );
  printf ( "PARTGRAPHRECURSIVE_TEST:\n" );
  printf ( "  METIS_PartGraphRecursive partitions a graph into K parts\n" );
  printf ( "  using multilevel recursive bisection.\n" );

  int ret = METIS_PartGraphRecursive ( &nvtxs, &ncon, xadj, adjncy, NULL, NULL, 
    NULL, &nParts, NULL, NULL, NULL, &objval, part );

  printf ( "\n" );
  printf ( "  Return code = %d\n", ret );
  printf ( "  Edge cuts for partition = %d\n", ( int ) objval );
    
  printf ( "\n" );
  printf ( "  Partition vector:\n" );
  printf ( "\n" );
  printf ( "  Node  Part\n" );
  printf ( "\n" );
  for ( unsigned part_i = 0; part_i < nvtxs; part_i++ )
  {
	printf ( "     %d     %d\n", part_i, ( int ) part[part_i] );
  }
  
  return;
}
/******************************************************************************/

void partgraphkway_test ( )

/******************************************************************************/
/*
  Purpose:

    PARTGRAPHKWAY_TEST tests PARTGRAPHKWAY.

  Discussion:

    The graph has the following form:

      0 --- 1 --- 2
      |     |     |
      3 --- 4 --- 5

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 February 2017

  Author:

    John Burkardt
*/
{
# define NVTXS 6
/*
  The number of vertices.
*/
  idx_t nvtxs = NVTXS;
/*
 Number of balancing constraints, which must be at least 1.
*/
  idx_t ncon = 1;
/*
  Pointers to initial entries in adjacency array.
*/
  idx_t xadj[NVTXS+1] = { 0, 2, 5, 7, 9, 12, 14 };
/*
  Adjacent vertices in consecutive index order.
*/
# define NEDGES 7
  idx_t adjncy[2 * NEDGES] = {1,3,0,4,2,1,5,0,4,3,1,5,4,2};
/*
  The number of parts requested for the partition.
*/
  idx_t nParts = 2;
/*
  On return, the edge cut volume of the partitioning solution.
*/
  idx_t objval;
/*
  On return, the partition vector for the graph.
*/
  idx_t part[NVTXS];

  printf ( "\n" );
  printf ( "PARTGRAPHKWAY_TEST:\n" );
  printf ( "  METIS_PartGraphKway partitions a graph into K parts\n" );
  printf ( "  using multilevel K-way partition.\n" );

  int ret = METIS_PartGraphKway ( &nvtxs, &ncon, xadj, adjncy, NULL, NULL, 
    NULL, &nParts, NULL, NULL, NULL, &objval, part );

  printf ( "\n" );
  printf ( "  Return code = %d\n", ret );
  printf ( "  Edge cuts for partition = %d\n", ( int ) objval );
    
  printf ( "\n" );
  printf ( "  Partition vector:\n" );
  printf ( "\n" );
  printf ( "  Node  Part\n" );
  printf ( "\n" );
  for ( unsigned part_i = 0; part_i < nvtxs; part_i++ )
  {
	printf ( "     %d     %d\n", part_i, ( int ) part[part_i] );
  }
    
  return;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    17 June 2014 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2014

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
