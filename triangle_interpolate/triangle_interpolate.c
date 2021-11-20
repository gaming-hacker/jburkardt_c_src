# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "triangle_interpolate.h"

/******************************************************************************/

void r8vec_uniform_01 ( int n, int *seed, double r[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01 returns a unit pseudorandom R8VEC.

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Second Edition,
    Springer, 1987,
    ISBN: 0387964673,
    LC: QA76.9.C65.B73.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, December 1986, pages 362-376.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998,
    ISBN: 0471134031,
    LC: T57.62.H37.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, Number 2, 1969, pages 136-143.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R[N], the vector of pseudorandom values.
*/
{
  int i;
  const int i4_huge = 2147483647;
  int k;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8VEC_UNIFORM_01 - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }

    r[i] = ( double ) ( *seed ) * 4.656612875E-10;
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

    17 June 2014 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2014

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

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
/******************************************************************************/

double triangle_area ( double p1x, double p1y, double p2x, double p2y, 
  double p3x, double p3y )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_AREA computes the area of a triangle in 2D.

  Discussion:

    If the triangle's vertices are given in counter clockwise order,
    the area will be positive.  If the triangle's vertices are given
    in clockwise order, the area will be negative!

    An earlier version of this routine always returned the absolute
    value of the computed area.  I am convinced now that that is
    a less useful result!  For instance, by returning the signed 
    area of a triangle, it is possible to easily compute the area 
    of a nonconvex polygon as the sum of the (possibly negative) 
    areas of triangles formed by node 1 and successive pairs of vertices.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 October 2005

  Author:

    John Burkardt

  Parameters:

    Input, double P1X, P1Y, P2X, P2Y, P3X, P3Y, the coordinates
    of the vertices P1, P2, and P3.

    Output, double TRIANGLE_AREA, the area of the triangle.
*/
{
  double area;

  area = 0.5 * ( 
    p1x * ( p2y - p3y ) + 
    p2x * ( p3y - p1y ) + 
    p3x * ( p1y - p2y ) );
 
  return area;
}
/******************************************************************************/

double *triangle_interpolate_linear ( int m, int n, double p1[2], double p2[2], 
  double p3[2], double p[2], double v1[], double v2[], double v3[] )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_INTERPOLATE_LINEAR interpolates data given on a triangle's vertices.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 January 2015

  Author:

    John Burkardt

  Parameters:

    Input, int M, the dimension of the quantity.

    Input, int N, the number of points.

    Input, double P1[2], P2[2], P3[2], the vertices of the triangle,
    in counterclockwise order.

    Input, double P[2*N], the point at which the interpolant is desired.

    Input, double V1[M], V2[M], V3[M], the value of some quantity at the vertices.

    Output, double TRIANGLE_INTERPOLATE_LINEAR[M,N], the interpolated value 
    of the quantity at P.
*/
{
  double abc;
  double apc;
  double abp;
  int i;
  int j;
  double pbc;
  double *v;

  v = ( double * ) malloc ( m * n * sizeof ( double ) );

  abc = triangle_area ( p1[0], p1[1], p2[0], p2[1], p3[0], p3[1] );

  for ( j = 0; j < n; j++ )
  {
    pbc = triangle_area ( p[0+j*2], p[1+j*2], p2[0],    p2[1],    p3[0],    p3[1] );
    apc = triangle_area ( p1[0],    p1[1],    p[0+j*2], p[1+j*2], p3[0],    p3[1] );
    abp = triangle_area ( p1[0],    p1[1],    p2[0],    p2[1],    p[0+j*2], p[1+j*2] );
    for ( i = 0; i < m; i++ )
    {
      v[i+j*m] =
      ( pbc * v1[i]
      + apc * v2[i]
      + abp * v3[i] )
      / abc;
    }
  }

  return v;
}    
/******************************************************************************/

double *uniform_in_triangle_map1 ( double v1[2], double v2[2], double v3[2],
  int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_IN_TRIANGLE_MAP1 maps uniform points into a triangle.

  Discussion:

    This routine uses Turk's rule 1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 August 2004

  Author:

    John Burkardt

  Reference:

    Greg Turk,
    Generating Random Points in a Triangle,
    in Graphics Gems,
    edited by Andrew Glassner,
    AP Professional, 1990, pages 24-28.

  Parameters:

    Input, double V1[2], V2[2], V3[2], the vertices.

    Input, int N, the number of points.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double UNIFORM_IN_TRIANGLE_MAP1[2*N], the points.
*/
{
  double a;
  double b;
  double c;
  int i;
  int j;
  double r[2];
  double *x;

  x = ( double * ) malloc ( 2 * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    r8vec_uniform_01 ( 2, seed, r );

    r[1] = sqrt ( r[1] );

    a = 1.0 - r[1];
    b = ( 1.0 - r[0] ) * r[1];
    c = r[0] * r[1];

    for ( i = 0; i < 2; i++ )
    {
      x[i+j*2] = a * v1[i] + b * v2[i] + c * v3[i];
    }
  }

  return x;
}
