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

    MAIN is the main program for SNOWFALL_HISTOGRAM.

  Discussion:

    SNOWFALL_HISTOGRAM creates a histogram of yearly snowfall totals.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 July 2018

  Author:

    John Burkardt
*/
{
  char command_filename[] = "snowfall_commands.txt";
  FILE *command;
  char data_filename[] = "snowfall_data.txt";
  char graphic_filename[] = "snowfall_histogram.png";

  timestamp ( );
  printf ( "\n" );
  printf ( "SNOWFALL_HISTOGRAM:\n" );
  printf ( "  C version\n" );
  printf ( "  Create a histogram of Nile flood heights.\n" );
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
  fprintf ( command, "set output '%s'\n", graphic_filename );
  fprintf ( command, "set xlabel '<--- Total Yearly Snow in Inches --->'\n" );
  fprintf ( command, "set ylabel '<--- Frequency --->'\n" );
  fprintf ( command, "set title 'Yearly Snowfall in Michigan'\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "set style fill solid\n" );
  fprintf ( command, "unset key\n" );
  fprintf ( command, "binwidth = 25.0\n" );
  fprintf ( command, "binstart = 50.0\n" );
  fprintf ( command, "set boxwidth 0.9*binwidth\n" );
  fprintf ( command, "plot '%s' i 0 using (binwidth*(floor(($10-binstart)/binwidth)+0.5)+binstart):(1.0) smooth freq with boxes lc rgb 'cyan'\n", data_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "\n" );
  printf ( "SNOWFALL_HISTOGRAM:\n" );
  printf ( "  Plot commands stored in \"%s\".\n", command_filename );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SNOWFALL_HISTOGRAM:\n" );
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
