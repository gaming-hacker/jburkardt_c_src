# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# include "vandermonde_approx_2d.h"
# include "test_interp_2d.h"
# include "qr_solve.h"
# include "r8lib.h"

int main ( );
void test01 ( int prob, int grid, int m );
double *r8poly_value_2d ( int m, double c[], int n, double x[], double y[] );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for VANDERMONDE_APPROX_2D_TEST.

  Discussion:

    VANDERMONDE_APPROX_2D_TEST tests the VANDERMONDE_APPROX_2D library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 October 2012

  Author:

    John Burkardt
*/
{
  int j;
  int m;
  int m_test[5] = { 0, 1, 2, 4, 8 };
  int m_test_num = 5;
  int grid;
  int prob;
  int prob_num;

  timestamp ( );
  printf ( "\n" );
  printf ( "VANDERMONDE_APPROX_2D_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the VANDERMONDE_APPROX_2D library.\n" );
  printf ( "  This test also needs the TEST_INTERP_2D library.\n" );

  prob_num = f00_num ( );

  for ( prob = 1; prob <= prob_num; prob++ )
  {
    grid = 1;
    for ( j = 0; j < m_test_num; j++ )
    {
      m = m_test[j];
      test01 ( prob, grid, m );
    }
  }
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "VANDERMONDE_APPROX_2D_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( int prob, int grd, int m )

/******************************************************************************/
/*
  Purpose:

    VANDERMONDE_APPROX_2D_TEST01 tests VANDERMONDE_APPROX_2D_MATRIX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 October 2012

  Author:

    John Burkardt

  Parameters:

    Input, int PROB, the problem number.

    Input, int GRD, the grid number.
    (Can't use GRID as the name because that's also a plotting function.)

    Input, int M, the total polynomial degree.
*/
{
  double *a;
  double app_error;
  double *c;
  int nd;
  int ni;
  int tm;
  double *xd;
  double *xi;
  double *yd;
  double *yi;
  double *zd;
  double *zi;

  printf ( "\n" );
  printf ( "TEST01:\n" );
  printf ( "  Approximate data from TEST_INTERP_2D problem #%d\n", prob );
  printf ( "  Use grid from TEST_INTERP_2D with index #%d\n", grd );
  printf ( "  Using polynomial approximant of total degree %d\n", m );

  nd = g00_size ( grd );
  printf ( "  Number of data points = %d\n", nd );

  xd = ( double * ) malloc ( nd * sizeof ( double ) );
  yd = ( double * ) malloc ( nd * sizeof ( double ) );
  g00_xy ( grd, nd, xd, yd );

  zd = ( double * ) malloc ( nd * sizeof ( double ) );
  f00_f0 ( prob, nd, xd, yd, zd );

  if ( nd < 10 )
  {
    r8vec3_print ( nd, xd, yd, zd, "  X, Y, Z data:" );
  }
/*
  Compute the Vandermonde matrix.
*/
  tm = triangle_num ( m + 1 );
  a = vandermonde_approx_2d_matrix ( nd, m, tm, xd, yd );
/*
  Solve linear system.
*/
  c = qr_solve ( nd, tm, a, zd );
/*
  #1:  Does approximant match function at data points?
*/
  ni = nd;
  xi = r8vec_copy_new ( ni, xd );
  yi = r8vec_copy_new ( ni, yd );
  zi = r8poly_value_2d ( m, c, ni, xi, yi );

  app_error = r8vec_norm_affine ( ni, zi, zd ) / ( double ) ( ni );

  printf ( "\n" );
  printf ( "  L2 data approximation error = %g\n", app_error );

  free ( a );
  free ( c );
  free ( xd );
  free ( xi );
  free ( yd );
  free ( yi );
  free ( zd );
  free ( zi );

  return;
}
/******************************************************************************/

double *r8poly_value_2d ( int m, double c[], int n, double x[], double y[] )

/******************************************************************************/
/*
  Purpose:

    R8POLY_VALUE_2D evaluates a polynomial in 2 variables, X and Y.

  Discussion:

    We assume the polynomial is of total degree M, and has the form:

      p(x,y) = c00 
             + c10 * x                + c01 * y
             + c20 * x^2   + c11 * xy + c02 * y^2
             + ...
             + cm0 * x^(m) + ...      + c0m * y^m.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 September 2012

  Author:

    John Burkardt

  Parameters:

    Input, int M, the degree of the polynomial.

    Input, double C[T(M+1)], the polynomial coefficients.  
    C[0] is the constant term.  T(M+1) is the M+1-th triangular number.
    The coefficients are stored consistent with the following ordering
    of monomials: 1, X, Y, X^2, XY, Y^2, X^3, X^2Y, XY^2, Y^3, X^4, ...

    Input, int N, the number of evaluation points.

    Input, double X[N], Y[N], the evaluation points.

    Output, double R8POLY_VALUE_2D[N], the value of the polynomial at the 
    evaluation points.
*/
{
  int ex;
  int ey;
  int i;
  int j;
  double *p;
  int s;

  p = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    p[i] = 0.0;
  }

  j = 0;
  for ( s = 0; s <= m; s++ )
  {
    for ( ex = s; 0 <= ex; ex-- )
    {
      ey = s - ex;
      for ( i = 0; i < n; i++ )
      {
        p[i] = p[i] + c[j] * pow ( x[i], ex ) * pow ( y[i], ey );
      }
      j = j + 1;
    }
  }
  return p;
}
