# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# include "blend.h"

/******************************************************************************/

double blend_101 ( double r, double x0, double x1 )

/******************************************************************************/
/*
  Purpose:

    BLEND_0D1 extends scalar data at endpoints to a line.

  Diagram:

    0-----r-----1

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 October 2018

  Author:

    John Burkardt

  Parameters:

    Input, double R, the coordinate where an interpolated value is desired.

    Input, double X0, X1, the data values at the ends of the line.

    Output, double BLEND_101, the interpolated data value at (R).
*/
{
  double x;

  x = ( 1.0 - r ) * x0 + r * x1;

  return x;
}
/******************************************************************************/

double blend_102 ( double r, double s, double x00, double x01, double x10, 
  double x11 )

/******************************************************************************/
/*
  Purpose:

    BLEND_102 extends scalar point data into a square.

  Diagram:

    01------------11
     |      .      |
     |      .      |
     |.....rs......|
     |      .      |
     |      .      |
    00------------10

  Formula:

    Written in terms of R and S, the map has the form:

      X(R,S) =
               1     * ( + x00 )
             + r     * ( - x00 + x10 )
             + s     * ( - x00       + x01 )
             + r * s * ( + x00 - x10 - x01 + x11 )

    Written in terms of the coefficients, the map has the form:

      X(R,S) = x00 * ( 1 - r - s + r * s )
             + x01 * (         s - r * s )
             + x10 * (     r     - r * s )
             + x11 * (             r * s )

             = x00 * ( 1 - r ) * ( 1 - s )
             + x01 * ( 1 - r ) *       s
             + x10 *       r   * ( 1 - s )
             + x11 *       r           s

    The nonlinear term ( r * s ) has an important role:

      If ( x01 + x10 - x00 - x11 ) is zero, then the input data lies in
      a plane, and the mapping is affine.  All the interpolated data 
      will lie on the plane defined by the four corner values.  In 
      particular, on any line through the square, data values at 
      intermediate points will lie between the values at the endpoints.  

      If ( x01 + x10 - x00 - x11 ) is not zero, then the input data does
      not lie in a plane, and the interpolation map is nonlinear.  On
      any line through the square, data values at intermediate points
      may lie above or below the data values at the endpoints.  The
      size of the coefficient of r * s will determine how severe this
      effect is.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2018

  Author:

    John Burkardt

  Reference:

    William Gordon,
    Blending-Function Methods of Bivariate and Multivariate Interpolation
    and Approximation,
    SIAM Journal on Numerical Analysis,
    Volume 8, Number 1, March 1971, pages 158-177.

    William Gordon and Charles Hall,
    Transfinite Element Methods: Blending-Function Interpolation over
    Arbitrary Curved Element Domains,
    Numerische Mathematik,
    Volume 21, Number 1, 1973, pages 109-129.

    William Gordon and Charles Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, 1973, pages 461-477.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press, 1999.

  Parameters:

    Input, double  R, S, the coordinates where an 
    interpolated value is desired.  

    Input, double  X00, X01, X10, X11, the data values 
    at the corners.

    Output, double BLEND_102, the interpolated data value at (R,S).
*/
{
  double x;

  x =             + x00 
      + r *     ( - x00 + x10 ) 
      + s *     ( - x00       + x01 ) 
      + r * s * ( + x00 - x10 - x01 + x11 );

  return x;
}
/******************************************************************************/

double blend_103 ( double r, double s, double t, double x000, double x001, 
  double x010, double x011, double x100, double x101, double x110, double x111 )

/******************************************************************************/
/*
  Purpose:

    BLEND_103 extends scalar point data into a cube.

  Diagram:

    011--------------111 
      |               |
      |               | 
      |               |
      |               |
      |               |
    001--------------101


      *---------------*
      |               |
      |               |
      |      rst      |
      |               |
      |               |
      *---------------*


    010--------------110
      |               |
      |               |
      |               |
      |               | 
      |               |
    000--------------100


  Formula:

    Written as a polynomial in R, S and T, the interpolation map has the 
    form

      X(R,S,T) =
        1         * ( + x000 )
      + r         * ( - x000 + x100 )
      +     s     * ( - x000        + x010 )
      +         t * ( - x000               + x001 )
      + r * s     * ( + x000 - x100 - x010                       + x110 )
      + r     * t * ( + x000 - x100        - x001        + x101 )
      +     s * t * ( + x000        - x010 - x001 + x011 )
      + r * s * t * ( - x000 + x100 + x010 + x001 - x011 - x101 - x110 + x111 )

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2018

  Author:

    John Burkardt

  Reference:

    William Gordon,
    Blending-Function Methods of Bivariate and Multivariate Interpolation
    and Approximation,
    SIAM Journal on Numerical Analysis,
    Volume 8, Number 1, March 1971, pages 158-177.

    William Gordon and Charles Hall,
    Transfinite Element Methods: Blending-Function Interpolation over
    Arbitrary Curved Element Domains,
    Numerische Mathematik,
    Volume 21, Number 1, 1973, pages 109-129.

    William Gordon and Charles Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, 1973, pages 461-477.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press, 1999.

  Parameters:

    Input, double R, S, T, the coordinates where an 
    interpolated value is desired.

    Input, double X000, X001, X010, X011, X100, X101, X110, 
    X111, the data values at the corners.

    Output, double BLEND_103, the interpolated data value at (R,S,T).
*/
{
  double x;
/*
  Interpolate the interior point.
*/
 x =
    1.0         * ( + x000 )
    + r         * ( - x000 + x100 )
    +     s     * ( - x000        + x010 )
    +         t * ( - x000               + x001 )
    + r * s     * ( + x000 - x100 - x010                      + x110 )
    + r     * t * ( + x000 - x100        - x001        + x101 )
    +     s * t * ( + x000        - x010 - x001 + x011 )
    + r * s * t * ( - x000 + x100 + x010 + x001 - x011 - x101 - x110 + x111 );
 
  return x;
}
/******************************************************************************/

double blend_112 ( double r, double s, double x00, double x01, double x10,
  double x11, double xr0, double xr1, double x0s, double x1s )

/******************************************************************************/
/*
  Purpose:

    BLEND_112 extends scalar data along the boundary into a square.

  Diagram:

    01-----r1-----11
     |      .      |
     |      .      |
    0s.....rs.....1s
     |      .      |
     |      .      |
    00-----r0-----10

  Formula:

    Written as a polynomial in R and S, the interpolation map has the form

      X(R,S) =
           1     * ( x0s + xr0 - x00 )
         + r     * ( x00 + x1s - x0s - x10 )
         + s     * ( x00 + xr0 - x01 - xr1 )
         + r * s * ( x01 + x10 - x00 - x11 )

    The nonlinear term ( r * s ) has an important role:

    If ( x01 + x10 - x00 - x11 ) is zero, then the input data lies in a plane,
    and the mapping is affine.  All the interpolated data will lie
    on the plane defined by the four corner values.  In particular,
    on any line through the square, data values at intermediate points
    will lie between the values at the endpoints.

    If ( x01 + x10 - x00 - x11 ) is not zero, then the input data does
    not lie in a plane, and the interpolation map is nonlinear.  On
    any line through the square, data values at intermediate points
    may lie above or below the data values at the endpoints.  The
    size of the coefficient of r * s will determine how severe this
    effect is.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 October 2018

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input, double R, S, the coordinates where an interpolated value is desired.

    Input, double X00, X01, X10, X11, the data values at the corners.

    Input, double XR0, XR1, X0S, X1S, the data values at points along the edges.

    Output, double BLEND_112, the interpolated data value at (R,S).
*/
{
  double x;

   x =
     - ( 1.0 - r ) * ( 1.0 - s ) * x00
     + ( 1.0 - r )               * x0s
     - ( 1.0 - r ) *         s   * x01
     +               ( 1.0 - s ) * xr0
     +                       s   * xr1
     -         r   * ( 1.0 - s ) * x10
     +         r                 * x1s
     -         r   *         s   * x11;

  return x;
}
/******************************************************************************/

double blend_113 ( double r, double s, double t, double x000, double x001, 
  double x010, double x011, double x100, double x101, double x110, double x111, 
  double xr00, double xr01, double xr10, double xr11, double x0s0, double x0s1, 
  double x1s0, double x1s1, double x00t, double x01t, double x10t, double x11t )

/******************************************************************************/
/*
  Purpose:

    BLEND_113 extends scalar line data into a cube.

  Diagram:

     011-----r11-----111 
      |               |
      |               | 
     0s1             1s1
      |               |
      |               |
     001-----r01-----101


     01t-------------11t
      |               |
      |               |
      |      rst      |
      |               |
      |               |
     00t-------------10t


     010-----r10-----110
      |               |
      |               |
     0s0             1s0
      |               | 
      |               |
     000-----r00-----100 

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2018

  Author:

    John Burkardt

  Reference:

    William Gordon,
    Blending-Function Methods of Bivariate and Multivariate Interpolation
    and Approximation,
    SIAM Journal on Numerical Analysis,
    Volume 8, Number 1, March 1971, pages 158-177.

    William Gordon and Charles Hall,
    Transfinite Element Methods: Blending-Function Interpolation over
    Arbitrary Curved Element Domains,
    Numerische Mathematik,
    Volume 21, Number 1, 1973, pages 109-129.

    William Gordon and Charles Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, 1973, pages 461-477.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press, 1999.

  Parameters:

    Input, double R, S, T, the coordinates where an interpolated
    value is desired.

    Input, double X000, X001, X010, X011, X100, X101, X110,
    X111, the data values at the corners.

    Input, double XR00, XR01, XR10, XR11, X0S0, X0S1, X1S0, 
    X1S1, X00T, X01T, X10T, X11T, the data values at points along the edges.

    Output, double BLEND_113, the interpolated data value at (R,S,T).
*/
{
  double x;
  double xr0t;
  double xr1t;
  double xrs0;
  double xrs1;
  double x0st;
  double x1st;
/*
  Interpolate the points in the centers of the faces.
*/
  x0st = blend_112 ( s, t, x000, x001, x010, x011, x0s0, x0s1, x00t, x01t );
  x1st = blend_112 ( s, t, x100, x101, x110, x111, x1s0, x1s1, x10t, x11t );
  xr0t = blend_112 ( r, t, x000, x001, x100, x101, xr00, xr01, x00t, x10t );
  xr1t = blend_112 ( r, t, x010, x011, x110, x111, xr10, xr11, x01t, x11t );
  xrs0 = blend_112 ( r, s, x000, x010, x100, x110, xr00, xr10, x0s0, x1s0 );
  xrs1 = blend_112 ( r, s, x001, x011, x101, x111, xr01, xr11, x0s1, x1s1 );
/*
  Interpolate the I-th coordinate component of the interior point.
*/
  x = blend_123 ( r, s, t, x000, x001, x010, x011, x100, x101, x110, x111, 
    xr00, xr01, xr10, xr11, x0s0, x0s1, x1s0, x1s1, x00t, x01t, x10t, x11t, 
    x0st, x1st, xr0t, xr1t, xrs0, xrs1 );

  return x;
}
/******************************************************************************/

double blend_123 ( double r, double s, double t,
  double x000, double x001, double x010, double x011,
  double x100, double x101, double x110, double x111,
  double xr00, double xr01, double xr10, double xr11,
  double x0s0, double x0s1, double x1s0, double x1s1,
  double x00t, double x01t, double x10t, double x11t,
  double x0st, double x1st, double xr0t, double xr1t, double xrs0, double xrs1 )

/******************************************************************************/
/*
  Purpose:

    BLEND_123 extends scalar data along the surface into a cube.

  Diagram:

    010-----r10-----110    011-----r11-----111
      |       .       |      |       .       |
      |       .       |      |       .       |
    0s0.....rs0.....1s0    0s1.....rs1.....1s1     S
      |       .       |      |       .       |     |
      |       .       |      |       .       |     |
    000-----r00-----100    001-----r01-----101     +----R
       BOTTOM                      TOP

    011-----0s1-----001    111-----1s1-----101
      |       .       |      |       .       |
      |       .       |      |       .       |
    01t.....0st.....00t    11t.....1st.....10t          T
      |       .       |      |       .       |          |
      |       .       |      |       .       |          |
    010-----0s0-----000    110-----1s0-----100     S----+
       LEFT                       RIGHT

    001-----r01-----101    011-----r11-----111
      |       .       |      |       .       |
      |       .       |      |       .       |
    00t.....r0t.....100    01t.....r1t.....11t     T
      |       .       |      |       .       |     |
      |       .       |      |       .       |     |
    000-----r00-----100    010-----r10-----110     +----R
       FRONT                       BACK

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 October 2018

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input, double R, S, T, the coordinates where an interpolated value is desired.

    Input, double X000, X001, X010, X011, X100, X101, X110, X111, the data
    values at the corners.

    Input, double XR00, XR01, XR10, XR11, X0S0, X0S1, X1S0, X1S1, X00T, X01T,
    X10T, X11T, the data values at points along the edges.

    Input, double X0ST, X1ST, XR0T, XR1T, XRS0, XRS1, the data values
    at points on the faces.

    Output, double BLEND_123, the interpolated data value at (R,S,T).
*/
{
  double x;
/*
  Interpolate the interior point.
*/

 x =     ( 1.0 - r ) * ( 1.0 - s ) * ( 1.0 - t ) * x000
       - ( 1.0 - r ) * ( 1.0 - s )               * x00t
       + ( 1.0 - r ) * ( 1.0 - s ) *         t   * x001
       - ( 1.0 - r )               * ( 1.0 - t ) * x0s0
       + ( 1.0 - r )                             * x0st
       - ( 1.0 - r )               *         t   * x0s1
       + ( 1.0 - r ) *         s   * ( 1.0 - t ) * x010
       - ( 1.0 - r ) *         s                 * x01t
       + ( 1.0 - r ) *         s   *         t   * x011
       -               ( 1.0 - s ) * ( 1.0 - t ) * xr00
       +               ( 1.0 - s )               * xr0t
       -               ( 1.0 - s ) *         t   * xr01
       +                             ( 1.0 - t ) * xrs0
       +                                     t   * xrs1
       -                       s   * ( 1.0 - t ) * xr10
       +                       s                 * xr1t
       -                       s   *         t   * xr11
       +         r   * ( 1.0 - s ) * ( 1.0 - t ) * x100
       -         r   * ( 1.0 - s )               * x10t
       +         r   * ( 1.0 - s ) *         t   * x101
       -         r                 * ( 1.0 - t ) * x1s0
       +         r                               * x1st
       -         r                 *         t   * x1s1
       +         r   *         s   * ( 1.0 - t ) * x110
       -         r   *         s                 * x11t
       +         r   *         s   *         t   * x111;

  return x;
}
/******************************************************************************/

void blend_i_0d1 ( double x[], int m )

/******************************************************************************/
/*
  Purpose:

    BLEND_I_0D1 extends indexed scalar data at endpoints along a line.

  Diagram:

    ( X0, ..., ..., ..., ..., ..., X6 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input/output, double X[M].

    On input, X[0] and X[M-1] contain scalar values which are to be
    interpolated through the entries X[1] through X[M-2].  It is assumed
    that the dependence of the data is linear in the vector index I.

    On output, X[1] through X[M-2] have been assigned interpolated values.

    Input, int M, the number of entries in X.
*/
{
  int i;
  double r;

  for ( i = 1; i < m - 1; i++ )
  {
    r = ( double ) i  / ( double ) ( m - 1 );

    x[i] = blend_101 ( r, x[0], x[m-1] );

  }

  return;
}
/******************************************************************************/

void blend_ij_0d1 ( double x[], int m1, int m2 )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJ_0D1 extends indexed scalar data at corners into a table.

  Diagram:

    ( X00,  ..., ..., ..., ..., ..., X06 )
    ( ...,  ..., ..., ..., ..., ..., ... )
    ( ...,  ..., ..., ..., ..., ..., ... )
    ( ...,  ..., ..., ..., ..., ..., ... )
    ( X40,  ..., ..., ..., ..., ..., X46 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input/output, double X[M1*M2], a singly dimensioned array that
    is "really" doubly dimensioned.  The double dimension index [I][J]
    corresponds to the single dimension index I * M2 + J.

    On input, data values have been stored in the entries
    [0], [M2-1], [M1*M2-M2] and [M1*M2-1], which correspond to the double
    dimension entries [0][0], [0][M2-1], [M1-1][0] and [M1-1][M2-1].

    On output, all entries in X have been assigned a value.

    Input, int M1, M2, the number of rows and columns in the doubly
    dimensioned data.
*/
{
  int i;
  int j;
  double r;
  double s;
/*
  Interpolate values along the edges.
*/
  for ( i = 1; i < m1 - 1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );

    x[i*m2] = blend_101 ( r, x[0], x[m1*m2-m2] );

    x[i*m2+m2-1] = blend_101 ( r, x[m2-1], x[m1*m2-1] );
  }

  for ( j = 1; j < m2 - 1; j++ )
  {
    s = ( double ) j / ( double ) ( m2 - 1 );

    x[j] = blend_101 ( s, x[0], x[m2-1] );

    x[(m1-1)*m2+j] = blend_101 ( s, x[m1*m2-m2], x[m1*m2-1] );
  }
/*
  Interpolate values in the interior.
*/
  for ( i = 1; i < m1 - 1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );

    for ( j = 1; j < m2 - 1; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );

      x[i*m2+j] = blend_112 ( r, s, x[0], x[m2-1], x[m1*m2-m2], x[m1*m2-1],
        x[i*m2], x[i*m2+m2-1], x[j], x[(m1-1)*m2+j] );
    }
  }
  return;
}
/******************************************************************************/

void blend_ij_1d1 ( double x[], int m1, int m2 )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJ_1D1 extends indexed scalar data along edges into a table.

  Diagram:

    ( X00,  X01,  X02,  X03,  X04,  X05,  X06 )
    ( X10,  ...,  ...,  ...,  ...,  ...,  X16 )
    ( X20,  ...,  ...,  ...,  ...,  ...,  X26 )
    ( X30,  ...,  ...,  ...,  ...,  ...,  X36 )
    ( X40,  X41,  X42,  X43,  X44,  X45,  X46 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input/output, double X[M1*M2], a singly dimensioned array that
    is "really" doubly dimensioned.  The double dimension index [I][J]
    corresponds to the single dimension index I * M2 + J.

    On input, data is contained in the "edge entries"
    X[0][J], X[I][0], X[M1-1][J] and X[I][M2-1],
    for I = 0 to M1-1, and J = 0 to M2-1.

    On output, all entries in X have been assigned a value.

    Input, int M1, M2, the number of rows and columns in X.
*/
{
  int i;
  int j;
  double r;
  double s;
/*
  Interpolate values in the interior.
*/

  for ( i = 1; i < m1 - 1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );

    for ( j = 1; j < m2 - 1; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );

      x[i*m2+j] = blend_112 ( r, s, x[0], x[m2-1], x[m1*m2-m2], x[m1*m2-1],
        x[i*m2], x[i*m2+m2-1], x[j], x[(m1-1)*m2+j] );
    }
  }
  return;
}
/******************************************************************************/

void blend_ij_w_1d1 ( double x[], double r[], double s[], int m1, int m2 )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJ_W_1D1 extends weighted indexed scalar data along edges into a table.

  Diagram:

    Instead of assuming that the data in the table is equally spaced,
    the arrays R and S are supplied, which should behave as
    "coordinates" for the data.

            S(1)  S(2)  S(3)  S(4)  S(5)  S(6)  S(M2)
      
    R(1)  ( X11,  X12,  X13,  X14,  X15,  X16,  X1M2  )
    R(2)  ( X21,  ...,  ...,  ...,  ...,  ...,  X2M2  )
    R(3)  ( X31,  ...,  ...,  ...,  ...,  ...,  X3M2  )
    R(4)  ( X41,  ...,  ...,  ...,  ...,  ...,  X4M2  )
    R(M1) ( XM11, XM12, XM13, XM14, XM15, XM16, XM1M2 )

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 October 2018

  Author:

    John Burkardt

  Reference:

    William Gordon,
    Blending-Function Methods of Bivariate and Multivariate Interpolation
    and Approximation,
    SIAM Journal on Numerical Analysis,
    Volume 8, Number 1, March 1971, pages 158-177.

    William Gordon and Charles Hall,
    Transfinite Element Methods: Blending-Function Interpolation over
    Arbitrary Curved Element Domains,
    Numerische Mathematik,
    Volume 21, Number 1, 1973, pages 109-129.

    William Gordon and Charles Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, 1973, pages 461-477.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press, 1999.

  Parameters:

    Input/output, double X[M1*M2].  
    On input, data is contained in the "edge entries" X(1,J), X(I,1), 
    X(M1,J) and X(I,M2), for I = 1 to M1, and J = 1 to M2.
    On output, all entries in X have been assigned a value.

    Input, double R[M1], S[M2], are "coordinates" for the rows and
    columns of the array.  The values in R, and the values in S, should 
    be strictly increasing or decreasing.

    Input, int M1, M2, the number of rows and columns in X.
*/
{
  int i;
  int j;
  double rr;
  double ss;
/*
  Interpolate values in the interior.
*/
  for ( i = 1; i < m1 - 1; i++ )
  {
    rr = ( r[i] - r[0] ) / ( r[m1-1] - r[0] );

    for ( j = 1; j < m2 - 1; j++ )
    {
      ss = ( s[j] - s[0] ) / ( s[m2-1] - s[0] );

      x[i*m2+j] = blend_112 ( rr, ss, x[0], x[m2-1], x[m1*m2-m2], x[m1*m2-1],
        x[i*m2], x[i*m2+m2-1], x[j], x[(m1-1)*m2+j] );
    }
  }

  return;
}
/******************************************************************************/

void blend_ijk_0d1 ( double x[], int m1, int m2, int m3 )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJK_0D1 extends indexed scalar data along corners into a cubic table.

  Diagram:

    ( X000,   ...,  ...,  ...,  ...,  ...,  X060 )
    ( ....,   ...,  ...,  ...,  ...,  ...,  ...  )
    ( ....,   ...,  ...,  ...,  ...,  ...,  ...  )   First "layer"
    ( ....,   ...,  ...,  ...,  ...,  ...,  ...  )
    ( X400,   ...,  ...,  ...,  ...,  ...,  X460 )

    ( ....,   ...,  ...,  ...,  ...,  ...,  ...  )
    ( ....,   ...,  ...,  ...,  ...,  ...,  ...  )
    ( ....,   ...,  ...,  ...,  ...,  ...,  ...  )   Middle "layers"
    ( ....,   ...,  ...,  ...,  ...,  ...,  ...  )
    ( ....,   ...,  ...,  ...,  ...,  ...,  ...  )

    ( X003,  ...,  ...,  ...,  ...,  ...,  X063  )
    ( ....,   ...,  ...,  ...,  ...,  ...,  ...  )
    ( ....,   ...,  ...,  ...,  ...,  ...,  ...  )   Last "layer"
    ( ....,   ...,  ...,  ...,  ...,  ...,  ...  )
    ( X403,  ...,  ...,  ...,  ...,  ...,  X463  )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input/output, double X[M1*M2*M3], a singly dimensioned array that
    is "really" triply dimensioned.  The triple dimension index
    [I][J][K] corresponds to the single dimension index
    I * M2*M3 + J * M2 + K

    On input, there is already scalar data in the entries X[I][J][K]
    corresponding to "cornders" of the table, that is, entries for which
    each of the three indices I, J and K is equal to their
    minimum or maximum possible values.

    Input, int M1, M2, M3, the number of rows, columns, and layers in X.
*/
{
  int i;
  int j;
  int k;
  double r;
  double s;
  double t;
/*
  Interpolate values along the "edges", that is, index triplets (i,j,k)
  with exactly two of I, J, K an "extreme" value.
*/
  for ( i = 1; i < m1 - 1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );
    x[i*m3*m2] = blend_101 ( r, x[0],              x[(m1-1)*m3*m2] );

    x[(i*m3+m2-1)*m2] = blend_101 ( r, x[(m2-1)*m2],      x[((m1-1)*m3+m2-1)*m2] );

    x[i*m3*m2+m3-1] = blend_101 ( r, x[m3-1],           x[(m1-1)*m3*m2+m3-1] );

    x[(i*m3+m2-1)*m2+m3-1] = blend_101 ( r, x[(m2-1)*m2+m3-1],
      x[((m1-1)*m3+m2-1)*m2+m3-1] );
  }

  for ( j = 1; j < m2 - 1; j++ )
  {
    s = ( double ) j / ( double ) ( m2 - 1 );
    x[j*m2] = blend_101 ( s, x[0], x[(m2-1)*m2] );

    x[((m1-1)*m3+j)*m2] = blend_101 ( s, x[(m1-1)*m3*m2], x[((m1-1)*m3+m2-1)*m2] );

    x[j*m2+m3-1] = blend_101 ( s, x[m3-1], x[(m2-1)*m2+m3-1] );

    x[((m1-1)*m3+j)*m2+m3-1] = blend_101 ( s, x[(m1-1)*m3*m2+m3-1],
      x[((m1-1)*m3+m2-1)*m2+m3-1] );
  }

  for ( k = 1; k < m3 - 1; k++ )
  {
    t = ( double ) k / ( double ) ( m3 - 1 );
    x[k] = blend_101 ( t, x[0], x[m3-1] );

    x[(m1-1)*m3*m2+k] = blend_101 ( t, x[(m1-1)*m3*m2], x[(m1-1)*m3*m2+m3-1] );

    x[(m2-1)*m2+k] = blend_101 ( t, x[(m2-1)*m2], x[(m2-1)*m2+m3-1] );

    x[((m1-1)*m3+m2-1)*m2+k] = blend_101 ( t, x[((m1-1)*m3+m2-1)*m2],
      x[((m1-1)*m3+m2-1)*m2+m3-1] );
  }
/*
  Interpolate values along the "faces", that is, index triplets (i,j,k)
  with exactly one of I, J, K is an "extreme" value.
*/
  for ( j = 1; j < m2 - 1; j++ )
  {
    s = ( double ) j / ( double ) ( m2 - 1 );
    for ( k = 1; k < m3 - 1; k++ )
    {
      t = ( double ) k / ( double ) ( m3 - 1 );

      x[j*m2+k] = blend_112 ( s, t,
        x[0],                   x[m3-1],
        x[(m2-1)*m2],           x[(m2-1)*m2+m3-1],
        x[j*m2],                x[j*m2+m3-1],
        x[k],                   x[(m2-1)*m2+k] );

      x[((m1-1)*m3+j)*m2+k] = blend_112 ( s, t,
        x[(m1-1)*m3*m2],        x[(m1-1)*m3*m2+m3-1],
        x[((m1-1)*m3+m2-1)*m2], x[((m1-1)*m3+m2-1)*m2+m3-1],
        x[((m1-1)*m3+j)*m2],    x[((m1-1)*m3+j)*m2+m3-1],
        x[(m1-1)*m3*m2+k],      x[((m1-1)*m3+m2-1)*m2+k] );
    }
  }

  for ( i = 1; i < m1 - 1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );
    for ( k = 1; k < m3 - 1; k++ )
    {
      t = ( double ) k / ( double ) ( m3 - 1 );

      x[i*m3*m2+k]  = blend_112 ( r, t,
        x[0],                   x[m3-1],
        x[(m1-1)*m3*m2],        x[(m1-1)*m3*m2+m3-1],
        x[i*m3*m2],             x[i*m3*m2+m3-1],
        x[k],                   x[(m1-1)*m3*m2+k] );

      x[(i*m3+m2-1)*m2+k] = blend_112 ( r, t,
        x[(m2-1)*m2],           x[(m2-1)*m2+m3-1],
        x[((m1-1)*m3+m2-1)*m2], x[((m1-1)*m3+m2-1)*m2+m3-1],
        x[(i*m3+m2-1)*m2],      x[(i*m3+m2-1)*m2+m3-1],
        x[(m2-1)*m2+k],         x[((m1-1)*m3+m2-1)*m2+k] );
    }
  }

  for ( i = 1; i < m1 - 1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );
    for ( j = 1; j < m2 - 1; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );

      x[(i*m3+j)*m2] = blend_112 ( r, s,
        x[0],            x[(m2-1)*m2],
        x[(m1-1)*m3*m2], x[((m1-1)*m3+m2-1)*m2],
        x[i*m3*m2],      x[(i*m3+m2-1)*m2],
        x[j*m2],         x[((m1-1)*m3+j)*m2] );

      x[(i*m3+j)*m2+m3-1] = blend_112 ( r, s,
       x[m3-1],              x[(m2-1)*m2+m3-1],
       x[(m1-1)*m3*m2+m3-1], x[((m1-1)*m3+m2-1)*m2+m3-1],
       x[i*m3*m2+m3-1],      x[(i*m3+m2-1)*m2+m3-1],
       x[j*m2+m3-1],         x[((m1-1)*m3+j)*m2+m3-1] );
    }
  }
/*
  Interpolate values in the interior.
*/
  for ( i = 1; i < m1 - 1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );

    for ( j = 1; j < m2 - 1; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );

      for ( k = 1; k < m3 - 1; k++ )
      {
        t = ( double ) k / ( double ) ( m3 - 1 );

        x[(i*m3+j)*m2+k] = blend_123 ( r, s, t,
          x[0],                    x[m3-1],
          x[(m2-1)*m2],            x[(m2-1)*m2+m3-1],
          x[(m1-1)*m3*m2],         x[(m1-1)*m3*m2+m3-1],
          x[((m1-1)*m3+m2-1)*m2],  x[((m1-1)*m3+m2-1)*m2+m3-1],
          x[i*m3*m2],              x[i*m3*m2+m3-1],
          x[(i*m3+m2-1)*m2],       x[(i*m3+m2-1)*m2+m3-1],
          x[j*m2],                 x[j*m2+m3-1],
          x[((m1-1)*m3+j)*m2],     x[((m1-1)*m3+j)*m2+m3-1],
          x[k],                    x[(m2-1)*m2+k],
          x[(m1-1)*m3*m2+k],       x[((m1-1)*m3+m2-1)*m2+k],
          x[j*m3+k],               x[((m1-1)*m3+j)*m2+k],
          x[i*m3*m2+k],            x[(i*m3+m2-1)*m2+k],
          x[(i*m3+j)*m2],          x[(i*m3+j)*m2+m3-1] );
      }
    }
  }
  return;
}
/******************************************************************************/

void blend_ijk_1d1 ( double x[], int m1, int m2, int m3 )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJK_1D1 extends indexed scalar data along "edges" into a cubic table.

  Diagram:

    ( X000,   X010,   X020,   X030,   X040,   X050 )
    ( X100,   ...,    ...,    ...,    ...,    X150 )
    ( X200,   ...,    ...,    ...,    ...,    X250 )   Layer 1
    ( X300,   ...,    ...,    ...,    ...,    X350 )
    ( X400,   X410,   X420,   X430,   X440,   X450 )

    ( X001,   ...,    ...,    ...,    ...,    X051 )
    ( ....,   ...,    ...,    ...,    ...,    ...  )
    ( ....,   ...,    ...,    ...,    ...,    ...  )   Layer K
    ( ....,   ...,    ...,    ...,    ...,    ...  )   1 < K < M3
    ( X401,   ...,    ...,    ...,    ...,    X451 )

    ( X002,   X012,   X022,   X032,   X042,   X052 )
    ( X102,   ...,    ...,    ...,    ...,    X152 )
    ( X202,   ...,    ...,    ...,    ...,    X252 )   Layer M3
    ( X302    ...,    ...,    ...,    ...,    X352 )
    ( X402,   X412,   X422,   X432,   X442,   X452 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input/output, double X[M1*M2*M3], a singly dimensioned array that
    is "really" triply dimensioned.  The triple dimension index
    [I][J][K] corresponds to the single dimension index
    I * M2*M3 + J * M2 + K

    On input, there is already scalar data in the entries X[I][J][K]
    corresponding to "edges" of the table, that is, entries for which
    at least two of the three indices I, J and K are equal to their
    minimum or maximum possible values.

    Input, int M1, M2, M3, the number of rows, columns, and layers in X.
*/
{
  int i;
  int j;
  int k;
  double r;
  double s;
  double t;
/*
  Interpolate values along the "faces", that is, index triplets (i,j,k)
  with exactly one of I, J, K is an "extreme" value.
*/
  for ( j = 1; j < m2 - 1; j++ )
  {
    s = ( double ) j / ( double ) ( m2 - 1 );
    for ( k = 1; k < m3 - 1; k++ )
    {
      t = ( double ) k / ( double ) ( m3 - 1 );

      x[j*m2+k] = blend_112 ( s, t,
        x[0],                   x[m3-1],
        x[(m2-1)*m2],           x[(m2-1)*m2+m3-1],
        x[j*m2],                x[j*m2+m3-1],
        x[k],                   x[(m2-1)*m2+k] );

      x[((m1-1)*m3+j)*m2+k] = blend_112 ( s, t,
        x[(m1-1)*m3*m2],        x[(m1-1)*m3*m2+m3-1],
        x[((m1-1)*m3+m2-1)*m2], x[((m1-1)*m3+m2-1)*m2+m3-1],
        x[((m1-1)*m3+j)*m2],    x[((m1-1)*m3+j)*m2+m3-1],
        x[(m1-1)*m3*m2+k],      x[((m1-1)*m3+m2-1)*m2+k] );
    }
  }

  for ( i = 1; i < m1 - 1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );
    for ( k = 1; k < m3 - 1; k++ )
    {
      t = ( double ) k / ( double ) ( m3 - 1 );

      x[i*m3*m2+k] = blend_112 ( r, t,
        x[0],                   x[m3-1],
        x[(m1-1)*m3*m2],        x[(m1-1)*m3*m2+m3-1],
        x[i*m3*m2],             x[i*m3*m2+m3-1],
        x[k],                   x[(m1-1)*m3*m2+k] );

      x[(i*m3+m2-1)*m2+k] = blend_112 ( r, t,
        x[(m2-1)*m2],           x[(m2-1)*m2+m3-1],
        x[((m1-1)*m3+m2-1)*m2], x[((m1-1)*m3+m2-1)*m2+m3-1],
        x[(i*m3+m2-1)*m2],      x[(i*m3+m2-1)*m2+m3-1],
        x[(m2-1)*m2+k],         x[((m1-1)*m3+m2-1)*m2+k] );
    }
  }

  for ( i = 1; i < m1 - 1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );
    for ( j = 1; j < m2 - 1; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );

      x[(i*m3+j)*m2] = blend_112 ( r, s,
        x[0],            x[(m2-1)*m2],
        x[(m1-1)*m3*m2], x[((m1-1)*m3+m2-1)*m2],
        x[i*m3*m2],      x[(i*m3+m2-1)*m2],
        x[j*m2],         x[((m1-1)*m3+j)*m2] );

      x[(i*m3+j)*m2+m3-1] = blend_112 ( r, s,
       x[m3-1],              x[(m2-1)*m2+m3-1],
       x[(m1-1)*m3*m2+m3-1], x[((m1-1)*m3+m2-1)*m2+m3-1],
       x[i*m3*m2+m3-1],      x[(i*m3+m2-1)*m2+m3-1],
       x[j*m2+m3-1],         x[((m1-1)*m3+j)*m2+m3-1] );
    }
  }
/*
  Interpolate values in the interior.
*/
  for ( i = 1; i < m1 - 1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );

    for ( j = 1; j < m2 - 1; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );

      for ( k = 1; k < m3 - 1; k++ )
      {
        t = ( double ) k / ( double ) ( m3 - 1 );

        x[(i*m3+j)*m2+k] = blend_123 ( r, s, t,
          x[0],                    x[m3-1],
          x[(m2-1)*m2],            x[(m2-1)*m2+m3-1],
          x[(m1-1)*m3*m2],         x[(m1-1)*m3*m2+m3-1],
          x[((m1-1)*m3+m2-1)*m2],  x[((m1-1)*m3+m2-1)*m2+m3-1],
          x[i*m3*m2],              x[i*m3*m2+m3-1],
          x[(i*m3+m2-1)*m2],       x[(i*m3+m2-1)*m2+m3-1],
          x[j*m2],                 x[j*m2+m3-1],
          x[((m1-1)*m3+j)*m2],     x[((m1-1)*m3+j)*m2+m3-1],
          x[k],                    x[(m2-1)*m2+k],
          x[(m1-1)*m3*m2+k],       x[((m1-1)*m3+m2-1)*m2+k],
          x[j*m3+k],               x[((m1-1)*m3+j)*m2+k],
          x[i*m3*m2+k],            x[(i*m3+m2-1)*m2+k],
          x[(i*m3+j)*m2],          x[(i*m3+j)*m2+m3-1] );
      }
    }
  }
  return;
}
/******************************************************************************/

void blend_ijk_2d1 ( double x[], int m1, int m2, int m3 )

/******************************************************************************/
/*
  Purpose:

    BLEND_IJK_2D1 extends indexed scalar data along faces into a cubic table.

  Diagram:

    ( X000    X010    X020    X030    X040    X050 )
    ( X100    X110    X120    X130    X140    X150 )
    ( X200    X210    X220    X230    X240    X250 )   Layer 1
    ( X300    X310    X320    X330    X340    X350 )
    ( X400    X410    X420    X430    X440    X450 )

    ( X001    X011    X021    X031    X041    X051 )
    ( X101    ...     ....    ....    ....    X151 )
    ( X201    ...     ....    ....    ....    X251 )   Layer K
    ( X301    ...     ....    ....    ....    X351 )   1 < K < M3
    ( X401    X411    X421    X431    X441    X451 )

    ( X002    X012    X022    X032    X042    X052 )
    ( X102    X112    X122    X132    X142    X152 )
    ( X202    X212    X222    X232    X242    X252 )   Layer M3
    ( X302    X312    X322    X332    X342    X352 )
    ( X402    X412    X422    X432    X442    X452 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input/output, double X[M1*M2*M3], a singly dimensioned array that
    is "really" triply dimensioned.  The triple dimension index
    [I][J][K] corresponds to the single dimension index
    I * M2*M3 + J * M2 + K

    On input, there is already scalar data in the entries X[I][J][K]
    corresponding to "faces" of the table, that is, entries for which
    at least one of the three indices I, J and K is equal to their
    minimum or maximum possible values.

    On output, all entries in X have been assigned a value, using the
    table indices as independent variables.

    Input, int M1, M2, M3, the number of rows, columns, and layers in X.
*/
{
  int i;
  int j;
  int k;
  double r;
  double s;
  double t;
/*
  Interpolate values in the interior.
*/
  for ( i = 1; i < m1 - 1; i++ )
  {
    r = ( double ) i / ( double ) ( m1 - 1 );

    for ( j = 1; j < m2 - 1; j++ )
    {
      s = ( double ) j / ( double ) ( m2 - 1 );

      for ( k = 1; k < m3 - 1; k++ )
      {
        t = ( double ) k / ( double ) ( m3 - 1 );

        x[(i*m3+j)*m2+k] = blend_123 ( r, s, t,
          x[0],                    x[m3-1],
          x[(m2-1)*m2],            x[(m2-1)*m2+m3-1],
          x[(m1-1)*m3*m2],         x[(m1-1)*m3*m2+m3-1],
          x[((m1-1)*m3+m2-1)*m2],  x[((m1-1)*m3+m2-1)*m2+m3-1],
          x[i*m3*m2],              x[i*m3*m2+m3-1],
          x[(i*m3+m2-1)*m2],       x[(i*m3+m2-1)*m2+m3-1],
          x[j*m2],                 x[j*m2+m3-1],
          x[((m1-1)*m3+j)*m2],     x[((m1-1)*m3+j)*m2+m3-1],
          x[k],                    x[(m2-1)*m2+k],
          x[(m1-1)*m3*m2+k],       x[((m1-1)*m3+m2-1)*m2+k],
          x[j*m3+k],               x[((m1-1)*m3+j)*m2+k],
          x[i*m3*m2+k],            x[(i*m3+m2-1)*m2+k],
          x[(i*m3+j)*m2],          x[(i*m3+j)*m2+m3-1] );
      }
    }
  }

  return;
}
/******************************************************************************/

void blend_r_0dn ( double r, double x[], int n,
  double ( *bound_r ) ( double r, int i ) )

/******************************************************************************/
/*
  Purpose:

    BLEND_R_0DN extends vector data at endpoints into a line.

  Diagram:

    0-----r-----1

  Discussion:

    This is simply linear interpolation.  BLEND_R_0DN is provided
    mainly as a "base routine" which can be compared to its generalizations,
    such as BLEND_RS_0DN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input, double R, the (R) coordinate of the point to be evaluated.

    Output, double X[N], the interpolated value at the point (R).

    Input, int N, the dimension of the vector space.

    Input, double ( * BOUND_R ) ( double r, double i), is a function which 
    is given (R) coordinates and an component value I, and returns the value 
    of the I-th component of the N-vector at that point.  BOUND_R will only be 
    called for "corners", that is, for values (R) where R is either 0.0
    or 1.0.  
*/
{
  int i;
  double x0;
  double x1;

  for ( i = 0; i < n; i++ )
  {
/*
  Get the I-th coordinate component at the two corners.
*/
    x0 = bound_r ( 0.0, i );
    x1 = bound_r ( 1.0, i );
/*
  Interpolate the I-th coordinate component of the interior point.
*/
    x[i] = blend_101 ( r, x0, x1 );
  }

  return;
}
/******************************************************************************/

void blend_rs_0dn ( double r, double s, double x[], int n,
  double ( *bound_rs ) ( double r, double s, int i ) )

/******************************************************************************/
/*
  Purpose:

    BLEND_RS_0DN extends vector data at corners into a square.

  Diagram:

    01-----r1-----11
     |      .      |
     |      .      |
    0s.....rs.....1s
     |      .      |
     |      .      |
    00-----r0-----10

  Discussion:

    BLEND_RS_0DN should be equivalent to the use of a bilinear finite
    element method.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input, double R, S, the (R,S) coordinates of the point to be evaluated.

    Output, double X[N], the interpolated value at the point (R,S).

    Input, int N, the dimension of the vector space.

    External, BOUND_RS, is a function which is given (R,S) coordinates
    and an component value I, and returns XI, the value of the I-th component
    of the N-vector at that point.  BOUND_RS will only be called for
    "corners", that is, for values (R,S) where R and S are either 0.0
    or 1.0.  BOUND_RS has the form:

      void bound_rs ( double r, double s, int i, double *xi )
*/
{
  int i;
  double x00;
  double x01;
  double x10;
  double x11;
  double xr0;
  double xr1;
  double x0s;
  double x1s;

  for ( i = 0; i < n; i++ )
  {
/*
  Get the I-th coordinate component at the four corners.
*/
    x00 = bound_rs ( 0.0, 0.0, i );
    x01 = bound_rs ( 0.0, 1.0, i );
    x10 = bound_rs ( 1.0, 0.0, i );
    x11 = bound_rs ( 1.0, 1.0, i );
/*
  Interpolate the I-th coordinate component at the sides.
*/
    xr0 = blend_101 ( r, x00, x10 );
    xr1 = blend_101 ( r, x01, x11 );
    x0s = blend_101 ( s, x00, x01 );
    x1s = blend_101 ( s, x10, x11 );
/*
  Interpolate the I-th coordinate component of the interior point.
*/
    x[i] = blend_112 ( r, s, x00, x01, x10, x11, xr0, xr1, x0s, x1s );
  }

  return;
}
/******************************************************************************/

void blend_rs_1dn ( double r, double s, double x[], int n,
  double ( *bound_rs ) ( double r, double s, int i ) )

/******************************************************************************/
/*
  Purpose:

    BLEND_RS_1DN extends vector data along sides into a square.

  Diagram:

    01-----r1-----11
     |      .      |
     |      .      |
    0s.....rs.....1s
     |      .      |
     |      .      |
    00-----r0-----10

  Discussion:

    BLEND_RS_1DN is NOT equivalent to a bilinear finite element method,
    since the data is sampled everywhere along the boundary lines,
    rather than at a finite number of nodes.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input, double R, S, the (R,S) coordinates of the point to be evaluated.

    Output, double X[N], the interpolated value at the point (R,S).

    Input, int N, the dimension of the vector space.

    External, BOUND_RS, is a function which is given (R,S) coordinates
    and an component value I, and returns XI, the value of the I-th component
    of the N-vector at that point.  BOUND_RS will only be called for
    "sides", that is, for values (R,S) where at least one of R and S is
    either 0.0 or 1.0.  BOUND_RS has the form:

      void bound_rs ( double r, double s, int i, double *xi )
*/
{
  int i;
  double x00;
  double x01;
  double x10;
  double x11;
  double xr0;
  double xr1;
  double x0s;
  double x1s;

  for ( i = 0; i < n; i++ )
  {
/*
  Get the I-th coordinate component at the four corners.
*/
    x00 = bound_rs ( 0.0, 0.0, i );
    x01 = bound_rs ( 0.0, 1.0, i );
    x10 = bound_rs ( 1.0, 0.0, i );
    x11 = bound_rs ( 1.0, 1.0, i );
/*
  Get the I-th coordinate component at the sides.
*/
    xr0 = bound_rs ( r, 0.0, i );
    xr1 = bound_rs ( r, 1.0, i );
    x0s = bound_rs ( 0.0, s, i );
    x1s = bound_rs ( 1.0, s, i );
/*
  Interpolate the I-th coordinate component of the interior point.
*/
    x[i] = blend_112 ( r, s, x00, x01, x10, x11, xr0, xr1, x0s, x1s );
  }

  return;
}
/******************************************************************************/

void blend_rst_0dn ( double r, double s, double t, double x[], int n,
  double ( *bound_rst ) ( double r, double s, double t, int i ) )

/******************************************************************************/
/*
  Purpose:

    BLEND_RST_0DN extends vector data at corners into a cube.

  Diagram:

    010-----r10-----110    011-----r11-----111
      |       .       |      |       .       |
      |       .       |      |       .       |
    0s0.....rs0.....1s0    0s1.....rs1.....1s1     S
      |       .       |      |       .       |     |
      |       .       |      |       .       |     |
    000-----r00-----100    001-----r01-----101     +----R
       BOTTOM                      TOP

    011-----0s1-----001    111-----1s1-----101
      |       .       |      |       .       |
      |       .       |      |       .       |
    01t.....0st.....00t    11t.....1st.....10t          T
      |       .       |      |       .       |          |
      |       .       |      |       .       |          |
    010-----0s0-----000    110-----1s0-----100     S----+
       LEFT                       RIGHT

    001-----r01-----101    011-----r11-----111
      |       .       |      |       .       |
      |       .       |      |       .       |
    00t.....r0t.....100    01t.....r1t.....11t     T
      |       .       |      |       .       |     |
      |       .       |      |       .       |     |
    000-----r00-----100    010-----r10-----110     +----R
       FRONT                       BACK

  Discussion:

    BLEND_RST_0DN is equivalent to a trilinear finite element method.
    Data along the edges, faces, and interior of the cube is interpolated
    from the data at the corners.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input, double R, S, T, the (R,S,T) coordinates of the point to be evaluated.

    Output, double X[N], the interpolated value at the point (R,S,T).

    Input, int N, the dimension of the vector space.

    Input, double * bound_rst ( r, s, t, i ), a function given (R,S,T) coordinates
    and an component value I, and returns XI, the value of the I-th component
    of the N-vector at that point.  BOUND_RST will only be called for
    "corners", that is, for values (R,S,T) where R, S and T are either 0.0
    or 1.0.
*/
{
  int i;
  double x000;
  double x001;
  double x010;
  double x011;
  double x100;
  double x101;
  double x110;
  double x111;
  double xr00;
  double xr01;
  double xr10;
  double xr11;
  double x0s0;
  double x0s1;
  double x1s0;
  double x1s1;
  double x00t;
  double x01t;
  double x10t;
  double x11t;
  double x0st;
  double x1st;
  double xr0t;
  double xr1t;
  double xrs0;
  double xrs1;

  for ( i = 0; i < n; i++ )
  {
/*
  Get the I-th coordinate component at the corners.
*/
    x000 = bound_rst ( 0.0, 0.0, 0.0, i );
    x001 = bound_rst ( 0.0, 0.0, 1.0, i );
    x010 = bound_rst ( 0.0, 1.0, 0.0, i );
    x011 = bound_rst ( 0.0, 1.0, 1.0, i );
    x100 = bound_rst ( 1.0, 0.0, 0.0, i );
    x101 = bound_rst ( 1.0, 0.0, 1.0, i );
    x110 = bound_rst ( 1.0, 1.0, 0.0, i );
    x111 = bound_rst ( 1.0, 1.0, 1.0, i );
/*
  Interpolate the I-th coordinate component at the edges.
*/
    xr00 = blend_101 ( r, x000, x100 );
    xr01 = blend_101 ( r, x001, x101 );
    xr10 = blend_101 ( r, x010, x110 );
    xr11 = blend_101 ( r, x011, x111 );

    x0s0 = blend_101 ( s, x000, x010 );
    x0s1 = blend_101 ( s, x001, x011 );
    x1s0 = blend_101 ( s, x100, x110 );
    x1s1 = blend_101 ( s, x101, x111 );

    x00t = blend_101 ( t, x000, x001 );
    x01t = blend_101 ( t, x010, x011 );
    x10t = blend_101 ( t, x100, x101 );
    x11t = blend_101 ( t, x110, x111 );
/*
  Interpolate the I-th component on the faces.
*/
    x0st = blend_112 ( s, t, x000, x001, x010, x011, x0s0, x0s1, x00t, x01t );

    x1st = blend_112 ( s, t, x100, x101, x110, x111, x1s0, x1s1, x10t, x11t );

    xr0t = blend_112 ( r, t, x000, x001, x100, x101, xr00, xr01, x00t, x10t );

    xr1t = blend_112 ( r, t, x010, x011, x110, x111, xr10, xr11, x01t, x11t );

    xrs0 = blend_112 ( r, s, x000, x010, x100, x110, xr00, xr10, x0s0, x1s0 );

    xrs1 = blend_112 ( r, s, x001, x011, x101, x111, xr01, xr11, x0s1, x1s1 );
/*
  Interpolate the I-th coordinate component of the interior point.
*/
    x[i] = blend_123 ( r, s, t, x000, x001, x010, x011, x100, x101,
      x110, x111, xr00, xr01, xr10, xr11, x0s0, x0s1, x1s0, x1s1,
      x00t, x01t, x10t, x11t, x0st, x1st, xr0t, xr1t, xrs0, xrs1 );
  }

  return;
}
/******************************************************************************/

void blend_rst_1dn ( double r, double s, double t, double x[], int n,
  double ( *bound_rst ) ( double r, double s, double t, int i ) )

/******************************************************************************/
/*
  Purpose:

    BLEND_RST_1DN extends vector data on edges into a cube.

  Diagram:

    010-----r10-----110    011-----r11-----111
      |       .       |      |       .       |
      |       .       |      |       .       |
    0s0.....rs0.....1s0    0s1.....rs1.....1s1     S
      |       .       |      |       .       |     |
      |       .       |      |       .       |     |
    000-----r00-----100    001-----r01-----101     +----R
       BOTTOM                      TOP

    011-----0s1-----001    111-----1s1-----101
      |       .       |      |       .       |
      |       .       |      |       .       |
    01t.....0st.....00t    11t.....1st.....10t          T
      |       .       |      |       .       |          |
      |       .       |      |       .       |          |
    010-----0s0-----000    110-----1s0-----100     S----+
       LEFT                       RIGHT

    001-----r01-----101    011-----r11-----111
      |       .       |      |       .       |
      |       .       |      |       .       |
    00t.....r0t.....100    01t.....r1t.....11t     T
      |       .       |      |       .       |     |
      |       .       |      |       .       |     |
    000-----r00-----100    010-----r10-----110     +----R
       FRONT                       BACK

  Discussion:

    BLEND_RST_1D is NOT equivalent to a trilinear finite element method,
    since the data is sampled everywhere along the corners and edges,
    rather than at a finite number of nodes.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input, double R, S, T, the (R,S,T) coordinates of the point to be evaluated.

    Output, double X(N), the interpolated value at the point (R,S,T).

    Input, int N, the dimension of the vector space.

    Input, double * bound_rst ( r, s, t, i ), a function given (R,S,T) coordinates
    and an component value I, and returns XI, the value of the I-th component
    of the N-vector at that point.  BOUND_RST will only be called for
    "edges", that is, for values (R,S,T) where at least two of R, S and T
    are either 0.0 or 1.0.
*/
{
  int i;
  double x000;
  double x001;
  double x010;
  double x011;
  double x100;
  double x101;
  double x110;
  double x111;
  double xr00;
  double xr01;
  double xr10;
  double xr11;
  double x0s0;
  double x0s1;
  double x1s0;
  double x1s1;
  double x00t;
  double x01t;
  double x10t;
  double x11t;
  double x0st;
  double x1st;
  double xr0t;
  double xr1t;
  double xrs0;
  double xrs1;

  for ( i = 0; i < n; i++ )
  {
/*
  Get the I-th coordinate component at the corners.
*/
    x000 = bound_rst ( 0.0, 0.0, 0.0, i );
    x001 = bound_rst ( 0.0, 0.0, 1.0, i );
    x010 = bound_rst ( 0.0, 1.0, 0.0, i );
    x011 = bound_rst ( 0.0, 1.0, 1.0, i );
    x100 = bound_rst ( 1.0, 0.0, 0.0, i );
    x101 = bound_rst ( 1.0, 0.0, 1.0, i );
    x110 = bound_rst ( 1.0, 1.0, 0.0, i );
    x111 = bound_rst ( 1.0, 1.0, 1.0, i );
/*
  Get the I-th coordinate component at the edges.
*/
    xr00 = bound_rst ( r, 0.0, 0.0, i );
    xr01 = bound_rst ( r, 0.0, 1.0, i );
    xr10 = bound_rst ( r, 1.0, 0.0, i );
    xr11 = bound_rst ( r, 1.0, 1.0, i );

    x0s0 = bound_rst ( 0.0, s, 0.0, i );
    x0s1 = bound_rst ( 0.0, s, 1.0, i );
    x1s0 = bound_rst ( 1.0, s, 0.0, i );
    x1s1 = bound_rst ( 1.0, s, 1.0, i );

    x00t = bound_rst ( 0.0, 0.0, t, i );
    x01t = bound_rst ( 0.0, 1.0, t, i );
    x10t = bound_rst ( 1.0, 0.0, t, i );
    x11t = bound_rst ( 1.0, 1.0, t, i );
/*
  Interpolate the I-th component on the faces.
*/
    x0st = blend_112 ( s, t, x000, x001, x010, x011, x0s0, x0s1, x00t, x01t );

    x1st = blend_112 ( s, t, x100, x101, x110, x111, x1s0, x1s1, x10t, x11t );

    xr0t = blend_112 ( r, t, x000, x001, x100, x101, xr00, xr01, x00t, x10t );

    xr1t = blend_112 ( r, t, x010, x011, x110, x111, xr10, xr11, x01t, x11t );

    xrs0 = blend_112 ( r, s, x000, x010, x100, x110, xr00, xr10, x0s0, x1s0 );

    xrs1 = blend_112 ( r, s, x001, x011, x101, x111, xr01, xr11, x0s1, x1s1 );
/*
  Interpolate the I-th coordinate component of the interior point.
*/
    x[i] = blend_123 ( r, s, t, x000, x001, x010, x011, x100, x101,
      x110, x111, xr00, xr01, xr10, xr11, x0s0, x0s1, x1s0, x1s1,
      x00t, x01t, x10t, x11t, x0st, x1st, xr0t, xr1t, xrs0, xrs1 );
  }

  return;
}
/******************************************************************************/

void blend_rst_2dn ( double r, double s, double t, double x[], int n,
  double ( *bound_rst ) ( double r, double s, double t, int i ) )

/******************************************************************************/
/*
  Purpose:

    BLEND_RST_2DN extends vector data on faces into a cube.

  Diagram:

    010-----r10-----110    011-----r11-----111
      |       .       |      |       .       |
      |       .       |      |       .       |
    0s0.....rs0.....1s0    0s1.....rs1.....1s1     S
      |       .       |      |       .       |     |
      |       .       |      |       .       |     |
    000-----r00-----100    001-----r01-----101     +----R
       BOTTOM                      TOP

    011-----0s1-----001    111-----1s1-----101
      |       .       |      |       .       |
      |       .       |      |       .       |
    01t.....0st.....00t    11t.....1st.....10t          T
      |       .       |      |       .       |          |
      |       .       |      |       .       |          |
    010-----0s0-----000    110-----1s0-----100     S----+
       LEFT                       RIGHT

    001-----r01-----101    011-----r11-----111
      |       .       |      |       .       |
      |       .       |      |       .       |
    00t.....r0t.....100    01t.....r1t.....11t     T
      |       .       |      |       .       |     |
      |       .       |      |       .       |     |
    000-----r00-----100    010-----r10-----110     +----R
       FRONT                       BACK

  Discussion:

    BLEND_RST_2DN is NOT equivalent to a trilinear finite element method,
    since the data is sampled everywhere along the corners, edges, and
    faces, rather than at a finite number of nodes.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 December 2013

  Author:

    John Burkardt

  Reference:

    William Gordon, Charles A Hall,
    Construction of Curvilinear Coordinate Systems and Application to
    Mesh Generation,
    International Journal of Numerical Methods in Engineering,
    Volume 7, pages 461-477, 1973.

    Joe Thompson, Bharat Soni, Nigel Weatherill,
    Handbook of Grid Generation,
    CRC Press,
    1999.

  Parameters:

    Input, double R, S, T, the (R,S,T) coordinates of the point to be evaluated.

    Output, double X[N], the interpolated value at the point (R,S,T).

    Input, int N, the dimension of the vector space.

    Input, double * bound_rst ( r, s, t, i ), a function given (R,S,T) coordinates
    and an component value I, and returns XI, the value of the I-th component
    of the N-vector at that point.  BOUND_RST will only be called for
    "faces", that is, for values (R,S,T) where at least one of R, S and T
    is either 0.0 or 1.0.
*/
{
  int i;
  double x000;
  double x001;
  double x010;
  double x011;
  double x100;
  double x101;
  double x110;
  double x111;
  double xr00;
  double xr01;
  double xr10;
  double xr11;
  double x0s0;
  double x0s1;
  double x1s0;
  double x1s1;
  double x00t;
  double x01t;
  double x10t;
  double x11t;
  double x0st;
  double x1st;
  double xr0t;
  double xr1t;
  double xrs0;
  double xrs1;

  for ( i = 0; i < n; i++ )
  {
/*
  Get the I-th coordinate component at the corners.
*/
    x000 = bound_rst ( 0.0, 0.0, 0.0, i );
    x001 = bound_rst ( 0.0, 0.0, 1.0, i );
    x010 = bound_rst ( 0.0, 1.0, 0.0, i );
    x011 = bound_rst ( 0.0, 1.0, 1.0, i );
    x100 = bound_rst ( 1.0, 0.0, 0.0, i );
    x101 = bound_rst ( 1.0, 0.0, 1.0, i );
    x110 = bound_rst ( 1.0, 1.0, 0.0, i );
    x111 = bound_rst ( 1.0, 1.0, 1.0, i );
/*
  Get the I-th coordinate component at the edges.
*/
    xr00 = bound_rst ( r, 0.0, 0.0, i );
    xr01 = bound_rst ( r, 0.0, 1.0, i );
    xr10 = bound_rst ( r, 1.0, 0.0, i );
    xr11 = bound_rst ( r, 1.0, 1.0, i );

    x0s0 = bound_rst ( 0.0, s, 0.0, i );
    x0s1 = bound_rst ( 0.0, s, 1.0, i );
    x1s0 = bound_rst ( 1.0, s, 0.0, i );
    x1s1 = bound_rst ( 1.0, s, 1.0, i );

    x00t = bound_rst ( 0.0, 0.0, t, i );
    x01t = bound_rst ( 0.0, 1.0, t, i );
    x10t = bound_rst ( 1.0, 0.0, t, i );
    x11t = bound_rst ( 1.0, 1.0, t, i );
/*
  Get the I-th component on the faces.
*/
    x0st = bound_rst ( 0.0, s, t, i );
    x1st = bound_rst ( 1.0, s, t, i );
    xr0t = bound_rst ( r, 0.0, t, i );
    xr1t = bound_rst ( r, 1.0, t, i );
    xrs0 = bound_rst ( r, s, 0.0, i );
    xrs1 = bound_rst ( r, s, 1.0, i );
/*
  Interpolate the I-th coordinate component of the interior point.
*/
    x[i] = blend_123 ( r, s, t, x000, x001, x010, x011, x100, x101,
      x110, x111, xr00, xr01, xr10, xr11, x0s0, x0s1, x1s0, x1s1,
      x00t, x01t, x10t, x11t, x0st, x1st, xr0t, xr1t, xrs0, xrs1 );
  }

  return;
}
/******************************************************************************/

int i4_max ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MAX returns the maximum of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, are two integers to be compared.

    Output, int I4_MAX, the larger of I1 and I2.
*/
{
  int value;

  if ( i2 < i1 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

int i4_min ( int i1, int i2 )

/******************************************************************************/
/*
  Purpose:

    I4_MIN returns the smaller of two I4's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 August 2006

  Author:

    John Burkardt

  Parameters:

    Input, int I1, I2, two integers to be compared.

    Output, int I4_MIN, the smaller of I1 and I2.
*/
{
  int value;

  if ( i1 < i2 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
/******************************************************************************/

void r8block_print ( int l, int m, int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8BLOCK_PRINT prints an R8BLOCK block (a 3D matrix).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 October 2018

  Author:

    John Burkardt

  Parameters:

    Input, int L, M, N, the dimensions of the block.

    Input, double A[L*M*N], the matrix to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;
  int j;
  int jhi;
  int jlo;
  int k;

  printf ( "\n" );
  printf ( "%s\n", title );

  for ( k = 1; k <= n; k++ )
  {
    printf ( "\n" );
    printf ( "  K = %2d", k );
    for ( jlo = 1; jlo <= m; jlo = jlo + 5 )
    {
      jhi = i4_min ( jlo + 4, m );
      printf ( "     " );
      for ( j = jlo; j <= jhi; j++ )
      {
        printf ( "%7d       ", j );
      }
      printf ( "\n" );
      printf ( "\n" );
      for ( i = 1; i <= l; i++ )
      {
        printf ( "%5d:", i );
        for ( j = jlo; j <= jhi; j++ )
        {
          printf ( "  %12g", a[i-1+(j-1)*l+(k-1)*l*m] );
        }
        printf ( "\n" );
      }
    }
  }

  return;
}
/******************************************************************************/

double *r8block_zeros_new ( int l, int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8BLOCK_ZEROS_NEW returns a new zeroed R8BLOCK.

  Discussion:

    An R8BLOCK is a triple dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 April 2013

  Author:

    John Burkardt

  Parameters:

    Input, int L, M, N, the number of rows, columns, and levels.

    Output, double R8BLOCK_ZEROS_NEW[L*M*N], the new zeroed matrix.
*/
{
  double *a;
  int i;
  int j;
  int k;

  a = ( double * ) malloc ( l * m * n * sizeof ( double ) );

  for ( k = 0; k < n; k++ )
  {
    for ( j = 0; j < m; j++ )
    {
      for ( i = 0; i < l; i++ )
      {
        a[i+j*l+k*l*m] = 0.0;
      }
    }
  }
  return a;
}
/******************************************************************************/

void r8mat_print ( int m, int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8MAT_PRINT prints an R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

    Entry A(I,J) is stored as A[I+J*M]

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 May 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows in A.

    Input, int N, the number of columns in A.

    Input, double A[M*N], the M by N matrix.

    Input, char *TITLE, a title.
*/
{
  r8mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
/******************************************************************************/

void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, char *title )

/******************************************************************************/
/*
  Purpose:

    R8MAT_PRINT_SOME prints some of an R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 June 2013

  Author:

    John Burkardt

  Parameters:

    Input, int M, the number of rows of the matrix.
    M must be positive.

    Input, int N, the number of columns of the matrix.
    N must be positive.

    Input, double A[M*N], the matrix.

    Input, int ILO, JLO, IHI, JHI, designate the first row and
    column, and the last row and column to be printed.

    Input, char *TITLE, a title.
*/
{
# define INCX 5

  int i;
  int i2hi;
  int i2lo;
  int j;
  int j2hi;
  int j2lo;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );

  if ( m <= 0 || n <= 0 )
  {
    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  (None)\n" );
    return;
  }
/*
  Print the columns of the matrix, in strips of 5.
*/
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )
  {
    j2hi = j2lo + INCX - 1;
    if ( n < j2hi )
    {
      j2hi = n;
    }
    if ( jhi < j2hi )
    {
      j2hi = jhi;
    }

    fprintf ( stdout, "\n" );
/*
  For each column J in the current range...

  Write the header.
*/
    fprintf ( stdout, "  Col:  ");
    for ( j = j2lo; j <= j2hi; j++ )
    {
      fprintf ( stdout, "  %7d     ", j - 1 );
    }
    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  Row\n" );
    fprintf ( stdout, "\n" );
/*
  Determine the range of the rows in this strip.
*/
    if ( 1 < ilo )
    {
      i2lo = ilo;
    }
    else
    {
      i2lo = 1;
    }
    if ( m < ihi )
    {
      i2hi = m;
    }
    else
    {
      i2hi = ihi;
    }

    for ( i = i2lo; i <= i2hi; i++ )
    {
/*
  Print out (up to) 5 entries in row I, that lie in the current strip.
*/
      fprintf ( stdout, "%5d:", i - 1 );
      for ( j = j2lo; j <= j2hi; j++ )
      {
        fprintf ( stdout, "  %14g", a[i-1+(j-1)*m] );
      }
      fprintf ( stdout, "\n" );
    }
  }

  return;
# undef INCX
}
/******************************************************************************/

double *r8mat_zeros_new ( int m, int n )

/******************************************************************************/
/*
  Purpose:

    R8MAT_ZEROS_NEW returns a new zeroed R8MAT.

  Discussion:

    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
    in column-major order.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 September 2008

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns.

    Output, double R8MAT_ZEROS_NEW[M*N], the new zeroed matrix.
*/
{
  double *a;
  int i;
  int j;

  a = ( double * ) malloc ( m * n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = 0.0;
    }
  }
  return a;
}
/******************************************************************************/

void r8vec_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8VEC_PRINT prints an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of components of the vector.

    Input, double A[N], the vector to be printed.

    Input, char *TITLE, a title.
*/
{
  int i;

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "%s\n", title );
  fprintf ( stdout, "\n" );
  for ( i = 0; i < n; i++ )
  {
    fprintf ( stdout, "  %8d: %14g\n", i, a[i] );
  }

  return;
}
/******************************************************************************/

double *r8vec_zeros_new ( int n )

/******************************************************************************/
/*
  Purpose:

    R8VEC_ZEROS_NEW creates and zeroes an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 March 2009

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Output, double R8VEC_ZEROS_NEW[N], a vector of zeroes.
*/
{
  double *a;
  int i;

  a = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    a[i] = 0.0;
  }
  return a;
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
