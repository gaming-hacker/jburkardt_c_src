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
# define N 18

  char cbuf[80];
  int i;
  int icray[N] = { 30, 30, 30, 30, 30, 30, 100, 100, 100, 100,
                 100, 100, 170, 170, 170, 170, 170, 170 };
  double xray[N]  = { 1.0, 3.0, 8.0, 1.5, 9.0, 6.3, 5.8, 2.3, 8.1, 3.5,
                     2.2, 8.7, 9.2, 4.8, 3.4, 6.9, 7.5, 3.8 };
  double xwray[N];
  double yray[N]  = {5.0, 8.0, 3.5, 2.0, 7.0, 1.0, 4.3, 7.2, 6.0, 8.5,
                    4.1, 5.0, 7.3, 2.8, 1.6, 8.9, 9.5, 3.2 };
  double ywray[N];
  double z1ray[N] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  double z2ray[N] = { 4.0, 5.0, 3.0, 2.0, 3.5, 4.5, 2.0, 1.6, 3.8, 4.7,
                    2.1, 3.5, 1.9, 4.2, 4.9, 2.8, 3.6, 4.3 };

  timestamp ( );
  printf ( "\n" );
  printf ( "EX07B:\n" );
  printf ( "  C version:\n" );
  printf ( "  Demonstrate 3D bar graphs.\n" );

  for ( i = 0; i < N; i++ )
  {
    xwray[i] = 0.5;
    ywray[i] = 0.5;
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
  setfil ( "ex07b.png" );
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
  axspos ( 200, 2600 );
  axslen ( 1800, 1800 );

  name ( "X-axis", "x" );
  name ( "Y-axis", "y" );
  name ( "Z-axis", "z" );

  titlin ( "3D Bars / BARS3D", 3 );
  labl3d ( "hori" );

  graf3d ( 0.0, 10.0, 0.0, 2.0, 0.0, 10.0, 0.0, 2.0, 0.0, 5.0, 0.0, 1.0 );
  grid3d ( 1, 1, "bottom" );
  bars3d ( xray, yray, z1ray, z2ray, xwray, ywray, icray, N );

  legini ( cbuf, 3, 20 );
  legtit ( " ");
  legpos ( 1350, 1150 );
  leglin ( cbuf, "First", 1 );
  leglin ( cbuf, "Second", 2 );
  leglin ( cbuf, "Third", 3 );
  legend ( cbuf, 3);

  height ( 50 );
  title ( );
/*
  Close DISLIN.
*/
  disfin ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "EX07B:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;

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

