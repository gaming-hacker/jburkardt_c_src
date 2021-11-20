# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "llsq.h"

int main ( );
void test01 ( );
void test02 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for LLSQ_TEST.

  Discussion:

    LLSQ_TEST tests the LLSQ library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 January 2019

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "LLSQ_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the LLSQ library.\n" );

  test01 ( );
  test02 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "LLSQ_TEST\n" );
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

    TEST01 calls LLSQ to match 15 data values.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 March 2012

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double error;
  int i;
  int n = 15;
  double x[15] = { 
    1.47, 1.50, 1.52, 1.55, 1.57, 1.60, 1.63, 1.65, 1.68, 1.70, 
    1.73, 1.75, 1.78, 1.80, 1.83 };
  double y[15] = {
    52.21, 53.12, 54.48, 55.84, 57.20, 58.57, 59.93, 61.29, 63.11, 64.47,
    66.28, 68.10, 69.92, 72.19, 74.46 };

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  LLSQ can compute the formula for a line of the form\n" );
  printf ( "    y = A * x + B\n" );
  printf ( "  which minimizes the RMS error to a set of N data values.\n" );

  llsq ( n, x, y, &a, &b );

  printf ( "\n" );
  printf ( "  Estimated relationship is y = %g * x + %g\n", a, b );
  printf ( "  Expected value is         y = 61.272 * x - 39.062\n" );
  printf ( "\n" );
  printf ( "     I      X       Y      B+A*X    |error|\n" );
  printf ( "\n" );
  error = 0.0;
  for ( i = 0; i < n; i++ )
  {
    printf ( "  %4d  %7g  %7g  %7g  %7g\n", i, x[i], y[i], b + a * x[i], b + a * x[i] - y[i] );
    error = error + pow ( b + a * x[i] - y[i], 2 );
  }
  error = sqrt ( error / ( double ) n );
  printf ( "\n" );
  printf ( "  RMS error =                      %g\n", error );

  return;
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 calls LLSQ0 to match 14 data values.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 January 2019

  Author:

    John Burkardt
*/
{
  double a;
  double error;
  int i;
  int n = 14;
  double x[14] = { 
    0.00, 0.10, 0.15, 0.20, 0.25,
    0.30, 0.35, 0.40, 0.45, 0.50,
    0.55, 0.60, 0.65, 0.70 };
  double y[14] = {
    0.0000,  0.0865,  0.1015,  0.1106,  0.1279,
    0.1892,  0.2695,  0.2888,  0.2425,  0.3465,
    0.3225,  0.3764,  0.4263,  0.4562 };

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  LLSQ0 can compute the formula for a line of the form\n" );
  printf ( "    y = A * x\n" );
  printf ( "  which minimizes the RMS error to a set of N data values.\n" );

  llsq0 ( n, x, y, &a );

  printf ( "\n" );
  printf ( "  Estimated relationship is y = %g * x\n", a );
  printf ( "\n" );
  printf ( "     I      X       Y        A*X    |error|\n" );
  printf ( "\n" );
  error = 0.0;
  for ( i = 0; i < n; i++ )
  {
    printf ( "  %4d  %7g  %7g  %7g  %7g\n", i, x[i], y[i], a * x[i], a * x[i] - y[i] );
    error = error + pow ( a * x[i] - y[i], 2 );
  }
  error = sqrt ( error / ( double ) n );
  printf ( "\n" );
  printf ( "  RMS error =                      %g\n", error );

  return;
}

