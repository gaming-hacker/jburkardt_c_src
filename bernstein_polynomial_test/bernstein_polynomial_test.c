# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "bernstein_polynomial.h"

int main ( );
void bernstein_matrix_test ( );
void bernstein_matrix_test2 ( );
void bernstein_matrix_determinant_test ( );
void bernstein_matrix_inverse_test ( );
void bernstein_poly_01_test ( );
void bernstein_poly_01_test2 ( );
void bernstein_poly_01_matrix_test ( );
void bernstein_poly_ab_test ( );
void bernstein_poly_ab_approx_test ( );
void bernstein_to_legendre_test ( );
void bernstein_to_power_test ( );
void bernstein_vandermonde_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for BERNSTEIN_POLYNOMIAL_TEST.

  Discussion:

    BERNSTEIN_POLYNOMIAL_TEST tests the BERNSTEIN_POLYNOMIAL library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 March 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "BERNSTEIN_POLYNOMIAL_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the BERNSTEIN_POLYNOMIAL library.\n" );

  bernstein_matrix_test ( );
  bernstein_matrix_test2 ( );
  bernstein_matrix_determinant_test ( );
  bernstein_matrix_inverse_test ( );
  bernstein_poly_01_test ( );
  bernstein_poly_01_test2 ( );
  bernstein_poly_01_matrix_test ( );
  bernstein_poly_ab_test ( );
  bernstein_poly_ab_approx_test ( );
  bernstein_to_legendre_test ( );
  bernstein_to_power_test ( );
  bernstein_vandermonde_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "BERNSTEIN_POLYNOMIAL_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( " \n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void bernstein_matrix_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_MATRIX_TEST tests BERNSTEIN_MATRIX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 January 2016

  Author:

    John Burkardt
*/
{
  double *a;
  int n;

  printf ( "\n" );
  printf ( "BERNSTEIN_MATRIX_TEST\n" );
  printf ( "  BERNSTEIN_MATRIX returns a matrix A which transforms a\n" );
  printf ( "  polynomial coefficient vector from the power basis to\n" );
  printf ( "  the Bernstein basis.\n" );

  n = 5;
  a = bernstein_matrix ( n );
  r8mat_print ( n, n, a, "  The Bernstein matrix A of order 5x5\n" );

  free ( a );

  return;
}
/******************************************************************************/

void bernstein_matrix_test2 ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_MATRIX_TEST2 tests BERNSTEIN_MATRIX.

  Discussion:

    We use the Bernstein matrix to rewrite a Bernstein polynomials
    in terms of the standard monomial basis.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 January 2016

  Author:

    John Burkardt
*/
{
  double *a;
  double *ax;
  int i;
  int k;
  int n;
  double *x;

  printf ( "\n" );
  printf ( "BERNSTEIN_MATRIX_TEST2\n" );
  printf ( "  BERNSTEIN_MATRIX returns a matrix A which\n" );
  printf ( "  transforms a polynomial coefficient vector\n" );
  printf ( "  from the the Bernstein basis to the power basis.\n" );
  printf ( "  We can use this to get explicit values of the\n" );
  printf ( "  4-th degree Bernstein polynomial coefficients as\n" );
  printf ( "\n" );
  printf ( "    b(4,K)(X) = C4 * x^4\n" );
  printf ( "              + C3 * x^3\n" );
  printf ( "              + C2 * x^2\n" );
  printf ( "              + C1 * x\n" );
  printf ( "              + C0 * 1\n" );

  n = 5;
  printf ( "\n" );
  printf ( "     K       C4           C3            C2" );
  printf ( "            C1             C0\n" );
  printf ( "\n" );

  a = bernstein_matrix ( n );
  x = ( double * ) malloc ( n * sizeof ( double ) );

  for ( k = 0; k < n; k++ )
  {
    for ( i = 0; i < n; i++ )
    {
      x[i] = 0.0;
    }
    x[k] = 1.0;

    ax = r8mat_mv_new ( n, n, a, x );

    printf ( "  %4d  ", k );
    for ( i = 0; i < n; i++ )
    {
      printf ( "%14.6g", ax[i] );
    }
    printf ( "\n" );
  }

  free ( a );
  free ( ax );
  free ( x );

  return;
}
/******************************************************************************/

void bernstein_matrix_determinant_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_MATRIX_DETERMINANT_TEST tests BERNSTEIN_MATRIX_DETERMINANT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 January 2016

  Author:

    John Burkardt
*/
{
  double *a;
  double a_norm_frobenius;
  double d1;
  int n;

  printf ( "\n" );
  printf ( "BERNSTEIN_MATRIX_DETERMINANT_TEST\n" );
  printf ( "  BERNSTEIN_MATRIX_DETERMINANT computes the determinant of\n" );
  printf ( "  the Bernstein matrix A.\n" );
  printf ( "\n" );
  printf ( "     N         ||A||          det(A)\n" );
  printf ( "                              computed\n" );
  printf ( "\n" );

  for ( n = 5; n <= 15; n++)
  {
    a = bernstein_matrix ( n );
    a_norm_frobenius = r8mat_norm_fro ( n, n, a );

    d1 = bernstein_matrix_determinant ( n );

    printf ( "  %4d  %14g  %14g\n", n, a_norm_frobenius, d1 );

    free ( a );
  }

  return;
}
/******************************************************************************/

void bernstein_matrix_inverse_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_MATRIX_INVERSE_TEST tests BERNSTEIN_MATRIX_INVERSE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 January 2016

  Author:

    John Burkardt
*/
{
  double *a;
  double a_norm_frobenius;
  double *b;
  double b_norm_frobenius;
  double *c;
  double error_norm_frobenius;
  int n;

  printf ( "\n" );
  printf ( "BERNSTEIN_MATRIX_INVERSE_TEST\n" );
  printf ( "  BERNSTEIN_MATRIX_INVERSE computes the inverse of the\n" );
  printf ( "  Bernstein matrix A.\n" );
  printf ( "\n" );
  printf ( "     N     ||A||        ||inv(A)||  ||I-A*inv(A)||\n" );
  printf ( "\n" );

  for ( n = 5; n <= 15; n++ )
  {
    a = bernstein_matrix ( n );
    a_norm_frobenius = r8mat_norm_fro ( n, n, a );

    b = bernstein_matrix_inverse ( n );
    b_norm_frobenius = r8mat_norm_fro ( n, n, b );

    c = r8mat_mm_new ( n, n, n, a, b );
    error_norm_frobenius = r8mat_is_identity ( n, c );

    printf ( "  %4d  %14g  %14g  %14g\n", 
      n, a_norm_frobenius, b_norm_frobenius, error_norm_frobenius );

    free ( a );
    free ( b );
    free ( c );
  }
  return;
}
/******************************************************************************/

void bernstein_poly_01_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_POLY_01_TEST tests BERNSTEIN_POLY_01.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 January 2016

  Author:

    John Burkardt
*/
{
  double b;
  double *bvec;
  int k;
  int n;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "BERNSTEIN_POLY_01_TEST:\n" );
  printf ( "  BERNSTEIN_POLY_01 evaluates the Bernstein polynomials\n" );
  printf ( "  based on the interval [0,1].\n" );
  printf ( "\n" );
  printf ( "     N     K     X       Exact         BP01(N,K)(X)\n" );
  printf ( "\n" );

  n_data = 0;

  while ( 1 )
  {
    bernstein_poly_01_values ( &n_data, &n, &k, &x, &b );

    if ( n_data == 0 )
    {
      break;
    }

    bvec = bernstein_poly_01 ( n, x );

    printf ( "  %4d  %4d  %7f  %14g  %14g\n", n, k, x, b, bvec[k] );

    free ( bvec );
  }

  return;
}
/******************************************************************************/

void bernstein_poly_01_test2 ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_POLY_01_TEST2 tests BERNSTEIN_POLY_01.

  Discussion:

    Here we test the Partition-of-Unity property.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 February 2012

  Author:

    John Burkardt
*/
{
  double *bvec;
  int n;
  int seed;
  double x;

  printf ( "\n" );
  printf ( "BERNSTEIN_POLY_01_TEST2:\n" );
  printf ( "  BERNSTEIN_POLY_01 evaluates the Bernstein polynomials\n" );
  printf ( "  based on the interval [0,1].\n" );
  printf ( "\n" );
  printf ( "  Here we test the partition of unity property.\n" );
  printf ( "\n" );
  printf ( "     N     X          Sum ( 0 <= K <= N ) BP01(N,K)(X)\n" );
  printf ( "\n" );

  seed = 123456789;

  for ( n = 0; n <= 10; n++ )
  {
    x = r8_uniform_01 ( &seed );

    bvec = bernstein_poly_01 ( n, x );

    printf ( "  %4d  %7f  %14g\n", n, x, r8vec_sum ( n + 1, bvec ) );

    free ( bvec );
  }
  return;
}
/******************************************************************************/

void bernstein_poly_01_matrix_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_POLY_01_MATRIX_TEST tests BERNSTEIN_POLY_01_MATRIX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 January 2016

  Author:

    John Burkardt
*/
{
  double *b;
  int m;
  int n;
  double *x;

  printf ( "\n" );
  printf ( "BERNSTEIN_POLY_01_MATRIX_TEST\n" );
  printf ( "  BERNSTEIN_POLY_01_MATRIX is given M data values X,\n" );
  printf ( "  and a degree N, and returns an Mx(N+1) matrix B such that\n" );
  printf ( "  B(i,j) is the j-th Bernstein polynomial evaluated at the.\n" );
  printf ( "  i-th data value.\n" );

  m = 5;
  x = r8vec_linspace_new ( m, 0.0, 1.0 );
  n = 1;
  b = bernstein_poly_01_matrix ( m, n, x );
  r8mat_print ( m, n + 1, b, "  B(5,1+1):" );
  free ( b );
  free ( x );

  m = 5;
  x = r8vec_linspace_new ( m, 0.0, 1.0 );
  n = 4;
  b = bernstein_poly_01_matrix ( m, n, x );
  r8mat_print ( m, n + 1, b, "  B(5,4+1):" );
  free ( b );
  free ( x );

  m = 10;
  x = r8vec_linspace_new ( m, 0.0, 1.0 );
  n = 4;
  b = bernstein_poly_01_matrix ( m, n, x );
  r8mat_print ( m, n + 1, b, "  B(10,4+1):" );
  free ( b );
  free ( x );

  m = 3;
  x = r8vec_linspace_new ( m, 0.0, 1.0 );
  n = 5;
  b = bernstein_poly_01_matrix ( m, n, x );
  r8mat_print ( m, n + 1, b, "  B(3,5+1):" );
  free ( b );
  free ( x );

  return;
}
/******************************************************************************/

void bernstein_poly_ab_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_POLY_AB_TEST tests BERNSTEIN_POLY_AB.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 February 2012

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double *bern;
  int k;
  int n = 10;
  double x;

  printf ( "\n" );
  printf ( "BERNSTEIN_POLY_AB_TEST\n" );
  printf ( "  BERNSTEIN_POLY_AB evaluates Bernstein polynomials over an\n" );
  printf ( "  arbitrary interval [A,B].\n" );
  printf ( "\n" );
  printf ( "  Here, we demonstrate that \n" );
  printf ( "    BPAB(N,K,A1,B1)(X1) = BPAB(N,K,A2,B2)(X2)\n" );
  printf ( "  provided only that\n" );
  printf ( "    (X1-A1)/(B1-A1) = (X2-A2)/(B2-A2).\n" );

  x = 0.3;
  a = 0.0;
  b = 1.0;
  bern = bernstein_poly_ab ( n, a, b, x );
 
  printf ( "\n" );
  printf ( "     N     K     A        B        X       BPAB(N,K,A,B)(X)\n" );
  printf ( "\n" );
  for ( k = 0; k <= n; k++ )
  {
    printf ( "  %4d  %4d  %7f  %7f  %7f  %14g\n", n, k, a, b, x, bern[k] );
  }

  free ( bern );
 
  x = 1.3;
  a = 1.0;
  b = 2.0;
  bern = bernstein_poly_ab ( n, a, b, x );
 
  printf ( "\n" );
  printf ( "     N     K     A        B        X       BPAB(N,K,A,B)(X)\n" );
  printf ( "\n" ); 
  for ( k = 0; k <= n; k++ )
  {
    printf ( "  %4d  %4d  %7f  %7f  %7f  %14g\n", n, k, a, b, x, bern[k] );
  }

  free ( bern );

  x = 2.6;
  a = 2.0;
  b = 4.0;
  bern = bernstein_poly_ab ( n, a, b, x );
 
  printf ( "\n" );
  printf ( "     N     K     A        B        X       BPAB(N,K,A,B)(X)\n" );
  printf ( "\n" );
 
  for ( k = 0; k <= n; k++ )
  {
    printf ( "  %4d  %4d  %7f  %7f  %7f  %14g\n", n, k, a, b, x, bern[k] );
  }

  free ( bern );

  return;
}
/******************************************************************************/

void bernstein_poly_ab_approx_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_POLY_AB_APPROX_TEST tests BERNSTEIN_POLY_AB_APPROX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 January 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double error_max;
  int i;
  int maxdata = 20;
  int ndata;
  int nval = 501;
  double *xdata;
  double *xval;
  double *ydata;
  double *yval;

  printf ( "\n" );
  printf ( "BERNSTEIN_POLY_AB_APPROX_TEST\n" );
  printf ( "  BERNSTEIN_POLY_AB_APPROX evaluates the Bernstein polynomial\n" );
  printf ( "  approximant to a function F(X).\n" );

  a = 1.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "     N      Max Error\n" );
  printf ( "\n" );

  for ( ndata = 0; ndata <= maxdata; ndata++ )
  {
/*
  Generate data values.
*/
    xdata = ( double * ) malloc ( ( ndata + 1 ) * sizeof ( double ) );
    ydata = ( double * ) malloc ( ( ndata + 1 ) * sizeof ( double ) );
    for ( i = 0; i <= ndata; i++)
    {
      if ( ndata == 0 )
      {
        xdata[i] = 0.5 * ( a + b );
      }
      else
      {
        xdata[i] = ( ( double ) ( ndata - i ) * a   
                   + ( double ) (         i ) * b ) 
                   / ( double ) ( ndata     );
      }
      ydata[i] = sin ( xdata[i] );
    }
/*
  Compare the true function and the approximant.
*/
    xval = r8vec_linspace_new ( nval, a, b );

    error_max = 0.0;

    yval = bernstein_poly_ab_approx ( ndata, a, b, ydata, nval, xval );

    error_max = 0.0;
    for ( i = 0; i < nval; i++ )
    {
      error_max = r8_max ( error_max, fabs ( yval[i] - sin ( xval[i] ) ) );
    }
    printf ( "  %4d  %14g\n", ndata, error_max );

    free ( xdata );
    free ( xval );
    free ( ydata );
    free ( yval );
  }
  return;
}
/******************************************************************************/

void bernstein_to_legendre_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_TO_LEGENDRE_TEST tests BERNSTEIN_TO_LEGENDRE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 March 2016

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  double *c;
  double e;
  int n = 5;

  printf ( "\n" );
  printf ( "BERNSTEIN_TO_LEGENDRE_TEST:\n" );
  printf ( "  BERNSTEIN_TO_LEGENDRE returns the matrix A which maps\n" );
  printf ( "  polynomial coefficients from Bernstein to Legendre form.\n" );

  a = bernstein_to_legendre ( n );
  r8mat_print ( n + 1, n + 1, a, "  A = bernstein_to_legendre(5):" );

  b = legendre_to_bernstein ( n );
  r8mat_print ( n + 1, n + 1, b, "  B = legendre_to_bernstein(5):" );

  c = r8mat_mm_new ( n + 1, n + 1, n + 1, a, b );
  e = r8mat_is_identity ( n + 1, c );
  printf ( "\n" );
  printf ( "  ||A*B-I|| = %g\n", e );

  free ( a );
  free ( b );
  free ( c );

  return;
}
/******************************************************************************/

void bernstein_to_power_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_TO_POWER_TEST tests BERNSTEIN_TO_POWER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 March 2016

  Author:

    John Burkardt
*/
{
  double *a;
  double *b;
  double *c;
  double e;
  int n = 5;

  printf ( "\n" );
  printf ( "BERNSTEIN_TO_POWER_TEST:\n" );
  printf ( "  BERNSTEIN_TO_POWER returns the matrix A which maps\n" );
  printf ( "  polynomial coefficients from Bernstein to Power form.\n" );

  a = bernstein_to_power ( n );
  r8mat_print ( n + 1, n + 1, a, "  A = bernstein_to_power(5):" );

  b = power_to_bernstein ( n );
  r8mat_print ( n + 1, n + 1, b, "  B = legendre_to_power(5):" );

  c = r8mat_mm_new ( n + 1, n + 1, n + 1, a, b );
  e = r8mat_is_identity ( n + 1, c );
  printf ( "\n" );
  printf ( "  ||A*B-I|| = %g\n", e );

  free ( a );
  free ( b );
  free ( c );

  return;
}
/******************************************************************************/

void bernstein_vandermonde_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNSTEIN_VANDERMONDE_TEST tests BERNSTEIN_VANDERMONDE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 December 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int n;

  printf ( "\n" );
  printf ( "BERNSTEIN_VANDERMONDE_TEST\n" );
  printf ( "  BERNSTEIN_VANDERMONDE returns an NxN matrix whose (I,J) entry\n" );
  printf ( "  is the value of the J-th Bernstein polynomial of degree N-1\n" );
  printf ( "  evaluated at the I-th equally spaced point in [0,1].\n" );

  n = 8;
  a = bernstein_vandermonde ( n );
  r8mat_print ( n, n, a, "  Bernstein Vandermonde ( 8 ):" );

  free ( a );

  return;
}

