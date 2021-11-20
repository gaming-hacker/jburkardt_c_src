# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "rk4.h"

int main ( );
void rk4_predator_test ( );
void predator_deriv ( double t, double u[], double f[] );
void predator_phase_plot ( int n, int m, double t[], double y[] );

/******************************************************************************/

int main ( ) 

/******************************************************************************/
/*
  Purpose:
 
    MAIN is the main program for rk4_test.

  Discussion:

    rk4_test tests rk4().

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 April 2020

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "rk4_test:\n" );
  printf ( "  C version\n" );
  printf ( "  Test rk4() .\n" );

  rk4_predator_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "rk4_test:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void rk4_predator_test ( ) 

/******************************************************************************/
/*
  Purpose:
 
    rk4_predator_test tests RK4 on the predator prey ODE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 April 2020

  Author:

    John Burkardt
*/
{
  int m;
  int n = 1000;
  double *t;
  double tspan[2];
  double *y;
  double *y0;

  m = 2;
  n = 1000;

  t = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  y = ( double * ) malloc ( ( n + 1 ) * m * sizeof ( double ) );
  y0 = ( double * ) malloc ( m * sizeof ( double ) );

  printf ( "\n" );
  printf ( "rk4_predator_test\n" );
  printf ( "  Use rk4() to solve the predator prey ODE.\n" );

  tspan[0] = 0.0;
  tspan[1] = 5.0;
  y0[0] = 5000.0;
  y0[1] = 100.0;
  
  rk4 ( predator_deriv, tspan, y0, n, m, t, y );

  predator_phase_plot ( n, m, t, y );
/*
  Free memory.
*/
  free ( t );
  free ( y );
  free ( y0 );

  return;
}
/******************************************************************************/

void predator_deriv ( double t, double y[], double f[] )

/******************************************************************************/
/*
  Purpose:
 
    predator_deriv returns the right hand side of the predator ODE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 April 2020

  Author:

    John Burkardt

  Input:

    double T, the current time.

    double Y[M], the current solution value.

  Output:

    double F[M], the value of the derivative, dU/dT.
*/
{
  double dfdt;
  double drdt;
  double fox;
  double rab;
  
  rab = y[0];
  fox = y[1];

  drdt =   2.0 * rab - 0.001 * rab * fox;
  dfdt = -10.0 * fox + 0.002 * rab * fox;

  f[0] = drdt;
  f[1] = dfdt;
  
  return;
}
/******************************************************************************/

void predator_phase_plot ( int n, int m, double t[], double y[] )

/******************************************************************************/
/*
  Purpose:

    predator_phase_plot makes a phase plot of the results.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    22 April 2020

  Author:

    John Burkardt

  Input:

    int n: the number of steps to take.

    int m: the number of variables.

    double t[n+1], y[(n+1)*m]: the times and solution values.
*/
{
  char command_filename[80];
  FILE *command;
  char data_filename[80];
  FILE *data;
  char header[] = "predator";
  int j;

  printf ( "\n" );
  printf ( "predator_phase_plot:\n" );
  printf ( "  Write command and data files that can be used\n" );
  printf ( "  by gnuplot for a predator-prey phase plot.\n" );
/*
  Create the data file.
*/
  strcpy ( data_filename, header );
  strcat ( data_filename, "_data.txt" );

  data = fopen ( data_filename, "wt" );

  for ( j = 0; j <= n; j++ )
  {
    fprintf ( data, "  %g  %g  %g\n", t[j], y[0+j*m], y[1+j*m] );
  }

  fclose ( data );

  printf ( "\n" );
  printf ( "  predator_phase_plot: data stored in \"%s\".\n", data_filename );
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
  fprintf ( command, "set xlabel '<-- Prey -->'\n" );
  fprintf ( command, "set ylabel '<-- Predator -->'\n" );
  fprintf ( command, "set title 'Predator-prey solution by rk4'\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "set style data lines\n" );
  fprintf ( command, "plot '%s' using 2:3 with lines\n", data_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "  predator_phase_plot: plot commands stored in \"%s\".\n", 
    command_filename );
 
  return;
}
