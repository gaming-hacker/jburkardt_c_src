# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa005.h"

/******************************************************************************/

double prncst ( double st, int idf, double d, int *ifault )

/******************************************************************************/
/*
  Purpose:

    PRNCST computes the lower tail of noncentral T distribution.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2010

  Author:

    Original FORTRAN77 version by BE Cooper.
    C version by John Burkardt.

  Reference:

    BE Cooper,
    Algorithm AS 5:
    The Integral of the Non-Central T-Distribution,
    Applied Statistics,
    Volume 17, Number 2, 1968, page 193.

  Parameters:

    Input, double ST, the argument.

    Input, int IDF, the number of degrees of freedom.

    Input, double D, the noncentrality parameter.

    Output, int *IFAULT, error flag.
    0, no error occurred.
    nonzero, an error occurred.

    Output, double PRNCST, the value of the lower tail of
    the noncentral T distribution.

  Local Parameters:

    Local, double G1, 1.0 / sqrt(2.0 * pi)

    Local, double G2, 1.0 / (2.0 * pi)

    Local, double G3, sqrt(2.0 * pi)
*/
{
  double a;
  double ak;
  double b;
  double da;
  double drb;
  double emin = 12.5;
  double f;
  double fk;
  double fkm1;
  double fmkm1;
  double fmkm2;
  double g1 = 0.3989422804;
  double g2 = 0.1591549431;
  double g3 = 2.5066282746;
  int ioe;
  int k;
  double rb;
  double sum;
  double value;

  f = ( double ) ( idf );
/*
  For very large IDF, use the normal approximation.
*/
  if ( 100 < idf )
  {
    *ifault = 1;

    a = sqrt ( 0.5 * f ) * exp ( lgamma ( 0.5 * ( f - 1.0 ) ) 
      - lgamma ( 0.5 * f ) ) * d;

    value = alnorm ( ( st - a ) / sqrt ( f * ( 1.0 + d * d ) 
      / ( f - 2.0 ) - a * a ), 0 );
    return value;
  }

  *ifault = 0;
  ioe = ( idf % 2 );
  a = st / sqrt ( f );
  b = f / ( f + st * st );
  rb = sqrt ( b );
  da = d * a;
  drb = d * rb;

  if ( idf == 1 )
  {
    value = alnorm ( drb, 1 ) + 2.0 * tfn ( drb, a );
    return value;
  }

  sum = 0.0;

  if ( fabs ( drb ) < emin )
  {
    fmkm2 = a * rb * exp ( - 0.5 * drb * drb ) 
    * alnorm ( a * drb, 0 ) * g1;
  }
  else
  {
    fmkm2 = 0.0;
  }

  fmkm1 = b * da * fmkm2;

  if ( fabs ( d ) < emin )
  {
    fmkm1 = fmkm1 + b * a * g2 * exp ( - 0.5 * d * d );
  }

  if ( ioe == 0 )
  {
    sum = fmkm2;
  }
  else
  {
    sum = fmkm1;
  }

  ak = 1.0;
  fk = 2.0;

  for ( k = 2; k <= idf - 2; k = k + 2 )
  {
    fkm1 = fk - 1.0;
    fmkm2 = b * ( da * ak * fmkm1 + fmkm2 ) * fkm1 / fk;
    ak = 1.0 / ( ak * fkm1 );
    fmkm1 = b * ( da * ak * fmkm2 + fmkm1 ) * fk / ( fk + 1.0 );

    if ( ioe == 0 )
    {
      sum = sum + fmkm2;
    }
    else
    {
      sum = sum + fmkm1;
    }
    ak = 1.0 / ( ak * fk );
    fk = fk + 2.0;
  }

  if ( ioe == 0 )
  {
    value = alnorm ( d, 1 ) + sum * g3;
  }
  else
  {
    value = alnorm ( drb, 1 ) + 2.0 * ( sum + tfn ( drb, a ) );
  }

  return value;
}

