# include <complex.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "toms243.h"

/******************************************************************************/

double complex toms243 ( double complex z )

/******************************************************************************/
/*
  Purpose:

    TOMS243 computes the natural logarithm for complex values.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 January 2018

  Author:

    John Burkardt

  Reference:

    David Collens,
    Algorithm 243: Logarithm of a Complex Number,
    Communications of the Association for Computing Machinery,
    Volume 7, Number 11, November 1964, page 660.

  Parameters:

    Input, double complex Z, the argument of the function.

    Output, double complex TOMS243, the value of the function.
*/
{
  double a;
  double b;
  double c;
  double d;
  double e;
  double f;
  static double r8_pi = 3.141592653589793;
  double complex value;

  a = creal ( z );
  b = cimag ( z );
/*
  Ugly hack to get NaN values.
*/
  if ( a == 0.0 && b == 0.0 )
  {
    c = 1.0 / a;
    d = 1.0 / b;
  }
  else
  {
    e = a / 2.0;
    f = b / 2.0;
    if ( abs ( e ) < 0.5 && fabs ( f ) < 0.5 )
    {
      c = fabs ( 2.0 * a ) + fabs ( 2.0 * b );
      d = 8.0 * ( a / c ) * a + 8.0 * ( b / c ) * b;
      c = 0.5 * ( log ( c ) + log ( d ) ) - log ( sqrt ( 8.0 ) );
    }
    else
    {
      c = fabs ( e / 2.0 ) + fabs ( f / 2.0 );
      d = 0.5 * ( e / c ) * e + 0.5 * ( f / c ) * f;
      c = 0.5 * ( log ( c ) + log ( d ) ) + log ( sqrt ( 8.0 ) );
    }

    if ( ( a != 0.0 ) && fabs ( f ) <= fabs ( e ) )
    {
      if ( copysign ( 1.0, a ) != -1.0 )
      {
        d = atan ( b / a );
      }
      else if ( copysign ( 1.0, b ) != -1.0 )
      {
        d = atan ( b / a ) + r8_pi;
      }
      else
      {
        d = atan ( b / a ) - r8_pi;
      }
    }
    else
    {
      d = - atan ( a / b ) + r8_pi / 2.0 * copysign ( 1.0, b );
    }

  }

  value = c + d * I;

  return value;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    17 June 2014 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2014

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}

