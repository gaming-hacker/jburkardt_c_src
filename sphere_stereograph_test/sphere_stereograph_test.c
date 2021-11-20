# include <complex.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "sphere_stereograph.h"

int main ( );

void test01 ( );
void test02 ( );
void test03 ( );

/******************************************************************************/

int main ( )

/*****************************************************************************80

  Purpose:

    MAIN is the main program for SPHERE_STEREOGRAPH_TEST.

  Discussion:

    SPHERE_STEREOGRAPH_TEST tests the SPHERE_STEREOGRAPH library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 November 2010

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "SPHERE_STEREOGRAPH_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the SPHERE_STEREOGRAPH library.\n" );

  test01 ( );
  test02 ( );
  test03 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SPHERE_STEREOGRAPH_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( )

/*****************************************************************************80

  Purpose:

    TEST01 checks that the two functions are inverses.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 November 2010

  Author:

    John Burkardt
*/
{
  double dif;
  int i;
  int j;
  int m;
  int n;
  double *p;
  double *p1;
  double *p2;
  double *q;
  double *q1;
  double *q2;
  int seed;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  SPHERE_STEREOGRAPH maps from sphere to plane.\n" );
  printf ( "  SPHERE_STEREOGRAPH_INVERSE is the inverse map.\n" );
  printf ( "  Check that these two functions are inverses.\n" );

  m = 3;
  n = 100;
/*
  Check #1.
*/
  seed = 123456789;
  p1 = uniform_on_sphere01_map ( m, n, &seed );
  q  = sphere_stereograph ( m, n, p1 );
  p2 = sphere_stereograph_inverse ( m, n, q );
  dif = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      dif = dif + pow ( p1[i+j*m] - p2[i+j*m], 2 );
    }
  }
  dif = sqrt ( dif ) / ( double ) ( n );
  printf ( "\n" );
  printf ( "  Map points from sphere to plane to sphere.\n" );
  printf ( "  RMS difference for %d points was %g\n", n, dif );

  free ( p1 );
  free ( p2 );
  free ( q );
/*
  Check #2.
*/
  q1 = r8mat_uniform_01_new ( m, n, &seed );
  for ( j = 0; j < n; j++ )
  {
    q1[m-1+j*m] = 1.0;
  }

  p = sphere_stereograph_inverse ( m, n, q1 );
  q2 = sphere_stereograph ( m, n, p );

  dif = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      dif = dif + pow ( q1[i+j*m] - q2[i+j*m], 2 );
    }
  }
  dif = sqrt ( dif ) / ( double ) ( n );
  printf ( "\n" );
  printf ( "  Map points from plane to sphere to plane.\n" );
  printf ( "  RMS difference for %d points was %g\n",n, dif );

  free ( p );
  free ( q1 );
  free ( q2 );

  return;
}
/******************************************************************************/

void test02 ( )

/*****************************************************************************80

  Purpose:

    TEST02 checks the generalized mapping.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 November 2010

  Author:

    John Burkardt
*/
{
  double *center;
  double dif;
  double *focus;
  int i;
  int j;
  int m;
  int n;
  double *p1;
  double *p2;
  double *q1;
  double *q2;
  int seed;

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  SPHERE_STEREOGRAPH standard mapping from sphere to plane.\n" );
  printf ( "  SPHERE_STEREOGRAPH2 generalized mapping:\n" );
  printf ( "  (focus and center are arbitrary)\n" );
  printf ( "  Check that these two functions can agree.\n" );

  m = 3;
  n = 100;

  focus = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m - 1; i++ )
  {
    focus[i] = 0.0;
  }
  focus[m-1] = -1.0;

  center = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    center[i] = 0.0;
  }
/*
  Check #1.
*/
  seed = 123456789;
  p1 = uniform_on_sphere01_map ( m, n, &seed );

  q1 = sphere_stereograph ( m, n, p1 );

  q2 = sphere_stereograph2 ( m, n, p1, focus, center );

  dif = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      dif = dif + pow ( q1[i+j*m] - q2[i+j*m], 2 );
    }
  }
  dif = sqrt ( dif ) / ( double ) ( n );
  printf ( "\n" );
  printf ( "  Map points from sphere to plane.\n" );
  printf ( "  RMS difference for %d points was %g\n", n, dif );

  free ( p1 );
  free ( q1 );
  free ( q2 );
/*
  Check #2.
*/
  q1 = r8mat_uniform_01_new ( m, n, &seed );
  for ( j = 0; j < n; j++ )
  {
    q1[m-1+j*m] = 1.0;
  }

  p1 = sphere_stereograph_inverse ( m, n, q1 );

  p2 = sphere_stereograph2_inverse ( m, n, q1, focus, center );

  dif = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      dif = dif + pow ( p1[i+j*m] - p2[i+j*m], 2 );
    }
  }
  dif = sqrt ( dif ) / ( double ) ( n );
  printf ( "\n" );
  printf ( "  Map points from plane to sphere.\n" );
  printf ( "  RMS difference for %d points was %g\n", n, dif );

  free ( p1 );
  free ( p2 );
  free ( q1 );

  free ( center );
  free ( focus );

  return;
}
/******************************************************************************/

void test03 ( )

/*****************************************************************************80

  Purpose:

    TEST03 checks that the two functions are inverses.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 November 2010

  Author:

    John Burkardt
*/
{
  double *alpha;
  double *beta;
  double *center;
  double dif;
  double *focus;
  int i;
  int j;
  int m;
  int n;
  double *normal;
  double *p;
  double *p1;
  double *p2;
  double *pq;
  double *pr;
  double *q;
  double *q1;
  double *q2;
  double r;
  int seed;
  double *tang;

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  SPHERE_STEREOGRAPH2 maps from sphere to plane.\n" );
  printf ( "  SPHERE_STEREOGRAPH2_INVERSE is the inverse map.\n" );
  printf ( "  Check that these two functions are inverses.\n" );

  m = 3;
  n = 100;
  seed = 123456789;

  focus = r8vec_uniform_01_new ( m, &seed );
  center = r8vec_uniform_01_new ( m, &seed );
  r = r8vec_norm_affine ( m, focus, center );

  printf ( "\n" );
  printf ( "  Using radius = %g\n", r );
  r8vec_transpose_print ( m, center, "  Center:" );
  r8vec_transpose_print ( m, focus, "  Focus:" );
/*
  Check #1.
*/
  p1 = uniform_on_sphere01_map ( m, n, &seed );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
       p1[i+j*m] = center[i] + r * p1[i+j*m];
    }
  }
  q  = sphere_stereograph2 ( m, n, p1, focus, center );

  p2 = sphere_stereograph2_inverse ( m, n, q, focus, center );

  dif = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      dif = dif + pow ( p1[i+j*m] - p2[i+j*m], 2 );
    }
  }
  dif = sqrt ( dif ) / ( double ) ( n );
  printf ( "\n" );
  printf ( "  Map points from sphere to plane to sphere.\n" );
  printf ( "  RMS difference for %d points was %g\n", n, dif );

  free ( p1 );
  free ( p2 );
  free ( q );
/*
  Check #2.
  We have to work hard to get random points on the plane, since
  all we know to begin with is the point of tangency and the normal.
*/
  tang = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    tang[i] = 2.0 * center[i] - focus[i];
  }
  normal = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    normal[i] = center[i] - focus[i];
  }

  pr = ( double * ) malloc ( m * sizeof ( double ) );
  pq = ( double * ) malloc ( m * sizeof ( double ) );
  plane_normal_basis_3d ( tang, normal, pr, pq );

  q1 = ( double * ) malloc ( m * n * sizeof ( double ) );

  alpha = r8vec_uniform_01_new ( n, &seed );
  beta = r8vec_uniform_01_new ( n, &seed );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      q1[i+j*m] = tang[i] + pr[i] * alpha[j] + pq[i] * beta[j];
    }
  }
  p = sphere_stereograph2_inverse ( m, n, q1, focus, center );
  q2 = sphere_stereograph2 ( m, n, p, focus, center );

  dif = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      dif = dif + pow ( q1[i+j*m] - q2[i+j*m], 2 );
    }
  }
  dif = sqrt ( dif ) / ( double ) ( n );
  printf ( "\n" );
  printf ( "  Map points from plane to sphere to plane.\n" );
  printf ( "  RMS difference for %d points was %g\n", n, dif );

  free ( alpha );
  free ( beta );
  free ( normal );
  free ( p );
  free ( pq );
  free ( pr );
  free ( q1 );
  free ( q2 );
  free ( tang );

  return;
}
