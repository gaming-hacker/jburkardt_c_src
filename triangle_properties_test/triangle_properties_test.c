# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "triangle_properties.h"

int main ( );
void triangle_angles_test ( );
void triangle_area_test ( );
void triangle_centroid_test ( );
void triangle_circumcircle_test ( );
void triangle_contains_point_test ( );
void triangle_diameter_test ( );
void triangle_edge_length_test ( );
void triangle_incircle_test ( );
void triangle_orientation_test ( );
void triangle_orthocenter_test ( );
void triangle_point_dist_test ( );
void triangle_point_near_test ( );
void triangle_quality_test ( );
void triangle_reference_sample_test ( );
void triangle_sample_test ( );
void triangle_xsi_to_xy_test ( );
void triangle_xy_to_xsi_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for TRIANGLE_PROPERTIES_TEST.

  Discussion:

    TRIANGLE_PROPERTIES_TEST tests the TRIANGLE_PROPERTIES library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "TRIANGLE_PROPERTIES_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the TRIANGLE_PROPERTIES library.\n" );

  triangle_angles_test ( );
  triangle_area_test ( );
  triangle_centroid_test ( );
  triangle_circumcircle_test ( );
  triangle_contains_point_test ( );
  triangle_diameter_test ( );
  triangle_edge_length_test ( );
  triangle_incircle_test ( );
  triangle_orientation_test ( );
  triangle_orthocenter_test ( );
  triangle_point_dist_test ( );
  triangle_point_near_test ( );
  triangle_quality_test ( );
  triangle_reference_sample_test ( );
  triangle_sample_test ( );
  triangle_xsi_to_xy_test ( );
  triangle_xy_to_xsi_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "TRIANGLE_PROPERTIES_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void triangle_angles_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_ANGLES_TEST tests TRIANGLE_ANGLES.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  double *angle;
  int i;
  const double r8_pi = 3.141592653589793;
  double t[2*3] = {
    0.0, 1.0, 
    0.0, 0.0, 
    1.0, 0.0 };

  printf ( "\n" );
  printf ( "TRIANGLE_ANGLES_TEST\n" );
  printf ( "  TRIANGLE_ANGLES computes the angles in a triangle.\n" );

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  angle = triangle_angles ( t );

  printf ( "\n" );
  printf ( "      Radians      Degrees\n" );
  printf ( "\n" );
  for ( i = 0; i < 3; i++ )
  {
    printf ( "  %14.6g  %14.6g\n", angle[i], ( angle[i] ) * 180.0 / r8_pi );
  }

  free ( angle );

  return;
}
/******************************************************************************/

void triangle_area_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_AREA_TEST tests TRIANGLE_AREA.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  double area;
  double t[2*3] = {
    0.0, 1.0, 
    0.0, 0.0, 
    1.0, 0.0 };

  printf ( "\n" );
  printf ( "TRIANGLE_AREA_TEST\n" );
  printf ( "  TRIANGLE_AREA computes the area of a triangle.\n" );

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  area = triangle_area ( t );

  printf ( "\n" );
  printf ( "  Triangle area is %g\n", area );

  return;
}
/******************************************************************************/

void triangle_centroid_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_CENTROID_TEST tests TRIANGLE_CENTROID;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  double *centroid;
  int i;
  int j;
  double t[2*3];
  double t_test[2*3*4] = {
         0.0,  0.0, 
         1.0,  0.0, 
         0.0,  1.0, 
         0.0,  0.0,
         1.0,  0.0, 
         0.5,  0.86602539, 
         0.0,  0.0, 
         1.0,  0.0, 
         0.5, 10.0, 
         0.0,  0.0, 
         1.0,  0.0, 
        10.0,  2.0 };
  int test;

  printf ( "\n" );
  printf ( "TRIANGLE_CENTROID_TEST\n" );
  printf ( "  TRIANGLE_CENTROID computes the centroid of a triangle.\n" );

  for ( test = 0; test < 4; test++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        t[i+j*2] = t_test[i+j*2+test*2*3];
      }
    }

    r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

    centroid = triangle_centroid ( t );

    r8vec_print ( 2, centroid, "  Centroid:" );

    free ( centroid );
  }

  return;
}
/******************************************************************************/

void triangle_circumcircle_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_CIRCUMCIRCLE_TEST tests TRIANGLE_CIRCUMCIRCLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  double pc[2];
  double r;
  double t[2*3];
  double t_test[2*3*4] = {
         0.0,  0.0, 
         1.0,  0.0, 
         0.0,  1.0, 
         0.0,  0.0,
         1.0,  0.0, 
         0.5,  0.86602539, 
         0.0,  0.0, 
         1.0,  0.0, 
         0.5, 10.0, 
         0.0,  0.0, 
         1.0,  0.0, 
        10.0,  2.0 };
  int test;

  printf ( "\n" );
  printf ( "TRIANGLE_CIRCUMCIRCLE_TEST\n" );
  printf ( "  TRIANGLE_CIRCUMCIRCLE computes the circumcircle of a triangle.\n" );

  for ( test = 0; test < 4; test++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        t[i+j*2] = t_test[i+j*2+test*2*3];
      }
    }

    r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

    triangle_circumcircle ( t, &r, pc );

    r8vec_print ( 2, pc, "  Circumcenter" );
    printf ( "  Circumradius: %g\n", r );

  }

  return;
}
/******************************************************************************/

void triangle_contains_point_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_CONTAINS_POINT_TEST tests TRIANGLE_CONTAINS_POINT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  int inside;
  int j;
  double p[2];
  double p_test[2*7] = {
     0.25,   0.25, 
     0.75,   0.25, 
     1.00,   1.00, 
    11.00,   0.50, 
     0.00,   1.00, 
     0.50, -10.00, 
     0.60,   0.60 };
  double t[2*3] = {
    0.0, 1.0, 
    0.0, 0.0, 
    1.0, 0.0 };
  double t2[2*3];
  int test;

  printf ( "\n" );
  printf ( "TRIANGLE_CONTAINS_POINT_TEST\n" );
  printf ( "  TRIANGLE_CONTAINS_POINT reports if a point\n" );
  printf ( "  is inside a triangle.\n" );

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  printf ( "\n" );
  printf ( "       X       Y     Inside\n" );
  printf ( "\n" );

  for ( test = 0; test < 7; test++ )
  {
    p[0] = p_test[0+test*2];
    p[1] = p_test[1+test*2];
 
    inside = triangle_contains_point ( t, p );

    printf ( "  %8.3f%8.3f     %i1\n", p[0], p[1], inside );
  }
/*
  Make a copy of the triangle with vertices in reverse order.
*/
  printf ( "\n" );
  printf ( "  Repeat the test, but reverse the triangle vertex\n" );
  printf ( "  ordering.\n" );
 
  for ( j = 0; j < 3; j++ )
  {
    t2[0+j*2] = t[0+(2-j)*3];
    t2[1+j*2] = t[1+(2-j)*3];
  }

  r8mat_transpose_print ( 2, 3, t2, "  Triangle vertices (reversed):" );

  printf ( "\n" );
  printf ( "       X       Y     Inside\n" );
  printf ( "\n" );

  for ( test = 0; test < 7; test++ )
  {
    p[0] = p_test[0+test*2];
    p[1] = p_test[1+test*2];
 
    inside = triangle_contains_point ( t2, p );

    printf ( "  %8.3f%8.3f     %i1\n", p[0], p[1], inside );
  }
 
  return;
}
/******************************************************************************/

void triangle_diameter_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_DIAMETER_TEST tests TRIANGLE_DIAMETER.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  double diameter;
  int i;
  int j;
  double t[2*3];
  double t_test[2*3*3] = {
     4.0, 2.0, 
     1.0, 5.0, 
    -2.0, 2.0, 
     4.0, 2.0, 
     5.0, 4.0, 
     6.0, 6.0, 
     4.0, 2.0, 
     1.0, 5.0, 
     4.0, 2.0 };
  int test;

  printf ( "\n" );
  printf ( "TRIANGLE_DIAMETER_TEST\n" );
  printf ( "  TRIANGLE_DIAMETER computes the diameter of\n" );
  printf ( "  the SMALLEST circle around the triangle.\n" );

  for ( test = 0; test < 3; test++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        t[i+j*2] = t_test[i+j*2+test*6];
      }
    }

    r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

    diameter = triangle_diameter ( t );

    printf ( "\n" );
    printf ( "  Diameter = %g\n", diameter );
  }

  return;
}
/******************************************************************************/

void triangle_edge_length_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_EDGE_LENGTH_TEST tests TRIANGLE_EDGE_LENGTH.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  double *edge_length;
  int i;
  int j;
  double t[2*3];
  double t_test[2*3*3] = {
     4.0, 2.0, 
     1.0, 5.0, 
    -2.0, 2.0, 
     4.0, 2.0, 
     5.0, 4.0, 
     6.0, 6.0, 
     4.0, 2.0, 
     1.0, 5.0, 
     4.0, 2.0 };
  int test;

  printf ( "\n" );
  printf ( "TRIANGLE_EDGE_LENGTH_TEST\n" );
  printf ( "  TRIANGLE_EDGE_LENGTH computes the edge lengths of a triangle.\n" );

  for ( test = 0; test < 3; test++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        t[i+j*2] = t_test[i+j*2+test*6];
      }
    }

    r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

    edge_length = triangle_edge_length ( t );

    r8vec_print ( 3, edge_length, "  EDGE_LENGTHS:" );

    free ( edge_length );
  }
  return;
}
/******************************************************************************/

void triangle_incircle_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_INCIRCLE_TEST tests TRIANGLE_INCIRCLE;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  double pc[2];
  double r;
  double t[2*3] = {
    0.0, 1.0,
    0.0, 0.0,
    1.0, 0.0 };

  printf ( "\n" );
  printf ( "TRIANGLE_INCIRCLE_TEST\n" );
  printf ( "  TRIANGLE_INCIRCLE_2D computes the incircle of a triangle.\n" );

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  triangle_incircle ( t, &r, pc );

  r8vec_print ( 2, pc, "  Incenter" );

  printf ( "\n" );
  printf ( "  Incircle radius is %g\n", r );

  return;
}
/******************************************************************************/

void triangle_orientation_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_ORIENTATION_TEST tests TRIANGLE_ORIENTATION.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  double t[2*3];
  double t_test[2*3*4] = {
     4.0,  2.0, 
     1.0,  5.0, 
    -2.0,  2.0, 
     1.0,  5.0, 
     4.0,  2.0, 
     1.0, -1.0, 
     1.0,  5.0, 
     2.0,  7.0, 
     3.0,  9.0, 
     1.0,  5.0, 
     4.0,  2.0, 
     1.0,  5.0 };
  int test;

  printf ( "\n" );
  printf ( "TRIANGLE_ORIENTATION_TEST\n" );
  printf ( "  TRIANGLE_ORIENTATION determines the orientation of a triangle.\n" );

  for ( test = 0; test < 4; test++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        t[i+j*2] = t_test[i+j*2+test*6];
      }
    }
    i = triangle_orientation ( t );

    r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

    if ( i == 0 )
    {
      printf ( "  The points are counterclockwise.\n" );
    }
    else if ( i == 1 )
    {
      printf ( "  The points are clockwise.\n" );
    }
    else if ( i == 2 )
    {
      printf ( "  The points are colinear.\n" );
    }
    else if ( i == 3 )
    {
      printf ( "  The points are not distinct.\n" );
    }
    else
    {
      printf ( "  The return value makes no sense.\n" );
    }

  }

  return;
}
/******************************************************************************/

void triangle_orthocenter_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_ORTHOCENTER_TEST tests TRIANGLE_ORTHOCENTER;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  int flag;
  int i;
  int j;
  double pc[2];
  double t[2*3];
  double t_test[2*3*4] = {
         0.0,  0.0, 
         1.0,  0.0, 
         0.0,  1.0, 
         0.0,  0.0,
         1.0,  0.0, 
         0.5,  0.86602539, 
         0.0,  0.0, 
         1.0,  0.0, 
         0.5, 10.0, 
         0.0,  0.0, 
         1.0,  0.0, 
        10.0,  2.0 };
  int test;

  printf ( "\n" );
  printf ( "TRIANGLE_ORTHOCENTER_TEST\n" );
  printf ( "  TRIANGLE_ORTHOCENTER_2D computes the orthocenter of a triangle.\n" );

  for ( test = 0; test < 4; test++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        t[i+j*2] = t_test[i+j*2+test*6];
      }
    }

    r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

    triangle_orthocenter ( t, pc, &flag );

    r8vec_print ( 2, pc, "  Orthocenter" );
  }

  return;
}
/******************************************************************************/

void triangle_point_dist_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_POINT_DIST_TEST tests TRIANGLE_POINT_DIST;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  double dist;
  double p[2];
  double p_test[2*7] = {
     0.25,   0.25, 
     0.75,   0.25, 
     1.00,   1.00, 
    11.00,   0.50, 
     0.00,   1.00, 
     0.50, -10.00, 
     0.60,   0.60 };
  double t[2*3] = {
    0.0, 1.0, 
    0.0, 0.0, 
    1.0, 0.0 };
  int test;

  printf ( "\n" );
  printf ( "TRIANGLE_POINT_DIST_TEST\n" );
  printf ( "  TRIANGLE_POINT_DIST computes the distance\n" );
  printf ( "  from a point to a triangle.\n" );

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  printf ( "\n" );
  printf ( "           P            DIST\n" );
  printf ( "\n" );

  for ( test = 0; test < 7; test++ )
  {
    p[0] = p_test[0+test*2];
    p[1] = p_test[1+test*2];

    dist = triangle_point_dist ( t, p );

    printf ( "  %8.3f%8.3f  %8.3f\n", p[0], p[1], dist );
  }
 
  return;
}
/******************************************************************************/

void triangle_point_near_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_POINT_NEAR_TEST tests TRIANGLE_POINT_NEAR.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2015

  Author:

    John Burkardt
*/
{
  double dist;
  double p[2];
  double p_test[2*7] = {
     0.25,   0.25, 
     0.75,   0.25, 
     1.00,   1.00, 
    11.00,   0.50, 
     0.00,   1.00, 
     0.50, -10.00, 
     0.60,   0.60 };
  double pn[2];
  double t[2*3] = {
    0.0, 1.0, 
    0.0, 0.0, 
    1.0, 0.0 };
  int test;

  printf ( "\n" );
  printf ( "TRIANGLE_POINT_NEAR_TEST\n" );
  printf ( "  TRIANGLE_POINT_NEAR computes the nearest\n" );
  printf ( "  point on a triangle to a given point.\n" );

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  printf ( "\n" );
  printf ( "           P                PN\n" );
  printf ( "\n" );

  for ( test = 0; test < 7; test++ )
  {
    p[0] = p_test[0+test*2];
    p[1] = p_test[1+test*2];


    triangle_point_near ( t, p, pn, &dist );

    printf ( "  %8.3f%8.3f  %8.3f%8.3f\n", p[0], p[1], pn[0], pn[1] );
  }
 
  return;
}
/******************************************************************************/

void triangle_quality_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_QUALITY_TEST tests TRIANGLE_QUALITY.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 November 2015

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  double quality;
  double t[2*3];
  double t_test[2*3*4] = {
         0.0,  0.0, 
         1.0,  0.0, 
         0.0,  1.0, 
         0.0,  0.0,
         1.0,  0.0, 
         0.5,  0.86602539, 
         0.0,  0.0, 
         1.0,  0.0, 
         0.5, 10.0, 
         0.0,  0.0, 
         1.0,  0.0, 
        10.0,  2.0 };
  int test;

  printf ( "\n" );
  printf ( "TRIANGLE_QUALITY_TEST\n" );
  printf ( "  TRIANGLE_QUALITY computes the quality of a triangle.\n" );

  for ( test = 0; test < 4; test++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        t[i+j*2] = t_test[i+j*2+test*6];
      }
    }

    r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

    quality = triangle_quality ( t );

    printf ( "\n" );
    printf ( "  Quality = %g\n", quality );
  }

  return;
}
/******************************************************************************/

void triangle_reference_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_REFERENCE_SAMPLE_TEST tests TRIANGLE_REFERENCE_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 November 2015

  Author:

    John Burkardt
*/
{
  double *p;
  int seed = 123456789;
  double t[2*3] = {
     0.0, 0.0, 
     1.0, 0.0, 
     0.0, 1.0 };
  int test;
  double *xsi;

  printf ( "\n" );
  printf ( "TRIANGLE_REFERENCE_SAMPLE_TEST\n" );
  printf ( "  TRIANGLE_REFERENCE_SAMPLE samples the reference triangle.\n" );

  printf ( "\n" );
  printf ( "  Sample points (X,Y) and (XSI1,XSI2,XSI3) coordinates:\n" );
  printf ( "\n" );

  for ( test = 0; test < 10; test++ )
  {
    p = triangle_reference_sample ( 1, &seed );
    xsi = triangle_xy_to_xsi ( t, p );
    printf ( "  %8.4f%8.4f    %8.4f%8.4f%8.4f\n", p[0], p[1], xsi[0], xsi[1], xsi[2] );
    free ( p );
    free ( xsi );
  }

  return;
}
/******************************************************************************/

void triangle_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_SAMPLE_TEST tests TRIANGLE_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 November 2015

  Author:

    John Burkardt
*/
{
  double *p;
  int seed = 123456789;
  double t[2*3] = {
     4.0, 2.0, 
     1.0, 5.0, 
    -2.0, 2.0 };
  int test;
  double *xsi;

  printf ( "\n" );
  printf ( "TRIANGLE_SAMPLE_TEST\n" );
  printf ( "  TRIANGLE_SAMPLE samples points from a triangle.\n" );

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  printf ( "\n" );
  printf ( "  Sample points (X,Y) and (XSI1,XSI2,XSI3) coordinates:\n" );
  printf ( "\n" );

  for ( test = 0; test < 10; test++ )
  {
    p = triangle_sample ( t, 1, &seed );
    xsi = triangle_xy_to_xsi ( t, p );
    printf ( "  %8.4f%8.4f    %8.4f%8.4f%8.4f\n", p[0], p[1], xsi[0], xsi[1], xsi[2] );
    free ( p );
    free ( xsi );
  }

  return;
}
/******************************************************************************/

void triangle_xsi_to_xy_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_XSI_TO_XY_TEST tests TRIANGLE_XSI_TO_XY.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 November 2015

  Author:

    John Burkardt
*/
{
  double *p;
  double *p2;
  int seed = 123456789;
  double t[2*3] = {
     4.0, 2.0, 
     1.0, 5.0, 
    -2.0, 2.0 };
  int test;
  double *xsi;

  printf ( "\n" );
  printf ( "TRIANGLE_XSI_TO_XY_TEST\n" );
  printf ( "  TRIANGLE_XSI_TO_XY converts XSI to XY coordinates.\n" );
  printf ( "\n" );
  printf ( "  We verify that (X,Y) -> (XSI1,XSI2,XSI3) -> (X,Y)\n" );
  printf ( "  works properly.\n" );

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  printf ( "\n" );
  printf ( "  Sample points:\n" );
  printf ( "\n" );

  for ( test = 0; test < 10; test++ )
  {

    if ( test == 0 )
    {
      p = triangle_centroid ( t );
    }
    else if ( test == 1 )
    {
      p = ( double * ) malloc ( 2 * sizeof ( double ) );
      p[0] = 3.0;
      p[1] = 0.0;
    }
    else
    {
      p = triangle_sample ( t, 1, &seed );
    }

    xsi = triangle_xy_to_xsi ( t, p );

    p2 = triangle_xsi_to_xy ( t, xsi );

    printf ( "  %8.4f%8.4f    %8.4f%8.4f%8.4f  %8.4f%8.4f\n", 
      p[0], p[1], xsi[0], xsi[1], xsi[2], p2[0], p2[1] );

    free ( p );
    free ( p2 );
    free ( xsi );
  }

  return;
}
/******************************************************************************/

void triangle_xy_to_xsi_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_XY_TO_XSI_TEST tests TRIANGLE_XY_TO_XSI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 November 2015

  Author:

    John Burkardt
*/
{
  double *p;
  double *p2;
  int seed = 123456789;
  double t[2*3] = {
     4.0, 2.0, 
     1.0, 5.0, 
    -2.0, 2.0 };
  int test;
  double *xsi;

  printf ( "\n" );
  printf ( "TRIANGLE_XY_TO_XSI_TEST\n" );
  printf ( "  TRIANGLE_XY_TO_XSI converts XY to XSI coordinates.\n" );
  printf ( "\n" );
  printf ( "  We verify that (X,Y) -> (XSI1,XSI2,XSI3) -> (X,Y)\n" );
  printf ( "  works properly.\n" );

  r8mat_transpose_print ( 2, 3, t, "  Triangle vertices:" );

  printf ( "\n" );
  printf ( "  Sample points:\n" );
  printf ( "\n" );

  for ( test = 0; test < 10; test++ )
  {

    if ( test == 0 )
    {
      p = triangle_centroid ( t );
    }
    else if ( test == 1 )
    {
      p = ( double * ) malloc ( 2 * sizeof ( double ) );
      p[0] = 3.0;
      p[1] = 0.0;
    }
    else
    {
      p = triangle_sample ( t, 1, &seed );
    }

    xsi = triangle_xy_to_xsi ( t, p );

    p2 = triangle_xsi_to_xy ( t, xsi );

    printf ( "  %8.4f%8.4f    %8.4f%8.4f%8.4f  %8.4f%8.4f\n", 
      p[0], p[1], xsi[0], xsi[1], xsi[2], p2[0], p2[1] );

    free ( p );
    free ( p2 );
    free ( xsi );
  }

  return;
}
