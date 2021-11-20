# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "triangle_interpolate.h"

int main ( );
void triangle_interpolate_linear_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_INTERPOLATE_TEST tests the TRIANGLE_INTERPOLATE library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 January 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TRIANGLE_INTERPOLATE_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TRIANGLE_INTERPOLATE library.\n" );

  triangle_interpolate_linear_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TRIANGLE_INTERPOLATE_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void triangle_interpolate_linear_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_INTERPOLATE_LINEAR_TEST tests TRIANGLE_INTERPOLATE_LINEAR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 January 2016

  Author:

    John Burkardt
*/
{
  int j;
  int m = 3;
  int n = 10;
  double *p;
  double p1[2] = { 0.0, 1.0 };
  double p2[2] = { 5.0, 0.0 };
  double p3[2] = { 4.0, 4.0 };
  int seed;
  double *v;
  double v1[3] = { 1.0, 0.0, 0.0 };
  double v2[3] = { 0.0, 1.0, 0.0 };
  double v3[3] = { 0.0, 0.0, 1.0 };

  printf ( "\n" );
  printf ( "TRIANGLE_INTERPOLATE_LINEAR_TEST\n" );
  printf ( "  TRIANGLE_INTERPOLATE_LINEAR uses linear interpolation\n" );
  printf ( "  on vertex data to estimate values in the interior.\n" );
/*
  Get N sample points inside the triangle.
*/
  seed = 123456789;
  p = uniform_in_triangle_map1 ( p1, p2, p3, n, &seed );
/*
  Request an intepolated value for R, G and B at each point.
*/
  v = triangle_interpolate_linear ( m, n, p1, p2, p3, p, v1, v2, v3 );
/*
  Report the data.
*/
  printf ( "\n" );
  printf ( "       X               Y               V(1)            V(2)            V(3)\n" );
  printf ( "\n" );
  printf ( "  %14.6g  %14.6g  %14.6g  %14.6g  %14.6g\n", 
    p1[0], p1[1], v1[0], v1[1], v1[2] );
  printf ( "  %14.6g  %14.6g  %14.6g  %14.6g  %14.6g\n", 
    p2[0], p2[1], v2[0], v2[1], v2[2] );
  printf ( "  %14.6g  %14.6g  %14.6g  %14.6g  %14.6g\n", 
    p3[0], p3[1], v3[0], v3[1], v3[2] );
  printf ( "\n" );
  for ( j = 0; j < n; j++ )
  {
    printf ( "  %14.6g  %14.6g  %14.6g  %14.6g  %14.6g\n", 
      p[0+j*2], p[1+j*2], v[0+j*m], v[1+j*m], v[2+j*m] );
  }

  free ( p );
  free ( v );

  return;
}
