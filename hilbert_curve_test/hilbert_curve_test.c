# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "hilbert_curve.h"

int main ( );
void d2xy_test ( );
void rot_test ( );
void xy2d_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for HILBERT_CURVE_TEST.

  Modified:

    02 January 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "HILBERT_CURVE_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the HILBERT_CURVE library.\n" );

  d2xy_test ( );
  rot_test ( );
  xy2d_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "HILBERT_CURVE_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void d2xy_test ( )

/******************************************************************************/
/*
  Purpose:

    D2XY_TEST tests D2XY.

  Modified:

    05 December 2015

  Author:

    John Burkardt
*/
{
  int d;
  int m;
  int n;
  int x;
  int y;

  printf ( "\n" );
  printf ( "D2XY_TEST:\n" );
  printf ( "  D2XY converts a Hilbert linear D coordinate to an (X,Y) 2D coordinate.\n" );

  m = 3;
  n = i4_power ( 2, m );

  printf ( "\n" );
  printf ( "    D    X    Y\n" );
  printf ( "\n" );
  for ( d = 0; d < n * n; d++ )
  {
    d2xy ( m, d, &x, &y );
    printf ( "  %3d  %3d  %3d\n", d, x, y );
  }
  return;
}
/******************************************************************************/

void rot_test ( )

/******************************************************************************/
/*
  Purpose:

    ROT_TEST tests ROT.

  Modified:

    02 January 2016

  Author:

    John Burkardt
*/
{
  int m;
  int n;
  int rx;
  int ry;
  int x;
  int x0;
  int x1;
  int y;
  int y0;
  int y1;

  printf ( "\n" );
  printf ( "ROT_TEST:\n" );
  printf ( "  ROT rotates and flips a quadrant appropriately.\n" );
  printf ( "\n" );
  printf ( "   X   Y  X0  Y0  X1  Y1\n" );
  printf ( "\n" );

  m = 3;
  n = i4_power ( 2, m );
  ry = 0;

  for ( y = 0; y < 8; y++ )
  {
    for ( x = 0; x < 8; x++ )
    {
      rx = 0;
      x0 = x;
      y0 = y;
      rot ( n, &x0, &y0, rx, ry );
      rx = 1;
      x1 = x;
      y1 = y;
      rot ( n, &x1, &y1, rx, ry );
      printf ( "  %2d  %2d  %2d  %2d  %2d  %2d\n", x, y, x0, y0, x1, y1 );
    }
  }
  return;
}
/******************************************************************************/

void xy2d_test ( )

/******************************************************************************/
/*
  Purpose:

    XY2D_TEST tests XY2D.

  Modified:

    05 December 2015

  Author:

    John Burkardt
*/
{
  int d;
  int m;
  int n;
  int x;
  int y;

  printf ( "\n" );
  printf ( "XY2D_TEST:\n" );
  printf ( "  XY2D converts an (X,Y) 2D coordinate to a Hilbert linear D coordinate.\n" );

  m = 3;
  n = i4_power ( 2, m );

  printf ( "\n" );
  printf ( "        " );
  for ( x = 0; x < n; x++ )
  {
    printf ( "%3d", x );
  }
  printf ( "\n" );
  printf ( "\n" );
  for ( y = n - 1; 0 <= y; y-- )
  {
    printf ( "  %3d:  ", y );
    for ( x = 0; x < n; x++ )
    {
      d = xy2d ( m, x, y );
      printf ( "%3d", d );
    }
    printf ( "\n" );
  }
  return;
}
