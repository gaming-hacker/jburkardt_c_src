# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "stiff_ode.h"

int main ( );
void stiff_euler_test ( int n );
void stiff_euler_backward_test ( int n );
void stiff_midpoint_test ( int n );
void plot2 ( int n1, double t1[], double y1[], int n2, double t2[], 
  double y2[], char *header, char *title );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    stiff_ode_test() tests stiff_ode.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt
*/
{
  double lambda;
  int n;
  double t0;
  double y0;

  timestamp ( );
  printf ( "\n" );
  printf ( "stiff_ode_test\n" );
  printf ( "  C version\n" );
  printf ( "  Test stiff_ode using euler(), euler_backward(), midpoint().\n" );

  stiff_parameters ( &lambda, &t0, &y0 );

  printf ( "\n" );
  printf ( "  Parameter values:\n" );
  printf ( "    lambda = %g\n", lambda );
  printf ( "    t0     = %g\n", t0 );
  printf ( "    y0     = %g\n", y0 );

  n = 27;

  stiff_euler_test ( n );
  stiff_euler_backward_test ( n );
  stiff_midpoint_test ( n );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "stiff_ode_test\n" );
  printf ( "  Normal end of execution.\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void stiff_euler_test ( int n )

/******************************************************************************/
/*
  Purpose:

    stiff_euler_test() tests stiff_euler().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt

  Input:

    int N: the number of steps to take.
*/
{
  const int n2 = 101;
  double t0 = 0.0;
  double *t1;
  double *t2;
  double tstop = 1.0;
  double *y1;
  double *y2;

  printf ( "\n" );
  printf ( "stiff_euler_test\n" );
  printf ( "  Solve stiff ODE using the Euler method.\n" );

  t1 = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  y1 = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  stiff_euler ( n, t1, y1 );

  t2 = r8vec_linspace_new ( n2, t0, tstop );
  y2 = stiff_exact ( n2, t2 );

  plot2 ( n+1, t1, y1, n2, t2, y2, "stiff_euler", 
    "Stiff ODE: euler method" );

  free ( t1 );
  free ( t2 );
  free ( y1 );
  free ( y2 );

  return;
}
/******************************************************************************/

void stiff_euler_backward_test ( int n )

/******************************************************************************/
/*
  Purpose:

    stiff_euler_backward_test() tests stiff_euler_backward().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt

  Input:

    int N: the number of steps to take.
*/
{
  const int n2 = 101;
  double t0 = 0.0;
  double *t1;
  double *t2;
  double tstop = 1.0;
  double *y1;
  double *y2;

  printf ( "\n" );
  printf ( "stiff_backward_euler_test\n" );
  printf ( "  Solve stiff ODE using the backward Euler method.\n" );

  t1 = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  y1 = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  stiff_euler_backward ( n, t1, y1 );

  t2 = r8vec_linspace_new ( n2, t0, tstop );
  y2 = stiff_exact ( n2, t2 );

  plot2 ( n+1, t1, y1, n2, t2, y2, "stiff_euler_backward",
    "Stiff ODE: backward euler method" );

  free ( t1 );
  free ( t2 );
  free ( y1 );
  free ( y2 );

  return;
}
/******************************************************************************/

void stiff_midpoint_test ( int n )

/******************************************************************************/
/*
  Purpose:

    stiff_midpoint_test tests stiff_midpoint().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2021

  Author:

    John Burkardt

  Input:

    int N: the number of steps to take.
*/
{
  const int n2 = 101;
  double t0 = 0.0;
  double *t1;
  double *t2;
  double tstop = 1.0;
  double *y1;
  double *y2;

  printf ( "\n" );
  printf ( "stiff_midpoint_test\n" );
  printf ( "  Solve stiff ODE using the midpoint method.\n" );

  t1 = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  y1 = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  stiff_midpoint ( n, t1, y1 );

  t2 = r8vec_linspace_new ( n2, t0, tstop );
  y2 = stiff_exact ( n2, t2 );

  plot2 ( n+1, t1, y1, n2, t2, y2, "stiff_midpoint", 
    "Stiff ODE: midpoint method" );

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

    plot2 plots two curves together.

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
