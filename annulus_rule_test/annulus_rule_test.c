# include <stdlib.h>
# include <stdio.h>

# include "annulus_rule.h"

int main ( );
void annulus_area_test ( );
void annulus_rule_compute_test ( );
void annulus_rule_monomial_test ( double center[2], double r1, double r2 );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ANNULUS_RULE_TEST.

  Discussion:

    ANNULUS_RULE_TEST tests ANNULUS_RULE.

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
  printf ( "ANNULUS_RULE_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test ANNULUS_RULE.\n" );

  annulus_area_test ( );
  annulus_rule_compute_test ( );

  center[0] = 0.0;
  center[1] = 0.0;
  r1 = 0.0;
  r2 = 1.0;
  annulus_rule_monomial_test ( center, r1, r2 );

  center[0] = 1.0;
  center[1] = 0.0;
  r1 = 0.5;
  r2 = 1.0;
  annulus_rule_monomial_test ( center, r1, r2 );

  center[0] = 1.0;
  center[1] = 0.0;
  r1 = 0.0;
  r2 = 1.0;
  annulus_rule_monomial_test ( center, r1, r2 );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ANNULUS_RULE_TEST\n" );
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

void annulus_rule_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    ANNULUS_RULE_COMPUTE_TEST tests ANNULUS_RULE_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 July 2018

  Author:

    John Burkardt
*/
{
  double center[2];
  int n;
  int nr;
  int nt;
  double r1;
  double r2;
  double *w;
  double *x;
  double *y;

  printf ( "\n" );
  printf ( "ANNULUS_RULE_COMPUTE_TEST:\n" );
  printf ( "  Test ANNULUS_RULE_COMPUTE.\n" );

  center[0] = 0.0;
  center[1] = 0.0;
  r1 = 0.5;
  r2 = 1.0;
  nr = 3;
  nt = 12;
  n = nt * nr;

  w = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );

  annulus_rule_compute ( center, r1, r2, nr, nt, w, x, y );

  r8vec3_print ( n, w, x, y, "  W, X, Y for annulus quadrature:" );

  free ( w );
  free ( x );
  free ( y );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ANNULUS_RULE_COMPUTE_TEST:\n" );
  printf ( "  Normal end of execution.\n" );

  return;
}
/******************************************************************************/

void annulus_rule_monomial_test ( double center[2], double r1, double r2 )

/******************************************************************************/
/*
  Purpose:

    ANNULUS_RULE_MONOMIAL_TEST estimates monomial integrals using quadrature.

  Discussion:

    If CENTER=(0,0) and R1 = 0 and R2 = 1, then we can compare exact values.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 July 2018

  Author:

    John Burkardt

  Parameters:

    Input, double CENTER[2], the coordinates of the center.

    Input, double R1, R2, the inner and outer radii of the annulus.
    0.0 <= R1 <= R2.
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
  int nr;
  int nt;
  double result;
  double *value;
  double *w;
  double *x;
  double *xy;
  double *y;

  printf ( "\n" );
  printf ( "ANNULUS_RULE_MONOMIAL_TEST\n" );
  printf ( "  ANNULUS_RULE_COMPUTE supplies a quadrature rule for the annulus\n" );
  printf ( "  with center (%g,%g), inner radius %g, outer radius %g.\n", 
    center[0], center[1], r1, r2 );

  printf ( "\n" );
  printf ( "    NR    NT           1               X^2            Y^2" );
  printf ( "             X^4             X^2Y^2          Y^4             X^6\n" );
  printf ( "\n" );

  nr = 4;

  while ( nr <= 64 )
  {
    nt = 4 * nr;
    n = nr * nt;

    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );
    xy = ( double * ) malloc ( 2 * n * sizeof ( double ) );
    y = ( double * ) malloc ( n * sizeof ( double ) );

    annulus_rule_compute ( center, r1, r2, nr, nt, w, x, y );

    for ( j = 0; j < n; j++ )
    {
      xy[0+2*j] = x[j];
      xy[1+2*j] = y[j];
    }

    printf ( "  %4d  %4d", nr, nt );
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        e[i] = e_test[i+j*2];
      }
      value = monomial_value ( 2, n, e, xy );

      result = r8vec_dot_product ( n, w, value );
      printf ( "  %14.6g", result );

      free ( value );
    }
    printf ( "\n" );

    free ( w );
    free ( x );
    free ( xy );
    free ( y );

    nr = 2 * nr;
  }

  if (
    center[0] == 0.0 &&
    center[1] == 0.0 &&
    r1 == 0.0 &&
    r2 == 1.0 )
  {
    printf ( "\n" );
    printf ( "     Exact  " );
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
