# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "stochastic_diffusion.h"

int main ( );
void diffusivity_1d_pwc_test ( );
void diffusivity_1d_xk_test ( );
void diffusivity_2d_bnt_contour ( );
void diffusivity_2d_elman_contour ( );
void diffusivity_2d_ntw_contour ( );
void diffusivity_2d_pwc_test ( );
void diffusivity_2d_pwc_contour ( int h, int w, double a, double b, double c, 
  double d );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for stochastic_diffusion_test.

  Discussion:

    stochastic_diffusion_test tests stochastic_diffusion.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 March 2019

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "stochastic_diffusion_test\n" );
  printf ( "  C version\n" );
  printf ( "  Test stochastic_diffusion.\n" );

  diffusivity_1d_pwc_test ( );
  diffusivity_1d_xk_test ( );
  diffusivity_2d_bnt_contour ( );
  diffusivity_2d_elman_contour ( );
  diffusivity_2d_ntw_contour ( );
  diffusivity_2d_pwc_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "stochastic_diffusion_test\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void diffusivity_1d_pwc_test ( )

/******************************************************************************/
/*
  Purpose:

     diffusivity_1d_pwc_test tests diffusivity_1d_pwc.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 March 2019

  Author:

    John Burkardt
*/
{
  char command_filename[] = "diffusivity_1d_pwc_commands.txt";
  FILE *command_unit;
  char data_filename[] = "diffusivity_1d_pwc_data.txt";
  FILE *data_unit;
  int j;
  int nc;
  int np;
  double vc[] = { 1.0,  1.5,  3.0,   1.2, 1.0, 0.8, 0.2,  0.4, 0.8, 1.0 };
  double *vp;
  double vp_max;
  double x_max;
  double x_min;
  double xc[] = { -0.9, -0.5, -0.45, -0.1, 0.2, 0.3, 0.32, 0.7, 0.85 };
  double *xp;

  printf ( "\n" );
  printf ( " diffusivity_1d_pwc_test\n" );
  printf ( "  Test diffusivity_1d_pwc.\n" );
/*
  Set up the spatial grid.
*/
  nc = 10;
/*
  Sample the diffusivity.
*/
  np = 100;
  x_min = -1.0;
  x_max = +1.0;
  xp = r8vec_linspace_new ( np, x_min, x_max );
/*
  Compute the diffusivity field.
*/
  vp = diffusivity_1d_pwc ( nc, xc, vc, np, xp );
/*
  Create data file.
*/
  data_unit = fopen ( data_filename, "wt" );
  for ( j = 0; j < np; j++ )
  {
    fprintf ( data_unit, "  %14.6g  %14.6g\n", xp[j], vp[j] );
  }
  fclose ( data_unit );
  printf ( "\n" );
  printf ( "  Created graphics data file '%s'\n", data_filename );
/*
  Create the command file.
*/
  vp_max = r8vec_max ( np, vp );

  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'diffusivity_1d_pwc.png'\n" );
  fprintf ( command_unit, "set xlabel '<---X--->'\n" );
  fprintf ( command_unit, "set ylabel '<---Rho(X)--->'\n" );
  fprintf ( command_unit, "set yrange [0.0:%g]\n", vp_max );
  fprintf ( command_unit, "set title 'PWC 1D Stochastic diffusivity function'\n" );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set style data lines\n" );
  fprintf ( command_unit, "plot '%s' using 1:2 lw 3 linecolor rgb 'red'\n", data_filename );

  fclose ( command_unit );

  printf ( "  Created graphics command file '%s'\n", command_filename );
/*
  Free memory.
*/
  free ( vp );
  free ( xp );

  return;
}
/******************************************************************************/

void diffusivity_1d_xk_test ( )

/******************************************************************************/
/*
  Purpose:

     diffusivity_1d_xk_test tests diffusivity_1d_xk.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Reference:

    Dongbin Xiu, George Karniadakis,
    Modeling uncertainty in steady state diffusion problems via
    generalized polynomial chaos,
    Computer Methods in Applied Mechanics and Engineering,
    Volume 191, 2002, pages 4927-4948.
*/
{
  double *dc;
  double dc_max;
  double dc0;
  char command_filename[] = "diffusivity_1d_xk_commands.txt";
  FILE *command_unit;
  char data_filename[] = "diffusivity_1d_xk_data.txt";
  FILE *data_unit;
  int j;
  int m;
  int n;
  int seed;
  double *omega;
  double *x;
  double x_min;
  double x_max;

  printf ( "\n" );
  printf ( " diffusivity_1d_xk_test\n" );
  printf ( "  Test diffusivity_1d_xk.\n" );
/*
  Set up the spatial grid.
*/
  n = 51;
  x_min = -1.0;
  x_max = +1.0;
  x = r8vec_linspace_new ( n, x_min, x_max );
/*
  Sample the OMEGA values.
*/
  m = 5;
  seed = 123456789;
  omega = r8vec_normal_01_new ( m, &seed );
/*
  Compute the diffusivity field.
*/
  dc0 = 10.0;
  dc = diffusivity_1d_xk ( dc0, m, omega, n, x );
/*
  Create data file.
*/
  data_unit = fopen ( data_filename, "wt" );
  for ( j = 0; j < n; j++ )
  {
    fprintf ( data_unit, "  %14.6g  %14.6g\n", x[j], dc[j] );
  }
  fclose ( data_unit );
  printf ( "\n" );
  printf ( "  Created graphics data file '%s'\n", data_filename );
/*
  Create the command file.
*/
  dc_max = r8vec_max ( n, dc );

  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'diffusivity_1d_xk.png'\n" );
  fprintf ( command_unit, "set xlabel '<---X--->'\n" );
  fprintf ( command_unit, "set ylabel '<---DC(X)--->'\n" );
  fprintf ( command_unit, "set yrange [0.0:%g]\n", dc_max );
  fprintf ( command_unit, "set title 'XK Stochastic diffusivity function'\n" );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set style data lines\n" );
  fprintf ( command_unit, "plot '%s' using 1:2 lw 3 linecolor rgb 'red'\n", data_filename );

  fclose ( command_unit );

  printf ( "  Created graphics command file '%s'\n", command_filename );
/*
  Free memory.
*/
  free ( dc );
  free ( omega );
  free ( x );

  return;
}
/******************************************************************************/

void diffusivity_2d_bnt_contour ( )

/******************************************************************************/
/*
  Purpose:

    DIFFUSIVITY_2D_BNT_CONTOUR displays contour plots of a 2D stochastic diffusivity function.

  Discussion:

    The diffusivity function is computed by DIFFUSIVITY_2D_BNT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Reference:

    Ivo Babuska, Fabio Nobile, Raul Tempone,
    A stochastic collocation method for elliptic partial differential equations
    with random input data,
    SIAM Journal on Numerical Analysis,
    Volume 45, Number 3, 2007, pages 1005-1034.
*/
{
  char command_filename[] = "diffusivity_2d_bnt_commands.txt";
  FILE *command_unit;
  char data_filename[] = "diffusivity_2d_bnt_data.txt";
  FILE *data_unit;
  double *dc;
  double dc0;
  int i;
  int j;
  int m = 4;
  int n;
  int nx = 41;
  int ny = 31;
  double *omega;
  int seed;
  double *xmat;
  double *xvec;
  double *ymat;
  double *yvec;

  printf ( "\n" );
  printf ( "DIFFUSIVITY_2D_BNT_CONTOUR\n" );
  printf ( "  Display contour or surface plots of the stochastic\n" );
  printf ( "  diffusivity function defined by DIFFUSIVITY_2D_BNT.\n" );
  printf ( "\n" );
  printf ( "  The first plot uses uniform random values for OMEGA.\n" );
  printf ( "  The second uses Gaussian (normal) random values.\n" );
/*
  Set the spatial grid.
*/
  xvec = r8vec_linspace_new ( nx, -1.5, 0.0 );
  yvec = r8vec_linspace_new ( ny, -0.4, 0.8 );

  xmat = ( double * ) malloc ( nx * ny * sizeof ( double ) );
  ymat = ( double * ) malloc ( nx * ny * sizeof ( double ) );
  r8vec_mesh_2d ( nx, ny, xvec, yvec, xmat, ymat );
/*
  Sample OMEGA.
*/
  seed = 123456789;
  omega = r8vec_uniform_01_new ( m, &seed );
/*
  Compute the diffusivity field.
*/
  dc0 = 10.0;
  n = nx * ny;
  dc = diffusivity_2d_bnt ( dc0, omega, n, xmat, ymat );
/*
  Create a data file.
*/
  data_unit = fopen ( data_filename, "wt" );
  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      fprintf ( data_unit, "  %14.6g  %14.6g  %14.6g\n",
        xmat[i+j*nx], ymat[i+j*nx], dc[i+j*nx] );
    }
    fprintf ( data_unit, "\n" );
  }
  fclose ( data_unit );
  printf ( "\n" );
  printf ( "  Created graphics data file '%s'\n", data_filename );
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'diffusivity_2d_bnt.png'\n" );
  fprintf ( command_unit, "set xlabel '<---X--->'\n" );
  fprintf ( command_unit, "set ylabel '<---Y--->'\n" );
  fprintf ( command_unit, "set zlabel '<---DC(X,Y)--->'\n" );
  fprintf ( command_unit, "set title 'BNT Stochastic diffusivity function'\n" );
  fprintf ( command_unit, "set contour\n" );
  fprintf ( command_unit, "set timestamp\n" );
  fprintf ( command_unit, "set cntrparam levels 10\n" );
  fprintf ( command_unit, "#set view map\n" );
  fprintf ( command_unit, "set view 75, 75\n" );
  fprintf ( command_unit, "unset key\n" );
  fprintf ( command_unit, "splot '%s'\n", data_filename );

  fclose ( command_unit );

  printf ( "  Created graphics command file '%s'\n", command_filename );

  free ( dc );
  free ( omega );
  free ( xmat );
  free ( xvec );
  free ( ymat );
  free ( yvec );

  return;
}
/******************************************************************************/

void diffusivity_2d_elman_contour ( )

/******************************************************************************/
/*
  Purpose:

    DIFFUSIVITY_2D_ELMAN_CONTOUR displays a contour plot of a 2D stochastic diffusivity function.

  Discussion:

    The diffusivity function is computed by DIFFUSIVITY_2D_ELMAN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Reference:

    Howard Elman, Darran Furnaval,
    Solving the stochastic steady-state diffusion problem using multigrid,
    IMA Journal on Numerical Analysis,
    Volume 27, Number 4, 2007, pages 675-688.
*/
{
  double a;
  double cl;
  char command_filename[] = "diffusivity_2d_elman_commands.txt";
  FILE *command_unit;
  char data_filename[] = "diffusivity_2d_elman_data.txt";
  FILE *data_unit;
  double *dc;
  double dc0;
  int i;
  int j;
  int m_1d = 5;
  int nx = 51;
  int ny = 51;
  double *omega;
  int seed;
  double *xmat;
  double *xvec;
  double *ymat;
  double *yvec;

  printf ( "\n" );
  printf ( "DIFFUSIVITY_2D_ELMAN_CONTOUR\n" );
  printf ( "  Display contour or surface plots of the stochastic\n" );
  printf ( "  diffusivity function defined by DIFFUSIVITY_2D_ELMAN.\n" );
/*
  Set the spatial grid.
*/
  a = 1.0;
  xvec = r8vec_linspace_new ( nx, -a, a );
  yvec = r8vec_linspace_new ( ny, -a, a );

  xmat = ( double * ) malloc ( nx * ny * sizeof ( double ) );
  ymat = ( double * ) malloc ( nx * ny * sizeof ( double ) );
  r8vec_mesh_2d ( nx, ny, xvec, yvec, xmat, ymat );
/*
  Sample OMEGA.
*/
  seed = 123456789;
  omega = r8vec_normal_01_new ( m_1d * m_1d, &seed );
/*
  Compute the diffusivity field.
*/
  cl = 0.1;
  dc0 = 10.0;
  dc = diffusivity_2d_elman ( a, cl, dc0, m_1d, omega, nx, nx, xmat, ymat );
/*
  Create a data file.
*/
  data_unit = fopen ( data_filename, "wt" );
  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      fprintf ( data_unit, "  %14.6g  %14.6g  %14.6g\n",
        xmat[i+j*nx], ymat[i+j*nx], dc[i+j*nx] );
    }
    fprintf ( data_unit, "\n" );
  }
  fclose ( data_unit );
  printf ( "\n" );
  printf ( "  Created graphics data file '%s'\n", data_filename );
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'diffusivity_2d_elman.png'\n" );
  fprintf ( command_unit, "set xlabel '<---X--->'\n" );
  fprintf ( command_unit, "set ylabel '<---Y--->'\n" );
  fprintf ( command_unit, "set zlabel '<---DC(X,Y)--->'\n" );
  fprintf ( command_unit, "set title 'Elman Stochastic diffusivity function'\n" );
  fprintf ( command_unit, "set contour\n" );
  fprintf ( command_unit, "set timestamp\n" );
  fprintf ( command_unit, "set cntrparam levels 10\n" );
  fprintf ( command_unit, "#set view map\n" );
  fprintf ( command_unit, "set view 75, 75\n" );
  fprintf ( command_unit, "unset key\n" );
  fprintf ( command_unit, "splot '%s'\n", data_filename );

  fclose ( command_unit );

  printf ( "  Created graphics command file '%s'\n", command_filename );

  free ( dc );
  free ( omega );
  free ( xmat );
  free ( xvec );
  free ( ymat );
  free ( yvec );

  return;
}
/******************************************************************************/

void diffusivity_2d_ntw_contour ( )

/******************************************************************************/
/*
  Purpose:

    DIFFUSIVITY_2D_NTW_CONTOUR displays a contour plot of a 2D stochastic diffusivity function.

  Discussion:

    The diffusivity function is computed by DIFFUSIVITY_2D_NTW.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Reference:

    Fabio Nobile, Raul Tempone, Clayton Webster,
    A Sparse Grid Stochastic Collocation Method for Partial Differential
    Equations with Random Input Data,
    SIAM Journal on Numerical Analysis,
    Volume 46, Number 5, 2008, pages 2309-2345.
*/
{
  double cl;
  char command_filename[] = "diffusivity_2d_ntw_commands.txt";
  FILE *command_unit;
  double d;
  char data_filename[] = "diffusivity_2d_ntw_data.txt";
  FILE *data_unit;
  double *dc;
  double dc0;
  int i;
  int j;
  int m = 21;
  int nx = 101;
  int ny = 101;
  double *omega;
  int seed;
  double *xmat;
  double *xvec;
  double *ymat;
  double *yvec;

  printf ( "\n" );
  printf ( "DIFFUSIVITY_2D_NTW_CONTOUR\n" );
  printf ( "  Display contour or surface plots of the stochastic\n" );
  printf ( "  diffusivity function defined by DIFFUSIVITY_2D_NTW.\n" );
/*
  Set the spatial grid.
*/
  d = 1.0;
  xvec = r8vec_linspace_new ( nx, 0.0, d );
  yvec = r8vec_linspace_new ( ny, 0.0, d );

  xmat = ( double * ) malloc ( nx * ny * sizeof ( double ) );
  ymat = ( double * ) malloc ( nx * ny * sizeof ( double ) );
  r8vec_mesh_2d ( nx, ny, xvec, yvec, xmat, ymat );
/*
  Sample OMEGA.
  We rescale to  [-sqrt(3),sqrt(3)].
*/
  seed = 123456789;
  omega = r8vec_uniform_01_new ( m, &seed );
  for ( i = 0; i < m; i++ )
  {
    omega[i] = ( 1.0 - omega[i] ) * ( - sqrt ( 3.0 ) ) 
             +         omega[i]   *     sqrt ( 3.0 );
  }
/*
  Evaluate the diffusivity field.
*/
  cl = 0.1;
  dc0 = 0.5;
  dc = diffusivity_2d_ntw ( cl, dc0, m, omega, nx * ny, xmat, ymat );
/*
  Create a data file.
*/
  data_unit = fopen ( data_filename, "wt" );
  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      fprintf ( data_unit, "  %14.6g  %14.6g  %14.6g\n", 
        xmat[i+j*nx], ymat[i+j*nx], dc[i+j*nx] );
    }
    fprintf ( data_unit, "\n" );
  }
  fclose ( data_unit );
  printf ( "\n" );
  printf ( "  Created graphics data file '%s'\n", data_filename );
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'diffusivity_2d_ntw.png'\n" );
  fprintf ( command_unit, "set xlabel '<---X--->'\n" );
  fprintf ( command_unit, "set ylabel '<---Y--->'\n" );
  fprintf ( command_unit, "set zlabel '<---DC(X,Y)--->'\n" );
  fprintf ( command_unit, "set title 'NTW Stochastic diffusivity function'\n" );
  fprintf ( command_unit, "set contour\n" );
  fprintf ( command_unit, "set timestamp\n" );
  fprintf ( command_unit, "set cntrparam levels 15\n" );
  fprintf ( command_unit, "#set view map\n" );
  fprintf ( command_unit, "set view 65, 65\n" );
  fprintf ( command_unit, "set key\n" );
  fprintf ( command_unit, "splot '%s'\n", data_filename );

  fclose ( command_unit );

  printf ( "  Created graphics command file '%s'.\n", command_filename );

  free ( dc );
  free ( omega );
  free ( xmat );
  free ( xvec );
  free ( ymat );
  free ( yvec );

  return;
}
/******************************************************************************/

void diffusivity_2d_pwc_test ( )

/******************************************************************************/
/*
  Purpose:

    diffusivity_2d_pwc_test tests diffusivity_2d_pwc.

  Discussion:

    This function calls diffusivity_2d_pwc_contour, which evaluates
    diffusivity_2d_pwc() over a given [a,b]x[c,d] grid.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 March 2019

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double d;
  int h;
  int w;

  h = 5;
  w = 4;
  a = -1.0;
  b = +1.0;
  c = -1.0;
  d = +1.0;
  diffusivity_2d_pwc_contour ( h, w, a, b, c, d );

  return;
}
/******************************************************************************/

void diffusivity_2d_pwc_contour ( int h, int w, double a, double b, double c, 
  double d )

/******************************************************************************/
/*
  Purpose:

    diffusivity_2d_pwc_contour displays contour plots of a 2D stochastic diffusivity function.

  Discussion:

    The diffusivity function is computed by diffusivity_2d_pwc.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 March 2019

  Author:

    John Burkardt

  Parameters:

    Input, int H, W, the height and width of the element grid.

    Input, double A, B, C, D, the lower and upper limits of X, and of Y.
*/
{
  char command_filename[] = "diffusivity_2d_pwc_commands.txt";
  FILE *command_unit;
  char data_filename[] = "diffusivity_2d_pwc_data.txt";
  FILE *data_unit;
  int i;
  int j;
  int n;
  int nx;
  int ny;
  double *omega;
  double *rho;
  int seed;
  double *xmat;
  double *xvec;
  double *ymat;
  double *yvec;

  printf ( "\n" );
  printf ( "diffusivity_2d_pwc_contour\n" );
  printf ( "  Test diffusivity_2d_pwc\n" );
  printf ( "  Display contour or surface plots of a stochastic\n" );
  printf ( "  diffusivity function defined by diffusivity_2d_pwc.\n" );
  printf ( "\n" );
  printf ( "  Underlying grid is %d elements wide (X) and %d high (Y)\n", w, h );

  nx = 101;
  ny = 101;
/*
  Set the spatial grid.
*/
  xvec = r8vec_linspace_new ( nx, a, b );
  yvec = r8vec_linspace_new ( ny, c, d );

  xmat = ( double * ) malloc ( nx * ny * sizeof ( double ) );
  ymat = ( double * ) malloc ( nx * ny * sizeof ( double ) );
  r8vec_mesh_2d ( nx, ny, xvec, yvec, xmat, ymat );

  seed = 123456789;
  omega = r8vec_uniform_ab_new ( h * w, 0.5, 1.5, &seed );

  n = nx * ny;
/*
  Compute the diffusivity field.
*/
  rho = diffusivity_2d_pwc ( h, w, a, b, c, d, omega, n, xmat, ymat );
/*
  Create a data file.
*/
  data_unit = fopen ( data_filename, "wt" );
  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      fprintf ( data_unit, "  %14.6g  %14.6g  %14.6g\n",
        xmat[i+j*nx], ymat[i+j*nx], rho[i+j*nx] );
    }
    fprintf ( data_unit, "\n" );
  }
  fclose ( data_unit );
  printf ( "\n" );
  printf ( "  Created graphics data file '%s'\n", data_filename );
/*
  Create the command file.
*/
  command_unit = fopen ( command_filename, "wt" );

  fprintf ( command_unit, "# %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output 'diffusivity_2d_pwc.png'\n" );
  fprintf ( command_unit, "set xlabel '<---X--->'\n" );
  fprintf ( command_unit, "set ylabel '<---Y--->'\n" );
  fprintf ( command_unit, "set zlabel '<---DC(X,Y)--->'\n" );
  fprintf ( command_unit, "set title 'PWC Stochastic diffusivity function'\n" );
  fprintf ( command_unit, "set contour\n" );
  fprintf ( command_unit, "set timestamp\n" );
  fprintf ( command_unit, "set cntrparam levels 10\n" );
  fprintf ( command_unit, "#set view map\n" );
  fprintf ( command_unit, "set view 75, 75\n" );
  fprintf ( command_unit, "unset key\n" );
  fprintf ( command_unit, "splot '%s'\n", data_filename );

  fclose ( command_unit );

  printf ( "  Created graphics command file '%s'\n", command_filename );
/*
  Free memory.
*/
  free ( omega );
  free ( rho );
  free ( xmat );
  free ( xvec );
  free ( ymat );
  free ( yvec );

  return;
}

