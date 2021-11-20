# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "newton_interp_1d.h"
# include "test_interp.h"

int main ( );
void newton_coef_1d_test ( );
void newton_value_1d_test ( );
void newton_interp_1d_test01 ( int prob );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    NEWTON_INTERP_1D_TEST tests the NEWTON_INTERP_1D library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 July 2015

  Author:

    John Burkardt
*/
{
  int prob;
  int prob_num;

  timestamp ( );
  printf ( "\n" );
  printf ( "NEWTON_INTERP_1D_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the NEWTON_INTERP_1D library.\n" );
  printf ( "  The R8LIB library is needed.\n" );
  printf ( "  This test needs the TEST_INTERP library as well.\n" );

  newton_coef_1d_test ( );

  newton_value_1d_test ( );

  prob_num = p00_prob_num ( );

  for ( prob = 1; prob <= prob_num; prob++ )
  {
     newton_interp_1d_test01 ( prob );
  }
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "NEWTON_INTERP_1D_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void newton_coef_1d_test ( )

/******************************************************************************/
/*
  Purpose:

    NEWTON_COEF_1D_TEST tests NEWTON_COEF_1D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 July 2015

  Author:

    John Burkardt
*/
{
  double *cd;
  int nd = 5;
  double xd[5] = { 0.0, 1.0, 2.0, 3.0, 4.0 };
  double yd[5] = { 24.0, 0.0, 0.0, 0.0, 0.0 };

  printf ( "\n" );
  printf ( "NEWTON_COEF_1D_TEST\n" );
  printf ( "  NEWTON_COEF_1D sets the coefficients for a 1D Newton interpolation.\n" );

  r8vec2_print ( nd, xd, yd, "  Interpolation data:" );

  cd = newton_coef_1d ( nd, xd, yd );

  r8vec_print ( nd, cd, "  Newton interpolant coefficients:" );

  free ( cd );

  return;
}
/******************************************************************************/

void newton_value_1d_test ( )

/******************************************************************************/
/*
  Purpose:

    NEWTON_VALUE_1D_TEST tests NEWTON_VALUE_1D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 July 2015

  Author:

    John Burkardt
*/
{
  double cd[5] = { 24.0, -24.0, +12.0, -4.0, 1.0 };
  int nd = 5;
  int ni = 16;
  double x_hi;
  double x_lo;
  double xd[5] = { 0.0, 1.0, 2.0, 3.0, 4.0 };
  double *xi;
  double *yi;

  printf ( "\n" );
  printf ( "NEWTON_VALUE_1D_TEST\n" );
  printf ( "  NEWTON_VALUE_1D evaluates a Newton 1d interpolant.\n" );

  r8vec2_print ( nd, xd, cd, "  The Newton interpolant data:" );

  x_lo = 0.0;
  x_hi = 5.0;
  xi = r8vec_linspace_new ( ni, x_lo, x_hi );
  yi = newton_value_1d ( nd, xd, cd, ni, xi );

  r8vec2_print ( ni, xi, yi, "  Newton interpolant values:" );

  free ( xi );
  free ( yi );

  return;
}
/******************************************************************************/

void newton_interp_1d_test01 ( int prob )

/******************************************************************************/
/*
  Purpose:

    NEWTON_INTERP_1D_TEST01 tests NEWTON_INTERP_1D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 July 2015

  Author:

    John Burkardt
*/
{
  double *cd;
  char command_filename[255];
  FILE *command_unit;
  char data_filename[255];
  FILE *data_unit;
  int i;
  double interp_error;
  char interp_filename[255];
  FILE *interp_unit;
  int j;
  double ld;
  double li;
  int nd;
  int ni;
  char output_filename[255];
  double *xd;
  double *xi;
  double xmax;
  double xmin;
  double *xy;
  double *yd;
  double *yi;
  double ymax;
  double ymin;

  printf ( "\n" );
  printf ( "NEWTON_INTERP_1D_TEST01:\n" );
  printf ( "  Interpolate data from TEST_INTERP problem #%d\n", prob );

  nd = p00_data_num ( prob );
  printf ( "  Number of data points = %d\n", nd );

  xy = p00_data ( prob, 2, nd );
  
  xd = ( double * ) malloc ( nd * sizeof ( double ) );
  yd = ( double * ) malloc ( nd * sizeof ( double ) );

  for ( i = 0; i < nd; i++ )
  {
    xd[i] = xy[0+i*2];
    yd[i] = xy[1+i*2];
  }

  r8vec2_print ( nd, xd, yd, "  X, Y data:" );
/*
  Get the Newton coefficients.
*/
  cd = newton_coef_1d ( nd, xd, yd );
/*
  #1:  Does interpolant match function at interpolation points?
*/
  ni = nd;
  xi = r8vec_copy_new ( ni, xd );
  yi = newton_value_1d ( nd, xd, cd, ni, xi );

  interp_error = r8vec_norm_affine ( ni, yi, yd ) / ( double ) ( ni );

  printf ( "\n" );
  printf ( "  L2 interpolation error averaged per interpolant node = %g\n", interp_error );

  free ( xi );
  free ( yi );
/*
  #2: Compare estimated curve length to piecewise linear (minimal) curve length.
  Assume data is sorted, and normalize X and Y dimensions by (XMAX-XMIN) and
  (YMAX-YMIN).
*/
  xmin = r8vec_min ( nd, xd );
  xmax = r8vec_max ( nd, xd );
  ymin = r8vec_min ( nd, yd );
  ymax = r8vec_max ( nd, yd );

  ni = 501;
  xi = r8vec_linspace_new ( ni, xmin, xmax );
  yi = newton_value_1d ( nd, xd, cd, ni, xi );

  ld = 0.0;
  for ( i = 0; i < nd - 1; i++ )
  {
    ld = ld + sqrt ( pow ( ( xd[i+1] - xd[i] ) / ( xmax - xmin ), 2 )
                   + pow ( ( yd[i+1] - yd[i] ) / ( ymax - ymin ), 2 ) ); 
  }

  li = 0.0;
  for ( i = 0; i < ni - 1; i++ )
  {
    li = li + sqrt ( pow ( ( xi[i+1] - xi[i] ) / ( xmax - xmin ), 2 )
                   + pow ( ( yi[i+1] - yi[i] ) / ( ymax - ymin ), 2 ) );
  }

  printf ( "\n" );
  printf ( "  Normalized length of piecewise linear interpolant = %g\n", ld );
  printf ( "  Normalized length of Newton interpolant           = %g\n", li );

  free ( xi );
  free ( yi );
/*
  Create data file.
*/
  sprintf ( data_filename, "data%02d.txt", prob );
  data_unit = fopen ( data_filename, "wt" );
  for ( j = 0; j < nd; j++ )
  {
    fprintf ( data_unit, "  %14g  %14g\n", xd[j], yd[j] );
  }
  fclose ( data_unit );
  printf ( "\n" );
  printf ( "  Created graphics data file \"%s\".\n", data_filename );
/*
  Create interp file.
*/
  ni = 501;
  xmin = r8vec_min ( nd, xd );
  xmax = r8vec_max ( nd, xd );
  xi = r8vec_linspace_new ( ni, xmin, xmax );
  yi = newton_value_1d ( nd, xd, cd, ni, xi );

  sprintf ( interp_filename, "interp%02d.txt", prob );
  interp_unit = fopen ( interp_filename, "wt" );
  for ( j = 0; j < ni; j++ )
  {
    fprintf ( interp_unit, "  %g  %g\n", xi[j], yi[j] );
  }
  fclose ( interp_unit );
  printf ( "  Created graphics interp file \"%s\".\n", interp_filename );
/*
  Plot the data and the interpolant.
*/
  sprintf ( command_filename, "commands%02d.txt", prob );
  command_unit = fopen ( command_filename, "wt" );

  sprintf ( output_filename, "plot%02d.png", prob );

  fprintf ( command_unit, "# %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "# Usage:\n" );
  fprintf ( command_unit, "#  gnuplot < %s\n", command_filename );
  fprintf ( command_unit, "#\n" );
  fprintf ( command_unit, "set term png\n" );
  fprintf ( command_unit, "set output '%s'\n", output_filename );
  fprintf ( command_unit, "set xlabel '<---X--->'\n" );
  fprintf ( command_unit, "set ylabel '<---Y--->'\n" );
  fprintf ( command_unit, "set title 'Data versus Newton polynomial interpolant'\n" );
  fprintf ( command_unit, "set grid\n" );
  fprintf ( command_unit, "set style data lines\n" );
  fprintf ( command_unit, "plot '%s' using 1:2 with points pt 7 ps 2 lc rgb 'blue',\\\n",
    data_filename );
  fprintf ( command_unit, "     '%s' using 1:2 lw 3 linecolor rgb 'red'\n", 
    interp_filename );

  fclose ( command_unit );
  printf ( "  Created graphics command file \"%s\".\n", command_filename );
/*
  Free memory.
*/
  free ( cd );
  free ( xd );
  free ( xi );
  free ( yd );
  free ( yi );

  return;
}

