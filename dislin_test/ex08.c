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

    MAIN demonstrates the use of shade patterns.

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
  static char cstr[3];
  static char *ctit = "Shading Patterns (AREAF)";
  int i;
  int iclr;
  int ii;
  static int ix[4] = { 0, 300, 300, 0 };
  int ixp[4];
  static int iy[4] = {0, 0, 400, 400 };
  int iyp[4];
  int j;
  int k;
  int nl;
  int nx;
  int nx0 = 335;
  int ny;
  int ny0 = 350;

  timestamp ( );
  printf ( "\n" );
  printf ( "EX08:\n" );
  printf ( "  C version:\n" );
  printf ( "  Demonstrate the use of shade patterns.\n" );
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
  setfil ( "ex08.png" );
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
  setvlt ( "small" );

  height ( 50 );
  nl = nlmess ( ctit );
  nx = ( 2970 - nl ) / 2 ;
  messag ( ctit, nx, 200 );

  iclr = 0;
  for ( i = 0; i < 3; i++ )
  {
    ny = ny0 + i * 600;
    for ( j = 0; j < 6; j++ )
    {
      nx = nx0 + j * 400;
      ii = i * 6 + j;
      shdpat ( (long) ii );
      sprintf ( cstr, "%d", ii );

      iclr = iclr % 16;
      iclr = iclr + 1;
      setclr ( iclr );

      for ( k = 0; k < 4; k++ )
      {
        ixp[k] = ix[k] + nx;
        iyp[k] = iy[k] + ny;
      }
      areaf ( ixp, iyp, 4 );

      nl = nlmess ( cstr );
      nx = nx + ( 300 - nl ) / 2;
      messag ( cstr, nx, ny+460 );
    }
  }
/*
  Close DISLIN.
*/
  disfin ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "EX08:\n" );
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

