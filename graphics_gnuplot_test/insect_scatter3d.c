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

    MAIN is the main program for INSECT_SCATTER3D.

  Discussion:

    INSECT_SCATTER3D creates a 3D scatter plot of insect measurements.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 July 2018

  Author:

    John Burkardt
*/
{
  char command_filename[] = "insect_commands.txt";
  FILE *command;
  char data_a_filename[] = "insect_a_data.txt";
  char data_b_filename[] = "insect_b_data.txt";
  char data_c_filename[] = "insect_c_data.txt";
  char plot_filename[] = "insect_scatter3d.png";

  timestamp ( );
  printf ( "\n" );
  printf ( "INSECT_SCATTER3D:\n" );
  printf ( "  C version\n" );
  printf ( "  Create a 3D scatter plot of measurements of three\n" );
  printf ( "  physical characteristics of 3 species of insects.\n" );
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
  fprintf ( command, "set xlabel '<--- First Tarsus --->'\n" );
  fprintf ( command, "set ylabel '<--- Second Tarsus --->'\n" );
  fprintf ( command, "set zlabel '<--- Max Aedeagus --->'\n" );
  fprintf ( command, "set title 'Sample Measurements of 3 Insect Species'\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "unset key\n" );
  fprintf ( command, "splot '%s' with points pt 7 ps 2 lt rgb 'red',\\\n", data_a_filename );
  fprintf ( command, "      '%s' with points pt 7 ps 2 lt rgb 'green',\\\n", data_b_filename );
  fprintf ( command, "      '%s' with points pt 7 ps 2 lt rgb 'blue'\n", data_c_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "\n" );
  printf ( "INSECT_SCATTER3D:\n" );
  printf ( "  Plot commands stored in \"%s\".\n", command_filename );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "INSECT_SCATTER3D:\n" );
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
