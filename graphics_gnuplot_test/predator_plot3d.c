# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

int main ( );
double *r8vec_linspace_new ( int n, double a, double b );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for PREDATOR_PLOT3D.

  Discussion:

    PREDATOR_PLOT3D computes and plots some predator/prey data.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 April 2018

  Author:

    John Burkardt
*/
{
  char command_filename[80];
  FILE *command;
  char data_filename[80];
  FILE *data;
  double dt;
  char header[] = "predator";
  int i;
  int n;
  double *pred;
  double *prey;
  double *t;

  timestamp ( );
  printf ( "\n" );
  printf ( "PREDATOR_PLOT3D:\n" );
  printf ( "  C version\n" );
  printf ( "  Model the interaction between rabbits and foxes.\n" );
  printf ( "  Create corresponding GNUPLOT input files.\n" );
/*
  Set number of points in plot.
*/
  n = 1001;
/*
  Allocate arrays.
*/
  t = ( double * ) malloc ( n * sizeof ( double ) );
  pred = ( double * ) malloc ( n * sizeof ( double ) );
  prey = ( double * ) malloc ( n * sizeof ( double ) );
/*
  Define the data.
*/
  dt = ( 5.0 - 0.0 ) / ( double ) ( n - 1 );

  t[0] = 0.0;
  prey[0] = 5000.0;
  pred[0] = 100.0;

  for ( i = 1; i < n; i++ )
  {
    t[i] = t[i-1] + dt;
    prey[i] = prey[i-1] + dt * (    2.0 * prey[i-1] - 0.001 * pred[i-1] * prey[i-1] );
    pred[i] = pred[i-1] + dt * ( - 10.0 * pred[i-1] + 0.002 * pred[i-1] * prey[i-1] );
  }
/*
  Create the data file.
*/
  strcpy ( data_filename, header );
  strcat ( data_filename, "_data.txt" );

  data = fopen ( data_filename, "wt" );

  for ( i = 0; i < n; i++ )
  {
    fprintf ( data, "  %g  %g  %g\n", t[i], prey[i], pred[i] );
  }

  fclose ( data );

  printf ( "\n" );
  printf ( "  PREDATOR_PLOT3D: data stored in \"%s\".\n", data_filename );
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
  fprintf ( command, "set output '%s_plot3d.png'\n", header );
  fprintf ( command, "set xlabel '<-- Predator -->'\n" );
  fprintf ( command, "set ylabel '<-- Prey -->'\n" );
  fprintf ( command, "set zlabel '<-- Time -->'\n" );
  fprintf ( command, "set title 'Predator/prey evolution'\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "set style data lines\n" );
  fprintf ( command, "splot '%s' using 2:3:1 with lines\n", data_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "  PREDATOR_PLOT3D: plot commands stored in \"%s\".\n", 
    command_filename );
/*
  Free memory.
*/
  free ( pred );
  free ( prey );
  free ( t );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "PREDATOR_PLOT3D:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

double *r8vec_linspace_new ( int n, double a, double b )

/******************************************************************************/
/*
  Purpose:

    R8VEC_LINSPACE_NEW creates a vector of linearly spaced values.

  Discussion:

    An R8VEC is a vector of R8's.

    4 points evenly spaced between 0 and 12 will yield 0, 4, 8, 12.
 
    In other words, the interval is divided into N-1 even subintervals,
    and the endpoints of intervals are used as the points.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2011

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double A, B, the first and last entries.

    Output, double R8VEC_LINSPACE_NEW[N], a vector of linearly spaced data.
*/
{
  int i;
  double *x;

  x = ( double * ) malloc ( n * sizeof ( double ) );

  if ( n == 1 )
  {
    x[0] = ( a + b ) / 2.0;
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      x[i] = ( ( double ) ( n - 1 - i ) * a 
             + ( double ) (         i ) * b ) 
             / ( double ) ( n - 1     );
    }
  }
  return x;
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
