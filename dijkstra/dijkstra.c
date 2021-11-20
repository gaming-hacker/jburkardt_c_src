# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# include "dijkstra.h"

/******************************************************************************/

int *dijkstra_distance ( int nv, int *ohd )

/******************************************************************************/
/*
  Purpose:

    DIJKSTRA_DISTANCE uses Dijkstra's minimum distance algorithm.

  Discussion:

    We essentially build a tree.  We start with only node 0 connected
    to the tree, and this is indicated by setting CONNECTED[0] = 1.

    We initialize MIND[I] to the one step distance from node 0 to node I.
    
    Now we search among the unconnected nodes for the node MV whose minimum
    distance is smallest, and connect it to the tree.  For each remaining
    unconnected node I, we check to see whether the distance from 0 to MV
    to I is less than that recorded in MIND[I], and if so, we can reduce
    the distance.

    After NV-1 steps, we have connected all the nodes to 0, and computed
    the correct minimum distances.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2019

  Author:

    Original C version by Norm Matloff, CS Dept, UC Davis.
    This C version by John Burkardt.

  Parameters:

    Input, int NV, the number of nodes.

    Input, int OHD[NV*NV], the distance of the direct link between
    nodes I and J.

    Output, int DIJKSTRA_DISTANCE[NV], the minimum distance from 
    node 0 to each node.
*/
{
  int *connected;
  int i;
  int j;
  int md;
  int *mind;
  int mv;
  int step; 
/*
  Start out with only node 0 connected to the tree.
*/
  connected = ( int * ) malloc ( nv * sizeof ( int ) );

  connected[0] = 1;
  for ( i = 1; i < nv; i++ )
  {
    connected[i] = 0;
  }
/*
  Initial estimate of minimum distance is the 1-step distance.
*/
  mind = ( int * ) malloc ( nv * sizeof ( int ) );

  for ( j = 0; j < nv; j++ )
  {
    mind[j] = ohd[0+j*nv];
  }
/*
  Attach one more node on each iteration.
*/
  for ( step = 1; step < nv; step++ )
  {
/*
  Find the nearest unconnected node.
*/
    find_nearest ( nv, mind, connected, &md, &mv );

    if ( mv == - 1 )
    {
      printf ( "\n" );
      printf ( "DIJKSTRA_DISTANCE - Warning!\n" );
      printf ( "  Search terminated early.\n" );
      printf ( "  Graph might not be connected.\n" );
      break;
    }
/*
  Mark this node as connected.
*/
    connected[mv] = 1;
/*
  Having determined the minimum distance to node MV, see if
  that reduces the minimum distance to other nodes.
*/
    update_mind ( nv, mv, connected, ohd, mind );
  }
/*
  Free memory.
*/
  free ( connected );

  return mind;
}
/******************************************************************************/

void find_nearest ( int nv, int *mind, int *connected, int *d, int *v )

/******************************************************************************/
/*
  Purpose:

    FIND_NEAREST finds the nearest unconnected node.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2019

  Author:

    Original C version by Norm Matloff, CS Dept, UC Davis.
    This C version by John Burkardt.

  Parameters:

    Input, int NV, the number of nodes.

    Input, int MIND[NV], the currently computed minimum distance from
    node 0 to each node.

    Input, int CONNECTED[NV], is 1 for each connected node, whose 
    minimum distance to node 0 has been determined.

    Output, int *D, the distance from node 0 to the nearest unconnected node.

    Output, int *V, the index of the nearest unconnected node.
*/
{
  int i;
  int i4_huge = 2147483647;

  *d = i4_huge;
  *v = -1;
  for ( i = 0; i < nv; i++ )
  {
    if ( ( ! connected[i] ) && ( mind[i] < *d ) )
    {
      *d = mind[i];
      *v = i;
    }
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

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 September 2003

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
/******************************************************************************/

void update_mind ( int nv, int mv, int *connected, int *ohd, int *mind )

/******************************************************************************/
/*
  Purpose:

    UPDATE_MIND updates the minimum distance vector.

  Discussion:

    We've just determined the minimum distance to node MV.

    For each node I which is not connected yet,
    check whether the route from node 0 to MV to I is shorter
    than the currently known minimum distance.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2019

  Author:

    Original C version by Norm Matloff, CS Dept, UC Davis.
    This C version by John Burkardt.

  Parameters:

    Input, int NV, the number of nodes.

    Input, int MV, the node whose minimum distance to node 0
    has just been determined.

    Input, int CONNECTED[NV], is 1 for each connected node, whose 
    minimum distance to node 0 has been determined.

    Input, int OHD[NV*NV], the distance of the direct link between
    nodes I and J.

    Input/output, int MIND[NV], the currently computed minimum distances
    from node 0 to each node.
*/
{
  int i;
  int i4_huge = 2147483647;

  for ( i = 0; i < nv; i++ )
  {
    if ( ! connected[i] )
    {
/*
  If we really use the maximum integer (or something close) to indicate
  no link, then we'll get burned if we add it to another value;
  Integer arithmetic can "wrap around", so that 17 + i4_huge becomes
  a very negative number!  So first we eliminate the possiblity that
  the link is infinite.
*/
      if ( ohd[mv+i*nv] < i4_huge )
      {
        if ( mind[mv] + ohd[mv+i*nv] < mind[i] )  
        {
          mind[i] = mind[mv] + ohd[mv+i*nv];
        }
      }
    }
  }
  return;
}

