# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "chebyshev_polynomial.h"

int main ( );

void test01 ( );
void t_mass_matrix_test ( );
void t_moment_test ( );
void t_polynomial_test ( );
void t_polynomial_ab_test ( );
void t_polynomial_ab_value_test ( );
void t_polynomial_coefficients_test ( );
void t_polynomial_plot_test ( );
void t_polynomial_value_test ( );
void t_polynomial_zeros_test ( );
void t_quadrature_rule_test ( );
void test07 ( );
void test08 ( );
void test09 ( );
void test10 ( );
void tt_product_test ( );
void tt_product_integral_test ( );
void ttt_product_integral_test ( );
void tu_product_test ( );

void u_mass_matrix_test ( );
void u_moment_test ( );
void u_polynomial_test ( );
void u_polynomial_ab_test ( );
void u_polynomial_ab_value_test ( );
void u_polynomial_coefficients_test ( );
void u_polynomial_plot_test ( );
void u_polynomial_value_test ( );
void u_polynomial_zeros_test ( );
void u_quadrature_rule_test ( );
void uu_product_test ( );
void uu_product_integral_test ( );

void v_mass_matrix_test ( );
void v_moment_test ( );
void v_polynomial_test ( );
void v_polynomial_ab_test ( );
void v_polynomial_ab_value_test ( );
void v_polynomial_coefficients_test ( );
void v_polynomial_plot_test ( );
void v_polynomial_value_test ( );
void v_polynomial_zeros_test ( );
void v_quadrature_rule_test ( );
void vv_product_integral_test ( );

void w_mass_matrix_test ( );
void w_moment_test ( );
void w_polynomial_test ( );
void w_polynomial_ab_test ( );
void w_polynomial_ab_value_test ( );
void w_polynomial_coefficients_test ( );
void w_polynomial_plot_test ( );
void w_polynomial_value_test ( );
void w_polynomial_zeros_test ( );
void w_quadrature_rule_test ( );
void ww_product_integral_test ( );

/******************************************************************************/

int main ( )

/****************************************************************************/
/*
  Purpose:

    MAIN is the main program for CHEBYSHEV_POLYNOMIAL_TEST.

  Discussion:

    CHEBYSHEV_POLYNOMIAL_TEST tests the CHEBYSHEV_POLYNOMIAL library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 July 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "CHEBYSHEV_POLYNOMIAL_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the CHEBYSHEV_POLYNOMIAL library.\n" );

  test01 ( );
  t_mass_matrix_test ( );
  t_moment_test ( );
  t_polynomial_test ( );
  t_polynomial_ab_test ( );
  t_polynomial_ab_value_test ( );
  t_polynomial_coefficients_test ( );
  t_polynomial_plot_test ( );
  t_polynomial_value_test ( );
  t_polynomial_zeros_test ( );
  t_quadrature_rule_test ( );
  test07 ( );
  test08 ( );
  test09 ( );
  test10 ( );
  tt_product_test ( );
  tt_product_integral_test ( );
  ttt_product_integral_test ( );
  tu_product_test ( );

  u_mass_matrix_test ( );
  u_moment_test ( );
  u_polynomial_test ( );
  u_polynomial_ab_test ( );
  u_polynomial_ab_value_test ( );
  u_polynomial_coefficients_test ( );
  u_polynomial_plot_test ( );
  u_polynomial_value_test ( );
  u_polynomial_zeros_test ( );
  u_quadrature_rule_test ( );
  uu_product_test ( );
  uu_product_integral_test ( );

  v_mass_matrix_test ( );
  v_moment_test ( );
  v_polynomial_test ( );
  v_polynomial_ab_test ( );
  v_polynomial_ab_value_test ( );
  v_polynomial_coefficients_test ( );
  v_polynomial_plot_test ( );
  v_polynomial_value_test ( );
  v_polynomial_zeros_test ( );
  v_quadrature_rule_test ( );
  vv_product_integral_test ( );

  w_mass_matrix_test ( );
  w_moment_test ( );
  w_polynomial_test ( );
  w_polynomial_ab_test ( );
  w_polynomial_ab_value_test ( );
  w_polynomial_coefficients_test ( );
  w_polynomial_plot_test ( );
  w_polynomial_value_test ( );
  w_polynomial_zeros_test ( );
  w_quadrature_rule_test ( );
  ww_product_integral_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "CHEBYSHEV_POLYNOMIAL_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( )

/****************************************************************************/
/*
  Purpose:

    TEST01 tests T_PROJECT_COEFFICIENTS_DATA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 June 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double *c;
  double *d;
  double *d2;
  int i;
  int m;
  int n;
  int seed;
  double *x;

  printf ( "\n" );
  printf ( "CHEBYSHEV_POLYNOMIAL_TEST01:\n" );
  printf ( "  T_PROJECT_COEFFICIENTS_DATA estimates the Chebyshev polynomial\n" );
  printf ( "  coefficients for a function given as data (x,fx).\n" );
  printf ( "\n" );
  printf ( "  Here, we use fx = f(x) = x^2 for the data.\n" );
  printf ( "\n" );
  printf ( "  Since T(0,x) = 1 and T(2,x) = 2*x^2 - 1, the correct expansion is\n" );
  printf ( "  f(x) = 1/2 T(0,x) + 0 T(1,x) + 1/2 T(2,x) + 0 * all other polys,\n" );
  printf ( "  if our Chebyshev polynomials are based in [-1,+1].\n" );
/*
  Data in [0,1];
*/
  a = 0.0;
  b = 1.0;

  printf ( "\n" );
  printf ( "  Chebyshev polynomials will be based in [%g,%g]\n", a, b );
/*
  Compute sample data.
*/
  m = 20;
  seed = 123456789;
  x = r8vec_uniform_ab_new ( m, a, b, &seed );
  d = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    d[i] = x[i] * x[i];
  }

  r8vec2_print ( m, x, d, "  Data ( X, D ):" );

  n = 4;
  c = t_project_coefficients_data ( a, b, m, n, x, d );

  r8vec_print ( n, c, "  Coefficients of Chebyshev expansion of degree 4." );
/*
  Compare Chebyshev expansion and original function.
*/
  d2 = t_project_value_ab ( m, n, x, c, a, b );

  printf ( "\n" );
  printf ( "   I      X(I)        D(I)      Chebyshev(X(I))\n" );
  printf ( "\n" );
  for ( i = 0; i < m; i++ )
  {
    printf ( "  %2d  %12g  %12g  %12g\n", i, x[i], d[i], d2[i] );
  }
/*
  Free memory.
*/
  free ( c );
  free ( d );
  free ( d2 );
  free ( x );

  return;
}
/******************************************************************************/

void t_mass_matrix_test ( )

/******************************************************************************/
/*
  Purpose:

    T_MASS_MATRIX_TEST tests T_MASS_MATRIX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 July 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int n;

  printf ( "\n" );
  printf ( "T_MASS_MATRIX_TEST:\n" );
  printf ( "  T_MASS_MATRIX computes the mass matrix for the\n" );
  printf ( "  Chebyshev T polynomials T(i,x).\n" );
  printf ( "  A(I,J) = integral ( -1 <=x <= +1 ) T(i,x) T(j,x) / sqrt ( 1 - x^2 ) dx\n" );
  printf ( "  0    if i is not equal to j;\n" );
  printf ( "  pi   if i = j = 0;\n" );
  printf ( "  pi/2 if i = j =/= 0.\n" );

  n = 3;
  a = t_mass_matrix ( n );

  r8mat_print ( n + 1, n + 1, a, "  T mass matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void t_moment_test ( )

/******************************************************************************/
/*
  Purpose:

    T_MOMENT_TEST tests T_MOMENT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 July 2015

  Author:

    John Burkardt
*/
{
  int e;
  double value;

  printf ( "\n" );
  printf ( "T_MOMENT_TEST:\n" );
  printf ( "  T_MOMENT returns the value of\n" );
  printf ( "  integral ( -1 <=x <= +1 ) x^e / sqrt ( 1 - x^2 ) dx\n" );
  printf ( "\n" );
  printf ( "   E       Moment\n" );
  printf ( "\n" );
  for ( e = 0; e <= 10; e++ )
  {
    value = t_moment ( e );
    printf ( "  %2d  %14.6g\n", e, value );
  }

  return;
}
/******************************************************************************/

void t_polynomial_test ( )

/****************************************************************************/
/*
  Purpose:

    T_POLYNOMIAL_TEST tests T_POLYNOMIAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 July 2015

  Author:

    John Burkardt
*/
{
  double fx;
  double *fx2;
  int n;
  int n_data;
  double x;
  double x_vec[1];

  printf ( "\n" );
  printf ( "T_POLYNOMIAL_TEST:\n" );
  printf ( "  T_POLYNOMIAL evaluates the Chebyshev polynomial T(n,x).\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X        T(n,x)        T(n,x)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    t_polynomial_values ( &n_data, &n, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    if ( n < 0 )
    {
      continue;
    }

    x_vec[0] = x;
    fx2 = t_polynomial ( 1, n, x_vec );

    printf ( "  %8d  %14g  %14g  %14g\n", n, x, fx, fx2[n] );

    free ( fx2 );

  }

  return;
}
/******************************************************************************/

void t_polynomial_ab_test ( )

/****************************************************************************/
/*
  Purpose:

    T_POLYNOMIAL_AB_TEST tests T_POLYNOMIAL_AB.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int m;
  int n;
  double *v;
  double *x;

  m = 11;
  n = 5;

  printf ( "\n" );
  printf ( "T_POLYNOMIAL_AB_TEST:\n" );
  printf ( "  T_POLYNOMIAL_AB evaluates Chebyshev polynomials TAB(n,x)\n" );
  printf ( "  shifted from [-1,+1] to the domain [A,B].\n" );
  printf ( "\n" );
  printf ( "  Here, we will use the new domain [0,1]\n" );
  printf ( "  and the desired maximum polynomial degree will be N = 5.\n" );

  a = 0.0;
  b = 1.0;
  x = r8vec_linspace_new ( m, a, b );
  
  v = t_polynomial_ab ( a, b, m, n, x );

  r8mat_print ( m, n + 1, v, "  Tables of T values:" );

  free ( v );
  free ( x );

  return;
}
/******************************************************************************/

void t_polynomial_ab_value_test ( )

/****************************************************************************/
/*
  Purpose:

    T_POLYNOMIAL_AB_VALUE_TEST tests T_POLYNOMIAL_AB_VALUE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double fx;
  double fx2;
  int n;
  int n_data;
  double x01;

  printf ( "\n" );
  printf ( "T_POLYNOMIAL_AB_VALUE_TEST:\n" );
  printf ( "  T_POLYNOMIAL_AB_VALUE evaluates Chebyshev polynomials TAB(n,x)\n" );
  printf ( "  shifted from [-1,+1] to the domain [A,B].\n" );
  printf ( "\n" );
  printf ( "  Here, we will use the new domain [0,1].\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X01    T01(n,x)       T01(n,x)\n" );
  printf ( "\n" );

  a = 0.0;
  b = 1.0;

  n_data = 0;

  for ( ; ; )
  {
    t_polynomial_01_values ( &n_data, &n, &x01, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = t_polynomial_ab_value ( a, b, n, x01 );

    printf ( "  %8d  %14g  %14g  %14g\n", n, x01, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void t_polynomial_coefficients_test ( )

/****************************************************************************/
/*
  Purpose:

    T_POLYNOMIAL_COEFFICIENTS_TEST tests T_POLYNOMIAL_COEFFICIENTS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 July 2015

  Author:

    John Burkardt
*/
{
  double *c;
  double *c2;
  int i;
  int j;
  int n;

  printf ( "\n" );
  printf ( "T_POLYNOMIAL_COEFFICIENTS_TEST\n" );
  printf ( "  T_POLYNOMIAL_COEFFICIENTS determines the polynomial coefficients \n" );
  printf ( "  of T(n,x).\n" );

  n = 5;

  c = t_polynomial_coefficients ( n );

  for ( i = 0; i <= n; i++ )
  {
    c2 = ( double * ) malloc ( ( i + 1 ) * sizeof ( double ) );
    for ( j = 0; j <= i; j++ )
    {
      c2[j] = c[i+j*(n+1)];
    }
    r8poly_print ( i, c2, "" );
    free ( c2 );
  }
  free ( c );

  return;
}
/******************************************************************************/

void t_polynomial_plot_test ( )

/******************************************************************************/
/*
  Purpose:

    T_POLYNOMIAL_PLOT_TEST tests T_POLYNOMIAL_PLOT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 July 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n_num = 6;
  int n_val[6];
  char output_filename[255];

  printf ( "\n" );
  printf ( "T_POLYNOMIAL_PLOT_TEST\n" );
  printf ( "  T_POLYNOMIAL_PLOT plots selected\n" );
  printf ( "  Chebyshev polynomials T(n,x).\n" );

  for ( i = 0; i <= 5; i++ )
  {
    n_val[i] = i;
  }

  strcpy ( output_filename, "t_polynomial_plot.png" );

  t_polynomial_plot ( n_num, n_val, output_filename );

  return;
}
/******************************************************************************/

void t_polynomial_value_test ( )

/****************************************************************************/
/*
  Purpose:

    T_POLYNOMIAL_VALUE_TEST tests T_POLYNOMIAL_VALUE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 July 2015

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  int n;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "T_POLYNOMIAL_VALUE_TEST:\n" );
  printf ( "  T_POLYNOMIAL_VALUE evaluates the Chebyshev polynomial T(n,x).\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X        T(n,x)        T(n,x)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    t_polynomial_values ( &n_data, &n, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = t_polynomial_value ( n, x );

    printf ( "  %8d  %14g  %14g  %14g\n", n, x, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void t_polynomial_zeros_test ( )

/****************************************************************************/
/*
  Purpose:

    T_POLYNOMIAL_ZEROS_TEST tests T_POLYNOMIAL_ZEROS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 August 2013

  Author:

    John Burkardt
*/
{
  double *fx;
  int i;
  int n;
  int n_max = 5;
  double *z;

  printf ( "\n" );
  printf ( "T_POLYNOMIAL_ZEROS_TEST:\n" );
  printf ( "  T_POLYNOMIAL_ZEROS returns zeroes of T(n,x).\n" );
  printf ( "\n" );
  printf ( "       N      X        T(n,x)\n" );
  printf ( "\n" );

  for ( n = 1; n <= n_max; n++ )
  {
    z = t_polynomial_zeros ( n );
    fx = t_polynomial ( n, n, z );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %8d  %8g  %14g\n", n, z[i], fx[i+n*n] );
    }
    printf ( "\n" );
    free ( fx );
    free ( z );
  }

  return;
}
/******************************************************************************/

void t_quadrature_rule_test ( )

/****************************************************************************/
/*
  Purpose:

    T_QUADRATURE_RULE_TEST tests T_QUADRATURE_RULE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 August 2013

  Author:

    John Burkardt
*/
{
  int e;
  double *f;
  int i;
  int n;
  double q;
  double q_exact;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "T_QUADRATURE_RULE_TEST:\n" );
  printf ( "  T_QUADRATURE_RULE computes the quadrature rule\n" );
  printf ( "  associated with T(n,x);\n" );

  n = 7;
  x = ( double * ) malloc ( n * sizeof ( double ) );
  w = ( double * ) malloc ( n * sizeof ( double ) );

  t_quadrature_rule ( n, x, w );

  r8vec2_print ( n, x, w, "    N      X            W" );

  printf ( "\n" );
  printf ( "  Use the quadrature rule to estimate:\n" );
  printf ( "\n" );
  printf ( "    Q = Integral ( -1 <= X <= +1 ) X^E / sqrt ( 1-x^2) dx\n" );
  printf ( "\n" );
  printf ( "   E       Q_Estimate      Q_Exact\n" );
  printf ( "\n" );

  f = ( double * ) malloc ( n * sizeof ( double ) );

  for ( e = 0; e <= 2 * n - 1; e++ )
  {
    if ( e == 0 )
    {
      for ( i = 0; i < n; i++ )
      {
        f[i] = 1.0;
      }
    }
    else
    {
      for ( i = 0; i < n; i++ )
      {
        f[i] = pow ( x[i], e );
      }
    }
    q = r8vec_dot_product ( n, w, f );
    q_exact = t_moment ( e );
    printf ( "  %2d  %14g  %14g\n", e, q, q_exact );
  }

  free ( f );
  free ( w );
  free ( x );

  return;
}
/******************************************************************************/

void test07 ( )

/****************************************************************************/
/*
  Purpose:

    TEST07 tests T_PROJECT_COEFFICIENTS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 August 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double *c;
  int n;

  printf ( "\n" );
  printf ( "TEST07:\n" );
  printf ( "  T_PROJECT_COEFFICIENTS computes the Chebyshev coefficients\n" );
  printf ( "  of a function defined over [-1,+1].\n" );
  printf ( "  T_PROJECT_COEFFICIENTS_AB works in [A,B].\n" );

  n = 3;
  c = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  c = t_project_coefficients ( n, exp );
  r8vec_print ( n + 1, c, "  Chebyshev coefficients for exp(x) in [-1,+1]" );
  free ( c );

  n = 5;
  c = ( double * ) malloc ( ( n + 1 ) * sizeof ( double ) );
  c = t_project_coefficients ( n, exp );
  r8vec_print ( n + 1, c, "  Chebyshev coefficients for exp(x) in [-1,+1]" );
  free ( c );

  n = 5;
  c = ( double * ) malloc ( (n+1) * sizeof ( double ) );
  c = t_project_coefficients ( n, sin );
  r8vec_print ( n + 1, c, "  Chebyshev coefficients for sin(x) in [-1,+1]" );
  free ( c );
/*
  Repeat calculation with T_PROJECT_COEFFICIENTS_AB.
*/
  n = 5;
  c = ( double * ) malloc ( (n+1) * sizeof ( double ) );
  a = -1.0;
  b = +1.0;
  c = t_project_coefficients_ab ( n, sin, a, b );
  r8vec_print ( n + 1, c, "  Chebyshev coefficients for sin(x) in [-1,+1]" );
  free ( c );
/*
  Now try a different interval.
*/
  n = 5;
  c = ( double * ) malloc ( (n+1) * sizeof ( double ) );
  a = 0.0;
  b = 1.0;
  c = t_project_coefficients_ab ( n, sqrt, a, b );
  r8vec_print ( n + 1, c, "  Chebyshev coefficients for sqrt(x) in [0,+1]" );
  free ( c );

  return;
}
/******************************************************************************/

void test08 ( )

/****************************************************************************/
/*
  Purpose:

    TEST08 tests T_PROJECT_COEFFICIENTS_DATA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 August 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double *c;
  double *d;
  int i;
  int m;
  int n;
  int seed;
  double *x;

  printf ( "\n" );
  printf ( "TEST08:\n" );
  printf ( "  T_PROJECT_COEFFICIENTS_DATA computes the Chebyshev\n" );
  printf ( "  coefficients of a function defined by data.\n" );
  printf ( "\n" );
  printf ( "  We are looking for an approximation that is good in [-1,+1].\n" );
  printf ( "\n" );
  printf ( "  Begin by using equally spaced points in [-1,+1].\n" );

  a = -1.0;
  b = +1.0;
  m = 10;
  x = r8vec_linspace_new ( m, a, b );
  d = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    d[i] = exp ( x[i] );
  }
  n = 3;
  c = t_project_coefficients_data ( a, b, m, n, x, d );
  r8vec_print ( n + 1, c, "  Chebyshev coefficients for exp(x) on [-1,+1]" );
  free ( c );
  free ( d );
  free ( x );

  a = -1.0;
  b = +1.0;
  m = 10;
  x = r8vec_linspace_new ( m, a, b );
  d = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    d[i] = exp ( x[i] );
  }
  n = 5;
  c = t_project_coefficients_data ( a, b, m, n, x, d );
  r8vec_print ( n + 1, c, "  Chebyshev coefficients for exp(x) on [-1,+1]" );
  free ( c );
  free ( d );
  free ( x );

  a = -1.0;
  b = +1.0;
  m = 10;
  x = r8vec_linspace_new ( m, a, b );
  d = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    d[i] = sin ( x[i] );
  }
  n = 5;
  c = t_project_coefficients_data ( a, b, m, n, x, d );
  r8vec_print ( n + 1, c, "  Chebyshev coefficients for sin(x) on [-1,+1]" );
  free ( c );
  free ( d );
  free ( x );

  printf ( "\n" );
  printf ( "  Now sample equally spaced points in [0,+1].\n" );
  printf ( "  The approximation still applies to the interval [-1,+1].\n" );

  a = 0.0;
  b = +1.0;
  m = 10;
  x = r8vec_linspace_new ( m, a, b );
  d = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    d[i] = sin ( x[i] );
  }
  n = 5;
  c = t_project_coefficients_data ( a, b, m, n, x, d );
  r8vec_print ( n + 1, c, "  Chebyshev coefficients for sin(x) on [0,+1]" );
  free ( c );
  free ( d );
  free ( x );

  a = 0.0;
  b = +1.0;
  m = 10;
  x = r8vec_linspace_new ( m, a, b );
  d = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    d[i] = sqrt ( x[i] );
  }
  n = 5;
  c = t_project_coefficients_data ( a, b, m, n, x, d );
  r8vec_print ( n + 1, c, "  Chebyshev coefficients for sqrt(x) on [0,+1]" );
  free ( c );
  free ( d );
  free ( x );

  printf ( "\n" );
  printf ( "  Now random points in [-1,+1].\n" );

  a = -1.0;
  b = +1.0;
  m = 10;
  seed = 123456789;
  x = r8vec_uniform_ab_new ( m, a, b, &seed );
  d = ( double * ) malloc ( m * sizeof ( double ) );
  for ( i = 0; i < m; i++ )
  {
    d[i] = sin ( x[i] );
  }
  n = 5;
  c = t_project_coefficients_data ( a, b, m, n, x, d );
  r8vec_print ( n + 1, c, "  Chebyshev coefficients for sin(x) on [-1,+1]" );
  free ( c );
  free ( d );
  free ( x );

  return;
}
/******************************************************************************/

void test09 ( )

/****************************************************************************/
/*
  Purpose:

    TEST09 compares a function and projection over [-1,+1].

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 August 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double *c;
  int i;
  int m;
  int n;
  double r;
  double *v;
  double *x;

  printf ( "\n" );
  printf ( "TEST09:\n" );
  printf ( "  T_PROJECT_COEFFICIENTS computes the Chebyshev interpolant C(F)(n,x)\n" );
  printf ( "  of a function F(x) defined over [-1,+1].\n" );
  printf ( "  T_PROJECT_VALUE evaluates that projection.\n" );

  printf ( "\n" );
  printf ( "  Compute projections of order N to exp(x) over [-1,+1],\n" );
  printf ( "\n" );
  printf ( "   N   Max||F(x)-C(F)(n,x)||\n" );
  printf ( "\n" );

  a = -1.0;
  b = +1.0;

  for ( n = 0; n <= 10; n++ )
  {
    c = t_project_coefficients ( n, exp );
    m = 101;
    x = r8vec_linspace_new ( m, a, b );
    v = t_project_value ( m, n, x, c );
    r = 0.0;
    for ( i = 0; i < m; i++ )
    {
      r = r8_max ( r, fabs ( v[i] - exp ( x[i] ) ) );
    }
    printf ( "  %2d  %14g\n", n, r );
    free ( c );
    free ( v );
    free ( x );
  }

  return;
}
/******************************************************************************/

void test10 ( )

/****************************************************************************/
/*
  Purpose:

    TEST10 compares a function and projection over [A,B].

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 August 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double *c;
  int i;
  int m;
  int n;
  double r;
  double *v;
  double *x;

  printf ( "\n" );
  printf ( "TEST10:\n" );
  printf ( "  T_PROJECT_COEFFICIENTS_AB computes the Chebyshev interpolant C(F)(n,x)\n" );
  printf ( "  of a function F(x) defined over [A,B].\n" );
  printf ( "  T_PROJECT_VALUE_AB evaluates that projection.\n" );

  a = 0.0;
  b = 1.5;

  printf ( "\n" );
  printf ( "  Compute projections of order N to exp(x) over [%g,%g]\n", a, b );
  printf ( "\n" );
  printf ( "   N   Max||F(x)-C(F)(n,x)||\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    c = t_project_coefficients_ab ( n, exp, a, b );
    m = 101;
    x = r8vec_linspace_new ( m, a, b );
    v = t_project_value_ab ( m, n, x, c, a, b );
    r = 0.0;
    for ( i = 0; i < m; i++ )
    {
      r = r8_max ( r, fabs ( v[i] - exp ( x[i] ) ) );
    }
    printf ( "  %2d  %14g\n", n, r );
    free ( c );
    free ( v );
    free ( x );
  }

  return;
}
/******************************************************************************/

void tt_product_test ( )

/******************************************************************************/
/*
  Purpose:

    TT_PRODUCT_TEST tests TT_PRODUCT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 July 2015

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  double r8_hi;
  double r8_lo;
  int seed;
  int test;
  double ti;
  double titj;
  double tj;
  double x;

  printf ( "\n" );
  printf ( "TT_PRODUCT_TEST:\n" );
  printf ( "  TT_PRODUCT(I,J;X) = T(I,X) * T(J,X)\n" );

  r8_lo = -1.0;
  r8_hi = +1.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "   I   J      X               TI              TJ              TI*TJ       TT_PRODUCT\n" );
  printf ( "\n" );
  for ( test = 1; test <= 10; test++ )
  {
    x = r8_uniform_ab ( r8_lo, r8_hi, &seed );
    i = i4_uniform_ab ( 0, 6, &seed );
    ti = t_polynomial_value ( i, x );
    j = i4_uniform_ab ( -1, 4, &seed );
    tj = t_polynomial_value ( j, x );
    titj = tt_product ( i, j, x );
    printf ( "  %2d  %2d  %14.6g  %14.6g  %14.6g  %14.6g  %14.6g\n",
      i, j, x, ti, tj, ti * tj, titj );
  }

  return;
}
/******************************************************************************/

void tt_product_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    TT_PRODUCT_INTEGRAL_TEST tests TT_PRODUCT_INTEGRAL.

  Discussion:

    This process should match the T_MASS_MATRIX computation.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 July 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int i;
  int j;
  int n;

  printf ( "\n" );
  printf ( "TT_PRODUCT_INTEGRAL_TEST:\n" );
  printf ( "  TT_PRODUCT_INTEGRAL computes the product integral\n" );
  printf ( "  of a pair of Chebyshev T polynomials T(i,x) and T(j,x).\n" );
  printf ( "  A(I,J) = integral ( -1 <=x <= +1 ) T(i,x) T(j,x) / sqrt ( 1 - x^2 ) dx\n" );
  printf ( "  0    if i is not equal to j;\n" );
  printf ( "  pi   if i = j = 0;\n" );
  printf ( "  pi/2 if i = j =/= 0.\n" );

  n = 4;
  a = ( double * ) malloc ( ( n + 1 ) * ( n + 1 ) * sizeof ( double ) );
  for ( i = 0; i <= n; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      a[i+j*(n+1)] = tt_product_integral ( i, j );
    }
  }

  r8mat_print ( n + 1, n + 1, a, "  T(i,x)*T(j,x) integral matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void ttt_product_integral_test ( )

/****************************************************************************/
/*
  Purpose:

    TTT_PRODUCT_INTEGRAL_TEST tests TTT_PRODUCT_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 August 2013

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int i;
  int j;
  int k;
  int l;
  int n;
  int seed;
  int test;
  int test_num = 20;
  double ti;
  double tj;
  double tk;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "TTT_PRODUCT_INTEGRAL_TEST:\n" );
  printf ( "  TTT_PRODUCT_INTEGRAL computes the triple integral\n" );
  printf ( "  Tijk = integral ( -1 <= x <= 1 ) T(i,x) T(j,x) T(k,x) / sqrt ( 1-x^2) dx\n" );
  printf ( "\n" );
  printf ( "   I   J   K     Tijk           Tijk\n" );
  printf ( "                 computed       exact\n" );
  printf ( "\n" );

  n = 15;
  x = ( double * ) malloc ( n * sizeof ( double ) );
  w = ( double * ) malloc ( n * sizeof ( double ) );

  t_quadrature_rule ( n, x, w );

  seed = 123456789;

  for ( test = 1; test <= test_num; test++ )
  {
    i = i4_uniform_ab ( 2, 6, &seed );
    j = i4_uniform_ab ( 1, 3, &seed );
    k = i4_uniform_ab ( 0, 4, &seed );
    fx1 = ttt_product_integral ( i, j, k );
    fx2 = 0.0;
    for ( l = 0; l < n; l++ )
    {
      ti = t_polynomial_value ( i, x[l] );
      tj = t_polynomial_value ( j, x[l] );
      tk = t_polynomial_value ( k, x[l] );
      fx2 = fx2 + w[l] * ti * tj * tk;
    }
    printf ( "  %2d  %2d  %2d  %14g  %14g\n", i, j, k, fx1, fx2 );
  }

  free ( x );
  free ( w );

  return;
}
/******************************************************************************/

void tu_product_test ( )

/******************************************************************************/
/*
  Purpose:

    TU_PRODUCT_TEST tests TU_PRODUCT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 July 2015

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  double r8_hi;
  double r8_lo;
  int seed;
  int test;
  double ti;
  double tiuj;
  double uj;
  double x;

  printf ( "\n" );
  printf ( "TU_PRODUCT_TEST:\n" );
  printf ( "  TU_PRODUCT(I,J;X) = T(I,X) * U(J,X)\n" );

  r8_lo = -1.0;
  r8_hi = +1.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "   I   J      X               TI              UJ              TI*UJ       TU_PRODUCT\n" );
  printf ( "\n" );
  for ( test = 1; test <= 10; test++ )
  {
    x = r8_uniform_ab ( r8_lo, r8_hi, &seed );
    i = i4_uniform_ab ( 0, 6, &seed );
    ti = t_polynomial_value ( i, x );
    j = i4_uniform_ab ( -1, 4, &seed );
    uj = u_polynomial_value ( j, x );
    tiuj = tu_product ( i, j, x );
    printf ( "  %2d  %2d  %14.6g  %14.6g  %14.6g  %14.6g  %14.6g\n",
      i, j, x, ti, uj, ti * uj, tiuj );
  }

  return;
}
/******************************************************************************/

void u_mass_matrix_test ( )

/******************************************************************************/
/*
  Purpose:

    U_MASS_MATRIX_TEST tests U_MASS_MATRIX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 July 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int n;

  printf ( "\n" );
  printf ( "U_MASS_MATRIX_TEST:\n" );
  printf ( "  U_MASS_MATRIX computes the mass matrix for the\n" );
  printf ( "  Chebyshev polynomials U(i,x).\n" );
  printf ( "  A(I,J) = integral ( -1 <=x <= +1 ) U(i,x) U(j,x) * sqrt ( 1 - x^2 ) dx\n" );
  printf ( "  0    if i is not equal to j;\n" );
  printf ( "  pi/2 if i = j.\n" );

  n = 3;
  a = u_mass_matrix ( n );

  r8mat_print ( n + 1, n + 1, a, "  U mass matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void u_moment_test ( )

/******************************************************************************/
/*
  Purpose:

    U_MOMENT_TEST tests U_MOMENT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 July 2015

  Author:

    John Burkardt
*/
{
  int e;
  double value;

  printf ( "\n" );
  printf ( "U_MOMENT_TEST:\n" );
  printf ( "  U_MOMENT returns the value of\n" );
  printf ( "  integral ( -1 <=x <= +1 ) x^e * sqrt ( 1 - x^2 ) dx\n" );
  printf ( "\n" );
  printf ( "   E       Moment\n" );
  printf ( "\n" );
  for ( e = 0; e <= 10; e++ )
  {
    value = u_moment ( e );
    printf ( "  %2d  %14.6g\n", e, value );
  }

  return;
}
/******************************************************************************/

void u_polynomial_test ( )

/****************************************************************************/
/*
  Purpose:

    U_POLYNOMIAL_TEST tests U_POLYNOMIAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 July 2015

  Author:

    John Burkardt
*/
{
  double fx;
  double *fx2;
  int n;
  int n_data;
  double x;
  double x_vec[1];

  printf ( "\n" );
  printf ( "U_POLYNOMIAL_TEST:\n" );
  printf ( "  U_POLYNOMIAL evaluates the Chebyshev polynomial U(n,x).\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X        U(n,x)        U(n,x)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    u_polynomial_values ( &n_data, &n, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    if ( n < 0 )
    {
      continue;
    }

    x_vec[0] = x;
    fx2 = u_polynomial ( 1, n, x_vec );

    printf ( "  %8d  %14g  %14g  %14g\n", n, x, fx, fx2[n] );

    free ( fx2 );

  }

  return;
}
/******************************************************************************/

void u_polynomial_ab_test ( )

/****************************************************************************/
/*
  Purpose:

    U_POLYNOMIAL_AB_TEST tests U_POLYNOMIAL_AB.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int m;
  int n;
  double *v;
  double *x;

  m = 11;
  n = 5;

  printf ( "\n" );
  printf ( "U_POLYNOMIAL_AB_TEST:\n" );
  printf ( "  U_POLYNOMIAL_AB evaluates Chebyshev polynomials UAB(n,x)\n" );
  printf ( "  shifted from [-1,+1] to the domain [A,B].\n" );
  printf ( "\n" );
  printf ( "  Here, we will use the new domain [0,1]\n" );
  printf ( "  and the desired maximum polynomial degree will be N = 5.\n" );

  a = 0.0;
  b = 1.0;
  x = r8vec_linspace_new ( m, a, b );
  
  v = u_polynomial_ab ( a, b, m, n, x );

  r8mat_print ( m, n + 1, v, "  Tables of U values:" );

  free ( v );
  free ( x );

  return;
}
/******************************************************************************/

void u_polynomial_ab_value_test ( )

/****************************************************************************/
/*
  Purpose:

    U_POLYNOMIAL_AB_VALUE_TEST tests U_POLYNOMIAL_AB_VALUE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double fx;
  double fx2;
  int n;
  int n_data;
  double x01;

  printf ( "\n" );
  printf ( "U_POLYNOMIAL_AB_VALUE_TEST:\n" );
  printf ( "  U_POLYNOMIAL_AB_VALUE evaluates Chebyshev polynomials UAB(n,x)\n" );
  printf ( "  shifted from [-1,+1] to the domain [A,B].\n" );
  printf ( "\n" );
  printf ( "  Here, we will use the new domain [0,1].\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X01    U01(n,x)       U01(n,x)\n" );
  printf ( "\n" );

  a = 0.0;
  b = 1.0;

  n_data = 0;

  for ( ; ; )
  {
    u_polynomial_01_values ( &n_data, &n, &x01, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = u_polynomial_ab_value ( a, b, n, x01 );

    printf ( "  %8d  %14g  %14g  %14g\n", n, x01, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void u_polynomial_coefficients_test ( )

/****************************************************************************/
/*
  Purpose:

    U_POLYNOMIAL_COEFFICIENTS_TEST tests U_POLYNOMIAL_COEFFICIENTS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 July 2015

  Author:

    John Burkardt
*/
{
  double *c;
  double *c2;
  int i;
  int j;
  int n;

  printf ( "\n" );
  printf ( "U_POLYNOMIAL_COEFFICIENTS_TEST\n" );
  printf ( "  U_POLYNOMIAL_COEFFICIENTS determines the polynomial coefficients \n" );
  printf ( "  of U(n,x).\n" );

  n = 5;

  c = u_polynomial_coefficients ( n );

  for ( i = 0; i <= n; i++ )
  {
    c2 = ( double * ) malloc ( ( i + 1 ) * sizeof ( double ) );
    for ( j = 0; j <= i; j++ )
    {
      c2[j] = c[i+j*(n+1)];
    }
    r8poly_print ( i, c2, "" );
    free ( c2 );
  }
  free ( c );

  return;
}
/******************************************************************************/

void u_polynomial_plot_test ( )

/******************************************************************************/
/*
  Purpose:

    U_POLYNOMIAL_PLOT_TEST tests U_POLYNOMIAL_PLOT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 July 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n_num = 6;
  int n_val[6];
  char output_filename[255];

  printf ( "\n" );
  printf ( "U_POLYNOMIAL_PLOT_TEST\n" );
  printf ( "  U_POLYNOMIAL_PLOT plots selected\n" );
  printf ( "  Chebyshev polynomials U(n,x).\n" );

  for ( i = 0; i <= 5; i++ )
  {
    n_val[i] = i;
  }

  strcpy ( output_filename, "u_polynomial_plot.png" );

  u_polynomial_plot ( n_num, n_val, output_filename );

  return;
}
/******************************************************************************/

void u_polynomial_value_test ( )

/****************************************************************************/
/*
  Purpose:

    U_POLYNOMIAL_VALUE_TEST tests U_POLYNOMIAL_VALUE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 July 2015

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  int n;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "U_POLYNOMIAL_VALUE_TEST:\n" );
  printf ( "  U_POLYNOMIAL_VALUE evaluates the Chebyshev polynomial U(n,x).\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X        U(n,x)        U(n,x)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    u_polynomial_values ( &n_data, &n, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = u_polynomial_value ( n, x );

    printf ( "  %8d  %14g  %14g  %14g\n", n, x, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void u_polynomial_zeros_test ( )

/****************************************************************************/
/*
  Purpose:

    U_POLYNOMIAL_ZEROS_TEST tests U_POLYNOMIAL_ZEROS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 August 2013

  Author:

    John Burkardt
*/
{
  double *fx;
  int i;
  int n;
  int n_max = 5;
  double *z;

  printf ( "\n" );
  printf ( "U_POLYNOMIAL_ZEROS_TEST:\n" );
  printf ( "  U_POLYNOMIAL_ZEROS returns zeroes of U(n,x).\n" );
  printf ( "\n" );
  printf ( "       N      X        U(n,x)\n" );
  printf ( "\n" );

  for ( n = 1; n <= n_max; n++ )
  {
    z = u_polynomial_zeros ( n );
    fx = u_polynomial ( n, n, z );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %8d  %8g  %14g\n", n, z[i], fx[i+n*n] );
    }
    printf ( "\n" );
    free ( fx );
    free ( z );
  }

  return;
}
/******************************************************************************/

void u_quadrature_rule_test ( )

/****************************************************************************/
/*
  Purpose:

    U_QUADRATURE_RULE_TEST tests U_QUADRATURE_RULE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 August 2013

  Author:

    John Burkardt
*/
{
  int e;
  double *f;
  int i;
  int n;
  double q;
  double q_exact;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "U_QUADRATURE_RULE_TEST:\n" );
  printf ( "  U_QUADRATURE_RULE computes the quadrature rule\n" );
  printf ( "  associated with U(n,x);\n" );

  n = 7;
  x = ( double * ) malloc ( n * sizeof ( double ) );
  w = ( double * ) malloc ( n * sizeof ( double ) );

  u_quadrature_rule ( n, x, w );

  r8vec2_print ( n, x, w, "    N      X            W" );

  printf ( "\n" );
  printf ( "  Use the quadrature rule to estimate:\n" );
  printf ( "\n" );
  printf ( "    Q = Integral ( -1 <= X <= +1 ) X^E * sqrt ( 1-x^2) dx\n" );
  printf ( "\n" );
  printf ( "   E       Q_Estimate      Q_Exact\n" );
  printf ( "\n" );

  f = ( double * ) malloc ( n * sizeof ( double ) );

  for ( e = 0; e <= 2 * n - 1; e++ )
  {
    if ( e == 0 )
    {
      for ( i = 0; i < n; i++ )
      {
        f[i] = 1.0;
      }
    }
    else
    {
      for ( i = 0; i < n; i++ )
      {
        f[i] = pow ( x[i], e );
      }
    }
    q = r8vec_dot_product ( n, w, f );
    q_exact = u_moment ( e );
    printf ( " %2d  %14g  %14g\n", e, q, q_exact );
  }

  free ( f );
  free ( w );
  free ( x );

  return;
}
/******************************************************************************/

void uu_product_test ( )

/******************************************************************************/
/*
  Purpose:

    UU_PRODUCT_TEST tests UU_PRODUCT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 July 2015

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  double r8_hi;
  double r8_lo;
  int seed;
  int test;
  double ui;
  double uiuj;
  double uj;
  double x;

  printf ( "\n" );
  printf ( "UU_PRODUCT_TEST:\n" );
  printf ( "  UU_PRODUCT(I,J;X) = U(I,X) * U(J,X)\n" );

  r8_lo = -1.0;
  r8_hi = +1.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "   I   J      X               UI              UJ              UI*UJ       UU_PRODUCT\n" );
  printf ( "\n" );
  for ( test = 1; test <= 10; test++ )
  {
    x = r8_uniform_ab ( r8_lo, r8_hi, &seed );
    i = i4_uniform_ab ( 0, 6, &seed );
    ui = u_polynomial_value ( i, x );
    j = i4_uniform_ab ( -1, 4, &seed );
    uj = u_polynomial_value ( j, x );
    uiuj = uu_product ( i, j, x );
    printf ( "  %2d  %2d  %14.6g  %14.6g  %14.6g  %14.6g  %14.6g\n",
      i, j, x, ui, uj, ui * uj, uiuj );
  }

  return;
}
/******************************************************************************/

void uu_product_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    UU_PRODUCT_INTEGRAL_TEST tests UU_PRODUCT_INTEGRAL.

  Discussion:

    This process should match the U_MASS_MATRIX computation.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 July 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int i;
  int j;
  int n;

  printf ( "\n" );
  printf ( "UU_PRODUCT_INTEGRAL_TEST:\n" );
  printf ( "  UU_PRODUCT_INTEGRAL computes the product integral\n" );
  printf ( "  of a pair of Chebyshev U polynomials U(i,x) and U(j,x).\n" );
  printf ( "  A(I,J) = integral ( -1 <=x <= +1 ) U(i,x) U(j,x) * sqrt ( 1 - x^2 ) dx\n" );
  printf ( "  0    if i is not equal to j;\n" );
  printf ( "  pi/2 if i = j.\n" );

  n = 4;
  a = ( double * ) malloc ( ( n + 1 ) * ( n + 1 ) * sizeof ( double ) );
  for ( i = 0; i <= n; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      a[i+j*(n+1)] = uu_product_integral ( i, j );
    }
  }

  r8mat_print ( n + 1, n + 1, a, "  U(i,x)*U(j,x) integral matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void v_mass_matrix_test ( )

/******************************************************************************/
/*
  Purpose:

    V_MASS_MATRIX_TEST tests V_MASS_MATRIX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int n;

  printf ( "\n" );
  printf ( "V_MASS_MATRIX_TEST:\n" );
  printf ( "  V_MASS_MATRIX computes the mass matrix for the\n" );
  printf ( "  Chebyshev polynomials V(i,x).\n" );
  printf ( "  A(I,J) = integral ( -1 <=x <= +1 ) V(i,x) V(j,x) sqrt(1+x)/sqrt(1-x) dx\n" );
  printf ( "  0  if i is not equal to j;\n" );
  printf ( "  pi if i = j.\n" );

  n = 3;
  a = v_mass_matrix ( n );

  r8mat_print ( n + 1, n + 1, a, "  V mass matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void v_moment_test ( )

/******************************************************************************/
/*
  Purpose:

    V_MOMENT_TEST tests V_MOMENT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 July 2015

  Author:

    John Burkardt
*/
{
  int e;
  double value;

  printf ( "\n" );
  printf ( "V_MOMENT_TEST:\n" );
  printf ( "  V_MOMENT returns the value of\n" );
  printf ( "  integral ( -1 <=x <= +1 ) x^e * sqrt(1+x) / sqrt(1-x) dx\n" );
  printf ( "\n" );
  printf ( "   E       Moment\n" );
  printf ( "\n" );
  for ( e = 0; e <= 10; e++ )
  {
    value = v_moment ( e );
    printf ( "  %2d  %14.6g\n", e, value );
  }

  return;
}
/******************************************************************************/

void v_polynomial_test ( )

/****************************************************************************/
/*
  Purpose:

    V_POLYNOMIAL_TEST tests V_POLYNOMIAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 August 2013

  Author:

    John Burkardt
*/
{
  double fx;
  double *fx2;
  int n;
  int n_data;
  double x;
  double x_vec[1];

  printf ( "\n" );
  printf ( "V_POLYNOMIAL_TEST:\n" );
  printf ( "  V_POLYNOMIAL evaluates the Chebyshev polynomial V(n,x).\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X        V(n,x)        V(n,x)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    v_polynomial_values ( &n_data, &n, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    if ( n < 0 )
    {
      continue;
    }

    x_vec[0] = x;
    fx2 = v_polynomial ( 1, n, x_vec );

    printf ( "  %8d  %8g  %14g  %14g\n", n, x, fx, fx2[n] );

    free ( fx2 );
  }

  return;
}
/******************************************************************************/

void v_polynomial_ab_test ( )

/****************************************************************************/
/*
  Purpose:

    V_POLYNOMIAL_AB_TEST tests V_POLYNOMIAL_AB.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int m;
  int n;
  double *v;
  double *x;

  m = 11;
  n = 5;

  printf ( "\n" );
  printf ( "V_POLYNOMIAL_AB_TEST:\n" );
  printf ( "  V_POLYNOMIAL_AB evaluates Chebyshev polynomials VAB(n,x)\n" );
  printf ( "  shifted from [-1,+1] to the domain [A,B].\n" );
  printf ( "\n" );
  printf ( "  Here, we will use the new domain [0,1]\n" );
  printf ( "  and the desired maximum polynomial degree will be N = 5.\n" );

  a = 0.0;
  b = 1.0;
  x = r8vec_linspace_new ( m, a, b );
  
  v = v_polynomial_ab ( a, b, m, n, x );

  r8mat_print ( m, n + 1, v, "  Tables of V values:" );

  free ( v );
  free ( x );

  return;
}
/******************************************************************************/

void v_polynomial_ab_value_test ( )

/****************************************************************************/
/*
  Purpose:

    V_POLYNOMIAL_AB_VALUE_TEST tests V_POLYNOMIAL_AB_VALUE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double fx;
  double fx2;
  int n;
  int n_data;
  double x01;

  printf ( "\n" );
  printf ( "V_POLYNOMIAL_AB_VALUE_TEST:\n" );
  printf ( "  V_POLYNOMIAL_AB_VALUE evaluates Chebyshev polynomials VAB(n,x)\n" );
  printf ( "  shifted from [-1,+1] to the domain [A,B].\n" );
  printf ( "\n" );
  printf ( "  Here, we will use the new domain [0,1].\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X01    V01(n,x)       V01(n,x)\n" );
  printf ( "\n" );

  a = 0.0;
  b = 1.0;

  n_data = 0;

  for ( ; ; )
  {
    v_polynomial_01_values ( &n_data, &n, &x01, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = v_polynomial_ab_value ( a, b, n, x01 );

    printf ( "  %8d  %14g  %14g  %14g\n", n, x01, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void v_polynomial_coefficients_test ( )

/****************************************************************************/
/*
  Purpose:

    V_POLYNOMIAL_COEFFICIENTS_TEST tests V_POLYNOMIAL_COEFFICIENTS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 July 2015

  Author:

    John Burkardt
*/
{
  double *c;
  double *c2;
  int i;
  int j;
  int n;

  printf ( "\n" );
  printf ( "V_POLYNOMIAL_COEFFICIENTS_TEST\n" );
  printf ( "  V_POLYNOMIAL_COEFFICIENTS determines the polynomial coefficients \n" );
  printf ( "  of V(n,x).\n" );

  n = 5;

  c = v_polynomial_coefficients ( n );

  for ( i = 0; i <= n; i++ )
  {
    c2 = ( double * ) malloc ( ( i + 1 ) * sizeof ( double ) );
    for ( j = 0; j <= i; j++ )
    {
      c2[j] = c[i+j*(n+1)];
    }
    r8poly_print ( i, c2, "" );
    free ( c2 );
  }
  free ( c );

  return;
}
/******************************************************************************/

void v_polynomial_plot_test ( )

/******************************************************************************/
/*
  Purpose:

    V_POLYNOMIAL_PLOT_TEST tests V_POLYNOMIAL_PLOT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 July 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n_num = 6;
  int n_val[6];
  char output_filename[255];

  printf ( "\n" );
  printf ( "V_POLYNOMIAL_PLOT_TEST\n" );
  printf ( "  V_POLYNOMIAL_PLOT plots selected\n" );
  printf ( "  Chebyshev polynomials V(n,x).\n" );

  for ( i = 0; i <= 5; i++ )
  {
    n_val[i] = i;
  }

  strcpy ( output_filename, "v_polynomial_plot.png" );

  v_polynomial_plot ( n_num, n_val, output_filename );

  return;
}
/******************************************************************************/

void v_polynomial_value_test ( )

/****************************************************************************/
/*
  Purpose:

    V_POLYNOMIAL_VALUE_TEST tests V_POLYNOMIAL_VALUE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 July 2015

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  int n;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "V_POLYNOMIAL_VALUE_TEST:\n" );
  printf ( "  V_POLYNOMIAL_VALUE evaluates the Chebyshev polynomial V(n,x).\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X        V(n,x)        V(n,x)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    v_polynomial_values ( &n_data, &n, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = v_polynomial_value ( n, x );

    printf ( "  %8d  %14g  %14g  %14g\n", n, x, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void v_polynomial_zeros_test ( )

/****************************************************************************/
/*
  Purpose:

    V_POLYNOMIAL_ZEROS_TEST tests V_POLYNOMIAL_ZEROS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 July 2015

  Author:

    John Burkardt
*/
{
  double *fx;
  int i;
  int n;
  int n_max = 5;
  double *z;

  printf ( "\n" );
  printf ( "V_POLYNOMIAL_ZEROS_TEST:\n" );
  printf ( "  V_POLYNOMIAL_ZEROS returns zeroes of V(n,x).\n" );
  printf ( "\n" );
  printf ( "       N      X        V(n,x)\n" );
  printf ( "\n" );

  for ( n = 1; n <= n_max; n++ )
  {
    z = v_polynomial_zeros ( n );
    fx = v_polynomial ( n, n, z );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %8d  %8g  %14g\n", n, z[i], fx[i+n*n] );
    }
    printf ( "\n" );
    free ( fx );
    free ( z );
  }

  return;
}
/******************************************************************************/

void v_quadrature_rule_test ( )

/****************************************************************************/
/*
  Purpose:

    V_QUADRATURE_RULE_TEST tests V_QUADRATURE_RULE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  int e;
  double *f;
  int i;
  int n;
  double q;
  double q_exact;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "V_QUADRATURE_RULE_TEST:\n" );
  printf ( "  V_QUADRATURE_RULE computes the quadrature rule\n" );
  printf ( "  associated with V(n,x);\n" );

  n = 7;
  x = ( double * ) malloc ( n * sizeof ( double ) );
  w = ( double * ) malloc ( n * sizeof ( double ) );

  v_quadrature_rule ( n, x, w );

  r8vec2_print ( n, x, w, "    N      X            W" );

  printf ( "\n" );
  printf ( "  Use the quadrature rule to estimate:\n" );
  printf ( "\n" );
  printf ( "    Q = Integral ( -1 <= X <= +1 ) X^E * sqrt(1+x)/sqrt(1-x) dx\n" );
  printf ( "\n" );
  printf ( "   E       Q_Estimate      Q_Exact\n" );
  printf ( "\n" );

  f = ( double * ) malloc ( n * sizeof ( double ) );

  for ( e = 0; e <= 2 * n - 1; e++ )
  {
    if ( e == 0 )
    {
      for ( i = 0; i < n; i++ )
      {
        f[i] = 1.0;
      }
    }
    else
    {
      for ( i = 0; i < n; i++ )
      {
        f[i] = pow ( x[i], e );
      }
    }
    q = r8vec_dot_product ( n, w, f );
    q_exact = v_moment ( e );
    printf ( " %2d  %14g  %14g\n", e, q, q_exact );
  }

  free ( f );
  free ( w );
  free ( x );

  return;
}
/******************************************************************************/

void vv_product_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    VV_PRODUCT_INTEGRAL_TEST tests VV_PRODUCT_INTEGRAL.

  Discussion:

    This process should match the V_MASS_MATRIX computation.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 July 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int i;
  int j;
  int n;

  printf ( "\n" );
  printf ( "VV_PRODUCT_INTEGRAL_TEST:\n" );
  printf ( "  VV_PRODUCT_INTEGRAL computes the product integral\n" );
  printf ( "  of a pair of Chebyshev V polynomials V(i,x) and V(j,x).\n" );
  printf ( "  A(I,J) = integral ( -1 <=x <= +1 ) V(i,x) V(j,x) * sqrt( 1 + x ) / sqrt ( 1 - x ) dx\n" );
  printf ( "  0  if i is not equal to j;\n" );
  printf ( "  pi if i = j.\n" );

  n = 4;
  a = ( double * ) malloc ( ( n + 1 ) * ( n + 1 ) * sizeof ( double ) );
  for ( i = 0; i <= n; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      a[i+j*(n+1)] = vv_product_integral ( i, j );
    }
  }

  r8mat_print ( n + 1, n + 1, a, "  V(i,x)*V(j,x) integral matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void w_mass_matrix_test ( )

/******************************************************************************/
/*
  Purpose:

    W_MASS_MATRIX_TEST tests W_MASS_MATRIX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int n;

  printf ( "\n" );
  printf ( "W_MASS_MATRIX_TEST:\n" );
  printf ( "  W_MASS_MATRIX computes the mass matrix for the\n" );
  printf ( "  Chebyshev polynomials W(i,x).\n" );
  printf ( "  A(I,J) = integral ( -1 <=x <= +1 ) W(i,x) W(j,x) sqrt(1-x)/sqrt(1+x) dx\n" );
  printf ( "  0  if i is not equal to j;\n" );
  printf ( "  pi if i = j.\n" );

  n = 3;
  a = w_mass_matrix ( n );

  r8mat_print ( n + 1, n + 1, a, "  W mass matrix:" );

  free ( a );

  return;
}
/******************************************************************************/

void w_moment_test ( )

/******************************************************************************/
/*
  Purpose:

    W_MOMENT_TEST tests W_MOMENT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 July 2015

  Author:

    John Burkardt
*/
{
  int e;
  double value;

  printf ( "\n" );
  printf ( "W_MOMENT_TEST:\n" );
  printf ( "  W_MOMENT returns the value of\n" );
  printf ( "  integral ( -1 <=x <= +1 ) x^e * sqrt(1-x) / sqrt(1+x) dx\n" );
  printf ( "\n" );
  printf ( "   E       Moment\n" );
  printf ( "\n" );
  for ( e = 0; e <= 10; e++ )
  {
    value = w_moment ( e );
    printf ( "  %2d  %14.6g\n", e, value );
  }

  return;
}
/******************************************************************************/

void w_polynomial_test ( )

/****************************************************************************/
/*
  Purpose:

    W_POLYNOMIAL_TEST tests W_POLYNOMIAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 July 2015

  Author:

    John Burkardt
*/
{
  double fx;
  double *fx2;
  int n;
  int n_data;
  double x;
  double x_vec[1];

  printf ( "\n" );
  printf ( "W_POLYNOMIAL_TEST:\n" );
  printf ( "  W_POLYNOMIAL evaluates the Chebyshev polynomial W(n,x).\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X        W(n,x)        W(n,x)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    w_polynomial_values ( &n_data, &n, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    if ( n < 0 )
    {
      continue;
    }

    x_vec[0] = x;
    fx2 = w_polynomial ( 1, n, x_vec );

    printf ( "  %8d  %8g  %14g  %14g\n", n, x, fx, fx2[n] );

    free ( fx2 );

  }

  return;
}
/******************************************************************************/

void w_polynomial_ab_test ( )

/****************************************************************************/
/*
  Purpose:

    W_POLYNOMIAL_AB_TEST tests W_POLYNOMIAL_AB.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int m;
  int n;
  double *v;
  double *x;

  m = 11;
  n = 5;

  printf ( "\n" );
  printf ( "W_POLYNOMIAL_AB_TEST:\n" );
  printf ( "  W_POLYNOMIAL_AB evaluates Chebyshev polynomials WAB(n,x)\n" );
  printf ( "  shifted from [-1,+1] to the domain [A,B].\n" );
  printf ( "\n" );
  printf ( "  Here, we will use the new domain [0,1]\n" );
  printf ( "  and the desired maximum polynomial degree will be N = 5.\n" );

  a = 0.0;
  b = 1.0;
  x = r8vec_linspace_new ( m, a, b );
  
  v = w_polynomial_ab ( a, b, m, n, x );

  r8mat_print ( m, n + 1, v, "  Tables of W values:" );

  free ( v );
  free ( x );

  return;
}
/******************************************************************************/

void w_polynomial_ab_value_test ( )

/****************************************************************************/
/*
  Purpose:

    W_POLYNOMIAL_AB_VALUE_TEST tests W_POLYNOMIAL_AB_VALUE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double fx;
  double fx2;
  int n;
  int n_data;
  double x01;

  printf ( "\n" );
  printf ( "W_POLYNOMIAL_AB_VALUE_TEST:\n" );
  printf ( "  W_POLYNOMIAL_AB_VALUE evaluates Chebyshev polynomials WAB(n,x)\n" );
  printf ( "  shifted from [-1,+1] to the domain [A,B].\n" );
  printf ( "\n" );
  printf ( "  Here, we will use the new domain [0,1].\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X01    W01(n,x)       W01(n,x)\n" );
  printf ( "\n" );

  a = 0.0;
  b = 1.0;

  n_data = 0;

  for ( ; ; )
  {
    w_polynomial_01_values ( &n_data, &n, &x01, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = w_polynomial_ab_value ( a, b, n, x01 );

    printf ( "  %8d  %14g  %14g  %14g\n", n, x01, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void w_polynomial_coefficients_test ( )

/****************************************************************************/
/*
  Purpose:

    W_POLYNOMIAL_COEFFICIENTS_TEST tests W_POLYNOMIAL_COEFFICIENTS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 July 2015

  Author:

    John Burkardt
*/
{
  double *c;
  double *c2;
  int i;
  int j;
  int n;

  printf ( "\n" );
  printf ( "W_POLYNOMIAL_COEFFICIENTS_TEST\n" );
  printf ( "  W_POLYNOMIAL_COEFFICIENTS determines the polynomial coefficients \n" );
  printf ( "  of W(n,x).\n" );

  n = 5;

  c = w_polynomial_coefficients ( n );

  for ( i = 0; i <= n; i++ )
  {
    c2 = ( double * ) malloc ( ( i + 1 ) * sizeof ( double ) );
    for ( j = 0; j <= i; j++ )
    {
      c2[j] = c[i+j*(n+1)];
    }
    r8poly_print ( i, c2, "" );
    free ( c2 );
  }
  free ( c );

  return;
}
/******************************************************************************/

void w_polynomial_plot_test ( )

/******************************************************************************/
/*
  Purpose:

    W_POLYNOMIAL_PLOT_TEST tests W_POLYNOMIAL_PLOT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 July 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n_num = 6;
  int n_val[6];
  char output_filename[255];

  printf ( "\n" );
  printf ( "W_POLYNOMIAL_PLOT_TEST\n" );
  printf ( "  W_POLYNOMIAL_PLOT plots selected\n" );
  printf ( "  Chebyshev polynomials W(n,x).\n" );

  for ( i = 0; i <= 5; i++ )
  {
    n_val[i] = i;
  }

  strcpy ( output_filename, "w_polynomial_plot.png" );

  w_polynomial_plot ( n_num, n_val, output_filename );

  return;
}
/******************************************************************************/

void w_polynomial_value_test ( )

/****************************************************************************/
/*
  Purpose:

    W_POLYNOMIAL_VALUE_TEST tests W_POLYNOMIAL_VALUE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 July 2015

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  int n;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "W_POLYNOMIAL_VALUE_TEST:\n" );
  printf ( "  W_POLYNOMIAL_VALUE evaluates the Chebyshev polynomial U(n,x).\n" );
  printf ( "\n" );
  printf ( "                   Tabulated      Computed\n" );
  printf ( "     N      X        W(n,x)        W(n,x)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    w_polynomial_values ( &n_data, &n, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = w_polynomial_value ( n, x );

    printf ( "  %8d  %14g  %14g  %14g\n", n, x, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void w_polynomial_zeros_test ( )

/****************************************************************************/
/*
  Purpose:

    W_POLYNOMIAL_ZEROS_TEST tests W_POLYNOMIAL_ZEROS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 July 2015

  Author:

    John Burkardt
*/
{
  double *fx;
  int i;
  int n;
  int n_max = 5;
  double *z;

  printf ( "\n" );
  printf ( "W_POLYNOMIAL_ZEROS_TEST:\n" );
  printf ( "  W_POLYNOMIAL_ZEROS returns zeroes of W(n,x).\n" );
  printf ( "\n" );
  printf ( "       N      X        W(n,x)\n" );
  printf ( "\n" );

  for ( n = 1; n <= n_max; n++ )
  {
    z = w_polynomial_zeros ( n );
    fx = w_polynomial ( n, n, z );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %8d  %8g  %14g\n", n, z[i], fx[i+n*n] );
    }
    printf ( "\n" );
    free ( fx );
    free ( z );
  }

  return;
}
/******************************************************************************/

void w_quadrature_rule_test ( )

/****************************************************************************/
/*
  Purpose:

    W_QUADRATURE_RULE_TEST tests W_QUADRATURE_RULE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 July 2015

  Author:

    John Burkardt
*/
{
  int e;
  double *f;
  int i;
  int n;
  double q;
  double q_exact;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "W_QUADRATURE_RULE_TEST:\n" );
  printf ( "  W_QUADRATURE_RULE computes the quadrature rule\n" );
  printf ( "  associated with W(n,x);\n" );

  n = 7;
  x = ( double * ) malloc ( n * sizeof ( double ) );
  w = ( double * ) malloc ( n * sizeof ( double ) );

  w_quadrature_rule ( n, x, w );

  r8vec2_print ( n, x, w, "    N      X            W" );

  printf ( "\n" );
  printf ( "  Use the quadrature rule to estimate:\n" );
  printf ( "\n" );
  printf ( "    Q = Integral ( -1 <= X <= +1 ) X^E * sqrt(1-x)/sqrt(1+x) dx\n" );
  printf ( "\n" );
  printf ( "   E       Q_Estimate      Q_Exact\n" );
  printf ( "\n" );

  f = ( double * ) malloc ( n * sizeof ( double ) );

  for ( e = 0; e <= 2 * n - 1; e++ )
  {
    if ( e == 0 )
    {
      for ( i = 0; i < n; i++ )
      {
        f[i] = 1.0;
      }
    }
    else
    {
      for ( i = 0; i < n; i++ )
      {
        f[i] = pow ( x[i], e );
      }
    }
    q = r8vec_dot_product ( n, w, f );
    q_exact = w_moment ( e );
    printf ( " %2d  %14g  %14g\n", e, q, q_exact );
  }

  free ( f );
  free ( w );
  free ( x );

  return;
}
/******************************************************************************/

void ww_product_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    WW_PRODUCT_INTEGRAL_TEST tests WW_PRODUCT_INTEGRAL.

  Discussion:

    This process should match the W_MASS_MATRIX computation.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 July 2015

  Author:

    John Burkardt
*/
{
  double *a;
  int i;
  int j;
  int n;

  printf ( "\n" );
  printf ( "WW_PRODUCT_INTEGRAL_TEST:\n" );
  printf ( "  WW_PRODUCT_INTEGRAL computes the product integral\n" );
  printf ( "  of a pair of Chebyshev W polynomials W(i,x) and W(j,x).\n" );
  printf ( "  A(I,J) = integral ( -1 <=x <= +1 ) W(i,x) W(j,x) * sqrt( 1 - x ) / sqrt ( 1 + x ) dx\n" );
  printf ( "  0  if i is not equal to j;\n" );
  printf ( "  pi if i = j.\n" );

  n = 4;
  a = ( double * ) malloc ( ( n + 1 ) * ( n + 1 ) * sizeof ( double ) );
  for ( i = 0; i <= n; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      a[i+j*(n+1)] = ww_product_integral ( i, j );
    }
  }

  r8mat_print ( n + 1, n + 1, a, "  W(i,x)*W(j,x) integral matrix:" );

  free ( a );

  return;
}
