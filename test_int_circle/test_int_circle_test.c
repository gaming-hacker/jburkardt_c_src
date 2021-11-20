# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "test_int_circle.h"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TEST_INT_CIRCLE_TEST.

  Discussion:

    TEST_INT_CIRCLE_TEST tests the TEST_INT_CIRCLE library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2013

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TEST_INT_CIRCLE_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TEST_INT_CIRCLE library.\n" );

  test01 ( );
  test02 ( );
  test03 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TEST_INT_CIRCLE_TEST\n" );
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

    TEST01: integral of X^E in the unit circle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 December 2013

  Author:

    John Burkardt
*/
{
  int e;
  double *f;
  int n;
  int n_log2;
  double q;
  int seed;
  double t;
  double *xy;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Use a simple Monte Carlo approach to estimate the\n" );
  printf ( "  integral of X^E over the circle of radius 1\n" );
  printf ( "  centered at the origin.\n" );
  printf ( "\n" );
  printf ( "           N   E       Exact Approximate   Error\n" );

  for ( e = 2; e <= 6; e = e + 2 )
  {
    printf ( "\n" );
    p01_param_set ( e );
    n = 1;
    for ( n_log2 = 0; n_log2 <= 20; n_log2++ )
    {
      seed = 123456789;
      xy = circle_unit_sample ( n, &seed );
      f = p01_f ( n, xy );
      q = circle_unit_area ( ) * r8vec_sum ( n, f ) / ( double ) ( n );
      t = p01_exact ( );
      printf ( "  %10d  %2d  %10.4f  %10.4f  %10.4e\n",
        n, e, t, q, fabs ( t - q ) );
      free ( f );
      free ( xy );
      n = n * 2;
    }
  }

  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02: integral of R^E in the unit circle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 December 2013

  Author:

    John Burkardt
*/
{
  int e;
  double *f;
  int n;
  int n_log2;
  double q;
  int seed;
  double t;
  double *xy;

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Use a simple Monte Carlo approach to estimate the\n" );
  printf ( "  integral of R^E over the circle of radius 1\n" );
  printf ( "  centered at the origin.\n" );
  printf ( "\n" );
  printf ( "           N   E       Exact Approximate   Error\n" );

  for ( e = 1; e <= 5; e = e + 2 )
  {
    printf ( "\n" );
    p02_param_set ( e );
    n = 1;
    for ( n_log2 = 0; n_log2 <= 20; n_log2++ )
    {
      seed = 123456789;
      xy = circle_unit_sample ( n, &seed );
      f = p02_f ( n, xy );
      q = circle_unit_area ( ) * r8vec_sum ( n, f ) / ( double ) ( n );
      t = p02_exact ( );
      printf ( "  %10d  %2d  %10.4f  %10.4f  %10.4e\n",
        n, e, t, q, fabs ( t - q ) );
      free ( f );
      free ( xy );
      n = n * 2;
    }
  }

  return;
}
/******************************************************************************/

void test03 ( )

/******************************************************************************/
/*
  Purpose:

    TEST03: integral of exp(x) in the unit circle.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 December 2013

  Author:

    John Burkardt
*/
{
  int e;
  double *f;
  int n;
  int n_log2;
  double q;
  int seed;
  double t;
  double *xy;

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  Use a simple Monte Carlo approach to estimate the\n" );
  printf ( "  integral of exp(X) over the circle of radius 1\n" );
  printf ( "  centered at the origin.\n" );
  printf ( "\n" );
  printf ( "           N       Exact Approximate   Error\n" );
  printf ( "\n" );

  n = 1;
  for ( n_log2 = 0; n_log2 <= 20; n_log2++ )
  {
    seed = 123456789;
    xy = circle_unit_sample ( n, &seed );
    f = p03_f ( n, xy );
    q = circle_unit_area ( ) * r8vec_sum ( n, f ) / ( double ) ( n );
    t = p03_exact ( );
    printf ( "  %10d  %10.4f  %10.4f  %e10.4\n",
      n, t, q, fabs ( t - q ) );
    free ( f );
    free ( xy );
    n = n * 2;
  }

  return;
}
