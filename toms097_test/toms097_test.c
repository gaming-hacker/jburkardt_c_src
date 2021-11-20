# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "toms097.h"

int main ( );
void i4mat_shortest_path_test ( );
void r8mat_shortest_path_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TOMS097_TEST.

  Discussion:

    TOMS097_TEST tests the TOMS097 library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 January 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TOMS097_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TOMS097 library.\n" );

  i4mat_shortest_path_test ( );
  r8mat_shortest_path_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TOMS097_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void i4mat_shortest_path_test ( )

/******************************************************************************/
/*
  Purpose:

    I4MAT_SHORTEST_PATH_TEST tests I4MAT_SHORTEST_PATH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 March 2014

  Author:

    John Burkardt
*/
{
# define N 6

  int a[N*N] = {
     0, -1, -1, -1, -1, -1, 
     2,  0, -1, -1, -1,  5, 
     5,  7,  0, -1,  2, -1, 
    -1,  1,  4,  0, -1,  2, 
    -1, -1, -1,  3,  0,  4, 
    -1,  8, -1, -1,  3,  0  };
  int i;
  int j;
  int n = N;

  printf ( "\n" );
  printf ( "I4MAT_SHORTEST_PATH_TEST\n" );
  printf ( "  I4MAT_SHORTEST_PATH uses Floyd''s algorithm to find the\n" );
  printf ( "  shortest distance between all pairs of nodes\n" );
  printf ( "  in a directed graph, starting from the initial array\n" );
  printf ( "  of direct node-to-node distances.\n" );

  printf ( "\n" );
  printf ( "  In the initial direct distance array, if\n" );
  printf ( "    A(I,J) = HUGE,\n" );
  printf ( "  this indicates there is NO directed link from\n" );
  printf ( "  node I to node J.  In that case, the value of\n" );
  printf ( "  of A(I,J) is essentially 'infinity'.\n" );

  printf ( "\n" );
  printf ( "  Initial direct-link distance matrix:\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      printf ( "%6d", a[i+j*n] );
    }
    printf ( "\n" );
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( a[i+j*n] == -1 )
      {
        a[i+j*n] = i4_huge ( );
      }
    }
  } 

  i4mat_shortest_path ( n, a );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( a[i+j*n] == i4_huge ( ) )
      {
        a[i+j*n] = -1;
      }
    }
  }

  printf ( "\n" );
  printf ( "  In the final shortest distance array, if\n" );
  printf ( "    A(I,J) = -1,\n" );
  printf ( "  this indicates there is NO directed path from\n" );
  printf ( "  node I to node J.\n" );

  printf ( "\n" );
  printf ( "  Final distance matrix:\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      printf ( "%6d", a[i+j*n] );
    }
    printf ( "\n" );
  }

  return;
# undef N
}
/******************************************************************************/

void r8mat_shortest_path_test ( )

/******************************************************************************/
/*
  Purpose:

    R8MAT_SHORTEST_PATH_TEST tests R8MAT_SHORTEST_PATH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 March 2014

  Author:

    John Burkardt
*/
{
# define N 6

  double a[N*N] = {
     0.0, -1.0, -1.0, -1.0, -1.0, -1.0, 
     2.0,  0.0, -1.0, -1.0, -1.0,  5.0, 
     5.0,  7.0,  0.0, -1.0,  2.0, -1.0, 
    -1.0,  1.0,  4.0,  0.0, -1.0,  2.0, 
    -1.0, -1.0, -1.0,  3.0,  0.0,  4.0, 
    -1.0,  8.0, -1.0, -1.0,  3.0,  0.0  };
  int i;
  int j;
  int n = N;

  printf ( "\n" );
  printf ( "R8MAT_SHORTEST_PATH_TEST\n" );
  printf ( "  R8MAT_SHORTEST_PATH uses Floyd''s algorithm to find the\n" );
  printf ( "  shortest distance between all pairs of nodes\n" );
  printf ( "  in a directed graph, starting from the initial array\n" );
  printf ( "  of direct node-to-node distances.\n" );

  printf ( "\n" );
  printf ( "  In the initial direct distance array, if\n" );
  printf ( "    A(I,J) = -1,\n" );
  printf ( "  this indicates there is NO directed link from\n" );
  printf ( "  node I to node J.  In that case, the value of\n" );
  printf ( "  of A(I,J) is essentially 'infinity'.\n" );

  printf ( "\n" );
  printf ( "  Initial direct-link distance matrix:\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      printf ( "%10.4f", a[i+j*n] );
    }
    printf ( "\n" );
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( a[i+j*n] == -1.0 )
      {
        a[i+j*n] = r8_huge ( );
      }
    }
  } 

  r8mat_shortest_path ( n, a );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( a[i+j*n] == r8_huge ( ) )
      { 
        a[i+j*n] = -1.0;
      }
    }
  }

  printf ( "\n" );
  printf ( "  In the final shortest distance array, if\n" );
  printf ( "    A(I,J) = -1,\n" );
  printf ( "  this indicates there is NO directed path from\n" );
  printf ( "  node I to node J.\n" );

  printf ( "\n" );
  printf ( "  Final distance matrix:\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      printf ( "%10.4f", a[i+j*n] );
    }
    printf ( "\n" );
  }

  return;
}
