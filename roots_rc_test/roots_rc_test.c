# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "roots_rc.h"

int main ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ROOTS_RC_TEST.

  Discussion:

    ROOTS_RC_TEST tests ROOTS_RC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2016

  Author:

    John Burkardt
*/
{
  double ferr;
  double *fx;
  int i;
  int it;
  int it_max = 30;
  int j;
  int n = 4;
  double *q;
  double *x;
  double *xnew;

  timestamp ( );
  printf ( "\n" );
  printf ( "ROOTS_RC_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  ROOTS_RC seeks a solution of\n" );
  printf ( "  the N-dimensional nonlinear system F(X) = 0, using reverse communication.\n" );

  fx = ( double * ) malloc ( n * sizeof ( double ) );
  q = ( double * ) malloc ( ( 2 * n + 2 ) * ( n + 2 ) * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  xnew = ( double * ) malloc ( n * sizeof ( double ) );

  printf ( "\n" );
  printf ( "       FERR          X\n" );
  printf ( "\n" );
/*
  Initialization.
*/
  for ( j = 0; j < n + 2; j++ )
  {
    for ( i = 0; i < 2 * n + 2; i++ )
    {
      q[i+j*(2*n+2)] = 0.0;
    }
  }

  xnew[0] = 1.2;
  for ( i = 1; i < n; i++ )
  {
    xnew[i] = 1.0;
  }

  it = 0;

  for ( ; ; )
  {
    for ( i = 0; i < n; i++ )
    {
      x[i] = xnew[i];
    }

    fx[0] = 1.0 - x[0];
    for ( i = 1; i < n; i++ )
    {
      fx[i] = 10.0 * ( x[i] - x[i-1] * x[i-1] );
    }

    if ( it == 0 )
    {
      printf ( "                " );
    }
    else
    {
      printf ( "  %14.6g", ferr );
    }
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %14.6g", x[i] );
    }
    printf ( "\n" );

    roots_rc ( n, x, fx, &ferr, xnew, q );

    if ( ferr < 1.0E-07 )
    {
      printf ( "\n" );
      printf ( "  Sum of |f(x)| less than tolerance.\n" );
      break;
    }

    if ( it_max < it )
    {
      printf ( "\n" );
      printf ( "  Too many iterations!\n" );
      break;
    }
    it = it + 1;
  }

  free ( fx );
  free ( q );
  free ( x );
  free ( xnew );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ROOTS_RC_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}

