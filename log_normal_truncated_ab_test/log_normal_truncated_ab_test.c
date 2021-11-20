# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "log_normal_truncated_ab.h"

int main ( );

void log_normal_truncated_ab_cdf_test ( );
void log_normal_truncated_ab_sample_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for LOG_NORMAL_TRUNCATED_AB_TEST.

  Discussion:

    LOG_NORMAL_TRUNCATED_AB_TEST tests the LOG_NORMAL_TRUNCATED_AB library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 March 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "LOG_NORMAL_TRUNCATED_AB_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the LOG_NORMAL_TRUNCATED_AB library.\n" );

  log_normal_truncated_ab_cdf_test ( );
  log_normal_truncated_ab_sample_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "LOG_NORMAL_TRUNCATED_AB_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void log_normal_truncated_ab_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    LOG_NORMAL_TRUNCATED_AB_CDF_TEST tests LOG_NORMAL_TRUNCATED_AB_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 March 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double mu;
  double pdf;
  int seed = 123456789;
  double sigma;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "LOG_NORMAL_TRUNCATED_AB_CDF_TEST\n" );
  printf ( "  LOG_NORMAL_TRUNCATED_AB_CDF evaluates the Log Normal Truncated AB CDF;\n" );
  printf ( "  LOG_NORMAL_TRUNCATED_AB_CDF_INV inverts the Log Normal Truncated AB CDF.\n" );
  printf ( "  LOG_NORMAL_TRUNCATED_AB_PDF evaluates the Log Normal Truncated AB PDF;\n" );

  mu = 0.5;
  sigma = 3.0;
  a = exp ( mu );
  b = exp ( mu + 2.0 * sigma );

  printf ( "\n" );
  printf ( "  PDF parameter MU =     %g\n", mu );
  printf ( "  PDF parameter SIGMA =  %g\n", sigma );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! log_normal_truncated_ab_check ( mu, sigma, a, b ) )
  {
    printf ( "\n" );
    printf ( "LOG_NORMAL_TRUNCATED_AB_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = log_normal_truncated_ab_sample ( mu, sigma, a, b, &seed );
    pdf = log_normal_truncated_ab_pdf ( x, mu, sigma, a, b );
    cdf = log_normal_truncated_ab_cdf ( x, mu, sigma, a, b );
    x2 = log_normal_truncated_ab_cdf_inv ( cdf, mu, sigma, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void log_normal_truncated_ab_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    LOG_NORMAL_TRUNCATED_AB_SAMPLE_TEST tests LOG_NORMAL_TRUNCATED_AB_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 March 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  double mu;
  int seed = 123456789;
  double sigma;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "LOG_NORMAL_TRUNCATED_AB_SAMPLE_TEST\n" );
  printf ( "  LOG_NORMAL_TRUNCATED_AB_MEAN computes the Log Normal Truncated AB mean;\n" );
  printf ( "  LOG_NORMAL_TRUNCATED_AB_SAMPLE samples the Log Normal Truncated AB distribution;\n" );
  printf ( "  LOG_NORMAL_TRUNCATED_AB_VARIANCE computes the Log Normal Truncated AB variance;\n" );

  mu = 0.5;
  sigma = 3.0;
  a = exp ( mu );
  b = exp ( mu + 2.0 * sigma );

  printf ( "\n" );
  printf ( "  PDF parameter MU =     %g\n", mu );
  printf ( "  PDF parameter SIGMA =  %g\n", sigma );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! log_normal_truncated_ab_check ( mu, sigma, a, b ) )
  {
    printf ( "\n" );
    printf ( "LOG_NORMAL_TRUNCATED_AB_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = log_normal_truncated_ab_mean ( mu, sigma, a, b );
  variance = log_normal_truncated_ab_variance ( mu, sigma, a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = log_normal_truncated_ab_sample ( mu, sigma, a, b, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax     );
  printf ( "  Sample minimum =  %g\n", xmin     );

  return;
# undef SAMPLE_NUM
}
