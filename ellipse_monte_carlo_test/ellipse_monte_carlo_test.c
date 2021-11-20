# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "ellipse_monte_carlo.h"

int main ( );
void ellipse_area1_test ( );
void ellipse_area2_test ( );
void test01 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ELLIPSE_MONTE_CARLO_TEST.

  Discussion:

    ELLIPSE_MONTE_CARLO_TEST tests the ELLIPSE_MONTE_CARLO library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 November 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ELLIPSE_MONTE_CARLO_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the ELLIPSE_MONTE_CARLO library.\n" );

  ellipse_area1_test ( );
  ellipse_area2_test ( );
  test01 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ELLIPSE_MONTE_CARLO_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void ellipse_area1_test ( )

/******************************************************************************/
/*
  Purpose:

    ELLIPSE_AREA1_TEST tests ELLIPSE_AREA1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 November 2016

  Author:

    John Burkardt
*/
{
  double a[2*2] = { 5.0, 1.0, 1.0, 2.0 };
  double area;
  double r;

  printf ( "\n" );
  printf ( "ELLIPSE_AREA1_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  ELLIPSE_AREA1 computes the area of an ellipse.\n" );

  r = 10.0;

  area = ellipse_area1 ( a, r );

  printf ( "\n" );
  printf ( "  R = %g\n", r );
  r8mat_print ( 2, 2, a, "  Matrix A in ellipse definition x*A*x=r^2" );
  printf ( "  Area = %g\n", area );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ELLIPSE_AREA1_TEST\n" );
  printf ( "  Normal end of execution.\n" );

  return;
}
/******************************************************************************/

void ellipse_area2_test ( )

/******************************************************************************/
/*
  Purpose:

    ELLIPSE_AREA2_TEST tests ELLIPSE_AREA2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 November 2016

  Author:

    John Burkardt
*/
{
  double a;
  double area;
  double b;
  double c;
  double d;
 
  printf ( "\n" );
  printf ( "ELLIPSE_AREA2_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  ELLIPSE_AREA2 computes the area of an ellipse.\n" );

  a = 5.0;
  b = 2.0;
  c = 2.0;
  d = 10.0;

  area = ellipse_area2 ( a, b, c, d );

  printf ( "\n" );
  printf ( "  Ellipse: %g * x^2 + %g * xy + %g * y^2 = %g\n", a, b, c, d );
  printf ( "  Area = %g\n", area );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ELLIPSE_AREA2_TEST\n" );
  printf ( "  Normal end of execution.\n" );

  return;
}
/******************************************************************************/

void test01 ( )

/******************************************************************************/
/*
  Purpose:

    TEST01 uses ELLIPSE01_SAMPLE with an increasing number of points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 April 2014

  Author:

    John Burkardt
*/
{
  double a[2*2] = { 9.0, 1.0, 1.0, 4.0 };
  int e[2];
  int e_test[2*7] = {
    0, 0, 
    1, 0, 
    0, 1, 
    2, 0, 
    1, 1, 
    0, 2, 
    3, 0 };
  int j;
  int n;
  double r = 2.0;
  double result;
  int seed;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Use ELLIPSE01_SAMPLE to estimate integrals\n" );
  printf ( "  in the ellipse x' * A * x <= r^2.\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "         N        1              X               Y  " );
  printf ( "             X^2               XY             Y^2             X^3\n" );
  printf ( "\n" );

  n = 1;

  while ( n <= 65536 )
  {

    x = ellipse_sample ( n, a, r, &seed );

    printf ( "  %8d", n );

    for ( j = 0; j < 7; j++ )
    {
      e[0] = e_test[0+j*2];
      e[1] = e_test[1+j*2];
 
      value = monomial_value ( 2, n, e, x );

      result = ellipse_area1 ( a, r ) * r8vec_sum ( n, value ) 
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
