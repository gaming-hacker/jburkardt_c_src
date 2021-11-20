# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "annulus_monte_carlo.h"

/******************************************************************************/

double *annulus_sample ( double center[2], double r1, double r2, int n, 
  int *seed )

/******************************************************************************/
/*
  Purpose:

    ANNULUS_SAMPLE uniformly samples a general annulus in 2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 July 2018

  Author:

    John Burkardt

  Parameters:

    Input, double CENTER[2], coordinates of the center.

    Input, double R1, R2, the inner and outer radius.

    Input, int N, the number of points.

    Input/output, int *SEED, a seed for the random 
    number generator.

    Output, double X[2*N], the points.
*/
{
  int i;
  int j;
  double *p;
  double *r;
  const double r8_pi = 3.141592653589793;
  double *theta;

  if ( r1 < 0.0 )
  {
    printf ( "\n" );
    printf ( "ANNULUS_SAMPLE - Fatal error!\n" );
    printf ( "  Inner radius R1 < 0.0.\n" );
    exit ( 1 );
  }

  if ( r2 < r1 )
  {
    printf ( "\n" );
    printf ( "ANNULUS_SAMPLE - Fatal error!\n" );
    printf ( "  Outer radius R2 < R1 = inner radius.\n" );
    exit ( 1 );
  }

  theta = r8vec_uniform_01_new ( n, seed );

  for ( i = 0; i < n; i++ )
  {
    theta[i] = theta[i] * 2.0 * r8_pi;
  }

  r = r8vec_uniform_01_new ( n, seed );

  for ( i = 0; i < n; i++ )
  {
    r[i] = sqrt ( ( 1.0 - r[i] ) * r1 * r1 
         +                r[i]   * r2 * r2 );
  }

  p = ( double * ) malloc ( 2 * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    p[0+j*2] = center[0] + r[j] * cos ( theta[j] );
    p[1+j*2] = center[1] + r[j] * sin ( theta[j] );
  }

  free ( r );
  free ( theta );

  return p;
}

