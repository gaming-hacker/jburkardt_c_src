# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "besselj.h"

int main ( );

void rjbesl_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for BESSELJ_TEST.

  Discussion:

    BESSELJ_TEST tests the BESSELJ library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 January 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "BESSELJ_TEST:\n" );
  printf ( "  C version,\n" );
  printf ( "  Test BESSELJ.\n" );

  rjbesl_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "BESSELJ_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void rjbesl_test ( )

/******************************************************************************/
/*
  Purpose:

    RJBESL_TEST tests RJBESL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 June 2019

  Author:

    John Burkardt
*/
{
  double alpha;
  double *b;
  double err;
  double fx;
  int n;
  int n_data;
  int nb;
  int ncalc;
  double order;
  double x;

  printf ( "\n" );
  printf ( "RJBESL_TEST:\n" );
  printf ( "  RJBESL computes the Bessel Jn function for NONINTEGER order.\n" );
  printf ( "\n" );
  printf ( "         ORDER             X                       FX                         FX          Error\n" );
  printf ( "                                                 exact                  computed\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_jx_values ( &n_data, &order, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    n = ( int ) ( order );
    alpha = order - ( double ) ( n );
    nb = n + 1;
    b = ( double * ) malloc ( nb * sizeof ( double ) );
    rjbesl ( x, alpha, nb, b, &ncalc );
    err = fabs ( fx - b[n] );
    printf ( "  %12g  %12g  %24.16g  %24.16g  %12.6g\n", order, x, fx, b[n], err );
    free ( b );
  }
  return;
}
