# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "midpoint_explicit.h"

/******************************************************************************/

void midpoint_explicit ( double *dydt ( double x, double y[] ), 
  double tspan[2], double y0[], int n, int m, double t[], double y[] )

/******************************************************************************/
/*
  Purpose:

    midpoint_explicit uses an explicit midpoint method to solve an ODE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

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
  double *f;
  int i;
  int j;
  double tm;
  double *ym;

  ym = ( double * ) malloc ( m * sizeof ( double ) );

  dt = ( tspan[1] - tspan[0] ) / ( double ) ( n );

  t[0] = tspan[0];
  j = 0;
  for ( i = 0; i < m; i++ )
  {
    y[i+j*m] = y0[i];
  }

  for ( j = 0; j < n; j++ )
  {
    f = dydt ( t[j], y+j*m );
    tm = t[j] + 0.5 * dt;
    for ( i = 0; i < m; i++ )
    {
      ym[i] = y[i+j*m] + 0.5 * dt * f[i];
    }
    free ( f );

    f = dydt ( tm, ym );
    t[j+1] = t[j] + dt;
    for ( i = 0; i < m; i++ )
    {
      y[i+(j+1)*m] = y[i+j*m] + dt * f[i];
    }
    free ( f );
  }

  free ( ym );

  return;
}
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

