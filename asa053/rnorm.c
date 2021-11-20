# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa053.h"

/******************************************************************************/

void rnorm ( int *seed, double *u1, double *u2 )

/******************************************************************************/
/*
  Purpose:

    RNORM returns two independent standard random normal deviates.

  Discussion:

    This routine sets U1 and U2 to two independent standardized 
    random normal deviates.   This is a version of the 
    method given in Knuth.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 April 2014

  Author:

    Original FORTRAN77 version by William Smith, Ronald Hocking.
    This C version by John Burkardt.

  Reference:

    Donald Knuth,
    The Art of Computer Programming,
    Volume 2, Seminumerical Algorithms,
    Third Edition,
    Addison Wesley, 1997,
    ISBN: 0201896842,
    LC: QA76.6.K64.

  Parameters:

    Input/output, int *SEED, a seed for the random 
    number generator.

    Output, double *U1, *U2, two standard random normal deviates.
*/
{
  double s;
  double x;
  double y;

  for ( ; ; )
  {
    x = r8_uniform_01 ( seed );
    y = r8_uniform_01 ( seed );
    x = 2.0 * x - 1.0;
    y = 2.0 * y - 1.0;
    s = x * x + y * y;

    if ( s <= 1.0 )
    {
      s = sqrt ( - 2.0 * log ( s ) / s );
      *u1 = x * s;
      *u2 = y * s;
      break;
    }
  }
  return;
}

