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

    MAIN demonstrates the use of the CURVE routine.

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
  int nthk;
  const double pi = 3.141592653589793;
  double step;
  double x;
  double xray[N];
  double y1ray[N];
  double y2ray[N];

  fpi = pi / 180.0;

  timestamp ( );
  printf ( "\n" );
  printf ( "EX01:\n" );
  printf ( "  C version:\n" );
  printf ( "  Demonstrate the use of the CURVE routine, for\n" );
  printf ( "  plotting (X,Y) data.\n" );

  step = 360.0 / ( double ) ( N - 1 );

  for ( i = 0; i < N; i++ )
  {
    xray[i] = i * step;
    x = xray[i] * fpi;
    y1ray[i] = sin ( x );
    y2ray[i] = cos ( x );
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
  setfil ( "ex01.png" );
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
  Plot a border around the page.
*/
  pagera ( );
/*
  Use the COMPLEX font.
*/
  complx ( );
  axspos ( 450, 1800 );
  axslen ( 2200, 1200 );

  name ( "X-axis", "x" );
  name ( "Y-axis", "y" );

  labdig ( -1, "x" );
  ticks ( 10, "xy" );

  titlin ( "Demonstration of CURVE", 1 );
  titlin ( "SIN(X), COS(X)", 3 );

  graf ( 0.0, 360.0, 0.0, 90.0, -1.0, 1.0, -1.0, 0.5 );
  title ( );

  color ( "red" );
  curve ( xray, y1ray, N );
/*
  Make the second curve thicker.
*/
  nthk = 10;
  thkcrv ( nthk );

  color ( "green" );
  curve ( xray, y2ray, N );

  color ( "fore" );
  dash ( );
  xaxgit ( );
/*
  Close DISLIN.
*/
  disfin ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "EX01:\n" );
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

