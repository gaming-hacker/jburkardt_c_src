# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa091.h"

/******************************************************************************/

double gammad ( double x, double p, int *ifault )

/******************************************************************************/
/*
  Purpose:

    GAMMAD computes the Incomplete Gamma Integral

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 November 2010

  Author:

    Original FORTRAN77 version by B Shea.
    C version by John Burkardt.

  Reference:

    B Shea,
    Algorithm AS 239:
    Chi-squared and Incomplete Gamma Integral,
    Applied Statistics,
    Volume 37, Number 3, 1988, pages 466-473.

  Parameters:

    Input, double X, P, the parameters of the incomplete 
    gamma ratio.  0 <= X, and 0 < P.

    Output, int IFAULT, error flag.
    0, no error.
    1, X < 0 or P <= 0.

    Output, double GAMMAD, the value of the incomplete 
    Gamma integral.
*/
{
  double a;
  double an;
  double arg;
  double b;
  double c;
  double elimit = - 88.0;
  double oflo = 1.0E+37;
  double plimit = 1000.0;
  double pn1;
  double pn2;
  double pn3;
  double pn4;
  double pn5;
  double pn6;
  double rn;
  double tol = 1.0E-14;
  int upper;
  double value;
  double xbig = 1.0E+08;

  value = 0.0;
/*
  Check the input.
*/
  if ( x < 0.0 )
  {
    *ifault = 1;
    return value;
  }

  if ( p <= 0.0 )
  {
    *ifault = 1;
    return value;
  }

  *ifault = 0;

  if ( x == 0.0 )
  {
    value = 0.0;
    return value;
  }
/*
  If P is large, use a normal approximation.
*/
  if ( plimit < p )
  {
    pn1 = 3.0 * sqrt ( p ) * ( pow ( x / p, 1.0 / 3.0 ) 
      + 1.0 / ( 9.0 * p ) - 1.0 );

    upper = 0;
    value = alnorm ( pn1, upper );
    return value;
  }
/*
  If X is large set value = 1.
*/
  if ( xbig < x )
  {
    value = 1.0;
    return value;
  }
/*
  Use Pearson's series expansion.
  (Note that P is not large enough to force overflow in ALOGAM).
  No need to test IFAULT on exit since P > 0.
*/
  if ( x <= 1.0 || x < p )
  {
    arg = p * log ( x ) - x - lgamma ( p + 1.0 );
    c = 1.0;
    value = 1.0;
    a = p;

    for ( ; ; )
    {
      a = a + 1.0;
      c = c * x / a;
      value = value + c;

      if ( c <= tol )
      {
        break;
      }
    }

    arg = arg + log ( value );

    if ( elimit <= arg )
    {
      value = exp ( arg );
    }
    else
    {
      value = 0.0;
    }
  }
/*
  Use a continued fraction expansion.
*/
  else 
  {
    arg = p * log ( x ) - x - lgamma ( p );
    a = 1.0 - p;
    b = a + x + 1.0;
    c = 0.0;
    pn1 = 1.0;
    pn2 = x;
    pn3 = x + 1.0;
    pn4 = x * b;
    value = pn3 / pn4;

    for ( ; ; )
    {
      a = a + 1.0;
      b = b + 2.0;
      c = c + 1.0;
      an = a * c;
      pn5 = b * pn3 - an * pn1;
      pn6 = b * pn4 - an * pn2;

      if ( pn6 != 0.0 )
      {
        rn = pn5 / pn6;

        if ( fabs ( value - rn ) <= r8_min ( tol, tol * rn ) )
        {
          break;
        }
        value = rn;
      }

      pn1 = pn3;
      pn2 = pn4;
      pn3 = pn5;
      pn4 = pn6;
/*
  Re-scale terms in continued fraction if terms are large.
*/
      if ( oflo <= fabs ( pn5 ) )
      {
        pn1 = pn1 / oflo;
        pn2 = pn2 / oflo;
        pn3 = pn3 / oflo;
        pn4 = pn4 / oflo;
      }
    }

    arg = arg + log ( value );

    if ( elimit <= arg )
    {
      value = 1.0 - exp ( arg );
    }
    else
    {
      value = 1.0;
    }
  }

  return value;
}

