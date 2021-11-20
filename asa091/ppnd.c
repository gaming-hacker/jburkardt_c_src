# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa091.h"

/******************************************************************************/

double ppnd ( double p, int *ifault )

/******************************************************************************/
/*
  Purpose:

    PPND produces the normal deviate value corresponding to lower tail area = P.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 June 2013

  Author:

    Original FORTRAN77 version by J Beasley, S Springer.
    C version by John Burkardt.

  Reference:

    J Beasley, S Springer,
    Algorithm AS 111:
    The Percentage Points of the Normal Distribution,
    Applied Statistics,
    Volume 26, Number 1, 1977, pages 118-121.

  Parameters:

    Input, double P, the value of the cumulative probability
    densitity function.  0 < P < 1.

    Output, integer *IFAULT, error flag.
    0, no error.
    1, P <= 0 or P >= 1.  PPND is returned as 0.

    Output, double PPND, the normal deviate value with the property that
    the probability of a standard normal deviate being less than or
    equal to PPND is P.
*/
{
  double a0 = 2.50662823884;
  double a1 = -18.61500062529;
  double a2 = 41.39119773534;
  double a3 = -25.44106049637;
  double b1 = -8.47351093090;
  double b2 = 23.08336743743;
  double b3 = -21.06224101826;
  double b4 = 3.13082909833;
  double c0 = -2.78718931138;
  double c1 = -2.29796479134;
  double c2 = 4.85014127135;
  double c3 = 2.32121276858;
  double d1 = 3.54388924762;
  double d2 = 1.63706781897;
  double r;
  double split = 0.42;
  double value;

  *ifault = 0;
/*
  0.08 < P < 0.92
*/
  if ( fabs ( p - 0.5 ) <= split )
  {
    r = ( p - 0.5 ) * ( p - 0.5 );

    value = ( p - 0.5 ) * ( ( ( 
        a3   * r 
      + a2 ) * r 
      + a1 ) * r 
      + a0 ) / ( ( ( ( 
        b4   * r 
      + b3 ) * r 
      + b2 ) * r 
      + b1 ) * r 
      + 1.0 );
  }
/*
  P < 0.08 or P > 0.92,
  R = min ( P, 1-P )
*/
  else if ( 0.0 < p && p < 1.0 )
  {
    if ( 0.5 < p )
    {
      r = sqrt ( - log ( 1.0 - p ) );
    }
    else
    {
      r = sqrt ( - log ( p ) );
    }

    value = ( ( ( 
        c3   * r 
      + c2 ) * r 
      + c1 ) * r 
      + c0 ) / ( ( 
        d2   * r 
      + d1 ) * r 
      + 1.0 );

    if ( p < 0.5 )
    {
      value = - value;
    }
  }
/*
  P <= 0.0 or 1.0 <= P
*/
  else
  {
    *ifault = 1;
    value = 0.0;
  }

  return value;
}

