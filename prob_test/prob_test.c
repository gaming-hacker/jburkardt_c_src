# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "prob.h"

int main ( );

void angle_cdf_test ( );
void angle_mean_test ( );
void angle_pdf_test ( );
void anglit_cdf_test ( );
void anglit_sample_test ( );
void arcsin_cdf_test ( );
void arcsin_sample_test ( );
void benford_cdf_test ( );
void benford_pdf_test ( );
void bernoulli_cdf_test ( );
void bernoulli_sample_test ( );
void bessel_i0_test ( );
void bessel_i1_test ( );
void beta_binomial_cdf_test ( );
void beta_binomial_sample_test ( );
void beta_cdf_test ( );
void beta_inc_test ( );
void beta_sample_test ( );
void binomial_cdf_test ( );
void binomial_sample_test ( );
void birthday_cdf_test ( );
void birthday_sample_test ( );
void bradford_cdf_test ( );
void bradford_sample_test ( );
void buffon_box_pdf_test ( );
void buffon_box_sample_test ( );
void buffon_pdf_test ( );
void buffon_sample_test ( );
void burr_cdf_test ( );
void burr_sample_test ( );
void cardioid_cdf_test ( );
void cardioid_sample_test ( );
void cauchy_cdf_test ( );
void cauchy_sample_test ( );
void chebyshev1_cdf_test ( );
void chebyshev1_sample_test ( );
void chi_cdf_test ( );
void chi_sample_test ( );
void chi_square_cdf_test ( );
void chi_square_sample_test ( );
void chi_square_noncentral_sample_test ( );
void circular_normal_01_sample_test ( );
void circular_normal_sample_test ( );
void cosine_cdf_test ( );
void cosine_sample_test ( );
void coupon_complete_pdf_test ( );
void coupon_sample_test ( );
void deranged_cdf_test ( );
void deranged_sample_test ( );
void dipole_cdf_test ( );
void dipole_sample_test ( );
void dirichlet_sample_test ( );
void dirichlet_pdf_test ( );
void dirichlet_mix_sample_test ( );
void dirichlet_mix_pdf_test ( );
void discrete_cdf_test ( );
void discrete_sample_test ( );
void disk_sample_test ( );
void empirical_discrete_cdf_test ( );
void empirical_discrete_sample_test ( );
void english_letter_cdf_test ( );
void english_sentence_length_cdf_test ( );
void english_sentence_length_sample_test ( );
void english_word_length_cdf_test ( );
void english_word_length_sample_test ( );
void erlang_cdf_test ( );
void erlang_sample_test ( );
void exponential_cdf_test ( );
void exponential_sample_test ( );
void exponential_01_cdf_test ( );
void exponential_01_sample_test ( );
void extreme_values_cdf_test ( );
void extreme_values_sample_test ( );
void f_cdf_test ( );
void f_sample_test ( );
void fermi_dirac_sample_test ( );
void fisher_pdf_test ( );
void fisk_cdf_test ( );
void fisk_sample_test ( );
void folded_normal_cdf_test ( );
void folded_normal_sample_test ( );
void frechet_cdf_test ( );
void frechet_sample_test ( );
void gamma_cdf_test ( );
void gamma_sample_test ( );
void genlogistic_cdf_test ( );
void genlogistic_sample_test ( );
void geometric_cdf_test ( );
void geometric_sample_test ( );
void gompertz_cdf_test ( );
void gompertz_sample_test ( );
void gumbel_cdf_test ( );
void gumbel_sample_test ( );
void half_normal_cdf_test ( );
void half_normal_sample_test ( );
void hypergeometric_cdf_test ( );
void hypergeometric_sample_test ( );
void i4_choose_test ( );
void i4_choose_log_test ( );
void i4_is_power_of_10_test ( );
void i4_uniform_ab_test ( );
void i4vec_uniform_ab_new_test ( );
void i4vec_unique_count_test ( );
void inverse_gaussian_cdf_test ( );
void inverse_gaussian_sample_test ( );
void laplace_cdf_test ( );
void laplace_sample_test ( );
void levy_cdf_test ( );
void logistic_cdf_test ( );
void logistic_sample_test ( );
void log_normal_cdf_test ( );
void log_normal_sample_test ( );
void log_series_cdf_test ( );
void log_series_sample_test ( );
void log_uniform_cdf_test ( );
void log_uniform_sample_test ( );
void lorentz_cdf_test ( );
void lorentz_sample_test ( );
void maxwell_cdf_test ( );
void maxwell_sample_test ( );
void multinomial_coef_test ( );
void multinomial_pdf_test ( );
void multinomial_sample_test ( );
void multinoulli_pdf_test ( );
void nakagami_cdf_test ( );
void nakagami_sample_test ( );
void negative_binomial_cdf_test ( );
void negative_binomial_sample_test ( );
void normal_01_cdf_test ( );
void normal_01_sample_test ( );
void normal_cdf_test ( );
void normal_sample_test ( );
void normal_truncated_ab_cdf_test ( );
void normal_truncated_ab_sample_test ( );
void normal_truncated_a_cdf_test ( );
void normal_truncated_a_sample_test ( );
void normal_truncated_b_cdf_test ( );
void normal_truncated_b_sample_test ( );
void pareto_cdf_test ( );
void pareto_sample_test ( );
void pearson_05_pdf_test ( );
void planck_pdf_test ( );
void planck_sample_test ( );
void poisson_cdf_test ( );
void poisson_sample_test ( );
void power_cdf_test ( );
void power_sample_test ( );
void quasigeometric_cdf_test ( );
void quasigeometric_sample_test ( );
void r8_beta_test ( );
void r8_ceiling_test ( );
void r8_error_f_test ( );
void r8_factorial_test ( );
void r8_gamma_inc_test ( );
void r8_gamma_log_int_test ( );
void r8_uniform_01_test ( );
void r8_zeta_test ( );
void rayleigh_cdf_test ( );
void rayleigh_sample_test ( );
void reciprocal_cdf_test ( );
void reciprocal_sample_test ( );
void runs_pdf_test ( );
void runs_sample_test ( );
void sech_cdf_test ( );
void sech_sample_test ( );
void semicircular_cdf_test ( );
void semicircular_sample_test ( );
void student_cdf_test ( );
void student_sample_test ( );
void student_noncentral_cdf_test ( );
void tfn_test ( );
void triangle_cdf_test ( );
void triangle_sample_test ( );
void triangular_cdf_test ( );
void triangular_sample_test ( );
void uniform_01_cdf_test ( );
void uniform_01_order_sample_test ( );
void uniform_01_sample_test ( );
void uniform_cdf_test ( );
void uniform_nsphere_sample_test ( );
void uniform_sample_test ( );
void uniform_discrete_cdf_test ( );
void uniform_discrete_sample_test ( );
void von_mises_cdf_test ( );
void von_mises_sample_test ( );
void weibull_cdf_test ( );
void weibull_sample_test ( );
void weibull_discrete_cdf_test ( );
void weibull_discrete_sample_test ( );
void zipf_cdf_test ( );
void zipf_sample_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for PROB_TEST.

  Discussion:

    PROB_TEST tests the PROB library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 September 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "PROB_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the PROB library.\n" );

  angle_cdf_test ( );
  angle_mean_test ( );
  angle_pdf_test ( );

  anglit_cdf_test ( );
  anglit_sample_test ( );

  arcsin_cdf_test ( );
  arcsin_sample_test ( );

  benford_cdf_test ( );
  benford_pdf_test ( );

  bernoulli_cdf_test ( );
  bernoulli_sample_test ( );

  bessel_i0_test ( );
  bessel_i1_test ( );

  beta_binomial_cdf_test ( );
  beta_binomial_sample_test ( );

  beta_cdf_test ( );
  beta_inc_test ( );
  beta_sample_test ( );

  binomial_cdf_test ( );
  binomial_sample_test ( );

  birthday_cdf_test ( );
  birthday_sample_test ( );

  bradford_cdf_test ( );
  bradford_sample_test ( );

  buffon_box_pdf_test ( );
  buffon_box_sample_test ( );

  buffon_pdf_test ( );
  buffon_sample_test ( );

  burr_cdf_test ( );
  burr_sample_test ( );

  cardioid_cdf_test ( );
  cardioid_sample_test ( );

  cauchy_cdf_test ( );
  cauchy_sample_test ( );

  chebyshev1_cdf_test ( );
  chebyshev1_sample_test ( );

  chi_cdf_test ( );
  chi_sample_test ( );

  chi_square_cdf_test ( );
  chi_square_sample_test ( );

  chi_square_noncentral_sample_test ( );

  circular_normal_01_sample_test ( );
  circular_normal_sample_test ( );

  cosine_cdf_test ( );
  cosine_sample_test ( );

  coupon_complete_pdf_test ( );
  coupon_sample_test ( );

  deranged_cdf_test ( );
  deranged_sample_test ( );

  dipole_cdf_test ( );
  dipole_sample_test ( );

  dirichlet_sample_test ( );
  dirichlet_pdf_test ( );

  dirichlet_mix_sample_test ( );
  dirichlet_mix_pdf_test ( );

  discrete_cdf_test ( );
  discrete_sample_test ( );
  disk_sample_test ( );
  empirical_discrete_cdf_test ( );
  empirical_discrete_sample_test ( );
  english_letter_cdf_test ( );
  english_sentence_length_cdf_test ( );
  english_sentence_length_sample_test ( );
  english_word_length_cdf_test ( );
  english_word_length_sample_test ( );
  erlang_cdf_test ( );
  erlang_sample_test ( );
  exponential_cdf_test ( );
  exponential_sample_test ( );
  exponential_01_cdf_test ( );
  exponential_01_sample_test ( );
  extreme_values_cdf_test ( );
  extreme_values_sample_test ( );
  f_cdf_test ( );
  f_sample_test ( );
  fermi_dirac_sample_test ( );
  fisher_pdf_test ( );
  fisk_cdf_test ( );
  fisk_sample_test ( );
  folded_normal_cdf_test ( );
  folded_normal_sample_test ( );
  frechet_cdf_test ( );
  frechet_sample_test ( );
  gamma_cdf_test ( );
  gamma_sample_test ( );
  genlogistic_cdf_test ( );
  genlogistic_sample_test ( );
  geometric_cdf_test ( );
  geometric_sample_test ( );
  gompertz_cdf_test ( );
  gompertz_sample_test ( );
  gumbel_cdf_test ( );
  gumbel_sample_test ( );
  half_normal_cdf_test ( );
  half_normal_sample_test ( );
  hypergeometric_cdf_test ( );
  hypergeometric_sample_test ( );
  i4_choose_test ( );
  i4_choose_log_test ( );
  i4_is_power_of_10_test ( );
  i4_uniform_ab_test ( );
  i4vec_uniform_ab_new_test ( );
  i4vec_unique_count_test ( );
  inverse_gaussian_cdf_test ( );
  inverse_gaussian_sample_test ( );
  laplace_cdf_test ( );
  laplace_sample_test ( );
  levy_cdf_test ( );
  logistic_cdf_test ( );
  logistic_sample_test ( );
  log_normal_cdf_test ( );
  log_normal_sample_test ( );
  log_series_cdf_test ( );
  log_series_sample_test ( );
  log_uniform_cdf_test ( );
  log_uniform_sample_test ( );
  lorentz_cdf_test ( );
  lorentz_sample_test ( );
  maxwell_cdf_test ( );
  maxwell_sample_test ( );
  multinomial_coef_test ( );
  multinomial_pdf_test ( );
  multinomial_sample_test ( );
  multinoulli_pdf_test ( );
  nakagami_cdf_test ( );
  nakagami_sample_test ( );
  negative_binomial_cdf_test ( );
  negative_binomial_sample_test ( );
  normal_01_cdf_test ( );
  normal_01_sample_test ( );
  normal_cdf_test ( );
  normal_sample_test ( );
  normal_truncated_ab_cdf_test ( );
  normal_truncated_ab_sample_test ( );
  normal_truncated_a_cdf_test ( );
  normal_truncated_a_sample_test ( );
  normal_truncated_b_cdf_test ( );
  normal_truncated_b_sample_test ( );
  pareto_cdf_test ( );
  pareto_sample_test ( );
  pearson_05_pdf_test ( );
  planck_pdf_test ( );
  planck_sample_test ( );
  poisson_cdf_test ( );
  poisson_sample_test ( );
  power_cdf_test ( );
  power_sample_test ( );
  quasigeometric_cdf_test ( );
  quasigeometric_sample_test ( );
  r8_beta_test ( );
  r8_ceiling_test ( );
  r8_error_f_test ( );
  r8_factorial_test ( );
  r8_gamma_inc_test ( );
  r8_gamma_log_int_test ( );
  r8_uniform_01_test ( );
  r8_zeta_test ( );
  rayleigh_cdf_test ( );
  rayleigh_sample_test ( );
  reciprocal_cdf_test ( );
  reciprocal_sample_test ( );
  runs_pdf_test ( );
  runs_sample_test ( );
  sech_cdf_test ( );
  sech_sample_test ( );
  semicircular_cdf_test ( );
  semicircular_sample_test ( );
  student_cdf_test ( );
  student_sample_test ( );
  student_noncentral_cdf_test ( );
  tfn_test ( );
  triangle_cdf_test ( );
  triangle_sample_test ( );
  triangular_cdf_test ( );
  triangular_sample_test ( );
  uniform_01_cdf_test ( );
  uniform_01_order_sample_test ( );
  uniform_01_sample_test ( );
  uniform_cdf_test ( );
  uniform_nsphere_sample_test ( );
  uniform_sample_test ( );
  uniform_discrete_cdf_test ( );
  uniform_discrete_sample_test ( );
  von_mises_cdf_test ( );
  von_mises_sample_test ( );
  weibull_cdf_test ( );
  weibull_sample_test ( );
  weibull_discrete_cdf_test ( );
  weibull_discrete_sample_test ( );
  zipf_cdf_test ( );
  zipf_sample_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "PROB_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void angle_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    ANGLE_CDF_TEST tests ANGLE_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 June 2013

  Author:

    John Burkardt
*/
{
  double cdf;
  int n;
  double x;

  printf ( "\n" );
  printf ( "ANGLE_CDF_TEST\n" );
  printf ( "  ANGLE_CDF evaluates the Angle CDF;\n" );

  n = 5;
  x = 0.50E+00;

  cdf = angle_cdf ( x, n );

  printf ( "\n" );
  printf ( "  Parameter N =     %d\n", n );
  printf ( "  PDF argument X =  %g\n", x );
  printf ( "  CDF value =       %g\n", cdf );

  return;
}
/******************************************************************************/

void angle_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    ANGLE_PDF_TEST tests ANGLE_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 June 2013

  Author:

    John Burkardt
*/
{
  int n;
  double pdf;
  double x;

  printf ( "\n" );
  printf ( "ANGLE_PDF_TEST\n" );
  printf ( "  ANGLE_PDF evaluates the Angle PDF;\n" );

  n = 5;
  x = 0.50E+00;

  pdf = angle_pdf ( x, n );

  printf ( "\n" );
  printf ( "  Parameter N =    %d\n", n );
  printf ( "  PDF argument X = %g\n", x );
  printf ( "  PDF value =      %g\n", pdf );

  return;
}
/******************************************************************************/

void angle_mean_test ( )

/******************************************************************************/
/*
  Purpose:

    ANGLE_MEAN_TEST tests ANGLE_MEAN;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 June 2013

  Author:

    John Burkardt
*/
{
  double mean;
  int n;

  printf ( "\n" );
  printf ( "ANGLE_MEAN_TEST\n" );
  printf ( "  ANGLE_MEAN computes the Angle mean;\n" );

  n = 5;
  mean = angle_mean ( n );

  printf ( "\n" );
  printf ( "  Parameter N = %d\n", n );
  printf ( "  PDF mean =    %g\n", mean );

  return;
}
/******************************************************************************/

void anglit_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    ANGLIT_CDF_TEST tests ANGLIT_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 August 2013

  Author:

    John Burkardt
*/
{
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "ANGLIT_CDF_TEST\n" );
  printf ( "  ANGLIT_CDF evaluates the Anglit CDF;\n" );
  printf ( "  ANGLIT_CDF_INV inverts the Anglit CDF.\n" );
  printf ( "  ANGLIT_PDF evaluates the Anglit PDF;\n" );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = anglit_sample ( &seed );
    pdf = anglit_pdf ( x );
    cdf = anglit_cdf ( x );
    x2 = anglit_cdf_inv ( cdf );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void anglit_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    ANGLIT_SAMPLE_TEST tests ANGLIT_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 August 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "ANGLIT_SAMPLE_TEST\n" );
  printf ( "  ANGLIT_MEAN computes the Anglit mean;\n" );
  printf ( "  ANGLIT_SAMPLE samples the Anglit distribution;\n" );
  printf ( "  ANGLIT_VARIANCE computes the Anglit variance.\n" );

  mean     = anglit_mean ( );
  variance = anglit_variance ( );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = anglit_sample ( &seed );
  }

  mean     = r8vec_mean     ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax     = r8vec_max      ( SAMPLE_NUM, x );
  xmin     = r8vec_min      ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void arcsin_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    ARCSIN_CDF_TEST tests ARCSIN_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 August 2013

  Author:

    John Burkardt
*/
{
  double a;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "ARCSIN_CDF_TEST\n" );
  printf ( "  ARCSIN_CDF evaluates the Arcsin CDF;\n" );
  printf ( "  ARCSIN_CDF_INV inverts the Arcsin CDF.\n" );
  printf ( "  ARCSIN_PDF evaluates the Arcsin PDF;\n" );

  a = 1.0E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a );

  if ( ! arcsin_check ( a ) )
  {
    printf ( "\n" );
    printf ( "ARCSIN_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = arcsin_sample ( a, &seed );
    pdf = arcsin_pdf ( x, a );
    cdf = arcsin_cdf ( x, a );
    x2 = arcsin_cdf_inv ( cdf, a );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void arcsin_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    ARCSIN_SAMPLE_TEST tests ARCSIN_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  int i;
  int j;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "ARCSIN_SAMPLE_TEST\n" );
  printf ( "  ARCSIN_MEAN computes the Arcsin mean;\n" );
  printf ( "  ARCSIN_SAMPLE samples the Arcsin distribution;\n" );
  printf ( "  ARCSIN_VARIANCE computes the Arcsin variance.\n" );

  for ( i = 1; i <= 2; i++ )
  {
    if ( i == 1 )
    {
      a = 1.0;
    }
    else if ( i == 2 )
    {
      a = 16.0;
    }

    printf ( "\n" );
    printf ( "  PDF parameter A =             %g\n", a );

    if ( ! arcsin_check ( a ) )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "ARCSIN_SAMPLE_TEST - Fatal error!\n" );
      fprintf ( stderr, "  The parameters are not legal.\n" );
      return;
    }

    mean = arcsin_mean ( a );
    variance = arcsin_variance ( a );

    printf ( "  PDF mean =                    %g\n", mean );
    printf ( "  PDF variance =                %g\n", variance );

    for ( j = 0; j < SAMPLE_NUM; j++ )
    {
      x[j] = arcsin_sample ( a, &seed );
    }

    mean = r8vec_mean ( SAMPLE_NUM, x );
    variance = r8vec_variance ( SAMPLE_NUM, x );
    xmax = r8vec_max ( SAMPLE_NUM, x );
    xmin = r8vec_min ( SAMPLE_NUM, x );

    printf ( "\n" );
    printf ( "  Sample size =     %d\n", SAMPLE_NUM );
    printf ( "  Sample mean =     %g\n", mean );
    printf ( "  Sample variance = %g\n", variance );
    printf ( "  Sample maximum =  %g\n", xmax );
    printf ( "  Sample minimum =  %g\n", xmin );
  }

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void benford_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    BENFORD_CDF_TEST tests BENFORD_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 March 2016

  Author:

    John Burkardt
*/
{
  double cdf;
  double cdf2;
  int n;
  double pdf;

  printf ( "\n" );
  printf ( "BENFORD_CDF_TEST\n" );
  printf ( "  BENFORD_CDF evaluates the Benford CDF.\n" );

  printf ( "\n" );
  printf ( "       N          CDF(N)          CDF(N) by summing\n" );
  printf ( "\n" );

  cdf2 = 0.0;
  for ( n = 1; n <= 9; n++ )
  {
    cdf = benford_cdf ( n );
    pdf = benford_pdf ( n );
    cdf2 = cdf2 + pdf;
    printf ( "  %6d  %14g  %14g\n", n, cdf, cdf2 );
  }

  printf ( "\n" );
  printf ( "       N          CDF(N)          CDF(N) by summing\n" );
  printf ( "\n" );

  cdf2 = 0.0;
  for ( n = 10; n <= 99; n++ )
  {
    cdf = benford_cdf ( n );
    pdf = benford_pdf ( n );
    cdf2 = cdf2 + pdf;
    printf ( "  %6d  %14g  %14g\n", n, cdf, cdf2 );
  }

  return;
}
/******************************************************************************/

void benford_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    BENFORD_PDF_TEST tests BENFORD_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 March 2016

  Author:

    John Burkardt
*/
{
  int n;
  double pdf;

  printf ( "\n" );
  printf ( "BENFORD_PDF_TEST\n" );
  printf ( "  BENFORD_PDF evaluates the Benford PDF.\n" );

  printf ( "\n" );
  printf ( "       N          PDF(N)\n" );
  printf ( "\n" );

  for ( n = 1; n <= 9; n++ )
  {
    pdf = benford_pdf ( n );
    printf ( "  %6d  %14g\n", n, pdf );
  }

  printf ( "\n" );
  printf ( "       N          PDF(N)\n" );
  printf ( "\n" );

  for ( n = 10; n <= 99; n++ )
  {
    pdf = benford_pdf ( n );
    printf ( "  %6d  %14g\n", n, pdf );
  }

  return;
}
/******************************************************************************/

void bernoulli_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNOULLI_CDF_TEST tests BERNOULLI_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2013

  Author:

    John Burkardt
*/
{
  double a;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "BERNOULLI_CDF_TEST\n" );
  printf ( "  BERNOULLI_CDF evaluates the Bernoulli CDF;\n" );
  printf ( "  BERNOULLI_CDF_INV inverts the Bernoulli CDF;\n" );
  printf ( "  BERNOULLI_PDF evaluates the Bernoulli PDF.\n" );

  a = 0.75E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a );

  if ( ! bernoulli_check ( a ) )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "BERNOULLI_CDF_TEST - Fatal error!\n" );
    fprintf ( stderr, "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = bernoulli_sample ( a, &seed );
    pdf = bernoulli_pdf ( x, a );
    cdf = bernoulli_cdf ( x, a );
    x2 = bernoulli_cdf_inv ( cdf, a );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void bernoulli_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    BERNOULLI_SAMPLE_TEST tests BERNOULLI_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "BERNOULLI_SAMPLE_TEST\n" );
  printf ( "  BERNOULLI_MEAN computes the Bernoulli mean;\n" );
  printf ( "  BERNOULLI_SAMPLE samples the Bernoulli distribution;\n" );
  printf ( "  BERNOULLI_VARIANCE computes the Bernoulli variance.\n" );

  a = 0.75E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a );

  if ( ! bernoulli_check ( a ) )
  {
    printf ( "\n" );
    printf ( "BERNOULLI_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = bernoulli_mean ( a );
  variance = bernoulli_variance ( a );

  printf ( "  PDF mean =                    %g\n", mean );
  printf ( "  PDF variance =                %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = bernoulli_sample ( a, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax );
  printf ( "  Sample minimum =  %d\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void bessel_i0_test ( )

/******************************************************************************/
/*
  Purpose:

    BESSEL_I0_TEST tests BESSEL_I0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2013

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "BESSEL_I0_TEST:\n" );
  printf ( "  BESSEL_I0 evaluates the Bessel function of the\n" );
  printf ( "  first kind and order 0;\n" );
  printf ( "\n" );
  printf ( "      X       Exact F       BESSEL_I0(X)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_i0_values ( &n_data, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = bessel_i0 ( x );

    printf ( "  %8g  %16g  %16g\n", x, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void bessel_i1_test ( )

/******************************************************************************/
/*
  Purpose:

    BESSEL_I1_TEST tests BESSEL_I1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2013

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "BESSEL_I1_TEST:\n" );
  printf ( "  BESSEL_I1 evaluates the Bessel function of the\n" );
  printf ( "  first kind and order 1;\n" );
  printf ( "\n" );
  printf ( "      X       Exact F       BESSEL_I1(X)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_i1_values ( &n_data, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = bessel_i1 ( x );

    printf ( "  %8g  %16g  %16g\n", x, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void beta_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    BETA_CDF_TEST tests BETA_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 August 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "BETA_CDF_TEST\n" );
  printf ( "  BETA_CDF evaluates the Beta CDF;\n" );
  printf ( "  BETA_CDF_INV inverts the Beta CDF.\n" );
  printf ( "  BETA_PDF evaluates the Beta PDF;\n" );

  a = 12.0;
  b = 12.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! beta_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "BETA_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "             A             B        X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = beta_sample ( a, b, &seed );
    pdf = beta_pdf ( x, a, b );
    cdf = beta_cdf ( x, a, b );
    x2 = beta_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g  %12g  %12g\n", a, b, x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void beta_inc_test ( )

/******************************************************************************/
/*
  Purpose:

    BETA_INC_TEST tests BETA_INC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 August 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double fx;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "BETA_INC_TEST:\n" );
  printf ( "  BETA_INC evaluates the normalized incomplete Beta\n" );
  printf ( "  function BETA_INC(A,B,X).\n" );
  printf ( "\n" );
  printf ( "         A         B         X       Exact F       BETA_INC(A,B,X)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    beta_inc_values ( &n_data, &a, &b, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = beta_inc ( a, b, x );

    printf ( "  %8g  %8g  %8g  %16g  %16g\n", a, b, x, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void beta_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    BETA_SAMPLE_TEST tests BETA_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "BETA_SAMPLE_TEST\n" );
  printf ( "  BETA_MEAN computes the Beta mean;\n" );
  printf ( "  BETA_SAMPLE Beta samples;\n" );
  printf ( "  BETA_VARIANCE computes the Beta variance;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! beta_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "BETA_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = beta_mean ( a, b );
  variance = beta_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = beta_sample ( a, b, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void beta_binomial_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    BETA_BINOMIAL_CDF_TEST tests BETA_BINOMIAL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int c;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "BETA_BINOMIAL_CDF_TEST\n" );
  printf ( "  BETA_BINOMIAL_CDF evaluates the Beta Binomial CDF;\n" );
  printf ( "  BETA_BINOMIAL_CDF_INV inverts the Beta Binomial CDF.\n" );
  printf ( "  BETA_BINOMIAL_PDF evaluates the Beta Binomial PDF;\n" );

  a = 2.0;
  b = 3.0;
  c = 4;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %d\n", c );

  if ( ! beta_binomial_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "BETA_BINOMIAL_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = beta_binomial_sample ( a, b, c, &seed );
    pdf = beta_binomial_pdf ( x, a, b, c );
    cdf = beta_binomial_cdf ( x, a, b, c );
    x2 = beta_binomial_cdf_inv ( cdf, a, b, c );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void beta_binomial_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    BETA_BINOMIAL_SAMPLE_TEST tests BETA_BINOMIAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 August 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int c;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "BETA_BINOMIAL_SAMPLE_TEST\n" );
  printf ( "  BETA_BINOMIAL_MEAN computes the Beta Binomial mean;\n" );
  printf ( "  BETA_BINOMIAL_SAMPLE samples the Beta Binomial distribution\n" );
  printf ( "  BETA_BINOMIAL_VARIANCE computes the Beta Binomial variance;\n" );

  a = 2.0;
  b = 3.0;
  c = 4;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %d\n", c );

  if ( ! beta_binomial_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "BETA_BINOMIAL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = beta_binomial_mean ( a, b, c );
  variance = beta_binomial_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = beta_binomial_sample ( a, b, c, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax );
  printf ( "  Sample minimum =  %d\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void binomial_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    BINOMIAL_CDF_TEST tests BINOMIAL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 September 2013

  Author:

    John Burkardt
*/
{
  int a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "BINOMIAL_CDF_TEST\n" );
  printf ( "  BINOMIAL_CDF evaluates the Binomial CDF;\n" );
  printf ( "  BINOMIAL_CDF_INV inverts the Binomial CDF.\n" );
  printf ( "  BINOMIAL_PDF evaluates the Binomial PDF;\n" );

  a = 5;
  b = 0.65;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %d\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! binomial_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "BINOMIAL_CDF_TEST - Warning!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = binomial_sample ( a, b, &seed );
    pdf = binomial_pdf ( x, a, b );
    cdf = binomial_cdf ( x, a, b );
    x2 = binomial_cdf_inv ( cdf, a, b );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void binomial_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    BINOMIAL_SAMPLE_TEST tests BINOMIAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "BINOMIAL_SAMPLE_TEST\n" );
  printf ( "  BINOMIAL_MEAN computes the Binomial mean;\n" );
  printf ( "  BINOMIAL_SAMPLE samples the Binomial distribution;\n" );
  printf ( "  BINOMIAL_VARIANCE computes the Binomial variance;\n" );

  a = 5;
  b = 0.30;

  printf ( "\n" );
  printf ( "  PDF parameter A = %d\n", a );
  printf ( "  PDF parameter B = %g\n", b );

  if ( ! binomial_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "BINOMIAL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = binomial_mean ( a, b );
  variance = binomial_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = binomial_sample ( a, b, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax );
  printf ( "  Sample minimum =  %d\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void birthday_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    BIRTHDAY_CDF_TEST tests BIRTHDAY_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 March 2016

  Author:

    John Burkardt
*/
{
  double cdf;
  int n;
  int n2;
  double pdf;

  printf ( "\n" );
  printf ( "BIRTHDAY_CDF_TEST\n" );
  printf ( "  BIRTHDAY_CDF evaluates the Birthday CDF;\n" );
  printf ( "  BIRTHDAY_CDF_INV inverts the Birthday CDF.\n" );
  printf ( "  BIRTHDAY_PDF evaluates the Birthday PDF;\n" );

  printf ( "\n" );
  printf ( "       N            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( n = 1; n <= 30; n++ )
  {
    pdf = birthday_pdf ( n );

    cdf = birthday_cdf ( n );

    n2 = birthday_cdf_inv ( cdf );

    printf ( "  %8d  %14g  %14g  %8d\n", n, pdf, cdf, n2 );
  }
  return;
}
/******************************************************************************/

void birthday_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    BIRTHDAY_SAMPLE_TEST tests BIRTHDAY_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 March 2016

  Author:

    John Burkardt
*/
{
  int i;
  double mean;
  int n;
  int nsample = 10000;
  double pdf;
  int seed;
  int x[nsample];

  seed = 12345678;

  printf ( "\n" );
  printf ( "BIRTHDAY_SAMPLE_TEST\n" );
  printf ( "  BIRTHDAY_SAMPLE samples the Birthday distribution.\n" );
  printf ( "\n" );
  printf ( "   N            Mean           PDF\n" );
  printf ( "\n" );

  for ( n = 10; n <= 40; n++ )
  {
    for ( i = 0; i < nsample; i++ )
    {
      x[i] = birthday_sample ( n, &seed );
    }
    mean = i4vec_mean ( nsample, x );
    pdf = birthday_pdf ( n );
    printf ( "  %2d  %14.6g  %14.6g\n", n, mean, pdf );
  }

  return;
}
/******************************************************************************/

void bradford_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    BRADFORD_CDF_TEST tests BRADFORD_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "BRADFORD_CDF_TEST\n" );
  printf ( "  BRADFORD_CDF evaluates the Bradford CDF;\n" );
  printf ( "  BRADFORD_CDF_INV inverts the Bradford CDF.\n" );
  printf ( "  BRADFORD_PDF evaluates the Bradford PDF;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! bradford_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "BRADFORD_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = bradford_sample ( a, b, c, &seed );
    pdf = bradford_pdf ( x, a, b, c );
    cdf = bradford_cdf ( x, a, b, c );
    x2 = bradford_cdf_inv ( cdf, a, b, c );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void bradford_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    BRADFORD_SAMPLE_TEST tests BRADFORD_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  double c;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "BRADFORD_SAMPLE_TEST\n" );
  printf ( "  BRADFORD_MEAN computes the Bradford mean;\n" );
  printf ( "  BRADFORD_SAMPLE samples the Bradford distribution;\n" );
  printf ( "  BRADFORD_VARIANCE computes the Bradford variance;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! bradford_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "BRADFORD_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = bradford_mean ( a, b, c );
  variance = bradford_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = bradford_sample ( a, b, c, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void buffon_box_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    BUFFON_BOX_PDF_TEST tests BUFFON_BOX_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int i;
  int j;
  int k;
  double l;
  double pdf;

  printf ( "\n" );
  printf ( "BUFFON_BOX_PDF_TEST\n" );
  printf ( "  BUFFON_BOX_PDF evaluates the Buffon-Laplace PDF, the probability\n" );
  printf ( "  that, on a grid of cells of width A and height B,\n" );
  printf ( "  a needle of length L, dropped at random, will cross\n" );
  printf ( "  at least one grid line.\n" );
  printf ( "\n" );
  printf ( "      A         B         L        PDF\n" );
  printf ( "\n" );

  for ( i = 1; i <= 5; i++ )
  {
    a = ( double ) ( i );
    for ( j = 1; j <= 5; j++ )
    {
      b = ( double ) ( j );
      for ( k = 0; k <= 5; k++ )
      {
        l = ( double ) ( k ) * r8_min ( a, b ) / 5.0;
        pdf = buffon_box_pdf ( a, b, l );
        printf ( "  %8g  %8g  %8g  %14g\n", a, b, l, pdf  );
      }
      printf ( "\n" );
    }
  }
  return;
}
/******************************************************************************/

void buffon_box_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    BUFFON_BOX_SAMPLE_TEST tests BUFFON_BOX_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 September 2013

  Author:

    John Burkardt
*/
{
# define TEST_NUM 4

  double a;
  double b;
  double err;
  int hits;
  double l;
  double pi = 3.141592653589793238462643;
  double pi_est;
  const double r8_huge = 1.0E+30;
  int test;
  int trial_num;
  int trial_num_test[TEST_NUM] = { 10, 100, 10000, 1000000 };

  a = 1.0;
  b = 1.0;
  l = 1.0;

  printf ( "\n" );
  printf ( "BUFFON_BOX_SAMPLE_TEST\n" );
  printf ( "  BUFFON_BOX_SAMPLE simulates a Buffon-Laplace needle dropping\n" );
  printf ( "  experiment.  On a grid of cells of width A and height B,\n" );
  printf ( "  a needle of length L is dropped at random.  We count\n" );
  printf ( "  the number of times it crosses at least one grid line,\n" );
  printf ( "  and use this to estimate the value of PI.\n" );

  printf ( "\n" );
  printf ( "  Cell width A =    %g\n", a );
  printf ( "  Cell height B =   %g\n", b );
  printf ( "  Needle length L = %g\n", l );
  printf ( "\n" );
  printf ( "    Trials      Hits          Est(Pi)     Err\n" );
  printf ( "\n" );

  for ( test = 0; test < TEST_NUM; test++ )
  {
    trial_num = trial_num_test[test];

    hits = buffon_box_sample ( a, b, l, trial_num );

    if ( 0 < hits )
    {
      pi_est = ( 2.0 * l * ( a + b ) - l * l ) * ( double ) trial_num
        / ( a * b * ( double ) hits );
    }
    else
    {
      pi_est = r8_huge;
    }

    err = fabs ( pi_est - pi );

    printf ( "  %8d  %8d  %14g  %14g\n", trial_num, hits, pi_est, err );
  }
  return;
# undef TEST_NUM
}
/******************************************************************************/

void buffon_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    BUFFON_PDF_TEST tests BUFFON_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  int i;
  int k;
  double l;
  double pdf;

  printf ( "\n" );
  printf ( "BUFFON_PDF_TEST\n" );
  printf ( "  BUFFON_PDF evaluates the Buffon PDF, the probability\n" );
  printf ( "  that, on a grid of cells of width A,\n" );
  printf ( "  a needle of length L, dropped at random, will cross\n" );
  printf ( "  at least one grid line.\n" );
  printf ( "\n" );
  printf ( "      A         L        PDF\n" );
  printf ( "\n" );

  for ( i = 1; i <= 5; i++ )
  {
    a = ( double ) ( i );
    for ( k = 0; k <= 5; k++ )
    {
      l = ( double ) ( k ) * a / 5.0;
      pdf = buffon_pdf ( a, l );
      printf ( "  %8g  %8g  %14g\n", a, l, pdf );
    }
    printf ( "\n" );
  }
  return;
}
/******************************************************************************/

void buffon_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    BUFFON_SAMPLE_TEST tests BUFFON_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 September 2013

  Author:

    John Burkardt
*/
{
# define TEST_NUM 4

  double a;
  double err;
  int hits;
  double l;
  double pi = 3.141592653589793238462643;
  double pi_est;
  const double r8_huge = 1.0E+30;
  int test;
  int trial_num;
  int trial_num_test[TEST_NUM] = { 10, 100, 10000, 1000000 };

  a = 1.0;
  l = 1.0;

  printf ( "\n" );
  printf ( "BUFFON_SAMPLE_TEST\n" );
  printf ( "  BUFFON_SAMPLE simulates a Buffon needle dropping\n" );
  printf ( "  experiment.  On a grid of cells of width A,\n" );
  printf ( "  a needle of length L is dropped at random.  We count\n" );
  printf ( "  the number of times it crosses at least one grid line,\n" );
  printf ( "  and use this to estimate the value of PI.\n" );

  printf ( "\n" );
  printf ( "  Cell width A =    %g\n", a );
  printf ( "  Needle length L = %g\n", l );
  printf ( "\n" );
  printf ( "    Trials      Hits          Est(Pi)     Err\n" );
  printf ( "\n" );

  for ( test = 0; test < TEST_NUM; test++ )
  {
    trial_num = trial_num_test[test];

    hits = buffon_sample ( a, l, trial_num );

    if ( 0 < hits )
    {
      pi_est = ( 2.0 * l * ( double ) trial_num ) / ( a * ( double ) hits );
    }
    else
    {
      pi_est = r8_huge;
    }

    err = fabs ( pi_est - pi );

    printf ( "  %8d  %8d  %14g  %14g\n", trial_num, hits, pi_est, err );
  }
  return;
# undef TEST_NUM
}
/******************************************************************************/

void burr_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    BURR_CDF_TEST tests BURR_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2006

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double cdf;
  double d;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "BURR_CDF_TEST\n" );
  printf ( "  BURR_CDF evaluates the Burr CDF;\n" );
  printf ( "  BURR_CDF_INV inverts the Burr CDF.\n" );
  printf ( "  BURR_PDF evaluates the Burr PDF;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;
  d = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );
  printf ( "  PDF parameter D =      %g\n", d );

  if ( ! burr_check ( a, b, c, d ) )
  {
    printf ( "\n" );
    printf ( "BURR_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = burr_sample ( a, b, c, d, &seed );
    pdf = burr_pdf ( x, a, b, c, d );
    cdf = burr_cdf ( x, a, b, c, d );
    x2 = burr_cdf_inv ( cdf, a, b, c, d );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void burr_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    BURR_SAMPLE_TEST tests BURR_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  double c;
  double d;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "BURR_SAMPLE_TEST\n" );
  printf ( "  BURR_MEAN computes the Burr mean;\n" );
  printf ( "  BURR_SAMPLE samples the Burr distribution;\n" );
  printf ( "  BURR_VARIANCE computes the Burr variance;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;
  d = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );
  printf ( "  PDF parameter D =      %g\n", d );

  if ( ! burr_check ( a, b, c, d ) )
  {
    printf ( "\n" );
    printf ( "BURR_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = burr_mean ( a, b, c, d );
  variance = burr_variance ( a, b, c, d );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = burr_sample ( a, b, c, d, &seed );
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
/******************************************************************************/

void cardioid_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    CARDIOID_CDF_TEST tests CARDIOID_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 September 2013

  Author:

    John Burkardt
*/
{
  double a = 0.0;
  double b = 0.25;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "CARDIOID_CDF_TEST\n" );
  printf ( "  CARDIOID_CDF evaluates the Cardioid CDF;\n" );
  printf ( "  CARDIOID_CDF_INV inverts the Cardioid CDF.\n" );
  printf ( "  CARDIOID_PDF evaluates the Cardioid PDF;\n" );

  printf ( "\n" );
  printf ( "  PDF parameter A = %g\n", a );
  printf ( "  PDF parameter B = %g\n", b );

  if ( ! cardioid_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "CARDIOID_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 0; i < 10; i++ )
  {
    x = cardioid_sample ( a, b, &seed );
    pdf = cardioid_pdf ( x, a, b );
    cdf = cardioid_cdf ( x, a, b );
    x2 = cardioid_cdf_inv ( cdf, a, b );
    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void cardioid_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    CARDIOID_SAMPLE_TEST tests CARDIOID_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a = 0.0;
  double b = 0.25;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "CARDIOID_SAMPLE_TEST\n" );
  printf ( "  CARDIOID_MEAN computes the Cardioid mean;\n" );
  printf ( "  CARDIOID_SAMPLE samples the Cardioid distribution;\n" );
  printf ( "  CARDIOID_VARIANCE computes the Cardioid variance.\n" );

  printf ( "\n" );
  printf ( "  PDF parameter A = %g\n", a );
  printf ( "  PDF parameter B = %g\n", b );

  if ( ! cardioid_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "CARDIOID_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = cardioid_mean ( a, b );
  variance = cardioid_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =                    %g\n", mean );
  printf ( "  PDF variance =                %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = cardioid_sample ( a, b, &seed );
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
/******************************************************************************/

void cauchy_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    CAUCHY_CDF_TEST tests CAUCHY_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "CAUCHY_CDF_TEST\n" );
  printf ( "  CAUCHY_CDF evaluates the Cauchy CDF;\n" );
  printf ( "  CAUCHY_CDF_INV inverts the Cauchy CDF.\n" );
  printf ( "  CAUCHY_PDF evaluates the Cauchy PDF;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! cauchy_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "CAUCHY_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = cauchy_sample ( a, b, &seed );
    pdf = cauchy_pdf ( x, a, b );
    cdf = cauchy_cdf ( x, a, b );
    x2 = cauchy_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void cauchy_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    CAUCHY_SAMPLE_TEST tests CAUCHY_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "CAUCHY_SAMPLE_TEST\n" );
  printf ( "  CAUCHY_MEAN computes the Cauchy mean;\n" );
  printf ( "  CAUCHY_SAMPLE samples the Cauchy distribution;\n" );
  printf ( "  CAUCHY_VARIANCE computes the Cauchy variance;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! cauchy_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "CAUCHY_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = cauchy_mean ( a, b );
  variance = cauchy_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = cauchy_sample ( a, b, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean    );
  printf ( "  Sample variance = %g\n", variance);
  printf ( "  Sample maximum =  %g\n", xmax    );
  printf ( "  Sample minimum =  %g\n", xmin    );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void chebyshev1_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV1_CDF_TEST tests CHEBYSHEV1_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 August 2016

  Author:

    John Burkardt
*/
{
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "CHEBYSHEV1_CDF_TEST\n" );
  printf ( "  CHEBYSHEV1_CDF evaluates the Chebyshev1 CDF;\n" );
  printf ( "  CHEBYSHEV1_CDF_INV inverts the Chebyshev1 CDF.\n" );
  printf ( "  CHEBYSHEV1_PDF evaluates the Chebyshev1 PDF;\n" );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = chebyshev1_sample ( &seed );
    pdf = chebyshev1_pdf ( x );
    cdf = chebyshev1_cdf ( x );
    x2 = chebyshev1_cdf_inv ( cdf );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void chebyshev1_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    CHEBYSHEV1_SAMPLE_TEST tests CHEBYSHEV1_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 August 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "CHEBYSHEV1_SAMPLE_TEST\n" );
  printf ( "  CHEBYSHEV1_MEAN computes the Chebyshev1 mean;\n" );
  printf ( "  CHEBYSHEV1_SAMPLE samples the Chebyshev1 distribution;\n" );
  printf ( "  CHEBYSHEV1_VARIANCE computes the Chebyshev1 variance.\n" );

  mean     = chebyshev1_mean ( );
  variance = chebyshev1_variance ( );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = chebyshev1_sample ( &seed );
  }

  mean     = r8vec_mean     ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax     = r8vec_max      ( SAMPLE_NUM, x );
  xmin     = r8vec_min      ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax     );
  printf ( "  Sample minimum =  %g\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void chi_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    CHI_CDF_TEST tests CHI_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "CHI_CDF_TEST\n" );
  printf ( "  CHI_CDF evaluates the Chi CDF;\n" );
  printf ( "  CHI_CDF_INV inverts the Chi CDF.\n" );
  printf ( "  CHI_PDF evaluates the Chi PDF;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! chi_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "CHI_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = chi_sample ( a, b, c, &seed );
    pdf = chi_pdf ( x, a, b, c );
    cdf = chi_cdf ( x, a, b, c );
    x2 = chi_cdf_inv ( cdf, a, b, c );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
//****************************************************************************80

void chi_sample_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CHI_SAMPLE_TEST tests CHI_SAMPLE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 September 2013
//
//  Author:
//
//    John Burkardt
//
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  double c;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "CHI_SAMPLE_TEST\n" );
  printf ( "  CHI_MEAN computes the Chi mean;\n" );
  printf ( "  CHI_SAMPLE samples the Chi distribution;\n" );
  printf ( "  CHI_VARIANCE computes the Chi variance;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! chi_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "CHI_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = chi_mean ( a, b, c );
  variance = chi_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = chi_sample ( a, b, c, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  return;
# undef SAMPLE_NUM
}
//****************************************************************************80

void chi_square_cdf_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CHI_SQUARE_CDF_TEST tests CHI_SQUARE_CDF.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 September 2013
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "CHI_SQUARE_CDF_TEST\n" );
  printf ( "  CHI_SQUARE_CDF evaluates the Chi Square CDF;\n" );
  printf ( "  CHI_SQUARE_CDF_INV inverts the Chi Square CDF.\n" );
  printf ( "  CHI_SQUARE_PDF evaluates the Chi Square PDF;\n" );

  a = 4.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a );

  if ( ! chi_square_check ( a ) )
  {
    printf ( "\n" );
    printf ( "CHI_SQUARE_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = chi_square_sample ( a, &seed );
    pdf = chi_square_pdf ( x, a );
    cdf = chi_square_cdf ( x, a );
    x2 = chi_square_cdf_inv ( cdf, a );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void chi_square_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    CHI_SQUARE_SAMPLE_TEST tests CHI_SQUARE_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  int j;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "CHI_SQUARE_SAMPLE_TEST\n" );
  printf ( "  CHI_SQUARE_MEAN computes the Chi Square mean;\n" );
  printf ( "  CHI_SQUARE_SAMPLE samples the Chi Square distribution;\n" );
  printf ( "  CHI_SQUARE_VARIANCE computes the Chi Square variance.\n" );

  a = 10.0E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a );

  if ( ! chi_square_check ( a ) )
  {
    printf ( "\n" );
    printf ( "CHI_SQUARE_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = chi_square_mean ( a );
  variance = chi_square_variance ( a );

  printf ( "  PDF mean =                    %g\n", mean );
  printf ( "  PDF variance =                %g\n", variance );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    x[j] = chi_square_sample ( a, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void chi_square_noncentral_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    CHI_SQUARE_NONCENTRAL_SAMPLE_TEST tests CHI_SQUARE_NONCENTRAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed;
  int seed_init = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "CHI_SQUARE_NONCENTRAL_SAMPLE_TEST\n" );
  printf ( "  CHI_SQUARE_NONCENTRAL_MEAN computes the Chi Square Noncentral mean;\n" );
  printf ( "  CHI_SQUARE_NONCENTRAL_SAMPLE samples the Chi Square Noncentral distribution;\n" );
  printf ( "  CHI_SQUARE_NONCENTRAL_VARIANCE computes the Chi Square Noncentral variance;\n" );

  a = 3.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! chi_square_noncentral_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "CHI_SQUARE_NONCENTRAL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = chi_square_noncentral_mean ( a, b );
  variance = chi_square_noncentral_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  seed = seed_init;

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = chi_square_noncentral_sample ( a, b, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Initial seed =     %d\n", seed_init );
  printf ( "  Final seed =       %d\n", seed );

  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void circular_normal_01_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCULAR_NORMAL_01_SAMPLE_TEST tests CIRCULAR_NORMAL_01_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int j;
  double *mean;
  int seed = 123456789;
  double *variance;
  double x[2*SAMPLE_NUM];
  double *xmax;
  double *xmin;
  double *y;

  printf ( "\n" );
  printf ( "CIRCULAR_NORMAL_01_SAMPLE_TEST\n" );
  printf ( "  CIRCULAR_NORMAL_01_MEAN computes the Circular Normal 01 mean;\n" );
  printf ( "  CIRCULAR_NORMAL_01_SAMPLE samples the Circular Normal 01 distribution;\n" );
  printf ( "  CIRCULAR_NORMAL_01_VARIANCE computes the Circular Normal 01 variance.\n" );

  mean = circular_normal_01_mean ( );
  variance = circular_normal_01_variance ( );

  printf ( "\n" );
  printf ( "  PDF mean =     %12g  %12g\n", mean[0], mean[1] );
  printf ( "  PDF variance = %12g  %12g\n", variance[0], variance[1] );

  free ( mean );
  free ( variance );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    y = circular_normal_01_sample ( &seed );
    x[0+j*2] = y[0];
    x[1+j*2] = y[1];
    free ( y );
  }

  mean = r8row_mean ( 2, SAMPLE_NUM, x );
  variance = r8row_variance ( 2, SAMPLE_NUM, x );
  xmax = r8row_max ( 2, SAMPLE_NUM, x );
  xmin = r8row_min ( 2, SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %12g  %12g\n", mean[0], mean[1] );
  printf ( "  Sample variance = %12g  %12g\n", variance[0], variance[1] );
  printf ( "  Sample maximum =  %12g  %12g\n", xmax[0], xmax[1] );
  printf ( "  Sample minimum =  %12g  %12g\n", xmin[0], xmin[1] );

  free ( mean );
  free ( variance );
  free ( xmax );
  free ( xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void circular_normal_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    CIRCULAR_NORMAL_SAMPLE_TEST tests CIRCULAR_NORMAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 March 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a[2];
  double b;
  int j;
  double *mean;
  int seed = 123456789;
  double *variance;
  double x[2*SAMPLE_NUM];
  double *xmax;
  double *xmin;
  double *y;

  a[0] = 1.0;
  a[1] = 5.0;
  b = 0.75;

  printf ( "\n" );
  printf ( "CIRCULAR_NORMAL_SAMPLE_TEST\n" );
  printf ( "  CIRCULAR_NORMAL_MEAN computes the Circular Normal mean;\n" );
  printf ( "  CIRCULAR_NORMAL_SAMPLE samples the Circular Normal distribution;\n" );
  printf ( "  CIRCULAR_NORMAL_VARIANCE computes the Circular Normal variance.\n" );

  mean = circular_normal_mean ( a, b );
  variance = circular_normal_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %12g  %12g\n", mean[0], mean[1] );
  printf ( "  PDF variance = %12g  %12g\n", variance[0], variance[1] );

  free ( mean );
  free ( variance );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    y = circular_normal_sample ( a, b, &seed );
    x[0+j*2] = y[0];
    x[1+j*2] = y[1];
    free ( y );
  }

  mean = r8row_mean ( 2, SAMPLE_NUM, x );
  variance = r8row_variance ( 2, SAMPLE_NUM, x );
  xmax = r8row_max ( 2, SAMPLE_NUM, x );
  xmin = r8row_min ( 2, SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %12g  %12g\n", mean[0], mean[1] );
  printf ( "  Sample variance = %12g  %12g\n",variance[0], variance[1] );
  printf ( "  Sample maximum =  %12g  %12g\n",xmax[0], xmax[1] );
  printf ( "  Sample minimum =  %12g  %12g\n",xmin[0], xmin[1] );

  free ( mean );
  free ( variance );
  free ( xmax );
  free ( xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void cosine_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    COSINE_CDF_TEST tests COSINE_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 March 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "COSINE_CDF_TEST\n" );
  printf ( "  COSINE_CDF evaluates the Cosine CDF;\n" );
  printf ( "  COSINE_CDF_INV inverts the Cosine CDF.\n" );
  printf ( "  COSINE_PDF evaluates the Cosine PDF;\n" );

  a = 2.0;
  b = 1.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! cosine_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "COSINE_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = cosine_sample ( a, b, &seed );
    pdf = cosine_pdf ( x, a, b );
    cdf = cosine_cdf ( x, a, b );
    x2 = cosine_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void cosine_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    COSINE_SAMPLE_TEST tests COSINE_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "COSINE_SAMPLE_TEST\n" );
  printf ( "  COSINE_MEAN computes the Cosine mean;\n" );
  printf ( "  COSINE_SAMPLE samples the Cosine distribution;\n" );
  printf ( "  COSINE_VARIANCE computes the Cosine variance;\n" );

  a = 2.0;
  b = 1.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! cosine_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "COSINE_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = cosine_mean ( a, b );
  variance = cosine_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = cosine_sample ( a, b, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n",SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void coupon_complete_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    COUPON_COMPLETE_PDF_TEST tests COUPON_COMPLETE_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 April 2016

  Author:

    John Burkardt
*/
{
  int box_num;
  double cdf;
  double pdf;
  int type_num;

  printf ( "\n" );
  printf ( "COUPON_COMPLETE_PDF_TEST\n" );
  printf ( "  COUPON_COMPLETE_PDF evaluates the coupon collector's\n" );
  printf ( "  complete collection pdf.\n" );
  printf ( "\n" );

  for ( type_num = 2; type_num <= 4; type_num++ )
  {
    printf ( "\n" );
    printf ( "  Number of coupon types is %d\n", type_num );
    printf ( "\n" );
    printf ( "   BOX_NUM      PDF             CDF\n" );
    printf ( "\n" );
    cdf = 0.0;
    for ( box_num = 1; box_num <= 20; box_num++ )
    {
      pdf = coupon_complete_pdf ( type_num, box_num );
      cdf = cdf + pdf;
      printf ( "  %8d  %14g  %14g\n", box_num, pdf, cdf );
    }
  }

  return;
}
/******************************************************************************/

void coupon_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    COUPON_SAMPLE_TEST tests COUPON_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 April 2016

  Author:

    John Burkardt
*/
{
# define N_TRIAL 10
# define MAX_TYPE 25

  double average;
  int coupon[MAX_TYPE];
  double expect;
  int i;
  int n_coupon;
  int n_type;
  int seed = 123456789;

  printf ( "\n" );
  printf ( "COUPON_SAMPLE_TEST:\n" );
  printf ( "  COUPON_SAMPLE samples the Coupon PDF.\n" );
  printf ( "\n" );

  for ( n_type = 5; n_type <= MAX_TYPE; n_type = n_type + 5 )
  {
    printf ( "\n" );
    printf ( "  Number of coupon types is %d\n", n_type );
    expect = ( double ) ( n_type ) * log ( ( double ) ( n_type ) );
    printf ( "  Expected wait is about %g\n", expect );
    printf ( "\n" );

    average = 0.0;
    for ( i = 1; i <= N_TRIAL; i++ )
    {
      coupon_sample ( n_type, &seed, coupon, &n_coupon );

      printf ( "  %6d  %6d\n", i, n_coupon );

      average = average + ( double ) ( n_coupon );
    }

    average = average / ( double ) ( N_TRIAL );
    printf ( "\n" );
    printf ( "  Average wait was %g\n", average );
  }

  return;
# undef N_TRIAL
# undef MAX_TRIAL
}
/******************************************************************************/

void deranged_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    DERANGED_CDF_TEST tests DERANGED_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 September 2013

  Author:

    John Burkardt
*/
{
  int a;
  double cdf;
  double pdf;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "DERANGED_CDF_TEST\n" );
  printf ( "  DERANGED_CDF evaluates the Deranged CDF;\n" );
  printf ( "  DERANGED_CDF_INV inverts the Deranged CDF.\n" );
  printf ( "  DERANGED_PDF evaluates the Deranged PDF;\n" );

  a = 7;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %d\n", a   );

  if ( ! deranged_check ( a ) )
  {
    printf ( "\n" );
    printf ( "DERANGED_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( x = 0; x <= a; x++ )
  {
    pdf = deranged_pdf ( x, a );
    cdf = deranged_cdf ( x, a );
    x2 = deranged_cdf_inv ( cdf, a );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2  );
  }

  return;
}
/******************************************************************************/

void deranged_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    DERANGED_SAMPLE_TEST tests DERANGED_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int a;
  int j;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "DERANGED_SAMPLE_TEST\n" );
  printf ( "  DERANGED_MEAN computes the Deranged mean;\n" );
  printf ( "  DERANGED_SAMPLE samples the Deranged distribution;\n" );
  printf ( "  DERANGED_VARIANCE computes the Deranged variance.\n" );

  a = 7;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %d\n", a );

  if ( ! deranged_check ( a ) )
  {
    printf ( "\n" );
    printf ( "DERANGED_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = deranged_mean ( a );
  variance = deranged_variance ( a );

  printf ( "  PDF mean =                    %g\n", mean     );
  printf ( "  PDF variance =                %g\n", variance );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    x[j] = deranged_sample ( a, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax     );
  printf ( "  Sample minimum =  %d\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void dipole_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    DIPOLE_CDF_TEST tests DIPOLE_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 September 2013

  Author:

    John Burkardt
*/
{
# define PI 3.14159265358979323
# define TEST_NUM 3

  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int test_i;
  double test_a[TEST_NUM] = { 0.0, PI/4.0, PI/2.0 };
  double test_b[TEST_NUM] = { 1.0, 0.5,    0.0 };
  double x;
  double x2;

  printf ( "\n" );
  printf ( "DIPOLE_CDF_TEST\n" );
  printf ( "  DIPOLE_CDF evaluates the Dipole CDF;\n" );
  printf ( "  DIPOLE_CDF_INV inverts the Dipole CDF.\n" );
  printf ( "  DIPOLE_PDF evaluates the Dipole PDF;\n" );

  for ( test_i = 0; test_i < TEST_NUM; test_i++ )
  {
    a = test_a[test_i];
    b = test_b[test_i];

    printf ( "\n" );
    printf ( "  PDF parameter A =      %g\n", a );
    printf ( "  PDF parameter B =      %g\n", b );

    if ( ! dipole_check ( a, b ) )
    {
      printf ( "\n" );
      printf ( "DIPOLE_CDF_TEST - Fatal error!\n" );
      printf ( "  The parameters are not legal.\n" );
      return;
    }

    printf ( "\n" );
    printf ( "       X            PDF           CDF            CDF_INV\n" );
    printf ( "\n" );

    for ( i = 1; i <= 10; i++ )
    {
      x = dipole_sample ( a, b, &seed );
      pdf = dipole_pdf ( x, a, b );
      cdf = dipole_cdf ( x, a, b );
      x2 = dipole_cdf_inv ( cdf, a, b );

      printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
    }

  }

  return;
# undef PI
# undef TEST_NUM
}
/******************************************************************************/

void dipole_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    DIPOLE_SAMPLE_TEST tests DIPOLE_SAMPLE;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000
# define PI 3.14159265358979323
# define TEST_NUM 3

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double test_a[TEST_NUM] = { 0.0, PI / 4.0, PI / 2.0 };
  double test_b[TEST_NUM] = { 1.0, 0.5,    0.0 };
  int test_i;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "DIPOLE_SAMPLE_TEST\n" );
  printf ( "  DIPOLE_SAMPLE samples the Dipole distribution;\n" );

  for ( test_i = 0; test_i < TEST_NUM; test_i++ )
  {
    a = test_a[test_i];
    b = test_b[test_i];

    printf ( "\n" );
    printf ( "  PDF parameter A =      %g\n", a );
    printf ( "  PDF parameter B =      %g\n", b );

    if ( ! dipole_check ( a, b ) )
    {
      printf ( "\n" );
      printf ( "DIPOLE_SAMPLE_TEST - Fatal error!\n" );
      printf ( "  The parameters are not legal.\n" );
      return;
    }

    for ( i = 0; i < SAMPLE_NUM; i++ )
    {
      x[i] = dipole_sample ( a, b, &seed );
    }

    mean = r8vec_mean ( SAMPLE_NUM, x );
    variance = r8vec_variance ( SAMPLE_NUM, x );
    xmax = r8vec_max ( SAMPLE_NUM, x );
    xmin = r8vec_min ( SAMPLE_NUM, x );

    printf ( "\n" );
    printf ( "  Sample size =     %d\n", SAMPLE_NUM );
    printf ( "  Sample mean =     %g\n", mean );
    printf ( "  Sample variance = %g\n", variance );
    printf ( "  Sample maximum =  %g\n", xmax );
    printf ( "  Sample minimum =  %g\n", xmin );
  }

  return;
# undef SAMPLE_NUM
# undef PI
# undef TEST_NUM
}
/******************************************************************************/

void dirichlet_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    DIRICHLET_SAMPLE_TEST tests DIRICHLET_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 April 2016

  Author:

    John Burkardt
*/
{
# define N 3
# define SAMPLE_NUM 1000

  double a[N] = { 0.250, 0.500, 1.250 };
  int i;
  int j;
  double *mean;
  double *m2;
  int seed = 123456789;
  double *variance;
  double x[N*SAMPLE_NUM];
  double *xmax;
  double *xmin;
  double *y;

  printf ( "\n" );
  printf ( "DIRICHLET_SAMPLE_TEST\n" );
  printf ( "  DIRICHLET_MEAN computes the Dirichlet mean;\n" );
  printf ( "  DIRICHLET_SAMPLE samples the Dirichlet distribution;\n" );
  printf ( "  DIRICHLET_VARIANCE computes the Dirichlet variance;\n" );

  printf ( "\n" );
  printf ( "  Number of components N = %d\n", N );

  r8vec_print ( N, a, "  PDF parameter A:" );

  if ( ! dirichlet_check ( N, a ) )
  {
    printf ( "\n" );
    printf ( "DIRICHLET_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = dirichlet_mean ( N, a );
  variance = dirichlet_variance ( N, a );

  r8vec_print ( N, mean, "  PDF mean:" );
  r8vec_print ( N, variance, "  PDF variance:" );

  free ( mean );
  free ( variance );

  m2 = dirichlet_moment2 ( N, a );

  r8mat_print ( N, N, m2, "  Second moment matrix:" );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    y = dirichlet_sample ( N, a, &seed );
    for ( i = 0; i < N; i++ )
    {
      x[i+j*N] = y[i];
    }
    free ( y );
  }

  mean = r8row_mean ( N, SAMPLE_NUM, x );
  variance = r8row_variance ( N, SAMPLE_NUM, x );
  xmax = r8row_max ( N, SAMPLE_NUM, x );
  xmin = r8row_min ( N, SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "\n" );
  printf ( "  Component Mean, Variance, Min, Max:\n" );
  printf ( "\n" );

  for ( i = 0; i < N; i++ )
  {
    printf ( "  %6d  %12g  %12g  %12g  %12g\n", 
      i, mean[i], variance[i], xmax[i], xmin[i] );
  }

  free ( mean );
  free ( m2 );
  free ( variance );
  free ( xmax );
  free ( xmin );

  return;
# undef N
# undef SAMPLE_NUM
}
/******************************************************************************/

void dirichlet_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    DIRICHLET_PDF_TEST tests DIRICHLET_PDF;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 April 2016

  Author:

    John Burkardt
*/
{
# define N 3

  double a[N] = { 0.250, 0.500, 1.250 };
  double pdf;
  double x[N] = { 0.500, 0.125, 0.375 };

  printf ( "\n" );
  printf ( "DIRICHLET_PDF_TEST\n" );
  printf ( "  DIRICHLET_PDF evaluates the Dirichlet PDF;\n" );

  printf ( "\n" );
  printf ( "  Number of components N = %d\n", N );

  r8vec_print ( N, a, "  PDF parameter A:" );

  if ( ! dirichlet_check ( N, a ) )
  {
    printf ( "\n" );
    printf ( "DIRICHLET_PDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  r8vec_print ( N, x, "  PDF argument X:" );

  pdf = dirichlet_pdf ( x, N, a );

  printf ( "\n" );
  printf ( "  PDF value = %g\n", pdf );

  return;
# undef N
}
/******************************************************************************/

void dirichlet_mix_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    DIRICHLET_MIX_SAMPLE_TEST tests DIRICHLET_MIX_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 April 2016

  Author:

    John Burkardt
*/
{
# define COMP_NUM 2
# define ELEM_NUM 3
# define SAMPLE_NUM 1000

  double a[ELEM_NUM*COMP_NUM] = {
    0.250, 0.500, 1.250,
    1.500, 0.500, 2.000 };
  int comp;
  double comp_weight[COMP_NUM] = { 1.0, 2.0 };
  int i;
  int j;
  double *mean;
  int seed = 123456789;
  double *variance;
  double x[ELEM_NUM*SAMPLE_NUM];
  double *xmax;
  double *xmin;
  double *y;

  printf ( "\n" );
  printf ( "DIRICHLET_MIX_SAMPLE_TEST\n" );
  printf ( "  DIRICHLET_MIX_SAMPLE samples the Dirichlet Mix distribution;\n" );
  printf ( "  DIRICHLET_MIX_MEAN computes the Dirichlet Mix mean;\n" );

  printf ( "\n" );
  printf ( "  Number of elements ELEM_NUM =   %d\n", ELEM_NUM );
  printf ( "  Number of components COMP_NUM = %d\n", COMP_NUM );
  r8mat_print ( ELEM_NUM, COMP_NUM, a, "  PDF parameters A(ELEM,COMP):" );
  r8vec_print ( COMP_NUM, comp_weight, "  Component weights" );

  if ( ! dirichlet_mix_check ( COMP_NUM, ELEM_NUM, a, comp_weight ) )
  {
    printf ( "\n" );
    printf ( "DIRICHLET_MIX_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = dirichlet_mix_mean ( COMP_NUM, ELEM_NUM, a, comp_weight );

  r8vec_print ( ELEM_NUM, mean, "  PDF mean" );

  free ( mean );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    y = dirichlet_mix_sample ( COMP_NUM, ELEM_NUM, a, comp_weight, &seed,
      &comp );

    for ( i = 0; i < ELEM_NUM; i++ )
    {
      x[i+j*ELEM_NUM] = y[i];
    }
    free ( y );
  }

  mean = r8row_mean ( ELEM_NUM, SAMPLE_NUM, x );
  variance = r8row_variance ( ELEM_NUM, SAMPLE_NUM, x );
  xmax = r8row_max ( ELEM_NUM, SAMPLE_NUM, x );
  xmin = r8row_min ( ELEM_NUM, SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "\n" );
  printf ( "  Component Mean, Variance, Max, Min:\n" );
  printf ( "\n" );

  for ( i = 0; i < ELEM_NUM; i++ )
  {
    printf ( "  %6d  %12g  %12g  %12g  %12g\n", 
      i, mean[i], variance[i], xmax[i], xmin[i] );
  }

  free ( mean );
  free ( variance );
  free ( xmax );
  free ( xmin );

  return;
}
/******************************************************************************/

void dirichlet_mix_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    DIRICHLET_MIX_PDF_TEST tests DIRICHLET_MIX_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 April 2016

  Author:

    John Burkardt
*/
{
# define COMP_NUM 2
# define ELEM_NUM 3

  double a[ELEM_NUM*COMP_NUM] = {
    0.250, 0.500, 1.250,
    1.500, 0.500, 2.000 };
  double comp_weight[COMP_NUM] = { 1.0, 2.0 };
  double pdf;
  double x[ELEM_NUM] = { 0.500, 0.125, 0.375 };

  printf ( "\n" );
  printf ( "DIRICHLET_MIX_PDF_TEST\n" );
  printf ( "  DIRICHLET_MIX_PDF evaluates the Dirichlet Mix PDF.\n" );

  printf ( "\n" );
  printf ( "  Number of elements ELEM_NUM =   %d\n", ELEM_NUM );
  printf ( "  Number of components COMP_NUM = %d\n", COMP_NUM );
  r8mat_print ( ELEM_NUM, COMP_NUM, a, "  PDF parameters A(ELEM,COMP):" );
  r8vec_print ( COMP_NUM, comp_weight, "  Component weights" );

  if ( ! dirichlet_mix_check ( COMP_NUM, ELEM_NUM, a, comp_weight ) )
  {
    printf ( "\n" );
    printf ( "DIRICHLET_MIX_PDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  r8vec_print ( ELEM_NUM, x, "  PDF argument X:" );

  pdf = dirichlet_mix_pdf ( x, COMP_NUM, ELEM_NUM, a, comp_weight );

  printf ( "\n" );
  printf ( "  PDF value =           %g\n", pdf );

  return;
# undef COMP_NUM
# undef ELEM_NUM
}
/******************************************************************************/

void discrete_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    DISCRETE_CDF_TEST tests DISCRETE_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 September 2013

  Author:

    John Burkardt
*/
{
# define A 6

  double b[A] = { 1.0, 2.0, 6.0, 2.0, 4.0, 1.0 };
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "DISCRETE_CDF_TEST\n" );
  printf ( "  DISCRETE_CDF evaluates the Discrete CDF;\n" );
  printf ( "  DISCRETE_CDF_INV inverts the Discrete CDF.\n" );
  printf ( "  DISCRETE_PDF evaluates the Discrete PDF;\n" );

  printf ( "\n" );
  printf ( "  PDF parameter A =      %d\n", A );
  r8vec_print ( A, b, "  PDF parameter B:" );

  if ( ! discrete_check ( A, b ) )
  {
    printf ( "\n" );
    printf ( "DISCRETE_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = discrete_sample ( A, b, &seed );
    pdf = discrete_pdf ( x, A, b );
    cdf = discrete_cdf ( x, A, b );
    x2 = discrete_cdf_inv ( cdf, A, b );

    printf ( "  %8d  %12g  %12g  %8d\n", x, pdf, cdf, x2 );
  }

  return;
# undef A
}
/******************************************************************************/

void discrete_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    DISCRETE_SAMPLE_TEST tests DISCRETE_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 September 2013

  Author:

    John Burkardt
*/
{
# define A 6
# define SAMPLE_NUM 1000

  double b[A] = { 1.0, 2.0, 6.0, 2.0, 4.0, 1.0 };
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "DISCRETE_SAMPLE_TEST\n" );
  printf ( "  DISCRETE_MEAN computes the Discrete mean;\n" );
  printf ( "  DISCRETE_SAMPLE samples the Discrete distribution;\n" );
  printf ( "  DISCRETE_VARIANCE computes the Discrete variance;\n" );

  printf ( "\n" );
  printf ( "  PDF parameter A =      %d\n", A );
  r8vec_print ( A, b, "  PDF parameter B:" );

  if ( ! discrete_check ( A, b ) )
  {
    printf ( "\n" );
    printf ( "DISCRETE_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = discrete_mean ( A, b );
  variance = discrete_variance ( A, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = discrete_sample ( A, b, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax );
  printf ( "  Sample minimum =  %d\n", xmin );

  return;
# undef A
# undef SAMPLE_NUM
}
/******************************************************************************/

void disk_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    DISK_SAMPLE_TEST tests DISK_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    18 March 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  double c;
  int j;
  double *mean;
  int seed = 123456789;
  double variance;
  double x[2*SAMPLE_NUM];
  double *xmax;
  double *xmin;
  double *y;

  printf ( "\n" );
  printf ( "DISK_SAMPLE_TEST\n" );
  printf ( "  DISK_MEAN returns the Disk mean;\n" );
  printf ( "  DISK_SAMPLE samples the Disk distribution;\n" );
  printf ( "  DISK_VARIANCE returns the Disk variance;\n" );

  a = 10.0;
  b = 4.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  mean = disk_mean ( a, b, c );
  variance = disk_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  Disk mean =     %12g  %12g\n", mean[0], mean[1] );
  printf ( "  Disk variance = %12g\n", variance );

  free ( mean );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    y = disk_sample ( a, b, c, &seed );
    x[0+j*2] = y[0];
    x[1+j*2] = y[1];
    free ( y );
  }

  variance = 0.0;
  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    variance = variance + pow ( x[0+j*2] - a, 2 ) + pow ( x[1+j*2] - b, 2 ); 
  }
  variance = variance / ( double )  ( SAMPLE_NUM );

  mean = r8row_mean ( 2, SAMPLE_NUM, x );
  xmax = r8row_max ( 2, SAMPLE_NUM, x );
  xmin = r8row_min ( 2, SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %12g  %12g\n", mean[0], mean[1] );
  printf ( "  Sample variance = %12g\n", variance );
  printf ( "  Sample maximum =  %12g  %12g\n", xmax[0], xmax[1] );
  printf ( "  Sample minimum =  %12g  %12g\n", xmin[0], xmin[1] );

  free ( mean );
  free ( xmax );
  free ( xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void empirical_discrete_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    EMPIRICAL_DISCRETE_CDF_TEST tests EMPIRICAL_DISCRETE_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 September 2013

  Author:

    John Burkardt
*/
{
# define A 6

  double b[A] = { 1.0, 1.0, 3.0, 2.0, 1.0, 2.0 };
  double c[A] = { 0.0, 1.0, 2.0, 4.5, 6.0, 10.0 };
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "EMPIRICAL_DISCRETE_CDF_TEST\n" );
  printf ( "  EMPIRICAL_DISCRETE_CDF evaluates the Empirical Discrete CDF;\n" );
  printf ( "  EMPIRICAL_DISCRETE_CDF_INV inverts the Empirical Discrete CDF.\n" );
  printf ( "  EMPIRICAL_DISCRETE_PDF evaluates the Empirical Discrete PDF;\n" );

  printf ( "\n" );
  printf ( "  PDF parameter A = %d\n", A );
  r8vec_print ( A, b, "  PDF parameter B = " );
  r8vec_print ( A, c, "  PDF parameter C = " );

  if ( ! empirical_discrete_check ( A, b, c ) )
  {
    printf ( "\n" );
    printf ( "EMPIRICAL_DISCRETE_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = empirical_discrete_sample ( A, b, c, &seed );
    pdf = empirical_discrete_pdf ( x, A, b, c );
    cdf = empirical_discrete_cdf ( x, A, b, c );
    x2 = empirical_discrete_cdf_inv ( cdf, A, b, c );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
# undef A
}
/******************************************************************************/

void empirical_discrete_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    EMPIRICAL_DISCRETE_SAMPLE_TEST tests EMPIRICAL_DISCRETE_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 September 2013

  Author:

    John Burkardt
*/
{
# define A 6
# define SAMPLE_NUM 1000

  double b[A] = { 1.0, 1.0, 3.0, 2.0, 1.0, 2.0 };
  double c[A] = { 0.0, 1.0, 2.0, 4.5, 6.0, 10.0 };
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "EMPIRICAL_DISCRETE_SAMPLE_TEST\n" );
  printf ( "  EMPIRICAL_DISCRETE_MEAN computes the Empirical Discrete mean;\n" );
  printf ( "  EMPIRICAL_DISCRETE_SAMPLE samples the Empirical Discrete distribution;\n" );
  printf ( "  EMPIRICAL_DISCRETE_VARIANCE computes the Empirical Discrete variance.\n" );

  printf ( "\n" );
  printf ( "  PDF parameter A = %d\n", A );
  r8vec_print ( A, b, "  PDF parameter B = " );
  r8vec_print ( A, c, "  PDF parameter C = " );

  if ( ! empirical_discrete_check ( A, b, c ) )
  {
    printf ( "\n" );
    printf ( "EMPIRICAL_DISCRETE_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = empirical_discrete_mean ( A, b, c );
  variance = empirical_discrete_variance ( A, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = empirical_discrete_sample ( A, b, c, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  return;
# undef A
# undef SAMPLE_NUM
}
/******************************************************************************/

void english_letter_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    ENGLISH_LETTER_CDF_TEST tests ENGLISH_LETTER_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 March 2016

  Author:

    John Burkardt
*/
{
  char c;
  char c2;
  double cdf;
  int i;
  double pdf;
  int seed;

  printf ( "\n" );
  printf ( "ENGLISH_LETTER_CDF_TEST\n" );
  printf ( "  ENGLISH_LETTER_CDF evaluates the English Letter CDF;\n" );
  printf ( "  ENGLISH_LETTER_CDF_INV inverts the English Letter CDF.\n" );
  printf ( "  ENGLISH_LETTER_PDF evaluates the English Letter PDF;\n" );

  seed = 123456789;

  printf ( "\n" );
  printf ( "   C              PDF             CDF    CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    c = english_letter_sample ( &seed );
    pdf = english_letter_pdf ( c );
    cdf = english_letter_cdf ( c );
    c2 = english_letter_cdf_inv ( cdf );

    printf ( "  '%c'  %14.6f  %14.6f  '%c'\n", c, pdf, cdf, c2 );
  }

  return;
}
/******************************************************************************/

void english_sentence_length_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    ENGLISH_SENTENCE_LENGTH_CDF_TEST tests ENGLISH_SENTENCE_LENGTH_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 April 2016

  Author:

    John Burkardt
*/
{
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "ENGLISH_SENTENCE_LENGTH_CDF_TEST\n" );
  printf ( "  ENGLISH_SENTENCE_LENGTH_CDF evaluates the English Sentence Length CDF;\n" );
  printf ( "  ENGLISH_SENTENCE_LENGTH_CDF_INV inverts the English Sentence Length CDF.\n" );
  printf ( "  ENGLISH_SENTENCE_LENGTH_PDF evaluates the English Sentence Length PDF;\n" );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = english_sentence_length_sample ( &seed );

    pdf = english_sentence_length_pdf ( x );

    cdf = english_sentence_length_cdf ( x );

    x2 = english_sentence_length_cdf_inv ( cdf );

    printf ( "  %8d  %12g  %12g  %8d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void english_sentence_length_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    ENGLISH_SENTENCE_LENGTH_SAMPLE_TEST tests ENGLISH_SENTENCE_LENGTH_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int i;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "ENGLISH_SENTENCE_LENGTH_SAMPLE_TEST\n" );
  printf ( "  ENGLISH_SENTENCE_LENGTH_MEAN computes the English Sentence Length mean;\n" );
  printf ( "  ENGLISH_SENTENCE_LENGTH_SAMPLE samples the English Sentence Length distribution;\n" );
  printf ( "  ENGLISH_SENTENCE_LENGTH_VARIANCE computes the English Sentence Length variance.\n" );

  mean = english_sentence_length_mean ( );
  variance = english_sentence_length_variance ( );

  printf ( "\n" );
  printf ( "  PDF mean =                    %g\n", mean );
  printf ( "  PDF variance =                %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = english_sentence_length_sample ( &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax );
  printf ( "  Sample minimum =  %d\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void english_word_length_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    ENGLISH_WORD_LENGTH_CDF_TEST tests ENGLISH_WORD_LENGTH_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2016

  Author:

    John Burkardt
*/
{
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "ENGLISH_WORD_LENGTH_CDF_TEST\n" );
  printf ( "  ENGLISH_WORD_LENGTH_CDF evaluates the English Word Length CDF;\n" );
  printf ( "  ENGLISH_WORD_LENGTH_CDF_INV inverts the English Word Length CDF.\n" );
  printf ( "  ENGLISH_WORD_LENGTH_PDF evaluates the English Word Length PDF;\n" );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = english_word_length_sample ( &seed );

    pdf = english_word_length_pdf ( x );

    cdf = english_word_length_cdf ( x );

    x2 = english_word_length_cdf_inv ( cdf );

    printf ( "  %8d  %12g  %12g  %8d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void english_word_length_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    ENGLISH_WORD_LENGTH_SAMPLE_TEST tests ENGLISH_WORD_LENGTH_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int i;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "ENGLISH_WORD_LENGTH_SAMPLE_TEST\n" );
  printf ( "  ENGLISH_WORD_LENGTH_MEAN computes the English Word Length mean;\n" );
  printf ( "  ENGLISH_WORD_LENGTH_SAMPLE samples the English Word Length distribution;\n" );
  printf ( "  ENGLISH_WORD_LENGTH_VARIANCE computes the English Word Length variance.\n" );

  mean = english_word_length_mean ( );
  variance = english_word_length_variance ( );

  printf ( "\n" );
  printf ( "  PDF mean =                    %g\n", mean );
  printf ( "  PDF variance =                %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = english_word_length_sample ( &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax );
  printf ( "  Sample minimum =  %d\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void erlang_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    ERLANG_CDF_TEST tests ERLANG_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int c;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "ERLANG_CDF_TEST\n" );
  printf ( "  ERLANG_CDF evaluates the Erlang CDF;\n" );
  printf ( "  ERLANG_CDF_INV inverts the Erlang CDF.\n" );
  printf ( "  ERLANG_PDF evaluates the Erlang PDF;\n" );

  a = 1.0;
  b = 2.0;
  c = 3;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %d\n", c );

  if ( ! erlang_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "ERLANG_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = erlang_sample ( a, b, c, &seed );
    pdf = erlang_pdf ( x, a, b, c );
    cdf = erlang_cdf ( x, a, b, c );
    x2 = erlang_cdf_inv ( cdf, a, b, c );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void erlang_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    ERLANG_SAMPLE_TEST tests ERLANG_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int c;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "ERLANG_SAMPLE_TEST\n" );
  printf ( "  ERLANG_MEAN computes the Erlang mean;\n" );
  printf ( "  ERLANG_SAMPLE samples the Erlang distribution;\n" );
  printf ( "  ERLANG_VARIANCE computes the Erlang variance;\n" );

  a = 1.0;
  b = 2.0;
  c = 3;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %d\n", c );

  if ( ! erlang_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "ERLANG_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = erlang_mean ( a, b, c );
  variance = erlang_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = erlang_sample ( a, b, c, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void exponential_01_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    EXPONENTIAL_01_CDF_TEST tests EXPONENTIAL_01_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2013

  Author:

    John Burkardt
*/
{
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "EXPONENTIAL_01_CDF_TEST\n" );
  printf ( "  EXPONENTIAL_01_CDF evaluates the Exponential 01 CDF;\n" );
  printf ( "  EXPONENTIAL_01_CDF_INV inverts the Exponential 01 CDF.\n" );
  printf ( "  EXPONENTIAL_01_PDF evaluates the Exponential 01 PDF;\n" );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = exponential_01_sample ( &seed );
    pdf = exponential_01_pdf ( x );
    cdf = exponential_01_cdf ( x );
    x2 = exponential_01_cdf_inv ( cdf );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void exponential_01_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    EXPONENTIAL_01_SAMPLE_TEST tests EXPONENTIAL_01_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "EXPONENTIAL_01_SAMPLE_TEST\n" );
  printf ( "  EXPONENTIAL_01_MEAN computes the Exponential 01 mean;\n" );
  printf ( "  EXPONENTIAL_01_SAMPLE samples the Exponential 01 distribution;\n" );
  printf ( "  EXPONENTIAL_01_VARIANCE computes the Exponential 01 variance.\n" );

  mean     = exponential_01_mean ( );
  variance = exponential_01_variance ( );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = exponential_01_sample ( &seed );
  }

  mean     = r8vec_mean     ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax     = r8vec_max      ( SAMPLE_NUM, x );
  xmin     = r8vec_min      ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax     );
  printf ( "  Sample minimum =  %g\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void exponential_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    EXPONENTIAL_CDF_TEST tests EXPONENTIAL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "EXPONENTIAL_CDF_TEST\n" );
  printf ( "  EXPONENTIAL_CDF evaluates the Exponential CDF;\n" );
  printf ( "  EXPONENTIAL_CDF_INV inverts the Exponential CDF.\n" );
  printf ( "  EXPONENTIAL_PDF evaluates the Exponential PDF;\n" );

  a = 1.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! exponential_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "EXPONENTIAL_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = exponential_sample ( a, b, &seed );
    pdf = exponential_pdf ( x, a, b );
    cdf = exponential_cdf ( x, a, b );
    x2 = exponential_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2  );
  }

  return;
}
/******************************************************************************/

void exponential_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    EXPONENTIAL_SAMPLE_TEST tests EXPONENTIAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "EXPONENTIAL_SAMPLE_TEST\n" );
  printf ( "  EXPONENTIAL_MEAN computes the Exponential mean;\n" );
  printf ( "  EXPONENTIAL_SAMPLE samples the Exponential distribution;\n" );
  printf ( "  EXPONENTIAL_VARIANCE computes the Exponential variance;\n" );

  a = 1.0;
  b = 10.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! exponential_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "EXPONENTIAL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = exponential_mean ( a, b );
  variance = exponential_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = exponential_sample ( a, b, &seed );
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
/******************************************************************************/

void extreme_values_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    EXTREME_VALUES_CDF_TEST tests EXTREME_VALUES_CDF

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "EXTREME_VALUES_CDF_TEST\n" );
  printf ( "  EXTREME_VALUES_CDF evaluates the Extreme Values CDF;\n" );
  printf ( "  EXTREME_VALUES_CDF_INV inverts the Extreme Values CDF.\n" );
  printf ( "  EXTREME_VALUES_PDF evaluates the Extreme Values PDF;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! extreme_values_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "EXTREME_VALUES_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = extreme_values_sample ( a, b, &seed );
    pdf = extreme_values_pdf ( x, a, b );
    cdf = extreme_values_cdf ( x, a, b );
    x2 = extreme_values_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void extreme_values_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    EXTREME_VALUES_SAMPLE_TEST tests EXTREME_VALUES_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "EXTREME_VALUES_SAMPLE_TEST\n" );
  printf ( "  EXTREME_VALUES_MEAN computes the Extreme Values mean;\n" );
  printf ( "  EXTREME_VALUES_SAMPLE samples the Extreme Values distribution;\n" );
  printf ( "  EXTREME_VALUES_VARIANCE computes the Extreme Values variance;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! extreme_values_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "EXTREME_VALUES_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = extreme_values_mean ( a, b );
  variance = extreme_values_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = extreme_values_sample ( a, b, &seed );
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
/******************************************************************************/

void f_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    F_CDF_TEST tests F_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 April 2016

  Author:

    John Burkardt
*/
{
  double cdf;
  int i;
  int m;
  int n;
  double pdf;
  int seed = 123456789;
  double x;

  printf ( "\n" );
  printf ( "F_CDF_TEST\n" );
  printf ( "  F_CDF evaluates the F CDF;\n" );
  printf ( "  F_PDF evaluates the F PDF;\n" );
  printf ( "  F_SAMPLE samples the F PDF;\n" );

  m = 1;
  n = 1;

  printf ( "\n" );
  printf ( "  PDF parameter M = %d\n", m   );
  printf ( "  PDF parameter N = %d\n", n   );

  if ( ! f_check ( m, n ) )
  {
    printf ( "\n" );
    printf ( "F_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameter values are illegal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = f_sample ( m, n, &seed );
    pdf = f_pdf ( x, m, n );
    cdf = f_cdf ( x, m, n );

    printf ( "  %12g  %12g  %12g\n", x, pdf, cdf );
  }

  return;
}
/******************************************************************************/

void f_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    F_SAMPLE_TEST tests F_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int i;
  int m;
  double mean;
  int n;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "F_SAMPLE_TEST\n" );
  printf ( "  F_MEAN computes the F mean;\n" );
  printf ( "  F_SAMPLE samples the F distribution;\n" );
  printf ( "  F_VARIANCE computes the F variance;\n" );

  m = 8;
  n = 6;

  printf ( "\n" );
  printf ( "  PDF parameter M = %d\n", m );
  printf ( "  PDF parameter N = %d\n", n );

  if ( ! f_check ( m, n ) )
  {
    printf ( "\n" );
    printf ( "F_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = f_mean ( m, n );
  variance = f_variance ( m, n );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = f_sample ( m, n, &seed );
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
/******************************************************************************/

void fermi_dirac_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    FERMI_DIRAC_SAMPLE_TEST tests FERMI_DIRAC_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2016

  Author:

    John Burkardt
*/
{
  int i;
  double mean;
  int sample_num = 10000;
  int seed;
  int test;
  double u;
  double u_test[7] = {
   1.0, 2.0, 4.0, 8.0, 16.0, 
  32.0, 1.0  };
  double v;
  double v_test[7] = {
   1.0, 1.0, 1.0, 1.0, 1.0, 
   1.0, 0.25  };
  double variance;
  double x[10000];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "FERMI_DIRAC_SAMPLE_TEST\n" );
  printf ( "  FERMI_DIRAC_SAMPLE samples the Fermi Dirac distribution.\n" );

  for ( test = 0; test < 7; test++ )
  {
    u = u_test[test];
    v = v_test[test];
    seed = 123456789;

    printf ( "\n" );
    printf ( "  U =          %g\n", u );
    printf ( "  V =          %g\n", v );

    for ( i = 0; i < sample_num; i++ )
    {
      x[i] = fermi_dirac_sample ( u, v, &seed );
    }

    mean = r8vec_mean ( sample_num, x );
    variance = r8vec_variance ( sample_num, x );
    xmax = r8vec_max ( sample_num, x );
    xmin = r8vec_min ( sample_num, x );

    printf ( "\n" );
    printf ( "  Sample size =     %d\n", sample_num  );
    printf ( "  Sample mean =     %g\n", mean     );
    printf ( "  Sample variance = %g\n", variance );
    printf ( "  Sample maximum =  %g\n", xmax     );
    printf ( "  Sample minimum =  %g\n", xmin     );
  }

  return;
}
/******************************************************************************/

void fisher_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    FISHER_PDF_TEST tests FISHER_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 April 2016

  Author:

    John Burkardt
*/
{
  int j;
  double kappa;
  double mu[3];
  int n = 10;
  double pdf;
  int seed;
  int test;
  int test_num = 3;
  double *x;

  printf ( "\n" );
  printf ( "FISHER_PDF_TEST\n" );
  printf ( "  FISHER_PDF evaluates the Fisher PDF.\n" );

  for ( test = 1; test <= test_num; test++ )
  {
    if ( test == 1 )
    {
      kappa = 0.0;
      mu[0] = 1.0;
      mu[1] = 0.0;
      mu[2] = 0.0;
    }
    else if ( test == 2 )
    {
      kappa = 0.5;
      mu[0] = 1.0;
      mu[1] = 0.0;
      mu[2] = 0.0;
    }
    else if ( test == 3 )
    {
      kappa = 10.0;
      mu[0] = 1.0;
      mu[1] = 0.0;
      mu[2] = 0.0;
    }

    printf ( "\n" );
    printf ( "  PDF parameters:\n" );
    printf ( "    Concentration parameter KAPPA = %g\n", kappa );
    printf ( "    Direction MU(1:3) = %g  %g  %g\n", mu[0], mu[1], mu[2] );

    printf ( "\n" );
    printf ( "      X                         PDF\n" );
    printf ( "\n" );

    seed = 123456789;

    for ( j = 0; j < n; j++ )
    {
      x = fisher_sample ( kappa, mu, 1, &seed );

      pdf = fisher_pdf ( x, kappa, mu );

      printf ( "  %10g  %10g  %10g  %14g\n", x[0], x[1], x[2], pdf );

      free ( x );
    }
  }
  return;
}
/******************************************************************************/

void fisk_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    FISK_CDF_TEST tests FISK_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "FISK_CDF_TEST\n" );
  printf ( "  FISK_CDF evaluates the Fisk CDF;\n" );
  printf ( "  FISK_CDF_INV inverts the Fisk CDF.\n" );
  printf ( "  FISK_PDF evaluates the Fisk PDF;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! fisk_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "FISK+_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = fisk_sample ( a, b, c, &seed );
    pdf = fisk_pdf ( x, a, b, c );
    cdf = fisk_cdf ( x, a, b, c );
    x2 = fisk_cdf_inv ( cdf, a, b, c );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void fisk_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    FISK_SAMPLE_TEST tests FISK_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  double c;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "FISK_SAMPLE_TEST\n" );
  printf ( "  FISK_MEAN computes the Fisk mean;\n" );
  printf ( "  FISK_SAMPLE samples the Fisk distribution;\n" );
  printf ( "  FISK_VARIANCE computes the Fisk variance;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! fisk_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "FISK_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = fisk_mean ( a, b, c );
  variance = fisk_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = fisk_sample ( a, b, c, &seed );
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
/******************************************************************************/

void folded_normal_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    FOLDED_NORMAL_CDF_TEST tests FOLDED_NORMAL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "FOLDED_NORMAL_CDF_TEST\n" );
  printf ( "  FOLDED_NORMAL_CDF evaluates the Folded Normal CDF;\n" );
  printf ( "  FOLDED_NORMAL_CDF_INV inverts the Folded Normal CDF.\n" );
  printf ( "  FOLDED_NORMAL_PDF evaluates the Folded Normal PDF;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! folded_normal_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "FOLDED_NORMAL_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = folded_normal_sample ( a, b, &seed );
    pdf = folded_normal_pdf ( x, a, b );
    cdf = folded_normal_cdf ( x, a, b );
    x2 = folded_normal_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void folded_normal_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    FOLDED_NORMAL_SAMPLE_TEST tests FOLDED_NORMAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "FOLDED_NORMAL_SAMPLE_TEST\n" );
  printf ( "  FOLDED_NORMAL_MEAN computes the Folded Normal mean;\n" );
  printf ( "  FOLDED_NORMAL_SAMPLE samples the Folded Normal distribution;\n" );
  printf ( "  FOLDED_NORMAL_VARIANCE computes the Folded Normal variance;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! folded_normal_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "FOLDED_NORMAL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = folded_normal_mean ( a, b );
  variance = folded_normal_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = folded_normal_sample ( a, b, &seed );
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
/******************************************************************************/

void frechet_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    FRECHET_CDF_TEST tests FRECHET_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 April 2016

  Author:

    John Burkardt
*/
{
  double alpha;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "FRECHET_CDF_TEST\n" );
  printf ( "  FRECHET_CDF evaluates the Frechet CDF;\n" );
  printf ( "  FRECHET_CDF_INV inverts the Frechet CDF.\n" );
  printf ( "  FRECHET_PDF evaluates the Frechet PDF;\n" );

  alpha = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter ALPHA =  %g\n", alpha );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = frechet_sample ( alpha, &seed );
    pdf = frechet_pdf ( x, alpha );
    cdf = frechet_cdf ( x, alpha );
    x2 = frechet_cdf_inv ( cdf, alpha );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void frechet_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    FRECHET_SAMPLE_TEST tests FRECHET_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double alpha;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "FRECHET_SAMPLE_TEST\n" );
  printf ( "  FRECHET_MEAN computes the Frechet mean;\n" );
  printf ( "  FRECHET_SAMPLE samples the Frechet distribution;\n" );
  printf ( "  FRECHET_VARIANCE computes the Frechet variance;\n" );

  alpha = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter ALPHA =  %g\n", alpha );

  mean = frechet_mean ( alpha );
  variance = frechet_variance ( alpha );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = frechet_sample ( alpha, &seed );
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
/******************************************************************************/

void gamma_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    GAMMA_CDF_TEST tests GAMMA_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;

  printf ( "\n" );
  printf ( "GAMMA_CDF_TEST\n" );
  printf ( "  GAMMA_CDF evaluates the Gamma CDF;\n" );
  printf ( "  GAMMA_PDF evaluates the Gamma PDF;\n" );
  printf ( "  GAMMA_SAMPLE samples the Gamma PDF;\n" );

  a = 1.0;
  b = 1.5;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A = %g\n", a );
  printf ( "  PDF parameter B = %g\n", b );
  printf ( "  PDF parameter B = %g\n", c );

  if ( ! gamma_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "GAMMA_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameter values are illegal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = gamma_sample ( a, b, c, &seed );
    pdf = gamma_pdf ( x, a, b, c );
    cdf = gamma_cdf ( x, a, b, c );

    printf ( "  %12g  %12g  %12g\n", x, pdf, cdf );
  }

  return;
}
/******************************************************************************/

void gamma_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    GAMMA_SAMPLE_TEST tests GAMMA_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  double c;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "GAMMA_SAMPLE_TEST\n" );
  printf ( "  GAMMA_MEAN computes the Gamma mean;\n" );
  printf ( "  GAMMA_SAMPLE samples the Gamma distribution;\n" );
  printf ( "  GAMMA_VARIANCE computes the Gamma variance;\n" );

  a = 1.0;
  b = 3.0;
  c = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! gamma_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "GAMMA_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = gamma_mean ( a, b, c );
  variance = gamma_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = gamma_sample ( a, b, c, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n",xmax     );
  printf ( "  Sample minimum =  %g\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void genlogistic_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    GENLOGISTIC_CDF_TEST tests GENLOGISTIC_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "GENLOGISTIC_CDF_TEST\n" );
  printf ( "  GENLOGISTIC_CDF evaluates the Genlogistic CDF;\n" );
  printf ( "  GENLOGISTIC_CDF_INV inverts the Genlogistic CDF.\n" );
  printf ( "  GENLOGISTIC_PDF evaluates the Genlogistic PDF;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! genlogistic_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "GENLOGISTIC_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = genlogistic_sample ( a, b, c, &seed );
    pdf = genlogistic_pdf ( x, a, b, c );
    cdf = genlogistic_cdf ( x, a, b, c );
    x2 = genlogistic_cdf_inv ( cdf, a, b, c );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void genlogistic_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    GENLOGISTIC_SAMPLE_TEST tests GENLOGISTIC_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  double c;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "GENLOGISTIC_SAMPLE_TEST\n" );
  printf ( "  GENLOGISTIC_MEAN computes the Genlogistic mean;\n" );
  printf ( "  GENLOGISTIC_SAMPLE samples the Genlogistic distribution;\n" );
  printf ( "  GENLOGISTIC_VARIANCE computes the Genlogistic variance;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! genlogistic_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "GENLOGISTIC_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = genlogistic_mean ( a, b, c );
  variance = genlogistic_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = genlogistic_sample ( a, b, c, &seed );
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
/******************************************************************************/

void geometric_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    GEOMETRIC_CDF_TEST tests GEOMETRIC_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "GEOMETRIC_CDF_TEST\n" );
  printf ( "  GEOMETRIC_CDF evaluates the Geometric CDF;\n" );
  printf ( "  GEOMETRIC_CDF_INV inverts the Geometric CDF.\n" );
  printf ( "  GEOMETRIC_PDF evaluates the Geometric PDF;\n" );

  a = 0.25E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a   );

  if ( ! geometric_check ( a ) )
  {
    printf ( "\n" );
    printf ( "GEOMETRIC_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = geometric_sample ( a, &seed );
    pdf = geometric_pdf ( x, a );
    cdf = geometric_cdf ( x, a );
    x2 = geometric_cdf_inv ( cdf, a );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void geometric_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    GEOMETRIC_SAMPLE_TEST tests GEOMETRIC_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  int j;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "GEOMETRIC_SAMPLE_TEST\n" );
  printf ( "  GEOMETRIC_MEAN computes the Geometric mean;\n" );
  printf ( "  GEOMETRIC_SAMPLE samples the Geometric distribution;\n" );
  printf ( "  GEOMETRIC_VARIANCE computes the Geometric variance.\n" );

  a = 0.25E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a );

  if ( ! geometric_check ( a ) )
  {
    printf ( "\n" );
    printf ( "GEOMETRIC_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = geometric_mean ( a );
  variance = geometric_variance ( a );

  printf ( "  PDF mean =                    %g\n", mean     );
  printf ( "  PDF variance =                %g\n", variance );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    x[j] = geometric_sample ( a, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax     );
  printf ( "  Sample minimum =  %d\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void gompertz_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    GOMPERTZ_CDF_TEST tests GOMPERTZ_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "GOMPERTZ_CDF_TEST\n" );
  printf ( "  GOMPERTZ_CDF evaluates the Gompertz CDF;\n" );
  printf ( "  GOMPERTZ_CDF_INV inverts the Gompertz CDF.\n" );
  printf ( "  GOMPERTZ_PDF evaluates the Gompertz PDF;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! gompertz_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "GOMPERTZ_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = gompertz_sample ( a, b, &seed );
    pdf = gompertz_pdf ( x, a, b );
    cdf = gompertz_cdf ( x, a, b );
    x2 = gompertz_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void gompertz_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    GOMPERTZ_SAMPLE_TEST tests GOMPERTZ_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "GOMPERTZ_SAMPLE_TEST\n" );
  printf ( "  GOMPERTZ_MEAN computes the Gompertz mean;\n" );
  printf ( "  GOMPERTZ_SAMPLE samples the Gompertz distribution;\n" );
  printf ( "  GOMPERTZ_VARIANCE computes the Gompertz variance;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! gompertz_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "GOMPERTZ_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = gompertz_sample ( a, b, &seed );
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
/******************************************************************************/

void gumbel_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    GUMBEL_CDF_TEST tests GUMBEL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "GUMBEL_CDF_TEST\n" );
  printf ( "  GUMBEL_CDF evaluates the Gumbel CDF;\n" );
  printf ( "  GUMBEL_CDF_INV inverts the Gumbel CDF.\n" );
  printf ( "  GUMBEL_PDF evaluates the Gumbel PDF;\n" );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = gumbel_sample ( &seed );
    pdf = gumbel_pdf ( x );
    cdf = gumbel_cdf ( x );
    x2 = gumbel_cdf_inv ( cdf );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void gumbel_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    GUMBEL_SAMPLE_TEST tests GUMBEL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "GUMBEL_SAMPLE_TEST\n" );
  printf ( "  GUMBEL_MEAN computes the Gumbel mean;\n" );
  printf ( "  GUMBEL_SAMPLE samples the Gumbel distribution;\n" );
  printf ( "  GUMBEL_VARIANCE computes the Gumbel variance.\n" );

  mean     = gumbel_mean ( );
  variance = gumbel_variance ( );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = gumbel_sample ( &seed );
  }

  mean     = r8vec_mean     ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax     = r8vec_max      ( SAMPLE_NUM, x );
  xmin     = r8vec_min      ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax     );
  printf ( "  Sample minimum =  %g\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void half_normal_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    HALF_NORMAL_CDF_TEST tests HALF_NORMAL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "HALF_NORMAL_CDF_TEST\n" );
  printf ( "  HALF_NORMAL_CDF evaluates the Half Normal CDF;\n" );
  printf ( "  HALF_NORMAL_CDF_INV inverts the Half Normal CDF.\n" );
  printf ( "  HALF_NORMAL_PDF evaluates the Half Normal PDF;\n" );

  a = 0.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! half_normal_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "HALF_NORMAL_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = half_normal_sample ( a, b, &seed );
    pdf = half_normal_pdf ( x, a, b );
    cdf = half_normal_cdf ( x, a, b );
    x2 = half_normal_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void half_normal_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    HALF_NORMAL_SAMPLE_TEST tests HALF_NORMAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "HALF_NORMAL_SAMPLE_TEST\n" );
  printf ( "  HALF_NORMAL_MEAN computes the Half Normal mean;\n" );
  printf ( "  HALF_NORMAL_SAMPLE samples the Half Normal distribution;\n" );
  printf ( "  HALF_NORMAL_VARIANCE computes the Half Normal variance;\n" );

  a = 0.0;
  b = 10.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! half_normal_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "HALF_NORMAL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = half_normal_mean ( a, b );
  variance = half_normal_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = half_normal_sample ( a, b, &seed );
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
/******************************************************************************/

void hypergeometric_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    HYPERGEOMETRIC_CDF_TEST tests HYPERGEOMETRIC_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2016

  Author:

    John Burkardt
*/
{
  double cdf;
  int l;
  int m;
  int n;
  double pdf;
  int x;

  printf ( "\n" );
  printf ( "HYPERGEOMETRIC_CDF_TEST\n" );
  printf ( "  HYPERGEOMETRIC_CDF evaluates the Hypergeometric CDF.\n" );
  printf ( "  HYPERGEOMETRIC_PDF evaluates the Hypergeometric PDF.\n" );

  n = 10;
  m = 7;
  l = 100;

  printf ( "\n" );
  printf ( "  Total number of balls L =         %d\n", l );
  printf ( "  Number of white balls M =         %d\n", m );
  printf ( "  Number of balls taken N =         %d\n", n );

  if ( ! hypergeometric_check ( n, m, l ) )
  {
    printf ( "\n" );
    printf ( "HYPERGEOMETRIC_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  x = 7;

  pdf = hypergeometric_pdf ( x, n, m, l );

  cdf = hypergeometric_cdf ( x, n, m, l );

  printf ( "  PDF argument X =                %d\n", x   );
  printf ( "  PDF value =                   = %g\n", pdf );
  printf ( "  CDF value =                   = %g\n", cdf );

  return;
}
/******************************************************************************/

void hypergeometric_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    HYPERGEOMETRIC_SAMPLE_TEST tests HYPERGEOMETRIC_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int j;
  int l;
  int m;
  double mean;
  int n;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "HYPERGEOMETRIC_SAMPLE_TEST\n" );
  printf ( "  HYPERGEOMETRIC_MEAN computes the Hypergeometric mean;\n" );
  printf ( "  HYPERGEOMETRIC_SAMPLE samples the Hypergeometric distribution;\n" );
  printf ( "  HYPERGEOMETRIC_VARIANCE computes the Hypergeometric variance.\n" );

  n = 10;
  m = 7;
  l = 100;

  printf ( "\n" );
  printf ( "  Total number of balls L =         %d\n", l );
  printf ( "  Number of white balls M =         %d\n", m );
  printf ( "  Number of balls taken N =         %d\n", n );

  if ( ! hypergeometric_check ( n, m, l ) )
  {
    printf ( "\n" );
    printf ( "HYPERGEOMETRIC_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = hypergeometric_mean ( n, m, l );
  variance = hypergeometric_variance ( n, m, l );

  printf ( "  PDF mean =                    %g\n", mean );
  printf ( "  PDF variance =                %g\n", variance );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    x[j] = hypergeometric_sample ( n, m, l, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax     );
  printf ( "  Sample minimum =  %d\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void i4_choose_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_CHOOSE_TEST tests I4_CHOOSE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 October 2014

  Author:

    John Burkardt
*/
{
  int cnk;
  int k;
  int n;

  printf ( "\n" );
  printf ( "I4_CHOOSE_TEST\n" );
  printf ( "  I4_CHOOSE evaluates C(N,K).\n" );
  printf ( "\n" );
  printf ( "       N       K     CNK\n" );

  for ( n = 0; n <= 4; n++ )
  {
    printf ( "\n" );
    for ( k = 0; k <= n; k++ )
    {
      cnk = i4_choose ( n, k );

      printf ( "  %6d  %6d  %6d\n", n, k, cnk );
    }
  }

  return;
}
/******************************************************************************/

void i4_choose_log_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_CHOOSE_LOG_TEST tests I4_CHOOSE_LOG.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    05 March 2016

  Author:

    John Burkardt
*/
{
  int cnk;
  double elcnk;
  int k;
  double lcnk;
  int n;

  printf ( "\n" );
  printf ( "I4_CHOOSE_LOG_TEST\n" );
  printf ( "  I4_CHOOSE_LOG evaluates log(C(N,K)).\n" );
  printf ( "\n" );
  printf ( "       N       K        log(CNK)   exp(log(CNK))     CNK\n" );

  for ( n = 0; n <= 4; n++ )
  {
    printf ( "\n" );
    for ( k = 0; k <= n; k++ )
    {
      lcnk = i4_choose_log ( n, k );
      elcnk = exp ( lcnk );
      cnk = i4_choose ( n, k );

      printf ( "  %6d  %6d  %14.6g  %14.6g  %6d\n", n, k, lcnk, elcnk, cnk );
    }
  }

  return;
}
/******************************************************************************/

void i4_is_power_of_10_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_IS_POWER_OF_10_TEST tests I4_IS_POWER_OF_10.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 March 2016

  Author:

    John Burkardt
*/
{
  int i;

  printf ( "\n" );
  printf ( "I4_IS_POWER_OF_10_TEST\n" );
  printf ( "  I4_IS_POWER_OF_10 reports whether an I4 is a power of 10.\n" );
  printf ( "\n" );
  printf ( "  I     I4_IS_POWER_OF_10(I)\n" );
  printf ( "\n" );

  for ( i = 97; i <= 103; i++ )
  {
    printf ( "  %6d  %1d\n", i, i4_is_power_of_10 ( i ) );
  }

  return;
}
/******************************************************************************/

void i4_uniform_ab_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_UNIFORM_AB_TEST tests I4_UNIFORM_AB.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 October 2014

  Author:

    John Burkardt
*/
{
  int a = -100;
  int b = 200;
  int i;
  int j;
  int seed = 123456789;

  printf ( "\n" );
  printf ( "I4_UNIFORM_AB_TEST\n" );
  printf ( "  I4_UNIFORM_AB computes pseudorandom values\n" );
  printf ( "  in an interval [A,B].\n" );

  printf ( "\n" );
  printf ( "  The lower endpoint A = %d\n", a );
  printf ( "  The upper endpoint B = %d\n", b );
  printf ( "  The initial seed is %d\n", seed );
  printf ( "\n" );

  for ( i = 1; i <= 20; i++ )
  {
    j = i4_uniform_ab ( a, b, &seed );
    printf ( "  %8d  %d\n", i, j );
  }

  return;
}
/******************************************************************************/

void i4vec_uniform_ab_new_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_UNIFORM_AB_NEW_TEST tests I4VEC_UNIFORM_AB_NEW.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 October 2014

  Author:

    John Burkardt
*/
{
  int a = -100;
  int b = 200;
  int n = 20;
  int seed = 123456789;
  int *v;

  printf ( "\n" );
  printf ( "I4VEC_UNIFORM_AB_NEW_TEST\n" );
  printf ( "  I4VEC_UNIFORM_AB_NEW computes pseudorandom values\n" );
  printf ( "  in an interval [A,B].\n" );

  printf ( "\n" );
  printf ( "  The lower endpoint A = %d\n", a );
  printf ( "  The upper endpoint B = %d\n", b );
  printf ( "  The initial seed is %d\n", seed );
  printf ( "\n" );

  v = i4vec_uniform_ab_new ( n, a, b, &seed );

  i4vec_print ( n, v, "  The vector:" );

  free ( v );

  return;
}
/******************************************************************************/

void i4vec_unique_count_test ( )

/******************************************************************************/
/*
  Purpose:

    I4VEC_UNIQUE_COUNT_TEST tests I4VEC_UNIQUE_COUNT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 March 2016

  Author:

    John Burkardt
*/
{
  int *a;
  int a_hi;
  int a_lo;
  int a_unique;
  int n;
  int seed;

  printf ( "\n" );
  printf ( "I4VEC_UNIQUE_COUNT_TEST\n" );
  printf ( "  I4VEC_UNIQUE_COUNT counts unique entries in an I4VEC.\n" );

  n = 20;
  a_lo = 0;
  a_hi = n;
  seed = 123456789;

  a = i4vec_uniform_ab_new ( n, a_lo, a_hi, &seed );

  i4vec_print ( n, a, "  Array:" );

  a_unique = i4vec_unique_count ( n, a  );

  printf ( "\n" );
  printf ( "  Number of unique entries is %d\n", a_unique );

  free ( a );

  return;
}
/******************************************************************************/

void inverse_gaussian_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    INVERSE_GAUSSIAN_CDF_TEST tests INVERSE_GAUSSIAN_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;

  printf ( "\n" );
  printf ( "INVERSE_GAUSSIAN_CDF_TEST\n" );
  printf ( "  INVERSE_GAUSSIAN_CDF evaluates the Inverse Gaussian CDF;\n" );
  printf ( "  INVERSE_GAUSSIAN_PDF evaluates the Inverse Gaussian PDF;\n" );

  a = 5.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! inverse_gaussian_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "INVERSE_GAUSSIAN_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = inverse_gaussian_sample ( a, b, &seed );
    pdf = inverse_gaussian_pdf ( x, a, b );
    cdf = inverse_gaussian_cdf ( x, a, b );

    printf ( "  %12g  %12g  %12g\n", x, pdf, cdf );
  }

  return;
}
/******************************************************************************/

void inverse_gaussian_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    INVERSE_GAUSSIAN_SAMPLE_TEST tests INVERSE_GAUSSIAN_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "INVERSE_GAUSSIAN_SAMPLE_TEST\n" );
  printf ( "  INVERSE_GAUSSIAN_MEAN computes the Inverse Gaussian mean;\n" );
  printf ( "  INVERSE_GAUSSIAN_SAMPLE samples the Inverse Gaussian distribution;\n" );
  printf ( "  INVERSE_GAUSSIAN_VARIANCE computes the Inverse Gaussian variance;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! inverse_gaussian_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "INVERSE_GAUSSIAN_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = inverse_gaussian_mean ( a, b );
  variance = inverse_gaussian_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = inverse_gaussian_sample ( a, b, &seed );
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
/******************************************************************************/

void laplace_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    LAPLACE_CDF_TEST tests LAPLACE_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "LAPLACE_CDF_TEST\n" );
  printf ( "  LAPLACE_CDF evaluates the Laplace CDF;\n" );
  printf ( "  LAPLACE_CDF_INV inverts the Laplace CDF.\n" );
  printf ( "  LAPLACE_PDF evaluates the Laplace PDF;\n" );

  a = 1.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! laplace_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "LAPLACE_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = laplace_sample ( a, b, &seed );
    pdf = laplace_pdf ( x, a, b );
    cdf = laplace_cdf ( x, a, b );
    x2 = laplace_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void laplace_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    LAPLACE_SAMPLE_TEST tests LAPLACE_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 March 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "LAPLACE_SAMPLE_TEST\n" );
  printf ( "  LAPLACE_MEAN computes the Laplace mean;\n" );
  printf ( "  LAPLACE_SAMPLE samples the Laplace distribution;\n" );
  printf ( "  LAPLACE_VARIANCE computes the Laplace variance;\n" );

  a = 1.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! laplace_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "LAPLACE_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = laplace_mean ( a, b );
  variance = laplace_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = laplace_sample ( a, b, &seed );
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
/******************************************************************************/

void levy_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    LEVY_CDF_TEST tests LEVY_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "LEVY_CDF_TEST\n" );
  printf ( "  LEVY_CDF evaluates the Levy CDF;\n" );
  printf ( "  LEVY_CDF_INV inverts the Levy CDF.\n" );
  printf ( "  LEVY_PDF evaluates the Levy PDF;\n" );

  a = 1.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = levy_sample ( a, b, &seed );
    pdf = levy_pdf ( x, a, b );
    cdf = levy_cdf ( x, a, b );
    x2 = levy_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void logistic_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    LOGISTIC_CDF_TEST tests LOGISTIC_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "LOGISTIC_CDF_TEST\n" );
  printf ( "  LOGISTIC_CDF evaluates the Logistic CDF;\n" );
  printf ( "  LOGISTIC_CDF_INV inverts the Logistic CDF.\n" );
  printf ( "  LOGISTIC_PDF evaluates the Logistic PDF;\n" );

  a = 1.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! logistic_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "LOGISTIC_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = logistic_sample ( a, b, &seed );
    pdf = logistic_pdf ( x, a, b );
    cdf = logistic_cdf ( x, a, b );
    x2 = logistic_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void logistic_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    LOGISTIC_SAMPLE_TEST tests LOGISTIC_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "LOGISTIC_SAMPLE_TEST\n" );
  printf ( "  LOGISTIC_MEAN computes the Logistic mean;\n" );
  printf ( "  LOGISTIC_SAMPLE samples the Logistic distribution;\n" );
  printf ( "  LOGISTIC_VARIANCE computes the Logistic variance;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! logistic_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "LOGISTIC_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = logistic_mean ( a, b );
  variance = logistic_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = logistic_sample ( a, b, &seed );
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
/******************************************************************************/

void log_normal_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    LOG_NORMAL_CDF_TEST tests LOG_NORMAL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 March 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "LOG_NORMAL_CDF_TEST\n" );
  printf ( "  LOG_NORMAL_CDF evaluates the Log Normal CDF;\n" );
  printf ( "  LOG_NORMAL_CDF_INV inverts the Log Normal CDF.\n" );
  printf ( "  LOG_NORMAL_PDF evaluates the Log Normal PDF;\n" );

  a = 10.0;
  b = 2.25;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! log_normal_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "LOG_NORMAL_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = log_normal_sample ( a, b, &seed );
    pdf = log_normal_pdf ( x, a, b );
    cdf = log_normal_cdf ( x, a, b );
    x2 = log_normal_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void log_normal_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    LOG_NORMAL_SAMPLE_TEST tests LOG_NORMAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "LOG_NORMAL_SAMPLE_TEST\n" );
  printf ( "  LOG_NORMAL_MEAN computes the Log Normal mean;\n" );
  printf ( "  LOG_NORMAL_SAMPLE samples the Log Normal distribution;\n" );
  printf ( "  LOG_NORMAL_VARIANCE computes the Log Normal variance;\n" );

  a = 1.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! normal_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "LOG_NORMAL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = log_normal_mean ( a, b);
  variance = log_normal_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = log_normal_sample ( a, b, &seed );
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
/******************************************************************************/

void log_series_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    LOG_SERIES_CDF_TEST tests LOG_SERIES_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "LOG_SERIES_CDF_TEST\n" );
  printf ( "  LOG_SERIES_CDF evaluates the Log Series CDF;\n" );
  printf ( "  LOG_SERIES_CDF_INV inverts the Log Series CDF.\n" );
  printf ( "  LOG_SERIES_PDF evaluates the Log Series PDF;\n" );

  a = 0.25E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a   );

  if ( ! log_series_check ( a ) )
  {
    printf ( "\n" );
    printf ( "LOG_SERIES_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = log_series_sample ( a, &seed );
    pdf = log_series_pdf ( x, a );
    cdf = log_series_cdf ( x, a );
    x2 = log_series_cdf_inv ( cdf, a );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void log_series_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    LOG_SERIES_SAMPLE_TEST tests LOG_SERIES_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  int j;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "LOG_SERIES_SAMPLE_TEST\n" );
  printf ( "  LOG_SERIES_MEAN computes the Log Series mean;\n" );
  printf ( "  LOG_SERIES_SAMPLE samples the Log Series distribution;\n" );
  printf ( "  LOG_SERIES_VARIANCE computes the Log Series variance.\n" );

  a = 0.25E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a        );

  if ( ! log_series_check ( a ) )
  {
    printf ( "\n" );
    printf ( "LOG_SERIES_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = log_series_mean ( a );
  variance = log_series_variance ( a );

  printf ( "  PDF mean =                    %g\n", mean     );
  printf ( "  PDF variance =                %g\n", variance );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    x[j] = log_series_sample ( a, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax     );
  printf ( "  Sample minimum =  %d\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void log_uniform_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    LOG_UNIFORM_CDF_TEST tests LOG_UNIFORM_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "LOG_UNIFORM_CDF_TEST\n" );
  printf ( "  LOG_UNIFORM_CDF evaluates the Log Uniform CDF;\n" );
  printf ( "  LOG_UNIFORM_CDF_INV inverts the Log Uniform CDF.\n" );
  printf ( "  LOG_UNIFORM_PDF evaluates the Log Uniform PDF;\n" );

  a = 2.0;
  b = 20.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! log_uniform_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "LOG_UNIFORM_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = log_uniform_sample ( a, b, &seed );
    pdf = log_uniform_pdf ( x, a, b );
    cdf = log_uniform_cdf ( x, a, b );
    x2 = log_uniform_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void log_uniform_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    LOG_UNIFORM_SAMPLE_TEST tests LOG_UNIFORM_SAMPLE;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "LOG_UNIFORM_SAMPLE_TEST\n" );
  printf ( "  LOG_UNIFORM_MEAN computes the Log Uniform mean;\n" );
  printf ( "  LOG_UNIFORM_SAMPLE samples the Log Uniform distribution;\n" );

  a = 2.0;
  b = 20.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! log_uniform_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "LOG_UNIFORM_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = log_uniform_mean ( a, b);

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = log_uniform_sample ( a, b, &seed );
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
/******************************************************************************/

void lorentz_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    LORENTZ_CDF_TEST tests LORENTZ_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "LORENTZ_CDF_TEST\n" );
  printf ( "  LORENTZ_CDF evaluates the Lorentz CDF;\n" );
  printf ( "  LORENTZ_CDF_INV inverts the Lorentz CDF.\n" );
  printf ( "  LORENTZ_PDF evaluates the Lorentz PDF;\n" );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = lorentz_sample ( &seed );
    pdf = lorentz_pdf ( x );
    cdf = lorentz_cdf ( x );
    x2 = lorentz_cdf_inv ( cdf );

    printf ( "  %12g   %12g  %12g  %12g\n", x, pdf, cdf, x2  );
  }

  return;
}
/******************************************************************************/

void lorentz_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    LORENTZ_SAMPLE_TEST tests LORENTZ_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "LORENTZ_SAMPLE_TEST\n" );
  printf ( "  LORENTZ_MEAN computes the Lorentz mean;\n" );
  printf ( "  LORENTZ_SAMPLE samples the Lorentz distribution;\n" );
  printf ( "  LORENTZ_VARIANCE computes the Lorentz variance.\n" );

  mean     = lorentz_mean ( );
  variance = lorentz_variance ( );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = lorentz_sample ( &seed );
  }

  mean     = r8vec_mean     ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax     = r8vec_max      ( SAMPLE_NUM, x );
  xmin     = r8vec_min      ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax     );
  printf ( "  Sample minimum =  %g\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void maxwell_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    MAXWELL_CDF_TEST tests MAXWELL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "MAXWELL_CDF_TEST\n" );
  printf ( "  MAXWELL_CDF evaluates the Maxwell CDF;\n" );
  printf ( "  MAXWELL_CDF_INV inverts the Maxwell CDF.\n" );
  printf ( "  MAXWELL_PDF evaluates the Maxwell PDF;\n" );

  a = 2.0E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a   );

  if ( ! maxwell_check ( a ) )
  {
    printf ( "\n" );
    printf ( "MAXWELL_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }
  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = maxwell_sample ( a, &seed );
    pdf = maxwell_pdf ( x, a );
    cdf = maxwell_cdf ( x, a );
    x2 = maxwell_cdf_inv ( cdf, a );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void maxwell_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    MAXWELL_SAMPLE_TEST tests MAXWELL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  int j;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "MAXWELL_SAMPLE_TEST\n" );
  printf ( "  MAXWELL_MEAN computes the Maxwell mean;\n" );
  printf ( "  MAXWELL_SAMPLE samples the Maxwell distribution;\n" );
  printf ( "  MAXWELL_VARIANCE computes the Maxwell variance.\n" );

  a = 2.0E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a        );

  if ( ! maxwell_check ( a ) )
  {
    printf ( "\n" );
    printf ( "MAXWELL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = maxwell_mean ( a );
  variance = maxwell_variance ( a );

  printf ( "  PDF mean =                    %g\n", mean     );
  printf ( "  PDF variance =                %g\n", variance );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    x[j] = maxwell_sample ( a, &seed );
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
/******************************************************************************/

void multinomial_coef_test ( )

/******************************************************************************/
/*
  Purpose:

    MULTINOMIAL_COEF_TEST tests MULTINOMIAL_COEF1, MULTINOMIAL_COEF2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 April 2016

  Author:

    John Burkardt
*/
{
# define MAXFACTOR 5

  int factor[MAXFACTOR];
  int i;
  int j;
  int n;
  int ncomb1;
  int ncomb2;
  int nfactor;

  printf ( "\n" );
  printf ( "MULTINOMIAL_COEF_TEST\n" );
  printf ( "  MULTINOMIAL_COEF1 computes multinomial\n" );
  printf ( "  coefficients using the Gamma function;\n" );
  printf ( "  MULTINOMIAL_COEF2 computes multinomial\n" );
  printf ( "  coefficients directly.\n" );

  printf ( "\n" );
  printf ( "  Line 10 of the BINOMIAL table:\n" );
  printf ( "\n" );

  n = 10;
  nfactor = 2;

  for ( i = 0; i <= n; i++ )
  {
    factor[0] = i;
    factor[1] = n - i;

    ncomb1 = multinomial_coef1 ( nfactor, factor );

    ncomb2 = multinomial_coef2 ( nfactor, factor );

    printf ( "  %2d  %2d  %5d  %5d\n",
      factor[0], factor[1], ncomb1, ncomb2 );
  }

  printf ( "\n" );
  printf ( "  Level 5 of the TRINOMIAL coefficients:\n" );

  n = 5;
  nfactor = 3;

  for ( i = 0; i <= n; i++ )
  {
    factor[0] = i;

    printf ( "\n" );

    for ( j = 0; j <= n - factor[0]; j++ )
    {
      factor[1] = j;
      factor[2] = n - factor[0] - factor[1];

      ncomb1 = multinomial_coef1 ( nfactor, factor );

      ncomb2 = multinomial_coef2 ( nfactor, factor );

      printf ( "  %2d  %2d  %2d  %5d  %5d\n",
        factor[0], factor[1], factor[2], ncomb1, ncomb2 );
    }
  }

  return;
# undef MAXFACTOR
}
/******************************************************************************/

void multinomial_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    MULTINOMIAL_SAMPLE_TEST tests MULTINOMIAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 April 2016

  Author:

    John Burkardt
*/
{
# define B 3
# define SAMPLE_NUM 1000

  int a;
  double c[B] = { 0.125, 0.500, 0.375 };
  int i;
  int j;
  double *mean;
  int seed = 123456789;
  double *variance;
  int x[B*SAMPLE_NUM];
  int *xmax;
  int *xmin;
  int *y;

  printf ( "\n" );
  printf ( "MULTINOMIAL_SAMPLE_TEST\n" );
  printf ( "  MULTINOMIAL_MEAN computes the Multinomial mean;\n" );
  printf ( "  MULTINOMIAL_SAMPLE samples the Multinomial distribution;\n" );
  printf ( "  MULTINOMIAL_VARIANCE computes the Multinomial variance;\n" );

  a = 5;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %d\n", a );
  printf ( "  PDF parameter B =      %d\n", B );
  r8vec_print ( B, c, "  PDF parameter C:" );

  if ( ! multinomial_check ( a, B, c ) )
  {
    printf ( "\n" );
    printf ( "MULTINOMIAL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = multinomial_mean ( a, B, c );
  variance = multinomial_variance ( a, B, c );
  r8vec_print ( B, mean, "  PDF mean:" );
  r8vec_print ( B, variance, "  PDF variance:" );

  free ( mean );
  free ( variance );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    y = multinomial_sample ( a, B, c, &seed );
    for ( i = 0; i < B; i++ )
    {
      x[i+j*B] = y[i];
    }
    free ( y );
  }

  mean = i4row_mean ( B, SAMPLE_NUM, x );
  variance = i4row_variance ( B, SAMPLE_NUM, x );
  xmax = i4row_max ( B, SAMPLE_NUM, x );
  xmin = i4row_min ( B, SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "\n" );
  printf ( "  Component Mean, Variance, Min, Max:\n" );
  printf ( "\n" );

  for ( i = 0; i < B; i++ )
  {
    printf ( "  %6d  %12g  %12g  %12d  %12d\n", 
      i+1, mean[i], variance[i], xmin[i], xmax[i] );
  }

  free ( mean );
  free ( variance );
  free ( xmax );
  free ( xmin );

  return;
# undef B
# undef SAMPLE_NUM
}
/******************************************************************************/

void multinomial_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    MULTINOMIAL_PDF_TEST tests MULTINOMIAL_PDF;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 April 2016

  Author:

    John Burkardt
*/
{
# define B 3

  int a;
  double c[B] = { 0.1, 0.5, 0.4 };
  double pdf;
  int x[B] = { 0, 2, 3 };

  printf ( "\n" );
  printf ( "MULTINOMIAL_PDF_TEST\n" );
  printf ( "  MULTINOMIAL_PDF evaluates the Multinomial PDF;\n" );

  a = 5;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %d\n", a );
  printf ( "  PDF parameter B =      %d\n", B );
  r8vec_print ( B, c, "  PDF parameter C:" );

  if ( ! multinomial_check ( a, B, c ) )
  {
    printf ( "\n" );
    printf ( "MULTINOMIAL_PDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  i4vec_print ( B, x, "  PDF argument X:" );

  pdf = multinomial_pdf ( x, a, B, c );

  printf ( "\n" );
  printf ( "  PDF value = %g\n", pdf);

  return;
# undef B
# undef SAMPLE_NUM
}
/******************************************************************************/

void multinoulli_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    MULTINOULLLI_PDF_TEST tests MULTINOULLI_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 September 2018

  Author:

    John Burkardt
*/
{
  int n = 5;
  double pdf;
  int seed;
  double *theta;
  double theta_sum;
  int x;

  printf ( "\n" );
  printf ( "MULTINOULLI_PDF_TEST\n" );
  printf ( "  MULTINOULLI_PDF evaluates the Multinoulli PDF.\n" );

  seed = 123456789;
  theta = r8vec_uniform_01_new ( n, &seed );
  theta_sum = 0.0;
  for ( x = 0; x < n; x++ )
  {
    theta_sum = theta_sum + theta[x];
  }
  for ( x = 0; x < n; x++ )
  {
    theta[x] = theta[x] / theta_sum;
  }

  printf ( "\n" );
  printf ( "   X     pdf(X)\n" );
  printf ( "\n" );
  for ( x = -1; x <= n; x++ )
  {
    pdf = multinoulli_pdf ( x, n, theta );
    printf ( "  %2d  %14.6g\n", x, pdf );
  }

  free ( theta );

  return;
}
/******************************************************************************/

void nakagami_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    NAKAGAMI_CDF_TEST tests NAKAGAMI_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double cdf;
  int i;
  double pdf;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "NAKAGAMI_CDF_TEST\n" );
  printf ( "  NAKAGAMI_CDF evaluates the Nakagami CDF;\n" );
  printf ( "  NAKAGAMI_CDF_INV inverts the Nakagami CDF;\n" );
  printf ( "  NAKAGAMI_PDF evaluates the Nakagami PDF;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! nakagami_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "NAKAGAMI_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF         CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = a + b * sqrt ( ( double ) ( i ) / c / 10.0 ); 
    pdf = nakagami_pdf ( x, a, b, c );
    cdf = nakagami_cdf ( x, a, b, c );
    x2 = nakagami_cdf_inv ( cdf, a, b, c );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void nakagami_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    NAKAGAMI_SAMPLE_TEST tests NAKAGAMI_SAMPLE;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double mean;
  double variance;

  printf ( "\n" );
  printf ( "NAKAGAMI_SAMPLE_TEST\n" );
  printf ( "  NAKAGAMI_MEAN evaluates the Nakagami mean;\n" );
  printf ( "  NAKAGAMI_VARIANCE evaluates the Nakagami variance;\n" );

  a = 1.0;
  b = 2.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! nakagami_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "NAKAGAMI_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = nakagami_mean ( a, b, c );
  variance = nakagami_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =      %g\n", mean     );
  printf ( "  PDF variance =  %g\n", variance );

  return;
}
/******************************************************************************/

void negative_binomial_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    NEGATIVE_BINOMIAL_CDF_TEST tests NEGATIVE_BINOMIAL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
  int a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "NEGATIVE_BINOMIAL_CDF_TEST\n" );
  printf ( "  NEGATIVE_BINOMIAL_CDF evaluates the Negative Binomial CDF;\n" );
  printf ( "  NEGATIVE_BINOMIAL_CDF_INV inverts the Negative Binomial CDF.\n" );
  printf ( "  NEGATIVE_BINOMIAL_PDF evaluates the Negative Binomial PDF;\n" );

  a = 2;
  b = 0.25;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %d\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! negative_binomial_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "NEGATIVE_BINOMIAL_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = negative_binomial_sample ( a, b, &seed );
    pdf = negative_binomial_pdf ( x, a, b );
    cdf = negative_binomial_cdf ( x, a, b );
    x2 = negative_binomial_cdf_inv ( cdf, a, b );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void negative_binomial_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    NEGATIVE_BINOMIAL_SAMPLE_TEST tests NEGATIVE_BINOMIAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "NEGATIVE_BINOMIAL_SAMPLE_TEST\n" );
  printf ( "  NEGATIVE_BINOMIAL_MEAN computes the Negative Binomial mean;\n" );
  printf ( "  NEGATIVE_BINOMIAL_SAMPLE samples the Negative Binomial distribution;\n" );
  printf ( "  NEGATIVE_BINOMIAL_VARIANCE computes the Negative Binomial variance;\n" );

  a = 2;
  b = 0.75;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %d\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! negative_binomial_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "NEGATIVE_BINOMIAL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = negative_binomial_mean ( a, b );
  variance = negative_binomial_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = negative_binomial_sample ( a, b, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax     );
  printf ( "  Sample minimum =  %d\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void normal_01_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_01_CDF_TEST tests NORMAL_01_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2013

  Author:

    John Burkardt
*/
{
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "NORMAL_01_CDF_TEST\n" );
  printf ( "  NORMAL_01_CDF evaluates the Normal 01 CDF;\n" );
  printf ( "  NORMAL_01_CDF_INV inverts the Normal 01 CDF.\n" );
  printf ( "  NORMAL_01_PDF evaluates the Normal 01 PDF;\n" );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = normal_01_sample ( &seed );
    pdf = normal_01_pdf ( x );
    cdf = normal_01_cdf ( x );
    x2 = normal_01_cdf_inv ( cdf );

    printf ( "  %24.16g  %12.6g  %12.6g  %24.16g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void normal_01_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_01_SAMPLE_TEST tests NORMAL_01_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "NORMAL_01_SAMPLE_TEST\n" );
  printf ( "  NORMAL_01_MEAN computes the Normal 01 mean;\n" );
  printf ( "  NORMAL_01_SAMPLE samples the Normal 01 distribution;\n" );
  printf ( "  NORMAL_01_VARIANCE computes the Normal 01 variance;\n" );

  mean = normal_01_mean ( );
  variance = normal_01_variance ( );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = normal_01_sample ( &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void normal_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_CDF_TEST tests NORMAL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 August 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "NORMAL_CDF_TEST\n" );
  printf ( "  NORMAL_CDF evaluates the Normal CDF;\n" );
  printf ( "  NORMAL_CDF_INV inverts the Normal CDF.\n" );
  printf ( "  NORMAL_PDF evaluates the Normal PDF;\n" );

  a = 100.0;
  b = 15.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! normal_check ( a, b ) )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "NORMAL_CDF_TEST - Fatal error!\n" );
    fprintf ( stderr, "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = normal_sample ( a, b, &seed );
    pdf = normal_pdf ( x, a, b );
    cdf = normal_cdf ( x, a, b );
    x2 = normal_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void normal_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_SAMPLE_TEST tests NORMAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    20 August 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "NORMAL_SAMPLE_TEST\n" );
  printf ( "  NORMAL_MEAN computes the Normal mean;\n" );
  printf ( "  NORMAL_SAMPLE samples the Normal distribution;\n" );
  printf ( "  NORMAL_VARIANCE computes the Normal variance;\n" );

  a = 100.0;
  b = 15.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! normal_check ( a, b ) )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "NORMAL_SAMPLE_TEST - Fatal error!\n" );
    fprintf ( stderr, "  The parameters are not legal.\n" );
    return;
  }

  mean = normal_mean ( a, b );
  variance = normal_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = normal_sample ( a, b, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void normal_truncated_ab_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_TRUNCATED_AB_CDF_TEST tests NORMAL_TRUNCATED_AB_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 April 2016

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
  double s;
  int seed;
  double x;
  double x2;

  a = 50.0;
  b = 150.0;
  mu = 100.0;
  s = 25.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "NORMAL_TRUNCATED_AB_CDF_TEST\n" );
  printf ( "  NORMAL_TRUNCATED_AB_CDF evaluates the Normal Truncated ABCDF.\n" );
  printf ( "  NORMAL_TRUNCATED_AB_CDF_INV inverts the Normal Truncated ABCDF.\n" );
  printf ( "  NORMAL_TRUNCATED_AB_PDF evaluates the Normal Truncated ABPDF.\n" );
  printf ( "\n" );
  printf ( "  The parent normal distribution has\n" );
  printf ( "    mean =               %g\n", mu );
  printf ( "    standard deviation = %g\n", s );
  printf ( "  The parent distribution is truncated to\n" );
  printf ( "  the interval [%g,%g]\n", a, b );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = normal_truncated_ab_sample ( mu, s, a, b, &seed );

    pdf = normal_truncated_ab_pdf ( x, mu, s, a, b );

    cdf = normal_truncated_ab_cdf ( x, mu, s, a, b );

    x2 = normal_truncated_ab_cdf_inv ( cdf, mu, s, a, b );

    printf ( "  %14.6g%14.6g%14.6g%14.6g\n", x, pdf, cdf, x2 );
  }
  return;
}
/******************************************************************************/

void normal_truncated_ab_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_TRUNCATED_AB_SAMPLE_TEST tests NORMAL_TRUNCATED_AB_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int i;
  double mean;
  double mu;
  double s;
  int sample_num = 1000;
  int seed;
  double variance;
  double *x;
  double xmax;
  double xmin;

  a = 50.0;
  b = 150.0;
  mu = 100.0;
  s = 25.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "NORMAL_TRUNCATED_AB_SAMPLE_TEST\n" );
  printf ( "  NORMAL_TRUNCATED_AB_MEAN computes the Normal Truncated AB mean;\n" );
  printf ( "  NORMAL_TRUNCATED_AB_SAMPLE samples the Normal Truncated ABdistribution;\n" );
  printf ( "  NORMAL_TRUNCATED_AB_VARIANCE computes the Normal Truncated ABvariance.\n" );
  printf ( "\n" );
  printf ( "  The parent normal distribution has\n" );
  printf ( "    mean =               %g\n", mu );
  printf ( "    standard deviation = %g\n", s );
  printf ( "  The parent distribution is truncated to\n" );
  printf ( "  the interval [%g,%g]\n", a, b );

  mean = normal_truncated_ab_mean ( mu, s, a, b );

  variance = normal_truncated_ab_variance ( mu, s, a, b );

  printf ( "\n" );
  printf ( "  PDF mean      =               %g\n", mean );
  printf ( "  PDF variance =                %g\n", variance );

  x = ( double * ) malloc ( sample_num * sizeof ( double ) );

  for ( i = 0; i < sample_num; i++ )
  {
    x[i] = normal_truncated_ab_sample ( mu, s, a, b, &seed );
  }

  mean = r8vec_mean ( sample_num, x );
  variance = r8vec_variance ( sample_num, x );
  xmax = r8vec_max ( sample_num, x );
  xmin = r8vec_min ( sample_num, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", sample_num );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  free ( x );

  return;
}
/******************************************************************************/

void normal_truncated_a_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_TRUNCATED_A_CDF_TEST tests NORMAL_TRUNCATED_A_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double cdf;
  int i;
  double mu;
  double pdf;
  double s;
  int seed;
  double x;
  double x2;

  a = 50.0;
  mu = 100.0;
  s = 25.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "NORMAL_TRUNCATED_A_CDF_TEST\n" );
  printf ( "  NORMAL_TRUNCATED_A_CDF evaluates the Normal Truncated A CDF.\n" );
  printf ( "  NORMAL_TRUNCATED_A_CDF_INV inverts the Normal Truncated A CDF.\n" );
  printf ( "  NORMAL_TRUNCATED_A_PDF evaluates the Normal Truncated A PDF.\n" );
  printf ( "\n" );
  printf ( "  The parent normal distribution has\n" );
  printf ( "    mean =               %g\n", mu );
  printf ( "    standard deviation = %g\n", s );
  printf ( "  The parent distribution is truncated to\n" );
  printf ( "  the interval [%g,+oo]\n", a );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = normal_truncated_a_sample ( mu, s, a, &seed );

    pdf = normal_truncated_a_pdf ( x, mu, s, a );

    cdf = normal_truncated_a_cdf ( x, mu, s, a );

    x2 = normal_truncated_a_cdf_inv ( cdf, mu, s, a );

    printf ( "  %14.6g%14.6g%14.6g%14.6g\n", x, pdf, cdf, x2 );
  }
  return;
}
/******************************************************************************/

void normal_truncated_a_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_TRUNCATED_A_SAMPLE_TEST tests NORMAL_TRUNCATED_A_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  int i;
  double mean;
  double mu;
  double s;
  int sample_num = 1000;
  int seed;
  double variance;
  double *x;
  double xmax;
  double xmin;

  a = 50.0;
  mu = 100.0;
  s = 25.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "NORMAL_TRUNCATED_A_SAMPLE_TEST\n" );
  printf ( "  NORMAL_TRUNCATED_A_MEAN computes the Normal Truncated A mean;\n" );
  printf ( "  NORMAL_TRUNCATED_A_SAMPLE samples the Normal Truncated A distribution;\n" );
  printf ( "  NORMAL_TRUNCATED_A_VARIANCE computes the Normal Truncated A variance.\n" );
  printf ( "\n" );
  printf ( "  The parent normal distribution has\n" );
  printf ( "    mean =               %g\n", mu );
  printf ( "    standard deviation = %g\n", s );
  printf ( "  The parent distribution is truncated to\n" );
  printf ( "  the interval [%g,+oo]\n", a );

  mean = normal_truncated_a_mean ( mu, s, a );

  variance = normal_truncated_a_variance ( mu, s, a );

  printf ( "\n" );
  printf ( "  PDF mean      =               %g\n", mean );
  printf ( "  PDF variance =                %g\n", variance );

  x = ( double * ) malloc ( sample_num * sizeof ( double ) );

  for ( i = 0; i < sample_num; i++ )
  {
    x[i] = normal_truncated_a_sample ( mu, s, a, &seed );
  }

  mean = r8vec_mean ( sample_num, x );
  variance = r8vec_variance ( sample_num, x );
  xmax = r8vec_max ( sample_num, x );
  xmin = r8vec_min ( sample_num, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", sample_num );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  free ( x );

  return;
}
/******************************************************************************/

void normal_truncated_b_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_TRUNCATED_B_CDF_TEST tests NORMAL_TRUNCATED_B_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 April 2016

  Author:

    John Burkardt
*/
{
  double b;
  double cdf;
  int i;
  double mu;
  double pdf;
  double s;
  int seed;
  double x;
  double x2;

  b = 150.0;
  mu = 100.0;
  s = 25.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "NORMAL_TRUNCATED_B_CDF_TEST\n" );
  printf ( "  NORMAL_TRUNCATED_B_CDF evaluates the Normal Truncated B CDF.\n" );
  printf ( "  NORMAL_TRUNCATED_B_CDF_INV inverts the Normal Truncated B CDF.\n" );
  printf ( "  NORMAL_TRUNCATED_B_PDF evaluates the Normal Truncated B PDF.\n" );
  printf ( "\n" );
  printf ( "  The parent normal distribution has\n" );
  printf ( "    mean =               %g\n", mu );
  printf ( "    standard deviation = %g\n", s );
  printf ( "  The parent distribution is truncated to\n" );
  printf ( "  the interval [-oo,%g]\n", b );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = normal_truncated_b_sample ( mu, s, b, &seed );

    pdf = normal_truncated_b_pdf ( x, mu, s, b );

    cdf = normal_truncated_b_cdf ( x, mu, s, b );

    x2 = normal_truncated_b_cdf_inv ( cdf, mu, s, b );

    printf ( "  %14.6g%14.6g%14.6g%14.6g\n", x, pdf, cdf, x2 );
  }
  return;
}
/******************************************************************************/

void normal_truncated_b_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    NORMAL_TRUNCATED_B_SAMPLE_TEST tests NORMAL_TRUNCATED_B_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 April 2016

  Author:

    John Burkardt
*/
{
  double b;
  int i;
  double mean;
  double mu;
  double s;
  int sample_num = 1000;
  int seed;
  double variance;
  double *x;
  double xmax;
  double xmin;

  b = 150.0;
  mu = 100.0;
  s = 25.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "NORMAL_TRUNCATED_B_SAMPLE_TEST\n" );
  printf ( "  NORMAL_TRUNCATED_B_MEAN computes the Normal Truncated B mean;\n" );
  printf ( "  NORMAL_TRUNCATED_B_SAMPLE samples the Normal Truncated B distribution;\n" );
  printf ( "  NORMAL_TRUNCATED_B_VARIANCE computes the Normal Truncated B variance.\n" );
  printf ( "\n" );
  printf ( "  The parent normal distribution has\n" );
  printf ( "    mean =               %g\n", mu );
  printf ( "    standard deviation = %g\n", s );
  printf ( "  The parent distribution is truncated to\n" );
  printf ( "  the interval [-oo,%g]\n", b );

  mean = normal_truncated_b_mean ( mu, s, b );

  variance = normal_truncated_b_variance ( mu, s, b );

  printf ( "\n" );
  printf ( "  PDF mean      =               %g\n", mean );
  printf ( "  PDF variance =                %g\n", variance );

  x = ( double * ) malloc ( sample_num * sizeof ( double ) );

  for ( i = 0; i < sample_num; i++ )
  {
    x[i] = normal_truncated_b_sample ( mu, s, b, &seed );
  }

  mean = r8vec_mean ( sample_num, x );
  variance = r8vec_variance ( sample_num, x );
  xmax = r8vec_max ( sample_num, x );
  xmin = r8vec_min ( sample_num, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", sample_num );
  printf ( "  Sample mean =     %g\n", mean );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax );
  printf ( "  Sample minimum =  %g\n", xmin );

  free ( x );

  return;
}
/******************************************************************************/

void pareto_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    PARETO_CDF_TEST tests PARETO_CDF.

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
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "PARETO_CDF_TEST\n" );
  printf ( "  PARETO_CDF evaluates the Pareto CDF;\n" );
  printf ( "  PARETO_CDF_INV inverts the Pareto CDF.\n" );
  printf ( "  PARETO_PDF evaluates the Pareto PDF;\n" );

  a = 0.5;
  b = 5.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! pareto_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "PARETO_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = pareto_sample ( a, b, &seed );
    pdf = pareto_pdf ( x, a, b );
    cdf = pareto_cdf ( x, a, b );
    x2 = pareto_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void pareto_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    PARETO_SAMPLE_TEST tests PARETO_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "PARETO_SAMPLE_TEST\n" );
  printf ( "  PARETO_MEAN computes the Pareto mean;\n" );
  printf ( "  PARETO_SAMPLE samples the Pareto distribution;\n" );
  printf ( "  PARETO_VARIANCE computes the Pareto variance;\n" );

  a = 0.5;
  b = 5.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! pareto_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "PARETO_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = pareto_mean ( a, b );
  variance = pareto_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = pareto_sample ( a, b, &seed );
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
/******************************************************************************/

void pearson_05_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    PEARSON_05_PDF_TEST tests PEARSON_05_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double pdf;
  double x;

  printf ( "\n" );
  printf ( "PEARSON_05_PDF_TEST\n" );
  printf ( "  PEARSON_05_PDF evaluates the Pearson 05 PDF.\n" );

  x = 5.0;

  a = 1.0;
  b = 2.0;
  c = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A = %g\n", a   );
  printf ( "  PDF parameter B = %g\n", b   );
  printf ( "  PDF parameter C = %g\n", c   );

  if ( ! pearson_05_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "PEARSON_05_PDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  pdf = pearson_05_pdf ( x, a, b, c );

  printf ( "\n" );
  printf ( "  PDF argument X =  %g\n", x   );
  printf ( "  PDF value =       %g\n", pdf );

  return;
}
/******************************************************************************/

void planck_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    PLANCK_PDF_TEST tests PLANCK_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  int i;
  double pdf;
  int seed = 123456789;
  double x;

  printf ( "\n" );
  printf ( "PLANCK_PDF_TEST\n" );
  printf ( "  PLANCK_PDF evaluates the Planck PDF.\n" );
  printf ( "  PLANCK_SAMPLE samples the Planck PDF.\n" );

  a = 2.0E+00;
  b = 3.0E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A = %g\n", a );
  printf ( "  PDF parameter B = %g\n", b );

  if ( ! planck_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "PLANCK_PDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = planck_sample ( a, b, &seed );

    pdf = planck_pdf ( x, a, b );

    printf ( "  %12g  %12g\n", x, pdf );
  }

  return;
}
/******************************************************************************/

void planck_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    PLANCK_SAMPLE_TEST tests PLANCK_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "PLANCK_SAMPLE_TEST\n" );
  printf ( "  PLANCK_MEAN computes the Planck mean;\n" );
  printf ( "  PLANCK_SAMPLE samples the Planck distribution;\n" );
  printf ( "  PLANCK_VARIANCE computes the Planck variance;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! planck_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "PLANCK_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = planck_mean ( a, b );
  variance = planck_variance ( a, b );

  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = planck_sample ( a, b, &seed );
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
/******************************************************************************/

void poisson_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    POISSON_CDF_TEST tests POISSON_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 March 2016

  Author:

    John Burkardt
*/
{
  double a;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "POISSON_CDF_TEST\n" );
  printf ( "  POISSON_CDF evaluates the Poisson CDF;\n" );
  printf ( "  POISSON_CDF_INV inverts the Poisson CDF.\n" );
  printf ( "  POISSON_PDF evaluates the Poisson PDF;\n" );

  a = 10.0E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a   );

  if ( ! poisson_check ( a ) )
  {
    printf ( "\n" );
    printf ( "POISSON_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = poisson_sample ( a, &seed );
    pdf = poisson_pdf ( x, a );
    cdf = poisson_cdf ( x, a );
    x2 = poisson_cdf_inv ( cdf, a );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void poisson_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    POISSON_SAMPLE_TEST tests POISSON_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "POISSON_SAMPLE_TEST\n" );
  printf ( "  POISSON_SAMPLE samples the Poisson PDF.\n" );
  printf ( "  POISSON_SAMPLE samples the Poisson PDF.\n" );
  printf ( "  POISSON_SAMPLE samples the Poisson PDF.\n" );

  a = 10.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );

  if ( ! poisson_check ( a ) )
  {
    printf ( "\n" );
    printf ( "POISSON_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = poisson_mean ( a );
  variance = poisson_variance ( a );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = poisson_sample ( a, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax     );
  printf ( "  Sample minimum =  %d\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void power_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    POWER_CDF_TEST tests POWER_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "POWER_CDF_TEST\n" );
  printf ( "  POWER_CDF evaluates the Power CDF;\n" );
  printf ( "  POWER_CDF_INV inverts the Power CDF.\n" );
  printf ( "  POWER_PDF evaluates the Power PDF;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! power_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "POWER_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = power_sample ( a, b, &seed );
    pdf = power_pdf ( x, a, b );
    cdf = power_cdf ( x, a, b );
    x2 = power_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void power_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    POWER_SAMPLE_TEST tests POWER_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "POWER_SAMPLE_TEST\n" );
  printf ( "  POWER_MEAN computes the Power mean;\n" );
  printf ( "  POWER_SAMPLE samples the Power distribution;\n" );
  printf ( "  POWER_VARIANCE computes the Power variance;\n" );

  a = 2.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! power_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "POWER_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = power_mean ( a, b );
  variance = power_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = power_sample ( a, b, &seed );
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
/******************************************************************************/

void quasigeometric_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    QUASIGEOMETRIC_CDF_TEST tests QUASIGEOMETRIC_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "QUASIGEOMETRIC_CDF_TEST\n" );
  printf ( "  QUASIGEOMETRIC_CDF evaluates the Quasigeometric CDF;\n" );
  printf ( "  QUASIGEOMETRIC_CDF_INV inverts the Quasigeometric CDF.\n" );
  printf ( "  QUASIGEOMETRIC_PDF evaluates the Quasigeometric PDF;\n" );

  a = 0.4825;
  b = 0.5893;

  printf ( "\n" );
  printf ( "  PDF parameter A = %g\n", a   );
  printf ( "  PDF parameter B = %g\n", b   );

  if ( ! quasigeometric_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "QUASIGEOMETRIC_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = quasigeometric_sample ( a, b, &seed );
    pdf = quasigeometric_pdf ( x, a, b );
    cdf = quasigeometric_cdf ( x, a, b );
    x2 = quasigeometric_cdf_inv ( cdf, a, b );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void quasigeometric_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    QUASIGEOMETRIC_SAMPLE_TEST tests QUASIGEOMETRIC_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int j;
  double mean;
  int seed = 123456789;
  double variance;
  int *x;
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "QUASIGEOMETRIC_SAMPLE_TEST\n" );
  printf ( "  QUASIGEOMETRIC_MEAN computes the Quasigeometric mean;\n" );
  printf ( "  QUASIGEOMETRIC_SAMPLE samples the Quasigeometric distribution;\n" );
  printf ( "  QUASIGEOMETRIC_VARIANCE computes the Quasigeometric variance.\n" );

  a = 0.4825;
  b = 0.5893;

  printf ( "\n" );
  printf ( "  PDF parameter A = %g\n", a );
  printf ( "  PDF parameter B = %g\n", b );

  if ( ! quasigeometric_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "QUASIGEOMETRIC_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = quasigeometric_mean ( a, b );
  variance = quasigeometric_variance ( a, b );

  printf ( "  PDF mean =                    %g\n", mean     );
  printf ( "  PDF variance =                %g\n", variance );

  x = ( int * ) malloc ( SAMPLE_NUM * sizeof ( int ) );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    x[j] = quasigeometric_sample ( a, b, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax     );
  printf ( "  Sample minimum =  %d\n", xmin     );

  free ( x );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void r8_beta_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BETA_TEST tests R8_BETA;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 March 2016

  Author:

    John Burkardt
*/
{
  double f1;
  double f2;
  int n_data;
  double x;
  double y;

  printf ( "\n" );
  printf ( "R8_BETA_TEST:\n" );
  printf ( "  R8_BETA evaluates the Beta function.\n" );
  printf ( "\n" );
  printf ( "             X              Y                BETA(X,Y)              R8_BETA(X,Y)\n" );
  printf ( "                                             tabulated                  computed\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    beta_values ( &n_data, &x, &y, &f1 );

    if ( n_data == 0 )
    {
      break;
    }
    f2 = r8_beta ( x, y );

    printf ( "  %12g  %12g  %24.16g  %24.16g\n", x,  y, f1, f2 );
  }
  return;
}
/******************************************************************************/

void r8_ceiling_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_CEILING_TEST tests R8_CEILING.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 September 2013

  Author:

    John Burkardt
*/
{
  int i;
  int ival;
  double rval;

  printf ( "\n" );
  printf ( "R8_CEILING_TEST\n" );
  printf ( "  R8_CEILING rounds an R8 up.\n" );
  printf ( "\n" );
  printf ( "       X           R8_CEILING(X)\n" );
  printf ( "\n" );

  for ( i = -6; i <= 6; i++ )
  {
    rval = ( double ) ( i ) / 5.0;
    ival = r8_ceiling ( rval );
    printf ( "  %14g  %6d\n", rval, ival );
  }

  return;
}
/******************************************************************************/

void r8_error_f_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_ERROR_F_TEST tests R8_ERROR_F.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 April 2016

  Author:

    John Burkardt
*/
{
  int i;
  int seed;
  double x;
  double y;
  double z;

  printf ( "\n" );
  printf ( "R8_ERROR_F_TEST\n" );
  printf ( "  ERROR_F evaluates ERF(X).\n" );
  printf ( "\n" );
  printf ( "X   -> Y = R8_ERROR_F(X) -> Z = R8_ERROR_F_INVERSE(Y)\n" );
  printf ( "\n" );

  seed = 123456789;

  x = 1.0;

  for ( i = 1; i <= 20; i++ )
  {
    x = normal_01_sample ( &seed );
    y = r8_error_f ( x );
    z = r8_error_f_inverse ( y );
    printf ( "  %12g  %12g  %12g\n", x, y, z );
  }
  return;
}
/******************************************************************************/

void r8_factorial_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_FACTORIAL_TEST tests R8_FACTORIAL.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 April 2016

  Author:

    John Burkardt
*/
{
  double f;
  int i;

  printf ( "\n" );
  printf ( "R8_FACTORIAL_TEST\n" );
  printf ( "  R8_FACTORIAL evaluates the factorial.\n" );
  printf ( "\n" );
  printf ( "    I                R8_FACTORIAL(I)\n" );
  printf ( "\n" );

  for ( i = 0; i <= 20; i++ )
  {
    f = r8_factorial ( i );

    printf ( "  %6d  %12g\n", i, f );
  }

 
  return;
}
/******************************************************************************/

void r8_gamma_inc_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_GAMMA_INC_TEST tests R8_GAMMA_INC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    27 January 2007

  Author:

    John Burkardt
*/
{
  double a;
  double fx;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_GAMMA_INC:\n" );
  printf ( "  R8_GAMMA_INC evaluates the normalized incomplete Gamma\n" );
  printf ( "  function.\n" );
  printf ( "\n" );
  printf ( "   A      X       Exact F       R8_GAMMA_INC(A,X)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gamma_inc_values ( &n_data, &a, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_gamma_inc ( a, x );

    printf ( "  %8g  %8g  %16g  %16g\n", a, x, fx, fx2 );
  }

  return;
}
/******************************************************************************/

void r8_gamma_log_int_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_GAMMA_LOG_INT_TEST tests R8_GAMMA_LOG_INT;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2016

  Author:

    John Burkardt
*/
{
  double g;
  int i;

  printf ( "\n" );
  printf ( "R8_GAMMA_LOG_INT_TEST\n" );
  printf ( "  R8_GAMMA_LOG_INT evaluates the log of the gamma function\n" );
  printf ( "  for integer argument.\n" );

  printf ( "\n" );
  printf ( "       I     R8_GAMMA_LOG_INT(I)\n" );
  printf ( "\n" );

  for ( i = 1; i <= 20; i++ )
  {
    g = r8_gamma_log_int ( i );

    printf ( "  %6d  %12g\n", i, g );
  }

  return;
}
/******************************************************************************/

void r8_uniform_01_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01_TEST tests R8_UNIFORM_01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2006

  Author:

    John Burkardt
*/
{
# define N 1000

  int i;
  double max;
  double mean;
  double min;
  int seed = 123456789;
  double x[N];
  double variance;

  printf ( "\n" );
  printf ( "R8_UNIFORM_01_TEST\n" );
  printf ( "  R8_UNIFORM_01 samples a uniform random distribution in [0,1].\n" );
  printf ( "  distributed random numbers.\n" );
  printf ( "  Using initial random number seed = %d\n", seed );

  for ( i = 0; i < N; i++ )
  {
    x[i] = r8_uniform_01 ( &seed );
  }

  printf ( "\n" );
  printf ( "  First few values:\n" );
  printf ( "\n" );
  for ( i = 0; i < 10; i++ )
  {
    printf ( "  %6d  %14f\n", i, x[i] );
  }
  min = r8vec_min ( N, x );
  max = r8vec_max ( N, x );
  mean = r8vec_mean ( N, x );
  variance = r8vec_variance ( N, x );

  printf ( "\n" );
  printf ( "  Number of samples was %d\n", N );
  printf ( "  Minimum value was %f\n", min );
  printf ( "  Maximum value was %f\n", max );
  printf ( "  Average value was %f\n", mean );
  printf ( "  Variance was      %f\n", variance );

  return;
# undef N
}
/******************************************************************************/

void r8_zeta_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_ZETA_TEST tests R8_ZETA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 March 2016

  Author:

    John Burkardt
*/
{
  int i;
  double p;
  double v;

  printf ( "\n" );
  printf ( "R8_ZETA_TEST\n" );
  printf ( "  R8_ZETA estimates the Zeta function.\n" );

  printf ( "\n" );
  printf ( "       P     R8_Zeta(P)\n" );
  printf ( "\n" );
  for ( i = 1; i <= 25; i++ )
  {
    p = ( double ) ( i );
    v = r8_zeta ( p );
    printf ( "  %6f  %14.6g\n", p, v );
  }

  printf ( "\n" );
  for ( i = 0; i <= 8; i++ )
  {
    p = 3.0 + ( double ) ( i ) / 8.0;
    v = r8_zeta ( p );
    printf ( "  %6f  %14.6g\n", p, v );
  }

  return;
}
/******************************************************************************/

void rayleigh_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    RAYLEIGH_CDF_TEST tests RAYLEIGH_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    28 March 2016

  Author:

    John Burkardt
*/
{
  double a;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "RAYLEIGH_CDF_TEST\n" );
  printf ( "  RAYLEIGH_CDF evaluates the Rayleigh CDF;\n" );
  printf ( "  RAYLEIGH_CDF_INV inverts the Rayleigh CDF.\n" );
  printf ( "  RAYLEIGH_PDF evaluates the Rayleigh PDF;\n" );

  a = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a   );

  if ( ! rayleigh_check ( a ) )
  {
    printf ( "\n" );
    printf ( "RAYLEIGH_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = rayleigh_sample ( a, &seed );
    pdf = rayleigh_pdf ( x, a );
    cdf = rayleigh_cdf ( x, a );
    x2 = rayleigh_cdf_inv ( cdf, a );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void rayleigh_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    RAYLEIGH_SAMPLE_TEST tests RAYLEIGH_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  int j;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "RAYLEIGH_SAMPLE_TEST\n" );
  printf ( "  RAYLEIGH_MEAN computes the Rayleigh mean;\n" );
  printf ( "  RAYLEIGH_SAMPLE samples the Rayleigh distribution;\n" );
  printf ( "  RAYLEIGH_VARIANCE computes the Rayleigh variance.\n" );

  a = 2.0E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a        );

  if ( ! rayleigh_check ( a ) )
  {
    printf ( "\n" );
    printf ( "RAYLEIGH_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = rayleigh_mean ( a );
  variance = rayleigh_variance ( a );

  printf ( "  PDF mean =                    %g\n", mean     );
  printf ( "  PDF variance =                %g\n", variance );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    x[j] = rayleigh_sample ( a, &seed );
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
/******************************************************************************/

void reciprocal_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    RECIPROCAL_CDF_TEST tests RECIPROCAL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "RECIPROCAL_CDF_TEST\n" );
  printf ( "  RECIPROCAL_CDF evaluates the Reciprocal CDF;\n" );
  printf ( "  RECIPROCAL_CDF_INV inverts the Reciprocal CDF.\n" );
  printf ( "  RECIPROCAL_PDF evaluates the Reciprocal PDF;\n" );

  a = 1.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! reciprocal_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "RECIPROCAL_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = reciprocal_sample ( a, b, &seed );
    pdf = reciprocal_pdf ( x, a, b );
    cdf = reciprocal_cdf ( x, a, b );
    x2 = reciprocal_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void reciprocal_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    RECIPROCAL_SAMPLE_TEST tests RECIPROCAL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "RECIPROCAL_SAMPLE_TEST\n" );
  printf ( "  RECIPROCAL_MEAN computes the Reciprocal mean;\n" );
  printf ( "  RECIPROCAL_SAMPLE samples the Reciprocal distribution;\n" );
  printf ( "  RECIPROCAL_VARIANCE computes the Reciprocal variance;\n" );

  a = 1.0;
  b = 3.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! reciprocal_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "RECIPROCAL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = reciprocal_mean ( a, b );
  variance = reciprocal_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = reciprocal_sample ( a, b, &seed );
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
/******************************************************************************/

void runs_pdf_test ( )

/******************************************************************************/
/*
  Purpose:

    RUNS_PDF_TEST tests RUNS_PDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
  int m;
  int n;
  double pdf;
  double pdf_total;
  int r;

  printf ( "\n" );
  printf ( "RUNS_PDF_TEST\n" );
  printf ( "  RUNS_PDF evaluates the Runs PDF;\n" );
  printf ( "\n" );
  printf ( "  M is the number of symbols of one kind,\n" );
  printf ( "  N is the number of symbols of the other kind,\n" );
  printf ( "  R is the number of runs (sequences of one symbol)\n" );
  printf ( "\n" );
  printf ( "         M         N         R      PDF\n" );
  printf ( "\n" );

  m = 6;

  for ( n = 0; n <= 9; n++ )
  {
    printf ( "\n" );
    pdf_total = 0.0;

    for ( r = 1; r <= 2 * i4_min ( m, n ) + 2; r++ )
    {
      pdf = runs_pdf ( m, n, r );

      printf ( "  %8d  %8d  %8d  %14g\n", m, n, r, pdf );

      pdf_total = pdf_total + pdf;
    }

    printf ( "  %8d                      %14g\n", m, pdf_total );

  }

  return;
}
/******************************************************************************/

void runs_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    RUNS_SAMPLE_TEST tests RUNS_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int i;
  int m;
  double mean;
  int n;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "RUNS_SAMPLE_TEST\n" );
  printf ( "  RUNS_MEAN computes the Runs mean;\n" );
  printf ( "  RUNS_SAMPLE samples the Runs distribution;\n" );
  printf ( "  RUNS_VARIANCE computes the Runs variance\n" );

  m = 10;
  n = 5;

  printf ( "\n" );
  printf ( "  PDF parameter M = %d\n", m );
  printf ( "  PDF parameter N = %d\n", n );

  mean = runs_mean ( m, n );
  variance = runs_variance ( m, n );

  printf ( "  PDF mean =        %g\n", mean );
  printf ( "  PDF variance =    %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = runs_sample ( m, n, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax     );
  printf ( "  Sample minimum =  %d\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void sech_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    SECH_CDF_TEST tests SECH_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "SECH_CDF_TEST\n" );
  printf ( "  SECH_CDF evaluates the Sech CDF;\n" );
  printf ( "  SECH_CDF_INV inverts the Sech CDF.\n" );
  printf ( "  SECH_PDF evaluates the Sech PDF;\n" );

  a = 3.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! sech_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "SECH_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = sech_sample ( a, b, &seed );
    pdf = sech_pdf ( x, a, b );
    cdf = sech_cdf ( x, a, b );
    x2 = sech_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void sech_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    SECH_SAMPLE_TEST tests SECH_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "SECH_SAMPLE_TEST\n" );
  printf ( "  SECH_MEAN computes the Sech mean;\n" );
  printf ( "  SECH_SAMPLE samples the Sech distribution;\n" );
  printf ( "  SECH_VARIANCE computes the Sech variance;\n" );

  a = 3.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! sech_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "SECH_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = sech_mean ( a, b );
  variance = sech_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = sech_sample ( a, b, &seed );
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
/******************************************************************************/

void semicircular_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    SEMICIRCULAR_CDF_TEST tests SEMICIRCULAR_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 March 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "SEMICIRCULAR_CDF_TEST\n" );
  printf ( "  SEMICIRCULAR_CDF evaluates the Semicircular CDF;\n" );
  printf ( "  SEMICIRCULAR_CDF_INV inverts the Semicircular CDF.\n" );
  printf ( "  SEMICIRCULAR_PDF evaluates the Semicircular PDF;\n" );

  a = 3.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! semicircular_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "SEMICIRCULAR_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = semicircular_sample ( a, b, &seed );
    pdf = semicircular_pdf ( x, a, b );
    cdf = semicircular_cdf ( x, a, b );
    x2 = semicircular_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void semicircular_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    SEMICIRCULAR_SAMPLE_TEST tests SEMICIRCULAR_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "SEMICIRCULAR_SAMPLE_TEST\n" );
  printf ( "  SEMICIRCULAR_MEAN computes the Semicircular mean;\n" );
  printf ( "  SEMICIRCULAR_SAMPLE samples the Semicircular distribution;\n" );
  printf ( "  SEMICIRCULAR_VARIANCE computes the Semicircular variance;\n" );

  a = 3.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! semicircular_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "SEMICIRCULAR_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = semicircular_mean ( a, b );
  variance = semicircular_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = semicircular_sample ( a, b, &seed );
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
/******************************************************************************/

void student_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    STUDENT_CDF_TEST tests STUDENT_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    30 March 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;

  printf ( "\n" );
  printf ( "STUDENT_CDF_TEST\n" );
  printf ( "  STUDENT_CDF evaluates the Student CDF;\n" );
  printf ( "  STUDENT_PDF evaluates the Student PDF;\n" );
  printf ( "  STUDENT_SAMPLE samples the Student PDF;\n" );

  a = 0.5;
  b = 2.0;
  c = 6.0;

  printf ( "\n" );
  printf ( "  PDF parameter A = %g\n", a   );
  printf ( "  PDF parameter B = %g\n", b   );
  printf ( "  PDF parameter C = %g\n", c   );

  if ( ! student_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "STUDENT_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameter values are illegal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = student_sample ( a, b, c, &seed );
    pdf = student_pdf ( x, a, b, c );
    cdf = student_cdf ( x, a, b, c );

    printf ( "  %12g  %12g  %12g\n", x, pdf, cdf );
  }

  return;
}
/******************************************************************************/

void student_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    STUDENT_SAMPLE_TEST tests STUDENT_SAMPLE

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  double c;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "STUDENT_SAMPLE_TEST\n" );
  printf ( "  STUDENT_MEAN evaluates the Student mean;\n" );
  printf ( "  STUDENT_SAMPLE samples the Student PDF;\n" );
  printf ( "  STUDENT_VARIANCE computes the Student variance;\n" );

  a = 0.5;
  b = 2.0;
  c = 6.0;

  printf ( "\n" );
  printf ( "  PDF parameter A = %g\n", a   );
  printf ( "  PDF parameter B = %g\n", b   );
  printf ( "  PDF parameter C = %g\n", c   );

  if ( ! student_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "STUDENT_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameter values are illegal.\n" );
    return;
  }

  mean = student_mean ( a, b, c );
  variance = student_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = student_sample ( a, b, c, &seed );
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
/******************************************************************************/

void student_noncentral_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    STUDENT_NONCENTRAL_CDF_TEST tests STUDENT_NONCENTRAL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 April 2016

  Author:

    John Burkardt
*/
{
  double b;
  double cdf;
  int idf;
  double x;

  printf ( "\n" );
  printf ( "STUDENT_NONCENTRAL_CDF_TEST\n" );
  printf ( "  STUDENT_NONCENTRAL_CDF evaluates the Student Noncentral CDF;\n" );

  x = 0.50;
  idf = 10;
  b = 1.0;

  cdf = student_noncentral_cdf ( x, idf, b );

  printf ( "\n" );
  printf ( "  PDF argument X =              %g\n", x   );
  printf ( "  PDF parameter IDF =           %d\n", idf );
  printf ( "  PDF parameter B =             %g\n", b   );
  printf ( "  CDF value =                   %g\n", cdf );

  return;
}
/******************************************************************************/

void tfn_test ( )

/******************************************************************************/
/*
  Purpose:

    TFN_TEST tests TFN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double h;
  int n_data;
  double t;
  double t2;

  printf ( "\n" );
  printf ( "TFN_TEST\n" );
  printf ( "  TFN evaluates Owen's T function;\n" );
  printf ( "\n" );
  printf ( "      H             A           T(H,A)          Exact\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    owen_values ( &n_data, &h, &a, &t );

    if ( n_data <= 0 )
    {
      break;
    }

    t2 = tfn ( h, a );

    printf ( "  %12g  %12g  %12g  %12g\n", h, a, t2, t );
  }

  return;
}
/******************************************************************************/

void triangle_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_CDF_TEST tests TRIANGLE_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "TRIANGLE_CDF_TEST\n" );
  printf ( "  TRIANGLE_CDF evaluates the Triangle CDF;\n" );
  printf ( "  TRIANGLE_CDF_INV inverts the Triangle CDF.\n" );
  printf ( "  TRIANGLE_PDF evaluates the Triangle PDF;\n" );

  a = 1.0;
  b = 3.0;
  c = 10.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! triangle_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "TRIANGLE_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = triangle_sample ( a, b, c, &seed );
    pdf = triangle_pdf ( x, a, b, c );
    cdf = triangle_cdf ( x, a, b, c );
    x2 = triangle_cdf_inv ( cdf, a, b, c );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void triangle_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGLE_SAMPLE_TEST tests TRIANGLE_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 March 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  double c;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "TRIANGLE_SAMPLE_TEST\n" );
  printf ( "  TRIANGLE_MEAN computes the Triangle mean;\n" );
  printf ( "  TRIANGLE_SAMPLE samples the Triangle distribution;\n" );
  printf ( "  TRIANGLE_VARIANCE computes the Triangle variance;\n" );

  a = 1.0;
  b = 3.0;
  c = 10.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =        %g\n", a );
  printf ( "  PDF parameter B =        %g\n", b );
  printf ( "  PDF parameter C =        %g\n", c );

  if ( ! triangle_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "TRIANGLE_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = triangle_mean ( a, b, c );
  variance = triangle_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = triangle_sample ( a, b, c, &seed );
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
/******************************************************************************/

void triangular_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGULAR_CDF_TEST tests TRIANGULAR_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 March 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "TRIANGULAR_CDF_TEST\n" );
  printf ( "  TRIANGULAR_CDF evaluates the Triangular CDF;\n" );
  printf ( "  TRIANGULAR_CDF_INV inverts the Triangular CDF.\n" );
  printf ( "  TRIANGULAR_PDF evaluates the Triangular PDF;\n" );

  a = 1.0;
  b = 10.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! triangular_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "TRIANGULAR_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = triangular_sample ( a, b, &seed );
    pdf = triangular_pdf ( x, a, b );
    cdf = triangular_cdf ( x, a, b );
    x2 = triangular_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void triangular_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    TRIANGULAR_SAMPLE_TEST tests TRIANGULAR_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "TRIANGULAR_SAMPLE_TEST\n" );
  printf ( "  TRIANGULAR_MEAN computes the Triangular mean;\n" );
  printf ( "  TRIANGULAR_SAMPLE samples the Triangular distribution;\n" );
  printf ( "  TRIANGULAR_VARIANCE computes the Triangular variance;\n" );

  a = 1.0;
  b = 10.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! triangular_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "TRIANGULAR_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = triangular_mean ( a, b );
  variance = triangular_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = triangular_sample ( a, b, &seed );
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
/******************************************************************************/

void uniform_01_order_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_01_ORDER_SAMPLE_TEST tests UNIFORM_01_ORDER_SAMPLE;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 April 2016

  Author:

    John Burkardt
*/
{
  int n;
  int seed = 123456789;
  double *x;

  printf ( "\n" );
  printf ( "UNIFORM_01_ORDER_SAMPLE_TEST\n" );
  printf ( "  UNIFORM_ORDER_SAMPLE samples theUniform 01 Order distribution.\n" );

  n = 10;
  x = uniform_01_order_sample ( n, &seed );

  r8vec_print ( n, x, "  Ordered sample:" );

  free ( x );

  return;
}
/******************************************************************************/

void uniform_nsphere_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_NSPHERE_SAMPLE_TEST tests UNIFORM_NSPHERE_SAMPLE;

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    10 April 2016

  Author:

    John Burkardt
*/
{
  int i;
  int j;
  int n;
  int seed = 123456789;
  double *x;

  n = 3;

  printf ( "\n" );
  printf ( "UNIFORM_NSPHERE_SAMPLE_TEST\n" );
  printf ( "  UNIFORM_NSPHERE_SAMPLE samples the Uniform Nsphere distribution.\n" );

  printf ( "\n" );
  printf ( "  Dimension N of sphere = %d\n", n );
  printf ( "\n" );
  printf ( "  Points on the sphere:\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = uniform_nsphere_sample ( n, &seed );
    printf ( "  %6d", i );
    for ( j = 0; j < n; j++ )
    {
      printf ( "%12g", x[j] );
    }
    printf ( "\n" );
    free ( x );
  }

  return;
}
/******************************************************************************/

void uniform_01_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_01_CDF_TEST tests UNIFORM_01_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 April 2016

  Author:

    John Burkardt
*/
{
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "UNIFORM_01_CDF_TEST\n" );
  printf ( "  UNIFORM_01_CDF evaluates the Uniform 01 CDF;\n" );
  printf ( "  UNIFORM_01_CDF_INV inverts the Uniform 01 CDF.\n" );
  printf ( "  UNIFORM_01_PDF evaluates the Uniform 01 PDF;\n" );

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = uniform_01_sample ( &seed );
    pdf = uniform_01_pdf ( x );
    cdf = uniform_01_cdf ( x );
    x2 = uniform_01_cdf_inv ( cdf );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void uniform_01_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_01_SAMPLE_TEST tests UNIFORM_01_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "UNIFORM_01_SAMPLE_TEST\n" );
  printf ( "  UNIFORM_01_MEAN computes the Uniform 01 mean;\n" );
  printf ( "  UNIFORM_01_SAMPLE samples the Uniform 01 distribution;\n" );
  printf ( "  UNIFORM_01_VARIANCE computes the Uniform 01 variance.\n" );

  mean     = uniform_01_mean ( );
  variance = uniform_01_variance ( );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = uniform_01_sample ( &seed );
  }

  mean     = r8vec_mean     ( SAMPLE_NUM, x );
  variance = r8vec_variance ( SAMPLE_NUM, x );
  xmax     = r8vec_max      ( SAMPLE_NUM, x );
  xmin     = r8vec_min      ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %g\n", xmax     );
  printf ( "  Sample minimum =  %g\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void uniform_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_CDF_TEST tests UNIFORM_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "UNIFORM_CDF_TEST\n" );
  printf ( "  UNIFORM_CDF evaluates the Uniform CDF;\n" );
  printf ( "  UNIFORM_CDF_INV inverts the Uniform CDF.\n" );
  printf ( "  UNIFORM_PDF evaluates the Uniform PDF;\n" );

  a = 1.0;
  b = 10.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! uniform_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "UNIFORM_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = uniform_sample ( a, b, &seed );
    pdf = uniform_pdf ( x, a, b );
    cdf = uniform_cdf ( x, a, b );
    x2 = uniform_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void uniform_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_SAMPLE_TEST tests UNIFORM_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 September 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "UNIFORM_SAMPLE_TEST\n" );
  printf ( "  UNIFORM_MEAN computes the Uniform mean;\n" );
  printf ( "  UNIFORM_SAMPLE samples the Uniform distribution;\n" );
  printf ( "  UNIFORM_VARIANCE computes the Uniform variance;\n" );

  a = 1.0;
  b = 10.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! uniform_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "UNIFORM_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = uniform_mean ( a, b );
  variance = uniform_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = uniform_sample ( a, b, &seed );
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
/******************************************************************************/

void uniform_discrete_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_DISCRETE_CDF_TEST tests UNIFORM_DISCRETE_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2016

  Author:

    John Burkardt
*/
{
  int a;
  int b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "UNIFORM_DISCRETE_CDF_TEST\n" );
  printf ( "  UNIFORM_DISCRETE_CDF evaluates the Uniform Discrete CDF;\n" );
  printf ( "  UNIFORM_DISCRETE_CDF_INV inverts the Uniform Discrete CDF.\n" );
  printf ( "  UNIFORM_DISCRETE_PDF evaluates the Uniform Discrete PDF;\n" );

  a = 1;
  b = 6;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %d\n", a );
  printf ( "  PDF parameter B =      %d\n", b );

  if ( ! uniform_discrete_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "UNIFORM_DISCRETE_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = uniform_discrete_sample ( a, b, &seed );
    pdf = uniform_discrete_pdf ( x, a, b );
    cdf = uniform_discrete_cdf ( x, a, b );
    x2 = uniform_discrete_cdf_inv ( cdf, a, b );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void uniform_discrete_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    UNIFORM_DISCRETE_SAMPLE_TEST tests UNIFORM_DISCRETE_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  int a;
  int b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "UNIFORM_DISCRETE_SAMPLE_TEST\n" );
  printf ( "  UNIFORM_DISCRETE_MEAN computes the Uniform Discrete mean;\n" );
  printf ( "  UNIFORM_DISCRETE_SAMPLE samples the Uniform Discrete distribution;\n" );
  printf ( "  UNIFORM_DISCRETE_VARIANCE computes the Uniform Discrete variance;\n" );

  a = 1;
  b = 6;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %d\n", a );
  printf ( "  PDF parameter B =      %d\n", b );

  if ( ! uniform_discrete_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "UNIFORM_DISCRETE_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = uniform_discrete_mean ( a, b );
  variance = uniform_discrete_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = uniform_discrete_sample ( a, b, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax     );
  printf ( "  Sample minimum =  %d\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void von_mises_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    VON_MISES_CDF_TEST tests VON_MISES_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2013

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "VON_MISES_CDF_TEST\n" );
  printf ( "  VON_MISES_CDF evaluates the Von Mises CDF;\n" );
  printf ( "  VON_MISES_CDF_INV inverts the Von Mises CDF.\n" );
  printf ( "  VON_MISES_PDF evaluates the Von Mises PDF;\n" );

  a = 1.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! von_mises_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "VON_MISES_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = von_mises_sample ( a, b, &seed );
    pdf = von_mises_pdf ( x, a, b );
    cdf = von_mises_cdf ( x, a, b );
    x2 = von_mises_cdf_inv ( cdf, a, b );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void von_mises_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    VON_MISES_SAMPLE_TEST tests VON_MISES_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 April 2013

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "VON_MISES_SAMPLE_TEST\n" );
  printf ( "  VON_MISES_MEAN computes the Von Mises mean;\n" );
  printf ( "  VON_MISES_SAMPLE samples the Von Mises distribution;\n" );
  printf ( "  VON_MISES_CIRCULAR_VARIANCE computes the Von Mises circular variance;\n" );

  a = 1.0;
  b = 2.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! von_mises_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "VON_MISES_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = von_mises_mean ( a, b );
  variance = von_mises_circular_variance ( a, b );

  printf ( "\n" );
  printf ( "  PDF mean =              %g\n", mean     );
  printf ( "  PDF circular variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = von_mises_sample ( a, b, &seed );
  }

  mean = r8vec_mean ( SAMPLE_NUM, x );
  variance = r8vec_circular_variance ( SAMPLE_NUM, x );
  xmax = r8vec_max ( SAMPLE_NUM, x );
  xmin = r8vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =              %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =              %g\n", mean     );
  printf ( "  Sample circular variance = %g\n", variance );
  printf ( "  Sample maximum =           %g\n", xmax     );
  printf ( "  Sample minimum =           %g\n", xmin     );

  return;
# undef SAMPLE_NUM
}
/******************************************************************************/

void weibull_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    WEIBULL_CDF_TEST tests WEIBULL_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double c;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  double x;
  double x2;

  printf ( "\n" );
  printf ( "WEIBULL_CDF_TEST\n" );
  printf ( "  WEIBULL_CDF evaluates the Weibull CDF;\n" );
  printf ( "  WEIBULL_CDF_INV inverts the Weibull CDF.\n" );
  printf ( "  WEIBULL_PDF evaluates the Weibull PDF;\n" );

  a = 2.0;
  b = 3.0;
  c = 4.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! weibull_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "WEIBULL_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = weibull_sample ( a, b, c, &seed );
    pdf = weibull_pdf ( x, a, b, c );
    cdf = weibull_cdf ( x, a, b, c );
    x2 = weibull_cdf_inv ( cdf, a, b, c );

    printf ( "  %12g  %12g  %12g  %12g\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void weibull_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    WEIBULL_SAMPLE_TEST tests WEIBULL_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  double c;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "WEIBULL_SAMPLE_TEST\n" );
  printf ( "  WEIBULL_MEAN computes the Weibull mean;\n" );
  printf ( "  WEIBULL_SAMPLE samples the Weibull distribution;\n" );
  printf ( "  WEIBULL_VARIANCE computes the Weibull variance.\n" );

  a = 2.0;
  b = 3.0;
  c = 4.0;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );
  printf ( "  PDF parameter C =      %g\n", c );

  if ( ! weibull_check ( a, b, c ) )
  {
    printf ( "\n" );
    printf ( "WEIBULL_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = weibull_mean ( a, b, c );
  variance = weibull_variance ( a, b, c );

  printf ( "\n" );
  printf ( "  PDF mean =     %g\n", mean     );
  printf ( "  PDF variance = %g\n", variance );

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = weibull_sample ( a, b, c, &seed );
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
/******************************************************************************/

void weibull_discrete_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    WEIBULL_DISCRETE_CDF_TEST tests WEIBULL_DISCRETE_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double cdf;
  int i;
  double pdf;
  int seed = 123456789;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "WEIBULL_DISCRETE_CDF_TEST\n" );
  printf ( "  WEIBULL_DISCRETE_CDF evaluates the Weibull Discrete CDF;\n" );
  printf ( "  WEIBULL_DISCRETE_CDF_INV inverts the Weibull Discrete CDF.\n" );
  printf ( "  WEIBULL_DISCRETE_PDF evaluates the Weibull Discrete PDF;\n" );

  a = 0.5;
  b = 1.5;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! weibull_discrete_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "WEIBULL_DISCRETE_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF            CDF_INV\n" );
  printf ( "\n" );

  for ( i = 1; i <= 10; i++ )
  {
    x = weibull_discrete_sample ( a, b, &seed );
    pdf = weibull_discrete_pdf ( x, a, b );
    cdf = weibull_discrete_cdf ( x, a, b );
    x2 = weibull_discrete_cdf_inv ( cdf, a, b );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void weibull_discrete_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    WEIBULL_DISCRETE_SAMPLE_TEST tests WEIBULL_DISCRETE_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 April 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  double b;
  int i;
  double mean;
  int seed = 123456789;
  double variance;
  double x[SAMPLE_NUM];
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "WEIBULL_DISCRETE_SAMPLE_TEST\n" );
  printf ( "  WEIBULL_DISCRETE_SAMPLE samples the Weibull Discrete distribution;\n" );

  a = 0.5;
  b = 1.5;

  printf ( "\n" );
  printf ( "  PDF parameter A =      %g\n", a );
  printf ( "  PDF parameter B =      %g\n", b );

  if ( ! weibull_discrete_check ( a, b ) )
  {
    printf ( "\n" );
    printf ( "WEIBULL_DISCRETE_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  for ( i = 0; i < SAMPLE_NUM; i++ )
  {
    x[i] = weibull_discrete_sample ( a, b, &seed );
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
/******************************************************************************/

void zipf_cdf_test ( )

/******************************************************************************/
/*
  Purpose:

    ZIPF_CDF_TEST tests ZIPF_CDF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 March 2016

  Author:

    John Burkardt
*/
{
  double a;
  double cdf;
  double pdf;
  int x;
  int x2;

  printf ( "\n" );
  printf ( "ZIPF_CDF_TEST\n" );
  printf ( "  ZIPF_CDF evaluates the Zipf CDF;\n" );
  printf ( "  ZIPF_CDF_INV inverts the Zipf CDF;\n" );
  printf ( "  ZIPF_PDF evaluates the Zipf PDF;\n" );

  a = 2.0E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a   );

  if ( ! zipf_check ( a ) )
  {
    printf ( "\n" );
    printf ( "ZIPF_CDF_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  printf ( "\n" );
  printf ( "       X            PDF           CDF         CDF_INV\n" );
  printf ( "\n" );

  for ( x = 1; x <= 20; x++ )
  {
    pdf = zipf_pdf ( x, a );
    cdf = zipf_cdf ( x, a );
    x2 = zipf_cdf_inv ( a, cdf );

    printf ( "  %12d  %12g  %12g  %12d\n", x, pdf, cdf, x2 );
  }

  return;
}
/******************************************************************************/

void zipf_sample_test ( )

/******************************************************************************/
/*
  Purpose:

    ZIPF_SAMPLE_TEST tests ZIPF_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 March 2016

  Author:

    John Burkardt
*/
{
# define SAMPLE_NUM 1000

  double a;
  int j;
  double mean;
  int seed = 123456789;
  double variance;
  int x[SAMPLE_NUM];
  int xmax;
  int xmin;

  printf ( "\n" );
  printf ( "ZIPF_SAMPLE_TEST\n" );
  printf ( "  ZIPF_MEAN computes the Zipf mean;\n" );
  printf ( "  ZIPF_SAMPLE samples the Zipf distribution;\n" );
  printf ( "  ZIPF_VARIANCE computes the Zipf variance.\n" );

  a = 4.0E+00;

  printf ( "\n" );
  printf ( "  PDF parameter A =             %g\n", a        );

  if ( ! zipf_check ( a ) )
  {
    printf ( "\n" );
    printf ( "ZIPF_SAMPLE_TEST - Fatal error!\n" );
    printf ( "  The parameters are not legal.\n" );
    return;
  }

  mean = zipf_mean ( a );
  variance = zipf_variance ( a );

  printf ( "  PDF mean =                    %g\n", mean     );
  printf ( "  PDF variance =                %g\n", variance );

  for ( j = 0; j < SAMPLE_NUM; j++ )
  {
    x[j] = zipf_sample ( a, &seed );
  }

  mean = i4vec_mean ( SAMPLE_NUM, x );
  variance = i4vec_variance ( SAMPLE_NUM, x );
  xmax = i4vec_max ( SAMPLE_NUM, x );
  xmin = i4vec_min ( SAMPLE_NUM, x );

  printf ( "\n" );
  printf ( "  Sample size =     %d\n", SAMPLE_NUM  );
  printf ( "  Sample mean =     %g\n", mean     );
  printf ( "  Sample variance = %g\n", variance );
  printf ( "  Sample maximum =  %d\n", xmax     );
  printf ( "  Sample minimum =  %d\n", xmin     );

  return;
# undef SAMPLE_NUM
}
