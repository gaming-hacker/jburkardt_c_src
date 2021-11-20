# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "euler.h"

int main ( );
void euler_humps_test ( int n );
void humps_deriv ( double x, double y[], double yp[] );
void humps_exact ( int n, double x[], double y[] );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    main is the main program for euler_test.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2020

  Author:

    John Burkardt
*/
{
  int n;

  timestamp ( );
  printf ( "\n" );
  printf ( "euler_test\n" );
  printf ( "  C version\n" );
  printf ( "  Test euler().\n" );

  n = 50;
  euler_humps_test ( n );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "euler_test:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void euler_humps_test ( int n )

/******************************************************************************/
/*
  Purpose:

    euler_humps_test calls the Euler code.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2020

  Author:

    John Burkardt

  Input:

    int N: the number of steps to take.
*/
{
  char command_filename[80];
  FILE *command;
  char data_filename[80];
  FILE *data;
  char header[] = "euler_humps";
  int i;
  int m = 1;
  double *t;
  double tspan[2];
  double *y;
  double y0[1];
  double *y2;

  t = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  y = ( double * ) malloc ( ( n + 1 ) * m * sizeof ( double ) );
  y2 = ( double * ) malloc ( ( n + 1 ) * m * sizeof ( double ) );

  printf ( "\n" );
  printf ( "euler_humps_test:\n" );

  tspan[0] = 0.0;
  tspan[1] = 2.0;
  humps_exact ( 1, tspan, y0 );

  euler ( humps_deriv, tspan, y0, n, m, t, y );

  humps_exact ( n+1, t, y2 );
/*
  Create the data file.
*/
  strcpy ( data_filename, header );
  strcat ( data_filename, "_data.txt" );

  data = fopen ( data_filename, "wt" );

  for ( i = 0; i <= n; i++ )
  {
    fprintf ( data, "  %g  %g  %g\n", t[i], y[i], y2[i] );
  }

  fclose ( data );

  printf ( "\n" );
  printf ( "  euler_humps_test: data stored in \"%s\".\n", data_filename );
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
  fprintf ( command, "set output '%s_test.png'\n", header );
  fprintf ( command, "set xlabel '<-- T -->'\n" );
  fprintf ( command, "set ylabel '<-- Y(T) -->'\n" );
  fprintf ( command, "set title 'euler: Humps ODE'\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "set style data lines\n" );
  fprintf ( command, "plot '%s' using 1:2 with lines lw 3 lt rgb 'red',\\\n", data_filename );
  fprintf ( command, "     '%s' using 1:3 with lines lw 3 lt rgb 'blue'\n", data_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "  euler_humps_test: plot commands stored in \"%s\".\n", 
    command_filename );

  free ( t );
  free ( y );
  free ( y2 );

  return;
}
/******************************************************************************/

void humps_deriv ( double x, double y[], double yp[] )

/******************************************************************************/
/*
  Purpose:

    humps_deriv evaluates the right hand side of the humps ODE.

  Purpose:

    humps_deriv evaluates the derivative of the humps function.

  Discussion:

    y = 1.0 / ( ( x - 0.3 )^2 + 0.01 )
      + 1.0 / ( ( x - 0.9 )^2 + 0.04 )
      - 6.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 August 2019

  Author:

    John Burkardt

  Input:

    double x, y[1]: the arguments.

  Output:

    double yp[1]: the value of the derivative at x.
*/
{
  yp[0] = - 2.0 * ( x - 0.3 ) / pow ( pow ( x - 0.3, 2 ) + 0.01, 2 )
          - 2.0 * ( x - 0.9 ) / pow ( pow ( x - 0.9, 2 ) + 0.04, 2 );

  return;
}
/******************************************************************************/

void humps_exact ( int n, double x[], double y[] )

/******************************************************************************/
/*
  Purpose:

    humps_exact evaluates the humps function.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 August 2019

  Author:

    John Burkardt

  Input:

    int n: the number of evaluation points.

    double x[n]: the evaluation point.

  Output:

    double y[n]: the function values.
*/
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    y[i] = 1.0 / ( pow ( x[i] - 0.3, 2 ) + 0.01 )
         + 1.0 / ( pow ( x[i] - 0.9, 2 ) + 0.04 )
         - 6.0;
  }

  return;
}
