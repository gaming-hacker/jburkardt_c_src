# include <stdlib.h>
# include <stdio.h>

# include "annulus_monte_carlo.h"

int main ( );
void annulus_area_test ( );
void annulus_sample_test ( double center[2], double r1, double r2 );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ANNULUS_MONTE_CARLO_TEST.

  Discussion:

    ANNULUS_MONTE_CARLO_TEST tests ANNULUS_MONTE_CARLO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 July 2018

  Author:

    John Burkardt
*/
{
  double center[2];
  double r1;
  double r2;

  timestamp ( );
  printf ( "\n" );
  printf ( "ANNULUS_MONTE_CARLO_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test ANNULUS_MONTE_CARLO.\n" );

  annulus_area_test ( );

  center[0] = 0.0;
  center[1] = 0.0;
  r1 = 0.0;
  r2 = 1.0;
  annulus_sample_test ( center, r1, r2 );

  center[0] = 1.0;
  center[1] = 0.0;
  r1 = 0.5;
  r2 = 1.0;
  annulus_sample_test ( center, r1, r2 );

  center[0] = 1.0;
  center[1] = 0.0;
  r1 = 0.0;
  r2 = 1.0;
  annulus_sample_test ( center, r1, r2 );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ANNULUS_MONTE_CARLO_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void annulus_area_test ( )

/******************************************************************************/
/*
  Purpose:

    ANNULUS_AREA_TEST test ANNULUS_AREA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 July 2018

  Author:

    John Burkardt
*/
{
  double area;
  double center[2];
  double *data;
  int i;
  double r1;
  double r2;
  int seed;

  printf ( "\n" );
  printf ( "ANNULUS_AREA_TEST\n" );
  printf ( "  ANNULUS_AREA computes the area of an annulus with\n" );
  printf ( "  center = (CX,CY) and inner radius R1, outer radius R2.\n" );
  
  seed = 123456789;

  printf ( "\n" );
  printf ( "  (   CX        CY     )    R1        R2          Area\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    data = r8vec_uniform_01_new ( 4, &seed );
    center[0] = 10.0 * data[0] - 5.0;
    center[1] = 10.0 * data[1] - 5.0;
    r1 = data[2];
    r2 = r1 + data[3];
    printf ( "  (%9.6f,%9.6f)  %9.6f  %9.6f", 
      center[0], center[1], r1, r2 );
    area = annulus_area ( center, r1, r2 );
    printf ( "  %9.6f\n", area );
    free ( data );
  }

  return;
}
/******************************************************************************/

void annulus_sample_test ( double center[2], double r1, double r2 )

/******************************************************************************/
/*
  Purpose:

    ANNULUS_SAMPLE_TEST uses ANNULUS_SAMPLE to estimate integrals.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 July 2018

  Author:

    John Burkardt
*/
{
  int e[2];
  int e_test[2*7] = {
    0, 0, 
    2, 0, 
    0, 2, 
    4, 0, 
    2, 2, 
    0, 4, 
    6, 0 };
  int i;
  int j;
  int n;
  double result;
  int seed;
  double *value;
  double *x;

  printf ( "\n" );
  printf ( "ANNULUS_SAMPLE_TEST\n" );
  printf ( "  Use ANNULUS_SAMPLE to estimate integrals in the annulus\n" );
  printf ( "  with center (%g,%g), inner radius %g, outer radius %g.\n", 
    center[0], center[1], r1, r2 );

  seed = 123456789;

  printf ( "\n" );
  printf ( "         N        1              X^2             Y^2" );
  printf ( "             X^4             X^2Y^2           Y^4             X^6\n" );
  printf ( "\n" );

  n = 1;

  while ( n <= 65536 )
  {
    x = annulus_sample ( center, r1, r2, n, &seed );

    printf ( "  %8d", n );
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        e[i] = e_test[i+j*2];
      }
      value = monomial_value ( 2, n, e, x );

      result = annulus_area ( center, r1, r2 ) 
        * r8vec_sum ( n, value ) / ( double ) ( n );
      printf ( "  %14.6g", result );

      free ( value );
    }
    printf ( "\n" );

    free ( x );

    n = 2 * n;
  }

  if (
    center[0] == 0.0 &&
    center[1] == 0.0 &&
    r1 == 0.0 &&
    r2 == 1.0 )
  {
    printf ( "\n" );
    printf ( "     Exact" );
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
       e[i] = e_test[i+j*2];
     }
     result = disk01_monomial_integral ( e );
      printf ( "  %14.6g", result );
    }
    printf ( "\n" );
  }

  return;
}
