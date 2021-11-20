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

    MAIN is the main program for BROWNIAN_2D_PLOT.

  Discussion:

    BROWNIAN_2D_PLOT creates a line plot of two-dimensional Brownian motion.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 July 2018

  Author:

    John Burkardt
*/
{
  char command_filename[] = "brownian_2d_commands.txt";
  FILE *command;
  char data_filename[] = "brownian_2d_data.txt";
  char header[] = "brownian_2d";

  timestamp ( );
  printf ( "\n" );
  printf ( "BROWNIAN_2D_PLOT:\n" );
  printf ( "  C version\n" );
  printf ( "  Create a line plot two-dimensional Brownian motion.\n" );
  printf ( "  Create corresponding GNUPLOT input files.\n" );
/*
  Create the command file.
*/
  command = fopen ( command_filename, "wt" );

  fprintf ( command, "# %s\n", command_filename );
  fprintf ( command, "#\n" );
  fprintf ( command, "# Usage:\n" );
  fprintf ( command, "#  gnuplot < %s\n", command_filename );
  fprintf ( command, "#\n" );
  fprintf ( command, "set term png\n" );
  fprintf ( command, "set output '%s_plot.png'\n", header );
  fprintf ( command, "set xlabel '<--- X --->'\n" );
  fprintf ( command, "set ylabel '<--- Y --->'\n" );
  fprintf ( command, "set title '1000 steps of Brownian Motion'\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "set style data lines\n" );
  fprintf ( command, "plot '%s' using 1:2 with lines lw 3\n", data_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "\n" );
  printf ( "BROWNIAN_2D_PLOT:\n" );
  printf ( "  Plot commands stored in \"%s\".\n", command_filename );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "BROWNIAN_2D_PLOT:\n" );
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
