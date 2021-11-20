# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "toms112.h"

/******************************************************************************/

bool point_in_polygon ( int n, double x[], double y[], double x0, double y0 )

/******************************************************************************/
/*
  Purpose:

    POINT_IN_POLYGON determines if a point is inside a polygon

  Discussion:

    If the points ( x(i), y(i) ) ( i = 1, 2, ..., n ) are,
    in this cyclic order, the vertices of a simple closed polygon and
    (x0,y0) is a point not on any side of the polygon, then the
    procedure determines, by setting "point_in_polygon" to TRUE or FALSE,
    whether (x0,y0) lies in the interior of the polygon.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 November 2016

  Author:

    John Burkardt

  Reference:

    Moshe Shimrat,
    ACM Algorithm 112,
    Position of Point Relative to Polygon,
    Communications of the ACM,
    Volume 5, Number 8, page 434, August 1962.

    Richard Hacker,
    Certification of Algorithm 112,
    Communications of the ACM,
    Volume 5, Number 12, page  606, December 1962.

  Parameters:

    Input, int N, the number of nodes or vertices in 
    the polygon.  N must be at least 3.

    Input, double X[N], Y[N], the vertices of the polygon.

    Input, double X0, Y0, the coordinates of the point to be tested.

    Output, bool POINT_IN_POLYGON, is TRUE if the point is
    inside the polygon.
*/
{
  int i;
  int ip1;
  double t;
  bool value;
  
  value = false;

  for ( i = 0; i < n; i++ )
  {
    ip1 = ( ( i + 1 ) % n );

    if ( ( y[ip1] < y0 ) == ( y0 <= y[i] ) )
    {
      t = x0 - x[i] - ( y0 - y[i] ) * ( x[ip1] - x[i] ) / ( y[ip1] - y[i] );
      if ( t < 0.0 )
      {
        value = ! value;
      }
    }
  }

  return value;
}
/******************************************************************************/

void r8vec2_print ( int n, double a1[], double a2[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC2_PRINT prints an R8VEC2.

  Discussion:

    An R8VEC2 is a dataset consisting of N pairs of real values, stored
    as two separate vectors A1 and A2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 March 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A1[N], double A2[N], the vectors to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );
  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %4d: %14g  %14g\n", i, a1[i], a2[i] );
  }

  return;
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

