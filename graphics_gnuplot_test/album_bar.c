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

    MAIN is the main program for album_bar.

  Discussion:

    album_bar creates a bar plot of data for music album sales over time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 July 2018

  Author:

    John Burkardt
*/
{
  char command_filename[] = "album_commands.txt";
  FILE *command;
  char data_filename[] = "album_data.txt";
  char graphic_filename[] = "album_bar.png";

  timestamp ( );
  printf ( "\n" );
  printf ( "ALBUM_BAR:\n" );
  printf ( "  C version\n" );
  printf ( "  Create a bar plot of music album sales over time.\n" );
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
  fprintf ( command, "set xlabel '<--- Year --->'\n" );
  fprintf ( command, "set ylabel '<--- Millions --->'\n" );
  fprintf ( command, "set title 'Music album sales, all formats'\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "set yrange [0:550]\n" );
  fprintf ( command, "set boxwidth 0.8\n" );
  fprintf ( command, "set style fill solid\n" );
  fprintf ( command, "plot '%s' using 1:2 with boxes lc rgb 'red'\n", data_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "\n" );
  printf ( "ALBUM_BAR:\n" );
  printf ( "  Plot commands stored in \"%s\".\n", command_filename );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ALBUM_BAR:\n" );
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
