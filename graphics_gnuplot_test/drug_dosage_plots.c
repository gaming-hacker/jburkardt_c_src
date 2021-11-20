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

    MAIN is the main program for DRUG_DOSAGE_PLOTS.

  Discussion:

    DRUG_DOSAGE_PLOTS plots the variation in blood levels of a medicinal drug

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 July 2018

  Author:

    John Burkardt
*/
{
  char command_filename[] = "drug_dosage_commands.txt";
  FILE *command;
  char data_filename[] = "drug_dosage_data.txt";
  char header[] = "drug_dosage";

  timestamp ( );
  printf ( "\n" );
  printf ( "DRUG_DOSAGE_PLOTS:\n" );
  printf ( "  C version\n" );
  printf ( "  On a single picture, plot:\n" );
  printf ( "  * the variation in blood levels of a medicinal drug.\n" );
  printf ( "  * the minimal effective level.\n" );
  printf ( "  * the toxic level.\n" );
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
  fprintf ( command, "set output '%s_plots.png'\n", header );
  fprintf ( command, "set xlabel '<--- Hours --->'\n" );
  fprintf ( command, "set ylabel '<--- Concentration (mg/l) --->'\n" );
  fprintf ( command, "set title 'Drug level variation over time'\n" );
  fprintf ( command, "set key on\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "set style data lines\n" );
  fprintf ( command, "set yrange [0:1100]\n" );
  fprintf ( command, "plot '%s' using 1:2 with lines lw 3, \\\n", data_filename );
  fprintf ( command, "     [y=800:800] 0,48 with lines lw 3 lt rgb 'green' title 'Minimal medicinal level', \\\n" );
  fprintf ( command, "     1000 with lines lw 3 lt rgb 'red' title 'Toxic level'\n" );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "\n" );
  printf ( "DRUG_DOSAGE_PLOTS:\n" );
  printf ( "  Plot commands stored in \"%s\".\n", command_filename );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "DRUG_DOSAGE_PLOTS:\n" );
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
