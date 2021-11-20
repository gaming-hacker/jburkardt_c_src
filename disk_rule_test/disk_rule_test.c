# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "disk_rule.h"

int main ( );
void test01 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for DISK_RULE_TEST.

  Discussion:

    DISK_RULE_TEST tests the DISK_RULE library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 April 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "DISK_RULE_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the DISK_RULE library.\n" );

  test01 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "DISK_RULE_TEST:\n" );
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

    TEST01 tests DISK_RULE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 April 2016

  Author:

    John Burkardt
*/
{
  double area;
  int d;
  int ex;
  int ey;
  double exact[15] = {
       9.0, 
       9.0,        18.0, 
     117.0 / 4.0,  18.0,        225.0 / 4.0, 
     279.0 / 4.0, 117.0 / 2.0,  225.0 / 4.0, 387.0 / 2.0, 
    1773.0 / 8.0, 279.0 / 2.0, 1341.0 / 8.0, 387.0 / 2.0, 5769.0 / 8.0 };
  int i;
  int j;
  int k;
  int nr = 4;
  int nt = 8;
  double q;
  const double r8_pi = 3.141592653589793;
  double rc;
  double s;
  double *w;
  double *x;
  double xc;
  double *y;
  double yc;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  DISK_RULE can compute a rule Q(f) for the general disk\n" );
  printf ( "  with center (XC,YC) and radius RC,\n" );
  printf ( "  using NT equally spaced angles and NR radial distances.\n" );
  printf ( "\n" );
  printf ( "  NT = %d\n", nt );
  printf ( "  NR = %d\n", nr );
  printf ( "\n" );
  printf ( "  Estimate integrals I(f) where f = x^ex * y^ey.\n" );
/*
  Define the general disk.
*/
  xc = 1.0;
  yc = 2.0;
  rc = 3.0;
/*
  Put in the factor of PI in the exact values.
*/
  for ( k = 0; k < 15; k++ )
  {
    exact[k] = exact[k] * r8_pi;
  }
/*
  Compute the quadrature rule.
*/
  w = ( double * ) malloc ( nr * nt * sizeof ( double ) );
  x = ( double * ) malloc ( nr * nt * sizeof ( double ) );
  y = ( double * ) malloc ( nr * nt * sizeof ( double ) );

  disk_rule ( nr, nt, xc, yc, rc, w, x, y );
/*
  Apply it to integrands.
*/
  printf ( "\n" );
  printf ( "  EX    EY      I(f)            Q(f)\n" ); 
  printf ( "\n" );
/*
  Specify a monomial.
*/
  k = 0;

  for ( d = 0; d <= 4; d++ )
  {
    for ( ex = d; 0 <= ex; ex-- )
    {
      ey = d - ex;

      s = 0.0;
      for ( j = 0; j < nt; j++ )
      {
        for ( i = 0; i < nr; i++ )
        {
          s = s + w[i+j*nr] * pow ( x[i+j*nr], ex ) * pow ( y[i+j*nr], ey );
        }
      }
      
      area = r8_pi * rc * rc;

      q = area * s;

      printf ( "   %2d  %2d  %14.6g  %14.6g\n", ex, ey, exact[k], q );

      k = k + 1;
    }
  }

  free ( w );
  free ( x );
  free ( y );

  return;
}

