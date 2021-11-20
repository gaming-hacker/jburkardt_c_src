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

    QUICKPLOT_CURVE demonstrates the DISLIN quickplot command QPLOT.

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
  int i;
  int n = 100;
  double pi = 3.1415926;
  double *xray;
  double *yray;

  timestamp ( );
  printf ( "\n" );
  printf ( "QUICKPLOT_CURVE:\n" );
  printf ( "  C version:\n" );
  printf ( "  Demonstrate the DISLIN 'quickplot' command QPLOT\n" );
  printf ( "  to plot a curve.\n" );
/*
  Set up the X and Y data for the plot.
*/
  xray = ( double * ) malloc ( n * sizeof ( double ) );
  yray = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    xray[i] = ( double ) ( i ) * 360.0 / ( double ) ( n - 1 );
  }
  for ( i = 0; i < n; i++ )
  {
    yray[i] = sin ( pi * xray[i] / 180.0 );
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
  setfil ( "quickplot_curve.png" );
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
  name ( "<-- Angle in Degrees -->", "X" );
  name ( "<-- Sine (angle) -->", "Y" );
  titlin ( "Quick plot by QPLOT", 2 );
/*
  Draw the curve.
*/
  qplot ( xray, yray, n );
/*
  Close DISLIN.
*/
  disfin ( );
/*
  Free memory.
*/
  free ( xray );
  free ( yray );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "QUICKPLOT_CURVE:\n" );
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
