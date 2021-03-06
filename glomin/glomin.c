# include <float.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "glomin.h"

/******************************************************************************/

double glomin ( double a, double b, double c, double m, double e, double t, 
  double f ( double x ), double *x, int *calls )

/******************************************************************************/
/*
  Purpose:

    glomin() seeks a global minimum of a function F(X) in an interval [A,B].

  Discussion:

    This function assumes: 
    * F(X) is twice continuously differentiable over [A,B];
    * F''(X) <= M for all X in [A,B];
    * the user can supply the value of this upper bound M.

    Thanks to Hans Bieshaar for supplying several corrections to the code,
    03 June 2021

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 June 2021

  Author:

    Original FORTRAN77 version by Richard Brent.
    C version by John Burkardt.

  Reference:

    Richard Brent,
    Algorithms for Minimization Without Derivatives,
    Dover, 2002,
    ISBN: 0-486-41998-3,
    LC: QA402.5.B74.

  Input:

    double A, B, the endpoints of the interval.
    It must be the case that A < B.

    double C, an initial guess for the global
    minimizer.  If no good guess is known, C = A or B is acceptable.

    double M, the bound on the second derivative.

    double E, a positive tolerance, a bound for the
    absolute error in the evaluation of F(X) for any X in [A,B].

    double T, a positive error tolerance.

    double F ( double x ), a user-supplied
    function whose global minimum is being sought.

  Output:

    double *X: the estimated value of the abscissa
    for which F attains its global minimum value in [A,B].

    int *CALLS: the number of function calls.

    double GLOMIN: the value F(X).
*/
{
  double a0;
  double a2;
  double a3;
  double d0;
  double d1;
  double d2;
  bool force_first;
  double h;
  long k;
  double m2;
  double p;
  double q;
  double qs;
  double r;
  double s;
  double y;
  double y0;
  double y1;
  double y2;
  double y3;
  double yb;
  double z0;
  double z1;
  double z2;

  *calls = 0;

  a0 = b;
  *x = a0;
  a2 = a;
  y0 = f ( b );
  *calls = *calls + 1;
  yb = y0;
  y2 = f ( a );
  *calls = *calls + 1;
  y = y2;

  if ( y0 < y )
  {
    y = y0;
  }
  else
  {
    *x = a;
  }

  if ( m <= 0.0 || b <= a )
  {
    return y;
  }

  m2 = 0.5 * ( 1.0 + 16.0 * DBL_EPSILON ) * m;

  if ( c <= a || b <= c ) 
  {
    c = 0.5 * ( a + b );
  }

  y1 = f ( c );
  *calls = *calls + 1;
  k = 3;
  d0 = a2 - c;
  h = 9.0 / 11.0;

  if ( y1 < y )
  {
    *x = c;
    y = y1;
  }

  for ( ; ; )
  {
    d1 = a2 - a0;
    d2 = c - a0;
    z2 = b - a2;
    z0 = y2 - y1;
    z1 = y2 - y0;
    r = d1 * d1 * z0 - d0 * d0 * z1;
    p = r;
    qs = 2.0 * ( d0 * z1 - d1 * z0 );
    q = qs;
/*
  Loop control corrected by Hans Bieshaar, 28 May 2021.
  "long integer" constants suggested by Hans Bieshaar, 2 June 2021.
*/
    force_first = true;

    if ( 100000L <= k && y < y2 )
    {
      k = ( 1611L * k ) % 1048576L;
      q = 1.0;
      r = ( b - a ) * 0.00001 * ( double ) k;
      force_first = false;
    }

    while ( r < z2 || force_first )
    {
      force_first = false;

      if ( q * ( r * ( yb - y2 ) + z2 * q * ( ( y2 - y ) + t ) ) < 
        z2 * m2 * r * ( z2 * q - r ) )
      {
        a3 = a2 + r / q;
        y3 = f ( a3 );
        *calls = *calls + 1;

        if ( y3 < y )
        {
          *x = a3;
          y = y3;
        }
      }
      k = ( ( 1611 * k ) % 1048576 );
      q = 1.0;
      r = ( b - a ) * 0.00001 * ( double ) ( k );
    }

    r = m2 * d0 * d1 * d2;
    s = sqrt ( ( ( y2 - y ) + t ) / m2 );
    h = 0.5 * ( 1.0 + h );
    p = h * ( p + 2.0 * r * s );
/*
  Correction supplied by Hans Bieshaar, 27 May 2021.
*/
    q = r + 0.5 * qs;
    r = - 0.5 * ( d0 + ( z0 + 2.01 * e ) / ( d0 * m2 ) );

    if ( r < s || d0 < 0.0 ) 
    {
      r = a2 + s;
    }
    else
    {
      r = a2 + r;
    }

    if ( 0.0 < p * q ) 
    {
      a3 = a2 + p / q;
    }
    else
    {
      a3 = r;
    }

    for ( ; ; )
    {
      a3 = fmax ( a3, r );

      if ( b <= a3 ) 
      {
        a3 = b;
        y3 = yb;
      }
      else
      {
        y3 = f ( a3 );
        *calls = *calls + 1;
      }

      if ( y3 < y ) 
      {
        *x = a3;
        y = y3;
      }

      d0 = a3 - a2;

      if ( a3 <= r ) 
      {
        break;
      }

      p = 2.0 * ( y2 - y3 ) / ( m * d0 );

      if ( ( 1.0 + 9.0 * DBL_EPSILON ) * d0 <= fabs ( p ) )
      {
        break;
      }

      if ( 0.5 * m2 * ( d0 * d0 + p * p ) <= ( y2 - y ) + ( y3 - y ) + 2.0 * t )
      {
        break;
      }
      a3 = 0.5 * ( a2 + a3 );
      h = 0.9 * h;
    }

    if ( b <= a3 )
    {
      break;
    }

    a0 = c;
    c = a2;
    a2 = a3;
    y0 = y1;
    y1 = y2;
    y2 = y3;
  }

  return y;
}

