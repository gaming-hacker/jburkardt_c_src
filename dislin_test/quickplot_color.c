# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "dislin_d.h"

int main ( int argc, char *argv[] );
void timestamp ( );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    QUICKPLOT_COLOR demonstrates the DISLIN quickplot command QPLCLR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:
 
    28 February 2014

  Author:

    This C version by John Burkardt.

  Reference:

    Helmut Michels,
    The Data Plotting Software DISLIN - version 10.4,
    Shaker Media GmbH, January 2010,
    ISBN13: 978-3-86858-517-9.
*/
{
# define N 100

  double fpi;
  int i;
  int j;
  int n = N;
  const double pi = 3.141592653589793;
  double step;
  double x;
  double y;
  double zmat[N][N];

  fpi = pi / 180.0;

  timestamp ( );
  printf ( "\n" );
  printf ( "QUICKPLOT_CURVE:\n" );
  printf ( "  C version:\n" );
  printf ( "  Demonstrate the DISLIN 'quickplot' command QPLCLR\n" );
  printf ( "  to make a color plot of a matrix of data.\n" );
/*
  Set up the X and Y data for the plot.
*/
  step = 360.0 / ( double ) ( N - 1 );
  for ( i = 0; i < N; i++ )
  {
    x = ( double ) i * step;
    for ( j = 0; j < N; j++ )
    {
      y = ( double ) j * step;
      zmat[i][j] = 2.0 * sin ( x * fpi ) * sin ( y * fpi );
    }
  }
/*
  Specify the format of the output file.
*/
  metafl ( "png" );
/*
  Specify that if a file already exists of the given name,
  the new data should overwrite the old.
*/
  filmod ( "delete" );
/*
  Specify the name of the output graphics file.
*/
  setfil ( "quickplot_color.png" );
/*
  Choose the page size and orientation.
*/
  setpag ( "usal" );
/*
  For PNG output, reverse the default black background to white.
*/
  scrmod ( "reverse" );
/*
  Open DISLIN.
*/
  disini ( );
/*
  Label the axes and the plot.
*/
  name ( "X-axis", "x" );
  name ( "Y-axis", "y" );
  titlin ( "Quick plot by QPLCLR", 2 );
/*
  Draw the curve.
*/
  qplclr ( ( double * ) zmat, n, n );
/*
  Close DISLIN.
*/
  disfin ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "QUICKPLOT_COLOR:\n" );
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

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2003

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

  fprintf ( stdout, "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}

