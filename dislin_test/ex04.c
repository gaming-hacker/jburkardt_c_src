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

    MAIN demonstrates the use of the interpolation options when using CURVE.

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
  static char *cpol[6] = { "SPLINE", "STEM", "BARS", "STAIRS", "STEP", "LINEAR" };
  static char *ctit    = "Interpolation Methods";
  int i;
  int nx;
  int ny;
  int nya = 2700;
  static double x[] = {
     0.0,  1.0,  3.0,  4.5,  6.0,  8.0,  9.0, 11.0, 12.0, 12.5,
    13.0, 15.0, 16.0, 17.0, 19.0, 20.0 };
  static double y[] = {
     2.0,  4.0,  4.5,  3.0,  1.0,  7.0,  2.0,  3.0,  5.0,  2.0, 
     2.5,  2.0,  4.0,  6.0,  5.5,  4.0 };

  timestamp ( );
  printf ( "\n" );
  printf ( "EX04:\n" );
  printf ( "  C version:\n" );
  printf ( "  Demonstrate the use of the various interpolation options\n" );
  printf ( "  when using CURVE to plot (X,Y) data.\n" );
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
  setfil ( "ex04.png" );
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
  Use the COMPLEX font.
*/
  complx ( );
  incmrk ( 1 );
  hsymbl ( 25 );
  titlin ( ctit, 1 );
  axslen ( 1500, 350 );

  setgrf ( "line", "line", "line", "line" );

  for ( i = 0; i < 6; i++ )
  {
    axspos ( 350, nya-i*350 );
    polcrv ( cpol[i] );
    marker ( 0 );

    graf ( 0.0, 20.0, 0.0, 5.0, 0.0, 10.0, 0.0, 5.0 );
    nx = nxposn ( 1.0 );
    ny = nyposn ( 8.0 );
    messag ( cpol[i], nx, ny );
    curve ( x, y, 16 );

    if ( i == 5 )
    {
      height ( 50 );
      title ( );
    }
    endgrf ( );
  }
/*
  Close DISLIN.
*/
  disfin ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "EX04:\n" );
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

