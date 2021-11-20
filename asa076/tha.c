# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa076.h"

/******************************************************************************/

double tha ( double h1, double h2, double a1, double a2 )

/******************************************************************************/
/*
  Purpose:

    THA computes Owen's T function.

  Discussion:

    This function computes T(H1/H2, A1/A2) for any real numbers H1, H2, 
    A1 and A2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 November 2010

  Author:

    Original FORTRAN77 version by JC Young, Christoph Minder.
    C version by John Burkardt.

  Reference:

    Richard Boys,
    Remark AS R80:
    A Remark on Algorithm AS76:
    An Integral Useful in Calculating Noncentral T and Bivariate
    Normal Probabilities,
    Applied Statistics,
    Volume 38, Number 3, 1989, pages 580-582.

    Youn-Min Chou,
    Remark AS R55:
    A Remark on Algorithm AS76:
    An Integral Useful in Calculating Noncentral T and Bivariate
    Normal Probabilities,
    Applied Statistics,
    Volume 34, Number 1, 1985, pages 100-101.

    PW Goedhart, MJW Jansen,
    Remark AS R89:
    A Remark on Algorithm AS76:
    An Integral Useful in Calculating Noncentral T and Bivariate
    Normal Probabilities,
    Applied Statistics,
    Volume 41, Number 2, 1992, pages 496-497.

    JC Young, Christoph Minder,
    Algorithm AS 76: 
    An Algorithm Useful in Calculating Noncentral T and 
    Bivariate Normal Distributions,
    Applied Statistics,
    Volume 23, Number 3, 1974, pages 455-457.

  Parameters:

    Input, double H1, H2, A1, A2, define the arguments
    of the T function.

    Output, double THA, the value of Owen's T function.
*/
{
  double a;
  double absa;
  double ah;
  double c1;
  double c2;
  double ex;
  double g;
  double gah;
  double gh;
  double h;
  double lam;
  double twopi = 6.2831853071795864769;
  double value;

  if ( h2 == 0.0 )
  {
    value = 0.0;
    return value;
  }

  h = h1 / h2;

  if ( a2 == 0.0 )
  {
    g = alnorm ( h, 0 );

    if ( h < 0.0 )
    {
      value = g / 2.0;
    }
    else
    {
      value = ( 1.0 - g ) / 2.0;
    }

    if ( a1 < 0.0 )
    {
      value = - value;
    }
    return value;
  }

  a = a1 / a2;

  if ( fabs ( h ) < 0.3 && 7.0 < fabs ( a ) )
  {
    lam = fabs ( a * h );
    ex = exp ( - lam * lam / 2.0 );
    g = alnorm ( lam, 0 );
    c1 = ( ex / lam + sqrt ( twopi ) * ( g - 0.5 ) ) / twopi;
    c2 = ( ( lam * lam + 2.0 ) * ex / lam / lam / lam
      + sqrt ( twopi ) * ( g - 0.5 ) ) / ( 6.0 * twopi );
    ah = fabs ( h );
    value = 0.25 - c1 * ah + c2 * ah * ah * ah;
    if ( a < 0.0 )
    {
      value = - fabs ( value );
    }
    else
    {
      value = fabs ( value );
    }
  }
  else
  {
    absa = fabs ( a );

    if ( absa <= 1.0 )
    {
      value = tfn ( h, a );
      return value;
    }

    ah = absa * h;
    gh = alnorm ( h, 0 );
    gah = alnorm ( ah, 0 );
    value = 0.5 * ( gh + gah ) - gh * gah - tfn ( ah, 1.0 / absa );

    if ( a < 0.0 )
    {
      value = - value;
    }
  }
  return value;
}

