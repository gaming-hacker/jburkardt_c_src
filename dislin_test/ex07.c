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

    MAIN demonstrates the creation of 3D bar and pie graphs.

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
  char cbuf[80];
  int ic1ray[5]  = { 50, 150, 100, 200, 175 };
  int ic2ray[5]  = { 50, 150, 100, 200, 175 };
  double xray[5]  = { 2.0, 4.0, 6.0, 8.0, 10.0 };
  double y1ray[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
  double y2ray[5] = { 3.2, 1.5, 2.0, 1.0, 3.0 };

  timestamp ( );
  printf ( "\n" );
  printf ( "EX07:\n" );
  printf ( "  C version:\n" );
  printf ( "  Demonstrate the creation of 3D bar and pie graphs.\n" );
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
  setfil ( "ex07.png" );
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

  titlin ( "3D Bar Graph / 3D Pie Chart", 2 );
  htitle ( 40 );

  shdpat ( 16 );
  axslen ( 1500, 1000 );
  axspos ( 300, 1400 );

  barwth ( 0.5);
  bartyp ( "3dvert" );
  labels ( "second", "bars" );
  labpos ( "outside", "bars" );
  labclr ( 255, "bars" );
  graf ( 0.0, 12.0, 0.0, 2.0, 0.0, 5.0, 0.0, 1.0 );
  title ( );
  color ( "red" );
  bars ( xray, y1ray, y2ray, 5 );
  endgrf ( );

  shdpat ( 16 );
  labels ( "data", "pie" );
  labclr ( 255, "pie" );
  chnpie ( "none" );
  pieclr ( ic1ray, ic2ray, 5 );
  pietyp ( "3d" );
  axspos ( 300, 2700 );
  piegrf ( cbuf, 0, y2ray , 5 );
/*
  Close DISLIN.
*/    
  disfin ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "EX07:\n" );
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

