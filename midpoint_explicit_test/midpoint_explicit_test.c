# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "midpoint_explicit.h"

int main ( );
double *predator_prey_deriv ( double t, double rf[] );
void predator_prey_midpoint_explicit_test ( double tspan[2], double p0[2], int n );
double *stiff_deriv ( double t, double y[] );
double *stiff_exact ( int n, double t[] );
void stiff_midpoint_explicit_test ( double tspan[2], double y0[1], int n );
void plot2 ( int n1, double t1[], double y1[], int n2, double t2[], 
  double y2[], char *header, char *title );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    midpoint_explicit_test() tests midpoint_explicit().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt
*/
{
  int n;
  double tspan[2];
  double y0[2];

  timestamp ( );
  printf ( "\n" );
  printf ( "midpoint_explicit_test:\n" );
  printf ( "  C version\n" );
  printf ( "  Test midpoint_explicit() on several ODE's.\n" );

  tspan[0] = 0.0;
  tspan[1] = 10.0;
  y0[0] = 5000.0;
  y0[1] = 100.0;
  n = 100;
  predator_prey_midpoint_explicit_test ( tspan, y0, n );

  tspan[0] = 0.0;
  tspan[1] = 1.0;
  y0[0] = 0.0;
  n = 27;
  stiff_midpoint_explicit_test ( tspan, y0, n );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "midpoint_explicit_test:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return ( 0 );
}
/******************************************************************************/

double *predator_prey_deriv ( double t, double rf[] )

/******************************************************************************/
/*
  Purpose:

    predator_prey_deriv evaluates the right hand side of the system.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 April 2020

  Author:

    John Burkardt

  Reference:

    George Lindfield, John Penny,
    Numerical Methods Using MATLAB,
    Second Edition,
    Prentice Hall, 1999,
    ISBN: 0-13-012641-1,
    LC: QA297.P45.

  Input:

    double T: the current time.

    double RF[2]: the current solution variables, rabbits and foxes.

  Output:

    double PREDATOR_PREY_DERIV[2]: the right hand side of the 2 ODE's.
*/
{
  double *drfdt;

  drfdt = ( double * ) malloc ( 2 * sizeof ( double ) );

  drfdt[0] =    2.0 * rf[0] - 0.001 * rf[0] * rf[1];
  drfdt[1] = - 10.0 * rf[1] + 0.002 * rf[0] * rf[1];

  return drfdt;
}
/******************************************************************************/

void predator_prey_midpoint_explicit_test ( double tspan[2], double p0[2], int n )

/******************************************************************************/
/*
  Purpose:

    predator_prey_midpoint_explicit_test() tests predator_prey_midpoint_explicit().

  Discussion:

    The physical system under consideration is a pair of animal populations.

    The PREY reproduce rapidly for each animal alive at the beginning of the
    year, two more will be born by the end of the year.  The prey do not have
    a natural death rate instead, they only die by being eaten by the predator.
    Every prey animal has 1 chance in 1000 of being eaten in a given year by
    a given predator.

    The PREDATORS only die of starvation, but this happens very quickly.
    If unfed, a predator will tend to starve in about 1/10 of a year.
    On the other hand, the predator reproduction rate is dependent on
    eating prey, and the chances of this depend on the number of available prey.

    The resulting differential equations can be written:

      PREY(0) = 5000         
      PRED(0) =  100

      d PREY / dT =    2 * PREY(T) - 0.001 * PREY(T) * PRED(T)
      d PRED / dT = - 10 * PRED(T) + 0.002 * PREY(T) * PRED(T)

    Here, the initial values (5000,100) are a somewhat arbitrary starting point.

    The pair of ordinary differential equations that result have an interesting
    behavior.  For certain choices of the interaction coefficients (such as
    those given here), the populations of predator and prey will tend to 
    a periodic oscillation.  The two populations will be out of phase the number
    of prey will rise, then after a delay, the predators will rise as the prey
    begins to fall, causing the predator population to crash again.

    There is a conserved quantity, which here would be:
      E(r,f) = 0.002 r + 0.001 f - 10 ln(r) - 2 ln(f)
 
  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt

  Reference:

    George Lindfield, John Penny,
    Numerical Methods Using MATLAB,
    Second Edition,
    Prentice Hall, 1999,
    ISBN: 0-13-012641-1,
    LC: QA297.P45.

  Input:

    double TSPAN = [ T0, TMAX ], the initial and final times.
    A reasonable value might be [ 0, 5 ].

    double P0 = [ PREY, PRED ], the initial number of prey and predators.
    A reasonable value might be [ 5000, 100 ].

    int N: the number of time steps.
*/
{
  char command_filename[80];
  FILE *command;
  char data_filename[80];
  FILE *data;
  char header[] = "predator_prey_midpoint_explicit";
  int i;
  const int m = 2;
  double *pout;
  double *t;

  printf ( "\n" );
  printf ( "predator_prey_midpoint_explicit_test\n" );
  printf ( "  A pair of ordinary differential equations for a population\n" );
  printf ( "  of predators and prey are solved using midpoint_fixed().\n" );

  t = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  pout = ( double * ) malloc ( ( n + 1 ) * m * sizeof ( double ) );

  midpoint_explicit ( predator_prey_deriv, tspan, p0, n, m, t, pout );
/*
  Create the data file.
*/
  strcpy ( data_filename, header );
  strcat ( data_filename, "_data.txt" );

  data = fopen ( data_filename, "wt" );

  for ( i = 0; i <= n; i++ )
  {
    fprintf ( data, "  %g  %g  %g\n", t[i], pout[0+i*m], pout[1+i*m] );
  }

  fclose ( data );

  printf ( "\n" );
  printf ( "  predator_prey_midpoint_explicit_test: data stored in \"%s\".\n", data_filename );
/*
  Create the command file.
*/
  strcpy ( command_filename, header );
  strcat ( command_filename, "_commands.txt" );

  command = fopen ( command_filename, "wt" );

  fprintf ( command, "# %s\n", command_filename );
  fprintf ( command, "#\n" );
  fprintf ( command, "# Usage:\n" );
  fprintf ( command, "#  gnuplot < %s\n", command_filename );
  fprintf ( command, "#\n" );
  fprintf ( command, "set term png\n" );
  fprintf ( command, "set output '%s.png'\n", header );
  fprintf ( command, "set xlabel '<-- Predator -->'\n" );
  fprintf ( command, "set ylabel '<-- Prey -->'\n" );
  fprintf ( command, "set title 'predator prey: midpoint explicit method'\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "set style data lines\n" );
  fprintf ( command, "plot '%s' using 2:3 with lines lw 3\n", data_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "  predator_prey_midpoint_explicit_test: plot commands stored in \"%s\".\n", 
    command_filename );

  free ( pout );
  free ( t );

  return;
}
/******************************************************************************/

double *stiff_deriv ( double t, double y[] )

/******************************************************************************/
/*
  stiff_deriv() evaluates the right hand side of the stiff ODE.

  Discussion:

    y' = 50 * ( cos(t) - y )
    y(0) = 0

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
  double *dydt;

  dydt = ( double * ) malloc ( 1 * sizeof ( double ) );

  dydt[0] = 50.0 * ( cos ( t ) - y[0] );

  return dydt;
}
/******************************************************************************/

double *stiff_exact ( int n, double t[] )

/******************************************************************************/
/*
  Purpose:

    stiff_exact() evaluates the exact solution of the stiff ODE.

  Discussion:

    y' = 50 * ( cos(t) - y )
    y(0) = 0

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
  double *y;

  y = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    y[i] = 50.0 * ( sin ( t[i] ) + 50.0 * cos ( t[i] )
      - 50.0 * exp ( - 50.0 * t[i] ) ) / 2501.0;
  }

  return y;
}
/******************************************************************************/

void stiff_midpoint_explicit_test ( double tspan[2], double y0[1], int n )

/******************************************************************************/
/*
  Purpose:

    stiff_midpoint_explicit_test() tests stiff_midpoint_explicit().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt

  Input:

    double TSPAN(2): the first and last times.

    double Y0: the initial condition.

    int N: the number of steps to take.
*/
{
  int m = 1;
  const int n2 = 101;
  double *t1;
  double *t2;
  double *y1;
  double *y2;

  printf ( "\n" );
  printf ( "stiff_midpoint_explicit_test\n" );
  printf ( "  Solve stiff ODE using midpoint_explicit().\n" );

  t1 = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  y1 = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  midpoint_explicit ( stiff_deriv, tspan, y0, n, m, t1, y1 );

  t2 = r8vec_linspace_new ( n2, tspan[0], tspan[1] );
  y2 = stiff_exact ( n2, t2 );

  plot2 ( n+1, t1, y1, n2, t2, y2, "stiff_midpoint_explicit", 
    "Stiff ODE: midpoint explicit method" );

  free ( t1 );
  free ( t2 );
  free ( y1 );
  free ( y2 );

  return;
}
/******************************************************************************/

void plot2 ( int n1, double t1[], double y1[], int n2, double t2[], 
  double y2[], char *header, char *title )

/******************************************************************************/
/*
  Purpose:

    plot2() plots two curves together.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 April 2020

  Author:

    John Burkardt

  Input:

    int N1: the size of the first data set.

    double T1(N1), Y1(N1), the first dataset.

    int N2: the size of the second data set.

    double T2(N2), Y2(N2), the secod dataset.

    char *HEADER: an identifier for the data.

    char *TITLE: a title to appear in the plot.
*/
{
  char command_filename[80];
  FILE *command;
  char data1_filename[80];
  char data2_filename[80];
  FILE *data;
  int i;
/*
  Create the data file.
*/
  strcpy ( data1_filename, header );
  strcat ( data1_filename, "_data1.txt" );
  data = fopen ( data1_filename, "wt" );
  for ( i = 0; i < n1; i++ )
  {
    fprintf ( data, "  %g  %g\n", t1[i], y1[i] );
  }
  fclose ( data );

  strcpy ( data2_filename, header );
  strcat ( data2_filename, "_data2.txt" );
  data = fopen ( data2_filename, "wt" );
  for ( i = 0; i < n2; i++ )
  {
    fprintf ( data, "  %g  %g\n", t2[i], y2[i] );
  }
  fclose ( data );

  printf ( "\n" );
  printf ( "  stiff_ode_test: data stored in '%s' and '%s'.\n", 
    data1_filename, data2_filename );
/*
  Create the command file.
*/
  strcpy ( command_filename, header );
  strcat ( command_filename, "_commands.txt" );

  command = fopen ( command_filename, "wt" );

  fprintf ( command, "# %s\n", command_filename );
  fprintf ( command, "#\n" );
  fprintf ( command, "# Usage:\n" );
  fprintf ( command, "#  gnuplot < %s\n", command_filename );
  fprintf ( command, "#\n" );
  fprintf ( command, "set term png\n" );
  fprintf ( command, "set output '%s.png'\n", header );
  fprintf ( command, "set xlabel '<-- T -->'\n" );
  fprintf ( command, "set ylabel '<-- Y(T) -->'\n" );
  fprintf ( command, "set title '%s'\n", title );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "set style data lines\n" );
  fprintf ( command, "plot '%s' using 1:2 with lines lw 3 lt rgb 'red',\\\n", data1_filename );
  fprintf ( command, "     '%s' using 1:2 with lines lw 3 lt rgb 'blue'\n", data2_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "  stiff_ode_test: plot commands stored in \"%s\".\n", 
    command_filename );

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

  fprintf ( stdout, "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}

