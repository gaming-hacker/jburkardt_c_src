# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "annulus_rule.h"

/******************************************************************************/

double annulus_area ( double center[2], double r1, double r2 )

/******************************************************************************/
/*
  Purpose:

    ANNULUS_AREA returns the area of an annulus in 2D.

  Discussion:

    A circular annulus with center (XC,YC), inner radius R1 and
    outer radius R2, is the set of points (X,Y) so that

      R1^2 <= (X-XC)^2 + (Y-YC)^2 <= R2^2

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 July 2018

  Author:

    John Burkardt

  Parameters:

    Input, double CENTER[2], coordinates of the center.
    This information is not actually needed to compute the area.

    Input, double R1, R2, the inner and outer radius of the disk.
    0.0 <= R1 <= R2.

    Output, double ANNULUS_AREA, the area of the annulus.
*/
{
  double area;
  const double r8_pi = 3.141592653589793;

  if ( r1 < 0.0 )
  {
    printf ( "\n" );
    printf ( "ANNULUS_AREA - Fatal error!\n" );
    printf ( "  Inner radius R1 < 0.0.\n" );
    exit ( 1 );
  }

  if ( r2 < r1 )
  {
    printf ( "\n" );
    printf ( "ANNULUS_AREA - Fatal error!\n" );
    printf ( "  Outer radius R2 < R1 = inner radius.\n" );
    exit ( 1 );
  }

  area = r8_pi * ( r2 + r1 ) * ( r2 - r1 );

  return area;
}

