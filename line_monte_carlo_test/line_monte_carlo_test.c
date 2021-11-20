# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "line_monte_carlo.h"

int main ( );
void line01_sample_random_test ( );
void line01_sample_ergodic_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for LINE_MONTE_CARLO_TEST.

  Discussion:

    LINE_MONTE_CARLO_TEST tests the LINE_MONTE_CARLO library.
    
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 June 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "LINE_MONTE_CARLO_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the LINE_MONTE_CARLO library.\n" );

  line01_sample_random_test ( );
  line01_sample_ergodic_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "LINE_MONTE_CARLO_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void line01_sample_random_test ( )

/******************************************************************************/
/*
  Purpose:

    LINE01_SAMPLE_RANDOM_TEST compares exact and estimated monomial integrals.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 June 2017

  Author:

    John Burkardt
*/
{
  int e;
  double error;
  double exact;
  int n = 4192;
  double result;
  int seed;
  int test;
  int test_num = 11;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "LINE01_SAMPLE_RANDOM_TEST\n" );
  printf ( "  LINE01_SAMPLE_RANDOM randomly samples the unit line segment. \n" );
  printf ( "  Use it to estimate integrals.\n" );
/*
  Get sample points.
*/
  seed = 123456789;
  x = line01_sample_random ( n, &seed );

  printf ( "\n" );
  printf ( "  Number of sample points used is %d\n", n );
  printf ( "\n" );
  printf ( "   E     MC-Estimate      Exact           Error\n" );
  printf ( "\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    e = test - 1;

    value = monomial_value_1d ( n, e, x );

    result = line01_length ( ) * r8vec_sum ( n, value ) / ( double ) ( n );
    exact = line01_monomial_integral ( e );
    error = fabs ( result - exact );

    printf ( "  %2d  %14.6g  %14.6g  %10.2e\n", e, result, exact, error );

    free ( value );
  }

  free ( x );

  return;
}
/******************************************************************************/

void line01_sample_ergodic_test ( )

/******************************************************************************/
/*
  Purpose:

    LINE01_SAMPLE_ERGODIC_TEST compares exact and estimated monomial integrals.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 June 2017

  Author:

    John Burkardt
*/
{
  int e;
  double error;
  double exact;
  int n = 4192;
  double result;
  double shift;
  int test;
  int test_num = 11;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "LINE01_SAMPLE_ERGODIC_TEST\n" );
  printf ( "  LINE01_SAMPLE_ERGODIC ergodically samples the unit line segment. \n" );
  printf ( "  Use it to estimate integrals.\n" );
/*
  Get sample points.
*/
  shift = 0.0;
  x = line01_sample_ergodic ( n, &shift );

  printf ( "\n" );
  printf ( "  Number of sample points used is %d\n", n );
  printf ( "\n" );
  printf ( "   E     MC-Estimate      Exact           Error\n" );
  printf ( "\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    e = test - 1;

    value = monomial_value_1d ( n, e, x );

    result = line01_length ( ) * r8vec_sum ( n, value ) / ( double ) ( n );
    exact = line01_monomial_integral ( e );
    error = fabs ( result - exact );

    printf ( "  %2d  %14.6g  %14.6g  %10.2e\n", e, result, exact, error );

    free ( value );
  }

  free ( x );

  return;
}
