# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "zero_rc.h"

/******************************************************************************/

void zero_rc ( double a, double b, double t, double *arg, int *status, 
  double value )

/******************************************************************************/
/*
  Purpose:

    zero_rc() seeks a root of a function F(X) using reverse communication.

  Discussion:

    The interval [A,B] must be a change of sign interval for F.
    That is, F(A) and F(B) must be of opposite signs.  Then
    assuming that F is continuous implies the existence of at least
    one value C between A and B for which F(C) = 0.

    The location of the zero is determined to within an accuracy
    of 4 * EPSILON * abs ( C ) + 2 * T.

    The routine is a revised version of the Brent zero finder 
    algorithm, using reverse communication.

    Thanks to Thomas Secretin for pointing out a transcription error in the
    setting of the value of P, 11 February 2013.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 July 2021

  Author:

    John Burkardt

  Reference:

    Richard Brent,
    Algorithms for Minimization Without Derivatives,
    Dover, 2002,
    ISBN: 0-486-41998-3,
    LC: QA402.5.B74.

  Input:

    double A, B, the endpoints of the change of sign interval.

    double T, a positive error tolerance.

    int *STATUS, used to communicate between the user and the routine.
    The user only sets STATUS to zero on the first call, to indicate 
    that this is a startup call.

    double VALUE, the function value at ARG, as requested
    by the routine on the previous call.  No value needs to be input
    on the first call.

  Output:

    double *ARG, the currently considered point.  For the next call,
    the user is requested to evaluate the function at ARG, and return
    the value in VALUE.  On return with STATUS zero, ARG is the routine's
    estimate for the function's zero.

    int *STATUS, used to communicate between the user and the routine.  
    The routine returns STATUS positive to request that the function be 
    evaluated at ARG, or returns STATUS as 0, to indicate that the 
    iteration is complete and that ARG is the estimated zero.
*/
{
  static double c;
  static double d;
  static double e;
  static double fa;
  static double fb;
  static double fc;
  double m;
  double p;
  double q;
  double r;
  double s;
  static double sa;
  static double sb;
  double tol;
/*
  Input STATUS = 0.
  Initialize, request F(A).
*/
  if ( *status == 0 )
  {
    sa = a;
    sb = b;
    e = sb - sa;
    d = e;

    *status = 1;
    *arg = a;
    return;
  }
/*
  Input STATUS = 1.
  Receive F(A), request F(B).
*/
  else if ( *status == 1 )
  {
    fa = value;
    *status = 2;
    *arg = sb;
    return;
  }
/*
  Input STATUS = 2
  Receive F(B).
*/
  else if ( *status == 2 )
  {
    fb = value;

    if ( 0.0 < fa * fb )
    {
      *status = -1;
      return;
    }
    c = sa;
    fc = fa;
  }
  else
  {
    fb = value;

    if ( ( 0.0 < fb && 0.0 < fc ) || ( fb <= 0.0 && fc <= 0.0 ) )
    {
      c = sa;
      fc = fa;
      e = sb - sa;
      d = e;
    }
  }
/*
  Compute the next point at which a function value is requested.
*/
  if ( fabs ( fc ) < fabs ( fb ) )
  {
    sa = sb;
    sb = c;
    c = sa;
    fa = fb;
    fb = fc;
    fc = fa;
  }

  tol = 2.0 * DBL_EPSILON * fabs ( sb ) + t;
  m = 0.5 * ( c - sb );

  if ( fabs ( m ) <= tol || fb == 0.0 )
  {
    *status = 0;
    *arg = sb;
    return;
  }

  if ( fabs ( e ) < tol || fabs ( fa ) <= fabs ( fb ) )
  {
    e = m;
    d = e;
  }
  else
  {
    s = fb / fa;

    if ( sa == c )
    {
      p = 2.0 * m * s;
      q = 1.0 - s;
    }
    else
    {
      q = fa / fc;
      r = fb / fc;
      p = s * ( 2.0 * m * q * ( q - r ) - ( sb - sa ) * ( r - 1.0 ) );
      q = ( q - 1.0 ) * ( r - 1.0 ) * ( s - 1.0 );
    }

    if ( 0.0 < p )
    {
      q = - q;
    }
    else
    {
      p = - p;
    }
    s = e;
    e = d;

    if ( 2.0 * p < 3.0 * m * q - fabs ( tol * q ) && 
         p < fabs ( 0.5 * s * q ) )
    {
      d = p / q;
    }
    else
    {
      e = m;
      d = e;
    }
  }

  sa = sb;
  fa = fb;

  if ( tol < fabs ( d ) )
  {
    sb = sb + d;
  }
  else if ( 0.0 < m )
  {
    sb = sb + tol;
  }
  else
  {
    sb = sb - tol;
  }

  *arg = sb;
  *status = *status + 1;

  return;
}
