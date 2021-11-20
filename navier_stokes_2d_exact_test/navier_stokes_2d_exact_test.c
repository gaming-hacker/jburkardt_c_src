# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "navier_stokes_2d_exact.h"

int main ( );
void uvp_gms_test ( );
void uvp_gms_test2 ( );
void rhs_gms_test ( );
void resid_gms_test ( );
void gnuplot_gms_test ( );
void uvp_lukas_test ( );
void uvp_lukas_test2 ( );
void rhs_lukas_test ( );
void resid_lukas_test ( );
void gnuplot_lukas_test ( );
void uvp_poiseuille_test ( );
void uvp_poiseuille_test2 ( );
void rhs_poiseuille_test ( );
void resid_poiseuille_test ( );
void gnuplot_poiseuille_test ( );
void parameter_poiseuille_test ( );
void uvp_spiral_test ( );
void uvp_spiral_test2 ( );
void rhs_spiral_test ( );
void resid_spiral_test ( );
void gnuplot_spiral_test ( );
void parameter_spiral_test ( );
void uvp_taylor_test ( );
void uvp_taylor_test2 ( );
void rhs_taylor_test ( );
void resid_taylor_test ( );
void gnuplot_taylor_test ( );
void parameter_taylor_test ( );
void uvp_vortex_test ( );
void uvp_vortex_test2 ( );
void rhs_vortex_test ( );
void resid_vortex_test ( );
void gnuplot_vortex_test ( );
void parameter_vortex_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    navier_stokes_2d_exact_test tests navier_stokes_2d_exact().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 August 2020

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "navier_stokes_2d_exact_test\n" );
  printf ( "  C version\n" );
  printf ( "  Test navier_stokes_2d_exact().\n" );
/*
  GMS Flow.
*/
  uvp_gms_test ( );
  uvp_gms_test2 ( );
  rhs_gms_test ( );
  resid_gms_test ( );
  gnuplot_gms_test ( );
/*
  Lukas Bystricky Flow.
*/
  uvp_lukas_test ( );
  uvp_lukas_test2 ( );
  rhs_lukas_test ( );
  resid_lukas_test ( );
  gnuplot_lukas_test ( );
/*
  Poiseuille Flow.
*/
  uvp_poiseuille_test ( );
  uvp_poiseuille_test2 ( );
  rhs_poiseuille_test ( );
  resid_poiseuille_test ( );
  gnuplot_poiseuille_test ( );
  parameter_poiseuille_test ( );
/*
  Spiral Flow.
*/
  uvp_spiral_test ( );
  uvp_spiral_test2 ( );
  rhs_spiral_test ( );
  resid_spiral_test ( );
  gnuplot_spiral_test ( );
  parameter_spiral_test ( );
/*
  Taylor Flow.
*/
  uvp_taylor_test ( );
  uvp_taylor_test2 ( );
  rhs_taylor_test ( );
  resid_taylor_test ( );
  gnuplot_taylor_test ( );
  parameter_taylor_test ( );
/*
  Vortex Flow.
*/
  uvp_vortex_test ( );
  uvp_vortex_test2 ( );
  rhs_vortex_test ( );
  resid_vortex_test ( );
  gnuplot_vortex_test ( );
  parameter_vortex_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "navier_stokes_2d_exact_test\n" );
  printf ( "  Normal end of execution.\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void uvp_gms_test ( )

/******************************************************************************/
/*
  Purpose:

    uvp_gms_test samples the GMS solution at a specific time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 August 2020

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 1.0;

  printf ( "\n" );
  printf ( "uvp_gms_test\n" );
  printf ( "  GMS Flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  at time T = 1,\n" );
  printf ( "  over the square [-1,+1]x[-1,+1].\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = -1.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );

  uvp_gms ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void uvp_gms_test2 ( )

/******************************************************************************/
/*
  Purpose:

    uvp_gms_test2 samples the GMS flow on the boundary at a specific time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 August 2020

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double nu;
  double *p;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 1.0;

  printf ( "\n" );
  printf ( "uvp_gms_test2\n" );
  printf ( "  GMS Flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  at time T = 1,\n" );
  printf ( "  over the boundary of the square [-1,+1]x[-1,+1].\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 400;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = -1.0;
  r8_hi = 1.0;

  r8vec_linspace ( 100, r8_lo, r8_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = r8_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = r8_hi;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+100 );

  r8vec_linspace ( 100, r8_hi, r8_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = r8_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = r8_lo;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+300 );

  uvp_gms ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void rhs_gms_test ( )

/******************************************************************************/
/*
  Purpose:

    rhs_gms_test samples the GMS right hand sides at a specific time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 August 2020

  Author:

    John Burkardt
*/
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 1.0;

  printf ( "\n" );
  printf ( "rhs_gms_test\n" );
  printf ( "  GMS Flow:\n" );
  printf ( "  Sample the Navier-Stokes right hand sides\n" );
  printf ( "  at time T = 1,\n" );
  printf ( "  over the square [-1,+1]x[-1,+1].\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  f = ( double * ) malloc ( n * sizeof ( double ) );
  g = ( double * ) malloc ( n * sizeof ( double ) );
  h = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = -1.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );

  rhs_gms ( nu, rho, n, x, y, t, f, g, h );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  F:  %14.6g  %14.6g\n", r8vec_min ( n, f ), r8vec_max ( n, f ) );
  printf ( "  G:  %14.6g  %14.6g\n", r8vec_min ( n, g ), r8vec_max ( n, g ) );
  printf ( "  H:  %14.6g  %14.6g\n", r8vec_min ( n, h ), r8vec_max ( n, h ) );

  free ( f );
  free ( g );
  free ( h );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void resid_gms_test ( )

/******************************************************************************/
/*
  Purpose:

    resid_gms_test samples the GMS residual at a specific time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 August 2020

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 1.0;

  printf ( "\n" );
  printf ( "resid_gms_test\n" );
  printf ( "  GMS Flow:\n" );
  printf ( "  Sample the Navier-Stokes residuals\n" );
  printf ( "  at time T = 1,\n" );
  printf ( "  over the square [-1,+1]x[-1,+1].\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  pr = ( double * ) malloc ( n * sizeof ( double ) );
  ur = ( double * ) malloc ( n * sizeof ( double ) );
  vr = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = -1.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );

  resid_gms ( nu, rho, n, x, y, t, ur, vr, pr );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  Ur:  %14.6g  %14.6g\n", r8vec_amin ( n, ur ), r8vec_amax ( n, ur ) );
  printf ( "  Vr:  %14.6g  %14.6g\n", r8vec_amin ( n, vr ), r8vec_amax ( n, vr ) );
  printf ( "  Pr:  %14.6g  %14.6g\n", r8vec_amin ( n, pr ), r8vec_amax ( n, pr ) );

  free ( pr );
  free ( ur );
  free ( vr );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void gnuplot_gms_test ( )

/******************************************************************************/
/*
  Purpose:

    gnuplot_gms_test plots the GMS flow.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 August 2020

  Author:

    John Burkardt
*/
{
  char header[255];
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  nu = 1.0;
  rho = 1.0;
  t = 1.0;

  printf ( "\n" );
  printf ( "gnuplot_gms_test:\n" );
  printf ( "  GMS Flow:\n" );
  printf ( "  Generate a velocity field on a regular grid.\n" );
  printf ( "  Store in GNUPLOT data and command files.\n" );

  x_lo = -1.0;
  x_hi = 1.0;

  y_lo = -1.0;
  y_hi = 1.0;

  x = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  y = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  n = x_num * y_num;

  u = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  v = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  p = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  uvp_gms ( nu, rho, n, x, y, t, u, v, p );

  strcpy ( header, "gms" );
  s = 0.25;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void uvp_lukas_test ( )

/******************************************************************************/
/*
  Purpose:

    uvp_lukas_test samples Lukas Bystricky's solution at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 March 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "uvp_lukas_test\n" );
  printf ( "  Lukas Bystricky Flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the unit square.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  t = 0.0;

  uvp_lukas ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void uvp_lukas_test2 ( )

/******************************************************************************/
/*
  Purpose:

    uvp_lukas_test2 samples Lukas Bystricky's flow on the boundary at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 March 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double nu;
  double *p;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  printf ( "\n" );
  printf ( "uvp_lukas_test2\n" );
  printf ( "  Lukas Bystricky Flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  on the boundary,\n" );
  printf ( "  at the initial time T = 0, using the unit square.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 400;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.0;
  r8_hi = 1.0;

  r8vec_linspace ( 100, r8_lo, r8_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = r8_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = r8_hi;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+100 );

  r8vec_linspace ( 100, r8_hi, r8_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = r8_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = r8_lo;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+300 );

  uvp_lukas ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void rhs_lukas_test ( )

/******************************************************************************/
/*
  Purpose:

    rhs_lukas_test samples Lukas Bystricky's right hand sides at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 March 2015

  Author:

    John Burkardt
*/
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  printf ( "\n" );
  printf ( "rhs_lukas_test\n" );
  printf ( "  Lukas Bystricky Flow:\n" );
  printf ( "  Sample the Navier-Stokes right hand sides\n" );
  printf ( "  at the initial time T = 0, using the unit square.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  f = ( double * ) malloc ( n * sizeof ( double ) );
  g = ( double * ) malloc ( n * sizeof ( double ) );
  h = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );

  rhs_lukas ( nu, rho, n, x, y, t, f, g, h );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  F:  %14.6g  %14.6g\n", r8vec_min ( n, f ), r8vec_max ( n, f ) );
  printf ( "  G:  %14.6g  %14.6g\n", r8vec_min ( n, g ), r8vec_max ( n, g ) );
  printf ( "  H:  %14.6g  %14.6g\n", r8vec_min ( n, h ), r8vec_max ( n, h ) );

  free ( f );
  free ( g );
  free ( h );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void resid_lukas_test ( )

/******************************************************************************/
/*
  Purpose:

    resid_lukas_test samples Lukas Bystricky's residual at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 March 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  printf ( "\n" );
  printf ( "resid_lukas_test\n" );
  printf ( "  Lukas Bystricky Flow:\n" );
  printf ( "  Sample the Navier-Stokes residuals\n" );
  printf ( "  at the initial time T = 0, over the unit square.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  pr = ( double * ) malloc ( n * sizeof ( double ) );
  ur = ( double * ) malloc ( n * sizeof ( double ) );
  vr = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );

  resid_lukas ( nu, rho, n, x, y, t, ur, vr, pr );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  Ur:  %14.6g  %14.6g\n", r8vec_amin ( n, ur ), r8vec_amax ( n, ur ) );
  printf ( "  Vr:  %14.6g  %14.6g\n", r8vec_amin ( n, vr ), r8vec_amax ( n, vr ) );
  printf ( "  Pr:  %14.6g  %14.6g\n", r8vec_amin ( n, pr ), r8vec_amax ( n, pr ) );

  free ( pr );
  free ( ur );
  free ( vr );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void gnuplot_lukas_test ( )

/******************************************************************************/
/*
  Purpose:

    gnuplot_lukas_test plots Lukas Bystricky's flow.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 March 2015

  Author:

    John Burkardt
*/
{
  char header[255];
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  printf ( "\n" );
  printf ( "gnuplot_lukas_test:\n" );
  printf ( "  Lukas Bystricky Flow:\n" );
  printf ( "  Generate a velocity field on a regular grid.\n" );
  printf ( "  Store in GNUPLOT data and command files.\n" );

  x_lo = 0.0;
  x_hi = 1.0;

  y_lo = 0.0;
  y_hi = 1.0;

  x = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  y = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  n = x_num * y_num;

  u = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  v = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  p = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  uvp_lukas ( nu, rho, n, x, y, t, u, v, p );

  strcpy ( header, "lukas" );
  s = 0.25;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void uvp_poiseuille_test ( )

/******************************************************************************/
/*
  Purpose:

    UVP_POISEUILLE_test samples the Poiseuille solution at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 July 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  double *y;
  double y_hi;
  double y_lo;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "UVP_POISEUILLE_test\n" );
  printf ( "  Poiseuille flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  at the initial time T = 0, over a channel region.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );

  x_lo = 0.0;
  x_hi = 6.0;
  y_lo = -1.0;
  y_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, x_lo, x_hi, &seed );
  y = r8vec_uniform_ab_new ( n, y_lo, y_hi, &seed );
  t = 0.0;

  uvp_poiseuille ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void uvp_poiseuille_test2 ( )

/******************************************************************************/
/*
  Purpose:

    UVP_POISEUILLE_test2 samples the Poiseuille solution on the boundary at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 July 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double nu;
  double *p;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  double *y;
  double y_hi;
  double y_lo;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  printf ( "\n" );
  printf ( "UVP_POISEUILLE_test2\n" );
  printf ( "  Poiseuille Flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  on the boundary,\n" );
  printf ( "  at the initial time T = 0, over a channel region.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 400;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );

  x_lo = 0.0;
  x_hi = 6.0;
  y_lo = -1.0;
  y_hi = +1.0;

  r8vec_linspace ( 100, x_lo, x_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = y_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = x_hi;
  }
  r8vec_linspace ( 100, y_lo, y_hi, y+100 );

  r8vec_linspace ( 100, x_hi, x_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = y_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = x_lo;
  }
  r8vec_linspace ( 100, y_hi, y_lo, y+300 );

  uvp_poiseuille ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void rhs_poiseuille_test ( )

/******************************************************************************/
/*
  Purpose:

    RHS_POISEUILLE_test samples the Poiseuille right hand sides at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 July 2015

  Author:

    John Burkardt
*/
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double x_hi;
  double x_lo;
  double *y;
  double y_hi;
  double y_lo;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "RHS_POISEUILLE_test\n" );
  printf ( "  Poiseuille Flow:\n" );
  printf ( "  Sample the Navier-Stokes right hand sides\n" );
  printf ( "  at the initial time T = 0, over a channel region.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  f = ( double * ) malloc ( n * sizeof ( double ) );
  g = ( double * ) malloc ( n * sizeof ( double ) );
  h = ( double * ) malloc ( n * sizeof ( double ) );

  x_lo = 0.0;
  x_hi = 6.0;
  y_lo = -1.0;
  y_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, x_lo, x_hi, &seed );
  y = r8vec_uniform_ab_new ( n, y_lo, y_hi, &seed );
  t = 0.0;

  rhs_poiseuille ( nu, rho, n, x, y, t, f, g, h );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  F:  %14.6g  %14.6g\n", r8vec_min ( n, f ), r8vec_max ( n, f ) );
  printf ( "  G:  %14.6g  %14.6g\n", r8vec_min ( n, g ), r8vec_max ( n, g ) );
  printf ( "  H:  %14.6g  %14.6g\n", r8vec_min ( n, h ), r8vec_max ( n, h ) );

  free ( f );
  free ( g );
  free ( h );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void resid_poiseuille_test ( )

/******************************************************************************/
/*
  Purpose:

    RESID_POISEUILLE_test samples the Poiseuille residual at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 July 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double x_hi;
  double x_lo;
  double *y;
  double y_hi;
  double y_lo;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "RESID_POISEUILLE_test\n" );
  printf ( "  Poiseuille Flow:\n" );
  printf ( "  Sample the Navier-Stokes residuals\n" );
  printf ( "  at the initial time T = 0, over a channel region.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  pr = ( double * ) malloc ( n * sizeof ( double ) );
  ur = ( double * ) malloc ( n * sizeof ( double ) );
  vr = ( double * ) malloc ( n * sizeof ( double ) );

  x_lo = 0.0;
  x_hi = 6.0;
  y_lo = -1.0;
  y_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, x_lo, x_hi, &seed );
  y = r8vec_uniform_ab_new ( n, y_lo, y_hi, &seed );
  t = 0.0;

  resid_poiseuille ( nu, rho, n, x, y, t, ur, vr, pr );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  Ur:  %14.6g  %14.6g\n", r8vec_amin ( n, ur ), r8vec_amax ( n, ur ) );
  printf ( "  Vr:  %14.6g  %14.6g\n", r8vec_amin ( n, vr ), r8vec_amax ( n, vr ) );
  printf ( "  Pr:  %14.6g  %14.6g\n", r8vec_amin ( n, pr ), r8vec_amax ( n, pr ) );

  free ( pr );
  free ( ur );
  free ( vr );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void gnuplot_poiseuille_test ( )

/******************************************************************************/
/*
  Purpose:

    GNUPLOT_POISEUILLE_test plots the Poiseuille flow.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 July 2015

  Author:

    John Burkardt
*/
{
  char header[255];
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  printf ( "\n" );
  printf ( "GNUPLOT_POISEUILLE_test:\n" );
  printf ( "  Spiral Flow:\n" );
  printf ( "  Generate a velocity field on a regular grid.\n" );
  printf ( "  Store in GNUPLOT data and command files.\n" );

  x_lo = 0.0;
  x_hi = 6.0;
  y_lo = -1.0;
  y_hi = +1.0;

  x = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  y = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  nu = 1.0;
  rho = 1.0;
  n = x_num * y_num;
  t = 0.0;

  u = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  v = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  p = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  uvp_poiseuille ( nu, rho, n, x, y, t, u, v, p );

  strcpy ( header, "poiseuille" );
  s = 5.00;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void parameter_poiseuille_test ( )

/******************************************************************************/
/*
  Purpose:

    PARAMETER_POISEUILLE_test monitors Poiseuille solution norms for various NU, RHO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 July 2015

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  int n;
  double nu;
  double *p;
  double p_norm;
  double rho;
  int seed;
  double t;
  double *u;
  double u_norm;
  double *v;
  double v_norm;
  double *x;
  double x_hi;
  double x_lo;
  double *y;
  double y_hi;
  double y_lo;

  printf ( "\n" );
  printf ( "PARAMETER_POISEUILLE_test\n" );
  printf ( "  Poiseuille Flow:\n" );
  printf ( "  Monitor solution norms over time for various\n" );
  printf ( "  values of NU, RHO.\n" );

  n = 1000;

  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  p = ( double * ) malloc ( n * sizeof ( double ) );

  x_lo = 0.0;
  x_hi = 6.0;
  y_lo = -1.0;
  y_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, x_lo, x_hi, &seed );
  y = r8vec_uniform_ab_new ( n, y_lo, y_hi, &seed );
/*
  Vary RHO.
*/
  printf ( "\n" );
  printf ( "  RHO affects the pressure scaling.\n" );
  printf ( "\n" );
  printf ( "     RHO         NU           T     ||U||       ||V||       ||P||\n" );
  printf ( "\n" );

  nu = 1.0;
  rho = 1.0;

  for ( j = 1; j <= 3; j++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_poiseuille ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      printf ( "  %10.4g  %10.4g  %8.4f  %10.4g  %10.4g  %10.4g\n",
        rho, nu, t, u_norm, v_norm, p_norm );
    }
    printf ( "\n" );
    rho = rho / 100.0;
  }
/*
  Vary NU.
*/
  printf ( "\n" );
  printf ( "  NU affects the time scaling.\n" );
  printf ( "\n" );
  printf ( "     RHO         NU           T     ||U||       ||V||       ||P||\n" );
  printf ( "\n" );

  nu = 1.0;
  rho = 1.0;

  for ( i = 1; i <= 4; i++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_poiseuille ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      printf ( "  %10.4g  %10.4g  %8.4f  %10.4g  %10.4g  %10.4g\n",
        rho, nu, t, u_norm, v_norm, p_norm );
    }

    printf ( "\n" );

    nu = nu / 10.0;
  }

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void uvp_spiral_test ( )

/******************************************************************************/
/*
  Purpose:

    UVP_SPIRAL_test samples the Spiral solution at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "UVP_SPIRAL_test\n" );
  printf ( "  Spiral flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the unit square.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  t = 0.0;

  uvp_spiral ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void uvp_spiral_test2 ( )

/******************************************************************************/
/*
  Purpose:

    UVP_SPIRAL_test2 samples the Spiral solution on the boundary at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 March 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double nu;
  double *p;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  printf ( "\n" );
  printf ( "UVP_SPIRAL_test2\n" );
  printf ( "  Spiral Flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  on the boundary,\n" );
  printf ( "  at the initial time T = 0, using the unit square.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 400;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.0;
  r8_hi = 1.0;

  r8vec_linspace ( 100, r8_lo, r8_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = r8_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = r8_hi;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+100 );

  r8vec_linspace ( 100, r8_hi, r8_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = r8_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = r8_lo;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+300 );

  uvp_spiral ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void rhs_spiral_test ( )

/******************************************************************************/
/*
  Purpose:

    RHS_SPIRAL_test samples the Spiral right hand sides at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 January 2015

  Author:

    John Burkardt
*/
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "RHS_SPIRAL_test\n" );
  printf ( "  Spiral Flow:\n" );
  printf ( "  Sample the Navier-Stokes right hand sides\n" );
  printf ( "  at the initial time T = 0, using the unit square.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  f = ( double * ) malloc ( n * sizeof ( double ) );
  g = ( double * ) malloc ( n * sizeof ( double ) );
  h = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  t = 0.0;

  rhs_spiral ( nu, rho, n, x, y, t, f, g, h );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  F:  %14.6g  %14.6g\n", r8vec_min ( n, f ), r8vec_max ( n, f ) );
  printf ( "  G:  %14.6g  %14.6g\n", r8vec_min ( n, g ), r8vec_max ( n, g ) );
  printf ( "  H:  %14.6g  %14.6g\n", r8vec_min ( n, h ), r8vec_max ( n, h ) );

  free ( f );
  free ( g );
  free ( h );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void resid_spiral_test ( )

/******************************************************************************/
/*
  Purpose:

    RESID_SPIRAL_test samples the Spiral residual at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 January 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "RESID_SPIRAL_test\n" );
  printf ( "  Spiral Flow:\n" );
  printf ( "  Sample the Navier-Stokes residuals\n" );
  printf ( "  at the initial time T = 0, over the unit square.\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  pr = ( double * ) malloc ( n * sizeof ( double ) );
  ur = ( double * ) malloc ( n * sizeof ( double ) );
  vr = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  t = 0.0;

  resid_spiral ( nu, rho, n, x, y, t, ur, vr, pr );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  Ur:  %14.6g  %14.6g\n", r8vec_amin ( n, ur ), r8vec_amax ( n, ur ) );
  printf ( "  Vr:  %14.6g  %14.6g\n", r8vec_amin ( n, vr ), r8vec_amax ( n, vr ) );
  printf ( "  Pr:  %14.6g  %14.6g\n", r8vec_amin ( n, pr ), r8vec_amax ( n, pr ) );

  free ( pr );
  free ( ur );
  free ( vr );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void gnuplot_spiral_test ( )

/******************************************************************************/
/*
  Purpose:

    GNUPLOT_SPIRAL_test plots a Spiral velocity field.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 January 2015

  Author:

    John Burkardt
*/
{
  char header[255];
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  printf ( "\n" );
  printf ( "GNUPLOT_SPIRAL_test:\n" );
  printf ( "  Spiral Flow:\n" );
  printf ( "  Generate a velocity field on a regular grid.\n" );
  printf ( "  Store in GNUPLOT data and command files.\n" );

  x_lo = 0.0;
  x_hi = 1.0;

  y_lo = 0.0;
  y_hi = 1.0;

  x = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  y = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  nu = 1.0;
  rho = 1.0;
  n = x_num * y_num;
  t = 0.0;

  u = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  v = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  p = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  uvp_spiral ( nu, rho, n, x, y, t, u, v, p );

  strcpy ( header, "spiral" );
  s = 5.00;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void parameter_spiral_test ( )

/******************************************************************************/
/*
  Purpose:

    PARAMETER_SPIRAL_test monitors Spiral solution norms for various NU, RHO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 January 2015

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  int n;
  double nu;
  double *p;
  double p_norm;
  double rho;
  int seed;
  double t;
  double *u;
  double u_norm;
  double *v;
  double v_norm;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  printf ( "\n" );
  printf ( "PARAMETER_SPIRAL_test\n" );
  printf ( "  Spiral Flow:\n" );
  printf ( "  Monitor solution norms over time for various\n" );
  printf ( "  values of NU, RHO.\n" );

  n = 1000;

  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  p = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
/*
  Vary RHO.
*/
  printf ( "\n" );
  printf ( "  RHO affects the pressure scaling.\n" );
  printf ( "\n" );
  printf ( "     RHO         NU           T     ||U||       ||V||       ||P||\n" );
  printf ( "\n" );

  nu = 1.0;
  rho = 1.0;

  for ( j = 1; j <= 3; j++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_spiral ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      printf ( "  %10.4g  %10.4g  %8.4f  %10.4g  %10.4g  %10.4g\n",
        rho, nu, t, u_norm, v_norm, p_norm );
    }
    printf ( "\n" );
    rho = rho / 100.0;
  }
/*
  Vary NU.
*/
  printf ( "\n" );
  printf ( "  NU affects the time scaling.\n" );
  printf ( "\n" );
  printf ( "     RHO         NU           T     ||U||       ||V||       ||P||\n" );
  printf ( "\n" );

  nu = 1.0;
  rho = 1.0;

  for ( i = 1; i <= 4; i++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_spiral ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      printf ( "  %10.4g  %10.4g  %8.4f  %10.4g  %10.4g  %10.4g\n",
        rho, nu, t, u_norm, v_norm, p_norm );
    }

    printf ( "\n" );

    nu = nu / 10.0;
  }

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void uvp_taylor_test ( )

/******************************************************************************/
/*
  Purpose:

    UVP_TAYLOR_test samples the Taylor solution at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "UVP_TAYLOR_test\n" );
  printf ( "  Taylor Flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the square centered at (1.5,1.5) with 'radius' 1.0,\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.5;
  r8_hi = 2.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  t = 0.0;

  uvp_taylor ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void uvp_taylor_test2 ( )

/******************************************************************************/
/*
  Purpose:

    UVP_TAYLOR_test2 samples the Taylor solution on the boundary at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 March 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double nu;
  double *p;
  double r8_hi;
  double r8_lo;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  printf ( "\n" );
  printf ( "UVP_TAYLOR_test2\n" );
  printf ( "  Taylor Flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  on the boundary,\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the square centered at (1.5,1.5) with 'radius' 1.0,\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 400;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.5;
  r8_hi = 2.5;

  r8vec_linspace ( 100, r8_lo, r8_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = r8_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = r8_hi;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+100 );

  r8vec_linspace ( 100, r8_hi, r8_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = r8_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = r8_lo;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+300 );

  uvp_taylor ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void rhs_taylor_test ( )

/******************************************************************************/
/*
  Purpose:

    RHS_TAYLOR_test samples the Taylor right hand sides.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 January 2015

  Author:

    John Burkardt
*/
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "RHS_TAYLOR_test\n" );
  printf ( "  Taylor Flow:\n" );
  printf ( "  Sample the Navier-Stokes right hand sides\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the square centered at (1.5,1.5) with 'radius' 1.0,\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  f = ( double * ) malloc ( n * sizeof ( double ) );
  g = ( double * ) malloc ( n * sizeof ( double ) );
  h = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.5;
  r8_hi = +2.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  t = 0.0;

  rhs_taylor ( nu, rho, n, x, y, t, f, g, h );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  F:  %14.6g  %14.6g\n", r8vec_min ( n, f ), r8vec_max ( n, f ) );
  printf ( "  G:  %14.6g  %14.6g\n", r8vec_min ( n, g ), r8vec_max ( n, g ) );
  printf ( "  H:  %14.6g  %14.6g\n", r8vec_min ( n, h ), r8vec_max ( n, h ) );

  free ( f );
  free ( g );
  free ( h );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void resid_taylor_test ( )

/******************************************************************************/
/*
  Purpose:

    RESID_TAYLOR_test samples the Taylor residual at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 January 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "RESID_TAYLOR_test\n" );
  printf ( "  Taylor Flow:\n" );
  printf ( "  Sample the Navier-Stokes residuals\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the square centered at (1.5,1.5) with 'radius' 1.0,\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  pr = ( double * ) malloc ( n * sizeof ( double ) );
  ur = ( double * ) malloc ( n * sizeof ( double ) );
  vr = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.5;
  r8_hi = +2.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  t = 0.0;

  resid_taylor ( nu, rho, n, x, y, t, ur, vr, pr );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  Ur:  %14.6g  %14.6g\n", r8vec_amin ( n, ur ), r8vec_amax ( n, ur ) );
  printf ( "  Vr:  %14.6g  %14.6g\n", r8vec_amin ( n, vr ), r8vec_amax ( n, vr ) );
  printf ( "  Pr:  %14.6g  %14.6g\n", r8vec_amin ( n, pr ), r8vec_amax ( n, pr ) );

  free ( pr );
  free ( ur );
  free ( vr );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void gnuplot_taylor_test ( )

/******************************************************************************/
/*
  Purpose:

    GNUPLOT_TAYLOR_test plots a Taylor velocity field.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 January 2015

  Author:

    John Burkardt
*/
{
  char header[255];
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  printf ( "\n" );
  printf ( "GNUPLOT_TAYLOR_test:\n" );
  printf ( "  Taylor Flow:\n" );
  printf ( "  Generate a velocity field on a regular grid.\n" );
  printf ( "  Store in GNUPLOT data and command files.\n" );

  x_lo = 0.5;
  x_hi = 2.5;

  y_lo = 0.5;
  y_hi = 2.5;

  x = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  y = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  nu = 1.0;
  rho = 1.0;
  n = x_num * y_num;
  t = 0.0;

  u = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  v = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  p = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  uvp_taylor ( nu, rho, n, x, y, t, u, v, p );

  strcpy ( header, "taylor" );
  s = 0.10;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void parameter_taylor_test ( )

/******************************************************************************/
/*
  Purpose:

    PARAMETER_TAYLOR_test monitors Taylor solution norms for various NU, RHO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 January 2015

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  int n;
  double nu;
  double *p;
  double p_norm;
  double rho;
  int seed;
  double t;
  double *u;
  double u_norm;
  double *v;
  double v_norm;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  printf ( "\n" );
  printf ( "PARAMETER_TAYLOR_test\n" );
  printf ( "  Taylor Flow:\n" );
  printf ( "  Monitor solution norms over time for various\n" );
  printf ( "  values of NU, RHO.\n" );

  n = 1000;

  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  p = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.5;
  r8_hi = +2.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
/*
  Vary RHO.
*/
  printf ( "\n" );
  printf ( "  RHO affects the pressure scaling.\n" );
  printf ( "\n" );
  printf ( "     RHO         NU           T     ||U||       ||V||       ||P||\n" );
  printf ( "\n" );

  nu = 1.0;
  rho = 1.0;

  for ( j = 1; j <= 3; j++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_taylor ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      printf ( "  %10.4g  %10.4g  %8.4f  %10.4g  %10.4g  %10.4g\n",
        rho, nu, t, u_norm, v_norm, p_norm );
    }
    printf ( "\n" );
    rho = rho / 100.0;
  }
/*
  Vary NU.
*/
  printf ( "\n" );
  printf ( "  NU affects the time scaling.\n" );
  printf ( "\n" );
  printf ( "     RHO         NU           T     ||U||       ||V||       ||P||\n" );
  printf ( "\n" );

  nu = 1.0;
  rho = 1.0;

  for ( i = 1; i <= 4; i++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_taylor ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      printf ( "  %10.4g  %10.4g  %8.4f  %10.4g  %10.4g  %10.4g\n",
        rho, nu, t, u_norm, v_norm, p_norm );
    }

    printf ( "\n" );

    nu = nu / 10.0;
  }

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void uvp_vortex_test ( )

/******************************************************************************/
/*
  Purpose:

    UVP_VORTEX_test samples the Vortex solution at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 July 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "UVP_VORTEX_test\n" );
  printf ( "  Vortex Flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the square centered at (1.5,1.5) with 'radius' 1.0,\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.5;
  r8_hi = 1.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  t = 0.0;

  uvp_vortex ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void uvp_vortex_test2 ( )

/******************************************************************************/
/*
  Purpose:

    UVP_VORTEX_test2 samples the Vortex solution on the boundary at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 July 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double nu;
  double *p;
  double r8_hi;
  double r8_lo;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  printf ( "\n" );
  printf ( "UVP_VORTEX_test2\n" );
  printf ( "  Vortex Flow:\n" );
  printf ( "  Estimate the range of velocity and pressure\n" );
  printf ( "  on the boundary,\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the square centered at (1.5,1.5) with 'radius' 1.0,\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 400;

  p = ( double * ) malloc ( n * sizeof ( double ) );
  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  y = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.5;
  r8_hi = 1.5;

  r8vec_linspace ( 100, r8_lo, r8_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = r8_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = r8_hi;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+100 );

  r8vec_linspace ( 100, r8_hi, r8_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = r8_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = r8_lo;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+300 );

  uvp_vortex ( nu, rho, n, x, y, t, u, v, p );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  U:  %14.6g  %14.6g\n", r8vec_min ( n, u ), r8vec_max ( n, u ) );
  printf ( "  V:  %14.6g  %14.6g\n", r8vec_min ( n, v ), r8vec_max ( n, v ) );
  printf ( "  P:  %14.6g  %14.6g\n", r8vec_min ( n, p ), r8vec_max ( n, p ) );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void rhs_vortex_test ( )

/******************************************************************************/
/*
  Purpose:

    RHS_VORTEX_test samples the Vortex right hand sides.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 July 2015

  Author:

    John Burkardt
*/
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "RHS_VORTEX_test\n" );
  printf ( "  Vortex Flow:\n" );
  printf ( "  Sample the Navier-Stokes right hand sides\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the square centered at (1.5,1.5) with 'radius' 1.0,\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  f = ( double * ) malloc ( n * sizeof ( double ) );
  g = ( double * ) malloc ( n * sizeof ( double ) );
  h = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.5;
  r8_hi = +1.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  t = 0.0;

  rhs_vortex ( nu, rho, n, x, y, t, f, g, h );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  F:  %14.6g  %14.6g\n", r8vec_min ( n, f ), r8vec_max ( n, f ) );
  printf ( "  G:  %14.6g  %14.6g\n", r8vec_min ( n, g ), r8vec_max ( n, g ) );
  printf ( "  H:  %14.6g  %14.6g\n", r8vec_min ( n, h ), r8vec_max ( n, h ) );

  free ( f );
  free ( g );
  free ( h );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void resid_vortex_test ( )

/******************************************************************************/
/*
  Purpose:

    RESID_VORTEX_test samples the Vortex residual at the initial time.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 July 2015

  Author:

    John Burkardt
*/
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  printf ( "\n" );
  printf ( "RESID_VORTEX_test\n" );
  printf ( "  Vortex Flow:\n" );
  printf ( "  Sample the Navier-Stokes residuals\n" );
  printf ( "  at the initial time T = 0, using a region that is\n" );
  printf ( "  the square centered at (1.5,1.5) with 'radius' 1.0,\n" );
  printf ( "  Kinematic viscosity NU = %g\n", nu );
  printf ( "  Fluid density RHO = %g\n", rho );

  n = 1000;

  pr = ( double * ) malloc ( n * sizeof ( double ) );
  ur = ( double * ) malloc ( n * sizeof ( double ) );
  vr = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.5;
  r8_hi = +1.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  t = 0.0;

  resid_vortex ( nu, rho, n, x, y, t, ur, vr, pr );

  printf ( "\n" );
  printf ( "           Minimum       Maximum\n" );
  printf ( "\n" );
  printf ( "  Ur:  %14.6g  %14.6g\n", r8vec_amin ( n, ur ), r8vec_amax ( n, ur ) );
  printf ( "  Vr:  %14.6g  %14.6g\n", r8vec_amin ( n, vr ), r8vec_amax ( n, vr ) );
  printf ( "  Pr:  %14.6g  %14.6g\n", r8vec_amin ( n, pr ), r8vec_amax ( n, pr ) );

  free ( pr );
  free ( ur );
  free ( vr );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void gnuplot_vortex_test ( )

/******************************************************************************/
/*
  Purpose:

    GNUPLOT_VORTEX_test plots a Vortex velocity field.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 July 2015

  Author:

    John Burkardt
*/
{
  char header[255];
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  printf ( "\n" );
  printf ( "GNUPLOT_VORTEX_test:\n" );
  printf ( "  Vortex Flow:\n" );
  printf ( "  Generate a velocity field on a regular grid.\n" );
  printf ( "  Store in GNUPLOT data and command files.\n" );

  x_lo = 0.5;
  x_hi = 1.5;

  y_lo = 0.5;
  y_hi = 1.5;

  x = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  y = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  nu = 1.0;
  rho = 1.0;
  n = x_num * y_num;
  t = 0.0;

  u = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  v = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );
  p = ( double * ) malloc ( x_num * y_num * sizeof ( double ) );

  uvp_vortex ( nu, rho, n, x, y, t, u, v, p );

  strcpy ( header, "vortex" );
  s = 0.10;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}
/******************************************************************************/

void parameter_vortex_test ( )

/******************************************************************************/
/*
  Purpose:

    PARAMETER_VORTEX_test monitors Vortex solution norms for various NU, RHO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 July 2015

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int k;
  int n;
  double nu;
  double *p;
  double p_norm;
  double rho;
  int seed;
  double t;
  double *u;
  double u_norm;
  double *v;
  double v_norm;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  printf ( "\n" );
  printf ( "PARAMETER_VORTEX_test\n" );
  printf ( "  Vortex Flow:\n" );
  printf ( "  Monitor solution norms over time for various\n" );
  printf ( "  values of NU, RHO.\n" );

  n = 1000;

  u = ( double * ) malloc ( n * sizeof ( double ) );
  v = ( double * ) malloc ( n * sizeof ( double ) );
  p = ( double * ) malloc ( n * sizeof ( double ) );

  r8_lo = 0.5;
  r8_hi = +1.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, &seed );
/*
  Vary RHO.
*/
  printf ( "\n" );
  printf ( "  RHO affects the pressure scaling.\n" );
  printf ( "\n" );
  printf ( "     RHO         NU           T     ||U||       ||V||       ||P||\n" );
  printf ( "\n" );

  nu = 1.0;
  rho = 1.0;

  for ( j = 1; j <= 3; j++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_vortex ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      printf ( "  %10.4g  %10.4g  %8.4f  %10.4g  %10.4g  %10.4g\n",
        rho, nu, t, u_norm, v_norm, p_norm );
    }
    printf ( "\n" );
    rho = rho / 100.0;
  }
/*
  Vary NU.
*/
  printf ( "\n" );
  printf ( "  NU affects the time scaling.\n" );
  printf ( "\n" );
  printf ( "     RHO         NU           T     ||U||       ||V||       ||P||\n" );
  printf ( "\n" );

  nu = 1.0;
  rho = 1.0;

  for ( i = 1; i <= 4; i++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_vortex ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      printf ( "  %10.4g  %10.4g  %8.4f  %10.4g  %10.4g  %10.4g\n",
        rho, nu, t, u_norm, v_norm, p_norm );
    }

    printf ( "\n" );

    nu = nu / 10.0;
  }

  free ( p );
  free ( u );
  free ( v );
  free ( x );
  free ( y );

  return;
}

