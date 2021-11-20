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

    MAIN demonstrates the creation of a contour plot.

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
# define N 50

  double fpi;
  int i;
  int j;
  const double pi = 3.141592653589793;
  double step;
  double x;
  double xray[N];
  double y;
  double yray[N];
  double zlev;
  double zmat[N][N];

  fpi = pi / 180.0;

  timestamp ( );
  printf ( "\n" );
  printf ( "EX11:\n" );
  printf ( "  C version:\n" );
  printf ( "  Demonstrate the creation of a contour plot.\n" );

  step = 360.0 / ( double ) ( N - 1 );

  for ( i = 0; i < N; i++ )
  {
    xray[i] = ( double ) i * step;
    yray[i] = ( double ) i * step;
  }

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      x = xray[i] * fpi;
      y = yray[j] * fpi;    
      zmat[i][j] = 2.0 * sin(x) * sin(y);
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
  setfil ( "ex11.png" );
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

  titlin ( "Contour Plot", 1 );
  titlin ( "F(X,Y) = 2 * SIN(X) * SIN(Y)", 3 );

  name ( "X-axis", "x" );
  name ( "Y-axis", "y" );

  intax ( );
  axspos ( 450, 2670 );
  graf ( 0.0, 360.0, 0.0, 90.0, 0.0, 360.0, 0.0, 90.0 );

  height ( 30 );

  for ( i = 0; i < 9; i++ )
  {
    zlev = -2.+i*0.5;
    setclr ( ( i + 1 ) * 25 );
    if ( i == 4 )
    {
      labels ( "none", "contur" ); 
    }
    else
    {
      labels ( "double", "contur" );
    }

    contur ( xray, N, yray, N, (double *) zmat, zlev );
  }

  height ( 50 );
  color ( "fore" );
  title ( );
/*
  Close DISLIN.
*/
  disfin ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "EX11:\n" );
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

