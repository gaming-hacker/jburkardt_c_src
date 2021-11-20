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

    MAIN demonstrates the use of bar graphs.

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
  static char cbuf[25];
  static char *ctit = "Bar Graphs (BARS)";
  int i;
  int nya = 2700;
  static double x[9]  = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
  static double y[9]  = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  static double y1[9] = { 1.0, 1.5, 2.5, 1.3, 2.0, 1.2, 0.7, 1.4, 1.1 };
  static double y2[9] = { 2.0, 2.7, 3.5, 2.1, 3.2, 1.9, 2.0, 2.3, 1.8 };
  static double y3[9] = { 4.0, 3.5, 4.5, 3.7, 4.0, 2.9, 3.0, 3.2, 2.6 };

  timestamp ( );
  printf ( "\n" );
  printf ( "EX05:\n" );
  printf ( "  C version:\n" );
  printf ( "  Demonstrate the display of data in bar graphs.\n" );
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
  setfil ( "ex05.png" );
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
  ticks ( 1, "x" );
  intax ( );
  axslen ( 1600, 700 );
  titlin ( ctit, 3 );

  legini ( cbuf, 3, 8 );
  leglin ( cbuf, "FIRST", 1 );
  leglin ( cbuf, "SECOND", 2 );
  leglin ( cbuf, "THIRD", 3 );
  legtit ( " " );
  shdpat ( 5L );

  for ( i = 1; i <= 3; i++ )
  {
     if ( 1 < i )
     {
       labels ( "none", "x" );
     }
    axspos ( 300, nya-(i-1)*800 );

    graf ( 0.0, 10.0, 0.0, 1.0, 0.0, 5.0, 0.0, 1.0 );

    if ( i == 1 )
    {
      bargrp ( 3, 0.15 );
      color ( "red" );
      bars ( x, y, y1, 9 );
      color ( "green" );
      bars ( x, y, y2, 9 );
      color ( "blue" );
      bars ( x, y, y3, 9 );
      color ( "fore" );
      reset ( "bargrp" );
    }
    else if ( i == 2 )
    {
      height ( 30 );
      labels ( "delta", "bars" );
      labpos ( "center", "bars" );
      color ( "red" );
      bars ( x, y, y1, 9 );
      color ( "green" );
      bars ( x, y1, y2, 9 );
      color ( "blue" );
      bars ( x, y2, y3, 9 );
      color ( "fore" );
      reset ( "height" ); 
    }
    else if ( i == 3 )
    {
      labels ( "second", "bars" );
      labpos ( "outside", "bars" );
      color ( "red" );
      bars ( x, y, y1, 9 );
      color ( "fore" );
    }

    if ( i < 3 )
    {
      legend ( cbuf, 7 );
    }
    else
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
  printf ( "EX05:\n" );
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

