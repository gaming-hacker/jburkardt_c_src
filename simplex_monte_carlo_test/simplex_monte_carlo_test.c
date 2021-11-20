# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "simplex_monte_carlo.h"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for SIMPLEX_MONTE_CARLO_TEST.

  Discussion:

    SIMPLEX_MONTE_CARLO_TEST tests the SIMPLEX_MONTE_CARLO library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2014

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "SIMPLEX_MONTE_CARLO_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the SIMPLEX_MONTE_CARLO library.\n" );

  test01 ( );
  test02 ( );
  test03 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SIMPLEX_MONTE_CARLO_TEST\n" );
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

    TEST01 uses SIMPLEX_UNIT_SAMPLE to estimate integrals in 3D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2014

  Author:

    John Burkardt
*/
{
  int e[3];
  int e_test[3*10] = {
    0, 0, 0, 
    1, 0, 0, 
    0, 1, 0, 
    0, 0, 1, 
    2, 0, 0,
    1, 1, 0,
    1, 0, 1, 
    0, 2, 0, 
    0, 1, 1, 
    0, 0, 2 };
  int i;
  int j;
  const int m = 3;
  int n;
  double result;
  int seed;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Use SIMPLEX_UNIT_SAMPLE for a Monte Carlo estimate of an\n" );
  printf ( "  integral over the interior of the unit simplex in 3D.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "         N        1               X               Y " );
  printf ( "              Z               X^2              XY             XZ" );
  printf ( "              Y^2             YZ               Z^2\n" );
  printf ( "\n" );

  n = 1;

  while ( n <= 65536 )
  {
    x = simplex_unit_sample ( m, n, &seed );

    printf ( "  %8d", n );
    for ( j = 0; j < 10; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        e[i] = e_test[i+j*m];
      }
      value = monomial_value ( m, n, e, x );

      result = simplex_unit_volume ( m ) * r8vec_sum ( n, value ) 
        / ( double ) ( n );

      printf ( "  %14.6g", result );

      free ( value );
    }

    printf ( "\n" );

    free ( x );

    n = 2 * n;
  }

  printf ( "\n" );
  printf ( "     Exact" );

  for ( j = 0; j < 10; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      e[i] = e_test[i+j*m];
    }

    result = simplex_unit_monomial_integral ( m, e );
    printf ( "  %14.6g", result );
  }

  printf ( "\n" );

  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 uses SIMPLEX_UNIT_SAMPLE to estimate integrals in 6D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2014

  Author:

    John Burkardt
*/
{
  int e[6];
  int e_test[6*7] = {
    0, 0, 0, 0, 0, 0, 
    1, 0, 0, 0, 0, 0, 
    0, 2, 0, 0, 0, 0, 
    0, 2, 2, 0, 0, 0, 
    0, 0, 0, 4, 0, 0, 
    2, 0, 0, 0, 2, 2, 
    0, 0, 0, 0, 0, 6 };
  int i;
  int j;
  const int m = 6;
  int n;
  double result;
  int seed;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Use SIMPLEX_UNIT_SAMPLE for a Monte Carlo estimate of an\n" );
  printf ( "  integral over the interior of the unit simplex in 6D.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "         N" );
  printf ( "        1      " );
  printf ( "        U      " );
  printf ( "         V^2    " );
  printf ( "         V^2W^2 " );
  printf ( "         X^4    " );
  printf ( "         Y^2Z^2 " );
  printf ( "         Z^6\n" );
  printf ( "\n" );

  n = 1;

  while ( n <= 65536 )
  {
    x = simplex_unit_sample ( m, n, &seed );

    printf ( "  %8d", n );
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        e[i] = e_test[i+j*m];
      }
      value = monomial_value ( m, n, e, x );

      result = simplex_unit_volume ( m ) * r8vec_sum ( n, value ) 
        / ( double ) ( n );

      printf ( "  %14.6g", result );

      free ( value );
    }

    printf ( "\n" );

    free ( x );

    n = 2 * n;
  }

  printf ( "\n" );
  printf ( "     Exact" );

  for ( j = 0; j < 7; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      e[i] = e_test[i+j*m];
    }

    result = simplex_unit_monomial_integral ( m, e );
    printf ( "  %14.6g", result );
  }

  printf ( "\n" );

  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03 uses SIMPLEX_GENERAL_SAMPLE to estimate integrals in 3D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 March 2017

  Author:

    John Burkardt
*/
{
  int e[3];
  int e_test[3*10] = {
    0, 0, 0, 
    1, 0, 0, 
    0, 1, 0, 
    0, 0, 1, 
    2, 0, 0,
    1, 1, 0,
    1, 0, 1, 
    0, 2, 0, 
    0, 1, 1, 
    0, 0, 2 };
  int i;
  int j;
  const int m = 3;
  int n;
  double result;
  int seed;
  double t[3*4] = {
    1.0, 0.0, 0.0, 
    2.0, 0.0, 0.0, 
    1.0, 2.0, 0.0, 
    1.0, 0.0, 3.0 };
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  SIMPLEX_GENERAL_SAMPLE computes a Monte Carlo estimate of an\n" );
  printf ( "  integral over the interior of a general simplex in 3D.\n" );

  printf ( "\n" );
  printf ( "  Simplex vertices:\n" );
  printf ( "\n" );
  for ( j = 0; j < 4; j++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      printf ( "  %14.6g", t[i+j*3] );
    }
    printf ( "\n" );
  }

  seed = 123456789;

  printf ( "\n" );
  printf ( "         N        1               X               Y " );
  printf ( "              Z               X^2              XY             XZ" );
  printf ( "              Y^2             YZ               Z^2\n" );
  printf ( "\n" );

  n = 1;

  while ( n <= 65536 )
  {
    x = simplex_general_sample ( m, n, t, &seed );

    printf ( "  %8d", n );
    for ( j = 0; j < 10; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        e[i] = e_test[i+j*m];
      }
      value = monomial_value ( m, n, e, x );

      result = simplex_general_volume ( m, t ) * r8vec_sum ( n, value ) 
        / ( double ) ( n );

      printf ( "  %14.6g", result );

      free ( value );
    }

    printf ( "\n" );

    free ( x );

    n = 2 * n;
  }

  return;
}
