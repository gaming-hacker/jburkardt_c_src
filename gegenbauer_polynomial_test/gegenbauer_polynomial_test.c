# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "gegenbauer_polynomial.h"

int main ( );
void gegenbauer_alpha_check_test ( );
void gegenbauer_ek_compute_test ( );
void gegenbauer_integral_test ( );
void gegenbauer_polynomial_value_test ( );
void gegenbauer_ss_compute_test ( );
void imtqlx_test ( );
void r8_hyper_2f1_test ( );
void r8_uniform_ab_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    GEGENBAUER_POLYNOMIAL_TEST tests the GEGENBAUER_POLYNOMIAL library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 November 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "GEGENBAUER_POLYNOMIAL_TEST:\n" );
  printf ( "  MATLAB version.\n" );
  printf ( "  Test the GEGENBAUER_POLYNOMIAL library.\n" );

  gegenbauer_alpha_check_test ( );
  gegenbauer_ek_compute_test ( );
  gegenbauer_integral_test ( );
  gegenbauer_polynomial_value_test ( );
  gegenbauer_ss_compute_test ( );

  imtqlx_test ( );

  r8_hyper_2f1_test ( );
  r8_uniform_ab_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "GEGENBAUER_POLYNOMIAL_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void gegenbauer_alpha_check_test ( )

/******************************************************************************/
/*
  Purpose:

    GEGENBAUER_ALPHA_CHECK_TEST compares GEGENBAUER_ALPHA_CHECK.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    30 November 2015

  Author:

    John Burkardt
*/
{
  double alpha;
  bool check;
  int n;
  int seed;

  printf ( "\n" );
  printf ( "GEGENBAUER_ALPHA_CHECK_TEST\n" );
  printf ( "  GEGENBAUER_ALPHA_CHECK checks that ALPHA is legal;\n" );
  printf ( "\n" );
  printf ( "       ALPHA   Check?\n" );
  printf ( "\n" );

  seed = 123456789;

  for ( n = 1; n <= 10; n++ )
  {
    alpha = r8_uniform_ab ( -5.0, +5.0, &seed );
    check = gegenbauer_alpha_check ( alpha );
    printf ( "  %10.4f       %1d\n", alpha, check );
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
  double alpha;
  int i;
  int n;
  double *w;
  double *x;

  alpha = 0.5;

  printf ( "\n" );
  printf ( "GEGENBAUER_EK_COMPUTE_TEST\n" );
  printf ( "  GEGENBAUER_EK_COMPUTE computes a Gauss-Gegenbauer rule;\n" );
  printf ( "\n" );
  printf ( "  Abscissas X and weights W for a Gauss Gegenbauer rule\n" );
  printf ( "  with ALPHA = %f\n", alpha );
  printf ( "  Integration interval = [-1,+1]\n" );
  printf ( "\n" );
  printf ( "                  W               X\n" );

  for ( n = 1; n <= 10; n++ )
  {
    printf ( "\n" );

    w = ( double * ) malloc ( n * sizeof ( double ) );
    x = ( double * ) malloc ( n * sizeof ( double ) );

    gegenbauer_ek_compute ( n, alpha, x, w );

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

void gegenbauer_polynomial_value_test ( )

/******************************************************************************/
/*
  Purpose:

    GEGENBAUER_POLYNOMIAL_VALUE_TEST tests GEGENBAUER_POLYNOMIAL_VALUE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 November 2015

  Author:

    John Burkardt
*/
{
  double alpha;
  double *c;
  double fx;
  int m;
  int n;
  int n_data;
  double x[1];
  double xscalar;

  printf ( "\n" );
  printf ( "GEGENBAUER_POLYNOMIAL_VALUE_TEST:\n" );
  printf ( "  GEGENBAUER_POLYNOMIAL_VALUE evaluates the Gegenbauer polynomial.\n" );
  printf ( "\n" );
  printf ( "       M     ALPHA         X           GPV    GEGENBAUER\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gegenbauer_polynomial_values ( &n_data, &m, &alpha, &xscalar, &fx );

    if ( n_data == 0 )
    {
      break;
    }
/*
  Since GEGENBAUER_POLYNOMIAL_VALUE expects a vector input X, we have to
  do a little "rewrapping" of the input.
*/
    n = 1;
    x[0] = xscalar;
    c = gegenbauer_polynomial_value ( m, n, alpha, x );
    printf ( "  %6d  %8.2f  %8.2f  %12f  %12f\n", m, alpha, x[0], fx, c[m+0*(m+1)] );
    free ( c );
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

void r8_hyper_2f1_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_HYPER_2F1_TEST tests R8_HYPER_2F1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 May 2012

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double fx;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_HYPER_2F1_TEST:\n" );
  printf ( "  R8_HYPER_2F1 evaluates the hypergeometric function 2F1.\n" );
  printf ( "\n" );
  printf ( "      A       B       C       X      " );
  printf ( " 2F1                       2F1                     DIFF\n" );
  printf ( "                                     " );
  printf ( "(tabulated)               (computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    hyper_2f1_values ( &n_data, &a, &b, &c, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_hyper_2f1 ( a, b, c, x );

    printf ( "  %6f  %6f  %6f  %6f  %24.16g  %24.16g  %10.4g\n",
      a, b, c, x, fx, fx2, fabs ( fx - fx2 )  );
  }
  return;
}
/******************************************************************************/

void r8_uniform_ab_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_AB_TEST tests R8_UNIFORM_AB.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  int i;
  int seed;

  b = 10.0;
  c = 25.0;
  seed = 17;

  printf ( "\n" );
  printf ( "R8_UNIFORM_AB_TEST\n" );
  printf ( "  R8_UNIFORM_AB produces a random real in a given range.\n" );
  printf ( "\n" );
  printf ( "  Using range %f <= A <= %f.\n", b, c );
  printf ( "\n" );

  printf ( "\n" );
  printf ( "     I      A\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    a = r8_uniform_ab ( b, c, &seed );
    printf ( "  %4d  %10f\n", i, a );
  }

  return;
}

