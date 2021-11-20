# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "geometry.h"

int main ( );
void angle_box_2d_test ( );
void angle_contains_ray_2d_test ( );
void angle_deg_2d_test ( );
void angle_rad_nd_test ( );

void ball01_volume_test ( );

void circle_dia2imp_2d_test ( );
void circle_imp_point_dist_2d_test ( );
void circle_lune_angle_by_height_2d_test ( );
void circle_lune_area_by_angle_2d_test ( );
void circle_lune_area_by_height_2d_test ( );
void circle_lune_height_by_angle_2d_test ( );
void circle_sector_area_2d_test ( );
void circle_triangle_area_2d_test ( );

void circles_intersect_area_2d_test ( );
void circles_intersect_points_2d_test ( );

void cube01_volume_test ( );

void ellipse_area1_test ( );
void ellipse_area2_test ( );
void ellipse_area3_test ( );
void ellipse_eccentricity_test ( );

void line_par_point_dist_2d_test ( );
void line_par_point_near_2d_test ( );

void line_par_point_dist_3d_test ( );
void line_par_point_near_3d_test ( );

void parallelogram_area_2d_test ( );
void parallelogram_area_3d_test ( );

void plane_normal_qr_to_xyz_test ( );
void plane_normal_xyz_to_qr_test ( );

void plane_normal_tetrahedron_intersect_test ( );

void polygon_contains_point_2d_test ( );
void polygon_contains_point_2d_convex_test ( );
void polygon_contains_point_2d_3_test ( );

void quad_area_2d_test ( );
void quad_area2_2d_test ( );

void quad_area_3d_test ( );

void sphere_exp2imp_3d_test ( );
void sphere_imp2exp_3d_test ( );

void sphere_exp2imp_nd_test ( );

void triangle_circumcenter_2d_test ( );
void triangle_circumcenter_2d_2_test ( );
void triangle_circumcenter_test ( );

void wedge01_volume_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for GEOMETRY_TEST.

  Discussion:

    GEOMETRY_TEST tests geometry().

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 March 2021

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "GEOMETRY_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test geometry().\n" );

  angle_box_2d_test ( );
  angle_contains_ray_2d_test ( );
  angle_deg_2d_test ( );
  angle_rad_nd_test ( );

  ball01_volume_test ( );

  circle_dia2imp_2d_test ( );
  circle_imp_point_dist_2d_test ( );
  circle_lune_angle_by_height_2d_test ( );
  circle_lune_area_by_angle_2d_test ( );
  circle_lune_area_by_height_2d_test ( );
  circle_lune_height_by_angle_2d_test ( );
  circle_sector_area_2d_test ( );
  circle_triangle_area_2d_test ( );

  circles_intersect_area_2d_test ( );
  circles_intersect_points_2d_test ( );

  cube01_volume_test ( );

  ellipse_area1_test ( );
  ellipse_area2_test ( );
  ellipse_area3_test ( );
  ellipse_eccentricity_test ( );

  line_par_point_dist_2d_test ( );
  line_par_point_near_2d_test ( );

  line_par_point_dist_3d_test ( );
  line_par_point_near_3d_test ( );

  parallelogram_area_2d_test( );
  parallelogram_area_3d_test( );

  plane_normal_qr_to_xyz_test ( );
  plane_normal_xyz_to_qr_test ( );

  plane_normal_tetrahedron_intersect_test ( );

  polygon_contains_point_2d_test ( );
  polygon_contains_point_2d_convex_test ( );
  polygon_contains_point_2d_3_test ( );

  quad_area_2d_test ( );
  quad_area2_2d_test ( );

  quad_area_3d_test ( );

  sphere_exp2imp_3d_test ( );
  sphere_imp2exp_3d_test ( );

  sphere_exp2imp_nd_test ( );

  triangle_circumcenter_2d_test ( );
  triangle_circumcenter_2d_2_test ( );
  triangle_circumcenter_test ( );

  wedge01_volume_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "GEOMETRY_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void angle_box_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    ANGLE_BOX_2D_TEST tests ANGLE_BOX_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 October 2010

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2

  double dist;
  double p1[DIM_NUM];
  double p2[DIM_NUM];
  double p3[DIM_NUM];
  double p4[DIM_NUM];
  double p5[DIM_NUM];

  printf ( "\n" );
  printf ( "ANGLE_BOX_2D_TEST\n" );
  printf ( "  ANGLE_BOX_2D\n" );
  printf ( "  Compute P4 and P5, normal to\n" );
  printf ( "  line through P1 and P2, and\n" );
  printf ( "  line through P2 and P3,\n" );
  printf ( "  and DIST units from P2.\n" );
/*
  These points define the lines
    y = 0
  and
    y = 2x-6
*/
  p1[0] = 0.0;
  p1[1] = 0.0;
  p2[0] = 3.0;
  p2[1] = 0.0;
  p3[0] = 4.0;
  p3[1] = 2.0;
  dist = 1.0;

  printf ( "\n" );
  printf ( "  DIST %14f\n", dist );
  printf ( "  P1:  %14f  %14f\n", p1[0], p1[1] );
  printf ( "  P2:  %14f  %14f\n", p2[0], p2[1] );
  printf ( "  P3:  %14f  %14f\n", p3[0], p3[1] );

  angle_box_2d ( dist, p1, p2, p3, p4, p5 );

  printf ( "  P4:  %14f  %14f\n", p4[0], p4[1] );
  printf ( "  P5:  %14f  %14f\n", p5[0], p5[1] );
/*
  These points define the lines
    y = 0
  and
    y = 2x-6
*/
  p1[0] = 0.0;
  p1[1] = 0.0;
  p2[0] = 3.0;
  p2[1] = 0.0;
  p3[0] = 2.0;
  p3[1] = -2.0;
  dist = 1.0;

  printf ( "\n" );
  printf ( "  DIST %14f\n", dist );
  printf ( "  P1:  %14f  %14f\n", p1[0], p1[1] );
  printf ( "  P2:  %14f  %14f\n", p2[0], p2[1] );
  printf ( "  P3:  %14f  %14f\n", p3[0], p3[1] );

  angle_box_2d ( dist, p1, p2, p3, p4, p5 );

  printf ( "  P4:  %14f  %14f\n", p4[0], p4[1] );
  printf ( "  P5:  %14f  %14f\n", p5[0], p5[1] );
/*
  By setting P1 = P2, we are asking to extend the line
    y = 2x-6
  from P3 to P2 through to the other side.
*/
  p1[0] = 3.0;
  p1[1] = 0.0;
  p2[0] = 3.0;
  p2[1] = 0.0;
  p3[0] = 2.0;
  p3[1] = -2.0;
  dist = 1.0;

  printf ( "\n" );
  printf ( "  DIST %14f\n", dist );
  printf ( "  P1:  %14f  %14f\n", p1[0], p1[1] );
  printf ( "  P2:  %14f  %14f\n", p2[0], p2[1] );
  printf ( "  P3:  %14f  %14f\n", p3[0], p3[1] );

  angle_box_2d ( dist, p1, p2, p3, p4, p5 );

  printf ( "  P4:  %14f  %14f\n", p4[0], p4[1] );
  printf ( "  P5:  %14f  %14f\n", p5[0], p5[1] );

  return;
# undef DIM_NUM
}
/******************************************************************************/

void angle_contains_ray_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    ANGLE_CONTAINS_RAY_2D_TEST tests ANGLE_CONTAINS_RAY_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2012

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define TEST_NUM 6

  int angle;
  int angle_num = 12;
  double angle_rad;
  int inside;
  double p[DIM_NUM];
  double p1[DIM_NUM];
  double p2[DIM_NUM];
  double p3[DIM_NUM];
  double pi = 3.141592653589793;
  int test;

  printf ( "\n" );
  printf ( "ANGLE_CONTAINS_RAY_2D_TEST\n" );
  printf ( "  ANGLE_CONTAINS_RAY_2D sees if a ray lies within an angle.\n" );

  for ( test = 0; test < TEST_NUM; test++ )
  {
    if ( test == 0 )
    {
      p1[0] = 1.0;
      p1[1] = 0.0;

      p2[0] = 0.0;
      p2[1] = 0.0;

      p3[0] = 1.0;
      p3[1] = 1.0;
    }
    else if ( test == 1 )
    {
      p1[0] = 1.0;
      p1[1] = 0.0;

      p2[0] = 0.0;
      p2[1] = 0.0;

      p3[0] = 0.0;
      p3[1] = 1.0;
    }
    else if ( test == 2 )
    {
      p1[0] =  1.0;
      p1[1] = -1.0;

      p2[0] = 0.0;
      p2[1] = 0.0;

      p3[0] = 0.0;
      p3[1] = 1.0;
    }
    else if ( test == 3 )
    {
      p1[0] = 1.0;
      p1[1] = 0.0;

      p2[0] = 0.0;
      p2[1] = 0.0;

      p3[0] = -1.0;
      p3[1] =  0.0;
    }
    else if ( test == 4 )
    {
      p1[0] = 1.0;
      p1[1] = 0.0;

      p2[0] = 0.0;
      p2[1] = 0.0;

      p3[0] =  0.0;
      p3[1] = -1.0;
    }
    else if ( test == 5 )
    {
      p1[0] = 1.0;
      p1[1] = 0.0;

      p2[0] = 0.0;
      p2[1] = 0.0;

      p3[0] =  1.0;
      p3[1] = -0.01;
    }

    r8vec_print ( DIM_NUM, p1, "  Vertex A" );
    r8vec_print ( DIM_NUM, p2, "  Vertex B" );
    r8vec_print ( DIM_NUM, p3, "  Vertex C" );

    printf ( "\n" );
    printf ( "       X            Y       Inside?\n" );
    printf ( "\n" );

    for ( angle = 0; angle <= angle_num; angle++ )
    {
      angle_rad = ( double ) ( angle ) * 2.0 * pi / ( double ) angle_num;

      p[0] = cos ( angle_rad );
      p[1] = sin ( angle_rad );

      inside = angle_contains_ray_2d ( p1, p2, p3, p );

      printf ( "  %12g  %12g  %d\n", p[0], p[1], inside );
    }

  }

  return;
# undef DIM_NUM
# undef TEST_NUM
}
/******************************************************************************/

void angle_deg_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    ANGLE_DEG_2D_TEST tests ANGLE_DEG_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2013

  Author:

    John Burkardt
*/
{
  int angle_num = 12;
  int i;
  double temp1;
  double temp2;
  double thetad;
  double thetar;
  double v1[2] = { 1.0, 0.0 };
  double v2[2];
  double v3[2] = { 0.0, 0.0 };

  printf ( "\n" );
  printf ( "ANGLE_DEG_2D_TEST\n" );
  printf ( "  ANGLE_DEG_2D computes an angle.\n" );
  printf ( "\n" );
  printf ( "  X  Y  Theta  ATAN2(y, x), ANGLE_DEG_2D\n" );
  printf ( "\n" );

  for ( i = 0; i <= angle_num; i++ )
  {
    thetad = ( double ) ( i ) * 360.0 / ( double ) ( angle_num );
    thetar = degrees_to_radians ( thetad );

    v2[0] = cos ( thetar );
    v2[1] = sin ( thetar );

    temp1 = radians_to_degrees ( atan2 ( v2[1], v2[0] ) );

    temp2 = angle_deg_2d ( v1, v3, v2 );

    printf ( "  %8.3f  %8.3f  %8.3f  %8.3f  %8.3f\n",
    v2[0], v2[1], thetad, temp1, temp2 );
  } 
  return;
}
/******************************************************************************/

void angle_rad_nd_test ( )

/******************************************************************************/
/*
  Purpose:

    ANGLE_RAD_ND_TEST tests ANGLE_RAD_ND.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2013

  Author:

    John Burkardt
*/
{
  int angle_num = 12;
  int i;
  double temp1;
  double temp2;
  double thetad;
  double thetar;
  double v1[2] = { 1.0, 0.0 };
  double v2[2];

  printf ( "\n" );
  printf ( "ANGLE_RAD_ND_TEST\n" );
  printf ( "  ANGLE_RAD_ND computes an angle.\n" );
  printf ( "\n" );
  printf ( "  X  Y  Theta  ATAN2(y, x), ANGLE_RAD_ND\n" );
  printf ( "\n" );

  for ( i = 0; i <= angle_num; i++ )
  {
    thetad = ( double ) ( i ) * 360.0 / ( double ) ( angle_num );
    thetar = degrees_to_radians ( thetad );

    v2[0] = cos ( thetar );
    v2[1] = sin ( thetar );

    temp1 = radians_to_degrees ( atan2 ( v2[1], v2[0] ) );

    temp2 = angle_rad_nd ( 2, v1, v2 );

    printf ( "  %8.3f  %8.3f  %8.3f  %8.3f  %8.3f\n",
    v2[0], v2[1], thetad, temp1, temp2 );
  } 
  return;
}
/******************************************************************************/

void ball01_volume_test ( )

/******************************************************************************/
/*
  Purpose:

    BALL01_VOLUME_TEST tests BALL01_VOLUME.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2018

  Author:

    John Burkardt
*/
{
  double volume;

  printf ( "\n" );
  printf ( "BALL01_VOLUME_TEST\n" );
  printf ( "  BALL01_VOLUME returns the volume of the unit ball.\n" );

  volume = ball01_volume ( );

  printf ( "\n" );
  printf ( "  Volume = %g\n", volume );

  return;
}
/******************************************************************************/

void circle_dia2imp_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLE_DIA2IMP_2D_TEST tests CIRCLE_DIA2IMP_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 January 2018

  Author:

    John Burkardt
*/
{
  double pc[2];
  double p1[2];
  double p2[2];
  double r;
  double theta;

  printf ( "\n" );
  printf ( "CIRCLE_DIA2IMP_2D_TEST\n" );
  printf ( "  CIRCLE_DIA2IMP_2D converts a diameter to an\n" );
  printf ( "  implicit circle in 2D.\n" );

  theta = 2.0;

  p1[0] = 2.0 + 5.0 * cos ( theta );
  p1[1] = 2.0 + 5.0 * sin ( theta );
  p2[0] = 2.0 - 5.0 * cos ( theta );
  p2[1] = 2.0 - 5.0 * sin ( theta );

  r8vec_print ( 2, p1, "  P1:" );
  r8vec_print ( 2, p2, "  P2:" );

  circle_dia2imp_2d ( p1, p2, &r, pc );

  circle_imp_print_2d ( r, pc, "  The implicit circle:" );

  return;
}
/******************************************************************************/

void circle_imp_point_dist_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLE_IMP_POINT_DIST_2D_TEST tests CIRCLE_IMP_POINT_DIST_2D;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 January 2018

  Author:

    John Burkardt
*/
{
  double d;
  double center[2] = { 0.0, 0.0 };
  int i;
  double *p;
  double r;
  int seed;

  printf ( "\n" );
  printf ( "CIRCLE_IMP_POINT_DIST_2D_TEST\n" );
  printf ( "  CIRCLE_IMP_POINT_DIST_2D finds the\n" );
  printf ( "  distance from a point to a circle.\n" );

  r = 5.0;
  circle_imp_print_2d ( r, center, "  The circle:" );

  printf ( "\n" );
  printf ( "       X       Y       D\n" );
  printf ( "\n" );

  seed = 123456789;

  for ( i = 1; i <= 10; i++ )
  {
    p = r8vec_uniform_ab_new ( 2, -10.0, +10.0, &seed );
    d = circle_imp_point_dist_2d ( r, center, p );
    printf ( "  %8f  %8f  %8f\n", p[0], p[1], d  );
    free ( p );
  }

  return;
}
/******************************************************************************/

void circle_lune_angle_by_height_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLE_LUNE_ANGLE_BY_HEIGHT_2D_TEST tests CIRCLE_LUNE_ANGLE_BY_HEIGHT_2D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 January 2018

  Author:

    John Burkardt
*/
{
  double angle;
  double h;
  int i;
  int n_test;
  double r;

  n_test = 6;

  r = 2.0;

  printf ( "\n" );
  printf ( "CIRCLE_LUNE_ANGLE_BY_HEIGHT_2D_TEST\n" );
  printf ( "  CIRCLE_LUNE_ANGLE_BY_HEIGHT_2D computes the angle of a\n" );
  printf ( "  circular lune based on the 'height' of the circular triangle.\n" );
  printf ( "\n" );
  printf ( "      R            H        Angle\n" );
  printf ( "\n" );

  for ( i = -n_test; i <= n_test; i++ )
  {
    h = ( double ) ( i ) * r / ( double ) ( n_test );

    angle = circle_lune_angle_by_height_2d ( r, h );

    printf ( "  %10f  %10f  %10f\n", r, h, angle );
  }

  return;
}
/******************************************************************************/

void circle_lune_area_by_angle_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLE_LUNE_AREA_BY_ANGLE_2D_TEST tests CIRCLE_LUNE_AREA_BY_ANGLE_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 January 2018

  Author:

    John Burkardt
*/
{
  double area;
  double pc[2] = { 0.0, 0.0 };
  double r = 1.0;
  double r8_pi = 3.141592653589793;
  int test;
  int test_num = 12;
  double theta1;
  double theta2;

  printf ( "\n" );
  printf ( "CIRCLE_LUNE_AREA_BY_ANGLE_2D_TEST\n" );
  printf ( "  CIRCLE_LUNE_AREA_BY_ANGLE_2D computes the area of a\n" );
  printf ( "  circular lune, defined by joining the endpoints\n" );
  printf ( "  of a circular arc.\n" );
  printf ( "\n" );
  printf ( "      R            Theta1      Theta2        Area\n" );
  printf ( "\n" );

  for ( test = 0; test <= test_num; test++ )
  {
    theta1 = 0.0;
    theta2 = ( double ) ( test ) * 2.0 * r8_pi / ( double ) ( test_num );

    area = circle_lune_area_by_angle_2d ( r, pc, theta1, theta2 );

    printf ( "  %6f  %12f  %12f  %12f\n", r, theta1, theta2, area  );
  }

  return;
}
/******************************************************************************/

void circle_lune_area_by_height_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLE_LUNE_AREA_BY_HEIGHT_2D_TEST tests CIRCLE_LUNE_AREA_BY_HEIGHT_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 January 2018

  Author:

    John Burkardt
*/
{
  double area;
  double h;
  int i;
  int n_test = 6;
  double r = 2.0;

  printf ( "\n" );
  printf ( "CIRCLE_LUNE_AREA_BY_HEIGHT_2D_TEST\n" );
  printf ( "  CIRCLE_LUNE_AREA_BY_HEIGHT_2D computes the area of a\n" );
  printf ( "  circular lune, defined by joining the endpoints\n" );
  printf ( "  of a circular arc.\n" );
  printf ( "\n" );
  printf ( "      R            Height        Area\n" );
  printf ( "\n" );

  for ( i = - n_test; i <= n_test; i++ )
  {
    h = ( double ) ( i ) * r / ( double ) ( n_test );

    area = circle_lune_area_by_height_2d ( r, h );

    printf ( "  %6f  %12f  %12f\n", r, h, area );
  }

  return;
}
/******************************************************************************/

void circle_lune_height_by_angle_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLE_LUNE_HEIGHT_BY_ANGLE_2D_TEST tests CIRCLE_LUNE_HEIGHT_BY_ANGLE_2D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 January 2018

  Author:

    John Burkardt
*/
{
  double angle;
  double height;
  int i;
  int n_test;
  double r;
  double r8_pi = 3.141592653589793;

  n_test = 12;

  r = 2.0;

  printf ( "\n" );
  printf ( "CIRCLE_LUNE_HEIGHT_BY_ANGLE_2D_TEST\n" );
  printf ( "  CIRCLE_LUNE_HEIGHT_BY_ANGLE_2D computes the height of\n" );
  printf ( "  the triangle of a circular lune, given the subtended angle.\n" );
  printf ( "\n" );
  printf ( "      R            Angle        Height\n" );
  printf ( "\n" );

  for ( i = 0; i <= n_test; i++ )
  {
    angle = ( double ) ( i ) * 2.0 * r8_pi / ( double ) ( n_test );

    height = circle_lune_height_by_angle_2d ( r, angle );

    printf ( "  %10f  %10f  %10f\n", r, angle, height );
  }

  return;
}
/******************************************************************************/

void circle_sector_area_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLE_SECTOR_AREA_2D_TEST tests CIRCLE_SECTOR_AREA_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 January 2018

  Author:

    John Burkardt
*/
{
  double area;
  double pc[2] = { 0.0, 0.0 };
  double r8_pi = 3.141592653589793;
  double r = 1.0;
  int test;
  int test_num = 12;
  double theta1;
  double theta2;

  printf ( "\n" );
  printf ( "CIRCLE_SECTOR_AREA_2D_TEST\n" );
  printf ( "  CIRCLE_SECTOR_AREA_2D computes the area of a\n" );
  printf ( "  circular sector, defined by joining the endpoints\n" );
  printf ( "  of a circular arc to the center.\n" );
  printf ( "\n" );
  printf ( "      R            Theta1      Theta2        Area\n" );
  printf ( "\n" );

  for ( test = 0; test <= test_num; test++ )
  {
    theta1 = 0.0;
    theta2 = ( double ) ( test ) * 2.0 * r8_pi / ( double ) ( test_num );

    area = circle_sector_area_2d ( r, pc, theta1, theta2 );

    printf ( "  %6f  %12f  %12f  %12f\n", r, theta1, theta2, area );
  }

  return;
}
/******************************************************************************/

void circle_triangle_area_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLE_TRIANGLE_AREA_2D_TEST tests CIRCLE_TRIANGLE_AREA_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 January 2018

  Author:

    John Burkardt
*/
{
  double area;
  double pc[2] = { 0.0, 0.0 };
  double r8_pi = 3.141592653589793;
  double r = 1.0;
  int test;
  int test_num = 12;
  double theta1;
  double theta2;

  printf ( "\n" );
  printf ( "CIRCLE_TRIANGLE_AREA_2D_TEST\n" );
  printf ( "  CIRCLE_TRIANGLE_AREA_2D computes the signed area of a\n" );
  printf ( "  triangle, defined by joining the endpoints\n" );
  printf ( "  of a circular arc and the center.\n" );
  printf ( "\n" );
  printf ( "      R            Theta1      Theta2        Area\n" );
  printf ( "\n" );

  for ( test = 0; test <= test_num; test++ )
  {
    theta1 = 0.0;
    theta2 = ( double ) ( test ) * 2.0 * r8_pi / ( double ) ( test_num );

    area = circle_triangle_area_2d ( r, pc, theta1, theta2 );

    printf ( "  %6f  %12f  %12f  %12f\n", r, theta1, theta2, area );
  }

  return;
}
/******************************************************************************/

void circles_intersect_area_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLES_INTERSECT_AREA_2D_TEST tests CIRCLES_INTERSECT_AREA_2D;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 January 2018

  Author:

    John Burkardt
*/
{
  double area;
  double d;
  double d_test[6] =  { 1.5, 1.0, 0.5, 1.5, 1.0, 0.0 };
  int i;
  int ntest = 6;
  double r1;
  double r1_test[6] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
  double r2;
  double r2_test[6] = { 0.5, 0.5, 0.5, 1.0, 1.0, 1.0 };

  printf ( "\n" );
  printf ( "CIRCLES_INTERSECT_AREA_2D_TEST\n" );
  printf ( "  CIRCLES_INTERSECT_AREA_2D determines the area of the\n" );
  printf ( "  intersection of two circes of radius R1 and R2,\n" );
  printf ( "  with a distance D between the centers.\n" );
  printf ( "\n" );
  printf ( "      R1      R2       D    Area\n" );
  printf ( "\n" );

  for ( i = 0; i < ntest; i++ )
  {
    r1 = r1_test[i];
    r2 = r2_test[i];
    d = d_test[i];
    area = circles_intersect_area_2d ( r1, r2, d );

    printf ( "  %6f  %6f  %6f  %6f\n", r1, r2, d, area );
  }

  return;
}
/******************************************************************************/

void circles_intersect_points_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCLES_INTERSECT_POINTS_2D_TEST tests CIRCLES_INTERSECT_POINTS_2D;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 January 2018

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2
# define TEST_NUM 5

  int int_num;
  double pint[DIM_NUM*2];
  double pc1[DIM_NUM] = { 0.0, 0.0 };
  double *pc2;
  double pc2_test[DIM_NUM*TEST_NUM] = {
    5.0,       5.0,
    7.0710678, 7.0710678,
    4.0,       0.0,
    6.0,       0.0,
    0.0,       0.0 };
  double r1 = 5.0;
  double r2;
  double r2_test[TEST_NUM] = { 0.5, 5.0, 3.0, 3.0, 5.0 };
  int test;

  printf ( "\n" );
  printf ( "CIRCLES_INTERSECT_POINTS_2D_TEST\n" );
  printf ( "  CIRCLES_IMP_INT_2D determines the intersections of\n" );
  printf ( "  two circles in 2D.\n" );

  circle_imp_print_2d ( r1, pc1, "  The first circle:" );

  for ( test = 0; test < TEST_NUM; test++ )
  {
    r2 = r2_test[test];
    pc2 = pc2_test + test*DIM_NUM;

    circle_imp_print_2d ( r2, pc2, "  The second circle:" );

    circles_intersect_points_2d ( r1, pc1, r2, pc2, &int_num, pint );

    if ( int_num == 0 )
    {
      printf ( "\n" );
      printf ( "  The circles do not intersect.\n" );
    }
    else if ( int_num == 1 )
    {
      printf ( "\n" );
      printf ( "  The circles intersect at one point:\n" );
      printf ( "\n" );
      printf ( "        P\n" );
      printf ( "\n" );
      printf ( "  %8f  %8f\n", pint[0+0*DIM_NUM], pint[1+0*DIM_NUM] );
    }
    else if ( int_num == 2 )
    {
      printf ( "\n" );
      printf ( "  The circles intersect at two points:\n" );
      printf ( "\n" );
      printf ( "        P\n" );
      printf ( "\n" );
      printf ( "  %8f  %8f\n", pint[0+0*DIM_NUM], pint[1+0*DIM_NUM] );
      printf ( "  %8f  %8f\n", pint[0+1*DIM_NUM], pint[1+1*DIM_NUM] );
    }
    else if ( int_num == 3 )
    {
      printf ( "\n" );
      printf ( "  The circles coincide (infinite intersection).\n" );
    }
  }

  return;
# undef DIM_NUM
# undef TEST_NUM
}
/******************************************************************************/

void cube01_volume_test ( )

/******************************************************************************/
/*
  Purpose:

    CUBE01_VOLUME_TEST tests CUBE01_VOLUME.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2018

  Author:

    John Burkardt
*/
{
  double volume;

  printf ( "\n" );
  printf ( "CUBE01_VOLUME_TEST\n" );
  printf ( "  CUBE01_VOLUME returns the volume of the unit cube.\n" );

  volume = cube01_volume ( );

  printf ( "\n" );
  printf ( "  Volume = %g\n", volume );

  return;
}
/******************************************************************************/

void ellipse_area1_test ( )

/******************************************************************************/
/*
  Purpose:

    ELLIPSE_AREA1_TEST tests ELLIPSE_AREA1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 November 2016

  Author:

    John Burkardt
*/
{
  double a[2*2] = { 5.0, 1.0, 1.0, 2.0 };
  double area;
  double r;

  printf ( "\n" );
  printf ( "ELLIPSE_AREA1_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  ELLIPSE_AREA1 computes the area of an ellipse.\n" );

  r = 10.0;

  area = ellipse_area1 ( a, r );

  printf ( "\n" );
  printf ( "  R = %g\n", r );
  r8mat_print ( 2, 2, a, "  Matrix A in ellipse definition x*A*x=r^2" );
  printf ( "  Area = %g\n", area );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ELLIPSE_AREA1_TEST\n" );
  printf ( "  Normal end of execution.\n" );

  return;
}
/******************************************************************************/

void ellipse_area2_test ( )

/******************************************************************************/
/*
  Purpose:

    ELLIPSE_AREA2_TEST tests ELLIPSE_AREA2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 November 2016

  Author:

    John Burkardt
*/
{
  double a;
  double area;
  double b;
  double c;
  double d;
 
  printf ( "\n" );
  printf ( "ELLIPSE_AREA2_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  ELLIPSE_AREA2 computes the area of an ellipse.\n" );

  a = 5.0;
  b = 2.0;
  c = 2.0;
  d = 10.0;

  area = ellipse_area2 ( a, b, c, d );

  printf ( "\n" );
  printf ( "  Ellipse: %g * x^2 + %g * xy + %g * y^2 = %g\n", a, b, c, d );
  printf ( "  Area = %g\n", area );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ELLIPSE_AREA2_TEST\n" );
  printf ( "  Normal end of execution.\n" );

  return;
}
/******************************************************************************/

void ellipse_area3_test ( )

/******************************************************************************/
/*
  Purpose:

    ELLIPSE_AREA3_TEST tests ELLIPSE_AREA3.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 November 2016

  Author:

    John Burkardt
*/
{
  double area;
  double r1;
  double r2;
 
  printf ( "\n" );
  printf ( "ELLIPSE_AREA3_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  ELLIPSE_AREA3 computes the area of an ellipse.\n" );

  r1 = 10.0;
  r2 = 10.0 / 3.0;

  area = ellipse_area3 ( r1, r2 );

  printf ( "\n" );
  printf ( "  Ellipse: (x/%g)^2 + (y/%g)^2 = 1\n", r1, r2 );
  printf ( "  Area = %g\n", area );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ELLIPSE_AREA3_TEST\n" );
  printf ( "  Normal end of execution.\n" );

  return;
}
/******************************************************************************/

void ellipse_eccentricity_test ( )

/******************************************************************************/
/*
  Purpose:

    ellipse_eccentricity_test tests ellipse_eccentricity().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 March 2021

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double e;
  int i;
  int n;
 
  printf ( "\n" );
  printf ( "ellipse_eccentricity_test:\n" );
  printf ( "  C version\n" );
  printf ( "  ellipse_eccentricity computes the eccentricity of an ellipse.\n" );

  printf ( "\n" );
  printf ( "      A      B      Ecc\n" );
  printf ( "\n" );
  a = 1.0;
  n = 10;
  for ( i = 0; i <= n; i++ )
  {
    b = ( double ) ( i ) / ( double ) ( n );
    e = ellipse_eccentricity ( a, b );
    printf ( "  %5.1f  %5.1f  %10.6f\n", a, b, e );
  }
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ellipse_eccentricity_test\n" );
  printf ( "  Normal end of execution.\n" );

  return;
}
/******************************************************************************/

void line_par_point_dist_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    LINE_PAR_POINT_DIST_2D_TEST tests LINE_PAR_POINT_DIST_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2013

  Author:

    John Burkardt
*/
{
# define TEST_NUM 3

  double dist;
  double f;
  double g;
  int i;
  double p[2];
  double p_test[2*TEST_NUM] = {
    0.0,  0.0,
    5.0, -1.0,
    5.0,  3.0 };
  int test;
  int test_num = TEST_NUM;
  double x0;
  double y0;

  printf ( "\n" );
  printf ( "LINE_PAR_POINT_DIST_2D_TEST\n" );
  printf ( "  LINE_PAR_POINT_DIST_2D finds the distance between\n" );
  printf ( "  a parametric line (X0,Y0,F,G) and a point P in 2D.\n" );

  x0 = 1.0;
  y0 = 3.0;
  f = +1.0;
  g = -1.0;

  printf ( "\n" );
  printf ( "  Parametric line:\n" );
  printf ( "  X(t) = %g + %g * t\n", x0, f );
  printf ( "  Y(t) = %g + %g * t\n", y0, g );

  for ( test = 0; test < test_num; test++ )
  {
    for ( i = 0; i < 2; i++ )
    {
      p[i] = p_test[i+test*2];
    }

    r8vec_print ( 2, p, "  The point P:" );

    dist = line_par_point_dist_2d ( f, g, x0, y0, p );

    printf ( "  Distance = %g\n", dist );
  }
  return;
# undef TEST_NUM
}
/******************************************************************************/

void line_par_point_near_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    LINE_PAR_POINT_NEAR_2D_TEST tests LINE_PAR_POINT_NEAR_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2013

  Author:

    John Burkardt
*/
{
# define TEST_NUM 3

  double dist;
  double f;
  double g;
  int i;
  double p[2];
  double *pn;
  double p_test[2*TEST_NUM] = {
    0.0,  0.0,
    5.0, -1.0,
    5.0,  3.0 };
  int test;
  int test_num = TEST_NUM;
  double x0;
  double y0;

  printf ( "\n" );
  printf ( "LINE_PAR_POINT_NEAR_2D_TEST\n" );
  printf ( "  LINE_PAR_POINT_NEAR_2D finds the point on\n" );
  printf ( "  a parametric line (X0,Y0,F,G) nearest a point P in 2D.\n" );

  x0 = 1.0;
  y0 = 3.0;
  f = +1.0;
  g = -1.0;

  printf ( "\n" );
  printf ( "  Parametric line:\n" );
  printf ( "  X(t) = %g + %g * t\n", x0, f );
  printf ( "  Y(t) = %g + %g * t\n", y0, g );

  for ( test = 0; test < test_num; test++ )
  {
    for ( i = 0; i < 2; i++ )
    {
      p[i] = p_test[i+test*2];
    }

    r8vec_print ( 2, p, "  The point P:" );

    pn = line_par_point_near_2d ( f, g, x0, y0, p );

    r8vec_print ( 2, pn, "  Nearest point PN:" );

    dist = r8vec_norm_affine ( 2, p, pn );

    printf ( "  Distance = %g\n", dist );

    free ( pn );
  }
  return;
# undef TEST_NUM
}
/******************************************************************************/

void line_par_point_dist_3d_test ( )

/******************************************************************************/
/*
  Purpose:

    LINE_PAR_POINT_DIST_3D_TEST tests LINE_PAR_POINT_DIST_3D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2013

  Author:

    John Burkardt
*/
{
# define TEST_NUM 3

  double dist;
  double f;
  double g;
  double h;
  int i;
  double p[3];
  double p_test[3*TEST_NUM] = {
    0.0,  0.0, 2.0, 
    5.0, -1.0, 1.0, 
    5.0,  3.0, 3.0 };
  int test;
  int test_num = TEST_NUM;
  double x0;
  double y0;
  double z0;

  printf ( "\n" );
  printf ( "LINE_PAR_POINT_DIST_3D_TEST\n" );
  printf ( "  LINE_PAR_POINT_DIST_3D finds the distance\n" );
  printf ( "  from a parametric line to a point in 3D.\n" );

  x0 = 1.0;
  y0 = 3.0;
  z0 = 2.0;

  f = +3.0;
  g = -3.0;
  h = -1.0;

  printf ( "\n" );
  printf ( "  Parametric line:\n" );
  printf ( "  X(t) = %g + %g * t\n", x0, f );
  printf ( "  Y(t) = %g + %g * t\n", y0, g );
  printf ( "  Z(t) = %g + %g * t\n", z0, h );

  for ( test = 0; test < test_num; test++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      p[i] = p_test[i+test*3];
    }

    r8vec_print ( 3, p, "  The point P:" );

    dist = line_par_point_dist_3d ( f, g, h, x0, y0, z0, p );

    printf ( "  Distance = %g\n", dist );
  }
  return;
# undef TEST_NUM
}
/******************************************************************************/

void line_par_point_near_3d_test ( )

/******************************************************************************/
/*
  Purpose:

    LINE_PAR_POINT_NEAR_3D_TEST tests LINE_PAR_POINT_NEAR_3D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 April 2013

  Author:

    John Burkardt
*/
{
# define TEST_NUM 3

  double dist;
  double f;
  double g;
  double h;
  int i;
  double p[3];
  double *pn;
  double p_test[3*TEST_NUM] = {
    0.0,  0.0, 2.0, 
    5.0, -1.0, 1.0, 
    5.0,  3.0, 3.0 };
  int test;
  int test_num = TEST_NUM;
  double x0;
  double y0;
  double z0;

  printf ( "\n" );
  printf ( "LINE_PAR_POINT_NEAR_3D_TEST\n" );
  printf ( "  LINE_PAR_POINT_NEAR_3D finds the nearest point on\n" );
  printf ( "  a parametric line to a point in 3D.\n" );

  x0 = 1.0;
  y0 = 3.0;
  z0 = 2.0;

  f = +3.0;
  g = -3.0;
  h = -1.0;

  printf ( "\n" );
  printf ( "  Parametric line:\n" );
  printf ( "  X(t) = %g + %g * t\n", x0, f );
  printf ( "  Y(t) = %g + %g * t\n", y0, g );
  printf ( "  Z(t) = %g + %g * t\n", z0, h );

  for ( test = 0; test < test_num; test++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      p[i] = p_test[i+test*3];
    }

    r8vec_print ( 3, p, "  The point P:" );

    pn = line_par_point_near_3d ( f, g, h, x0, y0, z0, p );

    r8vec_print ( 3, pn, "  Nearest point PN:" );

    dist = r8vec_norm_affine ( 3, p, pn );

    printf ( "  Distance = %g\n", dist );

    free ( pn );
  }
  return;
# undef TEST_NUM
}
/******************************************************************************/

void parallelogram_area_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    PARALLELOGRAM_AREA_2D_TEST tests PARALLELOGRAM_AREA_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 May 2010

  Author:

    John Burkardt
*/
{
  double area;
  double p[2*4] = {
    2.0, 7.0, 
    5.0, 7.0, 
    6.0, 9.0, 
    3.0, 9.0 };

  printf ( "\n" );
  printf ( "PARALLELOGRAM_AREA_2D_TEST\n" );
  printf ( "  PARALLELOGRAM_AREA_2D finds the area of a\n" );
  printf ( "  parallelogram in 2D.\n" );

  r8mat_transpose_print ( 2, 4, p, "  Vertices:" );

  area = parallelogram_area_2d ( p );

  printf ( "\n" );
  printf ( "  AREA = %f\n", area );

  return;
}
/******************************************************************************/

void parallelogram_area_3d_test ( )

/******************************************************************************/
/*
  Purpose:

    PARALLELOGRAM_AREA_3D_TEST tests PARALLELOGRAM_AREA_3D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 May 2010

  Author:

    John Burkardt
*/
{
  double area;
  double p[3*4] = {
    1.0,       2.0,       3.0, 
    2.4142137, 3.4142137, 3.0, 
    1.7071068, 2.7071068, 4.0, 
    0.2928931, 0.2928931, 4.0 };

  printf ( "\n" );
  printf ( "PARALLELOGRAM_AREA_3D_TEST\n" );
  printf ( "  PARALLELOGRAM_AREA_3D finds the area of a\n" );
  printf ( "  parallelogram in 3D.\n" );

  r8mat_transpose_print ( 3, 4, p, "  Vertices:" );

  area = parallelogram_area_3d ( p );

  printf ( "\n" );
  printf ( "  AREA = %f\n", area );

  return;
}
/******************************************************************************/

void plane_normal_qr_to_xyz_test ( )

/******************************************************************************/
/*
  Purpose:

    PLANE_NORMAL_QR_TO_XYZ_TEST tests PLANE_NORMAL_QR_TO_XYZ.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 November 2010

  Author:

    John Burkardt
*/
{
  double dif;
  int i;
  int j;
  int m = 3;
  int n = 5;
  double *normal;
  double *pp;
  double pq[3];
  double pr[3];
  double *qr1;
  double *qr2;
  int seed;
  double t;
  double *xyz;

  seed = 123456789;

  printf ( "\n" );
  printf ( "PLANE_NORMAL_QR_TO_XYZ_TEST\n" );
  printf ( "  PLANE_NORMAL_QR_TO_XYZ converts QR to XYZ coordinates\n" );
  printf ( "  for a normal plane, with point PP and NORMAL vector,\n" );
  printf ( "  and in-plane basis vectors PQ and PR,\n" );
/*
  Choose PP and NORMAL at random.
*/
  pp = r8vec_uniform_01_new ( m, &seed );

  normal = r8vec_uniform_01_new ( m, &seed );
/*
  Compute in-plane basis vectors PQ and PR.
*/
  plane_normal_basis_3d ( pp, normal, pq, pr );
/*
  Choose random Q, R coordinates.
*/
  qr1 = r8mat_uniform_01_new ( m - 1, n, &seed );
/*
  Convert to XYZ.
*/
  xyz = plane_normal_qr_to_xyz ( pp, normal, pq, pr, n, qr1 );
/*
  Convert XYZ to QR.
*/
  qr2 = plane_normal_xyz_to_qr ( pp, normal, pq, pr, n, xyz );

  dif = 0.0;
  for ( j = 0; j < n; j++ )
  {
    t = 0.0;
    for ( i = 0; i < m - 1; i++ )
    {
      t = t + pow ( qr1[0+j*2] - qr2[0+j*2], 2 );
    }
    t = sqrt ( t );
    dif = r8_max ( dif, t );
  }

  printf ( "\n" );
  printf ( "  Maximum difference was %f\n", dif );

  free ( normal );
  free ( pp );
  free ( qr1 );
  free ( qr2 );
  free ( xyz );

  return;
}
/******************************************************************************/

void plane_normal_xyz_to_qr_test ( )

/******************************************************************************/
/*
  Purpose:

    PLANE_NORMAL_XYZ_TO_QR_TEST tests PLANE_NORMAL_XYZ_TO_QR.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 November 2010

  Author:

    John Burkardt
*/
{
  double dif;
  int i;
  int j;
  int m = 3;
  int n = 5;
  double *normal;
  double *pp;
  double pq[3];
  double pr[3];
  double *qr1;
  double *qr2;
  int seed;
  double t;
  double *xyz;

  seed = 123456789;

  printf ( "\n" );
  printf ( "PLANE_NORMAL_XYZ_TO_QR_TEST\n" );
  printf ( "  PLANE_NORMAL_XYZ_TO_QR converts XYZ to QR coordinates\n" );
  printf ( "  for a normal plane, with point PP and NORMAL vector,\n" );
  printf ( "  and in-plane basis vectors PQ and PR,\n" );
/*
  Choose PP and NORMAL at random.
*/
  pp = r8vec_uniform_01_new ( m, &seed );

  normal = r8vec_uniform_01_new ( m, &seed );
/*
  Compute in-plane basis vectors PQ and PR.
*/
  plane_normal_basis_3d ( pp, normal, pq, pr );
/*
  Choose random Q, R coordinates.
*/
  qr1 = r8mat_uniform_01_new ( m - 1, n, &seed );
/*
  Convert to XYZ.
*/
  xyz = plane_normal_qr_to_xyz ( pp, normal, pq, pr, n, qr1 );
/*
  Convert XYZ to QR.
*/
  qr2 = plane_normal_xyz_to_qr ( pp, normal, pq, pr, n, xyz );

  dif = 0.0;
  for ( j = 0; j < n; j++ )
  {
    t = 0.0;
    for ( i = 0; i < m - 1; i++ )
    {
      t = t + pow ( qr1[0+j*2] - qr2[0+j*2], 2 );
    }
    t = sqrt ( t );
    dif = r8_max ( dif, t );
  }

  printf ( "\n" );
  printf ( "  Maximum difference was %f\n", dif );

  free ( normal );
  free ( pp );
  free ( qr1 );
  free ( qr2 );
  free ( xyz );

  return;
}
/******************************************************************************/

void plane_normal_tetrahedron_intersect_test ( )

/******************************************************************************/
/*
  Purpose:

    PLANE_NORMAL_TETRAHEDRON_INTERSECT_TEST tests PLANE_NORMAL_TETRAHEDRON_INTERSECT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 June 2010

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  int l;
  int int_num;
  double normal[3];
  double pint[3*4];
  double pp[3];
  double t[3*4] = {
    0.0, 0.0, 0.0, 
    1.0, 0.0, 0.0, 
    0.0, 1.0, 0.0, 
    0.0, 0.0, 1.0 };

  fprintf ( stdout, "\n" );
  fprintf ( stdout, "PLANE_NORMAL_TETRAHEDRON_INTERSECT_TEST\n" );
  fprintf ( stdout, "  PLANE_NORMAL_TETRAHEDRON_INTERSECT determines\n" );
  fprintf ( stdout, "  the intersection of a plane and tetrahedron.\n" );

  for ( k = 1; k <= 2; k++ )
  {
    if ( k == 1 )
    {
      normal[0] = 0.0;
      normal[1] = 0.0;
      normal[2] = 1.0;
    }
    else
    {
      normal[0] = 1.0 / sqrt ( 2.0 );
      normal[1] = 1.0 / sqrt ( 2.0 );
      normal[2] = 0.0;
    }

    fprintf ( stdout, "\n" );
    fprintf ( stdout, "  Plane normal vector number %d\n", k );
    fprintf ( stdout, "\n" );
    for ( i = 0; i < 3; i++ )
    {
      fprintf ( stdout, "  %f", normal[i] );
    }
    fprintf ( stdout, "\n" );

    for ( l = 0; l <= 6; l++ )
    {
      for ( i = 0; i < 3; i++ )
      {
        pp[i] = normal[i] * ( double ) ( l ) / 5.0;
      }
      plane_normal_tetrahedron_intersect ( pp, normal, t, &int_num, pint );

      fprintf ( stdout, "\n" );
      fprintf ( stdout, "  Point on plane:\n" );
      fprintf ( stdout, "\n" );
      for ( i = 0; i < 3; i++ )
      {
        fprintf ( stdout, "  %f", pp[i] );
      }
      fprintf ( stdout, "\n" );
      fprintf ( stdout, "\n" );
      fprintf ( stdout, "  Number of intersection points = %d\n", int_num );
      fprintf ( stdout, "\n" );
      for ( j = 0; j < int_num; j++ )
      {
        fprintf ( stdout, "  %4d", j );
        for ( i = 0; i < 3; i++ )
        {
          fprintf ( stdout, "  %f", pint[i+j*3] );
        }
        fprintf ( stdout, "\n" );
      }
    }
  }
  return;
}
/******************************************************************************/

void polygon_contains_point_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    polygon_contains_point_2d_test tests polygon_contains_point_2d().

  Discussion:

    x-x-x-x-x-x-x
    |i          |
    x x-x-x-x-x-x
    | |o
    x x x-x-x-x x
    | | |i    |
    x x x x-x x x
    | | | |o| |
    x x x-x x x x
    | |     |i|
    x x-x-x-x x x
    |         |o
    x-x-x-x-x-x x

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 September 2020

  Author:

    John Burkardt
*/
{
  int dim_num = 2;
  bool inside;
  int nv = 14;
  double p[2];
  double p_test[2*6] = {
    0.5, 5.5,
    1.5, 4.5,
    2.5, 3.5,
    3.5, 2.5,
    4.5, 1.5,
    5.5, 0.5 };
  int test;
  int test_num = 6;
  double v[2*14] = {
    0.0, 0.0,
    5.0, 0.0,
    5.0, 4.0,
    2.0, 4.0,
    2.0, 2.0,
    3.0, 2.0,
    3.0, 3.0,
    4.0, 3.0,
    4.0, 1.0,
    1.0, 1.0,
    1.0, 5.0,
    6.0, 5.0,
    6.0, 6.0,
    0.0, 6.0 };

  printf ( "\n" );
  printf ( "polygon_contains_point_2d_test\n" );
  printf ( "  polygon_contains_point_2d determines if \n" );
  printf ( "  a point is in a polygon.\n" );
 
  r8mat_transpose_print ( dim_num, nv, v, "  The polygon vertices:" );

  printf ( "\n" );
  printf ( "          P               Inside?\n" );
  printf ( "\n" );

  for ( test = 0; test < test_num; test++ )
  {
    p[0] = p_test[0+test*2];
    p[1] = p_test[1+test*2];
 
    inside = polygon_contains_point_2d ( nv, v, p );
 
    printf ( "  %12.4g  %12.4g  %d\n", p[0], p[1], inside );
  }

  return;
}
/******************************************************************************/

void polygon_contains_point_2d_convex_test ( )

/******************************************************************************/
/*
  Purpose:

    polygon_contains_point_2d_convex_test tests polygon_contains_point_2d_convex().

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 September 2020.

  Author:

    John Burkardt
*/
{
  int dim_num = 2;
  bool inside;
  int n = 5;
  double *p;
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
  printf ( "polygon_contains_point_2d_convex_test\n" );
  printf ( "  polygon_contains_point_2d_convex() determines if \n" );
  printf ( "  a point is inside a convex polygon.\n" );
 
  r8mat_transpose_print ( dim_num, n, v, "  The polygon vertices:" );

  printf ( "\n" );
  printf ( "          P          Inside?\n" );
  printf ( "\n" );

  for ( test = 0; test < test_num; test++ )
  {
    p = p_test + dim_num * test;

    printf ( "  %12.4g  %12.4g", p[0], p[1] );

    inside = polygon_contains_point_2d_convex ( n, v, p );

    printf ( "  %d\n", inside );
  }

  return;
}
/******************************************************************************/

void polygon_contains_point_2d_3_test ( )

/******************************************************************************/
/*
  Purpose:

    POLYGON_CONTAINS_POINT_2D_3_TEST tests POLYGON_CONTAINS_POINT_2D_3.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 November 2016

  Author:

    John Burkardt
*/
{
  int dim_num = 2;
  bool inside;
  int n = 5;
  double *p;
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
  printf ( "POLYGON_CONTAINS_POINT_2D_3_TEST\n" );
  printf ( "  POLYGON_CONTAINS_POINT_2D_3 determines if \n" );
  printf ( "  a point is in a polygon.\n" );
 
  r8mat_transpose_print ( dim_num, n, v, "  The polygon vertices:" );

  printf ( "\n" );
  printf ( "          P          Inside\n" );
  printf ( "\n" );

  for ( test = 0; test < test_num; test++ )
  {
    p = p_test + dim_num * test;

    printf ( "  %12.4g  %12.4g", p[0], p[1] );

    inside = polygon_contains_point_2d_3 ( n, v, p );

    printf ( "  %d\n", inside );
  }

  return;
}
/******************************************************************************/

void quad_area_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    QUAD_AREA_2D_TEST tests QUAD_AREA_2D;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 May 2010

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2

  double area;
  double quad[DIM_NUM*4] = {
    0.0, 0.0,
    1.0, 0.0,
    1.0, 1.0,
    0.0, 1.0 };

  printf ( "\n" );
  printf ( "QUAD_AREA_2D_TEST\n" );
  printf ( "  QUAD_AREA_2D finds the area of a quadrilateral;\n" );

  r8mat_transpose_print ( DIM_NUM, 4, quad, "  The vertices:" );

  area = quad_area_2d ( quad );

  printf ( "\n" );
  printf ( "  QUAD_AREA_2D area is  %f\n", area );

  return;
# undef DIM_NUM
}
/******************************************************************************/

void quad_area2_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    QUAD_AREA2_2D_TEST tests QUAD_AREA2_2D;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 May 2010

  Author:

    John Burkardt
*/
{
# define DIM_NUM 2

  double area;
  double quad[DIM_NUM*4] = {
    0.0, 0.0,
    1.0, 0.0,
    1.0, 1.0,
    0.0, 1.0 };

  printf ( "\n" );
  printf ( "QUAD_AREA2_2D_TEST\n" );
  printf ( "  QUAD_AREA2_2D finds the area of a quadrilateral.\n" );

  r8mat_transpose_print ( DIM_NUM, 4, quad, "  The vertices:" );

  area = quad_area2_2d ( quad );

  printf ( "\n" );
  printf ( "  QUAD_AREA2_2D area is %f\n", area );

  return;
# undef DIM_NUM
}
/******************************************************************************/

void quad_area_3d_test ( )

/******************************************************************************/
/*
  Purpose:

    QUAD_AREA_3D_TEST tests QUAD_AREA_3D;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 May 2010

  Author:

    John Burkardt
*/
{
  double area;
  double area1;
  double area2;
  int i;
  int j;
  double q[3*4] = {
    2.0, 2.0, 0.0, 
    0.0, 0.0, 0.0, 
    1.0, 1.0, 1.0, 
    3.0, 3.0, 1.0 };
  double t[3*3];

  printf ( "\n" );
  printf ( "QUAD_AREA_3D_TEST\n" );
  printf ( "  For a quadrilateral in 3D:\n" );
  printf ( "  QUAD_AREA_3D finds the area.\n" );

  r8mat_transpose_print ( 3, 4, q, "  The vertices:");

  area = quad_area_3d ( q );

  printf ( "\n" );
  printf ( "  QUAD_AREA_3D area is     %f\n", area );

  for ( j = 0; j < 3; j++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      t[i+j*3] = q[i+j*3];
    }
  }
  area1 = triangle_area_3d ( t );
  for ( j = 0; j < 2; j++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      t[i+j*3] = q[i+(j+2)*3];
    }
  }
  for ( i = 0; i < 3; i++ )
  {
    t[i+2*3] = q[i+0*3];
  }
  area2 = triangle_area_3d ( t );
  printf ( "  Sum of TRIANGLE_AREA_3D: %f\n", area1 + area2 );

  return;
}
/******************************************************************************/

void sphere_exp2imp_3d_test ( )

/******************************************************************************/
/*
  Purpose:

    SPHERE_EXP2IMP_3D_TEST tests SPHERE_EXP2IMP_3D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 July 2011

  Author:

    John Burkardt
*/
{
# define DIM_NUM 3

  int i;
  double pc[DIM_NUM] = {  1.0, 2.0, 3.0 };
  double p1[DIM_NUM] = {  4.0, 2.0, 3.0 };
  double p2[DIM_NUM] = {  1.0, 5.0, 3.0 };
  double p3[DIM_NUM] = {  1.0, 2.0, 6.0 };
  double p4[DIM_NUM] = { -2.0, 2.0, 3.0 };
  double r = 3.0;

  printf ( "\n" );
  printf ( "SPHERE_EXP2IMP_3D_TEST\n" );
  printf ( "  SPHERE_EXP2IMP_3D: explicit sphere => implicit form;\n" );

  printf ( "\n" );
  printf ( "  Initial form of explicit sphere:\n" );
  printf ( "\n" );
  printf ( "  P1:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p1[i] );
  }
  printf ( "\n" );
  printf ( "  P2:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p2[i] );
  }
  printf ( "\n" );
  printf ( "  P3:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p3[i] );
  }
  printf ( "\n" );
  printf ( "  P4:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p4[i] );
  }
  printf ( "\n" );

  sphere_exp2imp_3d ( p1, p2, p3, p4, &r, pc );

  printf ( "\n" );
  printf ( "  Computed form of implicit sphere:\n" );
  printf ( "\n" );
  printf ( "  Imputed radius = %f\n", r );

  r8vec_print ( DIM_NUM, pc, "  Imputed center:" );

  sphere_imp2exp_3d ( r, pc, p1, p2, p3, p4 );

  printf ( "\n" );
  printf ( "  Computed form of explicit sphere:\n" );
  printf ( "\n" );
  printf ( "  P1:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p1[i] );
  }
  printf ( "\n" );
  printf ( "  P2:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p2[i] );
  }
  printf ( "\n" );
  printf ( "  P3:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p3[i] );
  }
  printf ( "\n" );
  printf ( "  P4:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p4[i] );
  }
  printf ( "\n" );

  return;
# undef DIM_NUM
}
/******************************************************************************/

void sphere_imp2exp_3d_test ( )

/******************************************************************************/
/*
  Purpose:

    SPHERE_IMP2EXP_3D_TEST tests SPHERE_IMP2EXP_3D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 July 2011

  Author:

    John Burkardt
*/
{
# define DIM_NUM 3

  int i;
  double pc[DIM_NUM] = {  1.0, 2.0, 3.0 };
  double p1[DIM_NUM] = {  4.0, 2.0, 3.0 };
  double p2[DIM_NUM] = {  1.0, 5.0, 3.0 };
  double p3[DIM_NUM] = {  1.0, 2.0, 6.0 };
  double p4[DIM_NUM] = { -2.0, 2.0, 3.0 };
  double r = 3.0;

  printf ( "\n" );
  printf ( "SPHERE_IMP2EXP_3D_TEST\n" );
  printf ( "  SPHERE_IMP2EXP_3D: implicit sphere => explicit form.\n" );

  printf ( "\n" );
  printf ( "  Initial form of explicit sphere:\n" );
  printf ( "\n" );
  printf ( "  P1:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p1[i] );
  }
  printf ( "\n" );
  printf ( "  P2:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p2[i] );
  }
  printf ( "\n" );
  printf ( "  P3:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p3[i] );
  }
  printf ( "\n" );
  printf ( "  P4:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p4[i] );
  }
  printf ( "\n" );

  sphere_exp2imp_3d ( p1, p2, p3, p4, &r, pc );

  printf ( "\n" );
  printf ( "  Computed form of implicit sphere:\n" );
  printf ( "\n" );
  printf ( "  Imputed radius = %f\n", r );

  r8vec_print ( DIM_NUM, pc, "  Imputed center:" );

  sphere_imp2exp_3d ( r, pc, p1, p2, p3, p4 );

  printf ( "\n" );
  printf ( "  Computed form of explicit sphere:\n" );
  printf ( "\n" );
  printf ( "  P1:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p1[i] );
  }
  printf ( "\n" );
  printf ( "  P2:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p2[i] );
  }
  printf ( "\n" );
  printf ( "  P3:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p3[i] );
  }
  printf ( "\n" );
  printf ( "  P4:" );
  for ( i = 0; i < DIM_NUM; i++ )
  {
    printf ( "  %12f", p4[i] );
  }
  printf ( "\n" );

  return;
# undef DIM_NUM
}
/******************************************************************************/

void sphere_exp2imp_nd_test ( )

/******************************************************************************/
/*
  Purpose:

    SPHERE_EXP2IMP_ND_TEST tests SPHERE_EXP2IMP_ND.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    26 July 2011

  Author:

    John Burkardt
*/
{
# define N 3

  int n = N;
  double p[N*(N+1)] = {
    4.0, 2.0, 3.0, 
    1.0, 5.0, 3.0, 
    1.0, 2.0, 6.0, 
   -2.0, 2.0, 3.0 };
  double pc[N];
  double pc_true[N] = { 1.0, 2.0, 3.0 };
  double r;
  double r_true = 3.0;

  printf ( "\n" );
  printf ( "SPHERE_EXP2IMP_ND_TEST\n" );
  printf ( "  SPHERE_EXP2IMP_ND: explicit sphere => implicit form;\n" );

  r8mat_transpose_print ( n, n + 1, p, "  Initial form of explicit sphere:" );

  sphere_exp2imp_nd ( n, p, &r, pc );

  printf ( "\n" );
  printf ( "  Computed form of implicit sphere:\n" );
  printf ( "\n" );
  printf ( "  Imputed radius = %f\n", r );
  printf ( "  True radius =    %f\n", r_true );

  r8vec_print ( n, pc, "  Imputed center" );

  r8vec_print ( n, pc_true, "  True center" );

  return;
# undef N
}
/******************************************************************************/

void triangle_circumcenter_2d_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_CIRCUMCENTER_2D_TEST tests TRIANGLE_CIRCUMCENTER_2D.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 October 2010

  Author:

    John Burkardt
*/
{
# define M 2
# define TEST_NUM 4

  int i;
  int j;
  int m = M;
  double *pc;
  double t[M*3];
  double t_test[M*3*TEST_NUM] = {
         10.0,  5.0, 
         11.0,  5.0, 
         10.0,  6.0, 
         10.0,  5.0, 
         11.0,  5.0, 
         10.5,  5.86602539, 
         10.0,  5.0, 
         11.0,  5.0, 
         10.5, 15.0, 
         10.0,  5.0, 
         11.0,  5.0, 
        20.0,   7.0 };
  int test;
  int test_num = TEST_NUM;

  printf ( "\n" );
  printf ( "TRIANGLE_CIRCUMCENTER_2D_TEST\n" );
  printf ( "  TRIANGLE_CIRCUMCENTER_2D computes the circumcenter of a triangle;\n" );

  for ( test = 0; test < test_num; test++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        t[i+j*m] = t_test[i+j*m+test*m*3];
      }
    }
    r8mat_transpose_print ( m, 3, t, "  Triangle vertices:" );

    pc = triangle_circumcenter_2d ( t );
    r8vec_print ( m, pc, "  Circumcenter by TRIANGLE_CIRCUMCENTER_2D:" );
    free ( pc );
  }
  return;
# undef M
# undef TEST_NUM
}
/******************************************************************************/

void triangle_circumcenter_2d_2_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_CIRCUMCENTER_2D_2_TEST tests TRIANGLE_CIRCUMCENTER_2D_2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 October 2010

  Author:

    John Burkardt
*/
{
# define M 2
# define TEST_NUM 4

  int i;
  int j;
  int m = M;
  double *pc;
  double t[M*3];
  double t_test[M*3*TEST_NUM] = {
         10.0,  5.0, 
         11.0,  5.0, 
         10.0,  6.0, 
         10.0,  5.0, 
         11.0,  5.0, 
         10.5,  5.86602539, 
         10.0,  5.0, 
         11.0,  5.0, 
         10.5, 15.0, 
         10.0,  5.0, 
         11.0,  5.0, 
        20.0,   7.0 };
  int test;
  int test_num = TEST_NUM;

  printf ( "\n" );
  printf ( "TRIANGLE_CIRCUMCENTER_2D_2_TEST\n" );
  printf ( "  TRIANGLE_CIRCUMCENTER_2D_2 computes the circumcenter of a triangle;\n" );

  for ( test = 0; test < test_num; test++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        t[i+j*m] = t_test[i+j*m+test*m*3];
      }
    }
    r8mat_transpose_print ( m, 3, t, "  Triangle vertices:" );

    pc = triangle_circumcenter_2d_2 ( t );
    r8vec_print ( m, pc, "  Circumcenter by TRIANGLE_CIRCUMCENTER_2D_2:" );
    free ( pc );
  }
  return;
# undef M
# undef TEST_NUM
}
/******************************************************************************/

void test2101 ( )

/******************************************************************************/
/*
  Purpose:

    TEST2101 tests TRIANGLE_CIRCUMCENTER_2D and others.

  Discussion:

    The functions tested include
    * TRIANGLE_CIRCUMCENTER_2D;
    * TRIANGLE_CIRCUMCENTER_2D_2;

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 October 2010

  Author:

    John Burkardt
*/
{
# define M 2
# define TEST_NUM 4

  int i;
  int j;
  int m = M;
  double *pc;
  double t[M*3];
  double t_test[M*3*TEST_NUM] = {
         10.0,  5.0, 
         11.0,  5.0, 
         10.0,  6.0, 
         10.0,  5.0, 
         11.0,  5.0, 
         10.5,  5.86602539, 
         10.0,  5.0, 
         11.0,  5.0, 
         10.5, 15.0, 
         10.0,  5.0, 
         11.0,  5.0, 
        20.0,   7.0 };
  int test;
  int test_num = TEST_NUM;

  printf ( "\n" );
  printf ( "TEST2101\n" );
  printf ( "  For a triangle in 2D, the circumenter can be computed by:\n" );
  printf ( "  TRIANGLE_CIRCUMCENTER_2D;\n" );
  printf ( "  TRIANGLE_CIRCUMCENTER_2D_2;\n" );

  for ( test = 0; test < test_num; test++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        t[i+j*m] = t_test[i+j*m+test*m*3];
      }
    }
    r8mat_transpose_print ( m, 3, t, "  Triangle vertices:" );

    pc = triangle_circumcenter_2d ( t );
    r8vec_print ( m, pc, "  Circumcenter by TRIANGLE_CIRCUMCENTER_2D:" );
    free ( pc );

    pc = triangle_circumcenter_2d_2 ( t );
    r8vec_print ( m, pc, "  Circumcenter by TRIANGLE_CIRCUMCENTER_2D_2:" );
    free ( pc );
  }
  return;
# undef M
# undef TEST_NUM
}
/******************************************************************************/

void triangle_circumcenter_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_CIRCUMCENTER_TEST tests TRIANGLE_CIRCUMCENTER.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 October 2010

  Author:

    John Burkardt
*/
{
# define M1 2
# define TEST_NUM 4

  double *a12;
  int i;
  int j;
  int k;
  int m2;
  double *o1;
  double *o2;
  int m1 = M1;
/*
  double pc1[M1];
*/
  double *pc2;
  int seed;
  double t1[M1*3];
  double *t2;
  double t_test[M1*3*TEST_NUM] = {
         10.0,  5.0, 
         11.0,  5.0, 
         10.0,  6.0, 
         10.0,  5.0, 
         11.0,  5.0, 
         10.5,  5.86602539, 
         10.0,  5.0, 
         11.0,  5.0, 
         10.5, 15.0, 
         10.0,  5.0, 
         11.0,  5.0, 
        20.0,   7.0 };
  int test;
  int test_num = TEST_NUM;

  printf ( "\n" );
  printf ( "TRIANGLE_CIRCUMCENTER_TEST\n" );
  printf ( "  For a triangle in M dimensions, the circumenter can be computed by:\n" );
  printf ( "  TRIANGLE_CIRCUMCENTER;\n" );
/*
  Vary the dimension.
*/
  for ( m2 = 2; m2 <= 5; m2++ )
  {
    seed = 123456789;

    printf ( "\n" );
    printf ( "  M2 = %d\n", m2 );

    t2 = ( double * ) malloc ( m2 * 3 * sizeof ( double ) );
/*
  Randomly choose a mapping P2 = O2 + A12 * ( P1 - O1 )
*/
    a12 = r8mat_uniform_01_new ( m2, m1, &seed );
    o1 = r8vec_uniform_01_new ( m1, &seed );
    o2 = r8vec_uniform_01_new ( m2, &seed );
/*
  Map each M1-dimensional triangle into M2 space.
*/
    for ( test = 0; test < test_num; test++ )
    {
      for ( j = 0; j < 3; j++ )
      {
        for ( i = 0; i < m1; i++ )
        {
          t1[i+j*m1] = t_test[i+j*m1+test*m1*3];
        }
      }
      for ( j = 0; j < 3; j++ )
      {
        t1[i+j*m1] = t1[i+j*m1] - o1[i];
      }

      for ( j = 0; j < 3; j++ )
      {
        for ( i = 0; i < m2; i++ )
        {
          t2[i+j*m2] = 0.0;
          for ( k = 0; k < m1; k++ )
          {
            t2[i+j*m2] = t2[i+j*m2] + a12[i+k*m2] * t1[k+j*m1];
          }
        }
      }
      for ( j = 0; j < 3; j++ )
      {
        for ( i = 0; i < m2; i++ )
        {
          t2[i+j*m2] = t2[i+j*m2] + o2[i];
        }
      }

      pc2 = triangle_circumcenter ( m2, t2 );

      r8vec_print ( m2, pc2, "  Circumcenter by TRIANGLE_CIRCUMCENTER:" );
      printf ( "\n" );
      printf ( "  Distances from circumcenter to vertices:\n" );
      printf ( "\n" );
      for ( j = 0; j < 3; j++ )
      {
        printf ( "  %f\n", r8vec_norm_affine ( m2, pc2, t2+j*m2 ) );
      }
      free ( pc2 );
    }
    free ( a12 );
    free ( o1 );
    free ( o2 );
    free ( t2 );
  }
  return;
}
/******************************************************************************/

void wedge01_volume_test ( )

/******************************************************************************/
/*
  Purpose:

    WEDGE01_VOLUME_TEST tests WEDGE01_VOLUME.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 January 2018

  Author:

    John Burkardt
*/
{
  double volume;

  printf ( "\n" );
  printf ( "WEDGE01_VOLUME_TEST\n" );
  printf ( "  WEDGE01_VOLUME returns the volume of the unit wedge.\n" );

  volume = wedge01_volume ( );

  printf ( "\n" );
  printf ( "  Volume = %g\n", volume );

  return;
}
