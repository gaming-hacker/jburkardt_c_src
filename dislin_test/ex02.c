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

    MAIN demonstrates the use of the POLAR routine.

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
# define M 10
# define N 300

  double a;
  double f;
  int i;
  const double pi = 3.141592653589793;
  double step;
  double x2[M];
  double xray[N];
  double y2[M];
  double yray[N];

  f = pi / 180.0;

  timestamp ( );
  printf ( "\n" );
  printf ( "EX02:\n" );
  printf ( "  C version:\n" );
  printf ( "  Demonstrate the use of the POLAR routine, for\n" );
  printf ( "  plotting (R,Theta) data.\n" );

  step = 360.0 / ( double ) ( N - 1 );

  for ( i = 0; i < N; i++ )
  { 
    a = ( double ) i * step * f;
    yray[i] = a;
    xray[i] = sin ( 5.0 * a );
  }

  for ( i = 0; i < M; i++ )
  {
    x2[i] = ( double ) ( i + 1 );
    y2[i] = ( double ) ( i + 1 );
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
  setfil ( "ex02.png" );
/*
  Choose the page size and orientation.
*/
  setpag ( "usap" );
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
  Use the HARDWARE font.
*/
  hwfont ( );
  axspos ( 450, 1800 );

  titlin ( "Polar Plots", 2 );
  ticks  ( 3, "Y" );
  axends ( "NOENDS", "X" );
  labdig ( -1, "Y" );
  axslen ( 1000, 1000 );
  axsorg ( 1050, 900 );

  polar  ( 1.0, 0.0, 0.2, 0.0, 30.0 );
  curve  ( xray, yray, N );
  htitle ( 50 );
  title  ( );
  endgrf ( );

  labdig ( -1, "X" );
  axsorg ( 1050, 2250 );
  labtyp ( "VERT", "Y" );
  polar  ( 10.0, 0.0, 2.0, 0.0, 30.0 );
  barwth ( -5.0 );
  polcrv ( "FBARS" );
  curve  ( x2, y2, M );
/*
  Close DISLIN.
*/          
  disfin ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "EX02:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
# undef M
# undef N
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

