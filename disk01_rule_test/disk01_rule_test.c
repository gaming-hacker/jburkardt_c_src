# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "disk01_rule.h"

int main ( );
void test01 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for DISK01_RULE_TEST.

  Discussion:

    DISK01_RULE_TEST tests the DISK01_RULE library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "DISK01_RULE:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the DISK01_RULE library.\n" );

  test01 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "DISK01_RULE:\n" );
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

    TEST01 tests DISK01_RULE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 March 2014

  Author:

    John Burkardt
*/
{
  double area;
  int e[2];
  int e1;
  int e2;
  double exact;
  int i;
  int j;
  int nr = 4;
  int nt = 8;
  double q;
  const double r8_pi = 3.141592653589793;
  double *r;
  double s;
  double *t;
  double *w;
  double x;
  double y;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  DISK01_RULE can compute a rule Q(f) for the unit disk\n" );
  printf ( "  using NT equally spaced angles and NR radial distances.\n" );
  printf ( "\n" );
  printf ( "  NT = %d\n", nt );
  printf ( "  NR = %d\n", nr );
  printf ( "\n" );
  printf ( "  Estimate integrals I(f) where f = x^e[0] * y^e[1].\n" );
/*
  Compute the quadrature rule.
*/
  w = ( double * ) malloc ( nr * sizeof ( double ) );
  r = ( double * ) malloc ( nr * sizeof ( double ) );
  t = ( double * ) malloc ( nt * sizeof ( double ) );

  disk01_rule ( nr, nt, w, r, t );
/*
  Apply it to integrands.
*/
  printf ( "\n" );
  printf ( "  E(1)  E(2)    I(f)            Q(f)\n" ); 
  printf ( "\n" );
/*
  Specify a monomial.
*/
  for ( e1 = 0; e1 <= 6; e1 = e1 + 2 )
  {
    e[0] = e1;

    for ( e2 = e1; e2 <= 6; e2 = e2 + 2 )
    {
      e[1] = e2;

      s = 0.0;
      for ( j = 0; j < nt; j++ )
      {
        for ( i = 0; i < nr; i++ )
        {
          x = r[i] * cos ( t[j] );
          y = r[i] * sin ( t[j] );
          s = s + w[i] * pow ( x, e[0] ) * pow ( y, e[1] );
        }
      }

      area = r8_pi;

      q = area * s;

      exact = disk01_monomial_integral ( e );

      printf ( "   %2d  %2d  %14.6g  %14.6g\n", e[0], e[1], exact, q );
    }
  }

  free ( r );
  free ( t );
  free ( w );

  return;
}

