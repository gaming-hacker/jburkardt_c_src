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

    MAIN is the main program for CORVETTE_SCATTER.

  Discussion:

    CORVETTE_SCATTER creates a scatter plot of the Corvette sale price data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 July 2018

  Author:

    John Burkardt
*/
{
  char command_filename[] = "corvette_commands.txt";
  FILE *command;
  char data_filename[] = "corvette_data.txt";
  char plot_filename[] = "corvette_scatter.png";

  timestamp ( );
  printf ( "\n" );
  printf ( "CORVETTE_SCATTER:\n" );
  printf ( "  C version\n" );
  printf ( "  Create a scatter plot of the model year and price for\n" );
  printf ( "  used Corvette sales.\n" );
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
  fprintf ( command, "set output '%s'\n", plot_filename );
  fprintf ( command, "set xlabel '<--- Model Year --->'\n" );
  fprintf ( command, "set ylabel '<--- Sales Price --->'\n" );
  fprintf ( command, "set title 'Corvette Sale Price vs Model Year'\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "unset key\n" );
  fprintf ( command, "set style data lines\n" );
  fprintf ( command, "plot '%s' using 1:2 with points pt 7 ps 2\n", data_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "\n" );
  printf ( "CORVETTE_SCATTER:\n" );
  printf ( "  Plot commands stored in \"%s\".\n", command_filename );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "CORVETTE_SCATTER:\n" );
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
