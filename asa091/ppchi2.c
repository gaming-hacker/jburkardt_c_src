# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "asa091.h"

/******************************************************************************/

double ppchi2 ( double p, double v, double g, int *ifault )

/******************************************************************************/
/*
  Purpose:

    PPCHI2 evaluates the percentage points of the Chi-squared PDF.

  Discussion

    Incorporates the suggested changes in AS R85 (vol.40(1),
    pages 233-5, 1991) which should eliminate the need for the limited
    range for P, though these limits have not been removed
    from the routine.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 June 2013

  Author:

    Original FORTRAN77 version by Donald Best, DE Roberts.
    C version by John Burkardt.

  Reference:

    Donald Best, DE Roberts,
    Algorithm AS 91:
    The Percentage Points of the Chi-Squared Distribution,
    Applied Statistics,
    Volume 24, Number 3, 1975, pages 385-390.

  Parameters:

    Input, double P,  value of the chi-squared cumulative
    probability density function.
    0.000002 <= P <= 0.999998.

    Input, double V, the parameter of the chi-squared probability
    density function.
    0 < V.

    Input, double G, the value of log ( Gamma ( V / 2 ) ).

    Output, int *IFAULT, is nonzero if an error occurred.
    0, no error.
    1, P is outside the legal range.
    2, V is not positive.
    3, an error occurred in GAMMAD.
    4, the result is probably as accurate as the machine will allow.

    Output, double PPCHI2, the value of the chi-squared random
    deviate with the property that the probability that a chi-squared random
    deviate with parameter V is less than or equal to PPCHI2 is P.
*/
{
  double a;
  double aa = 0.6931471806;
  double b;
  double c;
  double c1 = 0.01;
  double c2 = 0.222222;
  double c3 = 0.32;
  double c4 = 0.4;
  double c5 = 1.24;
  double c6 = 2.2;
  double c7 = 4.67;
  double c8 = 6.66;
  double c9 = 6.73;
  double c10 = 13.32;
  double c11 = 60.0;
  double c12 = 70.0;
  double c13 = 84.0;
  double c14 = 105.0;
  double c15 = 120.0;
  double c16 = 127.0;
  double c17 = 140.0;
  double c18 = 175.0;
  double c19 = 210.0;
  double c20 = 252.0;
  double c21 = 264.0;
  double c22 = 294.0;
  double c23 = 346.0;
  double c24 = 420.0;
  double c25 = 462.0;
  double c26 = 606.0;
  double c27 = 672.0;
  double c28 = 707.0;
  double c29 = 735.0;
  double c30 = 889.0;
  double c31 = 932.0;
  double c32 = 966.0;
  double c33 = 1141.0;
  double c34 = 1182.0;
  double c35 = 1278.0;
  double c36 = 1740.0;
  double c37 = 2520.0;
  double c38 = 5040.0;
  double ch;
  double e = 0.5E-06;
  int i;
  int if1;
  int maxit = 20;
  double pmax = 0.999998;
  double pmin = 0.000002;
  double p1;
  double p2;
  double q;
  double s1;
  double s2;
  double s3;
  double s4;
  double s5;
  double s6;
  double t;
  double value;
  double x;
  double xx;
/*
  Test arguments and initialize.
*/
  value = - 1.0;

  if ( p < pmin || pmax < p )
  {
    *ifault = 1;
    return value;
  }

  if ( v <= 0.0 )
  {
    *ifault = 2;
    return value;
  }

  *ifault = 0;
  xx = 0.5 * v;
  c = xx - 1.0;
/*
  Starting approximation for small chi-squared
*/
  if ( v < - c5 * log ( p ) )
  {
    ch = pow ( p * xx * exp ( g + xx * aa ), 1.0 / xx );

    if ( ch < e )
    {
      value = ch;
      return value;
    }
  }
/*
  Starting approximation for V less than or equal to 0.32
*/
  else if ( v <= c3 )
  {
    ch = c4;
    a = log ( 1.0 - p );

    for ( ; ; )
    {
      q = ch;
      p1 = 1.0 + ch * ( c7 + ch );
      p2 = ch * (c9 + ch * ( c8 + ch ) );

      t = - 0.5 + (c7 + 2.0 * ch ) / p1 - ( c9 + ch * ( c10 + 
        3.0 * ch ) ) / p2;

      ch = ch - ( 1.0 - exp ( a + g + 0.5 * ch + c * aa ) * p2 / p1) / t;

      if ( fabs ( q / ch - 1.0 ) <= c1 )
      {
        break;
      }
    }
  }
  else
  {
/*
  Call to algorithm AS 111 - note that P has been tested above.
  AS 241 could be used as an alternative.
*/
    x = ppnd ( p, ifault );
/*
  Starting approximation using Wilson and Hilferty estimate
*/
    p1 = c2 / v;
    ch = v * pow ( x * sqrt ( p1 ) + 1.0 - p1, 3 );
/*
  Starting approximation for P tending to 1.
*/
    if ( c6 * v + 6.0 < ch )
    {
      ch = - 2.0 * ( log ( 1.0 - p ) - c * log ( 0.5 * ch ) + g );
    }
  }
/*
  Call to algorithm AS 239 and calculation of seven term
  Taylor series
*/
  for ( i = 1; i <= maxit; i++ )
  {
    q = ch;
    p1 = 0.5 * ch;
    p2 = p - gammad ( p1, xx, &if1 );

    if ( if1 != 0 )
    {
      *ifault = 3;
      return value;
    }

    t = p2 * exp ( xx * aa + g + p1 - c * log ( ch ) );
    b = t / ch;
    a = 0.5 * t - b * c;
    s1 = ( c19 + a * ( c17 + a * ( c14 + a * ( c13 + a * ( c12 + 
      c11 * a ))))) / c24;
    s2 = ( c24 + a * ( c29 + a * ( c32 + a * ( c33 + c35 * a )))) / c37;
    s3 = ( c19 + a * ( c25 + a * ( c28 + c31 * a ))) / c37;
    s4 = ( c20 + a * ( c27 + c34 * a) + c * ( c22 + a * ( c30 + c36 * a ))) / c38;
    s5 = ( c13 + c21 * a + c * ( c18 + c26 * a )) / c37;
    s6 = ( c15 + c * ( c23 + c16 * c )) / c38;
    ch = ch + t * ( 1.0 + 0.5 * t * s1 - b * c * ( s1 - b * 
      ( s2 - b * ( s3 - b * ( s4 - b * ( s5 - b * s6 ))))));

    if ( e < fabs ( q / ch - 1.0 ) )
    {
       value = ch;
       return value;
    }
  }

 *ifault = 4;
 value = ch;

  return value;
}

