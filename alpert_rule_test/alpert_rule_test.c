# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "alpert_rule.h"

int main ( );
void monte_carlo_regular_test ( );
void monte_carlo_log_test ( );
void monte_carlo_power_test ( );
void trapezoid_regular_test ( );
void trapezoid_log_test ( );
void trapezoid_power_test ( );
void alpert_regular_test ( );
void alpert_log_test ( );
void alpert_power_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    ALPERT_RULE_TEST tests the ALPERT_RULE library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2015

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ALPERT_RULE_TEST\n" );
  printf ( "  C version.\n" );
  printf ( "  Test the ALPERT_RULE library.\n" );

  monte_carlo_regular_test ( );
  monte_carlo_log_test ( );
  monte_carlo_power_test ( );

  trapezoid_regular_test ( );
  trapezoid_log_test ( );
  trapezoid_power_test ( );

  alpert_regular_test ( );
  alpert_log_test ( );
  alpert_power_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ALPERT_RULE_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void alpert_log_test ( )

/******************************************************************************/
/*
  Purpose:

    ALPERT_LOG_TEST tests the Alpert rule on the log integrand.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2015

  Author:

    John Burkardt
*/
{
  int a_l;
  int a_r;
  double *f1;
  double *f2;
  double *f3;
  double h;
  int i;
  int j_l;
  int j_r;
  int n;
  int nlog;
  int num_l;
  int order_l;
  int rule;
  double s1;
  double s2;
  double s3;
  double v1;
  double v2;
  double *w_l;
  double *w_r;
  double *x_l;
  double *x_r;
  double *x1;
  double *x2;
  double *x3;

  printf ( "\n" );
  printf ( "ALPERT_LOG_TEST\n" );
  printf ( "  Test the Alpert rule on the log integrand.\n" );
  printf ( "\n" );
  printf ( "  Rule  Order   J   A        N     N+2J               H        Estimate           Error\n" );
  printf ( "\n" );

  v2 = integral_log ( );

  num_l = num_log ( );
/*
  For the righthand interval, use the regular rule of the same index.
*/
  for ( rule = 1; rule <= num_l; rule++ )
  {
    a_l = a_log ( rule );
    j_l = j_log ( rule );
    order_l = order_log ( rule );
    x_l = ( double * ) malloc ( j_l * sizeof ( double ) );
    w_l = ( double * ) malloc ( j_l * sizeof ( double ) );
    rule_log ( rule, j_l, x_l, w_l );
    x1 = ( double * ) malloc ( j_l * sizeof ( double ) );

    a_r = a_regular ( rule );
    j_r = j_regular ( rule );
    x_r = ( double * ) malloc ( j_r * sizeof ( double ) );
    w_r = ( double * ) malloc ( j_r * sizeof ( double ) );
    rule_regular ( rule, j_r, x_r, w_r );
    x3 = ( double * ) malloc ( j_r * sizeof ( double ) );

    n = 8;

    for ( nlog = 4; nlog <= 7; nlog++ )
    {
      n = n * 2;
      h = 1.0 / ( double ) ( n + a_l + a_r - 1 );

      for ( i = 0; i < j_l; i++ )
      {
        x1[i] = h * x_l[i];
      }
      f1 = integrand_log ( j_l, x1 );
      s1 = r8vec_dot_product ( j_l, w_l, f1 );
      x2 = r8vec_linspace_new ( n, a_l * h, ( a_l + n - 1 ) * h );
      f2 = integrand_log ( n, x2 );
      s2 = r8vec_sum ( n, f2 );
      for ( i = 0; i < j_r; i++ )
      {
        x3[i] = 1.0 - h * x_r[i];
      }
      f3 = integrand_log ( j_r, x3 );
      s3 = r8vec_dot_product ( j_r, w_r, f3 );

      v1 = h * ( s1 + s2 + s3 );

      printf ( "    %2d   %4d  %2d  %2d  %7d  %7d  %14.6g  %14.6g  %14.6g\n",
        rule, order_l, j_l, a_l, n, n + j_l + j_r, h, v1, fabs ( v1 - v2 ) );

      free ( f1 );
      free ( f2 );
      free ( f3 );
      free ( x2 );
    }

    printf ( "\n" );

    free ( w_l );
    free ( w_r );
    free ( x_l );
    free ( x_r );
    free ( x1 );
    free ( x3 );
  }

  printf ( "\n" );
  printf ( "                                                   Exact:%14.6g\n", v2 );

  return;
}
/******************************************************************************/

void alpert_power_test ( )

/******************************************************************************/
/*
  Purpose:

    ALPERT_POWER_TEST tests the Alpert rule on the power integrand.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2015

  Author:

    John Burkardt
*/
{
  int a_p;
  int a_r;
  double *f1;
  double *f2;
  double *f3;
  double h;
  int i;
  int j_p;
  int j_r;
  int n;
  int nlog;
  int num_p;
  double order_p;
  int rule;
  double s1;
  double s2;
  double s3;
  double v1;
  double v2;
  double *w_p;
  double *w_r;
  double *x_p;
  double *x_r;
  double *x1;
  double *x2;
  double *x3;

  printf ( "\n" );
  printf ( "ALPERT_POWER_TEST\n" );
  printf ( "  Test the Alpert rule on the power integrand.\n" );
  printf ( "\n" );
  printf ( "  Rule  Order   J   A        N     N+2J               H        Estimate           Error\n" );
  printf ( "\n" );

  v2 = integral_power ( );

  num_p = num_power ( );
/*
  For the righthand interval, use the regular rule of the same index.
*/
  for ( rule = 1; rule <= num_p; rule++ )
  {
    a_p = a_power ( rule );
    j_p = j_power ( rule );
    order_p = order_power ( rule );
    x_p = ( double * ) malloc ( j_p * sizeof ( double ) );
    w_p = ( double * ) malloc ( j_p * sizeof ( double ) );
    rule_power ( rule, j_p, x_p, w_p );

    x1 = ( double * ) malloc ( j_p * sizeof ( double ) );

    a_r = a_regular ( rule );
    j_r = j_regular ( rule );
    x_r = ( double * ) malloc ( j_r * sizeof ( double ) );
    w_r = ( double * ) malloc ( j_r * sizeof ( double ) );
    rule_regular ( rule, j_r, x_r, w_r );

    x3 = ( double * ) malloc ( j_r * sizeof ( double ) );

    n = 8;

    for ( nlog = 4; nlog <= 6; nlog++ )
    {
      n = n * 2;
      h = 1.0 / ( double ) ( n + a_p + a_r - 1 );

      for ( i = 0; i < j_p; i++ )
      {
        x1[i] = h * x_p[i];
      }
      f1 = integrand_power ( j_p, x1 );
      s1 = r8vec_dot_product ( j_p, w_p, f1 );

      x2 = r8vec_linspace_new ( n, a_p * h, ( a_p + n - 1 ) * h );
      f2 = integrand_power ( n, x2 );
      s2 = r8vec_sum ( n, f2 );

      for ( i = 0; i < j_r; i++ )
      {
        x3[i] = 1.0 - h * x_r[i];
      }
      f3 = integrand_power ( j_r, x3 );
      s3 = r8vec_dot_product ( j_r, w_r, f3 );

      v1 = h * ( s1 + s2 + s3 );

      printf ( "    %2d   %4.1f  %2d  %2d  %7d  %7d  %14.6g  %14.6g  %14.6g\n",
        rule, order_p, j_p, a_p, n, n + j_p + j_r, h, v1, fabs ( v1 - v2 ) );

      free ( f1 );
      free ( f2 );
      free ( f3 );
      free ( x2 );
    }
    printf ( "\n" );
    free ( w_p );
    free ( w_r );
    free ( x_p );
    free ( x_r );
    free ( x1 );
    free ( x3 );
  }

  printf ( "\n" );
  printf ( "                                                   Exact:%14.6g\n", v2 );

  return;
}
/******************************************************************************/

void alpert_regular_test ( )

/******************************************************************************/
/*
  Purpose:

    ALPERT_REGULAR_TEST tests the Alpert rule on the regular integrand.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2015

  Author:

    John Burkardt
*/
{
  int a;
  double *f1;
  double *f2;
  double *f3;
  double h;
  int i;
  int j;
  int n;
  int nlog;
  int num;
  int order;
  int rule;
  double s1;
  double s2;
  double s3;
  double v1;
  double v2;
  double *w;
  double *x;
  double *x1;
  double *x2;
  double *x3;

  printf ( "\n" );
  printf ( "ALPERT_REGULAR_TEST\n" );
  printf ( "  Test the Alpert rule on the regular integrand.\n" );
  printf ( "\n" );
  printf ( "  Rule  Order   J   A        N     N+2J               H        Estimate           Error\n" );
  printf ( "\n" );

  v2 = integral_regular ( );

  num = num_regular ( );

  for ( rule = 1; rule <= num; rule++ )
  {
    a = a_regular ( rule );
    j = j_regular ( rule );
    order = order_regular ( rule );
    x = ( double * ) malloc ( j * sizeof ( double ) );
    w = ( double * ) malloc ( j * sizeof ( double ) );
    rule_regular ( rule, j, x, w );

    x1 = ( double * ) malloc ( j * sizeof ( double ) );
    x3 = ( double * ) malloc ( j * sizeof ( double ) );

    n = 8;

    for ( nlog = 4; nlog <= 6; nlog++ )
    {
      n = n * 2;
      h = 1.0 / ( double ) ( n + 2 * a - 1 );

      for ( i = 0; i < j; i++ )
      {
        x1[i] = h * x[i];
      }
      f1 = integrand_regular ( j, x1 ); 
      s1 = r8vec_dot_product ( j, w, f1 );

      x2 = r8vec_linspace_new ( n, a * h, ( a + n - 1 ) * h );
      f2 = integrand_regular ( n, x2 );
      s2 = r8vec_sum ( n, f2 );

      for ( i = 0; i < j; i++ )
      {
        x3[i] = 1.0 - h * x[i];
      }
      f3 = integrand_regular ( j, x3 );
      s3 = r8vec_dot_product ( j, w, f3 );

      v1 = h * ( s1 + s2 + s3 );

      printf ( "    %2d   %4d  %2d  %2d  %7d  %7d  %14.6g  %14.6g  %14.6g\n",
        rule, order, j, a, n, n + 2 * j, h, v1, fabs ( v1 - v2 ) );

      free ( f1 );
      free ( f2 );
      free ( f3 );
      free ( x2 );
    }
    printf ( "\n" );
    free ( w );
    free ( x );
    free ( x1 );
    free ( x3 );
  }

  printf ( "\n" );
  printf ( "                                                   Exact:%14.6g\n", v2 );

  return;
}
/******************************************************************************/

void monte_carlo_log_test ( )

/******************************************************************************/
/*
  Purpose:

    MONTE_CARLO_LOG_TEST tests the Monte Carlo rule on the log singular integrand.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2015

  Author:

    John Burkardt
*/
{
  double *f;
  double h;
  int n;
  int nlog;
  int seed;
  double v1;
  double v2;
  double *x;

  printf ( "\n" );
  printf ( "MONTE_CARLO_LOG_TEST\n" );
  printf ( "  Test the Monte Carlo rule on the log singular integrand.\n" );
  printf ( "\n" );
  printf ( "          N        Estimate           Error\n" );
  printf ( "\n" );

  v2 = integral_log ( );

  seed = 123456789;

  n = 17;

  for ( nlog = 5; nlog <= 20; nlog++ )
  {
    n = ( n - 1 ) * 2 + 1;
    h = 1.0 / ( double ) ( n );
    x = r8vec_uniform_01_new ( n, &seed );
    f = integrand_log ( n, x );
    v1 = h * r8vec_sum ( n, f );
    printf ( "  %9d  %14.6g  %14.6g\n", n, v1, fabs ( v1 - v2 ) );

    free ( f );
    free ( x );
  }

  printf ( "\n" );
  printf ( "      Exact: %14.6g\n", v2 );

  return;
}
/******************************************************************************/

void monte_carlo_power_test ( )

/******************************************************************************/
/*
  Purpose:

    MONTE_CARLO_POWER_TEST tests the Monte Carlo rule on the power singular integrand.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2015

  Author:

    John Burkardt
*/
{
  double *f;
  double h;
  int n;
  int nlog;
  int seed;
  double v1;
  double v2;
  double *x;

  printf ( "\n" );
  printf ( "MONTE_CARLO_POWER_TEST\n" );
  printf ( "  Test the Monte Carlo rule on the power singular integrand.\n" );
  printf ( "\n" );
  printf ( "          N        Estimate           Error\n" );
  printf ( "\n" );

  v2 = integral_power ( );

  seed = 123456789;

  n = 17;

  for ( nlog = 5; nlog <= 20; nlog++ )
  {
    n = ( n - 1 ) * 2 + 1;
    h = 1.0 / ( double ) ( n );
    x = r8vec_uniform_01_new ( n, &seed) ;
    f = integrand_power ( n, x );
    v1 = h * r8vec_sum ( n, f );
    printf ( "  %9d  %14.6g  %14.6g\n", n, v1, fabs ( v1 - v2 ) );

    free ( f );
    free ( x );
  }

  printf ( "\n" );
  printf ( "      Exact: %14.6g\n", v2 );

  return;
}
/******************************************************************************/

void monte_carlo_regular_test ( )

/******************************************************************************/
/*
  Purpose:

    MONTE_CARLO_REGULAR_TEST tests the Monte Carlo rule on the regular integrand.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2015

  Author:

    John Burkardt
*/
{
  double *f;
  double h;
  int n;
  int nlog;
  int seed;
  double v1;
  double v2;
  double *x;

  printf ( "\n" );
  printf ( "MONTE_CARLO_REGULAR_TEST\n" );
  printf ( "  Test the Monte Carlo rule on the regular integrand.\n" );
  printf ( "\n" );
  printf ( "          N        Estimate           Error\n" );
  printf ( "\n" );

  v2 = integral_regular ( );

  seed = 123456789;

  n = 17;

  for ( nlog = 5; nlog <= 20; nlog++ )
  {
    n = ( n - 1 ) * 2 + 1;
    h = 1.0 / ( double ) ( n );
    x = r8vec_uniform_01_new ( n, &seed );
    f = integrand_regular ( n, x );
    v1 = h * r8vec_sum ( n, f );
    printf ( "  %9d  %14.6g  %14.6g\n", n, v1, fabs ( v1 - v2 ) );

    free ( f );
    free ( x );
  }

  printf ( "\n" );
  printf ( "      Exact: %14.6g\n", v2 );

  return;
}
/******************************************************************************/

void trapezoid_log_test ( )

/******************************************************************************/
/*
  Purpose:

    TRAPEZOID_LOG_TEST tests the trapezoid rule on the log-singular integrand.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2015

  Author:

    John Burkardt
*/
{
  double *f;
  double h;
  int n;
  int nlog;
  double v1;
  double v2;
  double *x;

  printf ( "\n" );
  printf ( "TRAPEZOID_LOG_TEST\n" );
  printf ( "  Test the trapezoidal rule on the log-singular integrand.\n" );
  printf ( "\n" );
  printf ( "        N        Estimate           Error\n" );
  printf ( "\n" );

  v2 = integral_log ( );

  n = 17;

  for ( nlog = 5; nlog <= 12; nlog++ )
  {
    n = ( n - 1 ) * 2 + 1;
    h = 1.0 / ( double ) ( n - 1 );
    x = r8vec_linspace_new ( n, 0.0, 1.0 );
    x[0] = 0.5 * ( x[0] + x[1] );
    f = integrand_log ( n, x );
    v1 = h * ( r8vec_sum ( n, f ) - 0.5 * ( f[0] + f[n-1] ) );
    printf ( "  %7d  %14.6g  %14.6g\n", n, v1, fabs ( v1 - v2 ) );

    free ( f );
    free ( x );
  }

  printf ( "\n" );
  printf ( "    Exact: %14.6g\n", v2 );

  return;
}
/******************************************************************************/

void trapezoid_power_test ( )

/******************************************************************************/
/*
  Purpose:

    TRAPEZOID_POWER_TEST tests the trapezoid rule on the power-singular integrand.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2015

  Author:

    John Burkardt
*/
{
  double *f;
  double h;
  int n;
  int nlog;
  double v1;
  double v2;
  double *x;

  printf ( "\n" );
  printf ( "TRAPEZOID_POWER_TEST\n" );
  printf ( "  Test the trapezoidal rule on the power-singular integrand.\n" );
  printf ( "\n" );
  printf ( "        N        Estimate           Error\n" );
  printf ( "\n" );

  v2 = integral_power ( );

  n = 17;

  for ( nlog = 5; nlog <= 12; nlog++ )
  {
    n = ( n - 1 ) * 2 + 1;
    h = 1.0 / ( double ) ( n - 1 );
    x = r8vec_linspace_new ( n, 0.0, 1.0 );
    x[0] = 0.5 * ( x[0] + x[1] );
    f = integrand_power ( n, x );
    v1 = h * ( r8vec_sum ( n, f ) - 0.5 * ( f[0] + f[n-1] ) );
    printf ( "  %7d  %14.6g  %14.6g\n", n, v1, fabs ( v1 - v2 ) );

    free ( f );
    free ( x );
  }

  printf ( "\n" );
  printf ( "    Exact: %14.6g\n", v2 );

  return;
}
/******************************************************************************/

void trapezoid_regular_test ( )

/******************************************************************************/
/*
  Purpose:

    TRAPEZOID_REGULAR_TEST tests the trapezoid rule on the regular integrand.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2015

  Author:

    John Burkardt
*/
{
  double *f;
  double h;
  int n;
  int nlog;
  double v1;
  double v2;
  double *x;

  printf ( "\n" );
  printf ( "TRAPEZOID_REGULAR_TEST\n" );
  printf ( "  Test the trapezoidal rule on the regular integrand.\n" );
  printf ( "\n" );
  printf ( "        N        Estimate           Error\n" );
  printf ( "\n" );

  v2 = integral_regular ( );

  n = 17;

  for ( nlog = 5; nlog <= 12; nlog++ )
  {
    n = ( n - 1 ) * 2 + 1;
    h = 1.0 / ( double ) ( n - 1 );
    x = r8vec_linspace_new ( n, 0.0, 1.0 );
    f = integrand_regular ( n, x );
    v1 = h * ( r8vec_sum ( n, f ) - 0.5 * ( f[0] + f[n-1] ) );
    printf ( "  %7d  %14.6g  %14.6g\n", n, v1, fabs ( v1 - v2 ) );

    free ( f );
    free ( x );
  }

  printf ( "\n" );
  printf ( "    Exact: %14.6g\n", v2 );

  return;
}

