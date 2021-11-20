# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "disk01_quarter_monte_carlo.h"

int main ( );
void test01 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for DISK01_QUARTER_MONTE_CARLO_TEST.

  Discussion:

    DISK01_QUARTER_MONTE_CARLO_TEST tests the DISK01_QUARTER_MONTE_CARLO library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "DISK01_QUARTER_MONTE_CARLO_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the DISK01_QUARTER_MONTE_CARLO library.\n" );

  test01 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "DISK01_QUARTER_MONTE_CARLO_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( )

/******************************************************************************/
/*
  Purpose:

    TEST01 uses DISK01_QUARTER_SAMPLE with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2014

  Author:

    John Burkardt
*/
{
  int e[2];
  double err;
  double exact;
  int i;
  int j;
  int n;
  double q;
  int seed;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Use DISK01_QUARTER_SAMPLE to estimate integrals\n" );
  printf ( " in the unit disk.\n" );

  for ( i = 0; i <= 4; i++ )
  {
    e[0] = i;
    for ( j = 0; j <= 4 - e[0]; j++ )
    {
      e[1] = j;
      exact = disk01_quarter_monomial_integral ( e );
      printf ( "\n" );
      printf ( "  Estimate integral of X^%dY^%d\n", e[0], e[1] );
      printf ( "\n" );
      printf ( "         N        Estimate       Error\n" );
      printf ( "\n" );

      n = 1;
      seed = 123456789;

      while ( n <= 65536 )
      {
        x = disk01_quarter_sample ( n, &seed );

        value = monomial_value ( 2, n, e, x );

        q = disk01_quarter_area ( ) * r8vec_sum ( n, value ) / ( double ) ( n );

        err = fabs ( q - exact );
        printf ( "  %8d  %14.6g  %10.2e\n", n, q, err );

        free ( value );
        free ( x );

        n = 2 * n;
      }
      printf ( "    Exact:  %14.6g  %10.2e\n", exact, 0.0 );
    }
  }

  return;
}
