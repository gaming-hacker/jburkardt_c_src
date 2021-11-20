# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa103.h"

/******************************************************************************/

double digamma ( double x, int *ifault )

/******************************************************************************/
/*
  Purpose:

    DIGAMMA calculates DIGAMMA ( X ) = d ( LOG ( GAMMA ( X ) ) ) / dX

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 March 2016

  Author:

    Original FORTRAN77 version by Jose Bernardo.
    C version by John Burkardt.

  Reference:

    Jose Bernardo,
    Algorithm AS 103:
    Psi ( Digamma ) Function,
    Applied Statistics,
    Volume 25, Number 3, 1976, pages 315-317.

  Parameters:

    Input, double X, the argument of the digamma function.
    0 < X.

    Output, int *IFAULT, error flag.
    0, no error.
    1, X <= 0.

    Output, double DIGAMMA, the value of the digamma function at X.
*/
{
  static double c = 8.5;
  static double euler_mascheroni = 0.57721566490153286060;
  double r;
  double value;
  double x2;
/*
  Check the input.
*/
  if ( x <= 0.0 )
  {
    value = 0.0;
    *ifault = 1;
    return value;
  }
/*
  Initialize.
*/
  *ifault = 0;
/*
  Use approximation for small argument.
*/
  if ( x <= 0.000001 )
  {
    value = - euler_mascheroni - 1.0 / x + 1.6449340668482264365 * x;
    return value;
  }
/*
  Reduce to DIGAMA(X + N).
*/
  value = 0.0;
  x2 = x;
  while ( x2 < c )
  {
    value = value - 1.0 / x2;
    x2 = x2 + 1.0;
  }
/*
  Use Stirling's (actually de Moivre's) expansion.
*/
  r = 1.0 / x2;
  value = value + log ( x2 ) - 0.5 * r;

  r = r * r;

  value = value 
    - r * ( 1.0 / 12.0 
    - r * ( 1.0 / 120.0 
    - r * ( 1.0 / 252.0 
    - r * ( 1.0 / 240.0
    - r * ( 1.0 / 132.0 ) ) ) ) );

  return value;
}
