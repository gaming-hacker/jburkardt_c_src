# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "simplex_coordinates.h"

int main ( );
void simplex_coordinates1_test ( int n );
void simplex_coordinates2_test ( int n );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for SIMPLEX_COORDINATES_TEST.

  Discussion:

    SIMPLEX_COORDINATES_TEST tests the SIMPLEX_COORDINATES library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 September 2010

  Author:

    John Burkardt
*/
{
  int n;

  timestamp ( );
  printf ( "\n" );
  printf ( "SIMPLEX_COORDINATES_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the SIMPLEX_COORDINATES library.\n" );

  n = 3;
  simplex_coordinates1_test ( n );
  simplex_coordinates2_test ( n );

  n = 4;
  simplex_coordinates1_test ( n );
  simplex_coordinates2_test ( n );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SIMPLEX_COORDINATES_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void simplex_coordinates1_test ( int n )

/******************************************************************************/
/*
  Purpose:

    SIMPLEX_COORDINATES1_TEST tests SIMPLEX_COORDINATES1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 September 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the spatial dimension.
*/
{
  int i;
  int j;
  int k;
  double side;
  double volume;
  double volume2;
  double *x;
  double *xtx;

  printf ( "\n" );
  printf ( "SIMPLEX_COORDINATES1_TEST\n" );
  printf ( "  SIMPLEX_COORDINATES1 computes the coordinates of a regular simplex.\n" );

  x = simplex_coordinates1 ( n );

  r8mat_transpose_print ( n, n + 1, x, "  Simplex vertex coordinates:" );

  side = 0.0;
  for ( i = 0; i < n; i++ )
  {
    side = side + pow ( x[i+0*n] - x[i+1*n], 2 );
  }
  side = sqrt ( side );

  volume = simplex_volume ( n, x );

  volume2 = sqrt ( ( double ) ( n + 1 ) ) / r8_factorial ( n ) 
    / sqrt ( pow ( 2.0, n ) ) * pow ( side, n );

  printf ( "\n" );
  printf ( "  Side length =     %f\n", side );
  printf ( "  Volume =          %f\n", volume );
  printf ( "  Expected volume = %f\n", volume2 );

  xtx = ( double * ) malloc ( ( n + 1 ) * ( n + 1 ) * sizeof ( double ) );

  for ( j = 0; j < n + 1; j++ )
  {
    for ( i = 0; i < n + 1; i++ )
    {
      xtx[i+j*(n+1)] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        xtx[i+j*(n+1)] = xtx[i+j*(n+1)] + x[k+i*n] * x[k+j*n];
      }
    }
  }

  r8mat_transpose_print ( n + 1, n + 1, xtx, "  Dot product matrix:" );

  free ( x );
  free ( xtx );

  return;
}
/******************************************************************************/

void simplex_coordinates2_test ( int n )

/******************************************************************************/
/*
  Purpose:

    SIMPLEX_COORDINATES2_TEST tests SIMPLEX_COORDINATES2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 September 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N, the spatial dimension.
*/
{
  int i;
  int j;
  int k;
  double side;
  double volume;
  double volume2;
  double *x;
  double *xtx;

  printf ( "\n" );
  printf ( "SIMPLEX_COORDINATES2_TEST\n" );
  printf ( "  SIMPLEX_COORDINATES2 computes the coordinates of a regular simplex.\n" );

  x = simplex_coordinates2 ( n );

  r8mat_transpose_print ( n, n + 1, x, "  Simplex vertex coordinates:" );

  side = 0.0;
  for ( i = 0; i < n; i++ )
  {
    side = side + pow ( x[i+0*n] - x[i+1*n], 2 );
  }
  side = sqrt ( side );

  volume = simplex_volume ( n, x );

  volume2 = sqrt ( ( double ) ( n + 1 ) ) / r8_factorial ( n ) 
    / sqrt ( pow ( 2.0, n ) ) * pow ( side, n );

  printf ( "\n" );
  printf ( "  Side length =     %f\n", side );
  printf ( "  Volume =          %f\n", volume );
  printf ( "  Expected volume = %f\n", volume2 );

  xtx = ( double * ) malloc ( ( n + 1 ) * ( n + 1 ) * sizeof ( double ) );

  for ( j = 0; j < n + 1; j++ )
  {
    for ( i = 0; i < n + 1; i++ )
    {
      xtx[i+j*(n+1)] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        xtx[i+j*(n+1)] = xtx[i+j*(n+1)] + x[k+i*n] * x[k+j*n];
      }
    }
  }

  r8mat_transpose_print ( n + 1, n + 1, xtx, "  Dot product matrix:" );

  free ( x );
  free ( xtx );

  return;
}
