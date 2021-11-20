# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "triangle01_integrals.h"

int main ( );
void test01 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TRIANGLE01_INTEGRALS_TEST.

  Discussion:

    TRIANGLE01_INTEGRALS_TEST tests the TRIANGLE01_INTEGRALS library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 January 2014

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TRIANGLE01_INTEGRALS_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TRIANGLE01_INTEGRALS library.\n" );

  test01 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TRIANGLE01_INTEGRALS_TEST\n" );
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

    TEST01 uses TRIANGLE01_SAMPLE to compare exact and estimated monomial integrals.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 January 2014

  Author:

    John Burkardt
*/
{
  int e[2];
  double error;
  double exact;
  int i;
  int j;
  int m = 2;
  int n = 4192;
  double result;
  int seed;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Estimate monomial integrals using Monte Carlo\n" );
  printf ( "  over the interior of the unit triangle in 2D.\n" );
/*
  Get sample points.
*/
  seed = 123456789;
  x = triangle01_sample ( n, &seed );

  printf ( "\n" );
  printf ( "  Number of sample points used is %d\n", n );
/*
  Randomly choose X, Y exponents.
*/
  printf ( "\n" );
  printf ( "  We will restrict this test to randomly chosen even exponents.\n" );
  printf ( "\n" );
  printf ( "  Ex  Ey     MC-Estimate      Exact           Error\n" );
  printf ( "\n" );

  for ( i = 0; i <= 4; i++ )
  {
    e[0] = i;
    for ( j = 0; j <= 4; j++ )
    {
      e[1] = j;

      value = monomial_value ( m, n, e, x );

      result = triangle01_area ( ) * r8vec_sum ( n, value ) / ( double ) ( n );
      exact = triangle01_monomial_integral ( e );
      error = fabs ( result - exact );

      printf ( "  %2d  %2d  %14.6g  %14.6g  %10.2e\n",
        e[0], e[1], result, exact, error );

      free ( value );
    }
  }

  free ( x );

  return;
}
