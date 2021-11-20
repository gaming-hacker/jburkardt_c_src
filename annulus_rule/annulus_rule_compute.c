# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "annulus_rule.h"

/******************************************************************************/

void annulus_rule_compute ( double center[2], double r1, double r2, int nr, 
  int nt, double w[], double x[], double y[] )

/******************************************************************************/
/*
  Purpose:

    ANNULUS_RULE_COMPUTE computes a quadrature rule for an annulus.

  Discussion:

    The integration region is points (X,Y) such that

      R1^2 <= ( X - CENTER(1) )^2 + ( Y - CENTER(2) )^2 <= R2^2

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 July 2018

  Author:

    John Burkardt

  Reference:

    William Peirce,
    Numerical Integration Over the Planar Annulus,
    Journal of the Society for Industrial and Applied Mathematics,
    Volume 5, Issue 2, June 1957, pages 66-73.

  Parameters:

    Input, double CENTER(2), the coordinates of the center.

    Input, double R1, R2, the inner and outer radii of the annulus.
    0.0 <= R1 <= R2.

    Input, int NR, the number of points in the radial rule.

    Input, int NT, the number of angles to use.
    The value NT=4*NR is recommended.

    Output, double W[NR*NT], the weights for the rule.

    Output, double X[NR*NT], Y[NR*NT], the points for the rule.
*/
{
  double a;
  double area;
  double b;
  double c;
  double d;
  int i;
  int j;
  int k;
  const double r8_pi = 3.141592653589793;
  double *ra;
  double *rw;
  double t;
  double tw;
/*
  Request a Legendre rule for [-1,+1].
*/
  ra = ( double * ) malloc ( nr * sizeof ( double ) );
  rw = ( double * ) malloc ( nr * sizeof ( double ) );

  legendre_ek_compute ( nr, ra, rw );
/*
  Adjust the rule from [-1,+1] to [r1^2,r2^2].
*/
  a = -1.0;
  b = +1.0;
  c = r1 * r1;
  d = r2 * r2;
  rule_adjust ( a, b, c, d, nr, ra, rw );
/*
  Convert from R^2 to R.
*/
  for ( i = 0; i < nr; i++ )
  {
    ra[i] = sqrt ( ra[i] );
  }
  for ( i = 0; i < nr; i++ )
  {
    rw[i] = rw[i] / ( r2 + r1 ) / ( r2 - r1 );
  }
/*
  Set the angular weight.
*/
  tw = 1.0 / ( double ) ( nt );
/*
  Get area of annulus.
*/
  area = annulus_area ( center, r1, r2 );
/*
  Form the abscissa and weight vectors.
*/
  k = 0;
  for ( i = 0; i < nt; i++ )
  {
    t = 2.0 * r8_pi * ( double ) ( i ) / ( double ) ( nt );
    for ( j = 0; j < nr; j++ )
    {
      x[k] = center[0] + ra[j] * cos ( t );
      y[k] = center[1] + ra[j] * sin ( t );
      w[k] = area * tw * rw[j];
      k = k + 1;
    }
  }

  free ( ra );
  free ( rw );

  return;
}

