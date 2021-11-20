# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "navier_stokes_3d_exact.h"

int main ( );
void resid_burgers_test ( );
void uvwp_burgers_test ( );
void resid_ethier_test ( );
void uvwp_ethier_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    NS3DE_TEST tests the NS3DE library.

  Location:

    http://people.sc.fsu.edu/~jburkardt/c_src/navier_stokes_3d_exact/ns3de_test.c

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 July 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "NS3DE_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the NS3DE library.\n" );

  uvwp_burgers_test ( );
  resid_burgers_test ( );

  uvwp_ethier_test ( );
  resid_ethier_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "NS3DE_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void uvwp_burgers_test ( )

/******************************************************************************/
/*
  Purpose:

    UVWP_BURGERS_TEST tests UVWP_BURGERS

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 July 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *p;
  int seed;
  double *t;
  double *u;
  double *v;
  double *w;
  double *x;
  double xyz_hi;
  double xyz_lo;
  double *y;
  double *z;

  nu = 0.25;

  printf ( "\n" );
  printf ( "UVWP_BURGERS_TEST\n" );
  printf ( "  UVWP_BURGERS evaluates the Burgers solution.\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  at the initial time T = 0, in a region that is the\n" );
  printf ( "  cube centered at (0,0,0) with 'radius' 1.0.\n" );
  printf ( "  Viscosity NU = %g\n", nu );

  n = 1000;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  w = ( double * ) malloc ( n * sizeof ( double ) );

  xyz_lo = -1.0;
  xyz_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  y = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  z = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  t = r8vec_zeros_new ( n );

  uvwp_burgers ( nu, n, x, y, z, t, u, v, w, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:    %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:    %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  W:    %14.6g  %14.6g\n", r8vec_min ( n, w ), r8vec_max ( n, w ) );
  printf ( "  P:    %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( t );
  free ( u );
  free ( v );
  free ( w );
  free ( x );
  free ( y );
  free ( z );

  return;
}
/******************************************************************************/

void resid_burgers_test ( )

/******************************************************************************/
/*
  Purpose:

    RESID_BURGERS_TEST tests RESID_BURGERS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 July 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *pr;
  int seed;
  double *t;
  double *ur;
  double *vr;
  double *wr;
  double *x;
  double xyz_hi;
  double xyz_lo;
  double *y;
  double *z;

  nu = 0.25;

  printf ( "\n" );
  printf ( "RESID_BURGERS_TEST\n" );
  printf ( "  RESID_BURGERS evaluates the Burgers residual.\n" );
  printf ( "  Sample the Navier-Stokes residuals\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the cube centered at (0,0,0) with 'radius' 1.0,\n" );
  printf ( "  Viscosity NU = %g\n", nu );

  n = 1000;

  pr = ( double * ) malloc ( n * sizeof ( double ) );
  ur = ( double * ) malloc ( n * sizeof ( double ) );
  vr = ( double * ) malloc ( n * sizeof ( double ) );
  wr = ( double * ) malloc ( n * sizeof ( double ) );

  xyz_lo = -1.0;
  xyz_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  y = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  z = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  t = r8vec_zeros_new ( n );

  resid_burgers ( nu, n, x, y, z, t, ur, vr, wr, pr );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  Ur:    %14.6g  %14.6g\n", r8vec_amin ( n, ur ), r8vec_amax ( n, ur ) );
  printf ( "  Vr:    %14.6g  %14.6g\n", r8vec_amin ( n, vr ), r8vec_amax ( n, vr ) );
  printf ( "  Wr:    %14.6g  %14.6g\n", r8vec_amin ( n, wr ), r8vec_amax ( n, wr ) );
  printf ( "  Pr:    %14.6g  %14.6g\n", r8vec_amin ( n, pr ), r8vec_amax ( n, pr ) );

  free ( pr );
  free ( t );
  free ( ur );
  free ( vr );
  free ( wr );
  free ( x );
  free ( y );
  free ( z );

  return;
}
/******************************************************************************/

void uvwp_ethier_test ( )

/******************************************************************************/
/*
  Purpose:

    UVWP_ETHIER_TEST tests UVWP_ETHIER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 July 2015

  Author:

    John Burkardt
*/
{
  double a;
  double d;
  int n;
  double *p;
  const double r8_pi = 3.141592653589793;
  int seed;
  double *t;
  double *u;
  double *v;
  double *w;
  double *x;
  double xyz_hi;
  double xyz_lo;
  double *y;
  double *z;

  a = r8_pi / 4.0;
  d = r8_pi / 2.0;

  printf ( "\n" );
  printf ( "UVWP_ETHIER_TEST\n" );
  printf ( "  UVWP_ETHIER evaluates the Ethier solution.\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  at the initial time T = 0, in a region that is the\n" );
  printf ( "  cube centered at (0,0,0) with 'radius' 1.0.\n" );
  printf ( "  Parameter A = %g\n", a );
  printf ( "  Parameter D = %g\n", d );

  n = 1000;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  w = ( double * ) malloc ( n * sizeof ( double ) );

  xyz_lo = -1.0;
  xyz_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  y = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  z = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  t = r8vec_zeros_new ( n );

  uvwp_ethier ( a, d, n, x, y, z, t, u, v, w, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:    %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:    %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  W:    %14.6g  %14.6g\n", r8vec_min ( n, w ), r8vec_max ( n, w ) );
  printf ( "  P:    %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( t );
  free ( u );
  free ( v );
  free ( w );
  free ( x );
  free ( y );
  free ( z );

  return;
}
/******************************************************************************/

void resid_ethier_test ( )

/******************************************************************************/
/*
  Purpose:

    RESID_ETHIER_TEST tests RESID_ETHIER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 July 2015

  Author:

    John Burkardt
*/
{
  double a;
  double d;
  int n;
  double *pr;
  const double r8_pi = 3.141592653589793;
  int seed;
  double *t;
  double *ur;
  double *vr;
  double *wr;
  double *x;
  double xyz_hi;
  double xyz_lo;
  double *y;
  double *z;

  a = r8_pi / 4.0;
  d = r8_pi / 2.0;

  printf ( "\n" );
  printf ( "RESID_ETHIER_TEST\n" );
  printf ( "  RESID_ETHIER evaluates the Ethier residual.\n" );
  printf ( "  Sample the Navier-Stokes residuals\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the cube centered at (0,0,0) with 'radius' 1.0,\n" );
  printf ( "  Parameter A = %g\n", a );
  printf ( "  Parameter D = %g\n", d );

  n = 1000;

  pr = ( double * ) malloc ( n * sizeof ( double ) );
  ur = ( double * ) malloc ( n * sizeof ( double ) );
  vr = ( double * ) malloc ( n * sizeof ( double ) );
  wr = ( double * ) malloc ( n * sizeof ( double ) );

  xyz_lo = -1.0;
  xyz_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  y = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  z = r8vec_uniform_ab_new ( n, xyz_lo, xyz_hi, &seed );
  t = r8vec_zeros_new ( n );

  resid_ethier ( a, d, n, x, y, z, t, ur, vr, wr, pr );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  Ur:    %14.6g  %14.6g\n", r8vec_amin ( n, ur ), r8vec_amax ( n, ur ) );
  printf ( "  Vr:    %14.6g  %14.6g\n", r8vec_amin ( n, vr ), r8vec_amax ( n, vr ) );
  printf ( "  Wr:    %14.6g  %14.6g\n", r8vec_amin ( n, wr ), r8vec_amax ( n, wr ) );
  printf ( "  Pr:    %14.6g  %14.6g\n", r8vec_amin ( n, pr ), r8vec_amax ( n, pr ) );

  free ( pr );
  free ( t );
  free ( ur );
  free ( vr );
  free ( wr );
  free ( x );
  free ( y );
  free ( z );

  return;
}

