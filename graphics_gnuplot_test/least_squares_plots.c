# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

int main ( );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for LEAST_SQUARES_PLOTS.

  Discussion:

    LEAST_SQUARES_PLOTS plots the variation in blood levels of a medicinal drug

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 July 2018

  Author:

    John Burkardt
*/
{
  char command_filename[] = "least_squares_commands.txt";
  FILE *command;
  char data1_filename[] = "least_squares1_data.txt";
  char data2_filename[] = "least_squares2_data.txt";
  char data3_filename[] = "least_squares3_data.txt";
  char header[] = "least_squares";

  timestamp ( );
  printf ( "\n" );
  printf ( "LEAST_SQUARES_PLOTS:\n" );
  printf ( "  C version\n" );
  printf ( "  On a single picture, plot:\n" );
  printf ( "  * 15 data points (X,Y).\n" );
  printf ( "  * the least squares line Y=A*X+B.\n" );
  printf ( "  * the exact formula Y=1/2*X^2 + 1.\n" );
  printf ( "  Create corresponding GNUPLOT input files.\n" );
/*
  Plot three curves on one image.
*/
  command = fopen ( command_filename, "wt" );

  fprintf ( command, "# %s\n", command_filename );
  fprintf ( command, "#\n" );
  fprintf ( command, "# Usage:\n" );
  fprintf ( command, "#  gnuplot < %s\n", command_filename );
  fprintf ( command, "#\n" );
  fprintf ( command, "set term png\n" );
  fprintf ( command, "set output '%s_plots.png'\n", header );
  fprintf ( command, "set xlabel '<--- X --->'\n" );
  fprintf ( command, "set ylabel '<--- Y --->'\n" );
  fprintf ( command, "set title 'Formula (green), Data (blue), least squares fit (red)'\n" );
  fprintf ( command, "set key on\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "plot '%s' using 1:2 with points lw 3 lt rgb 'blue' title 'Data', \\\n", data1_filename );
  fprintf ( command, "     '%s' using 1:2 with lines lw 3 lt rgb 'red' title 'Least Squares Line', \\\n", data2_filename );
  fprintf ( command, "     '%s' using 1:2 with lines lw 3 lt rgb 'green' title 'Exact Formula'\n", data3_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "\n" );
  printf ( "LEAST_SQUARES_PLOTS:\n" );
  printf ( "  Plot commands stored in \"%s\".\n", command_filename );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "LEAST_SQUARES_PLOTS:\n" );
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
