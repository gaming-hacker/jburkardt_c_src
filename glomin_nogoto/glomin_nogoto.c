# include <float.h>
# include <math.h>

/******************************************************************************/

double glomin_nogoto ( double a, double b, double c, double m,
  double e, double t, double f ( double x ), double *x, int *calls )

/******************************************************************************/
/*
  Purpose:

    glomin_nogoto() seeks a global minimum of a function in an interval.

  Discussion:

    This function assumes: 
    * F(X) is twice continuously differentiable over [A,B];
    * F''(X) <= M for all X in [A,B];
    * the user can supply the value of this upper bound M.

    Thanks to Hans Bieshaar for supplying several corrections to the code,
    03 June 2021.

    Thanks to Hans Bieshaar for rewriting the code so that it has no
    goto statements, 13 July 2021.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 July 2021

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

    double F ( double x ), a user-supplied function whose global 
    minimum is being sought.

  Output:

    double *X: the estimated value of the abscissa
    for which F attains its global minimum value in [A,B].

    int *CALLS: the number of function calls.

    double GLOMIN_NOGOTO: the value F(X).
*/
{

// Initialization

  *calls = 0;
	double a0 = b;
	*x = a0;
	double a2 = a;

	double y0 = f ( b );
  *calls = *calls + 1;

	double yb = y0;

	double y2 = f ( a );
  *calls = *calls + 1;

	double y = y2;

	if ( y0 < y )
		y = y0;
	else
		*x = a;

	if ( m <= 0.0 || b <= a )
		return y;

// Nontrivial case (m>0, a<b)

	double m2 = 0.5 * ( 1.0 + 16.0 * DBL_EPSILON ) * m;

	if ( c <= a || b <= c )
		c = 0.5 * ( a + b );

	double y1 = f ( c );
  *calls = *calls + 1;

	long k = 3;
	double d0 = a2 - c;
	double h = 9.0 / 11.0;

	if ( y1 < y )
  {
		*x = c;
		y = y1;
	}
// Main loop

	for (;;)
  {
// next:  (unused label, used in Algol 60 version)

		const double d1 = a2 - a0;
		const double d2 = c - a0;
		const double z2 = b - a2;
		const double z0 = y2 - y1;
		const double z1 = y2 - y0;
		double r = d1 * d1 * z0 - d0 * d0 * z1;
		double p = r;
		const double qs = 2.0 * ( d0 * z1 - d1 * z0 );
		double q = qs;

// Try to find a lower value of f using quadratic interpolation

		int random_search = ( 100000L <= k && y < y2 );

	  for ( ; ; )
    {
//
// With probability about 0.1 do a random search for a lower
// value of f(). Any reasonable random number generator can be
// used in place of the one here (it need not be very good).
//
			if ( random_search )
      {
        k = ( 1611 * k ) % 1048576L;
				q = 1.0;
				r = ( b - a ) * 0.00001 * k;
		    if ( z2 <= r ) break;
			}
      else
      {
				random_search = 1;
      }

			if ( q * ( r * ( yb - y2 ) + z2 * q * ( ( y2 - y ) + t ) ) <
				z2 * m2 * r * ( z2 * q - r ) )
			{
				const double xt = a2 + r / q;
				const double yt = f ( xt );
        *calls = *calls + 1;

				if ( yt < y )
        {
					*x = xt;
					y = yt;
				}
			}

		}

// Prepare to step as far as possible

		r = m2 * d0 * d1 * d2;
		const double s = sqrt ( ( ( y2 - y ) + t ) / m2 );
		h = 0.5 * ( 1.0 + h );
		p = h * ( p + 2.0 * r * s );
		q = r + 0.5 * qs;
		r = - 0.5 * ( d0 + ( z0 + 2.01 * e ) / ( d0 * m2 ) );
		r = a2 + ( r < s || d0 < 0.0 ? s : r );

// It is safe to step to r, but we may try to step further

		double a3 = ( p * q > 0.0 ? a2 + p / q : r );
		double y3;

    for ( ; ; )
    {
// inner:
      if ( a3 < r )
				a3 = r;

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
				break;

// Inspect the parabolic lower bound on f in (a2, a3)

			p = 2.0 * ( y2 - y3 ) / ( m * d0 );

			if ( ( 1.0 + 9.0 * DBL_EPSILON) * d0 <= fabs ( p ) )
				break;

			if ( 0.5 * m2 * ( d0 * d0 + p * p ) <= ( y2 - y ) + ( y3 - y ) + 2.0 * t )
				break;

// Halve the step and try again

			a3 = 0.5 * ( a2 + a3 );
			h = h * 0.9;
		} 
// end inner loop

    if ( b <= a3 )
			return y;

// Prepare for the next step

		a0 = c;
		c = a2;
		a2 = a3;
		y0 = y1;
		y1 = y2;
		y2 = y3;
	}
// end main loop

}
