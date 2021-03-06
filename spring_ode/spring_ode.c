# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

int main ( );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for SPRING_ODE.

  Discussion:

    This is a simple example of how to plot when you don't have a plotter.
    This is a particular kind of "ASCII graphics", or "typewriter graphics"
    or "lineprinter graphics", and shows you how valuable an illustration 
    can be, even when it's as crude as this example.

    Hooke's law for a spring observes that the restoring force is
    proportional to the displacement: F = - k x

    Newton's law relates the force to acceleration: F = m a

    Putting these together, we have

      m * d^2 x/dt^2 = - k * x

    We can add a damping force with coefficient c:

      m * d^2 x/dt^2 = - k * x - c * dx/dt

    If we write this as a pair of first order equations for (x,v), we have

          dx/dt = v
      m * dv/dt = - k * x - c * v

    and now we can approximate these values for small time steps.

    Note that the plotting assumes that the value of X will always be
    between -1 and +1.  If the initial condition uses V = 0, and X starts
    between -1 and +1, then this will be OK.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 May 2012

  Author:

    John Burkardt

  Parameters:

    None
*/
{
  float c;
  float dt;
  int i;
  int j;
  float k;
  float m;
  int n;
  int p;
  float t_final;
  float v;
  float v_old;
  float x;
  float x_old;
  char z[21];

  timestamp ( );
  printf ( "\n" );
  printf ( "SPRING_ODE\n" );
  printf ( "  C version\n" );
  printf ( "  Approximate the solution of a spring equation.\n" );
  printf ( "  Display the solution with line printer graphics.\n" );
  printf ( "\n" );
/*
  Data
*/
  m = 1.0;
  k = 1.0;
  c = 0.3;
  t_final = 20.0;
  n = 100;
  dt = t_final / ( float ) ( n );
/*
  Initial conditions.
*/
  x = 1.0;
  v = 0.0;
/*
  Compute the approximate solution at equally spaced times.
*/
  for ( i = 0; i <= n; i++ )
  {
    x_old = x;
    v_old = v;
/*
    t = ( float ) ( i ) * t_final / ( float ) ( n );
*/
    x = x_old + dt * v_old;
    v = v_old + ( dt / m ) * ( - k * x_old - c * v_old );
/*
  Approximate the position of X in [-1,+1] to within 1/10.
*/
    p = ( int ) ( 10 * ( 1.0 + x ) );

    if ( p < 0 )
    {
      p = 0;
    }
    else if ( 20 < p )
    {
      p = 20;
    }
/*
  Fill in the next line of the plot, placing 'x' in the p position.
*/
    for ( j = 0; j <= 20; j++ )
    {
      if ( ( i % 10 ) == 0 )
      {
        z[j] = '-';
      }
      else
      {
        z[j] = ' ';
      }
    }
    z[0] = '|';
    z[5] = '.';
    z[10] = '+';
    z[15] = '.';
    z[20] = '|';

    z[p] = 'x';
    for ( j = 0; j <= 20; j++ )
    {
      printf ( "%c", z[j] );
    }
    printf ( "\n" );
  }
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SPRING_ODE:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2003

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

  fprintf ( stdout, "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
