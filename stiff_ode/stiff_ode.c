# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "stiff_ode.h"

/******************************************************************************/

double *r8vec_linspace_new ( int n, double a, double b )

/******************************************************************************/
/*
  Purpose:

    r8vec_linspace_new() creates a vector of linearly spaced values.

  Discussion:

    An R8VEC is a vector of R8's.

    4 points evenly spaced between 0 and 12 will yield 0, 4, 8, 12.
 
    In other words, the interval is divided into N-1 even subintervals,
    and the endpoints of intervals are used as the points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2011

  Author:

    John Burkardt

  Input:

    int N, the number of entries in the vector.

    double A, B, the first and last entries.

  Output:

    double R8VEC_LINSPACE_NEW[N], a vector of linearly spaced data.
*/
{
  int i;
  double *x;

  x = ( double * ) malloc ( n * sizeof ( double ) );

  if ( n == 1 )
  {
    x[0] = ( a + b ) / 2.0;
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      x[i] = ( ( double ) ( n - 1 - i ) * a 
             + ( double ) (         i ) * b ) 
             / ( double ) ( n - 1     );
    }
  }
  return x;
}
/******************************************************************************/

void stiff_deriv ( double t, double y[], double dydt[] )

/******************************************************************************/
/*
  stiff_deriv() evaluates the right hand side of the stiff ODE.

  Discussion:

    y' = lambda * ( cos(t) - y )
    y(t0) = y0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt

  Input:

    double T, Y[1]: the time and solution value.

  Output:

    double DYDT[1]: the derivative value.
*/
{
  double lambda;
  double t0;
  double y0;

  stiff_parameters ( &lambda, &t0, &y0 );

  dydt[0] = lambda * ( cos ( t ) - y[0] );

  return;
}
/******************************************************************************/

void stiff_euler ( int n, double t[], double y[] )

/******************************************************************************/
/*
  Purpose:

    stiff_euler() uses the Euler method on the stiff equation.

  Discussion:

    y' = lambda * ( cos(t) - y )
    y(t0) = y0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt

  Input:

    int N: the number of steps to take.

  Output:

    double T[N+1], Y[N+1]: the times and estimated solutions.
*/
{
  double dt;
  int i;
  double lambda;
  double t0;
  double tstop;
  double y0;

  stiff_parameters ( &lambda, &t0, &y0 );

  tstop = 1.0;
  dt = ( tstop - 0 ) / ( double ) ( n );

  t[0] = t0;
  y[0] = y0;

  for ( i = 0; i < n; i++ )
  {
    t[i+1] = t[i] + dt;
    y[i+1] = y[i] + dt * lambda * ( cos ( t[i] ) - y[i] );
  }

  return;
}
/******************************************************************************/

void stiff_euler_backward ( int n, double t[], double y[] )

/******************************************************************************/
/*
  Purpose:

    stiff_euler_backward() uses the backward Euler method on the stiff ODE.

  Discussion:

    y' = lambda * ( cos(t) - y )
    y(t0) = y0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt

  Input:

    int N: the number of steps to take.

  Output:

    double T[N+1], Y[N+1]: the times and estimated solutions.
*/
{
  double dt;
  int i;
  double lambda;
  double t0;
  double tstop;
  double y0;

  stiff_parameters ( &lambda, &t0, &y0 );

  tstop = 1.0;
  dt = ( tstop - 0 ) / ( double ) ( n );

  t[0] = t0;
  y[0] = y0;

  for ( i = 0; i < n; i++ )
  {
    t[i+1] = t[i] + dt;
    y[i+1] = ( y[i] + dt * lambda * cos ( t[i+1] ) ) 
      / ( 1.0 + lambda * dt );
  }

  return;
}
/******************************************************************************/

double *stiff_exact ( int n, double t[] )

/******************************************************************************/
/*
  Purpose:

    stiff_exact() evaluates the exact solution of the stiff ODE.

  Discussion:

    y' = lambda * ( cos(t) - y )
    y(t0) = y0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt

  Input:

    int N: the number of values.

    double T[N]: the evaluation times.

  Output:

    double STIFF_EXACT[N]: the exact solution values.
*/
{
  int i;
  double lambda;
  double t0;
  double *y;
  double y0;

  y = ( double * ) malloc ( n * sizeof ( double ) );

  stiff_parameters ( &lambda, &t0, &y0 );

  for ( i = 0; i < n; i++ )
  {
    y[i] = lambda * ( sin ( t[i] ) + lambda * cos ( t[i] )
      - lambda * exp ( - lambda * t[i] ) ) / ( lambda * lambda + 1.0 );
  }

  return y;
}
/******************************************************************************/

void stiff_midpoint ( int n, double t[], double y[] )

/******************************************************************************/
/*
  Purpose:

    stiff_midpoint() uses the midpoint method on the stiff ODE.

  Discussion:

    y' = lambda * ( cos(t) - y )
    y(t0) = y0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt

  Input:

    int N: the number of steps to take.

  Output:

    double T[N+1], Y[N+1]: the times and estimated solutions.
*/
{
  double dt;
  int i;
  double lambda;
  double t0;
  double tstop;
  double y0;

  stiff_parameters ( &lambda, &t0, &y0 );

  tstop = 1.0;
  dt = ( tstop - 0 ) / ( double ) ( n );

  t[0] = t0;
  y[0] = y0;

  for ( i = 0; i < n; i++ )
  {
    t[i+1] = t[i] + dt;
    y[i+1] = 
      ( 
        y[i] + lambda * 0.5 * dt * ( 
                                     cos ( t[i] ) - y[i] + cos ( t[i+1] ) 
                                   ) 
      ) 
      / ( 1.0 + lambda * 0.5 * dt );
  }

  return;
}
/******************************************************************************/

void stiff_parameters ( double *lambda, double *t0, double *y0 )

/******************************************************************************/
/*
  Purpose:

    stiff_parameters() returns parameters of the stiff ODE.

  Discussion:

    y' = lambda * ( cos(t) - y )
    y(t0) = y0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt

  Output:

    double *LAMBDA, a parameter.

    double *T0, double *Y0: the initial time and value.
*/
{
  *lambda = 50.0;
  *t0 = 0.0;
  *y0 = 0.0;

  return;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    timestamp() prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2003

  Author:

    John Burkardt
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
 
