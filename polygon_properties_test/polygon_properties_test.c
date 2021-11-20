# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "polygon_properties.h"

int main ( );
void polygon_angles_test ( );
void polygon_area_test ( );
void polygon_area_2_test ( );
void polygon_centroid_test ( );
void polygon_centroid_2_test ( );
void polygon_contains_point_test ( );
void polygon_contains_point_2_test ( );
void polygon_diameter_test ( );
void polygon_expand_test ( );
void polygon_inrad_data_test ( );
void polygon_integral_1_test ( );
void polygon_integral_x_test ( );
void polygon_integral_xx_test ( );
void polygon_integral_xy_test ( );
void polygon_integral_y_test ( );
void polygon_integral_yy_test ( );
void polygon_is_convex_test ( );
void polygon_lattice_area_test ( );
void polygon_outrad_data_test ( );
void polygon_perimeter_test ( );
void polygon_perimeter_quad_test ( );
double f1 ( double x, double y );
double fx2 ( double x, double y );
void polygon_point_dist_test ( );
void polygon_point_near_test ( );
void polygon_sample_test ( );
void polygon_side_data_test ( );
void polygon_triangulate_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for POLYGON_PROPERTIES_TEST.

  Discussion:

    POLYGON_PROPERTIES_TEST tests the POLYGON_PROPERTIES library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 October 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "POLYGON_PROPERTIES_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the POLYGON_PROPERTIES library.\n" );

  polygon_angles_test ( );
  polygon_area_test ( );
  polygon_area_2_test ( );
  polygon_centroid_test ( );
  polygon_centroid_2_test ( );
  polygon_contains_point_test ( );
  polygon_contains_point_2_test ( );
  polygon_diameter_test ( );
  polygon_expand_test ( );
  polygon_inrad_data_test ( );
  polygon_integral_1_test ( );
  polygon_integral_x_test ( );
  polygon_integral_xx_test ( );
  polygon_integral_xy_test ( );
  polygon_integral_y_test ( );
  polygon_integral_yy_test ( );
  polygon_is_convex_test ( );
  polygon_lattice_area_test ( );
  polygon_outrad_data_test ( );
  polygon_perimeter_test ( );
  polygon_perimeter_quad_test ( );
  polygon_point_dist_test ( );
  polygon_point_near_test ( );
  polygon_sample_test ( );
  polygon_side_data_test ( );
  polygon_triangulate_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "POLYGON_PROPERTIES_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void polygon_angles_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_ANGLES_TEST tests POLYGON_ANGLES.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  double *angle;
  int i;
  int n = 6;
  double v[2*6] = {
    0.0, 0.0,
    1.0, 0.0,
    2.0, 1.0,
    3.0, 0.0,
    3.0, 2.0,
    1.0, 2.0 };

  printf ( "\n" );
  printf ( "POLYGON_ANGLES_TEST\n" );
  printf ( "  POLYGON_ANGLES computes the angles of a polygon.\n" );

  printf ( "\n" );
  printf ( "  Number of polygonal vertices = %d\n", n );

  r8mat_transpose_print ( 2, n, v, "  The polygon vertices:" );

  angle = polygon_angles ( n, v );

  printf ( "\n" );
  printf ( "  Polygonal angles in degrees:\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    printf ( "  %8d  %14.6g\n", i, r8_degrees ( angle[i] ) );
  }

  free ( angle );

  return;
}
/******************************************************************************/

void polygon_area_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_AREA_TEST tests POLYGON_AREA.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  double area;
  double area_exact1 = 2.0;
  double area_exact2 = 6.0;
  int n1 = 4;
  int n2 = 8;
  double v1[2*4] = {
    1.0, 0.0, 
    2.0, 1.0, 
    1.0, 2.0, 
    0.0, 1.0 };
  double v2[2*8] = {
        0.0, 0.0, 
        3.0, 0.0, 
        3.0, 3.0, 
        2.0, 3.0, 
        2.0, 1.0, 
        1.0, 1.0, 
        1.0, 2.0, 
        0.0, 2.0 };

  printf ( "\n" );
  printf ( "POLYGON_AREA_TEST\n" );
  printf ( "  POLYGON_AREA computes the area of a polygon\n" );

  printf ( "\n" );
  printf ( "  Number of polygonal vertices = %d\n", n1 );
  r8mat_transpose_print ( 2, n1, v1, "  The polygon vertices:" );
  area = polygon_area ( n1, v1 );
  printf ( "\n" );
  printf ( "  Exact area is        %g\n", area_exact1 );
  printf ( "  The computed area is %g\n", area );

  printf ( "\n" );
  printf ( "  Number of polygonal vertices = %d\n", n2 );
  r8mat_transpose_print ( 2, n2, v2, "  The polygon vertices:" );
  area = polygon_area ( n2, v2 );
  printf ( "\n" );
  printf ( "  Exact area is        %g\n", area_exact2 );
  printf ( "  The computed area is %g\n", area );

  return;
}
/******************************************************************************/

void polygon_area_2_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_AREA_2_TEST tests POLYGON_AREA_2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  double area;
  double area_exact1 = 2.0;
  double area_exact2 = 6.0;
  int n1 = 4;
  int n2 = 8;
  double v1[2*4] = {
    1.0, 0.0, 
    2.0, 1.0, 
    1.0, 2.0, 
    0.0, 1.0 };
  double v2[2*8] = {
        0.0, 0.0, 
        3.0, 0.0, 
        3.0, 3.0, 
        2.0, 3.0, 
        2.0, 1.0, 
        1.0, 1.0, 
        1.0, 2.0, 
        0.0, 2.0 };

  printf ( "\n" );
  printf ( "POLYGON_AREA_2_TEST\n" );
  printf ( "  POLYGON_AREA_2 computes the area of a polygon\n" );

  printf ( "\n" );
  printf ( "  Number of polygonal vertices = %d\n", n1 );
  r8mat_transpose_print ( 2, n1, v1, "  The polygon vertices:" );
  area = polygon_area_2 ( n1, v1 );
  printf ( "\n" );
  printf ( "  Exact area is        %g\n", area_exact1 );
  printf ( "  The computed area is %g\n", area );

  printf ( "\n" );
  printf ( "  Number of polygonal vertices = %d\n", n2 );
  r8mat_transpose_print ( 2, n2, v2, "  The polygon vertices:" );
  area = polygon_area_2 ( n2, v2 );
  printf ( "\n" );
  printf ( "  Exact area is        %g\n", area_exact2 );
  printf ( "  The computed area is %g\n", area );

  return;
}
/******************************************************************************/

void polygon_centroid_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_CENTROID_TEST tests POLYGON_CENTROID.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  double *centroid;
  int n = 4;
  double v[2*4] = {
    1.0, 0.0,
    2.0, 1.0,
    1.0, 2.0,
    0.0, 1.0 };

  printf ( "\n" );
  printf ( "POLYGON_CENTROID_TEST\n" );
  printf ( "  POLYGON_CENTROID computes the centroid of a polygon\n" );

  r8mat_transpose_print ( 2, n, v, "  The polygon vertices:" );

  centroid = polygon_centroid ( n, v );
  r8vec_print ( 2, centroid, "  POLYGON_CENTROID:" );
  free ( centroid );

  return;
}
/******************************************************************************/

void polygon_centroid_2_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_CENTROID_2_TEST tests POLYGON_CENTROID_2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  double *centroid;
  int n = 4;
  double v[2*4] = {
    1.0, 0.0,
    2.0, 1.0,
    1.0, 2.0,
    0.0, 1.0 };

  printf ( "\n" );
  printf ( "POLYGON_CENTROID_2_TEST\n" );
  printf ( "  POLYGON_CENTROID_2 computes the centroid of a polygon\n" );

  r8mat_transpose_print ( 2, n, v, "  The polygon vertices:" );

  centroid = polygon_centroid_2 ( n, v );
  r8vec_print ( 2, centroid, "  POLYGON_CENTROID_2:" );
  free ( centroid );

  return;
}
/******************************************************************************/

void polygon_contains_point_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_CONTAINS_POINT_TEST tests POLYGON_CONTAINS_POINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  int inside;
  int n = 5;
  double p[2];
  double p_test[2*4] = {
    1.0,  1.0, 
    3.0,  4.0, 
    0.0,  2.0, 
    0.5, -0.25 };
  int test;
  int test_num = 4;
  double v[2*5] = {
    0.0, 0.0, 
    1.0, 0.0, 
    2.0, 1.0, 
    1.0, 2.0, 
    0.0, 2.0 };
 
  printf ( "\n" );
  printf ( "POLYGON_CONTAINS_POINT_TEST\n" );
  printf ( "  POLYGON_CONTAINS_POINT determines if\n" );
  printf ( "  a point is in a polygon.\n" );

  r8mat_transpose_print ( 2, n, v, "  The polygon vertices:" );

  printf ( "\n" );
  printf ( "          P          In1  In2\n" );
  printf ( "\n" );

  for ( test = 0; test < test_num; test++ )
  {
    p[0] = p_test[0+test*2];
    p[1] = p_test[1+test*2];
 
    inside = polygon_contains_point ( n, v, p );

    printf ( "  %14.6g  %14.6g    %d\n", p[0], p[1], inside );
  } 

  return;
}
/******************************************************************************/

void polygon_contains_point_2_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_CONTAINS_POINT_2_TEST tests POLYGON_CONTAINS_POINT_2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  int inside;
  int n = 5;
  double p[2];
  double p_test[2*4] = {
    1.0,  1.0, 
    3.0,  4.0, 
    0.0,  2.0, 
    0.5, -0.25 };
  int test;
  int test_num = 4;
  double v[2*5] = {
    0.0, 0.0, 
    1.0, 0.0, 
    2.0, 1.0, 
    1.0, 2.0, 
    0.0, 2.0 };
 
  printf ( "\n" );
  printf ( "POLYGON_CONTAINS_POINT_2_TEST\n" );
  printf ( "  POLYGON_CONTAINS_POINT_2 determines if\n" );
  printf ( "  a point is in a polygon.\n" );

  r8mat_transpose_print ( 2, n, v, "  The polygon vertices:" );

  printf ( "\n" );
  printf ( "          P          In1  In2\n" );
  printf ( "\n" );

  for ( test = 0; test < test_num; test++ )
  {
    p[0] = p_test[0+test*2];
    p[1] = p_test[1+test*2];
 
    inside = polygon_contains_point_2 ( n, v, p );

    printf ( "  %14.6g  %14.6g    %d\n", p[0], p[1], inside );
  } 

  return;
}
/******************************************************************************/

void polygon_diameter_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_DIAMETER_TEST tests POLYGON_DIAMETER;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  double diameter;
  double diameter_exact = 2.0;
  int n = 4;
  double v[2*4] = {
    1.0, 0.0, 
    2.0, 1.0, 
    1.0, 2.0, 
    0.0, 1.0 };

  printf ( "\n" );
  printf ( "POLYGON_DIAMETER_TEST\n" );
  printf ( "  POLYGON_DIAMETER computes the diameter of a polygon;\n" );

  r8mat_transpose_print ( 2, n, v, "  The polygon vertices:" );

  diameter = polygon_diameter ( n, v );

  printf ( "\n" );
  printf ( "  Diameter ( computed ) %g\n", diameter );
  printf ( "  Diameter ( exact )    %g\n", diameter_exact );
 
  return;
}
/******************************************************************************/

void polygon_expand_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_EXPAND_TEST tests POLYGON_EXPAND;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  double h;
  int n = 4;
  double v[2*4] = {
    1.0, 1.0, 
    5.0, 1.0, 
    2.0, 4.0, 
    1.0, 3.0 };
  double *w;

  printf ( "\n" );
  printf ( "POLYGON_EXPAND_TEST\n" );
  printf ( "  POLYGON_EXPAND expands a polygon by an amount H.\n" );

  h = 0.5;

  r8mat_transpose_print ( 2, n, v, "  The polygon vertices:" );

  printf ( "\n" );
  printf ( "  The expansion amount H = %g\n", h );

  w = polygon_expand ( n, v, h );

  r8mat_transpose_print ( 2, n, w, "  The expanded polygon:" );

  free ( w );

  return;
}
/******************************************************************************/

void polygon_inrad_data_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_INRAD_DATA_TEST tests POLYGON_INRAD_DATA.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  double area;
  int n;
  double radin;
  double radout;
  double side;

  printf ( "\n" );
  printf ( "POLYGON_INRAD_TEST\n" );
  printf ( "  POLYGON_INRAD_DATA uses the inradius of a regular polygon\n" );
  printf ( "  to compute area, outradius, and side length\n" );

  for ( n = 3; n <= 5; n++ )
  {
    printf ( "\n" );
    printf ( "  Number of polygonal sides = %d\n", n );
    radin = 1.0;
    printf ( "\n" );
    printf ( "  Assuming RADIN = %g\n", radin );
    polygon_inrad_data ( n, radin, &area, &radout, &side );
    printf ( "    AREA =   %g\n", area );
    printf ( "    RADOUT = %g\n", radout );
    printf ( "    SIDE =   %g\n", side );
  }
  return;
}
/******************************************************************************/

void polygon_integral_1_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_INTEGRAL_1_TEST tests POLYGON_INTEGRAL_1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  int n1 = 4;
  int n2 = 3;
  double result;
  double v1[2*4] = {
    0.0, 0.0, 
    1.0, 0.0, 
    1.0, 1.0, 
    0.0, 1.0 };
  double v2[2*3] = {
    1.0, 1.0, 
    4.0, 3.0, 
    2.0, 5.0 };

  printf ( "\n" );
  printf ( "POLYGON_INTEGRAL_1_TEST\n" );
  printf ( "  POLYGON_INTEGRAL_1 integrates 1 over a polygon\n" );

  r8mat_transpose_print ( 2, n1, v1, "  Vertices of polygon V1:" );

  result = polygon_integral_1 ( n1, v1 );
  printf ( "\n" );
  printf ( "    1    %g\n", result );

  r8mat_transpose_print ( 2, n2, v2, "  Vertices of polygon V2:" );

  result = polygon_integral_1 ( n2, v2 );
  printf ( "\n" );
  printf ( "    1    %g\n", result );

  return;
}
/******************************************************************************/

void polygon_integral_x_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_INTEGRAL_X_TEST tests POLYGON_INTEGRAL_X.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  int n1 = 4;
  int n2 = 3;
  double result;
  double v1[2*4] = {
    0.0, 0.0, 
    1.0, 0.0, 
    1.0, 1.0, 
    0.0, 1.0 };
  double v2[2*3] = {
    1.0, 1.0, 
    4.0, 3.0, 
    2.0, 5.0 };

  printf ( "\n" );
  printf ( "POLYGON_INTEGRAL_X_TEST\n" );
  printf ( "  POLYGON_INTEGRAL_X integrates x over a polygon\n" );

  r8mat_transpose_print ( 2, n1, v1, "  Vertices of polygon V1:" );

  result = polygon_integral_x ( n1, v1 );
  printf ( "\n" );
  printf ( "    x    %g\n", result );

  r8mat_transpose_print ( 2, n2, v2, "  Vertices of polygon V2:" );

  result = polygon_integral_x ( n2, v2 );
  printf ( "\n" );
  printf ( "    x    %g\n", result );

  return;
}
/******************************************************************************/

void polygon_integral_xx_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_INTEGRAL_XX_TEST tests POLYGON_INTEGRAL_XX.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  int n1 = 4;
  int n2 = 3;
  double result;
  double v1[2*4] = {
    0.0, 0.0, 
    1.0, 0.0, 
    1.0, 1.0, 
    0.0, 1.0 };
  double v2[2*3] = {
    1.0, 1.0, 
    4.0, 3.0, 
    2.0, 5.0 };

  printf ( "\n" );
  printf ( "POLYGON_INTEGRAL_XX_TEST\n" );
  printf ( "  POLYGON_INTEGRAL_XX integrates x^2 over a polygon\n" );

  r8mat_transpose_print ( 2, n1, v1, "  Vertices of polygon V1:" );

  result = polygon_integral_xx ( n1, v1 );
  printf ( "\n" );
  printf ( "    x^2  %g\n", result );

  r8mat_transpose_print ( 2, n2, v2, "  Vertices of polygon V2:" );

  result = polygon_integral_xx ( n2, v2 );
  printf ( "\n" );
  printf ( "    x^2  %g\n", result );

  return;
}
/******************************************************************************/

void polygon_integral_xy_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_INTEGRAL_XY_TEST tests POLYGON_INTEGRAL_XY.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  int n1 = 4;
  int n2 = 3;
  double result;
  double v1[2*4] = {
    0.0, 0.0, 
    1.0, 0.0, 
    1.0, 1.0, 
    0.0, 1.0 };
  double v2[2*3] = {
    1.0, 1.0, 
    4.0, 3.0, 
    2.0, 5.0 };

  printf ( "\n" );
  printf ( "POLYGON_INTEGRAL_XY_TEST\n" );
  printf ( "  POLYGON_INTEGRAL_XY integrates x*y over a polygon\n" );

  r8mat_transpose_print ( 2, n1, v1, "  Vertices of polygon V1:" );

  result = polygon_integral_xy ( n1, v1 );
  printf ( "\n" );
  printf ( "    x*y  %g\n", result );

  r8mat_transpose_print ( 2, n2, v2, "  Vertices of polygon V2:" );

  result = polygon_integral_xy ( n2, v2 );
  printf ( "\n" );
  printf ( "    x*y  %g\n", result );

  return;
}
/******************************************************************************/

void polygon_integral_y_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_INTEGRAL_Y_TEST tests POLYGON_INTEGRAL_Y.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  int n1 = 4;
  int n2 = 3;
  double result;
  double v1[2*4] = {
    0.0, 0.0, 
    1.0, 0.0, 
    1.0, 1.0, 
    0.0, 1.0 };
  double v2[2*3] = {
    1.0, 1.0, 
    4.0, 3.0, 
    2.0, 5.0 };

  printf ( "\n" );
  printf ( "POLYGON_INTEGRAL_Y_TEST\n" );
  printf ( "  POLYGON_INTEGRAL_Y integrates y over a polygon\n" );

  r8mat_transpose_print ( 2, n1, v1, "  Vertices of polygon V1:" );

  result = polygon_integral_y ( n1, v1 );
  printf ( "\n" );
  printf ( "    y    %g\n", result );

  r8mat_transpose_print ( 2, n2, v2, "  Vertices of polygon V2:" );

  result = polygon_integral_y ( n2, v2 );
  printf ( "\n" );
  printf ( "    y    %g\n", result );

  return;
}
/******************************************************************************/

void polygon_integral_yy_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_INTEGRAL_YY_TEST tests POLYGON_INTEGRAL_YY.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  int n1 = 4;
  int n2 = 3;
  double result;
  double v1[2*4] = {
    0.0, 0.0, 
    1.0, 0.0, 
    1.0, 1.0, 
    0.0, 1.0 };
  double v2[2*3] = {
    1.0, 1.0, 
    4.0, 3.0, 
    2.0, 5.0 };

  printf ( "\n" );
  printf ( "POLYGON_INTEGRAL_YY_TEST\n" );
  printf ( "  POLYGON_INTEGRAL_YY integrates y^2 over a polygon\n" );

  r8mat_transpose_print ( 2, n1, v1, "  Vertices of polygon V1:" );

  result = polygon_integral_yy ( n1, v1 );
  printf ( "\n" );
  printf ( "    y^2  %g\n", result );

  r8mat_transpose_print ( 2, n2, v2, "  Vertices of polygon V2:" );

  result = polygon_integral_yy ( n2, v2 );
  printf ( "\n" );
  printf ( "    y^2  %g\n", result );

  return;
}
/******************************************************************************/

void polygon_is_convex_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_IS_CONVEX_TEST tests POLYGON_IS_CONVEX.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{ 
  double angle;
  int i;
  int n;
  int n01 = 1;
  int n02 = 2;
  int n03 = 3;
  int n04 = 3;
  int n05 = 3;
  int n06 = 4;
  int n07 = 5;
  int n08 = 5;
  int n09 = 6;
  int n10 = 6;
  int n11 = 8;
  const double r8_pi = 3.141592653589793;
  int result;
  int test;
  int test_num = 11;
  char title[255];
  double *v;
  double v01[2*1] = {
    0.0, 0.0 };
  double v02[2*2] = {
    0.0, 0.0, 
    1.0, 2.0 };
  double v03[2*3] = {
    0.0, 0.0, 
    2.0, 0.0, 
    1.0, 0.0 };
  double v04[2*3] = {
    0.0, 0.0, 
    1.0, 0.0, 
    0.0, 2.0 };
  double v05[2*3] = {
    0.0, 0.0, 
    0.0, 2.0, 
    1.0, 0.0 };
  double v06[2*4] = {
    1.0, 0.0, 
    2.0, 0.0, 
    3.0, 1.0, 
    0.0, 1.0 };
  double v07[2*5] = {
    0.0, 0.0, 
    0.5, 0.5, 
    1.0, 0.0, 
    1.0, 1.0, 
    0.0, 1.0 };
  double *v08;
  double *v09;
  double v10[2*6] = {
    0.0, 0.0, 
    2.0, 0.0, 
    1.0, 1.0, 
    0.0, 0.0, 
    2.0, 0.0, 
    1.0, 1.0 };
  double v11[2*8] = { 
    1.0, 0.0, 
    3.0, 0.0, 
    3.0, 3.0, 
    0.0, 3.0, 
    0.0, 1.0, 
    2.0, 1.0, 
    2.0, 2.0, 
    1.0, 2.0 };

  printf ( "\n" );
  printf ( "POLYGON_IS_CONVEX_TEST\n" );
  printf ( "  POLYGON_IS_CONVEX determines if a polygon\n" );
  printf ( "  is convex.\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    if ( test == 1 )
    {
      n = n01;
      v = v01;
      strcpy ( title, "  A point:" );
    }
    else if ( test == 2 )
    {
      n = n02;
      v = v02;
      strcpy ( title, "  A line:" );
    }
    else if ( test == 3 )
    {
      n = n03;
      v = v03;
      strcpy ( title, "  A triangle:" );
    }
    else if ( test == 4 )
    {
      n = n04;
      v = v04;
      strcpy ( title, "  A CCW triangle:" );
    }
    else if ( test == 5 )
    {
      n = n05;
      v = v05;
      strcpy ( title, "  A CW triangle:" );
    }
    else if ( test == 6 )
    {
      n = n06;
      v = v06;
      strcpy ( title, "  Polygon with large angle:" );
    }
    else if ( test == 7 )
    {
      n = n07;
      v = v07;
      strcpy ( title, "  Polygon with huge angle:" );
    }
    else if ( test == 8 )
    {
      n = n08;
      v08 = ( double * ) malloc ( 2 * n * sizeof ( double ) );
      for ( i = 0; i < n; i++ )
      {
        angle = ( double ) ( i ) * 4.0 * r8_pi / ( double ) ( n );
        v08[0+i*2] = cos ( angle );
        v08[1+i*2] = sin ( angle );
      }
      v = v08;
      strcpy ( title, "  A five-pointed star:" );
    }
    else if ( test == 9 )
    {
      n = n09;
      v09 = ( double * ) malloc ( 2 * n * sizeof ( double ) );
      for ( i = 0; i < n; i++ )
      {
        angle = ( double ) ( i ) * 2.0 * r8_pi / ( double ) ( n );
        v09[0+i*2] = cos ( angle );
        v09[1+i*2] = sin ( angle );
      }
      v = v09;
      strcpy ( title, "  A hexagon:" );
    }
    else if ( test == 10 )
    {
      n = n10;
      v = v10;
      strcpy ( title, "  A triangle twice:" );
    }
    else if ( test == 11 )
    {
      n = n11;
      v = v11;
      strcpy ( title, "  Square knot:" );
    }

    r8mat_transpose_print ( 2, n, v, title );
    result = polygon_is_convex ( n, v );

    if ( result == -1 )
    {
      printf ( "  The polygon is not convex.\n" );
    }
    else if ( result == 0 )
    {
      printf ( "  The polygon is degenerate and convex.\n" );
    }
    else if ( result == 1 )
    {
      printf ( "  The polygon is convex and counterclockwise.\n" );
    }
    else if ( result == 2 )
    {
      printf ( "  The polygon is convex and clockwise.\n" );
    }
  }

  free ( v08 );
  free ( v09 );

  return;
}
/******************************************************************************/

void polygon_lattice_area_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_LATTICE_AREA_TEST tests POLYGON_LATTICE_AREA.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  double area;
  int b;
  int i;

  printf ( "\n" );
  printf ( "POLYGON_LATTICE_AREA_TEST\n" );
  printf ( "  POLYGON_LATTICE_AREA returns the area\n" );
  printf ( "  of a polygon, measured in lattice points.\n" );

  i = 5;
  b = 6;

  printf ( "\n" );
  printf ( "  Number of interior lattice points = %d\n", i );
  printf ( "  Number of boundary lattice points = %d\n", b );

  area = polygon_lattice_area ( i, b );

  printf ( "  Area of polygon is %g\n", area );

  return;
}
/******************************************************************************/

void polygon_outrad_data_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_OUTRAD_DATA_TEST tests POLYGON_OUTRAD_DATA;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  double area;
  int n;
  double radin;
  double radout;
  double side;

  printf ( "\n" );
  printf ( "POLYGON_OUTRAD_DATA_TEST\n" );
  printf ( "  POLYGON_OUTRAD_DATA uses the outradius of a regular polygon\n" );
  printf ( "  to compute area, inradius, and side length.\n" );

  for ( n = 3; n <= 5; n++ )
  {
    printf ( "\n" );
    printf ( "  Number of polygonal sides = %d\n", n );
    radout = 1.0;
    printf ( "\n" );
    printf ( "  Assuming RADOUT = %g\n", radout );
    polygon_outrad_data ( n, radout, &area, &radin, &side );
    printf ( "    AREA =   %g\n", area );
    printf ( "    RADIN =  %g\n", radin );
    printf ( "    SIDE =   %g\n", side );
  }
  return;
}
/******************************************************************************/

void polygon_perimeter_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_PERIMETER_TEST tests POLYGON_PERIMETER.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 October 2015

  Author:

    John Burkardt
*/
{
  int n1 = 4;
  int n2 = 3;
  double result;
  double v1[2*4] = {
    0.0, 0.0, 
    1.0, 0.0, 
    1.0, 1.0, 
    0.0, 1.0 };
  double v2[2*3] = {
    1.0, 1.0, 
    4.0, 3.0, 
    2.0, 5.0 };

  printf ( "\n" );
  printf ( "POLYGON_PERIMETER_TEST\n" );
  printf ( "  POLYGON_PERIMETER computes the perimeter of a polygon\n" );

  r8mat_transpose_print ( 2, n1, v1, "  Vertices of polygon V1:" );

  result = polygon_perimeter ( n1, v1 );
  printf ( "\n" );
  printf ( "    Perimeter = %g\n", result );

  r8mat_transpose_print ( 2, n2, v2, "  Vertices of polygon V2:" );

  result = polygon_perimeter ( n2, v2 );
  printf ( "\n" );
  printf ( "    Perimeter = %g\n", result );

  return;
}
/******************************************************************************/

void polygon_perimeter_quad_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_PERIMETER_QUAD_TEST tests POLYGON_PERIMETER_QUAD.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 October 2015

  Author:

    John Burkardt
*/
{ 
  double hmax;
  int i;
  int n1 = 4;
  int n2 = 3;
  double v1[2*4] = {
    0.0, 0.0, 
    1.0, 0.0, 
    1.0, 1.0, 
    0.0, 1.0 };
  double v2[2*3] = {
    1.0, 1.0, 
    4.0, 3.0, 
    2.0, 5.0 };
  double value;

  printf ( "\n" );
  printf ( "POLYGON_PERIMETER_QUAD_TEST\n" );
  printf ( "  POLYGON_PERIMETER_QUAD estimates the integral of\n" );
  printf ( "  a function over the perimeter of a polygon using\n" );
  printf ( "  the composite midpoint rule over each side.\n" );

  r8mat_transpose_print ( 2, n1, v1, "  Vertices of polygon V1:" );

  hmax = 0.5;
  value = polygon_perimeter_quad ( n1, v1, hmax, f1 );
  printf ( "\n" );
  printf ( "  Using HMAX = %g, estimated integral of 1 over perimeter = %g\n", hmax, value );

  printf ( "\n" );
  hmax = 2.0;
  for ( i = 1; i <= 3; i++ )
  {
    hmax = hmax / 2.0;
    value = polygon_perimeter_quad ( n1, v1, hmax, fx2 );
    printf ( "  Using HMAX = %g, estimated integral of x^2 over perimeter = %g\n", hmax, value );
  }

  r8mat_transpose_print ( 2, n2, v2, "  Vertices of polygon V2:" );

  hmax = 0.5;
  value = polygon_perimeter_quad ( n2, v2, hmax, f1 );
  printf ( "\n" );
  printf ( "  Using HMAX = %g, estimated integral of 1 over perimeter = %g\n", hmax, value );

  printf ( "\n" );
  hmax = 2.0;
  for ( i = 1; i <= 3; i++ )
  {
    hmax = hmax / 2.0;
    value = polygon_perimeter_quad ( n2, v2, hmax, fx2 );
    printf ( "  Using HMAX = %g, estimated integral of x^2 over perimeter = %g\n", hmax, value );
  }

  return;
}
/******************************************************************************/

double f1 ( double x, double y )

/******************************************************************************/
/*
  Purpose:

    F1 evaluates f(x,y) = 1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 October 2015

  Author:

    John Burkardt
*/
{
  double value;

  value = 1.0;

  return value;
}
/******************************************************************************/

double fx2 ( double x, double y )

/******************************************************************************/
/*
  Purpose:

    FX2 evaluates f(x,y) = x^2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 October 2015

  Author:

    John Burkardt
*/
{
  double value;

  value = x * x;

  return value;
}
/******************************************************************************/

void polygon_point_dist_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_POINT_DIST_TEST tests POLYGON_POINT_DIST.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{ 
  double dist;
  int n = 3;
  double p[2];
  double p_test[2*3] = {
    4.0,  5.0, 
    2.0,  3.0, 
   -2.0, -1.0 };
  double v[2*3] = {
    1.0, 1.0, 
    4.0, 3.0, 
    2.0, 5.0 };
  int test;

  printf ( "\n" );
  printf ( "POLYGON_POINT_DIST_TEST\n" );
  printf ( "  POLYGON_POINT_DIST computes polygon-point distance.\n" );

  r8mat_transpose_print ( 2, n, v, "  Vertices of polygon:" );

  printf ( "\n" );
  printf ( "       X             Y             DIST\n" );
  printf ( "\n" );

  for ( test = 0; test < 3; test++ )
  {
    p[0] = p_test[0+test*2];
    p[1] = p_test[1+test*2];
    dist = polygon_point_dist ( n, v, p );
    printf ( "  %14.6g  %14.6g  %14.6g\n", p[0], p[1], dist );
  }

  return;
}
/******************************************************************************/

void polygon_point_near_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_POINT_NEAR_TEST tests POLYGON_POINT_NEAR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{ 
  int n = 3;
  double p[2];
  double p_test[2*3] = {
    4.0,  5.0, 
    2.0,  3.0, 
   -2.0, -1.0 };
  double *pn;
  double v[2*3] = {
    1.0, 1.0, 
    4.0, 3.0, 
    2.0, 5.0 };
  int test;

  printf ( "\n" );
  printf ( "POLYGON_POINT_NEAR_TEST\n" );
  printf ( "  POLYGON_POINT_NEAR computes nearest point on polygon.\n" );

  r8mat_transpose_print ( 2, n, v, "  Vertices of polygon:" );

  printf ( "\n" );
  printf ( "       X             Y             XN             YN\n" );
  printf ( "\n" );

  for ( test = 0; test < 3; test++ )
  {
    p[0] = p_test[0+test*2];
    p[1] = p_test[1+test*2];
    pn = polygon_point_near ( n, v, p );
    printf ( "  %14.6g  %14.6g    %14.6g  %14.6g\n", p[0], p[1], pn[0], pn[1] );
    free ( pn );
  }

  return;
}
/******************************************************************************/

void polygon_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_SAMPLE_TEST tests POLYGON_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  int n = 20;
  int nv = 6;
  int seed;
  double v[2*6] = {
    0.0, 0.0, 
    2.0, 0.0, 
    2.0, 1.0, 
    1.0, 1.0, 
    1.0, 2.0, 
    0.0, 1.0 };
  double *x;

  printf ( "\n" );
  printf ( "POLYGON_SAMPLE_TEST\n" );
  printf ( "  POLYGON_SAMPLE samples a polygon.\n" );

  seed = 123456789;

  x = polygon_sample ( nv, v, n, &seed );

  r8mat_transpose_print ( 2, n, x, "  Sample points:" );

  free ( x );

  return;
}
/******************************************************************************/

void polygon_side_data_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_SIDE_DATA_TEST tests POLYGON_SIDE_DATA;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 October 2015

  Author:

    John Burkardt
*/
{
  double area;
  int n;
  double radin;
  double radout;
  double side;

  printf ( "\n" );
  printf ( "POLYGON_SIDE_DATA_TEST\n" );
  printf ( "  POLYGON_SIDE_DATA uses the side length of a regular polygon\n" );
  printf ( "  to compute area, inradius, and outradius.\n" );

  for ( n = 3; n <= 5; n++ )
  {
    printf ( "\n" );
    printf ( "  Number of polygonal sides = %d\n", n );
    side = 1.0;
    printf ( "\n" );
    printf ( "  Assuming SIDE = %g\n", side );
    polygon_side_data ( n, side, &area, &radin, &radout );
    printf ( "    AREA =   %g\n", area );
    printf ( "    RADIN =  %g\n", radin );
    printf ( "    RADOUT = %g\n", radout );
  }
  return;
}
/******************************************************************************/

void polygon_triangulate_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_TRIANGULATE_TEST tests POLYGON_TRIANGULATE.

  Discussion:

    There are N-3 triangles in the triangulation.

    For the first N-2 triangles, the first edge listed is always an
    internal diagonal.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 October 2015
*/
{
  int j;
  int n = 10;
  int *triangles;
  double x[10] = {
    8.0, 7.0, 6.0, 5.0, 4.0, 
    3.0, 2.0, 1.0, 0.0, 4.0 };
  double y[10] = {
    0.0, 10.0,  0.0, 10.0,  0.0, 
   10.0,  0.0, 10.0,  0.0, -2.0 };

  printf ( "\n" );
  printf ( "POLYGON_TRIANGULATE_TEST\n" );
  printf ( "  POLYGON_TRIANGULATE triangulates a polygon.\n" );
  printf ( "  Here, we triangulate the comb_10 polygon.\n" );

  triangles = polygon_triangulate ( n, x, y );

  printf ( "\n" );
  printf ( "  Triangles:\n" );
  printf ( "\n" );

  for ( j = 0; j < n - 2; j++ )
  {
    printf ( "  %2d:    %2d  %2d  %2d\n", 
      j, triangles[0+j*3], triangles[1+j*3], triangles[2+j*3] );
  }

  free ( triangles );

  return;
}
