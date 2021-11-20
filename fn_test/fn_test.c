# include <complex.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "fn.h"
# include "test_values.h"

int main ( );
void i4_mach_test ( );
void r8_acos_test ( );
void r8_acosh_test ( );
void r8_ai_test ( );
void r8_aid_test ( );
void r8_aint_test ( );
void r8_asin_test ( );
void r8_asinh_test ( );
void r8_atan_test ( );
void r8_atan2_test ( );
void r8_atanh_test ( );
void r8_besi0_test ( );
void r8_besi1_test ( );
void r8_besj0_test ( );
void r8_besj1_test ( );
void r8_besk_test ( );
void r8_besk0_test ( );
void r8_besk1_test ( );
void r8_besy0_test ( );
void r8_besy1_test ( );
void r8_beta_test ( );
void r8_betai_test ( );
void r8_bi_test ( );
void r8_bid_test ( );
void r8_binom_test ( );
void r8_cbrt_test ( );
void r8_chi_test ( );
void r8_chu_test ( );
void r8_ci_test ( );
void r8_cin_test ( );
void r8_cinh_test ( );
void r8_cos_test ( );
void r8_cos_deg_test ( );
void r8_cosh_test ( );
void r8_cot_test ( );
void r8_csevl_test ( );
void r8_dawson_test ( );
void r8_e1_test ( );
void r8_ei_test ( );
void r8_erf_test ( );
void r8_erfc_test ( );
void r8_exp_test ( );
void r8_fac_test ( );
void r8_gamic_test ( );
void r8_gamit_test ( );
void r8_gaml_test ( );
void r8_gamma_test ( );
void r8_gamr_test ( );
void r8_inits_test ( );
void r8_int_test ( );
void r8_lbeta_test ( );
void r8_lgams_test ( );
void r8_lgmc_test ( );
void r8_li_test ( );
void r8_lngam_test ( );
void r8_lnrel_test ( );
void r8_log_test ( );
void r8_log10_test ( );
void r8_mach_test ( );
void r8_pak_test ( );
void r8_poch_test ( );
void r8_psi_test ( );
void r8_rand_test ( );
void r8_randgs_test ( );
void r8_random_test ( );
void r8_ren_test ( );
void shi_test ( );
void si_test ( );
void sin_test ( );
void sin_deg_test ( );
void sinh_test ( );
void spence_test ( );
void sqrt_test ( );
void tan_test ( );
void tanh_test ( );
void r8_upak_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for FN_TEST.

  Discussion:

    FN_TEST tests the FN library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 May 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "FN_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  FN evaluates special functions.\n" );

  i4_mach_test ( );
  r8_acos_test ( );
  r8_acosh_test ( );
  r8_ai_test ( );
  r8_aid_test ( );
  r8_aint_test ( );
  r8_asin_test ( );
  r8_asinh_test ( );
  r8_atan_test ( );
  r8_atan2_test ( );
  r8_atanh_test ( );
  r8_besi0_test ( );
  r8_besi1_test ( );
  r8_besj0_test ( );
  r8_besj1_test ( );
  r8_besk_test ( );
  r8_besk0_test ( );
  r8_besk1_test ( );
  r8_besy0_test ( );
  r8_besy1_test ( );
  r8_beta_test ( );
  r8_betai_test ( );
  r8_bi_test ( );
  r8_bid_test ( );
  r8_binom_test ( );
  r8_cbrt_test ( );
  r8_chi_test ( );
  r8_chu_test ( );
  r8_ci_test ( );
  r8_cin_test ( );
  r8_cinh_test ( );
  r8_cos_test ( );
  r8_cos_deg_test ( );
  r8_cosh_test ( );
  r8_cot_test ( );
  r8_csevl_test ( );
  r8_dawson_test ( );
  r8_e1_test ( );
  r8_ei_test ( );
  r8_erf_test ( );
  r8_erfc_test ( );
  r8_exp_test ( );
  r8_fac_test ( );
  r8_gamic_test ( );
  r8_gamit_test ( );
  r8_gaml_test ( );
  r8_gamma_test ( );
  r8_gamr_test ( );
  r8_inits_test ( );
  r8_int_test ( );
  r8_lbeta_test ( );
  r8_lgams_test ( );
  r8_lgmc_test ( );
  r8_li_test ( );
  r8_lngam_test ( );
  r8_lnrel_test ( );
  r8_log_test ( );
  r8_log10_test ( );
  r8_mach_test ( );
  r8_pak_test ( );
  r8_poch_test ( );
  r8_psi_test ( );
  r8_rand_test ( );
  r8_randgs_test ( );
  r8_random_test ( );
  r8_ren_test ( );
  shi_test ( );
  si_test ( );
  sin_test ( );
  sin_deg_test ( );
  sinh_test ( );
  spence_test ( );
  sqrt_test ( );
  tan_test ( );
  tanh_test ( );
  r8_upak_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "FN_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void i4_mach_test ( )

/******************************************************************************/
/*
  Purpose:

    I4_MACH_TEST tests I4_MACH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 April 2016

  Author:

    John Burkardt
*/
{
  int i;

  printf ( "\n" );
  printf ( "I4_MACH_TEST:\n" );
  printf ( "  I4_MACH evaluates integer machine numbers.\n" );
  printf ( "\n" );
  printf ( "  I4_MACH(1) = the standard input unit.\n" );
  printf ( "  I4_MACH(2) = the standard output unit.\n" );
  printf ( "  I4_MACH(3) = the standard punch unit.\n" );
  printf ( "  I4_MACH(4) = the standard error message unit.\n" );
  printf ( "  I4_MACH(5) = the number of bits per integer storage unit.\n" );
  printf ( "  I4_MACH(6) = the number of characters per integer storage unit.\n" );
  printf ( "  I4_MACH(7) = A, the base.\n" );
  printf ( "  I4_MACH(8) = S, the number of base A digits.\n" );
  printf ( "  I4_MACH(9) = A^S-1, the largest integer.\n" );
  printf ( "  I4_MACH(10) = B, the base.\n" );
  printf ( "  I4_MACH(11) = T, the number of single precision base B digits.\n" );
  printf ( "  I4_MACH(12) = EMIN, the smallest single precision exponent E.\n" );
  printf ( "  I4_MACH(13) = EMAX, the largest single precision exponent E.\n" );
  printf ( "  I4_MACH(14) = T, the number of double precision base B digits.\n" );
  printf ( "  I4_MACH(15) = EMIN, the smallest double precision exponent E.\n" );
  printf ( "  I4_MACH(16) = EMAX, the largest double precision exponent E.\n" );
  printf ( "\n" );
  printf ( "    I     I4_MACH(I)\n" );
  printf ( "\n" );

  for ( i = 1; i <= 16; i++ )
  {
    printf ( "  %4d  %12d\n", i, i4_mach ( i ) );
  }

  return;
}
/******************************************************************************/

void r8_acos_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_ACOS_TEST tests R8_ACOS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_ACOS_TEST:\n" );
  printf ( "  R8_ACOS computes the arc cosine function.\n" );
  printf ( "\n" );
  printf ( "             X      ARCCOS(X)  R8_ACOS(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    arccos_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_acos ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_acosh_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_ACOSH_TEST tests R8_ACOSH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_ACOSH_TEST:\n" );
  printf ( "  R8_ACOSH evaluates the arc hyperbolic cosine\n" );
  printf ( "\n" );
  printf ( "             X      ARCCOSH(X)  R8_ACOSH(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    arccosh_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_acosh ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_ai_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_AI_TEST tests R8_AI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_AI_TEST:\n" );
  printf ( "  R8_AI evaluates the Airy function Ai(x)\n" );
  printf ( "\n" );
  printf ( "             X   AIRY_AI(X)  R8_AI(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    airy_ai_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_ai ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_aid_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_AID_TEST tests R8_AID.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_AID_TEST:\n" );
  printf ( "  R8_AID evaluates the derivative of the Airy Ai(x) function.\n" );
  printf ( "\n" );
  printf ( "             X   AIRY_AID(X)  R8_AID(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    airy_ai_prime_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_aid ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_aint_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_AINT_TEST tests R8_AINT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_AINT_TEST:\n" );
  printf ( "  R8_AINT rounds an R8 towards 0.\n" );
  printf ( "\n" );
  printf ( "             X     AINT(X)  R8_AINT(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    int_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_aint ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_asin_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_ASIN_TEST tests R8_ASIN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_ASIN_TEST:\n" );
  printf ( "  R8_ASIN evaluates the arcsine.\n" );
  printf ( "\n" );
  printf ( "             X      ARCSIN(X)  R8_ASIN(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    arcsin_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_asin ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_asinh_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_ASINH_TEST tests R8_ASINH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_ASINH_TEST:\n" );
  printf ( "  R8_ASINH evaluates the hyperbolic arcsine\n" );
  printf ( "\n" );
  printf ( "             X      ARCSINH(X)  R8_ASINH(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    arcsinh_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_asinh ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_atan_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_ATAN_TEST tests R8_ATAN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_ATAN_TEST:\n" );
  printf ( "  R8_ATAN evaluates the arctangent.\n" );
  printf ( "\n" );
  printf ( "             X      ARCTAN(X)  R8_ATAN(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    arctan_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_atan ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_atan2_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_ATAN2_TEST tests R8_ATAN2.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;
  double y;

  printf ( "\n" );
  printf ( "R8_ATAN2_TEST:\n" );
  printf ( "  R8_ATAN2 evaluates the arctangent.\n" );
  printf ( "\n" );
  printf ( "             X             Y      ARCTAN2(Y,X)  R8_ATAN2(Y,X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    arctan2_values ( &n_data, &x, &y, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_atan2 ( y, x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_atanh_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_ATANH_TEST tests R8_ATANH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_ATANH_TEST:\n" );
  printf ( "  R8_ATANH evaluates the hyperbolic arctangent\n" );
  printf ( "\n" );
  printf ( "             X      ARCTANH(X)  R8_ATANH(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    arctanh_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_atanh ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_besi0_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BESI0_TEST tests R8_BESI0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_BESI0_TEST:\n" );
  printf ( "  R8_BESI0 evalutes the Bessel I0(x) function.\n" );
  printf ( "\n" );
  printf ( "             X      BESI0(X)  R8_BESI0(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_i0_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_besi0 ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_besi1_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BESI1_TEST tests R8_BESI1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_BESI1_TEST:\n" );
  printf ( "  R8_BESI1 evaluates the Bessel I1(x) function\n" );
  printf ( "\n" );
  printf ( "             X      BESI1(X)  R8_BESI1(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_i1_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_besi1 ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_besj0_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BESJ0_TEST tests R8_BESJ0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_BESJ0_TEST:\n" );
  printf ( "  R8_BESJ0 evaluates the Bessel J0(x) function.\n" );
  printf ( "\n" );
  printf ( "             X      BESJ0(X)  R8_BESJ0(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_j0_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_besj0 ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_besj1_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BESJ1_TEST tests R8_BESJ1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_BESJ1_TEST:\n" );
  printf ( "  R8_BESJ1 evaluates the Bessel J1(x) function.\n" );
  printf ( "\n" );
  printf ( "             X      BESJ1(X)  R8_BESJ1(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_j1_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_besj1 ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_besk_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BESK_TEST tests R8_BESK.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 November 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double nu;
  double x;

  printf ( "\n" );
  printf ( "R8_BESK_TEST:\n" );
  printf ( "  R8_BESK evaluates the Bessel K(NU,X) function.\n" );
  printf ( "\n" );
  printf ( "              NU               X      BESK(X)  R8_BESK(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_kx_values ( &n_data, &nu, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_besk ( nu, x );

    printf ( "  %14g  %14g  %14g  %14g  %14g\n", nu, x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_besk0_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BESK0_TEST tests R8_BESK0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_BESK0_TEST:\n" );
  printf ( "  R8_BESK0 evaluates the Bessel K0(x) function.\n" );
  printf ( "\n" );
  printf ( "             X      BESK0(X)  R8_BESK0(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_k0_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_besk0 ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_besk1_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BESK1_TEST tests R8_BESK1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_BESK1_TEST:\n" );
  printf ( "  R8_BESK1 evaluates the Bessel K1(x) function.\n" );
  printf ( "\n" );
  printf ( "             X      BESK1(X)  R8_BESK1(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_k1_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_besk1 ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_besy0_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BESY0_TEST tests R8_BESY0.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_BESY0_TEST:\n" );
  printf ( "  R8_BESY0 evaluates the Bessel Y0(x) function.\n" );
  printf ( "\n" );
  printf ( "             X      BESY0(X)  R8_BESY0(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_y0_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_besy0 ( x );

   printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_besy1_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BESY1_TEST tests R8_BESY1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_BESY1_TEST:\n" );
  printf ( "  R8_BESY1 evaluates the Bessel Y1(x) function.\n" );
  printf ( "\n" );
  printf ( "             X      BESY1(X)  R8_BESY1(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    bessel_y1_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_besy1 ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_beta_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BETA_TEST tests R8_BETA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double fx1;
  double fx2;
  int n_data;

  printf ( "\n" );
  printf ( "R8_BETA_TEST:\n" );
  printf ( "  R8_BETA evaluates the Beta function.\n" );
  printf ( "\n" );
  printf ( "             A        B        BETA(A,B)  R8_BETA(A,B)       Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    beta_values ( &n_data, &a, &b, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_beta ( a, b );

    printf ( "  %14g  %14g  %14g  %14g  %14g\n", a, b, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_betai_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BETAI_TEST tests R8_BETAI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_BETAI_TEST:\n" );
  printf ( "  R8_BETAI evaluates the incomplete Beta function.\n" );
  printf ( "\n" );
  printf ( "             X        BETA(A,B,X)  R8_BETAI(A,B,X)       Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    beta_inc_values ( &n_data, &a, &b, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_betai ( x, a, b );

    printf ( "  %14g  %14g  %14g  %14g  %14g  %14g\n", a, b, x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_bi_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BI_TEST tests R8_BI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_BI_TEST:\n" );
  printf ( "  R8_BI evaluates the Airy Bi(x) function.\n" );
  printf ( "\n" );
  printf ( "             X   AIRY_BI(X)  R8_BI(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    airy_bi_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_bi ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_bid_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BID_TEST tests R8_BID.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_BID_TEST:\n" );
  printf ( "  R8_BID evaluates the derivative of the Airy Bi(x) function.\n" );
  printf ( "\n" );
  printf ( "             X   AIRY_BID(X)  R8_BID(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    airy_bi_prime_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_bid ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_binom_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_BINOM_TEST tests R8_BINOM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  int a;
  int b;
  int fx1;
  double fx2;
  int n_data;

  printf ( "\n" );
  printf ( "R8_BINOM_TEST:\n" );
  printf ( "  R8_BINOM evaluates the binomial coefficient.\n" );
  printf ( "\n" );
  printf ( "             A    B        BINOM(A,B)  R8_BINOM(A,B)       Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    binomial_values ( &n_data, &a, &b, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_binom ( ( double ) a, ( double ) b );

    printf ( "  %14d  %14d  %14d  %14g  %14g\n", a, b, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_cbrt_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_CBRT_TEST tests R8_CBRT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_CBRT_TEST:\n" );
  printf ( "  R8_CBRT evaluates the cube root function\n" );
  printf ( "\n" );
  printf ( "             X      CBRT(X)  R8_CBRT(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    cbrt_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_cbrt ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_chi_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_CHI_TEST tests R8_CHI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_CHI_TEST:\n" );
  printf ( "  R8_CHI evaluates the hypergeometric integral.\n" );
  printf ( "\n" );
  printf ( "             X      CHI(X)  R8_CHI(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    chi_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_chi ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_chu_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_CHU_TEST tests R8_CHU.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_CHU_TEST:\n" );
  printf ( "  R8_CHU evaluates the hypergeometric U function.\n" );
  printf ( "\n" );
  printf ( "             A               B               X     CHU(A,B,X)  R8_CHU(A,B,X)  Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    hypergeometric_u_values ( &n_data, &a, &b, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_chu ( a, b, x );

    printf ( "  %14g  %14g  %14g  %14g  %14g  %14g\n", a, b, x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }

  return;
}
/******************************************************************************/

void r8_ci_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_CI_TEST tests R8_CI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_CI_TEST:\n" );
  printf ( "  R8_CI evaluates the cosine integral.\n" );
  printf ( "\n" );
  printf ( "             X      CI(X)  R8_CI(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    ci_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_ci ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_cin_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_CIN_TEST tests R8_CIN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_CIN_TEST:\n" );
  printf ( "  R8_CIN evaluates the alternate cosine integral.\n" );
  printf ( "\n" );
  printf ( "             X      CIN(X)  R8_CIN(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    cin_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_cin ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_cinh_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_CINH_TEST tests R8_CINH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_CINH_TEST:\n" );
  printf ( "  R8_CINH evaluates the alternate hyperbolic cosine integral.\n" );
  printf ( "\n" );
  printf ( "             X      CINH(X)  R8_CINH(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    cinh_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_cinh ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_cos_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_COS_TEST tests R8_COS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_COS_TEST:\n" );
  printf ( "  R8_COS evaluates the cosine.\n" );
  printf ( "\n" );
  printf ( "             X      COS(X)  R8_COS(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    cos_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_cos ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_cos_deg_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_COS_DEG_TEST tests R8_COS_DEG.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_COS_DEG_TEST:\n" );
  printf ( "  R8_COS_DEG evaluates the cosine of an argument in degrees.\n" );
  printf ( "\n" );
  printf ( "             X      COS_DEG(X)  R8_COS_DEG(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    cos_degree_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_cos_deg ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_cosh_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_COSH_TEST tests R8_COSH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_COSH_TEST:\n" );
  printf ( "  R8_COSH evaluates the hyperbolic cosine\n" );
  printf ( "\n" );
  printf ( "             X      COSH(X)  R8_COSH(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    cosh_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_cosh ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_cot_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_COT_TEST tests R8_COT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_COT_TEST:\n" );
  printf ( "  R8_COT evaluates the cotangent.\n" );
  printf ( "\n" );
  printf ( "             X      COT(X)  R8_COT(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    cot_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_cot ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_csevl_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_CSEVL_TEST tests R8_CSEVL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 April 2016

  Author:

    John Burkardt
*/
{
  double err;
  int i;
  int n;
  double expcs[15] = {
   2.532131755504016, 
   1.130318207984970, 
   0.271495339534077, 
   0.044336849848664, 
   0.005474240442094, 
   0.000542926311914, 
   0.000044977322954, 
   0.000003198436462, 
   0.000000199212481, 
   0.000000011036772, 
   0.000000000550590,
   0.000000000024980, 
   0.000000000001039, 
   0.000000000000040, 
   0.000000000000001 };
  double s;
  double x;

  printf ( "\n" );
  printf ( "R8_CSEVL_TEST:\n" );
  printf ( "  R8_CSEVL evaluates a Chebyshev approximant\n" );
  printf ( "  of N terms at a point X.\n" );
  printf ( "\n" );
  printf ( "  Here we use an approximant to the exponential function.\n" );
  printf ( "  and average the absolute error at 21 points.\n" );
  printf ( "\n" );
  printf ( "   N    error\n" );
  printf ( "\n" );

  for ( n = 1; n <= 12; n++ )
  {
    err = 0.0;
    for ( i = -10; i <= 10; i++ )
    {
      x = ( double ) ( i ) / 10.0;
      s = r8_csevl ( x, expcs, n );
      err = err + fabs ( s - exp ( x ) );
    }
    err = err / 21.0;
    printf ( "  %2d  %14.6g\n", n, err );
  }

  return;
}
/******************************************************************************/

void r8_dawson_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_DAWSON_TEST tests R8_DAWSON.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_DAWSON_TEST:\n" );
  printf ( "  R8_DAWSON evaluates Dawson's integral.\n" );
  printf ( "\n" );
  printf ( "             X      DAWSON(X)  R8_DAWSON(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    dawson_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_dawson ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_e1_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_E1_TEST tests R8_E1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_E1_TEST:\n" );
  printf ( "  R8_E1 evaluates the exponential integral E1(x).\n" );
  printf ( "\n" );
  printf ( "             X      E1(X)  R8_E1(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    e1_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_e1 ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_ei_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_EI_TEST tests R8_EI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_EI_TEST:\n" );
  printf ( "  R8_EI evaluates the Ei(X) exponential integral.\n" );
  printf ( "\n" );
  printf ( "             X      EI(X)  R8_EI(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    ei_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_ei ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_erf_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_ERF_TEST tests R8_ERF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_ERF_TEST:\n" );
  printf ( "  R8_ERF evaluates the error function.\n" );
  printf ( "\n" );
  printf ( "             X      ERF(X)  R8_ERF(X)         Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    erf_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_erf ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_erfc_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_ERFC_TEST tests R8_ERFC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_ERFC_TEST:\n" );
  printf ( "  R8_ERFC evaluates the complementary error function.\n" );
  printf ( "\n" );
  printf ( "             X      ERFC(X)  R8_ERFC(X)         Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    erfc_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_erfc ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_exp_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_EXP_TEST tests R8_EXP.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_EXP_TEST:\n" );
  printf ( "  R8_EXP evaluates the exponential function.\n" );
  printf ( "\n" );
  printf ( "             X      EXP(X)\n" );
  printf ( "                   R4_EXP(X)         Diff\n" );
  printf ( "                   R8_EXP(X)         Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    exp_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_exp ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_fac_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_FAC_TEST tests R8_FAC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n;
  int n_data;

  printf ( "\n" );
  printf ( "R8_FAC_TEST:\n" );
  printf ( "  R8_FAC evaluates the factorial function.\n" );
  printf ( "\n" );
  printf ( "             N      FAC(N)  R8_FAC(N)         Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    r8_factorial_values ( &n_data, &n, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_fac ( n );

    printf ( "\n" );
    printf ( "  %14d  %14g  %14g  %14g\n", n, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_gamic_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_GAMIC_TEST tests R8_GAMIC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_GAMIC_TEST:\n" );
  printf ( "  R8_GAMIC evaluates the incomplete gamma function.\n" );
  printf ( "\n" );
  printf ( "             X        GAMIC(A,X)  R8_GAMIC(A,X)       Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gamma_inc_values ( &n_data, &a, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_gamic ( a, x );

    printf ( "  %14g  %14g  %14g  %14g  %14g\n", a, x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_gamit_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_GAMIT_TEST tests R8_GAMIT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double a;
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_GAMIT_TEST:\n" );
  printf ( "  R8_GAMIT evaluates Tricomi's incomplete Gamma function.\n" );
  printf ( "\n" );
  printf ( "        A     X        GAMIT(A,X)  R8_GAMIT(A,X)       Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gamma_inc_tricomi_values ( &n_data, &a, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_gamit ( a, x );

    printf ( "  %14g  %14g  %14g  %14g  %14g\n", a, x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_gaml_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_GAML_TEST tests R8_GAML.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double xmax;
  double xmin;

  printf ( "\n" );
  printf ( "R8_GAML_TEST:\n" );
  printf ( "  R8_GAML returns bounds for the argument of the gamma function.\n" );

  r8_gaml ( &xmin, &xmax );

  printf ( "\n" );
  printf ( "  Lower limit XMIN = %g\n", xmin );
  printf ( "  Upper limit XMAX = %g\n", xmax );

  return;
}
/******************************************************************************/

void r8_gamma_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_GAMMA_TEST tests R8_GAMMA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_GAMMA_TEST:\n" );
  printf ( "  R8_GAMMA evaluates the gamma function.\n" );
  printf ( "\n" );
  printf ( "             X      GAMMA(X)  R8_GAMMA(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gamma_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_gamma ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_gamr_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_GAMR_TEST tests R8_GAMR.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  double gx;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_GAMR_TEST:\n" );
  printf ( "  R8_GAMR evaluates 1.0/Gamma(x).\n" );
  printf ( "\n" );
  printf ( "             X    1/GAMMA(X)  R8_GAMR(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gamma_values ( &n_data, &x, &gx );

    if ( n_data == 0 )
    {
      break;
    }

    fx1 = 1.0 / gx;
    fx2 = r8_gamr ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_inits_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_INITS_TEST tests R8_INITS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 April 2016

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double sincs[15] = {
    -0.374991154955873175839919279977323464, 
    -0.181603155237250201863830316158004754, 
    +0.005804709274598633559427341722857921, 
    -0.000086954311779340757113212316353178, 
    +0.000000754370148088851481006839927030, 
    -0.000000004267129665055961107126829906, 
    +0.000000000016980422945488168181824792, 
    -0.000000000000050120578889961870929524, 
    +0.000000000000000114101026680010675628, 
    -0.000000000000000000206437504424783134, 
    +0.000000000000000000000303969595918706, 
    -0.000000000000000000000000371357734157, 
    +0.000000000000000000000000000382486123, 
    -0.000000000000000000000000000000336623, 
    +0.000000000000000000000000000000000256 };
  double tol;

  printf ( "\n" );
  printf ( "R8_INITS_TEST:\n" );
  printf ( "  R8_INITS determines the Chebyshev interpolant degree\n" );
  printf ( "  necessary to guarantee a desired accuracy level.\n" );
  printf ( "\n" );
  printf ( "  Here, we use a 15 term Chebyshev expansion for the\n" );
  printf ( "  sine function.\n" );
  printf ( "\n" );
  printf ( "  Accuracy    Terms Needed\n" );
  printf ( "\n" );

  tol = 1.0;
  for ( i = 1; i <= 18; i++ )
  {
    n = r8_inits ( sincs, 15, tol );
    printf ( "  %14.6g  %4d\n", tol, n );
    tol = tol / 10.0;
  }

  return;
}
/******************************************************************************/

void r8_int_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_INT_TEST tests R8_INT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_INT_TEST:\n" );
  printf ( "  R8_INT rounds an R8 to an integer value\n" );
  printf ( "\n" );
  printf ( "             X      INT(X)  R8_INT(X)         Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    int_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_int ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_lbeta_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_LBETA_TEST tests R8_LBETA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double fx1;
  double fx2;
  int n_data;

  printf ( "\n" );
  printf ( "R8_LBETA_TEST:\n" );
  printf ( "  R8_LBETA evaluates the logarithm of the Beta function.\n" );
  printf ( "\n" );
  printf ( "             A  B        LBETA(A,B)  R8_LBETA(A,B)       Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    beta_log_values ( &n_data, &a, &b, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_lbeta ( a, b );

    printf ( "  %14g  %14g  %14g  %14g  %14g\n", a, b, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_lgams_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_LGAMS_TEST tests R8_LGAMS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    01 May 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double slngam;
  double x;

  printf ( "\n" );
  printf ( "R8_LGAMS_TEST:\n" );
  printf ( "  R8_LGAMS evaluates the sign of Gamma(x) and\n" );
  printf ( "  the logarithm of the absolute value of Gamma(x).\n" );
  printf ( "\n" );
  printf ( "             X        LNGAM(X)  Sign(Gamma(X)) ALNGAM        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gamma_log_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    r8_lgams ( x, &fx2, &slngam );

    printf ( "  %14.6g  %14.6g  %14.6g  %14.6g  %14.6g\n",
      x, fx1, slngam, fx2, fabs ( fx1 - fx2 ) );

  }

  return;
}
/******************************************************************************/

void r8_lgmc_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_LGMC_TEST tests R8_LGMC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  double gamma_log;
  int n_data;
  const double r8_pi = 3.141592653589793;
  double x;

  printf ( "\n" );
  printf ( "R8_LGMC_TEST:\n" );
  printf ( "  R8_LGMC evaluates the correction log gamma factor.\n" );
  printf ( "  r8_lgmc(x) = log ( gamma ( x ) ) - log ( sqrt ( 2 * pi )\n" );
  printf ( "  - ( x - 0.5 ) * log ( x ) + x\n" );
  printf ( "\n" );
  printf ( "             X        LGMC(X)  R8_LGMC(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gamma_log_values ( &n_data, &x, &gamma_log );

    if ( n_data == 0 )
    {
      break;
    }
/*
  Function requires 10 <= x.
*/
    if ( 10.0 <= x )
    {
      fx1 = gamma_log - log ( sqrt ( 2.0 * r8_pi ) ) - ( x - 0.5 ) * log ( x ) + x;
      fx2 = r8_lgmc ( x );
      printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
    }
  }
  return;
}
/******************************************************************************/

void r8_li_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_LI_TEST tests R8_LI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_LI_TEST:\n" );
  printf ( "  R8_LI evaluates the logarithmic integral.\n" );
  printf ( "\n" );
  printf ( "             X      LI(X)  R8_LI(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    logarithmic_integral_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_li ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_lngam_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_LNGAM_TEST tests R8_LNGAM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_LNGAM_TEST:\n" );
  printf ( "  R8_LNGAM evaluates the logarithm of the gamma function.\n" );
  printf ( "\n" );
  printf ( "             X        LNGAM(X)  R8_LNGAM(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gamma_log_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_lngam ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_lnrel_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_LNREL_TEST tests R8_LNREL.

  Licensing:

    This code is distributed under the GNU LGPL logcense.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_LNREL_TEST:\n" );
  printf ( "  R8_LNREL evaluates ln(X+1).\n" );
  printf ( "\n" );
  printf ( "             X      LN(X+1)  R8_LNREL(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    log_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }
    x = x - 1.0;

    fx2 = r8_lnrel ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_log_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_LOG_TEST tests R8_LOG.

  Licensing:

    This code is distributed under the GNU LGPL logcense.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_LOG_TEST:\n" );
  printf ( "  R8_LOG evaluates the logarithm of an R8.\n" );
  printf ( "\n" );
  printf ( "             X      LOG(X)  R8_LOG(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    log_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_log ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_log10_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_LOG10_TEST tests R8_LOG10.

  Licensing:

    This code is distributed under the GNU LGPL log10cense.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_LOG10_TEST:\n" );
  printf ( "  R8_LOG10 evaluates log10(x)\n" );
  printf ( "\n" );
  printf ( "             X      LOG10(X)  R8_LOG10(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    log10_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_log10 ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_mach_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_MACH_TEST tests R8_MACH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 April 2016

  Author:

    John Burkardt
*/
{
  int i;

  printf ( "\n" );
  printf ( "R8_MACH_TEST:\n" );
  printf ( "  R8_MACH evaluates double precision machine numbers.\n" );
  printf ( "\n" );
  printf ( "  R8_MACH (1) = B^(EMIN-1), the smallest positive magnitude.\n" );
  printf ( "  R8_MACH (2) = B^EMAX*(1 - B^(-T)), the largest magnitude.\n" );
  printf ( "  R8_MACH (3) = B^(-T), the smallest relative spacing.\n" );
  printf ( "  R8_MACH (4) = B^(1-T), the largest relative spacing.\n" );
  printf ( "  R8_MACH (5) = LOG10(B)\n" );
  printf ( "\n" );
  printf ( "    I     R8_MACH(I)\n" );
  printf ( "\n" );

  for ( i = 1; i <= 5; i++ )
  {
    printf ( "  %4d  %14.6g\n", i, r8_mach ( i ) );
  }

  return;
}
/******************************************************************************/

void r8_pak_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_PAK_TEST tests R8_PAK.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  int n_test[11] = {
    7, 8, 7, 7, 4, 0, -1, 0, 7, 2, 0 };
  double x;
  double y;
  double y_test[11] = {
    0.5, 
    0.5, 
   -0.5, 
    0.75, 
    0.9375, 
    0.5, 
    0.5, 
    0.625, 
    0.5048828125, 
    0.7853981633974483, 
    0.0 };

  printf ( "\n" );
  printf ( "R8_PAK_TEST:\n" );
  printf ( "  R8_PAK converts a mantissa and base 2 exponent to an R8.\n" );
  printf ( "\n" );
  printf ( "    Mantissa     Exponent         R8\n" );
  printf ( "\n" );

  for ( i = 0; i < 11; i++ )
  {
    y = y_test[i];
    n = n_test[i];

    x = r8_pak ( y, n );
    printf ( "  %24.16g  %8d  %24.16g\n", y, n, x );
  }

  return;
}
/******************************************************************************/

void r8_poch_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_POCH_TEST tests R8_POCH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 April 2016

  Author:

    John Burkardt
*/
{
  double a;
  double fx1;
  double fx2;
  int n;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_POCH_TEST:\n" );
  printf ( "  R8_POCH evaluates the Pochhammer symbol.\n" );
  printf ( "\n" );
  printf ( "             X        POCH(A,X)  R8_POCH(A,X)       Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    r8_rise_values ( &n_data, &a, &n, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    x = ( double ) n;
    fx2 = r8_poch ( a, x );


    printf ( "  %14g  %14g  %14g  %14g  %14g\n", 
      a, x, fx1, fx2, fabs ( fx1 - fx2 ) );
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

    This code is distributed under the GNU LGPL psicense.

  Modified:

    25 April 2016

  Author:

    John Burkardt
*/
{
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "R8_PSI_TEST:\n" );
  printf ( "  R8_PSI evaluates the psi(x) function.\n" );
  printf ( "\n" );
  printf ( "             X      PSI(X)  R8_PSI(X)        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    psi_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r8_psi ( x );

    printf ( "  %14g  %14g  %14g  %14g\n", x, fx1, fx2, fabs ( fx1 - fx2 ) );
  }
  return;
}
/******************************************************************************/

void r8_rand_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_RAND_TEST tests R8_RAND.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 May 2016

  Author:

    John Burkardt
*/
{
  double average;
  int i;
  int i_value[7] = { 1, 2, 3, 4, 10, 100, 1000 };
  int ix0;
  int ix1;
  int k;
  double r;
  double r_value[7] = { 
    0.0004127026, 
    0.6750836372, 
    0.1614754200, 
    0.9086198807, 
    0.5527787209, 
    0.3600893021, 
    0.2176990509 };
  double s;
  double variance;

  printf ( "\n" );
  printf ( "R8_RAND_TEST:\n" );
  printf ( "  R8_RAND generates a random R8.\n" );
  printf ( "\n" );
  printf ( "               I       R8_RAND        Expected\n" );
  printf ( "\n" );
/*
  Start the sequence.
*/
  ix0 = 0;
  ix1 = 0;
  s = 0.0;

  k = 0;

  for ( i = 1; i <= 1000; i++ )
  {
    r = r8_rand ( s, &ix0, &ix1 );

    if ( i == i_value[k] )
    {
      printf ( "  %14d  %14g  %14g\n", i, r, r_value[k] );
      k = k + 1;
    }
  }
/*
  Restart the sequence.
*/
  ix0 = 0;
  ix1 = 0;
  s = 0.0;

  average = 0.0;
  for ( i = 1; i <= 1000000; i++ )
  {
    r = r8_rand ( s, &ix0, &ix1 );
    average = average + r;
  }
  average = average / 1000000.0;
  printf ( "\n" );
  printf ( "     Average =  %14g  %14g\n", average, 0.5 );
/*
  Restart the sequence.
*/
  ix0 = 0;
  ix1 = 0;
  s = 0.0;

  variance = 0.0;
  for ( i = 1; i <= 1000000; i++ )
  {
    r = r8_rand ( s, &ix0, &ix1 );
    variance = variance + pow ( r - average, 2 );
  }
  variance = variance / 1000000.0;
  printf ( "     Variance = %14g  %14g\n", variance, 1.0 / 12.0 );

  return;
}
/******************************************************************************/

void r8_randgs_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_RANDGS_TEST tests R8_RANDGS.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  int i;
  double m;
  double m2;
  double r;
  double sd;
  double sd2;
  int seed;

  m = 3.0;
  sd = 2.0;
  seed = 123456789;

  printf ( "\n" );
  printf ( "R8_RANDGS_TEST:\n" );
  printf ( "  R8_RANDGS generates a random normal R8.\n" );
  printf ( "  Mean =  %14g\n", m );
  printf ( "  Standard deviation =  %14g\n", sd );
  printf ( "\n" );
  printf ( "               I       R8_RANDGS\n" );
  printf ( "\n" );

  m2 = 0.0;
  sd2 = 0.0;

  for ( i = 1; i <= 1000; i++ )
  {
    r = r8_randgs ( m, sd, &seed );
    m2 = m2 + r;
    sd2 = sd2 + pow ( m - r, 2 );
    if ( i <= 10 )
    {
      printf ( "  %14d  %14g\n", i, r );
    }
  }

  m2 = m2 / 1000.0;
  sd2 = sqrt ( sd2 / 1000.0 );

  printf ( "\n" );
  printf ( "  Sequence mean =  %14g\n", m2 );
  printf ( "  Sequence standard deviation =  %14g\n", sd2 );

  return;
}
/******************************************************************************/

void r8_random_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_RANDOM_TEST tests R8_RANDOM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 May 2016

  Author:

    John Burkardt
*/
{
  double average;
  int i;
  int i_value[7] = { 1, 2, 3, 4, 10, 100, 1000 };
  int ix0;
  int ix1;
  int k;
  int n = 32;
  double r;
  double t[33];
  double variance;

  printf ( "\n" );
  printf ( "R8_RANDOM_TEST:\n" );
  printf ( "  R8_RANDOM generates a random R8.\n" );
  printf ( "\n" );
  printf ( "               I       R8_RANDOM\n" );
  printf ( "\n" );
/*
  Start the sequence.
*/
  ix0 = 0;
  ix1 = 0;
  r8_random_init ( n, t, &ix0, &ix1 );

  k = 0;

  for ( i = 1; i <= 1000; i++ )
  {
    r = r8_random ( n, t, &ix0, &ix1 );

    if ( i == i_value[k] )
    {
      printf ( "  %14d  %14g\n", i, r );
      k = k + 1;
    }
  }
/*
  Restart the sequence.
*/
  ix0 = 0;
  ix1 = 0;
  r8_random_init ( n, t, &ix0, &ix1 );

  average = 0.0;
  for ( i = 1; i <= 1000000; i++ )
  {
    r = r8_random ( n, t, &ix0, &ix1 );
    average = average + r;
  }
  average = average / 1000000.0;
  printf ( "\n" );
  printf ( "     Average =  %14g  %14g\n", average, 0.5 );
/*
  Restart the sequence.
*/
  ix0 = 0;
  ix1 = 0;
  r8_random_init ( n, t, &ix0, &ix1 );

  variance = 0.0;
  for ( i = 1; i <= 1000000; i++ )
  {
    r = r8_random ( n, t, &ix0, &ix1 );
    variance = variance + pow ( r - average, 2 );
  }
  variance = variance / 1000000.0;
  printf ( "     Variance = %14g  %14g\n", variance, 1.0 / 12.0 );

  return;
}
/******************************************************************************/

void r8_ren_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_REN_TEST tests R8_REN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    15 May 2016

  Author:

    John Burkardt
*/
{
  double average;
  int i;
  int i_value[7] = { 1, 2, 3, 4, 10, 100, 1000 };
  int k;
  double r;
  double r_value[7] = { 
    0.470393,
    0.799066,
    0.883261,
    0.407667,
    0.955566,
    0.173576,
    0.121733 };
  int seed;
  double variance;

  printf ( "\n" );
  printf ( "R8_REN_TEST:\n" );
  printf ( "  R8_REN generates a random R8 value.\n" );
  printf ( "\n" );
  printf ( "               I       R8_REN         Expected\n" );
  printf ( "\n" );

  seed = 100001;
  k = 0;

  for ( i = 1; i <= 1000; i++ )
  {
    r = r8_ren ( &seed );

    if ( i == i_value[k] )
    {
      printf ( "  %14d  %14g  %14g\n", i, r, r_value[k] );
      k = k + 1;
    }
  }

  seed = 123456789;
  average = 0.0;
  for ( i = 1; i <= 1000000; i++ )
  {
    r = r8_ren ( &seed );
    average = average + r;
  }
  average = average / 1000000.0;
  printf ( "\n" );
  printf ( "     Average =  %14g  %14g\n", average, 0.5 );

  seed = 123456789;
  variance = 0.0;
  for ( i = 1; i <= 1000000; i++ )
  {
    r = r8_ren ( &seed );
    variance = variance + pow ( r - average, 2 );
  }
  variance = variance / 1000000.0;
  printf ( "     Variance = %14g  %14g\n", variance, 1.0 / 12.0 );

  return;
}
/******************************************************************************/

void shi_test ( )

/******************************************************************************/
/*
  Purpose:

    SHI_TEST tests R4_SHI and R8_SHI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  float fx2;
  double fx3;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "SHI_TEST:\n" );
  printf ( "  Test SHI_VALUES, R4_SHI, R8_SHI.\n" );
  printf ( "\n" );
  printf ( "             X      SHI(X)\n" );
  printf ( "                   R4_SHI(X)         Diff\n" );
  printf ( "                   R8_SHI(X)         Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    shi_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r4_shi ( ( float ) x );
    fx3 = r8_shi ( x );

    printf ( "\n" );
    printf ( "  %14g  %14g\n", x, fx1 );
    printf ( "                  %14g  %14g\n", fx2, fabs ( fx1 - fx2 ) );
    printf ( "                  %14g  %14g\n", fx3, fabs ( fx1 - fx3 ) );
  }
  return;
}
/******************************************************************************/

void si_test ( )

/******************************************************************************/
/*
  Purpose:

    SI_TEST tests R4_SI and R8_SI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  float fx2;
  double fx3;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "SI_TEST:\n" );
  printf ( "  Test SI_VALUES, R4_SI, R8_SI.\n" );
  printf ( "\n" );
  printf ( "             X      SI(X)\n" );
  printf ( "                   R4_SI(X)         Diff\n" );
  printf ( "                   R8_SI(X)         Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    si_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r4_si ( ( float ) x );
    fx3 = r8_si ( x );

    printf ( "\n" );
    printf ( "  %14g  %14g\n", x, fx1 );
    printf ( "                  %14g  %14g\n", fx2, fabs ( fx1 - fx2 ) );
    printf ( "                  %14g  %14g\n", fx3, fabs ( fx1 - fx3 ) );
  }
  return;
}
/******************************************************************************/

void sin_test ( )

/******************************************************************************/
/*
  Purpose:

    SIN_TEST tests R4_SIN and R8_SIN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  float fx2;
  double fx3;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "SIN_TEST:\n" );
  printf ( "  Test SIN_VALUES, R4_SIN, R8_SIN.\n" );
  printf ( "\n" );
  printf ( "             X      SIN(X)\n" );
  printf ( "                   R4_SIN(X)         Diff\n" );
  printf ( "                   R8_SIN(X)         Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    sin_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r4_sin ( ( float ) x );
    fx3 = r8_sin ( x );

    printf ( "\n" );
    printf ( "  %14g  %14g\n", x, fx1 );
    printf ( "                  %14g  %14g\n", fx2, fabs ( fx1 - fx2 ) );
    printf ( "                  %14g  %14g\n", fx3, fabs ( fx1 - fx3 ) );
  }
  return;
}
/******************************************************************************/

void sin_deg_test ( )

/******************************************************************************/
/*
  Purpose:

    SIN_DEG_TEST tests R4_SIN_DEG and R8_SIN_DEG.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  float fx2;
  double fx3;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "SIN_DEG_TEST:\n" );
  printf ( "  Test SIN_DEGREE_VALUES, R4_SIN_DEG, R8_SIN_DEG.\n" );
  printf ( "\n" );
  printf ( "             X      SIN_DEG(X)\n" );
  printf ( "                   R4_SIN_DEG(X)         Diff\n" );
  printf ( "                   R8_SIN_DEG(X)         Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    sin_degree_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r4_sin_deg ( ( float ) x );
    fx3 = r8_sin_deg ( x );

    printf ( "\n" );
    printf ( "  %14g  %14g\n", x, fx1 );
    printf ( "                  %14g  %14g\n", fx2, fabs ( fx1 - fx2 ) );
    printf ( "                  %14g  %14g\n", fx3, fabs ( fx1 - fx3 ) );
  }
  return;
}
/******************************************************************************/

void sinh_test ( )

/******************************************************************************/
/*
  Purpose:

    SINH_TEST tests R4_SINH and R8_SINH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  float fx2;
  double fx3;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "SINH_TEST:\n" );
  printf ( "  Test SINH_VALUES, R4_SINH, R8_SINH\n" );
  printf ( "\n" );
  printf ( "             X      SINH(X)\n" );
  printf ( "                   R4_SINH(X)        Diff\n" );
  printf ( "                   R8_SINH(X)        Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    sinh_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r4_sinh ( ( float ) x );
    fx3 = r8_sinh ( x );

    printf ( "\n" );
    printf ( "  %14g  %14g\n", x, fx1 );
    printf ( "                  %14g  %14g\n", fx2, fabs ( fx1 - fx2 ) );
    printf ( "                  %14g  %14g\n", fx3, fabs ( fx1 - fx3 ) );
  }
  return;
}
/******************************************************************************/

void spence_test ( )

/******************************************************************************/
/*
  Purpose:

    SPENCE_TEST tests R4_SPENCE and R8_SPENCE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  float fx2;
  double fx3;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "SPENCE_TEST:\n" );
  printf ( "  Test DILOGARITHM_VALUES, R4_SPENCE, R8_SPENCE\n" );
  printf ( "\n" );
  printf ( "             X      SPENCE(X)\n" );
  printf ( "                   R4_SPENCE(X)        Diff\n" );
  printf ( "                   R8_SPENCE(X)        Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    dilogarithm_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r4_spence ( ( float ) x );
    fx3 = r8_spence ( x );

    printf ( "\n" );
    printf ( "  %14g  %14g\n", x, fx1 );
    printf ( "                  %14g  %14g\n", fx2, fabs ( fx1 - fx2 ) );
    printf ( "                  %14g  %14g\n", fx3, fabs ( fx1 - fx3 ) );
  }
  return;
}
/******************************************************************************/

void sqrt_test ( )

/******************************************************************************/
/*
  Purpose:

    SQRT_TEST tests R4_SQRT and R8_SQRT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  float fx2;
  double fx3;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "SQRT_TEST:\n" );
  printf ( "  Test SQRT_VALUES, R4_SQRT, R8_SQRT\n" );
  printf ( "\n" );
  printf ( "             X      SQRT(X)\n" );
  printf ( "                   R4_SQRT(X)        Diff\n" );
  printf ( "                   R8_SQRT(X)        Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    sqrt_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r4_sqrt ( ( float ) x );
    fx3 = r8_sqrt ( x );

    printf ( "\n" );
    printf ( "  %14g  %14g\n", x, fx1 );
    printf ( "                  %14g  %14g\n", fx2, fabs ( fx1 - fx2 ) );
    printf ( "                  %14g  %14g\n", fx3, fabs ( fx1 - fx3 ) );
  }
  return;
}
/******************************************************************************/

void tan_test ( )

/******************************************************************************/
/*
  Purpose:

    TAN_TEST tests R4_TAN and R8_TAN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  float fx2;
  double fx3;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "TAN_TEST:\n" );
  printf ( "  Test TAN_VALUES, R4_TAN, R8_TAN.\n" );
  printf ( "\n" );
  printf ( "             X      TAN(X)\n" );
  printf ( "                   R4_TAN(X)         Diff\n" );
  printf ( "                   R8_TAN(X)         Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    tan_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r4_tan ( ( float ) x );
    fx3 = r8_tan ( x );

    printf ( "\n" );
    printf ( "  %14g  %14g\n", x, fx1 );
    printf ( "                  %14g  %14g\n", fx2, fabs ( fx1 - fx2 ) );
    printf ( "                  %14g  %14g\n", fx3, fabs ( fx1 - fx3 ) );
  }
  return;
}
/******************************************************************************/

void tanh_test ( )

/******************************************************************************/
/*
  Purpose:

    TANH_TEST tests R4_TANH and R8_TANH.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 January 2012

  Author:

    John Burkardt
*/
{
  double fx1;
  float fx2;
  double fx3;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "TANH_TEST:\n" );
  printf ( "  Test TANH_VALUES, R4_TANH, R8_TANH\n" );
  printf ( "\n" );
  printf ( "             X      TANH(X)\n" );
  printf ( "                   R4_TANH(X)        Diff\n" );
  printf ( "                   R8_TANH(X)        Diff\n" );

  n_data = 0;

  for ( ; ; )
  {
    tanh_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = r4_tanh ( ( float ) x );
    fx3 = r8_tanh ( x );

    printf ( "\n" );
    printf ( "  %14g  %14g\n", x, fx1 );
    printf ( "                  %14g  %14g\n", fx2, fabs ( fx1 - fx2 ) );
    printf ( "                  %14g  %14g\n", fx3, fabs ( fx1 - fx3 ) );
  }
  return;
}
/******************************************************************************/

void r8_upak_test ( )

/******************************************************************************/
/*
  Purpose:

    R8_UPAK_TEST tests R8_UPAK.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 April 2016

  Author:

    John Burkardt
*/
{
  int i;
  int n;
  double x;
  double x_test[11] = {
    64.0,
   128.0,
   -64.0,
    96.0,
    15.0,
    0.5,
    0.25,
    0.625,
   64.625,
    3.141592653589793,
    0.0 };
  double y;

  printf ( "\n" );
  printf ( "R8_UPAK_TEST:\n" );
  printf ( "  R8_UPAK converts an R8 to a mantissa and base 2 exponent.\n" );
  printf ( "\n" );
  printf ( "             X         Mantissa     Exponent\n" );
  printf ( "\n" );

  for ( i = 0; i < 11; i++ )
  {
    x = x_test[i];

    r8_upak ( x, &y, &n );

    printf ( "  %14.6g  %14.6g  %8d\n", x, y, n );
  }

  return;
}
