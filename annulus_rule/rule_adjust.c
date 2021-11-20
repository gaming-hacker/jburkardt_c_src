# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "annulus_rule.h"

/******************************************************************************/

void rule_adjust ( double a, double b, double c, double d, int order,
  double x[], double w[] )

/******************************************************************************/
/*
  Purpose:

    RULE_ADJUST maps a quadrature rule from [A,B] to [C,D].

  Discussion:

    Most quadrature rules are defined on a special interval, like
    [-1,1] or [0,1].  To integrate over an interval, the abscissas
    and weights must be adjusted.  This can be done on the fly,
    or by calling this routine.

    If the weight function W(X) is not 1, then the W vector will
    require further adjustment by the user.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 March 2008

  Author:

    John Burkardt

  Parameters:

    Input, double A, B, the endpoints of the definition interval.

    Input, double C, D, the endpoints of the integration interval.

    Input, int ORDER, the number of abscissas and weights.

    Input/output, double X[ORDER], W[ORDER], the abscissas
    and weights.
*/
{
  int i;

  for ( i = 0; i < order; i++ )
  {
    x[i] = ( ( b - x[i]     ) * c
           + (     x[i] - a ) * d )
           / ( b              - a );
  }

  for ( i = 0; i < order; i++ )
  {
    w[i] = ( ( d - c ) / ( b - a ) ) * w[i];
  }

  return;
}

