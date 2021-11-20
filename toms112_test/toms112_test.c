# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "toms112.h"

int main ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TOMS112_TEST.

  Discussion:

    TOMS112_TEST tests the TOMS112 library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 November 2016

  Author:

    John Burkardt
*/
{
  bool inside;
  int n = 5;
  int test;
  int test_num = 4;
  double x[5] = { 0.0,  1.0,  2.0,  1.0,  0.0 };
  double x0;
  double x0_test[4] = { 1.0, 3.0, 0.0, 0.5 };
  double y[5] = { 0.0, 0.0, 1.0, 2.0, 2.0 };
  double y0;
  double y0_test[4] = { 1.0, 4.0, 2.0, -0.25 };

  timestamp ( );
  printf ( "\n" );
  printf ( "TOMS112_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  POINT_IN_POLYGON determines if a point is in a polygon.\n" );

  r8vec2_print ( n, x, y, "  The polygon vertices:" );

  printf ( "\n" );
  printf ( "        Px       Py  Inside\n" );
  printf ( "\n" );

  for ( test = 0; test < test_num; test++ )
  {
    x0 = x0_test[test];
    y0 = y0_test[test];
 
    inside = point_in_polygon ( n, x, y, x0, y0 );

    printf ( "  %8.4g %8.4g       %d\n", x0, y0, inside );
  }
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TOMS112_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}

