# include <complex.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "r8poly.h"

int main ( );

void r8_sign_test ( );

void r82poly2_type_test ( );
void r82poly2_print_test ( );

void r8mat_inverse_3d_test ( );
void r8mat_print_test ( );
void r8mat_print_some_test ( );

void r8poly_add_test ( );
void r8poly_ant_coef_test ( );
void r8poly_ant_value_test ( );
void r8poly_degree_test ( );
void r8poly_deriv_test ( );
void r8poly_division_test ( );
void r8poly_lagrange_coef_test ( );
void r8poly_lagrange_0_test ( );
void r8poly_lagrange_1_test ( );
void r8poly_lagrange_2_test ( );
void r8poly_lagrange_factor_test ( );
void r8poly_lagrange_value_test ( );
void r8poly_multiply_test ( );
void r8poly_power_test ( );
void r8poly_print_test ( );
void r8poly_value_test ( );
void r8poly_value_horner_test ( );
void r8poly_values_horner_test ( );

void r8poly2_ex_test ( );
void r8poly2_ex2_test ( );
void r8poly2_f ( double x, double *y, double *yp, double *ypp );
void r8poly2_root_test ( );
void r8poly2_rroot_test ( );
void r8poly2_val_test ( );
void r8poly2_val2_test ( );

void r8poly3_root_test ( );

void r8poly4_root_test ( );

void r8vec_even_new_test ( );
void r8vec_even_select_test ( );
void r8vec_indicator1_new_test ( );
void r8vec_is_distinct_test ( );
void r8vec_linspace_new_test ( );
void r8vec_print_test ( );
void r8vec_transpose_print_test ( );
void r8vec_uniform_01_new_test ( );

void r8vec2_print_test ( );

void roots_to_r8poly_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for R8POLY_TEST.

  Discussion:

    R8POLY_TEST tests R8POLY.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 November 2019

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "R8POLY_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test r8poly.\n" );

  r8_sign_test ( );

  r82poly2_print_test ( );
  r82poly2_type_test ( );

  r8mat_inverse_3d_test ( );
  r8mat_print_test ( );
  r8mat_print_some_test ( );

  r8poly_add_test ( );
  r8poly_ant_coef_test ( );
  r8poly_ant_value_test ( );
  r8poly_degree_test ( );
  r8poly_deriv_test ( );
  r8poly_division_test ( );
  r8poly_lagrange_coef_test ( );
  r8poly_lagrange_0_test ( );
  r8poly_lagrange_1_test ( );
  r8poly_lagrange_2_test ( );
  r8poly_lagrange_factor_test ( );
  r8poly_lagrange_value_test ( );
  r8poly_multiply_test ( );
  r8poly_power_test ( );
  r8poly_print_test ( );
  r8poly_value_test ( );
  r8poly_value_horner_test ( );
  r8poly_values_horner_test ( );

  r8poly2_ex_test ( );
  r8poly2_ex2_test ( );
  r8poly2_root_test ( );
  r8poly2_rroot_test ( );
  r8poly2_val_test ( );
  r8poly2_val2_test ( );

  r8poly3_root_test ( );

  r8poly4_root_test ( );

  r8vec_even_new_test ( );
  r8vec_even_select_test ( );
  r8vec_indicator1_new_test ( );
  r8vec_is_distinct_test ( );
  r8vec_linspace_new_test ( );
  r8vec_print_test ( );
  r8vec_transpose_print_test ( );
  r8vec_uniform_01_new_test ( );

  r8vec2_print_test ( );

  roots_to_r8poly_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "R8POLY_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void r8_sign_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_SIGN_TEST tests R8_SIGN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 September 2014

  Author:

    John Burkardt
*/
{
  double r8;
  double r8_test[5] = { -1.25, -0.25, 0.0, +0.5, +9.0 };
  double s;
  int test;
  const int test_num = 5;

  printf ( "\n" );
  printf ( "R8_SIGN_TEST\n" );
  printf ( "  R8_SIGN returns the sign of a number.\n" );
  printf ( "\n" );
  printf ( "    X        R8_SIGN(X)\n" );
  printf ( "\n" );

  for ( test = 0; test < test_num; test++ )
  {
    r8 = r8_test[test];
    s = r8_sign ( r8 );
    printf ( "  %8.4f  %8.0f\n", r8, s );
  }

  return;
}
/******************************************************************************/

void r82poly2_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R82POLY2_PRINT_TEST tests R82POLY2_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2018

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double d;
  double e;
  double f;

  printf ( "\n" );
  printf ( "R82POLY2_PRINT_TEST\n" );
  printf ( "  R82POLY2_PRINT prints an R82POLY2,\n" );
  printf ( "  a quadratic polynomial in x and y.\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;
  d = 4.0;
  e = 5.0;
  f = 6.0;

  printf ( "\n" );
  printf ( "  Coefficients a, b, c, d, e, f\n" );
  printf ( "  %14.6g  %14.6g  %14.6g  %14.6g  %14.6g  %14.6g\n",
    a, b, c, d, e, f );
  printf ( "\n" );

  r82poly2_print ( a, b, c, d, e, f );

  return;
}
/******************************************************************************/

void r82poly2_type_test ( )

/******************************************************************************/
/*
  Purpose:

    R82POLY2_TYPE_TEST tests R82POLY2_TYPE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 March 2012

  Author:

    John Burkardt
*/
{
# define TEST_NUM 12

  double a;
  double a_test[TEST_NUM] = {
    9.0, 4.0, 9.0,  1.0, 0.0,
    1.0, 0.0, 0.0,  0.0, 0.0,
    0.0, 0.0 };
  double b;
  double b_test[TEST_NUM] = {
    -4.0, 1.0,  16.0,  1.0,  0.0,
     2.0, 1.0,   1.0,  1.0,  0.0,
     0.0, 0.0 };
  double c;
  double c_test[TEST_NUM] = {
     0.0, -4.0,   0.0,   0.0, 1.0,
     0.0,  0.0,   0.0,  0.0,  0.0,
     0.0,  0.0 };
  double d;
  double r8_test[TEST_NUM] = {
    -36.0,  3.0,  36.0,  -6.0, 3.0,
    -2.0,   0.0,   0.0,  0.0,  2.0,
     0.0, 0.0 };
  double e;
  double e_test[TEST_NUM] = {
    -24.0, -4.0, -32.0, -10.0, -1.0,
     16.0, -6.0, -6.0, -2.0, -1.0,
     0.0, 0.0 };
  double f;
  double f_test[TEST_NUM] = {
    -36.0,  1.0, -92.0, 115.0, -3.0,
     33.0, +8.0, 10.0,  +1.0,  1.0,
      0.0, 1.0 };
  int test;
  int type;

  printf ( "\n" );
  printf ( "R82POLY2_TYPE_TEST\n" );
  printf ( "  R82POLY2_TYPE determines the type of a second order\n" );
  printf ( "  equation in two variables.\n" );
  printf ( "\n" );

  for ( test = 0; test < TEST_NUM; test++ )
  {
    a = a_test[test];
    b = b_test[test];
    c = c_test[test];
    d = r8_test[test];
    e = e_test[test];
    f = f_test[test];

    printf ( "\n" );

    r82poly2_print ( a, b, c, d, e, f );

    type = r82poly2_type ( a, b, c, d, e, f );

    printf ( "  Type = %d\n", type );

    r82poly2_type_print ( type );
  }

  return;
# undef TEST_NUM
}
/******************************************************************************/

void r8mat_inverse_3d_test ( )

/******************************************************************************/
/*
  Purpose:

    R8MAT_INVERSE_3D_TEST tests R8MAT_INVERSE_3D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 June 2012

  Author:

    John Burkardt
*/
{
# define N 3

  double a[N*N];
  double *b;
  double c[N*N];
  int i;
  int j;
  int k;

  printf ( "\n" );
  printf ( "R8MAT_INVERSE_3D_TEST\n" );
  printf ( "  R8MAT_INVERSE_3D inverts a 3 by 3 matrix.\n" );

  a[0+0*N] = 3.0;
  a[0+1*N] = 2.0;
  a[0+2*N] = 1.0;

  a[1+0*N] = 2.0;
  a[1+1*N] = 2.0;
  a[1+2*N] = 1.0;

  a[2+0*N] = 0.0;
  a[2+1*N] = 1.0;
  a[2+2*N] = 1.0;

  r8mat_print ( 3, 3, a, "  Matrix A:" );

  b = r8mat_inverse_3d ( a );

  r8mat_print ( 3, 3, b, "  Inverse matrix B:" );

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      c[i+j*N] = 0.0;
      for ( k = 0; k < N; k++ )
      {
        c[i+j*N] = c[i+j*N] + a[i+k*N] * b[k+j*N];
      }
    }
  }

  r8mat_print ( 3, 3, c, "  C = A * B:" );

  free ( b );

  return;

# undef N
}
/******************************************************************************/

void r8mat_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8MAT_PRINT_TEST tests R8MAT_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 August 2014

  Author:

    John Burkardt
*/
{
# define M 6
# define N 4

  double a[M*N];
  int i;
  int j;
  int m = M;
  int n = N;

  printf ( "\n" );
  printf ( "R8MAT_PRINT_TEST\n" );
  printf ( "  R8MAT_PRINT prints an R8MAT.\n" );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( ( i + 1 ) * 10 + ( j + 1 ) );
    }
  }
  r8mat_print ( m, n, a, "  The matrix:" );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8mat_print_some_test ( )

/******************************************************************************/
/*
  Purpose:

    R8MAT_PRINT_SOME_TEST tests R8MAT_PRINT_SOME.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 August 2014

  Author:

    John Burkardt
*/
{
# define M 6
# define N 4

  double a[M*N];
  int i;
  int j;
  int m = M;
  int n = N;

  printf ( "\n" );
  printf ( "R8MAT_PRINT_SOME_TEST\n" );
  printf ( "  R8MAT_PRINT_SOME prints some of an R8MAT.\n" );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( ( i + 1 ) * 10 + ( j + 1 ) );
    }
  }
  r8mat_print_some ( m, n, a, 2, 1, 4, 2, "  Rows 2:4, Cols 1:2:" );

  return;
# undef M
# undef N
}
/******************************************************************************/

void r8poly_add_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_ADD_TEST tests R8POLY_ADD.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    28 May 2015

  Author:

    John Burkardt
*/
{
  double a[6] = { 0.0,  1.1, 2.2, 3.3, 4.4,  5.5 };
  double b[6] = { 1.0, -2.1, 7.2, 8.3, 0.0, -5.5 };
  double *c;
  int na = 5;
  int nb = 5;
  int nc;
  int nc2;

  printf ( "\n" );
  printf ( "R8POLY_ADD_TEST\n" );
  printf ( "  R8POLY_ADD adds two polynomials.\n" );

  r8poly_print ( na, a, "  Polynomial A:" );

  r8poly_print ( nb, b, "  Polynomial B:" );

  c = r8poly_add ( na, a, nb, b );

  nc = i4_max ( na, nb );

  nc2 = r8poly_degree ( nc, c );

  r8poly_print ( nc2, c, "  Polynomial C = A+B:" );

  free ( c );

  return;
}
/******************************************************************************/

void r8poly_ant_coef_test ( )

/******************************************************************************/
/*
  Purpose:

    r8poly_ant_coef_test tests r8poly_ant_coef().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 October 2019

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *poly_cof;
  double *poly_cof2;

  n = 5;

  printf ( "\n" );
  printf ( "r8poly_ant_coef_test\n" );
  printf ( "  r8poly_ant_coef() computes the coefficients of the\n" );
  printf ( "  antiderivative of a polynomial;\n" );

  poly_cof = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  for ( i = 0; i < n + 1; i++ )
  {
    poly_cof[i] = n + 1 - i;
  }

  r8poly_print ( n, poly_cof, "  Polynomial p(x):" );

  poly_cof2 = r8poly_ant_coef ( n, poly_cof );

  r8poly_print ( n+1, poly_cof2, "  Antideriv(p(x)):" );

  free ( poly_cof );
  free ( poly_cof2 );

  return;
}
/******************************************************************************/

void r8poly_ant_value_test ( )

/******************************************************************************/
/*
  Purpose:

    r8poly_ant_value_test tests r8poly_ant_value().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 October 2019

  Author:

    John Burkardt
*/
{
  double c[5] = { 24.0, -50.0, +35.0, -10.0, 1.0 };
  int i;
  int m = 4;
  int n = 16;
  double p;
  double *x;
  double x_hi;
  double x_lo;

  printf ( "\n" );
  printf ( "r8poly_ant_value_test\n" );
  printf ( "  r8poly_ant_value() evaluates the antiderivative of a polynomial at\n" );
  printf ( "  one point, using a naive method.\n" );

  r8poly_print ( m, c, "  The polynomial coefficients:" );

  x_lo = 0.0;
  x_hi = 5.0;
  x = r8vec_linspace_new ( n, x_lo, x_hi );

  printf ( "\n" );
  printf ( "   I    X    antiP(X)\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    p = r8poly_ant_value ( m, c, x[i] );
    printf ( "  %2d  %8.4f  %14.6g\n", i, x[i], p );
  }

  free ( x );

  return;
}
/******************************************************************************/

void r8poly_degree_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_DEGREE_TEST tests R8POLY_DEGREE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 January 2015

  Author:

    John Burkardt
*/
{
  double c1[4] = { 1.0, 2.0, 3.0, 4.0 }; 
  double c2[4] = { 1.0, 2.0, 3.0, 0.0 };
  double c3[4] = { 1.0, 2.0, 0.0, 4.0 };
  double c4[4] = { 1.0, 0.0, 0.0, 0.0 };
  double c5[4] = { 0.0, 0.0, 0.0, 0.0 };
  int d;
  int m;
 
  printf ( "\n" );
  printf ( "R8POLY_DEGREE_TEST\n" );
  printf ( "  R8POLY_DEGREE determines the degree of an R8POLY.\n" );

  m = 3;

  r8poly_print ( m, c1, "  The R8POLY:" );
  d = r8poly_degree ( m, c1 );
  printf ( "  Dimensioned degree = %d,  Actual degree = %d\n", m, d );

  r8poly_print ( m, c2, "  The R8POLY:" );
  d = r8poly_degree ( m, c2 );
  printf ( "  Dimensioned degree = %d,  Actual degree = %d\n", m, d );

  r8poly_print ( m, c3, "  The R8POLY:" );
  d = r8poly_degree ( m, c3 );
  printf ( "  Dimensioned degree = %d,  Actual degree = %d\n", m, d );

  r8poly_print ( m, c4, "  The R8POLY:" );
  d = r8poly_degree ( m, c4 );
  printf ( "  Dimensioned degree = %d,  Actual degree = %d\n", m, d );

  r8poly_print ( m, c5, "  The R8POLY:" );
  d = r8poly_degree ( m, c5 );
  printf ( "  Dimensioned degree = %d,  Actual degree = %d\n", m, d );

  return;
}
/******************************************************************************/

void r8poly_deriv_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_DERIV_TEST tests R8POLY_DERIV.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 June 2012

  Author:

    John Burkardt
*/
{
# define N 4

  double *c;
  double *cp;
  int d;
  double *x;

  printf ( "\n" );
  printf ( "R8POLY_DERIV_TEST\n" );
  printf ( "  R8POLY_DERIV computes the coefficients of\n" );
  printf ( "  the derivative of a polynomial.\n" );

  x = r8vec_indicator1_new ( N );

  c = roots_to_r8poly ( N, x );

  r8poly_print ( N, c, "  The initial polynomial" );

  for ( d = 0; d <= N; d++ )
  {
    cp = r8poly_deriv ( N, c, d );
    printf ( "\n" );
    printf ( "  The derivative of order %d\n", d );
    printf ( "\n" );
    r8poly_print ( N-d, cp, " " );
    free ( cp );
  }

  free ( c );
  free ( x );

  return;
# undef N
}
/******************************************************************************/

void r8poly_division_test ( )

/******************************************************************************/
/*
  Purpose:

    r8poly_division_test tests r8poly_division.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
  double a[11];
  double b[11];
  int na;
  int nb;
  int nq;
  int nr;
  int ntest = 3;
  double q[11];
  double r[11];
  int test;

  printf ( "\n" );
  printf ( "r8poly_division_test\n" );
  printf ( "  r8poly_division computes the quotient and\n" );
  printf ( "  remainder for polynomial division.\n" );
  printf ( "\n" );
/*
  1: Divide X^3 + 2*X^2 - 5*X - 6  by X-2.  
     Quotient is 3+4*X+X^2, remainder is 0.

  2: Divide X^4 + 3*X^3 + 2*X^2 - 2  by  X^2 + X - 3.
     Quotient is X^2 + 2*X + 3, remainder 8*X + 7.

  3: Divide X^3 - 2*X^2 + 0*X - 4  by  X - 3.
     Quotient is X^2 + X + 3, remainder 5.
*/
  for ( test = 1; test <= ntest; test++ )
  {
    if ( test == 1 )
    {
      na = 3;
      a[0] = -6.0;
      a[1] = -5.0;
      a[2] =  2.0;
      a[3] =  1.0;
      nb = 1;
      b[0] = -2.0;
      b[1] =  1.0;
    }
    else if ( test == 2 )
    {
      na = 4;
      a[0] = -2.0;
      a[1] =  5.0;
      a[2] =  2.0;
      a[3] =  3.0;
      a[4] =  1.0;
      nb = 2;
      b[0] = -3.0;
      b[1] =  1.0;
      b[2] =  1.0;
    }
    else if ( test == 3 )
    {
      na = 3;
      a[0] = -4.0;
      a[1] =  0.0;
      a[2] = -2.0;
      a[3] =  1.0;
      nb = 1;
      b[0] = -3.0;
      b[1] =  1.0;
    }

    r8poly_print ( na, a, "  The polynomial to be divided, A:" );

    r8poly_print ( nb, b, "  The divisor polynomial, B:" );

    r8poly_division ( na, a, nb, b, &nq, q, &nr, r );

    r8poly_print ( nq, q, "  The quotient polynomial, Q:" );

    r8poly_print ( nr, r, "  The remainder polynomial, R:" );
  }
  return;
}
/******************************************************************************/

void r8poly_lagrange_coef_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_LAGRANGE_COEF_TEST tests R8POLY_LAGRANGE_COEF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 June 2012

  Author:

    John Burkardt
*/
{
# define NPOL 5

  int i;
  int ipol;
  double *pcof;
  double *xpol;

  printf ( "\n" );
  printf ( "R8POLY_LAGRANGE_COEF_TEST\n" );
  printf ( "  R8POLY_LAGRANGE_COEF returns the coefficients for\n" );
  printf ( "  a Lagrange basis polynomial.\n" );

  xpol = r8vec_indicator1_new ( NPOL );

  r8vec_print ( NPOL, xpol, "  Abscissas:" );

  for ( ipol = 1; ipol <= NPOL; ipol++ )
  {
    pcof = r8poly_lagrange_coef ( NPOL, ipol, xpol );

    printf ( "\n" );
    printf ( "  Lagrange basis polynomial %4d:\n", ipol );
    printf ( "\n" );

    for ( i = 0; i < NPOL; i++ )
    {
      printf ( "%10g  %4d\n", pcof[i], i );
    }
    free ( pcof );

  }

  free ( xpol );

  return;
# undef NPOL
}
/******************************************************************************/

void r8poly_lagrange_0_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_LAGRANGE_0_TEST tests R8POLY_LAGRANGE_0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 June 2012

  Author:

    John Burkardt
*/
{
# define NPOL 5

  int ival;
  int nx;
  double wval;
  double xhi;
  double xlo;
  double *xpol;
  double xval;

  printf ( "\n" );
  printf ( "R8POLY_LAGRANGE_0_TEST\n" );
  printf ( "  R8POLY_LAGRANGE_0 evaluates the Lagrange\n" );
  printf ( "  factor W(X) at a point.\n" );
  printf ( "\n" );
  printf ( "  The number of data points is %d\n", NPOL );
/*
  Set the abscissas of the polynomials.
*/
  xlo = 0.0E+00;
  xhi = ( double ) ( NPOL - 1 );

  xpol = r8vec_even_new ( NPOL, xlo, xhi );

  r8vec_print ( NPOL, xpol, "  Abscissas:" );
/*
  Evaluate W(X).
*/
  printf ( "\n" );
  printf ( "      X          W(X)\n" );
  printf ( "\n" );

  nx = 4 * NPOL - 1;

  for ( ival = 1; ival <= nx; ival++ )
  {
    xval = r8vec_even_select ( nx, xlo, xhi, ival );

    wval = r8poly_lagrange_0 ( NPOL, xpol, xval );

    printf ( "%12g  %12g\n", xval, wval );
  }

  free ( xpol );

  return;
# undef NPOL
}
/******************************************************************************/

void r8poly_lagrange_1_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_LAGRANGE_1_TEST tests R8POLY_LAGRANGE_1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 June 2012

  Author:

    John Burkardt
*/
{
# define NPOL 5

  double dwdx;
  int ival;
  int nx;
  double xhi;
  double xlo;
  double *xpol;
  double xval;

  printf ( "\n" );
  printf ( "R8POLY_LAGRANGE_1_TEST\n" );
  printf ( "  R8POLY_LAGRANGE_1 evaluates the Lagrange\n" );
  printf ( "  factor W'(X) at a point.\n" );
  printf ( "\n" );
  printf ( "  The number of data points is %d\n", NPOL );
/*
  Set the abscissas of the polynomials.
*/
  xlo = 0.0E+00;
  xhi = ( double ) ( NPOL - 1 );

  xpol = r8vec_even_new ( NPOL, xlo, xhi );

  r8vec_print ( NPOL, xpol, "  Abscissas:" );
/*
  Evaluate W'(X).
*/
  printf ( "\n" );
  printf ( "      X          W'(X)\n" );
  printf ( "\n" );

  nx = 4 * NPOL - 1;

  for ( ival = 1; ival <= nx; ival++ )
  {
    xval = r8vec_even_select ( nx, xlo, xhi, ival );

    dwdx = r8poly_lagrange_1 ( NPOL, xpol, xval );

    printf ( "%12g  %12g\n", xval, dwdx );
  }

  free ( xpol );

  return;
# undef NPOL
}
/******************************************************************************/

void r8poly_lagrange_2_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_LAGRANGE_2_TEST tests R8POLY_LAGRANGE_2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 June 2012

  Author:

    John Burkardt
*/
{
# define NPOL 5

  double dw2dx2;
  int ival;
  int nx;
  double xhi;
  double xlo;
  double *xpol;
  double xval;

  printf ( "\n" );
  printf ( "R8POLY_LAGRANGE_2_TEST\n" );
  printf ( "  R8POLY_LAGRANGE_2 evaluates the Lagrange\n" );
  printf ( "  factor W''(X) at a point.\n" );
  printf ( "\n" );
  printf ( "  The number of data points is %d\n", NPOL );
/*
  Set the abscissas of the polynomials.
*/
  xlo = 0.0E+00;
  xhi = ( double ) ( NPOL - 1 );

  xpol = r8vec_even_new ( NPOL, xlo, xhi );

  r8vec_print ( NPOL, xpol, "  Abscissas:" );
/*
  Evaluate W(X), W'(X), W''.
*/
  printf ( "\n" );
  printf ( "      X          W''(X)\n" );
  printf ( "\n" );

  nx = 4 * NPOL - 1;

  for ( ival = 1; ival <= nx; ival++ )
  {
    xval = r8vec_even_select ( nx, xlo, xhi, ival );

    dw2dx2 = r8poly_lagrange_2 ( NPOL, xpol, xval );

    printf ( "%12g  %12g\n", xval, dw2dx2 );
  }

  free ( xpol );

  return;
# undef NPOL
}
/******************************************************************************/

void r8poly_lagrange_factor_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_LAGRANGE_FACTOR_TEST tests R8POLY_LAGRANGE_FACTOR.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 June 2012

  Author:

    John Burkardt
*/
{
# define NPOL 5

  double dwdx;
  int i;
  double wval;
  double xhi;
  double xlo;
  double xpol[NPOL];
  double xval;

  printf ( "\n" );
  printf ( "R8POLY_LAGRANGE_FACTOR_TEST\n" );
  printf ( "  R8POLY_LAGRANGE_FACTOR evaluates the Lagrange\n" );
  printf ( "  factor W(X) at a point.\n" );
  printf ( "\n" );
  printf ( "  For this test, we use %d functions.\n", NPOL );
/*
  Set the abscissas of the polynomials.
*/
  xlo = 0.0;
  xhi = ( double ) ( NPOL - 1 );
  for ( i = 0; i < NPOL; i++ )
  {
    xpol[i] = ( ( double ) ( NPOL - i ) * xlo + ( double ) i * xhi )
      / ( double ) ( NPOL );
  }

  r8vec_print ( NPOL, xpol, "  Abscissas:" );
/*
  Evaluate W(X) and W'(X).
*/
  printf ( "\n" );
  printf ( "      X          W(X)          W'(X)\n" );
  printf ( "\n" );

  for ( i = 0; i < 2 * NPOL - 2; i++ )
  {
    xval = r8vec_even_select ( 2 * NPOL - 1, xhi, xlo, i );

    r8poly_lagrange_factor ( NPOL, xpol, xval, &wval, &dwdx );

    printf ( "%10g  %10g  %10g\n", xval, wval, dwdx );
  }

  return;
# undef NPOL
}
/******************************************************************************/

void r8poly_lagrange_value_test ( )

/******************************************************************************/
/*
  Purpose:

    r8poly_lagrange_value_test tests r8poly_lagrange_value().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 June 2012

  Author:

    John Burkardt
*/
{
# define NPOL 5

  int ipol;
  int ival;
  double p1;
  double p2;
  double xhi;
  double xlo;
  double *xpol;
  double xval;

  printf ( "\n" );
  printf ( "r8poly_lagrange_value_test\n" );
  printf ( "  r8poly_lagrange_value() evaluates a Lagrange\n" );
  printf ( "  interpolating polynomial at a point.\n" );
  printf ( "\n" );
  printf ( "  For this test, we use %d functions.\n", NPOL );
/*
  Set the abscissas of the polynomials.
*/
  xlo = 0.0E+00;
  xhi = ( double ) ( NPOL - 1 );
  xpol = r8vec_even_new ( NPOL, xlo, xhi );

  r8vec_print ( NPOL, xpol, "  Abscissas:" );
/*
  Evaluate the polynomials.
*/
  printf ( "\n" );
  printf ( "  Here are the values of the functions at\n" );
  printf ( "  several points:\n" );
  printf ( "\n" );
  printf ( "      X          L1          L2          L3      L4          L5\n" );
  printf ( "\n" );

  for ( ival = 0; ival < 2 * NPOL - 1; ival++ )
  {

    xval = r8vec_even_select ( 2 * NPOL - 1, xhi, xlo, ival );
    printf ( "%10g  ", xval );

    for ( ipol = 0; ipol < NPOL; ipol++ )
    {
      r8poly_lagrange_value ( NPOL, ipol, xpol, xval, &p1, &p2 );
      printf ( "%10g  ", p1 );
    }
    printf ( "\n" );
  }
  printf ( "\n" );
  printf ( "  And the derivatives:\n" );
  printf ( "\n" );
  printf ( "      X          L'1         L'2         L'3     L'4         L'5\n" );
  printf ( "\n" );

  for ( ival = 0; ival < 2 * NPOL - 1; ival++ )
  {
    xval = r8vec_even_select ( 2 * NPOL - 1, xhi, xlo, ival );
    printf ( "%10g  ", xval );

    for ( ipol = 0; ipol < NPOL; ipol++ )
    {
      r8poly_lagrange_value ( NPOL, ipol, xpol, xval, &p1, &p2 );
      printf ( "%10g  ", p2 );
    }
    printf ( "\n" );
  }

  free ( xpol );

  return;
# undef NPOL
}
/******************************************************************************/

void r8poly_multiply_test ( )

/******************************************************************************/
/*
  Purpose:

    r8poly_multiply_test tests r8poly_multiply.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define MAXN 5

  double a[MAXN+1];
  double b[MAXN+1];
  double c[MAXN+1];
  int na;
  int nb;
  int ntest = 2;
  int test;

  printf ( "\n" );
  printf ( "r8poly_multiply_test\n" );
  printf ( "  r8poly_multiply multiplies two polynomials.\n" );
  printf ( "\n" );
/*
  1: Multiply (1+X) times (1-X).  Answer is 1-X^2.
  2: Multiply (1+2*X+3*X^2) by (1-2*X). Answer is 1 + 0*X - X^2 - 6*X^3
*/
  for ( test = 1; test <= ntest; test++ )
  {
    if ( test == 1 )
    {
      na = 1;
      a[0] = 1.0;
      a[1] = 1.0;
      nb = 1;
      b[0] =  1.0;
      b[1] = -1.0;
    }
    else if ( test == 2 )
    {
      na = 2;
      a[0] = 1.0;
      a[1] = 2.0;
      a[2] = 3.0;
      nb = 1;
      b[0] =  1.0;
      b[1] = -2.0;
    }

    r8poly_multiply ( na, a, nb, b, c );

    r8poly_print ( na, a, "  The factor A:" );

    r8poly_print ( nb, b, "  The factor B:" );

    r8poly_print ( na+nb, c, "  The product C = A*B:" );

  }

  return;
# undef MAXN
}
/******************************************************************************/

void r8poly_power_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_POWER_TEST tests R8POLY_POWER.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 March 2014

  Author:

    John Burkardt
*/
{
# define LMAX 10

  double a[LMAX+1];
  double b[LMAX+1];
  int na;
  int p;

  printf ( "\n" );
  printf ( "R8POLY_POWER_TEST\n" );
  printf ( "  R8POLY_POWER takes a polynomial to a power.\n" );
/*
  Cube (2-X).  Answer is 8-12*X+6*X^2-X^3.
*/
  na = 1;
  a[0] =  2.0;
  a[1] = -1.0;
  p = 3;

  r8poly_print ( na, a, "  The polynomial A:" );
 
  r8poly_power ( na, a, p, b );
 
  r8poly_print ( p*na, b, "  Raised to the power 3:" );
/*
  Square X+X^2
*/
  na = 2;
  a[0] =  0.0;
  a[1] =  1.0;
  a[2] =  1.0;
  p = 2;

  r8poly_print ( na, a, "  The polynomial A:" );
 
  r8poly_power ( na, a, p, b );
 
  r8poly_print ( p*na, b, "  Raised to the power 2:" );
 
  return;
# undef LMAX
}
/******************************************************************************/

void r8poly_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_PRINT_TEST tests R8POLY_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 January 2015

  Author:

    John Burkardt
*/
{
  double c[6] = { 12.0, -3.4, 56.0, 0.0, 0.78, 9.0 };
  int m = 5;

  printf ( "\n" );
  printf ( "R8POLY_PRINT_TEST\n" );
  printf ( "  R8POLY_PRINT prints an R8POLY.\n" );

  r8poly_print ( m, c, "  The R8POLY:" );

  return;
}
/******************************************************************************/

void r8poly_value_horner_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_VALUE_HORNER_TEST tests R8POLY_VALUE_HORNER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 January 2015

  Author:

    John Burkardt
*/
{
  double c[5] = { 24.0, -50.0, +35.0, -10.0, 1.0 };
  int i;
  int m = 4;
  int n = 16;
  double p;
  double *x;
  double x_hi;
  double x_lo;

  printf ( "\n" );
  printf ( "R8POLY_VALUE_HORNER_TEST\n" );
  printf ( "  R8POLY_VALUE_HORNER evaluates a polynomial at\n" );
  printf ( "  one point, using Horner's method.\n" );

  r8poly_print ( m, c, "  The polynomial coefficients:" );

  x_lo = 0.0;
  x_hi = 5.0;
  x = r8vec_linspace_new ( n, x_lo, x_hi );

  printf ( "\n" );
  printf ( "   I    X    P(X)\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    p = r8poly_value_horner ( m, c, x[i] );
    printf ( "  %2d  %8.4f  %14.6g\n", i, x[i], p );
  }

  free ( x );

  return;
}
/******************************************************************************/

void r8poly_value_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_VALUE_TEST tests R8POLY_VALUE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 August 2017

  Author:

    John Burkardt
*/
{
  double c[5] = { 24.0, -50.0, +35.0, -10.0, 1.0 };
  int i;
  int m = 4;
  int n = 16;
  double p;
  double *x;
  double x_hi;
  double x_lo;

  printf ( "\n" );
  printf ( "R8POLY_VALUE_TEST\n" );
  printf ( "  R8POLY_VALUE evaluates a polynomial at\n" );
  printf ( "  one point, using a naive method.\n" );

  r8poly_print ( m, c, "  The polynomial coefficients:" );

  x_lo = 0.0;
  x_hi = 5.0;
  x = r8vec_linspace_new ( n, x_lo, x_hi );

  printf ( "\n" );
  printf ( "   I    X    P(X)\n" );
  printf ( "\n" );

  for ( i = 0; i < n; i++ )
  {
    p = r8poly_value ( m, c, x[i] );
    printf ( "  %2d  %8.4f  %14.6g\n", i, x[i], p );
  }

  free ( x );

  return;
}
/******************************************************************************/

void r8poly_values_horner_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY_VALUES_HORNER_TEST tests R8POLY_VALUE_HORNER.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 December 2013

  Author:

    John Burkardt
*/
{
  double c[5] = { 24.0, -50.0, +35.0, -10.0, 1.0 };
  int m = 4;
  int n = 16;
  double *p;
  double *x;
  double x_hi;
  double x_lo;

  printf ( "\n" );
  printf ( "R8POLY_VALUES_HORNER_TEST\n" );
  printf ( "  R8POLY_VALUES_HORNER evaluates a polynomial at a\n" );
  printf ( "  point, using Horner's method.\n" );

  r8poly_print ( m, c, "  The polynomial:" );

  x_lo = 0.0;
  x_hi = 5.0;
  x = r8vec_linspace_new ( n, x_lo, x_hi );

  p = r8poly_values_horner ( m, c, n, x );

  r8vec2_print ( n, x, p, "  X, P(X):" );

  free ( p );
  free ( x );

  return;
# undef N
}
/******************************************************************************/

void r8poly2_ex_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_EX_TEST tests R8POLY2_EX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 June 2012

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  int ierror;
  double x1;
  double x2;
  double x3;
  double xmin;
  double y1;
  double y2;
  double y3;
  double ymin;

  printf ( "\n" );
  printf ( "R8POLY2_EX_TEST\n" );
  printf ( "  R8POLY2_EX finds the extreme value\n" );
  printf ( "  of a parabola determined by three points.\n" );

  a =  2.0;
  b = -4.0;
  c = 10.0;

  x1 = 1.0;
  y1 = a * x1 * x1 + b * x1 + c;
  x2 = 2.0;
  y2 = a * x2 * x2 + b * x2 + c;
  x3 = 3.0;
  y3 = a * x3 * x3 + b * x3 + c;

  printf ( "\n" );
  printf ( "  Parabolic coefficients A = %g, B = %g, c = %g\n", a, b, c );
  printf ( "\n" );
  printf ( "  X, Y data:\n" );
  printf ( "\n" );
  printf ( "  %10.4g  %10.4g\n", x1, y1 );
  printf ( "  %10.4g  %10.4g\n", x2, y2 );
  printf ( "  %10.4g  %10.4g\n", x3, y3 );

  a = 0.0;
  b = 0.0;
  c = 0.0;

  ierror = r8poly2_ex ( x1, y1, x2, y2, x3, y3, &xmin, &ymin );

  if ( ierror == 0 )
  {
    printf ( "\n" );
    printf ( "  R8POLY2_EX returns XMIN = %g, YMIN = %g\n", xmin, ymin );
  }
  else
  {
    printf ( "\n" );
    printf ( "  R8POLY2_EX returns error code %d.\n", ierror );
  }

  return;
}
/******************************************************************************/

void r8poly2_ex2_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_EX2_TEST tests R8POLY2_EX2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 June 2012

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  int ierror;
  double x1;
  double x2;
  double x3;
  double xmin;
  double y1;
  double y2;
  double y3;
  double ymin;

  printf ( "\n" );
  printf ( "R8POLY2_EX2_TEST\n" );;
  printf ( "  R8POLY2_EX2 finds the extreme value\n" );
  printf ( "  of a parabola determined by three points.\n" );

  a =  2.0;
  b = -4.0;
  c = 10.0;

  x1 = 1.0;
  y1 = a * x1 * x1 + b * x1 + c;
  x2 = 2.0;
  y2 = a * x2 * x2 + b * x2 + c;
  x3 = 3.0;
  y3 = a * x3 * x3 + b * x3 + c;

  printf ( "\n" );
  printf ( "  Parabolic coefficients A = %g, B = %g, c = %g\n", a, b, c );
  printf ( "\n" );
  printf ( "  X, Y data:\n" );
  printf ( "\n" );
  printf ( "  %10.4g  %10.4g\n", x1, y1 );
  printf ( "  %10.4g  %10.4g\n", x2, y2 );
  printf ( "  %10.4g  %10.4g\n", x3, y3 );

  a = 0.0;
  b = 0.0;
  c = 0.0;

  ierror = r8poly2_ex2 ( x1, y1, x2, y2, x3, y3, &xmin, &ymin, &a, &b, &c );

  if ( ierror == 0 )
  {
    printf ( "\n" );
    printf ( "  R8POLY2_EX2 returns XMIN = %g, YMIN = %g\n", xmin, ymin );
    printf ( "  and A = %g, B = %g, c = %g\n", a, b, c );
  }
  else
  {
    printf ( "\n" );
    printf ( "  R8POLY2_EX2 returns error code %d.\n", ierror );
  }

  return;
}
/******************************************************************************/

void r8poly2_root_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_ROOT_TEST tests R8POLY2_ROOT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2018

  Author:

    John Burkardt
*/
{
  double a;
  double a_test[3] = { 2.0, 1.0, 1.0 };
  double b;
  double b_test[3] = { -2.0, -20.0, -2.0 };
  double c;
  double c_test[3] = { -24.0, 100.0, 10.0 };
  double complex r1;
  double complex r2;
  int test;
  const int test_num = 3;

  printf ( "\n" );
  printf ( "R8POLY2_ROOT_TEST\n" );
  printf ( "  R8POLY2_ROOT finds quadratic equation roots.\n" );
  printf ( "\n" );
  printf ( "         A         B         C     R1         R2\n" );
  printf ( "\n" );

  for ( test = 0; test < test_num; test++ )
  {
    a = a_test[test];
    b = b_test[test];
    c = c_test[test];

    r8poly2_root ( a, b, c, &r1, &r2 );

    printf ( "  %8.1f  %8.1f  %8.1f  (%14.6g,%14.6g)  (%14.6g,%14.6g)\n", 
      a, b, c, creal ( r1 ), cimag ( r1 ), creal ( r2 ), cimag ( r2 ) );
  }

  return;
}
/******************************************************************************/

void r8poly2_rroot_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_RROOT_TEST tests R8POLY2_RROOT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 August 2018

  Author:

    John Burkardt
*/
{
  double a;
  double a_test[5] = { 2.0,    1.0,  1.0, 1.0,  1.0 };
  double b;
  double b_test[5] = { -2.0,  -20.0, -2.0, 0.0, -6.0 };
  double c;
  double c_test[5] = { -24.0, 100.0, 10.0, 1.0, 10.0 };
  double r1;
  double r2;
  int test;
  const int test_num = 5;

  printf ( "\n" );
  printf ( "R8POLY2_RROOT_TEST\n" );
  printf ( "  R8POLY2_RROOT finds the real parts of quadratic equation roots.\n" );
  printf ( "\n" );
  printf ( "         A         B         C     R1         R2\n" );
  printf ( "\n" );

  for ( test = 0; test < test_num; test++ )
  {
    a = a_test[test];
    b = b_test[test];
    c = c_test[test];

    r8poly2_rroot ( a, b, c, &r1, &r2 );
 
    printf ( "  %8.1f  %8.1f  %8.1f  %14.6g  %14.6g\n", a, b, c, r1, r2 );
  }
 
  return;
}
/******************************************************************************/

void r8poly2_val_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_VAL_TEST tests R8POLY2_VAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
  int i;
  double x;
  double x1;
  double x2;
  double x3;
  double y;
  double y1;
  double y2;
  double y3;
  double yp;
  double ypp;

  printf ( "\n" );
  printf ( "R8POLY2_VAL_TEST\n" );
  printf ( "  R8POLY2_VAL evaluates a parabola given\n" );
  printf ( "  3 data points.\n" );
  printf ( "\n" );
  printf ( "  Our parabola will be 2*x^2 + 3 * x + 1.\n" );
  printf ( "\n" );
  printf ( "  Case 1: 3 distinct data points:\n" );
  printf ( "\n" );

  x1 = -1.0;
  x2 = 1.0;
  x3 = 3.0;

  r8poly2_f ( x1, &y1, &yp, &ypp );
  r8poly2_f ( x2, &y2, &yp, &ypp );
  r8poly2_f ( x3, &y3, &yp, &ypp );

  printf ( "  %g  %g\n", x1, y1 );
  printf ( "  %g  %g\n", x2, y2 );
  printf ( "  %g  %g\n", x3, y3 );

  printf ( "\n" );
  printf ( "  Sampled data:\n" );
  printf ( "\n" );
  printf ( "  X, Y, Y', Y''\n" );
  printf ( "\n" );
  for ( i = 0; i < 4; i++ )
  {
    x = ( double ) i;
    r8poly2_val ( x1, y1, x2, y2, x3, y3, x, &y, &yp, &ypp );
    printf ( "  %g  %g  %g  %g\n", x, y, yp, ypp );
  }

  printf ( "\n" );
  printf ( "  Case 2: X1=X2, X3 distinct:\n" );
  printf ( "\n" );

  x1 = -1.0;
  x2 = -1.0;
  x3 = 3.0;

  r8poly2_f ( x1, &y1, &y2, &ypp );
  r8poly2_f ( x3, &y3, &yp, &ypp );

  printf ( "  %g  %g\n", x1, y1 );
  printf ( "  %g  %g\n", x2, y2 );
  printf ( "  %g  %g\n", x3, y3 );

  printf ( "\n" );
  printf ( "  Sampled data:\n" );
  printf ( "\n" );
  printf ( "   X, Y, Y', Y''\n" );
  printf ( "\n" );
  for ( i = 0; i < 4; i++ )
  {
    x = ( double ) i;
    r8poly2_val ( x1, y1, x2, y2, x3, y3, x, &y, &yp, &ypp );
    printf ( "  %g  %g  %g  %g\n", x, y, yp, ypp );
  }

  printf ( "\n" );
  printf ( "  Case 3: X1=X2=X3:\n" );
  printf ( "\n" );

  x1 = -1.0;
  x2 = -1.0;
  x3 = -1.0;

  r8poly2_f ( x1, &y1, &y2, &y3 );

  printf ( "  %g  %g\n", x1, y1 );
  printf ( "  %g  %g\n", x2, y2 );
  printf ( "  %g  %g\n", x3, y3 );

  printf ( "\n" );
  printf ( "  Sampled data:\n" );
  printf ( "\n" );
  printf ( "  X, Y, Y', Y''\n" );
  printf ( "\n" );
  for ( i = 0; i < 4; i++ )
  {
    x = ( double ) i;
    r8poly2_val ( x1, y1, x2, y2, x3, y3, x, &y, &yp, &ypp );
    printf ( "  %g  %g  %g  %g\n", x, y, yp, ypp );
  }

  return;
}
/******************************************************************************/

void r8poly2_f ( double x, double *y, double *yp, double *ypp )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_F evaluates a parabola for us.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
  *y = 2.0 * x * x + 3.0 * x + 1.0;
  *yp = 4.0 * x + 3.0;
  *ypp = 4.0;

  return;
}
/******************************************************************************/

void r8poly2_val2_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY2_VAL2_TEST tests R8POLY2_VAL2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 June 2012

  Author:

    John Burkardt
*/
{
# define NDATA 5

  int i;
  int left;
  double xdata[NDATA];
  double xval;
  double ydata[NDATA];
  double yval;
  double zdata[NDATA];
  double zval;

  printf ( "\n" );
  printf ( "R8POLY2_VAL2_TEST\n" );
  printf ( "  R8POLY2_VAL2 evaluates parabolas through\n" );
  printf ( "  3 points in a table\n" );
  printf ( "\n" );
  printf ( "  Our data tables will actually be parabolas:\n" );
  printf ( "    A: 2*x^2 + 3 * x + 1.\n" );
  printf ( "    B: 4*x^2 - 2 * x + 5.\n" );
  printf ( "\n" );

  for ( i = 0; i < NDATA; i++ )
  {
    xval = 2.0 * ( double ) ( i + 1 );
    xdata[i] = xval;
    ydata[i] = 2.0 * xval * xval + 3.0 * xval + 1.0;
    zdata[i] = 4.0 * xval * xval - 2.0 * xval + 5.0;
    printf ( "%6d  %10g  %10g  %10g\n", i, xdata[i], ydata[i], zdata[i] );
  }

  printf ( "\n" );
  printf ( "  Interpolated data:\n" );
  printf ( "\n" );
  printf ( "  LEFT, X, Y1, Y2\n" );
  printf ( "\n" );

  for ( i = 0; i <= 4; i++ )
  {
    xval = ( double ) ( 2 * i + 1 );
    left = i;
    if ( NDATA - 3 < left )
    {
      left = NDATA - 3;
    }
    if ( left < 0 )
    {
      left = 0;
    }
    r8poly2_val2 ( NDATA, xdata, ydata, left, xval, &yval );
    r8poly2_val2 ( NDATA, xdata, zdata, left, xval, &zval );

    printf ( "%6d  %10g  %10g  %10g\n", left, xval, yval, zval );
  }

  return;
# undef NDATA
}
/******************************************************************************/

void r8poly3_root_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY3_ROOT_TEST tests R8POLY3_ROOT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2018

  Author:

    John Burkardt
*/
{
  double a;
  double a_test[4] = { 1.0, 9.0, 1.0, 1.0 };
  double b;
  double b_test[4] = { -6.0, -36.0, -5.0, -8.0 };
  double c;
  double c_test[4] = { 11.0, 54.0, 8.0, 25.0 };
  double d;
  double d_test[4] = { -6.0, -27.0, -4.0, -26.0 };
  double complex r1;
  double complex r2;
  double complex r3;
  int test;
  const int test_num = 4;
/*
  1: Three distinct real roots, 1, 2, 3.
  2: One repeated real root, 1.5, 1.5, 1.5.
  3: Two real roots, one repeated, 1, 2, 2.
  4: One real root, a complex conjugate pair, 2, 3+2I, 3-2I.
*/
  printf ( "\n" );
  printf ( "R8POLY3_ROOT_TEST\n" );
  printf ( "  R8POLY3_ROOT finds roots of cubic equations.\n" );
  printf ( "\n" );

  for ( test = 0; test < test_num; test++ )
  {
    a = a_test[test];
    b = b_test[test];
    c = c_test[test];
    d = d_test[test];

    printf ( "\n" );
    printf ( "  Polynomial coefficients A, B, C, D:\n" );
    printf ( "\n" );
    printf ( "  %g  %g  %g  %g\n", a, b, c, d );

    r8poly3_root ( a, b, c, d, &r1, &r2, &r3 );

    printf ( "\n" );
    printf ( "  Roots:\n" );
    printf ( "\n" );
    printf ( "  (%g,%g)\n", creal ( r1 ), cimag ( r1 ) );
    printf ( "  (%g,%g)\n", creal ( r2 ), cimag ( r2 ) );
    printf ( "  (%g,%g)\n", creal ( r3 ), cimag ( r3 ) );
  }

  return;
}
/******************************************************************************/

void r8poly4_root_test ( )

/******************************************************************************/
/*
  Purpose:

    R8POLY4_ROOT_TEST tests R8POLY4_ROOT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2018

  Author:

    John Burkardt
*/
{
  double a;
  double a_test[7] = {
    1.0, 1.0, 1.0, 1.0, 1.0, 
    1.0, 1.0 };
  double b;
  double b_test[7] = {
    -10.0, -5.0, -22.0, -16.0, -20.0, 
    2.0, 0.0 };
  double c;
  double c_test[7] = {
    35.0, 1.0, 141.0, 72.0, 150.0, 
    1.0, 13.0 };
  double d;
  double d_test[7] = {
    -50.0, 21.0, -220.0, -128.0, -500.0, 
    8.0, 0.0 };
  double e;
  double e_test[7] = {
    24.0, -18.0, +100.0, 80.0, 625.0, 
    -12.0, 36.0 };
  double complex r1;
  double complex r2;
  double complex r3;
  double complex r4;
  int test;
  const double test_num = 7;
/*
  1: Four distinct real roots, 1, 2, 3, 4.
  2: Three distinct real roots, 1, -2, 3, 3
  3: Two distinct real roots, 1, 1, 10, 10.
  4: Two distinct real roots, 2, 2, 2, 10
  5: One real root, 5, 5, 5, 5
  6: Two distinct real roots, one complex conjugate pair.
  7: Two distinct complex conjugate pairs.
*/
  printf ( "\n" );
  printf ( "R8POLY4_ROOT_TEST\n" );
  printf ( "  R8POLY4_ROOT finds roots of quartic equations.\n" );
  printf ( "\n" );

  for ( test = 0; test < test_num; test++ )
  {
    a = a_test[test];
    b = b_test[test];
    c = c_test[test];
    d = d_test[test];
    e = e_test[test];

    printf ( "\n" );
    printf ( "  A = %g\n", a );
    printf ( "  B = %g\n", b );
    printf ( "  C = %g\n", c );
    printf ( "  D = %g\n", d );
    printf ( "  E = %g\n", e );

    r8poly4_root ( a, b, c, d, e, &r1, &r2, &r3, &r4 );

    printf ( "\n" );
    printf ( "  Roots:\n" );
    printf ( "\n" );
    printf ( "  (%g,%g)\n", creal ( r1 ), cimag ( r1 ) );
    printf ( "  (%g,%g)\n", creal ( r2 ), cimag ( r2 ) );
    printf ( "  (%g,%g)\n", creal ( r3 ), cimag ( r3 ) );
    printf ( "  (%g,%g)\n", creal ( r4 ), cimag ( r4 ) );
  }

  return;
}
/******************************************************************************/

void r8vec_even_new_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_EVEN_NEW_TEST tests R8VEC_EVEN_NEW.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2018

  Author:

    John Burkardt
*/
{
  int n = 10;
  double *x;
  double xhi = 99.0;
  double xlo = 0.0;

  printf ( "\n" );
  printf ( "R8VEC_EVEN_NEW_TEST\n" );
  printf ( "  R8VEC_EVEN_NEW computes N evenly spaced values\n" );
  printf ( "  between XLO and XHI.\n" );
  printf ( "\n" );
  printf ( "  XLO = %g\n", xlo );
  printf ( "  XHI = %g\n", xhi );
  printf ( "  while N = %d\n", n );

  x = r8vec_even_new ( n, xlo, xhi );

  r8vec_print ( n, x, "  Resulting array:" );

  free ( x );

  return;
}
/******************************************************************************/

void r8vec_even_select_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_EVEN_SELECT_TEST tests R8VEC_EVEN_SELECT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2018

  Author:

    John Burkardt
*/
{
  int n = 10;
  int i;
  double xhi = 99.0;
  double xi;
  double xlo = 0.0;

  printf ( "\n" );
  printf ( "R8VEC_EVEN_SELECT_TEST\n" );
  printf ( "  R8VEC_EVEN_SELECT computes one of N evenly spaced values\n" );
  printf ( "  between XLO and XHI.\n" );
  printf ( "\n" );
  printf ( "  XLO = %g\n", xlo );
  printf ( "  XHI = %g\n", xhi );
  printf ( "  while N = %d\n", n );

  for ( i = 2; i <= n; i = i + 3 )
  {
    xi = r8vec_even_select ( n, xlo, xhi, i );
    printf ( "  %2d  %14.6g\n", i, xi );
  }

  return;
}
/******************************************************************************/

void r8vec_indicator1_new_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_INDICATOR1_NEW_TEST tests R8VEC_INDICATOR1_NEW.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 September 2014

  Author:

    John Burkardt
*/
{
  int n;
  double *v;

  printf ( "\n" );
  printf ( "R8VEC_INDICATOR1_NEW_TEST\n" );
  printf ( "  R8VEC_INDICATOR1_NEW returns an indicator vector.\n" );

  n = 10;
  v = r8vec_indicator1_new ( n );
  r8vec_print ( n, v, "  Indicator1 vector:" );
  free ( v );

  return;
# undef N
}
/******************************************************************************/

void r8vec_is_distinct_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_IS_DISTINCT_TEST tests R8VEC_IS_DISTINCT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 August 2018

  Author:

    John Burkardt
*/
{
  int n = 3;
  double x1[3] = { 0.0, 0.0, 0.0 };
  double x2[3] = { 1.0, 0.0, 1.0 };
  double x3[3] = { 0.0, 2.0, 1.0 };

  printf ( "\n" );
  printf ( "R8VEC_IS_DISTINCT_TEST\n" );
  printf ( "  R8VEC_IS_DISTINCT is TRUE if an R8VEC only contains\n" );
  printf ( "  distinct entries.\n" );

  printf ( "\n" );
  r8vec_transpose_print ( n, x1, "  X:" );
  if ( r8vec_is_distinct ( n, x1 ) )
  {
    printf ( "  X is distinct.\n" );
  }
  else
  {
    printf ( "  X is NOT distinct.\n" );
  }

  printf ( "\n" );
  r8vec_transpose_print ( n, x2, "  X:" );
  if ( r8vec_is_distinct ( n, x2 ) )
  {
    printf ( "  X is distinct.\n" );
  }
  else
  {
    printf ( "  X is NOT distinct.\n" );
  }

  printf ( "\n" );
  r8vec_transpose_print ( n, x3, "  X:" );
  if ( r8vec_is_distinct ( n, x3 ) )
  {
    printf ( "  X is distinct.\n" );
  }
  else
  {
    printf ( "  X is NOT distinct.\n" );
  }

  return;
}
/******************************************************************************/

void r8vec_linspace_new_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_LINSPACE_NEW_TEST tests R8VEC_LINSPACE_NEW.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2012

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int n = 5;
  double *x;

  printf ( "\n" );
  printf ( "R8VEC_LINSPACE_NEW_TEST\n" );
  printf ( "  For a R8VEC:\n" );
  printf ( "  R8VEC_LINSPACE_NEW: evenly spaced points between A and B;\n" );

  a = 10.0;
  b = 20.0;

  x = r8vec_linspace_new ( n, a, b );
  r8vec_print ( n, x, "  r8vec_linspace ( 5, 10, 20 )" );
  free ( x );

  return;
}
/******************************************************************************/

void r8vec_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_PRINT_TEST tests R8VEC_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 August 2014

  Author:

    John Burkardt
*/
{
  double a[4] = { 123.456, 0.000005, -1.0E+06, 3.14159265 };
  int n = 4;

  printf ( "\n" );
  printf ( "R8VEC_PRINT_TEST\n" );
  printf ( "  R8VEC_PRINT prints an R8VEC.\n" );

  r8vec_print ( n, a, "  The R8VEC:" );

  return;
}
/******************************************************************************/

void r8vec_transpose_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_TRANSPOSE_PRINT_TEST tests R8VEC_TRANSPOSE_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 November 2010

  Author:

    John Burkardt
*/
{
  int n = 12;
  int seed;
  double *x;

  seed = 123456789;

  printf ( "\n" );
  printf ( "R8VEC_TRANSPOSE_PRINT_TEST\n" );
  printf ( "  R8VEC_TRANSPOSE_PRINT prints an R8VEC \"tranposed\",\n" );
  printf ( "  that is, placing multiple entries on a line.\n" );

  x = r8vec_uniform_01_new ( n, &seed );

  r8vec_transpose_print ( n, x, "  The vector X:" );

  free ( x );

  return;
}
/******************************************************************************/

void r8vec_uniform_01_new_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_NEW_TEST tests R8VEC_UNIFORM_01_NEW.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 June 2012

  Author:

    John Burkardt
*/
{
# define N 10

  int j;
  double *r;
  int seed;

  printf ( "\n" );
  printf ( "R8VEC_UNIFORM_01_NEW_TEST\n" );
  printf ( "  R8VEC_UNIFORM_01_NEW returns a random R8VEC\n" );
  printf ( "  with entries in a given range [ 0.0, 1.0 ]\n" );
  printf ( "\n" );

  seed = 123456789;

  for ( j = 1; j <= 3; j++ )
  {
    printf ( "\n" );
    printf ( "  Input SEED = %d\n", seed );
    printf ( "\n" );

    r = r8vec_uniform_01_new ( N, &seed );

    r8vec_print ( N, r, "  Random R8VEC:" );

    free ( r );
  }

  return;
# undef N
}
/******************************************************************************/

void r8vec2_print_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC2_PRINT_TEST tests R8VEC2_PRINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 January 2016

  Author:

    John Burkardt
*/
{
  double a[5] = { 123.456, 0.000005, -1.0E+06, 3.14159265 };
  double b[5];
  double c[5];
  int i;
  int n = 5;

  printf ( "\n" );
  printf ( "R8VEC2_PRINT_TEST\n" );
  printf ( "  R8VEC2_PRINT prints a pair of R8VEC's.\n" );

  for ( i = 0; i < n; i++ )
  {
    b[i] = a[i] * a[i];
    c[i] = sqrt ( a[i] );
  }

  r8vec2_print ( n, b, c, "  Squares and roots:" );

  return;
}
/******************************************************************************/

void roots_to_r8poly_test ( )

/******************************************************************************/
/*
  Purpose:

    ROOTS_TO_R8POLY_TEST tests ROOTS_TO_R8POLY.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 March 2015

  Author:

    John Burkardt
*/
{
  double *c;
  int n = 5;
  double x[5] = { 1.0, -4.0, 3.0, 0.0, 3.0 };

  printf ( "\n" );
  printf ( "ROOTS_TO_R8POLY_TEST:\n" );
  printf ( "  ROOTS_TO_R8POLY is given N real roots,\n" );
  printf ( "  and constructs the coefficient vector\n" );
  printf ( "  of the corresponding polynomial.\n" );

  r8vec_print ( n, x, "  N real roots:" );

  c = roots_to_r8poly ( n, x );

  r8poly_print ( n, c, "  Corresponding polynomial:" );

  free ( c );

  return;
}
