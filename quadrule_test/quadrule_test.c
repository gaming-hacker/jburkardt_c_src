# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "quadrule.h"

int main ( );
void chebyshev_set_test ( );
void chebyshev1_compute_test ( );
void chebyshev1_integral_test ( );
void chebyshev1_set_test ( );
void chebyshev2_compute_test ( );
void chebyshev2_compute_test2 ( );
void chebyshev2_integral_test ( );
void chebyshev2_set_test ( );
void chebyshev3_compute_test ( );
void chebyshev3_integral_test ( );
void chebyshev3_set_test ( );
void clenshaw_curtis_compute_test ( );
void clenshaw_curtis_set_test ( );
void fejer1_compute_test ( );
void fejer1_set_test ( );
void fejer2_compute_test ( );
void fejer2_set_test ( );
void gegenbauer_integral_test ( );
void gegenbauer_ek_compute_test ( );
void gegenbauer_ss_compute_test ( );
void gen_hermite_ek_compute_test ( );
void gen_hermite_integral_test ( );
void gen_laguerre_ek_compute_test ( );
void gen_laguerre_integral_test ( );
void gen_laguerre_ss_compute_test ( );
void hermite_ek_compute_test ( );
void hermite_integral_test ( );
void hermite_set_test ( );
void hermite_ss_compute_test ( );
void hermite_gk16_set_test ( );
void hermite_gk18_set_test ( );
void hermite_gk22_set_test ( );
void hermite_gk24_set_test ( );
void hermite_1_set_test ( );
void hermite_probabilist_set_test ( );
void imtqlx_test ( );
void jacobi_ek_compute_test ( );
void jacobi_integral_test ( );
void jacobi_ss_compute_test ( );
void kronrod_set_test ( );
void laguerre_ek_compute_test ( );
void laguerre_integral_test ( );
void laguerre_set_test ( );
void laguerre_ss_compute_test ( );
void laguerre_1_set_test ( );
void legendre_dr_compute_test ( );
void legendre_ek_compute_test ( );
void legendre_integral_test ( );
void legendre_set_test ( );
void lobatto_compute_test ( );
void lobatto_set_test ( );
void nc_compute_weights_test ( );
void ncc_compute_test ( );
void ncc_set_test ( );
void nco_compute_test ( );
void nco_set_test ( );
void ncoh_compute_test ( );
void ncoh_set_test ( );
void patterson_set_test ( );
void r8_psi_test ( );
void radau_compute_test ( );
void radau_set_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for QUADRULE_TEST.

  Discussion:

    QUADRULE_TEST tests the QUADRULE library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    21 June 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "QUADRULE_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the QUADRULE library.\n" );

  chebyshev_set_test ( );
  chebyshev1_compute_test ( );
  chebyshev1_integral_test ( );
  chebyshev1_set_test ( );
  chebyshev2_compute_test ( );
  chebyshev2_compute_test2 ( );
  chebyshev2_integral_test ( );
  chebyshev2_set_test ( );
  chebyshev3_compute_test ( );
  chebyshev3_integral_test ( );
  chebyshev3_set_test ( );
  clenshaw_curtis_compute_test ( );
  clenshaw_curtis_set_test ( );
  fejer1_compute_test ( );
  fejer1_set_test ( );
  fejer2_compute_test ( );
  fejer2_set_test ( );
  gegenbauer_integral_test ( );
  gegenbauer_ek_compute_test ( );
  gegenbauer_ss_compute_test ( );
  gen_hermite_ek_compute_test ( );
  gen_hermite_integral_test ( );
  gen_laguerre_ek_compute_test ( );
  gen_laguerre_integral_test ( );
  gen_laguerre_ss_compute_test ( );
  hermite_ek_compute_test ( );
  hermite_integral_test ( );
  hermite_set_test ( );
  hermite_ss_compute_test ( );
  hermite_gk16_set_test ( );
  hermite_gk18_set_test ( );
  hermite_gk22_set_test ( );
  hermite_gk24_set_test ( );
  hermite_1_set_test ( );
  hermite_probabilist_set_test ( );
  imtqlx_test ( );
  jacobi_ek_compute_test ( );
  jacobi_integral_test ( );
  jacobi_ss_compute_test ( );
  kronrod_set_test ( );
  laguerre_ek_compute_test ( );
  laguerre_integral_test ( );
  laguerre_set_test ( );
  laguerre_ss_compute_test ( );
  laguerre_1_set_test ( );
  legendre_dr_compute_test ( );
  legendre_ek_compute_test ( );
  legendre_integral_test ( );
  legendre_set_test ( );
  lobatto_compute_test ( );
  lobatto_set_test ( );
  nc_compute_weights_test ( );
  ncc_compute_test ( );
  ncc_set_test ( );
  nco_compute_test ( );
  nco_set_test ( );
  ncoh_compute_test ( );
  ncoh_set_test ( );
  patterson_set_test ( );
  r8_psi_test ( );
  radau_compute_test ( );
  radau_set_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "QUADRULE_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );
 
  return 0;
}
/******************************************************************************/

void chebyshev_set_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV_SET_TEST tests CHEBYSHEV_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "CHEBYSHEV_SET_TEST\n" );
  printf ( "  CHEBYSHEV_SET sets\n" );
  printf ( "  a Chebyshev quadrature rule over [-1,1].\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 9; n++ )
  {
    if ( n == 8 )
    {
      continue;
    }
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    chebyshev_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }

 
  return;
}
/******************************************************************************/

void chebyshev1_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV1_COMPUTE_TEST tests CHEBYSHEV1_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 April 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "CHEBYSHEV1_COMPUTE_TEST\n" );
  printf ( "  CHEBYSHEV1_COMPUTE computes\n" );
  printf ( "  a Chebyshev Type 1 quadrature rule over [-1,1].\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    chebyshev1_compute ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void chebyshev1_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV1_INTEGRAL_TEST tests CHEBYSHEV1_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int n;
  double value;

  printf ( "\n" );
  printf ( "CHEBYSHEV1_INTEGRAL_TEST\n" );
  printf ( "  CHEBYSHEV1_INTEGRAL evaluates\n" );
  printf ( "  Integral ( -1 < x < +1 ) x^n / sqrt(1-x*x) dx\n" );
  printf ( "\n" );
  printf ( "         N         Value\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    value = chebyshev1_integral ( n );

    printf ( "  %8d  %24.16g\n", n, value );
  }
 
  return;
}
/******************************************************************************/

void chebyshev1_set_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV1_SET_TEST tests CHEBYSHEV1_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "CHEBYSHEV1_SET_TEST\n" );
  printf ( "  CHEBYSHEV1_SET sets\n" );
  printf ( "  a Chebyshev Type 1 quadrature rule over [-1,1].\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    chebyshev1_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void chebyshev2_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV2_COMPUTE_TEST tests CHEBYSHEV2_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    07 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "CHEBYSHEV2_COMPUTE_TEST\n" );
  printf ( "  CHEBYSHEV2_COMPUTE computes\n" );
  printf ( "  a Chebyshev Type 2 quadrature rule over [-1,1].\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    chebyshev2_compute ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void chebyshev2_compute_test2 ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV2_COMPUTE_TEST2 uses CHEBYSHEV2_COMPUTE over the semicircle.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 June 2015

  Author:

    John Burkardt
*/
{
  double error;
  double exact;
  double *f;
  int i;
  int n = 10;
  double q;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "CHEBYSHEV2_COMPUTE_TEST2\n" );
  printf ( "  Approximate the integral of f(x,y) over the semicircle\n" );
  printf ( "    -1 <= x <= 1, y = sqrt ( 1 - x^2 )\n" );
  printf ( "  using N Chebyshev points.\n" );
  printf ( "  If p(x,y) involves any term of odd degree in y,\n" );
  printf ( "  the estimate will only be approximate.\n" );
  printf ( "\n" );
  printf ( "  Polynomial    N    Integral        Estimate       Error\n" );
  printf ( "\n" );

  f = ( double * ) malloc ( n * sizeof ( double ) );
  x = ( double * ) malloc ( n * sizeof ( double ) );
  w = ( double * ) malloc ( n * sizeof ( double ) );

  chebyshev2_compute ( n, x, w );
/*
  f(x,y) = 1
*/
  exact = 1.5707963267948966192;
  for ( i = 0; i < n; i++ )
  {
    f[i] = 1.0;
  }
  q = r8vec_dot_product ( n, w, f );
  error = fabs ( q - exact );
  printf ( "  1              %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = x
*/
  exact = 0.0;
  for ( i = 0; i < n; i++ )
  {
    f[i] = x[i];
  }
  q = r8vec_dot_product ( n, w, f );
  error = fabs ( q - exact );
  printf ( "  x              %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = y = sqrt ( 1 - x^2 )
*/
  exact = 0.66666666666666666667;
  for ( i = 0; i < n; i++ )
  {
    f[i] = sqrt ( 1.0 - pow ( x[i], 2 ) );
  }
  q = r8vec_dot_product ( n, w, f ) / 2.0;
  error = fabs ( q - exact );
  printf ( "     y           %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = x^2
*/
  exact = 0.39269908169872415481;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( x[i], 2 );
  }
  q = r8vec_dot_product ( n, w, f );
  error = fabs ( q - exact );
  printf ( "  x^2            %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = xy = x * sqrt ( 1 - x^2 )
*/
  exact = 0.0;
  for ( i = 0; i < n; i++ )
  {
    f[i] = x[i] * sqrt ( 1.0 - pow ( x[i], 2 ) );
  }
  q = r8vec_dot_product ( n, w, f ) / 2.0;
  error = fabs ( q - exact );
  printf ( "  x  y           %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = y^2 -> ( 1 - x^2 )
*/
  exact = 0.39269908169872415481;
  for ( i = 0; i < n; i++ )
  {
    f[i] = 1.0 - pow ( x[i], 2 );
  }
  q = r8vec_dot_product ( n, w, f ) / 3.0;
  error = fabs ( q - exact );
  printf ( "     y^2         %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = x^3
*/
  exact = 0.0;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( x[i], 3 );
  }
  q = r8vec_dot_product ( n, w, f );
  error = fabs ( q - exact );
  printf ( "  x^3            %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = x^2 y = x^2 sqrt ( 1 - x^2 )
*/
  exact = 0.13333333333333333333;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( x[i], 2 ) * sqrt ( 1.0 - pow ( x[i], 2 ) );
  }
  q = r8vec_dot_product ( n, w, f ) / 2.0;
  error = fabs ( q - exact );
  printf ( "  x^2y           %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = x y^2 = x * ( 1 - x^2 )
*/
  exact = 0.0;
  for ( i = 0; i < n; i++ )
  {
    f[i] = x[i] * ( 1.0 - pow ( x[i], 2 ) );
  }
  q = r8vec_dot_product ( n, w, f ) / 3.0;
  error = fabs ( q - exact );
  printf ( "  x  y^2         %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = y^3
*/
  exact = 0.26666666666666666667;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( 1.0 - pow ( x[i], 2 ), 1.5 );
  }
  q = r8vec_dot_product ( n, w, f ) / 4.0;
  error = fabs ( q - exact );
  printf ( "     y^3         %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = x^4
*/
  exact = 0.19634954084936207740;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( x[i], 4 );
  }
  q = r8vec_dot_product ( n, w, f );
  error = fabs ( q - exact );
  printf ( "  x^4            %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = x^2y^2 -> x^2( 1 - x^2 )
*/
  exact = 0.065449846949787359135;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( x[i], 2 ) * ( 1.0 - pow ( x[i], 2 ) );
  }
  q = r8vec_dot_product ( n, w, f ) / 3.0;
  error = fabs ( q - exact );
  printf ( "  x^2y^2         %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = y^4 -> ( 1 - x^2 )^2
*/
  exact = 0.19634954084936207740;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( 1.0 - pow ( x[i], 2 ), 2 );
  }
  q = r8vec_dot_product ( n, w, f ) / 5.0;
  error = fabs ( q - exact );
  printf ( "     y^4         %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = x^4y = x^4 sqrt ( 1 - x^2 )
*/
  exact = 0.057142857142857142857;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( x[i], 4 ) * sqrt ( 1.0 - pow ( x[i], 2 ) );
  }
  q = r8vec_dot_product ( n, w, f ) / 2.0;
  error = fabs ( q - exact );
  printf ( "  x^4y           %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  x^2y^3 = x^2 ( 1 - x^2 )^(3/2)
*/
  exact = 0.038095238095238095238;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( x[i], 2 ) * pow ( 1.0 - pow ( x[i], 2 ), 1.5 );
  }
  q = r8vec_dot_product ( n, w, f ) / 4.0;
  error = fabs ( q - exact );
  printf ( "  x^2y^3         %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = y^5
*/
  exact = 0.15238095238095238095;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( 1.0 - pow ( x[i], 2 ), 2.5 );
  }
  q = r8vec_dot_product ( n, w, f ) / 6.0;
  error = fabs ( q - exact );
  printf ( "     y^5         %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = x^6
*/
  exact = 0.12271846303085129838;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( x[i], 6 );
  }
  q = r8vec_dot_product ( n, w, f );
  error = fabs ( q - exact );
  printf ( "  x^6            %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = x^4y^2 -> x^4( 1 - x^2 )
*/
  exact = 0.024543692606170259675;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( x[i], 4 ) * ( 1.0 - pow ( x[i], 2 ) );
  }
  q = r8vec_dot_product ( n, w, f ) / 3.0;
  error = fabs ( q - exact );
  printf ( "  x^4y^2         %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = x^2y^4 -> x^2( 1 - x^2 )^2
*/
  exact = 0.024543692606170259675;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( x[i], 2 ) * pow ( 1.0 - pow ( x[i], 2 ), 2 );
  }
  q = r8vec_dot_product ( n, w, f ) / 5.0;
  error = fabs ( q - exact );
  printf ( "  x^2y^4         %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );
/*
  f(x,y) = y^6 -> ( 1 - x^2 )^3
*/
  exact = 0.12271846303085129838;
  for ( i = 0; i < n; i++ )
  {
    f[i] = pow ( 1.0 - pow ( x[i], 2 ), 3 );
  }
  q = r8vec_dot_product ( n, w, f ) / 7.0;
  error = fabs ( q - exact );
  printf ( "     y^6         %2d  %14.6g  %14.6g  %14.6g\n", n, exact, q, error );

  free ( f );
  free ( w );
  free ( x );

  return;
}
/******************************************************************************/

void chebyshev2_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV2_INTEGRAL_TEST tests CHEBYSHEV2_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int n;
  double value;

  printf ( "\n" );
  printf ( "CHEBYSHEV2_INTEGRAL_TEST\n" );
  printf ( "  CHEBYSHEV2_INTEGRAL evaluates\n" );
  printf ( "  Integral ( -1 < x < +1 ) x^n * sqrt(1-x*x) dx\n" );
  printf ( "\n" );
  printf ( "         N         Value\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    value = chebyshev2_integral ( n );

    printf ( "  %8d  %24.16g\n", n, value );
  }
 
  return;
}
/******************************************************************************/

void chebyshev2_set_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV2_SET_TEST tests CHEBYSHEV2_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "CHEBYSHEV2_SET_TEST\n" );
  printf ( "  CHEBYSHEV2_SET sets\n" );
  printf ( "  a Chebyshev Type 2 quadrature rule over [-1,1].\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    chebyshev2_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void chebyshev3_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV3_COMPUTE_TEST tests CHEBYSHEV3_COMPUTE

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 April 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "CHEBYSHEV3_COMPUTE_TEST\n" );
  printf ( "  CHEBYSHEV3_COMPUTE computes\n" );
  printf ( "  a Chebyshev Type 3 quadrature rule over [-1,1].\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    chebyshev3_compute ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void chebyshev3_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV3_INTEGRAL_TEST tests CHEBYSHEV3_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 June 2015

  Author:

    John Burkardt
*/
{
  int n;
  double value;

  printf ( "\n" );
  printf ( "CHEBYSHEV3_INTEGRAL_TEST\n" );
  printf ( "  CHEBYSHEV3_INTEGRAL evaluates\n" );
  printf ( "  Integral ( -1 < x < +1 ) x^n / sqrt(1-x*x) dx\n" );
  printf ( "\n" );
  printf ( "         N         Value\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    value = chebyshev3_integral ( n );

    printf ( "  %8d  %24.16g\n", n, value );
  }
 
  return;
}
/******************************************************************************/

void chebyshev3_set_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV3_SET_TEST tests CHEBYSHEV3_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "CHEBYSHEV3_SET_TEST\n" );
  printf ( "  CHEBYSHEV3_SET sets\n" );
  printf ( "  a Chebyshev Type 3 quadrature rule over [-1,1].\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    chebyshev3_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void clenshaw_curtis_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    CLENSHAW_CURTIS_COMPUTE_TEST tests CLENSHAW_CURTIS_COMPUTE

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 October 2006

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "CLENSHAW_CURTIS_COMPUTE_TEST\n" );
  printf ( "  CLENSHAW_CURTIS_COMPUTE computes\n" );
  printf ( "  a Clenshaw-Curtis quadrature rule over [-1,1].\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    clenshaw_curtis_compute ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void clenshaw_curtis_set_test ( )

/******************************************************************************/
/*
  Purpose:

    CLENSHAW_CURTIS_SET_TEST tests CLENSHAW_CURTIS_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "CLENSHAW_CURTIS_SET_TEST\n" );
  printf ( "  CLENSHAW_CURTIS_SET sets up a Clenshaw-Curtis rule;\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    clenshaw_curtis_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void fejer1_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    FEJER1_COMPUTE_TEST tests FEJER1_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 April 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "FEJER1_COMPUTE_TEST\n" );
  printf ( "  FEJER1_COMPUTE computes a Fejer type 1 quadrature rule;\n" );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    fejer1_compute ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void fejer1_set_test ( )

/******************************************************************************/
/*
  Purpose:

    FEJER1_SET_TEST tests FEJER1_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 April 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "FEJER1_SET_TEST\n" );
  printf ( "  FEJER1_SET sets a Fejer type 1 quadrature rule;\n" );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    fejer1_set ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void fejer2_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    FEJER2_COMPUTE_TEST tests FEJER2_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 April 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "FEJER2_COMPUTE_TEST\n" );
  printf ( "  FEJER2_COMPUTE computes a Fejer type 2 quadrature rule;\n" );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    fejer2_compute ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void fejer2_set_test ( )

/******************************************************************************/
/*
  Purpose:

    FEJER2_SET_TEST tests FEJER2_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 April 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "FEJER2_SET_TEST\n" );
  printf ( "  FEJER2_SET sets a Fejer type 2 quadrature rule;\n" );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    fejer2_set ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void gegenbauer_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    GEGENBAUER_INTEGRAL_TEST tests GEGENBAUER_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 June 2015

  Author:

    John Burkardt
*/
{
  double alpha;
  int n;
  double value;

  alpha = 0.25;

  printf ( "\n" );
  printf ( "GEGENBAUER_INTEGRAL_TEST\n" );
  printf ( "  GEGENBAUER_INTEGRAL evaluates\n" );
  printf ( "  Integral ( -1 < x < +1 ) x^n * (1-x*x)^alpha dx\n" );
  printf ( "\n" );
  printf ( "         N         Value\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    value = gegenbauer_integral ( n, alpha );

    printf ( "  %8d  %24.16g\n", n, value );
  }
 
  return;
}
/******************************************************************************/

void gegenbauer_ek_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    GEGENBAUER_EK_COMPUTE_TEST tests GEGENBAUER_EK_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 November 2015

  Author:

    John Burkardt
*/
{
  double a;
  double alpha;
  double b;
  int i;
  int n;
  double *w;
  double *x;

  alpha = 0.5;
  a = -1.0;
  b = +1.0;

  printf ( "\n" );
  printf ( "GEGENBAUER_EK_COMPUTE_TEST\n" );
  printf ( "  GEGENBAUER_EK_COMPUTE computes a Gauss-Gegenbauer rule;\n" );
  printf ( "\n" );
  printf ( "  Abscissas X and weights W for a Gauss Gegenbauer rule\n" );
  printf ( "  with ALPHA = %f\n", alpha );
  printf ( "  Integration interval = [%g,%g]\n", a, b );
  printf ( "\n" );
  printf ( "                  W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    printf ( "\n" );

    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    gegenbauer_ek_compute ( n, alpha, a, b, x, w );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }

    free ( w );
    free ( x );
  }
  return;
}
/******************************************************************************/

void gegenbauer_ss_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    GEGENBAUER_SS_COMPUTE_TEST tests GEGENBAUER_SS_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 June 2008

  Author:

    John Burkardt
*/
{
  double alpha;
  int i;
  int n;
  double *w;
  double *x;

  alpha = 0.5;

  printf ( "\n" );
  printf ( "GEGENBAUER_SS_COMPUTE_TEST\n" );
  printf ( "  GEGENBAUER_SS_COMPUTE computes a Gauss-Gegenbauer rule;\n" );
  printf ( "\n" );
  printf ( "  Abscissas X and weights W for a Gauss Gegenbauer rule\n" );
  printf ( "  with ALPHA = %f\n", alpha );
  printf ( "\n" );
  printf ( "                  W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    printf ( "\n" );

    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    gegenbauer_ss_compute ( n, alpha, x, w );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }

    free ( w );
    free ( x );
  }
  return;
}
/******************************************************************************/

void gen_hermite_ek_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    GEN_HERMITE_EK_COMPUTE_TEST tests GEN_HERMITE_EK_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 June 2015

  Author:

    John Burkardt
*/
{
  double alpha;
  int i;
  int n;
  double *w;
  double *x;

  alpha = 0.5;

  printf ( "\n" );
  printf ( "GEN_HERMITE_EK_COMPUTE_TEST\n" );
  printf ( "  GEN_HERMITE_EK_COMPUTE computes a \n" );
  printf ( "  generalized Hermite quadrature rule\n" );
  printf ( "  using the Elhay-Kautsky algorithm.\n" );
  printf ( "\n" );
  printf ( "  Using ALPHA = %g\n", alpha );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    gen_hermite_ek_compute ( n, alpha, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void gen_hermite_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    GEN_HERMITE_INTEGRAL_TEST tests GEN_HERMITE_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 June 2015

  Author:

    John Burkardt
*/
{
  double alpha;
  int n;
  double value;

  alpha = 0.5;

  printf ( "\n" );
  printf ( "GEN_HERMITE_INTEGRAL_TEST\n" );
  printf ( "  GEN_HERMITE_INTEGRAL evaluates\n" );
  printf ( "  Integral ( -oo < x < +oo ) exp(-x^2) x^n |x|^alpha dx\n" );
  printf ( "\n" );
  printf ( "  Use ALPHA = %g\n", alpha );
  printf ( "\n" );
  printf ( "         N         Value\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    value = gen_hermite_integral ( n, alpha );

    printf ( "  %8d  %24.16g\n", n, value );
  }
 
  return;
}
/******************************************************************************/

void gen_laguerre_ek_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    GEN_LAGUERRE_EK_COMPUTE_TEST tests GEN_LAGUERRE_EK_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 June 2015

  Author:

    John Burkardt
*/
{
  double alpha;
  int i;
  int n;
  double *w;
  double *x;

  alpha = 0.5;

  printf ( "\n" );
  printf ( "GEN_LAGUERRE_EK_COMPUTE_TEST\n" );
  printf ( "  GEN_LAGUERRE_EK_COMPUTE computes a \n" );
  printf ( "  generalized Laguerre quadrature rule\n" );
  printf ( "  using the Elhay-Kautsky algorithm.\n" );
  printf ( "\n" );
  printf ( "  Using ALPHA = %g\n", alpha );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    gen_laguerre_ek_compute ( n, alpha, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void gen_laguerre_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    GEN_LAGUERRE_INTEGRAL_TEST tests GEN_LAGUERRE_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 June 2015

  Author:

    John Burkardt
*/
{
  double alpha;
  int n;
  double value;

  alpha = 0.5;

  printf ( "\n" );
  printf ( "GEN_LAGUERRE_INTEGRAL_TEST\n" );
  printf ( "  GEN_LAGUERRE_INTEGRAL evaluates\n" );
  printf ( "  Integral ( 0 < x < +oo ) exp(-x) x^n x^alpha dx\n" );
  printf ( "\n" );
  printf ( "  Use ALPHA = %g\n", alpha );
  printf ( "\n" );
  printf ( "         N         Value\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    value = gen_laguerre_integral ( n, alpha );

    printf ( "  %8d  %24.16g\n", n, value );
  }
 
  return;
}
/******************************************************************************/

void gen_laguerre_ss_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    GEN_LAGUERRE_SS_COMPUTE_TEST tests GEN_LAGUERRE_SS_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 June 2015

  Author:

    John Burkardt
*/
{
  double alpha;
  int i;
  int n;
  double *w;
  double *x;

  alpha = 0.5;

  printf ( "\n" );
  printf ( "GEN_LAGUERRE_SS_COMPUTE_TEST\n" );
  printf ( "  GEN_LAGUERRE_SS_COMPUTE computes a \n" );
  printf ( "  generalized Laguerre quadrature rule\n" );
  printf ( "  using the Stroud-Secrest algorithm.\n" );
  printf ( "\n" );
  printf ( "  Using ALPHA = %g\n", alpha );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    gen_laguerre_ss_compute ( n, alpha, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void hermite_ek_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    HERMITE_EK_COMPUTE_TEST tests HERMITE_EK_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "HERMITE_EK_COMPUTE_TEST\n" );
  printf ( "  HERMITE_EK_COMPUTE computes a Hermite quadrature rule\n" );
  printf ( "  using the Elhay-Kautsky algorithm.\n" );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    hermite_ek_compute ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void hermite_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    HERMITE_INTEGRAL_TEST tests HERMITE_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int n;
  double value;

  printf ( "\n" );
  printf ( "HERMITE_INTEGRAL_TEST\n" );
  printf ( "  HERMITE_INTEGRAL evaluates\n" );
  printf ( "  Integral ( -oo < x < +oo ) exp(-x^2) x^n dx\n" );
  printf ( "\n" );
  printf ( "         N         Value\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    value = hermite_integral ( n );

    printf ( "  %8d  %24.16g\n", n, value );
  }
 
  return;
}
/******************************************************************************/

void hermite_set_test ( )

/******************************************************************************/
/*
  Purpose:

    HERMITE_SET_TEST tests HERMITE_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "HERMITE_SET_TEST\n" );
  printf ( "  HERMITE_SET sets up a Hermite quadrature rule;\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    hermite_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void hermite_ss_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    HERMITE_SS_COMPUTE_TEST tests HERMITE_SS_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "HERMITE_SS_COMPUTE_TEST\n" );
  printf ( "  HERMITE_SS_COMPUTE computes a Hermite quadrature rule\n" );
  printf ( "  using the Stroud-Secrest algorithm.\n" );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    hermite_ss_compute ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void hermite_gk16_set_test ( )

/******************************************************************************/
/*
  Purpose:

    HERMITE_GK16_SET_TEST tests HERMITE_GK16_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int l;
  int l_max = 8;
  int n;
  int n_list[9] = { 1, 3, 7, 9, 17, 19, 31, 33, 35 };
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "HERMITE_GK16_SET_TEST\n" );
  printf ( "  HERMITE_GK16_SET sets a nested Hermite quadrature rule\n" );
  printf ( "  over (-oo,+oo).\n" );
  printf ( "\n" );
  printf ( "     Order       X                       W\n" );

  for ( l = 0; l <= l_max; l++ )
  {
    n = n_list[l];
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    hermite_gk16_set ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }
  return;
}
/******************************************************************************/

void hermite_gk18_set_test ( )

/******************************************************************************/
/*
  Purpose:

    HERMITE_GK18_SET_TEST tests HERMITE_GK18_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int l;
  int l_max = 4;
  int n;
  int n_list[9] = { 1, 3, 9, 19, 37 };
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "HERMITE_GK18_SET_TEST\n" );
  printf ( "  HERMITE_GK18_SET sets a nested Hermite quadrature rule\n" );
  printf ( "  over (-oo,+oo).\n" );
  printf ( "\n" );
  printf ( "     Order       X                       W\n" );

  for ( l = 0; l <= l_max; l++ )
  {
    n = n_list[l];
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    hermite_gk18_set ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }
  return;
}
/******************************************************************************/

void hermite_gk22_set_test ( )

/******************************************************************************/
/*
  Purpose:

    HERMITE_GK22_SET_TEST tests HERMITE_GK22_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int l;
  int l_max = 4;
  int n;
  int n_list[9] = { 1, 3, 9, 19, 41 };
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "HERMITE_GK22_SET_TEST\n" );
  printf ( "  HERMITE_GK22_SET sets a nested Hermite quadrature rule\n" );
  printf ( "  over (-oo,+oo).\n" );
  printf ( "\n" );
  printf ( "     Order       X                       W\n" );

  for ( l = 0; l <= l_max; l++ )
  {
    n = n_list[l];
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    hermite_gk22_set ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }
  return;
}
/******************************************************************************/

void hermite_gk24_set_test ( )

/******************************************************************************/
/*
  Purpose:

    HERMITE_GK24_SET_TEST tests HERMITE_GK24_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int l;
  int l_max = 4;
  int n;
  int n_list[9] = { 1, 3, 9, 19, 43 };
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "HERMITE_GK24_SET_TEST\n" );
  printf ( "  HERMITE_GK24_SET sets a nested Hermite quadrature rule\n" );
  printf ( "  over (-oo,+oo).\n" );
  printf ( "\n" );
  printf ( "     Order       X                       W\n" );

  for ( l = 0; l <= l_max; l++ )
  {
    n = n_list[l];
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    hermite_gk24_set ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }
  return;
}
/******************************************************************************/

void hermite_1_set_test ( )

/******************************************************************************/
/*
  Purpose:

    HERMITE_1_SET_TEST tests HERMITE_1_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "HERMITE_1_SET_TEST\n" );
  printf ( "  HERMITE_1_SET sets up a unit density Hermite quadrature rule;\n" );
  printf ( "  The integration interval is ( -oo, +oo ).\n" );
  printf ( "  The weight function is 1.\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    hermite_1_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void hermite_probabilist_set_test ( )

/******************************************************************************/
/*
  Purpose:

    HERMITE_PROBABILIST_SET_TEST tests HERMITE_PROBABILIST_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "HERMITE_PROBABILIST_SET_TEST\n" );
  printf ( "  HERMITE_PROBABILIST_SET sets up a Hermite quadrature rule;\n" );
  printf ( "  The integration interval is ( -oo, +oo ).\n" );
  printf ( "  The weight function is exp ( - x * x / 2 ) / sqrt ( 2 * pi ).\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    hermite_probabilist_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void imtqlx_test ( )

/******************************************************************************/
/*
  Purpose:

    IMTQLX_TEST tests IMTQLX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 June 2015

  Author:

    John Burkardt.
*/
{
  double angle;
  double d[5];
  double e[5];
  int i;
  double lam[5];
  double lam2[5];
  int n = 5;
  double qtz[5];
  double r8_pi = 3.141592653589793;
  double z[5];

  printf ( "\n" );
  printf ( "IMTQLX_TEST\n" );
  printf ( "  IMTQLX takes a symmetric tridiagonal matrix A\n" );
  printf ( "  and computes its eigenvalues LAM.\n" );
  printf ( "  It also accepts a vector Z and computes Q'*Z,\n" );
  printf ( "  where Q is the matrix that diagonalizes A.\n" );

  for ( i = 0; i < n; i++ )
  {
    d[i] = 2.0;
  }
  for ( i = 0; i < n - 1; i++ )
  {
    e[i] = -1.0;
  }
  e[n-1] = 0.0;
  for ( i = 0; i < n; i++ )
  {
    z[i] = 1.0;
  }
/*
  On input, LAM is D, and QTZ is Z.
*/
  for ( i = 0; i < n; i++ )
  {
    lam[i] = d[i];
  }
  for ( i = 0; i < n; i++ )
  {
    qtz[i] = z[i];
  }

  imtqlx ( n, lam, e, qtz );

  r8vec_print ( n, lam, "  Computed eigenvalues:" );

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( 2 * ( n + 1 ) );
    lam2[i] = 4.0 * pow ( sin ( angle ), 2 );
  }

  r8vec_print ( n, lam2, "  Exact eigenvalues:" );

  r8vec_print ( n, z, "  Vector Z:" );
  r8vec_print ( n, qtz, "  Vector Q'*Z:" );

  return;
}
/******************************************************************************/

void jacobi_ek_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    JACOBI_EK_COMPUTE tests JACOBI_EK_COMPUTE.

  Discussion:

    Compare with tabular values on page 178 of Stroud and Secrest.

     In particular,

             X              W

     1  -0.9833999115   0.4615276287E-03
     2  -0.9447138932   0.2732249104E-02
     3  -0.8849310847   0.8045830455E-02
    ..  .............   ................
    19   0.9656375637   0.7613987785E-01
    20   0.9934477866   0.3348337670E-01

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 June 2015

  Author:

    John Burkardt
*/
{
  double alpha;
  double beta;
  int i;
  int n;
  double *w;
  double *x;

  alpha = 1.5;
  beta = 0.5;

  printf ( "\n" );
  printf ( "JACOBI_EK_COMPUTE_TEST\n" );
  printf ( "  JACOBI_EK_COMPUTE computes a Gauss-Jacobi rule;\n" );
  printf ( "\n" );
  printf ( "  ALPHA = %f\n", alpha );
  printf ( "  BETA =  %f\n", beta );

  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    jacobi_ek_compute ( n, alpha, beta, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void jacobi_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    JACOBI_INTEGRAL_TEST tests JACOBI_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 June 2015

  Author:

    John Burkardt
*/
{
  double alpha;
  double beta;
  int n;
  double value;

  alpha = 1.5;
  beta = 0.5;

  printf ( "\n" );
  printf ( "JACOBI_INTEGRAL_TEST\n" );
  printf ( "  JACOBI_INTEGRAL evaluates\n" );
  printf ( "  Integral ( -1 < x < +1 ) x^n (1-x)^alpha (1+x)^beta dx\n" );
  printf ( "\n" );
  printf ( "  Use ALPHA = %g\n", alpha );
  printf ( "      BETA  = %g\n", beta );
  printf ( "\n" );
  printf ( "         N         Value\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    value = jacobi_integral ( n, alpha, beta );

    printf ( "  %8d  %24.16g\n", n, value );
  }
 
  return;
}
/******************************************************************************/

void jacobi_ss_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    JACOBI_SS_COMPUTE tests JACOBI_SS_COMPUTE.

  Discussion:

    Compare with tabular values on page 178 of Stroud and Secrest.

     In particular,

             X              W

     1  -0.9833999115   0.4615276287E-03
     2  -0.9447138932   0.2732249104E-02
     3  -0.8849310847   0.8045830455E-02
    ..  .............   ................
    19   0.9656375637   0.7613987785E-01
    20   0.9934477866   0.3348337670E-01

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 June 2015

  Author:

    John Burkardt
*/
{
  double alpha;
  double beta;
  int i;
  int n;
  double *w;
  double *x;

  alpha = 1.5;
  beta = 0.5;

  printf ( "\n" );
  printf ( "JACOBI_SS_COMPUTE_TEST\n" );
  printf ( "  JACOBI_SS_COMPUTE computes a Gauss-Jacobi rule;\n" );
  printf ( "\n" );
  printf ( "  ALPHA = %f\n", alpha );
  printf ( "  BETA =  %f\n", beta );

  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    jacobi_ss_compute ( n, alpha, beta, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void kronrod_set_test ( )

/******************************************************************************/
/*
  Purpose:

    KRONROD_SET_TEST tests KRONROD_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int nk;
  int nl;
  int nl_test[4] = { 7, 10, 15, 20 };
  int test;
  double *wk;
  double *wl;
  double *xk;
  double *xl;

  printf ( "\n" );
  printf ( "KRONROD_SET_TEST\n" );
  printf ( "  KRONROD_SET sets up a Kronrod quadrature rule;\n" );
  printf ( "  This is used following a lower order Legendre rule.\n" );

  for ( test = 0; test < 4; test++ )
  {
    printf ( "\n" );
    printf ( "  Legendre/Kronrod quadrature pair #%d\n", test );
    printf ( "                X                         W\n" );
    printf ( "\n" );

    nl = nl_test[test];
    wl = ( double * ) malloc ( nl * sizeof ( double ) );
    xl = ( double * ) malloc ( nl * sizeof ( double ) );

    legendre_set ( nl, xl, wl );

    printf ( "\n" );

    for ( i = 0; i < nl; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, xl[i], wl[i] );
    }
    free ( wl );
    free ( xl );

    printf ( "\n" );

    nk = 2 * nl + 1;
    wk = ( double * ) malloc ( nk * sizeof ( double ) );
    xk = ( double * ) malloc ( nk * sizeof ( double ) );

    kronrod_set ( nk, xk, wk );

    printf ( "\n" );

    for ( i = 0; i < nk; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, xk[i], wk[i] );
    }
    free ( wk );
    free ( xk );
  }
  return;
}
/******************************************************************************/

void laguerre_ek_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    LAGUERRE_EK_COMPUTE_TEST tests LAGUERRE_EK_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "LAGUERRE_EK_COMPUTE_TEST\n" );
  printf ( "  LAGUERRE_EK_COMPUTE computes a Laguerre quadrature rule\n" );
  printf ( "  using the Elhay-Kautsky algorithm.\n" );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    laguerre_ek_compute ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void laguerre_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    LAGUERRE_INTEGRAL_TEST tests LAGUERRE_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 June 2015

  Author:

    John Burkardt
*/
{
  int n;
  double value;

  printf ( "\n" );
  printf ( "LAGUERRE_INTEGRAL_TEST\n" );
  printf ( "  LAGUERRE_INTEGRAL evaluates\n" );
  printf ( "  Integral ( 0 < x < oo ) x^n exp(-x) dx\n" );
  printf ( "\n" );
  printf ( "         N         Value\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    value = laguerre_integral ( n );

    printf ( "  %8d  %24.16g\n", n, value );
  }
 
  return;
}
/******************************************************************************/

void laguerre_set_test ( )

/******************************************************************************/
/*
  Purpose:

    LAGUERRE_SET_TEST tests LAGUERRE_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "LAGUERRE_SET_TEST\n" );
  printf ( "  LAGUERRE_SET sets a Laguerre rule.\n" );
  printf ( "\n" );
  printf ( "         I      X            W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    laguerre_set ( n, x, w );

    printf ( "\n" );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void laguerre_ss_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    LAGUERRE_SS_COMPUTE_TEST tests LAGUERRE_SS_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "LAGUERRE_SS_COMPUTE_TEST\n" );
  printf ( "  LAGUERRE_SS_COMPUTE computes a Laguerre quadrature rule\n" );
  printf ( "  using the Stroud-Secrest algorithm.\n" );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    laguerre_ss_compute ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void laguerre_1_set_test ( )

/******************************************************************************/
/*
  Purpose:

    LAGUERRE_1_SET_TEST tests LAGUERRE_1_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "LAGUERRE_1_SET_TEST\n" );
  printf ( "  LAGUERRE_1_SET sets a Laguerre rule.\n" );
  printf ( "  The density function is rho(x) = 1.\n" );
  printf ( "\n" );
  printf ( "         I      X            W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    laguerre_1_set ( n, x, w );

    printf ( "\n" );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void legendre_dr_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    LEGENDRE_DR_COMPUTE_TEST tests LEGENDRE_DR_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "LEGENDRE_DR_COMPUTE_TEST\n" );
  printf ( "  LEGENDRE_DR_COMPUTE computes a Legendre quadrature rule\n" );
  printf ( "  using the Davis-Rabinowitz algorithm.\n" );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    legendre_dr_compute ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void legendre_ek_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    LEGENDRE_EK_COMPUTE_TEST tests LEGENDRE_EK_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    16 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "LEGENDRE_EK_COMPUTE_TEST\n" );
  printf ( "  LEGENDRE_EK_COMPUTE computes a Legendre quadrature rule\n" );
  printf ( "  using the Elhay-Kautsky algorithm.\n" );
  printf ( "\n" );
  printf ( "     Order        W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    legendre_ek_compute ( n, x, w );

    printf ( "\n" );
    printf ( "  %8d\n", n );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, w[i], x[i]  );
    }
    free ( w );
    free ( x );
  }

  return;
}
/******************************************************************************/

void legendre_integral_test ( )

/******************************************************************************/
/*
  Purpose:

    LEGENDRE_INTEGRAL_TEST tests LEGENDRE_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    14 June 2015

  Author:

    John Burkardt
*/
{
  int n;
  double value;

  printf ( "\n" );
  printf ( "LEGENDRE_INTEGRAL_TEST\n" );
  printf ( "  LEGENDRE_INTEGRAL evaluates\n" );
  printf ( "  Integral ( -1 < x < +1 ) x^n dx\n" );
  printf ( "\n" );
  printf ( "         N         Value\n" );
  printf ( "\n" );

  for ( n = 0; n <= 10; n++ )
  {
    value = legendre_integral ( n );

    printf ( "  %8d  %24.16g\n", n, value );
  }
 
  return;
}
/******************************************************************************/

void legendre_set_test ( )

/******************************************************************************/
/*
  Purpose:

    LEGENDRE_SET_TEST tests LEGENDRE_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    18 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "LEGENDRE_SET_TEST\n" );
  printf ( "  LEGENDRE_SET sets a Legendre rule.\n" );
  printf ( "\n" );
  printf ( "         I      X            W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    legendre_set ( n, x, w );

    printf ( "\n" );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void lobatto_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    LOBATTO_COMPUTE_TEST tests LOBATTO_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 April 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "LOBATTO_COMPUTE_TEST\n" );
  printf ( "  LOBATTO_COMPUTE computes a Lobatto rule;\n" );
  printf ( "\n" );
  printf ( "         I      X             W\n" );

  for ( n = 4; n <= 12; n = n + 3 )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    lobatto_compute ( n, x, w );

    printf ( "\n" );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %8d  %12g  %12g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
  return;
}
/******************************************************************************/

void lobatto_set_test ( )

/******************************************************************************/
/*
  Purpose:

    LOBATTO_SET_TEST tests LOBATTO_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 April 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "LOBATTO_SET_TEST\n" );
  printf ( "  LOBATTO_SET sets a Lobatto rule;\n" );
  printf ( "\n" );
  printf ( "         I      X             W\n" );

  for ( n = 4; n <= 12; n = n + 3 )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    lobatto_set ( n, x, w );

    printf ( "\n" );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %8d  %12g  %12g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
  return;
}
/******************************************************************************/

void nc_compute_weights_test ( )

/******************************************************************************/
/*
  Purpose:

    NC_COMPUTE_WEIGHTS_TEST tests NC_COMPUTE_WEIGHTS.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;
  double x_max;
  double x_min;

  printf ( "\n" );
  printf ( "NC_COMPUTE_WEIGHTS_TEST\n" );
  printf ( "  NC_COMPUTE_WEIGHTS computes weights for \n" );
  printf ( "  a Newton-Cotes rule;\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  x_min = 0.0;
  x_max = 1.0;

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    r8vec_linspace ( n, x_min, x_max, x );
    nc_compute_weights ( n, x_min, x_max, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void ncc_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    NCC_COMPUTE_TEST tests NCC_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "NCC_COMPUTE_TEST\n" );
  printf ( "  NCC_COMPUTE computes a Newton-Cotes Closed rule;\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    ncc_compute ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void ncc_set_test ( )

/******************************************************************************/
/*
  Purpose:

    NCC_SET_TEST tests NCC_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    24 April 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "NCC_SET_TEST\n" );
  printf ( "  NCC_SET sets up a Newton-Cotes Closed rule;\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    ncc_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void nco_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    NCO_COMPUTE_TEST tests NCO_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "NCO_COMPUTE_TEST\n" );
  printf ( "  NCO_COMPUTE computes a Newton-Cotes Open rule;\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    nco_compute ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void nco_set_test ( )

/******************************************************************************/
/*
  Purpose:

    NCO_SET_TEST tests NCO_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "NCO_SET_TEST\n" );
  printf ( "  NCO_SET sets up a Newton-Cotes Open rule;\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    nco_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void ncoh_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    NCOH_COMPUTE_TEST tests NCOH_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "NCOH_COMPUTE_TEST\n" );
  printf ( "  NCOH_COMPUTE computes a Newton-Cotes Open Half rule;\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    ncoh_compute ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void ncoh_set_test ( )

/******************************************************************************/
/*
  Purpose:

    NCOH_SET_TEST tests NCOH_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "NCOH_SET_TEST\n" );
  printf ( "  NCOH_SET sets up a Newton-Cotes Open Half rule;\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( n = 1; n <= 10; n++ )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    ncoh_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void patterson_set_test ( )

/******************************************************************************/
/*
  Purpose:

    PATTERSON_SET_TEST tests PATTERSON_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int n;
  int n_test[4] = { 1, 3, 7, 15 };
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "PATTERSON_SET_TEST\n" );
  printf ( "  PATTERSON_SET sets Patterson quadrature rule;\n" );
  printf ( "\n" );
  printf ( "    Index      X             W\n" );

  for ( j = 0; j < 4; j++ )
  {
    n = n_test[j];
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    patterson_set ( n, x, w );

    printf ( "\n" );

    for ( i = 0; i < n; i++ )
    {
      printf ( "  %2d  %24.16g  %24.16g\n", i, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
 
  return;
}
/******************************************************************************/

void r8_psi_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_PSI_TEST tests R8_PSI.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    19 May 2012

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_PSI_TEST:\n" );
  printf ( "  R8_PSI evaluates the Psi function.\n" );
  printf ( "\n" );
  printf ( "         X                  Psi(X)           " );
  printf ( "         Psi(X)          DIFF\n" );
  printf ( "                         (Tabulated)         " );
  printf ( "       (R8_PSI)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    psi_values ( &n_data, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_psi ( x );

    printf ( "  %8.2g  %24.16g  %24.16g  %10.4g\n", 
      x, fx, fx2, fabs ( fx - fx2 ) );

  }

  return;
}
/******************************************************************************/

void radau_compute_test ( )

/******************************************************************************/
/*
  Purpose:

    RADAU_COMPUTE_TEST tests RADAU_COMPUTE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "RADAU_COMPUTE_TEST\n" );
  printf ( "  RADAU_COMPUTE computes a Radau rule;\n" );
  printf ( "\n" );
  printf ( "         I      X            W\n" );

  for ( n = 4; n <= 12; n = n + 3 )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    radau_compute ( n, x, w );

    printf ( "\n" );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %8d  %24.16gg  %24.16g\n", i+1, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
  return;
}
/******************************************************************************/

void radau_set_test ( )

/******************************************************************************/
/*
  Purpose:

    RADAU_SET_TEST tests RADAU_SET.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    09 June 2015

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double *w;
  double *x;

  printf ( "\n" );
  printf ( "RADAU_SET_TEST\n" );
  printf ( "  RADAU_SET sets a Radau rule from a table.\n" );
  printf ( "\n" );
  printf ( "         I      X            W\n" );

  for ( n = 4; n <= 12; n = n + 3 )
  {
    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    radau_set ( n, x, w );

    printf ( "\n" );
    for ( i = 0; i < n; i++ )
    {
      printf ( "  %8d  %24.16g  %24.16g\n", i+1, x[i], w[i] );
    }
    free ( w );
    free ( x );
  }
  return;
}
