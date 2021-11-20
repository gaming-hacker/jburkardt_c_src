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

    MAIN is the main program for CORKSCREW_PLOT3D.

  Discussion:

    CORKSCREW_PLOT3D creates a plot of a 3D curve resembling a corkscrew.

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
  char header[] = "corkscrew";
  int i;
  int n;
  double *r;
  const double r8_pi = 3.141592653589793;
  double *theta;
  double theta_max;
  double theta_min;
  double *x;
  double *y;
  double *z;

  timestamp ( );
  printf ( "\n" );
  printf ( "CORKSCREW_PLOT3D:\n" );
  printf ( "  C version\n" );
  printf ( "  Define (X,Y,Z) data on a 3D curve.\n" );
  printf ( "  Create corresponding GNUPLOT input files.\n" );
/*
  Set number of points in plot.
*/
  n = 101;
/*
  Allocate arrays.
*/
  r = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );
/*
  Define the data.
*/
  z = r8vec_linspace_new ( n, -2.0, 2.0 );
  theta_min = - 6.0 * r8_pi;
  theta_max = + 6.0 * r8_pi;
  theta = r8vec_linspace_new ( n, theta_min, theta_max );
  for ( i = 0; i < n; i++ )
  {
    r[i] = 1.0 + z[i] * z[i];
    x[i] = r[i] * sin ( theta[i] );
    y[i] = r[i] * cos ( theta[i] );
  }
/*
  Create the data file.
*/
  strcpy ( data_filename, header );
  strcat ( data_filename, "_data.txt" );

  data = fopen ( data_filename, "wt" );

  for ( i = 0; i < n; i++ )
  {
    fprintf ( data, "  %g  %g  %g\n", x[i], y[i], z[i] );
  }

  fclose ( data );

  printf ( "\n" );
  printf ( "  CORKSCREW_PLOT3D: data stored in \"%s\".\n", data_filename );
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
  fprintf ( command, "set xlabel 'X'\n" );
  fprintf ( command, "set ylabel 'Y'\n" );
  fprintf ( command, "set zlabel 'Z'\n" );
  fprintf ( command, "set title 'Corkscrew curve'\n" );
  fprintf ( command, "set grid\n" );
  fprintf ( command, "set style data lines\n" );
  fprintf ( command, "splot '%s' using 1:2:3 with lines\n", data_filename );
  fprintf ( command, "quit\n" );

  fclose ( command );

  printf ( "  CORKSCREW_PLOT3D: plot commands stored in \"%s\".\n", 
    command_filename );
/*
  Free memory.
*/
  free ( r );
  free ( theta );
  free ( x );
  free ( y );
  free ( z );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "CORKSCREW_PLOT3D:\n" );
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
