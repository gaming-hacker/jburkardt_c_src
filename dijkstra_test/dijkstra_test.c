# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# include "dijkstra.h"

int main ( int argc, char **argv );
int *init ( int nv );

/******************************************************************************/

int main ( int argc, char **argv )

/******************************************************************************/
/*
  Purpose:

    dijkstra_test runs an example of Dijkstra's minimum distance algorithm.

  Discussion:

    Given the distance matrix that defines a graph, we seek a list
    of the minimum distances between node 0 and all other nodes.

    This program sets up a small example problem and solves it.

    The correct minimum distances are:

      0   35   15   45   49   41

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 June 2010

  Author:

    Original C version by Norm Matloff, CS Dept, UC Davis.
    This C version by John Burkardt.
*/
{
  int i;
  int i4_huge = 2147483647;
  int j;
  int *mind;
  int nv;
  int *ohd;

  timestamp ( );
  printf ( "\n" );
  printf ( "dijkstra_test\n" );
  printf ( "  C version\n" );
  printf ( "  Test dijkstra(), using Dijkstra's algorithm to determine the minimum\n" );
  printf ( "  distance from node 0 to each node in a graph,\n" );
  printf ( "  given the distances between each pair of nodes.\n" );
/*
  Initialize the problem data.
*/
  nv = 6;
  ohd = init ( nv );
/*
  Print the distance matrix.
*/
  printf ( "\n" );
  printf ( "  Distance matrix:\n" );
  printf ( "\n" );
  for ( i = 0; i < nv; i++ )
  {
    for ( j = 0; j < nv; j++ )
    {
      if ( ohd[i+j*nv] == i4_huge )
      {
        printf ( "  Inf" );
      }
      else
      {
        printf ( "  %3d", ohd[i+j*nv] );
      }
    }
    printf ( "\n" );
  }
/*
  Carry out the algorithm.
*/
  mind = dijkstra_distance ( nv, ohd );
/*
  Print the results.
*/
  printf ( "\n" );
  printf ( "  Minimum distances from node 0:\n");
  printf ( "\n" );
  for ( i = 0; i < nv; i++ )
  {
    printf ( "  %2d  %2d\n", i, mind[i] );
  }
/*
  Free memory.
*/
  free ( mind );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "dijkstra_test\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

int *init ( int nv )

/******************************************************************************/
/*
  Purpose:

    INIT initializes the problem data.

  Discussion:

    The graph uses 6 nodes, and has the following diagram and
    distance matrix:

    N0--15--N2-100--N3           0   40   15  Inf  Inf  Inf
      \      |     /            40    0   20   10   25    6
       \     |    /             15   20    0  100  Inf  Inf
        40  20  10             Inf   10  100    0  Inf  Inf
          \  |  /              Inf   25  Inf  Inf    0    8
           \ | /               Inf    6  Inf  Inf    8    0
            N1
            / \
           /   \
          6    25
         /       \
        /         \
      N5----8-----N4

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2019

  Author:

    Original C version by Norm Matloff, CS Dept, UC Davis.
    This C version by John Burkardt.

  Parameters:

    Input, int NV, the number of nodes.

    Output, int INIT[6*6], the distance of the direct link between
    nodes I and J.
*/
{
  int i;
  int i4_huge = 2147483647;
  int j;
  int *ohd;

  ohd = ( int * ) malloc ( nv * nv * sizeof ( int ) );

  for ( i = 0; i < nv; i++ )  
  {
    for ( j = 0; j < nv; j++ )
    {
      if ( i == j )
      {
        ohd[i+j*nv] = 0;
      }
      else
      {
        ohd[i+j*nv] = i4_huge;
      }
    }
  }

  ohd[0+1*nv] = ohd[1+0*nv] = 40;
  ohd[0+2*nv] = ohd[2+0*nv] = 15;
  ohd[1+2*nv] = ohd[2+1*nv] = 20;
  ohd[1+3*nv] = ohd[3+1*nv] = 10;
  ohd[1+4*nv] = ohd[4+1*nv] = 25;
  ohd[2+3*nv] = ohd[3+2*nv] = 100;
  ohd[1+5*nv] = ohd[5+1*nv] = 6;
  ohd[4+5*nv] = ohd[5+4*nv] = 8;

  return ohd;
}

