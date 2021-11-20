# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "vandermonde_interp_1d.h"
# include "condition.h"
# include "qr_solve.h"
# include "test_interp.h"
# include "r8lib.h"

int main ( );
void vandermonde_coef_1d_test ( );
void vandermonde_matrix_1d_test ( );
void vandermonde_value_1d_test ( );
void test01 ( int prob );
void test02 ( int prob );
void r8poly_print ( int n, double a[], char *title );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for VANDERMONDE_INTERP_1D_TEST.

  Discussion:

    VANDERMONDE_INTERP_1D_TEST tests the VANDERMONDE_INTERP_1D library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 July 2015

  Author:

    John Burkardt
*/
{
  int prob;
  int prob_num;

  timestamp ( );
  printf ( "\n" );
  printf ( "VANDERMONDE_INTERP_1D_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the VANDERMONDE_INTERP_1D library.\n" );
  printf ( "  The QR_SOLVE library is needed.\n" );
  printf ( "  The R8LIB library is needed.\n" );
  printf ( "  This test needs the CONDITION library.\n" );
  printf ( "  This test needs the TEST_INTERP library.\n" );

  vandermonde_coef_1d_test ( );

  vandermonde_matrix_1d_test ( );

  vandermonde_value_1d_test ( );

  prob_num = p00_prob_num ( );

  for ( prob = 1; prob <= prob_num; prob++ )
  {
    test01 ( prob );
  }

  for ( prob = 1; prob <= prob_num; prob++ )
  {
    test02 ( prob );
  }
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "VANDERMONDE_INTERP_1D_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void vandermonde_coef_1d_test ( )

/******************************************************************************/
/*
  Purpose:

    VANDERMONDE_COEF_1D_TEST tests VANDERMONDE_COEF_1D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 July 2015

  Author:

    John Burkardt
*/
{
  double *cd;
  int nd = 5;
  double xd[5] = { 0.0, 1.0, 2.0, 3.0, 4.0 };
  double yd[5] = { 24.0, 0.0, 0.0, 0.0, 0.0 };

  printf ( "\n" );
  printf ( "VANDERMONDE_COEF_1D_TEST\n" );
  printf ( "  VANDERMONDE_COEF_1D sets the Vandermonde coefficients for 1D interpolation.\n" );

  r8vec2_print ( nd, xd, yd, "  Interpolation data:" );

  cd = vandermonde_coef_1d ( nd, xd, yd );

  r8vec_print ( nd, cd, "  Vandermonde interpolant coefficients:" );

  r8poly_print ( nd - 1, cd, "  Vandermonde interpolant polynomial:" );

  free ( cd );

  return;
}
/******************************************************************************/

void vandermonde_matrix_1d_test ( )

/******************************************************************************/
/*
  Purpose:

    VANDERMONDE_MATRIX_1D_TEST tests VANDERMONDE_MATRIX_1D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 July 2015

  Author:

    John Burkardt
*/
{
  double *ad;
  int nd = 4;
  double xd[4] = { -1.0, 2.0, 3.0, 5.0 };

  printf ( "\n" );
  printf ( "VANDERMONDE_MATRIX_1D_TEST\n" );
  printf ( "  VANDERMONDE_MATRIX_1D sets the Vandermonde matrix for 1D interpolation.\n" );

  ad = vandermonde_matrix_1d ( nd, xd );

  r8mat_print ( nd, nd, ad, "  Vandermonde matrix:" );

  free ( ad );

  return;
}
/******************************************************************************/

void vandermonde_value_1d_test ( )

/******************************************************************************/
/*
  Purpose:

    VANDERMONDE_VALUE_1D_TEST tests VANDERMONDE_VALUE_1D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 July 2015

  Author:

    John Burkardt
*/
{
  double cd[5] = { 24.0, -50.0, +35.0, -10.0, 1.0 };
  int nd = 5;
  int ni = 16;
  double x_hi;
  double x_lo;
  double *xi;
  double *yi;

  printf ( "\n" );
  printf ( "VANDERMONDE_VALUE_1D_TEST\n" );
  printf ( "  VANDERMONDE_VALUE_1D evaluates a Vandermonde interpolant.\n" );

  r8poly_print ( nd - 1, cd, "  The polynomial:" );

  x_lo = 0.0;
  x_hi = 5.0;
  xi = r8vec_linspace_new ( ni, x_lo, x_hi );

  yi = vandermonde_value_1d ( nd, cd, ni, xi );

  r8vec2_print ( ni, xi, yi, "  X, P(X):" );

  free ( xi );
  free ( yi );

  return;
}
/******************************************************************************/

void test01 ( int prob )

/******************************************************************************/
/*
  Purpose:

    TEST01 tests VANDERMONDE_INTERP_1D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 October 2012

  Author:

    John Burkardt
*/
{
  double *ad;
  int debug = 0;
  double *cd;
  double condition;
  int i;
  double int_error;
  double ld;
  double li;
  int nd;
  int ni;
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
  printf ( "TEST01:\n" );
  printf ( "  Interpolate data from TEST_INTERP problem #%d\n", prob );

  nd = p00_data_num ( prob );
  printf ( "  Number of data points = %d\n", nd );

  xy = p00_data ( prob, 2, nd );
  
  if ( debug )
  {
    r8mat_transpose_print ( 2, nd, xy, "  Data array:" );
  }

  xd = ( double * ) malloc ( nd * sizeof ( double ) );
  yd = ( double * ) malloc ( nd * sizeof ( double ) );

  for ( i = 0; i < nd; i++ )
  {
    xd[i] = xy[0+i*2];
    yd[i] = xy[1+i*2];
  }
/*
  Compute Vandermonde matrix and get condition number.
*/
  ad = vandermonde_matrix_1d ( nd, xd );

  condition = condition_hager ( nd, ad );

  printf ( "\n" );
  printf ( "  Condition of Vandermonde matrix is %g\n", condition );
/*
  Solve linear system.
*/
  cd = qr_solve ( nd, nd, ad, yd );
/*
  #1:  Does interpolant match function at interpolation points?
*/
  ni = nd;
  xi = r8vec_copy_new ( ni, xd );
  yi = vandermonde_value_1d ( nd, cd, ni, xi );

  int_error = r8vec_norm_affine ( ni, yi, yd ) / ( double ) ( ni );

  printf ( "\n" );
  printf ( "  L2 interpolation error averaged per interpolant node = %g\n", int_error );

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
  yi = vandermonde_value_1d ( nd, cd, ni, xi );

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
  printf ( "  Normalized length of polynomial interpolant       = %g\n", li );

  free ( ad );
  free ( cd );
  free ( xd );
  free ( xi );
  free ( xy );
  free ( yd );
  free ( yi );

  return;
}
/******************************************************************************/

void test02 ( int prob )

/******************************************************************************/
/*
  Purpose:

    TEST02 tests VANDERMONDE_INTERP_1D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 July 2015

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem index.
*/
{
  double *ad;
  double *cd;
  char command_filename[255];
  FILE *command_unit;
  char data_filename[255];
  FILE *data_unit;
  int i;
  char interp_filename[255];
  FILE *interp_unit;
  int j;
  int nd;
  int ni;
  char output_filename[255];
  double *xd;
  double *xi;
  double *xy;
  double xmax;
  double xmin;
  double *yd;
  double *yi;

  printf ( "\n" );
  printf ( "TEST02:\n" );
  printf ( "  VANDERMONDE_INTERP_1D_MATRIX sets the Vandermonde linear system for the\n" );
  printf ( "  interpolating polynomial.\n" );
  printf ( "  Interpolate data from TEST_INTERP problem #%d\n", prob );

  nd = p00_data_num ( prob );
  printf ( "  Number of data points = %d\n", nd );

  xy = p00_data ( prob, 2, nd );
  
  r8mat_transpose_print ( 2, nd, xy, "  Data array:" );

  xd = ( double * ) malloc ( nd * sizeof ( double ) );
  yd = ( double * ) malloc ( nd * sizeof ( double ) );

  for ( i = 0; i < nd; i++ )
  {
    xd[i] = xy[0+2*i];
    yd[i] = xy[1+2*i];
  }
/*
  Set up the Vandermonde matrix AD.
*/
  ad = vandermonde_matrix_1d ( nd, xd );
/*
  Solve the linear system for the polynomial coefficients C.
*/
  cd = qr_solve ( nd, nd, ad, yd );
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
  yi = vandermonde_value_1d ( nd, cd, ni, xi );

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
  fprintf ( command_unit, "set title 'Data versus Vandermonde polynomial interpolant'\n" );
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
  free ( ad );
  free ( cd );
  free ( xd );
  free ( xi );
  free ( xy );
  free ( yd );
  free ( yi );

  return;
}
/******************************************************************************/

void r8poly_print ( int n, double a[], char *title )

/******************************************************************************/
/*
  Purpose:

    R8POLY_PRINT prints out a polynomial.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 July 2015

  Author:

    John Burkardt

  Parameters:

    Input, int N, the dimension of A.

    Input, double A[N+1], the polynomial coefficients.
    A(0) is the constant term and
    A(N) is the coefficient of X**N.

    Input, char *TITLE, a title.
*/
{
  int i;
  double mag;
  char plus_minus;

  if ( 0 < s_len_trim ( title ) )
  {
    printf ( "\n" );
    printf ( "%s\n", title );
  }
  printf ( "\n" );

  if ( n < 0 )
  {
    printf ( "  p(x) = 0\n" );
    return;
  }

  if ( a[n] < 0.0 )
  {
    plus_minus = '-';
  }
  else
  {
    plus_minus = ' ';
  }

  mag = fabs ( a[n] );

  if ( 2 <= n )
  {
    printf ( "  p(x) = %c%g * x^%d\n", plus_minus, mag, n );
  }
  else if ( n == 1 )
  {
    printf ( "  p(x) = %c%g * x\n", plus_minus, mag );
  }
  else if ( n == 0 )
  {
    printf ( "  p(x) = %c%g\n", plus_minus, mag );
  }

  for ( i = n - 1; 0 <= i; i-- )
  {
    if ( a[i] < 0.0 )
    {
      plus_minus = '-';
    }
    else
    {
      plus_minus = '+';
    }

    mag = fabs ( a[i] );

    if ( mag != 0.0 )
    {
      if ( 2 <= i )
      {
        printf ( "         %c%g * x^%d\n", plus_minus, mag, i );
      }
      else if ( i == 1 )
      {
        printf ( "         %c%g * x\n", plus_minus, mag );
      }
      else if ( i == 0 )
      {
        printf ( "         %c%g\n", plus_minus, mag );
      }
    }
  }
  return;
}
