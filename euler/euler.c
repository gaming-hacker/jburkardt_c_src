# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "euler.h"

/******************************************************************************/

void euler ( void dydt ( double x, double y[], double yp[] ), double tspan[2], 
  double y0[], int n, int m, double t[], double y[] )

/******************************************************************************/
/*
  Purpose:

    euler approximates the solution to an ODE using Euler's method.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2020

  Author:

    John Burkardt

  Input:

    dydt: a function that evaluates the right hand side of the ODE.

    double tspan[2]: contains the initial and final times.

    double y0[m]: a column vector containing the initial condition.

    int n: the number of steps to take.

    int m: the number of variables.

  Output:

    double t[n+1], y[m*(n+1)]: the times and solution values.
*/
{
  double dt;
  double *dy;
  int i;
  int j;
  double tfirst;
  double tlast;

  dy = ( double * ) malloc ( m * sizeof ( double ) );

  tfirst = tspan[0];
  tlast = tspan[1];
  dt = ( tlast - tfirst ) / ( double ) ( n );
  j = 0;
  t[j] = tspan[0];
  for ( i = 0; i < m; i++ )
  {
    y[i+j*m] = y0[i];
  }

  for ( j = 0; j < n; j++ )
  {
    dydt ( t[j], y+j*m, dy );
    t[j+1] = t[j] + dt;
    for ( i = 0; i < m; i++ )
    {
      y[i+(j+1)*m] = y[i+j*m] + dt * dy[i];
    }
  }

  free ( dy );

  return;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    timestamp prints the current YMDHMS date as a time stamp.

  Example:

    17 June 2014 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2014

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
