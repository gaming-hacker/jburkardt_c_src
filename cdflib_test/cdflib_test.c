# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "cdflib.h"

int main ( );
void beta_test ( );
void beta_inc_test ( );
void cdfbet_test ( );
void cdfbin_test ( );
void cdfchi_test ( );
void cdfchn_test ( );
void cdff_test ( );
void cdffnc_test ( );
void cdfgam_test ( );
void cdfnbn_test ( );
void cdfnor_test ( );

void cdfpoi_test ( );
void cdft_test ( );
void cumbet_test ( );
void cumbin_test ( );
void cumchi_test ( );
void cumchn_test ( );
void cumf_test ( );
void cumfnc_test ( );
void cumgam_test ( );
void cumnbn_test ( );

void cumnor_test ( );
void cumpoi_test ( );
void cumt_test ( );
void error_f_test ( );
void gamma_x_test ( );
void gamma_inc_test ( );
void psi_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    cdflib_test() tests cdflib().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    13 July 2013

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "cdflib_test():\n" );
  printf ( "  C version\n" );
  printf ( "  Test cdflib().\n" );

  beta_test ( );
  beta_inc_test ( );
  cdfbet_test ( );
  cdfbin_test ( );
  cdfchi_test ( );
  cdfchn_test ( );
  cdff_test ( );
  cdffnc_test ( );
  cdfgam_test ( );
  cdfnbn_test ( );
  cdfnor_test ( );

  cdfpoi_test ( );
  cdft_test ( );
  cumbet_test ( );
  cumbin_test ( );
  cumchi_test ( );
  cumchn_test ( );
  cumf_test ( );
  cumfnc_test ( );
  cumgam_test ( );
  cumnbn_test ( );

  cumnor_test ( );
  cumpoi_test ( );
  cumt_test ( );
  error_f_test ( );
  gamma_x_test ( );
  gamma_inc_test ( );
  psi_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "cdflib_test()\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void beta_test ( )

/******************************************************************************/
/*
  Purpose:

    beta_test tests BETA, GAMMA_X.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double apb;
  double beta1;
  double beta2;

  printf ( "\n" );
  printf ( "beta_test\n" );
  printf ( "  BETA evaluates the Beta function;\n" );
  printf ( "  GAMMA_X evaluates the Gamma function.\n" );

  a = 2.2;
  b = 3.7;
  apb = a + b;

  beta1 = beta ( a, b );
  beta2 = gamma_x ( &a ) * gamma_x ( &b ) / gamma_x ( &apb );

  printf ( "\n" );
  printf ( "  Argument A =                   %g\n", a );
  printf ( "  Argument B =                   %g\n", b );
  printf ( "  Beta(A,B) =                    %g\n", beta1 );
  printf ( "  (Expected value = 0.0454 )\n" );
  printf ( "\n" );
  printf ( "  Gamma(A)*Gamma(B)/Gamma(A+B) = %g\n", beta2 );

  return;
}
/******************************************************************************/

void beta_inc_test ( )

/******************************************************************************/
/*
  Purpose:

    beta_inc_test tests BETA_INC and BETA_INC_VALUES.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int ierror;
  int n_data;
  double x;
  double y;

  printf ( "\n" );
  printf ( "beta_inc_test\n" );
  printf ( "  BETA_INC computes the incomplete Beta ratio.\n" );
  printf ( "  BETA_INC_CDF_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    X         Y         A         B         CDF           CDF\n" );
  printf (
    "                                           (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    beta_inc_values ( &n_data, &a, &b, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    y = 1.0 - x;

    beta_inc ( &a, &b, &x, &y, &cdf_compute, &ccdf_compute, &ierror );

    printf ( "  %10g  %10g  %10g  %10g  %14g  %14g\n",
      x, y, a, b, cdf_lookup, cdf_compute );
  }

  printf ( "\n" );
  printf ( "    X         Y         A         B         1-CDF         CCDF\n" );
  printf (
    "                                           (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    beta_inc_values ( &n_data, &a, &b, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    y = 1.0 - x;

    beta_inc ( &a, &b, &x, &y, &cdf_compute, &ccdf_compute, &ierror );

    printf ( "  %10g  %10g  %10g  %10g  %14g  %14g\n",
      x, y, a, b, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void cdfbet_test ( )

/******************************************************************************/
/*
  Purpose:

    cdfbet_test tests CDFBET.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double bound;
  double p;
  double q;
  int status;
  int which;
  double x;
  double y;

  printf ( "\n" );
  printf ( "cdfbet_test\n" );
  printf ( "  CDFBET computes one missing parameter from the\n" );
  printf ( "  BETA CDF:\n" );
  printf ( "\n" );
  printf ( "   BETA_CDF ( (P,Q), (X,Y), A, B )\n" );
  printf ( "\n" );
  printf ( "      P           Q               X           Y" );
  printf ( "            A           B\n" );
  printf ( "\n" );

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      x = 0.25;
      y = 1.0 - x;
      a = 2.0;
      b = 3.0;
    }
    else if ( which == 2 )
    {
      p = 0.261719;
      q = 1.0 - p;
      x = -1.0;
      y = -1.0;
      a = 2.0;
      b = 3.0;
    }
    else if ( which == 3 )
    {
      p = 0.261719;
      q = 1.0 - p;
      x = 0.25;
      y = 1.0 - x;
      a = -1.0;
      b = 3.0;
    }
    else if ( which == 4 )
    {
      p = 0.261719;
      q = 1.0 - p;
      x = 0.25;
      y = 1.0 - x;
      a = 2.0;
      b = -1.0;
    }

    cdfbet ( &which, &p, &q, &x, &y, &a, &b, &status, &bound );

    if ( status != 0 )
    {
      printf ( "\n" );
      printf ( "  CDFBET returned STATUS = %d\n", status );
      continue;
    }
    printf ( "  %10g  %10g  %10g  %10g  %10g  %10g\n",
      p, q, x, y, a, b );
  }

  return;
}
/******************************************************************************/

void cdfbin_test ( )

/******************************************************************************/
/*
  Purpose:

    cdfbin_test tests CDFBIN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double bound;
  double ompr;
  double p;
  double pr;
  double q;
  double s;
  int status;
  int which;
  double xn;

  printf ( "\n" );
  printf ( "cdfbin_test\n" );
  printf ( "  CDFBIN computes one missing parameter from the\n" );
  printf ( "  Binomial CDF:\n" );
  printf ( "\n" );
  printf ( "   BINOMIAL_CDF ( (P,Q), S, XN, (PR,OMPR) )\n" );
  printf ( "\n" );
  printf ( "      P           Q                S          " );
  printf ( "XN         PR         OMPR\n" );
  printf ( "\n" );

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      s = 5.0;
      xn = 8.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 2 )
    {
      p = 0.067347;
      q = 1.0 - p;
      s = -1.0;
      xn = 8.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 3 )
    {
      p = 0.067347;
      q = 1.0 - p;
      s = 5.0;
      xn = -1.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 4 )
    {
      p = 0.067347;
      q = 1.0 - p;
      s = 5.0;
      xn = 8.0;
      pr = -1.0;
      ompr = -1.0;
    }

    cdfbin ( &which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound );

    if ( status != 0 )
    {
      printf ( "\n" );
      printf ( "  CDFBIN returned STATUS = %d\n", status );
      continue;
    }
    printf ( "  %10g  %10g  %10g  %10g  %10g  %10g\n",
      p, q, s, xn, pr, ompr );
  }

  return;
}
/******************************************************************************/

void cdfchi_test ( )

/******************************************************************************/
/*
  Purpose:

    cdfchi_test tests CDFCHI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double bound;
  double df;
  double p;
  double q;
  int status;
  int which;
  double x;

  printf ( "\n" );
  printf ( "cdfchi_test\n" );
  printf ( "  CDFCHI computes one missing parameter from the\n" );
  printf ( "  Chi Square CDF:\n" );
  printf ( "\n" );
  printf ( "   CHI_CDF ( (P,Q), X, DF )\n" );
  printf ( "\n" );
  printf ( "      P           Q                X          DF\n" );
  printf ( "\n" );

  for ( which = 1; which <= 3; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      x = 5.0;
      df = 8.0;
    }
    else if ( which == 2 )
    {
      p = 0.242424;
      q = 1.0 - p;
      x = -1.0;
      df = 8.0;
    }
    else if ( which == 3 )
    {
      p = 0.242424;
      q = 1.0 - p;
      x = 5.0;
      df = -1.0;
    }

    cdfchi ( &which, &p, &q, &x, &df, &status, &bound );

    if ( status != 0 )
    {
      printf ( "\n" );
      printf ( "  CDFCHI returned STATUS = %d\n", status );
      continue;
    }
    printf ( "  %10g  %10g  %10g  %10g\n", p, q, x, df );
  }
  return;
}
/******************************************************************************/

void cdfchn_test ( )

/******************************************************************************/
/*
  Purpose:

    cdfchn_test tests CDFCHN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double bound;
  double df;
  double p;
  double pnonc;
  double q;
  int status;
  int which;
  double x;

  printf ( "\n" );
  printf ( "cdfchn_test\n" );
  printf ( "  CDFCHN computes one missing parameter from the\n" );
  printf ( "  Chi Square CDF:\n" );
  printf ( "\n" );
  printf ( "   CHI_Noncentral_CDF ( (P,Q), X, DF, PNONC )\n" );
  printf ( "\n" );
  printf ( "     P         Q             X        DF     PNONC\n" );
  printf ( "\n" );

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      x = 5.0;
      df = 8.0;
      pnonc = 0.5;
    }
    else if ( which == 2 )
    {
      p = 0.211040;
      q = 1.0 - p;
      x = -1.0;
      df = 8.0;
      pnonc = 0.5;
    }
    else if ( which == 3 )
    {
      p = 0.211040;
      q = 1.0 - p;
      x = 5.0;
      df = -1.0;
      pnonc = 0.5;
    }
    else if ( which == 4 )
    {
      p = 0.211040;
      q = 1.0 - p;
      x = 5.0;
      df = 8.0;
      pnonc = -1.0;
    }

    cdfchn ( &which, &p, &q, &x, &df, &pnonc, &status, &bound );

    if ( status != 0 )
    {
      printf ( "\n" );
      printf ( "  CDFCHN returned STATUS = %d\n", status );
      continue;
    }

    printf ( "  %10g  %10g  %10g  %10g  %10g\n",
      p, q, x, df, pnonc );
  }
  return;
}
/******************************************************************************/

void cdff_test ( )

/******************************************************************************/
/*
  Purpose:

    cdff_test tests CDFF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double bound;
  double dfd;
  double dfn;
  double f;
  double p;
  double q;
  int status;
  int which;

  printf ( "\n" );
  printf ( "cdff_test\n" );
  printf ( "  CDFF computes one missing parameter from the\n" );
  printf ( "  F CDF:\n" );
  printf ( "\n" );
  printf ( "   F_CDF ( (P,Q), F, DFN, DFD )\n" );
  printf ( "\n" );
  printf ( "     P         Q             F       DFN       DFD\n" );
  printf ( "\n" );

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      f = 5.0;
      dfn = 8.0;
      dfd = 3.0;
    }
    else if ( which == 2 )
    {
      p = 0.893510;
      q = 1.0 - p;
      f = -1.0;
      dfn = 8.0;
      dfd = 3.0;
    }
    else if ( which == 3 )
    {
      p = 0.893510;
      q = 1.0 - p;
      f = 5.0;
      dfn = -1.0;
      dfd = 3.0;
    }
    else if ( which == 4 )
    {
      p = 0.893510;
      q = 1.0 - p;
      f = 5.0;
      dfn = 8.0;
      dfd = -1.0;
    }

    cdff ( &which, &p, &q, &f, &dfn, &dfd, &status, &bound );

    if ( status != 0 )
    {
      printf ( "\n" );
      printf ( "  CDFF returned STATUS = %d\n", status );
      continue;
    }

    printf ( "  %10g  %10g  %10g  %10g  %10g\n",
      p, q, f, dfn, dfd );
  }
  return;
}
/******************************************************************************/

void cdffnc_test ( )

/******************************************************************************/
/*
  Purpose:

    cdffnc_test tests CDFFNC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double bound;
  double dfd;
  double dfn;
  double f;
  double p;
  double pnonc;
  double q;
  int status;
  int which;

  printf ( "\n" );
  printf ( "cdffnc_test\n" );
  printf ( "  CDFFNC computes one missing parameter from the\n" );
  printf ( "  noncentral F CDF:\n" );
  printf ( "\n" );
  printf ( "   F_noncentral_CDF ( (P,Q), F, DFN, DFD, PNONC )\n" );
  printf ( "\n" );
  printf ( "         P         Q         F       DFN       DFD     PNONC\n" );
  printf ( "\n" );

  for ( which = 1; which <= 5; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      f = 5.0;
      dfn = 8.0;
      dfd = 3.0;
      pnonc = 17.648016;
    }
    else if ( which == 2 )
    {
      p = 0.60;
      q = 1.0 - p;
      f = -1.0;
      dfn = 8.0;
      dfd = 3.0;
      pnonc = 17.648016;
    }
    else if ( which == 3 )
    {
      p = 0.60;
      q = 1.0 - p;
      f = 5.0;
      dfn = -1.0;
      dfd = 3.0;
      pnonc = 17.648016;
    }
    else if ( which == 4 )
    {
      p = 0.60;
      q = 1.0 - p;
      f = 5.0;
      dfn = 8.0;
      dfd = -1.0;
      pnonc = 17.648016;
    }
    else if ( which == 5 )
    {
      p = 0.60;
      q = 1.0 - p;
      f = 5.0;
      dfn = 8.0;
      dfd = 3.0;
      pnonc = -1.0;
    }

    cdffnc ( &which, &p, &q, &f, &dfn, &dfd, &pnonc, &status, &bound );

    if ( status != 0 )
    {
      printf ( "\n" );
      printf ( "  CDFFNC returned STATUS = %d\n", status );
      continue;
    }

    printf ( "  %10g  %10g  %10g  %10g  %10g  %10g\n",
      p, q, f, dfn, dfd, pnonc );
  }

  return;
}
/******************************************************************************/

void cdfgam_test ( )

/******************************************************************************/
/*
  Purpose:

    cdfgam_test tests CDFGAM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double bound;
  double p;
  double q;
  double scale;
  double shape;
  int status;
  int which;
  double x;

  printf ( "\n" );
  printf ( "cdfgam_test\n" );
  printf ( "  CDFGAM computes one missing parameter from the\n" );
  printf ( "  Gamma CDF:\n" );
  printf ( "\n" );
  printf ( "   Gamma_CDF ( (P,Q), X, SHAPE, SCALE )\n" );
  printf ( "\n" );
  printf ( "    P         Q              X     SHAPE     SCALE\n" );
  printf ( "\n" );

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      x = 5.0;
      shape = 8.0;
      scale = 3.0;
    }
    else if ( which == 2 )
    {
      p = 0.981998;
      q = 1.0 - p;
      x = -1.0;
      shape = 8.0;
      scale = 3.0;
    }
    else if ( which == 3 )
    {
      p = 0.981998;
      q = 1.0 - p;
      x = 5.0;
      shape = -1.0;
      scale = 3.0;
    }
    else if ( which == 4 )
    {
      p = 0.981998;
      q = 1.0 - p;
      x = 5.0;
      shape = 8.0;
      scale = -1.0;
    }

    cdfgam ( &which, &p, &q, &x, &shape, &scale, &status, &bound );

    if ( status != 0 )
    {
      printf ( "\n" );
      printf ( "  CDFGAM returned STATUS = %d\n", status );
      continue;
    }

    printf ( "  %10g  %10g  %10g  %10g  %10g\n",
      p, q, x, shape, scale );
  }

  return;
}
/******************************************************************************/

void cdfnbn_test ( )

/******************************************************************************/
/*
  Purpose:

    cdfnbn_test tests CDFNBN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double bound;
  double f;
  double ompr;
  double p;
  double pr;
  double q;
  double s;
  int status;
  int which;

  printf ( "\n" );
  printf ( "cdfnbn_test\n" );
  printf ( "  CDFNBN computes one missing parameter from the\n" );
  printf ( "  negative Binomial CDF:\n" );
  printf ( "\n" );
  printf ( "   negative binomial CDF ( (P,Q), F, S, (PR,OMPR) )\n" );
  printf ( "\n" );
  printf ( "    P         Q               F         S       PR        OMPR\n" );
  printf ( "\n" );

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      f = 3.0;
      s = 5.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 2 )
    {
      p = 0.988752;
      q = 1.0 - p;
      f = -1.0;
      s = 5.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 3 )
    {
      p = 0.988752;
      q = 1.0 - p;
      f = 3.0;
      s = -1.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 4 )
    {
      p = 0.988752;
      q = 1.0 - p;
      f = 3.0;
      s = 5.0;
      pr = -1.0;
      ompr = -1.0;
    }

    cdfnbn ( &which, &p, &q, &f, &s, &pr, &ompr, &status, &bound );

    if ( status != 0 )
    {
      printf ( "\n" );
      printf ( "  CDFNBN returned STATUS = %d\n", status );
      continue;
    }
    printf ( "  %10g  %10g  %10g  %10g  %10g  %10g\n",
      p, q, f, s, pr, ompr );
  }

  return;
}
/******************************************************************************/

void cdfnor_test ( )

/******************************************************************************/
/*
  Purpose:

    cdfnor_test tests CDFNOR.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double bound;
  double mean;
  double p;
  double q;
  double sd;
  int status;
  int which;
  double x;

  printf ( "\n" );
  printf ( "cdfnor_test\n" );
  printf ( "  CDFNOR computes one missing parameter from the\n" );
  printf ( "  Normal CDF:\n" );
  printf ( "\n" );
  printf ( "   Normal_CDF ( (P,Q), X, MEAN, SD )\n" );
  printf ( "\n" );
  printf ( "    P         Q               X      MEAN       SD\n" );
  printf ( "\n" );

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      x = 3.0;
      mean = 5.0;
      sd = 0.875;
    }
    else if ( which == 2 )
    {
      p = 0.011135;
      q = 1.0 - p;
      x = -1.0;
      mean = 5.0;
      sd = 0.875;
    }
    else if ( which == 3 )
    {
      p = 0.011135;
      q = 1.0 - p;
      x = 3.0;
      mean = -1.0;
      sd = 0.875;
    }
    else if ( which == 4 )
    {
      p = 0.011135;
      q = 1.0 - p;
      x = 3.0;
      mean = 5.0;
      sd = -1.0;
    }

    cdfnor ( &which, &p, &q, &x, &mean, &sd, &status, &bound );

    if ( status != 0 )
    {
      printf ( "\n" );
      printf ( "  CDFNOR returned STATUS = %d\n", status );
      continue;
    }
    printf ( "  %10g  %10g  %10g  %10g  %10g\n",
      p, q, x, mean, sd );
  }

  return;
}
/******************************************************************************/

void cdfpoi_test ( )

/******************************************************************************/
/*
  Purpose:

    cdfpoi_test tests CDFPOI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double bound;
  double p;
  double q;
  double s;
  int status;
  int which;
  double xlam;

  printf ( "\n" );
  printf ( "cdfpoi_test\n" );
  printf ( "  CDFPOI computes one missing parameter from the\n" );
  printf ( "  Poisson CDF:\n" );
  printf ( "\n" );
  printf ( "   POISSON_CDF ( (P,Q), S, XLAM )\n" );
  printf ( "\n" );
  printf ( "     P         Q         S         XLAM\n" );
  printf ( "\n" );

  for ( which = 1; which <= 3; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      s = 3.0;
      xlam = 5.0;
    }
    else if ( which == 2 )
    {
      p = 0.265026;
      q = 1.0 - p;
      s = -1.0;
      xlam = 5.0;
    }
    else if ( which == 3 )
    {
      p = 0.265026;
      q = 1.0 - p;
      s = 3.0;
      xlam = -1.0;
    }

    cdfpoi ( &which, &p, &q, &s, &xlam, &status, &bound );

    if ( status != 0 )
    {
      printf ( "\n" );
      printf ( "  CDFPOI returned STATUS = %d\n", status );
      continue;
    }
    printf ( "  %10g  %10g  %10g  %10g\n",
      p, q, s, xlam );
  }

  return;
}
/******************************************************************************/

void cdft_test ( )

/******************************************************************************/
/*
  Purpose:

    cdft_test tests CDFT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double bound;
  double df;
  double p;
  double q;
  int status;
  double t;
  int which;

  printf ( "\n" );
  printf ( "cdft_test\n" );
  printf ( "  CDFT computes one missing parameter from the\n" );
  printf ( "  T CDF:\n" );
  printf ( "\n" );
  printf ( "   T_CDF ( (P,Q), T, DF )\n" );
  printf ( "\n" );
  printf ( "    P         Q         T         DF\n" );
  printf ( "\n" );

  for ( which = 1; which <= 3; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      t = 3.0;
      df = 5.0;
    }
    else if ( which == 2 )
    {
      p = 0.984950;
      q = 1.0 - p;
      t = -1.0;
      df = 5.0;
    }
    else if ( which == 3 )
    {
      p = 0.984950;
      q = 1.0 - p;
      t = 3.0;
      df = -1.0;
    }

    cdft ( &which, &p, &q, &t, &df, &status, &bound );

    if ( status != 0 )
    {
      printf ( "\n" );
      printf ( "  CDFT returned STATUS = %d\n", status );
      continue;
    }
    printf ( "  %10g  %10g  %10g  %10g\n",
      p, q, t, df );
  }

  return;
}
/******************************************************************************/

void cumbet_test ( )

/******************************************************************************/
/*
  Purpose:

    cumbet_test tests CUMBET.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int n_data;
  double x;
  double y;

  printf ( "\n" );
  printf ( "cumbet_test\n" );
  printf ( "  CUMBET computes the Beta CDF\n" );
  printf ( "  and the complementary CDF.\n" );
  printf ( "  BETA_INC_CDF_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    X         Y         A         B         CDF           CDF\n" );
  printf (
    "                                           (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    beta_inc_values ( &n_data, &a, &b, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    y = 1.0 - x;

    cumbet ( &x, &y, &a, &b, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10g  %10g  %10g  %10g  %10g\n",
      x, y, a, b, cdf_lookup, cdf_compute );
  }

  printf ( "\n" );
  printf ( "    X         Y         A         B         1-CDF         CCDF\n" );
  printf (
    "                                           (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    beta_inc_values ( &n_data, &a, &b, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    y = 1.0 - x;

    cumbet ( &x, &y, &a, &b, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10g  %10g  %10g  %10g  %10g\n",
      x, y, a, b, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void cumbin_test ( )

/******************************************************************************/
/*
  Purpose:

    cumbin_test tests CUMBIN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int n_data;
  double ompr;
  int s;
  double s_double;
  double pr;
  int x;
  double x_double;

  printf ( "\n" );
  printf ( "cumbin_test\n" );
  printf ( "  CUMBIN computes the Binomial CDF\n" );
  printf ( "  and the complementary CDF.\n" );
  printf ( "  BINOMIAL_CDF_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "   X   S    Pr       CDF           CDF\n" );
  printf ( "                    (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    binomial_cdf_values ( &n_data, &x, &pr, &s, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ompr = 1.0 - pr;

    s_double = ( double ) s;
    x_double = ( double ) x;

    cumbin ( &s_double, &x_double, &pr, &ompr, &cdf_compute, &ccdf_compute );

    printf ( "  %10d  %10d  %10g  %10g  %10g\n",
      s, x, pr, cdf_lookup, cdf_compute );
  }

  printf ( "\n" );
  printf ( "   X   S    Pr       1-CDF         CCDF\n" );
  printf ( "                    (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    binomial_cdf_values ( &n_data, &x, &pr, &s, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    ompr = 1.0 - pr;

    s_double = ( double ) s;
    x_double = ( double ) x;

    cumbin ( &s_double, &x_double, &pr, &ompr, &cdf_compute, &ccdf_compute );

    printf ( "  %10d  %10d  %10g  %10g  %10g\n",
      s, x, pr, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void cumchi_test ( )

/******************************************************************************/
/*
  Purpose:

    cumchi_test tests CUMCHI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int df;
  double df_double;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "cumchi_test\n" );
  printf ( "  CUMCHI computes the chi square CDF\n" );
  printf ( "  and the complementary CDF.\n" );
  printf ( "  CHI_SQUARE_CDF_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    X       DF    CDF           CDF\n" );
  printf ( "                 (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    chi_square_cdf_values ( &n_data, &df, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    df_double = ( double ) df;

    cumchi ( &x, &df_double, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10d  %10g  %10g\n",
      x, df, cdf_lookup, cdf_compute );
  }

  printf ( "\n" );
  printf ( "    X       DF    1-CDF         CCDF\n" );
  printf ( "                 (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    chi_square_cdf_values ( &n_data, &df, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    df_double = ( double ) df;

    cumchi ( &x, &df_double, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10d  %10g  %10g\n",
      x, df, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void cumchn_test ( )

/******************************************************************************/
/*
  Purpose:

    cumchn_test tests CUMCHN.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int df;
  double df_double;
  double lambda;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "cumchn_test\n" );
  printf ( "  CUMCHN computes the cumulative density\n" );
  printf ( "  function for the noncentral chi-squared\n" );
  printf ( "  distribution.\n" );
  printf ( "  CHI_NONCENTRAL_CDF_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    DF    Lambda    X         CDF           CDF\n" );
  printf ( "                             (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    chi_noncentral_cdf_values ( &n_data, &x, &lambda, &df, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    df_double = ( double ) df;

    cumchn ( &x, &df_double, &lambda, &cdf_compute, &ccdf_compute );

    printf ( "  %10d  %10g  %10g  %10g  %10g\n",
      df, lambda, x, cdf_lookup, cdf_compute );
  }

  printf ( "\n" );
  printf ( "    DF    Lambda    X         1-CDF         CCDF\n" );
  printf ( "                             (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    chi_noncentral_cdf_values ( &n_data, &x, &lambda, &df, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    df_double = ( double ) df;

    cumchn ( &x, &df_double, &lambda, &cdf_compute, &ccdf_compute );

    printf ( "  %10d  %10g  %10g  %10g  %10g\n",
      df, lambda, x, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void cumf_test ( )

/******************************************************************************/
/*
  Purpose:

    cumf_test tests CUMF.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int dfd;
  double dfd_double;
  int dfn;
  double dfn_double;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "cumf_test\n" );
  printf ( "  CUMF computes the F CDF\n" );
  printf ( "  and the complementary CDF.\n" );
  printf ( "  F_CDF_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    X      DFN DFD    CDF           CDF\n" );
  printf ( "                     (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    f_cdf_values ( &n_data, &dfn, &dfd, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    dfn_double = ( double ) dfn;
    dfd_double = ( double ) dfd;

    cumf ( &x, &dfn_double, &dfd_double, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10d  %10d  %10g  %10g\n",
      x, dfn, dfd, cdf_lookup, cdf_compute );

  }

  printf ( "\n" );
  printf ( "    X      DFN DFD    1-CDF         CCDF\n" );
  printf ( "                     (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    f_cdf_values ( &n_data, &dfn, &dfd, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    dfn_double = ( double ) dfn;
    dfd_double = ( double ) dfd;

    cumf ( &x, &dfn_double, &dfd_double, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10d  %10d  %10g  %10g\n",
      x, dfn, dfd, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void cumfnc_test ( )

/******************************************************************************/
/*
  Purpose:

    cumfnc_test tests CUMFNC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int dfd;
  double dfd_double;
  int dfn;
  double dfn_double;
  double lambda;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "cumfnc_test\n" );
  printf ( "  CUMFNC computes the noncentral F CDF\n" );
  printf ( "  and the complementary CDF.\n" );
  printf ( "  F_NONCENTRAL_CDF_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    X      DFN DFD    LAMBDA    CDF           CDF\n" );
  printf ( "                               (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    f_noncentral_cdf_values ( &n_data, &dfn, &dfd, &lambda, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    dfn_double = ( double ) dfn;
    dfd_double = ( double ) dfd;

    cumfnc ( &x, &dfn_double, &dfd_double, &lambda, &cdf_compute,
      &ccdf_compute );

    printf ( "  %10g  %10d  %10d  %10g  %10g  %10g\n",
      x, dfn, dfd, lambda, cdf_lookup, cdf_compute );
  }

  printf ( "\n" );
  printf ( "    X      DFN DFD    LAMBDA    1-CDF         CCDF\n" );
  printf ( "                               (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    f_noncentral_cdf_values ( &n_data, &dfn, &dfd, &lambda, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    dfn_double = ( double ) dfn;
    dfd_double = ( double ) dfd;

    cumfnc ( &x, &dfn_double, &dfd_double, &lambda, &cdf_compute,
      &ccdf_compute );

    printf ( "  %10g  %10d  %10d  %10g  %10g  %10g\n",
      x, dfn, dfd, lambda, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void cumgam_test ( )

/******************************************************************************/
/*
  Purpose:

    cumgam_test tests CUMGAM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double a;
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "cumgam_test\n" );
  printf ( "  CUMGAM computes the Gamma CDF\n" );
  printf ( "  and the complementary CDF.\n" );
  printf ( "  GAMMA_INC_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    A         X         CDF           CDF\n" );
  printf ( "                        (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gamma_inc_values ( &n_data, &a, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    cumgam ( &x, &a, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10g  %10g  %10g\n",
      a, x, cdf_lookup, cdf_compute );
  }

  printf ( "\n" );
  printf ( "    A         X         CDF           CDF\n" );
  printf ( "                        (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gamma_inc_values ( &n_data, &a, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    cumgam ( &x, &a, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10g  %10g  %10g\n",
      a, x, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void cumnbn_test ( )

/******************************************************************************/
/*
  Purpose:

    cumnbn_test() tests cumnbn().

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int f;
  double f_double;
  int n_data;
  double ompr;
  int s;
  double s_double;
  double pr;

  printf ( "\n" );
  printf ( "cumnbn_test():\n" );
  printf ( "  cumnbn() computes the Negative Binomial CDF.\n" );
  printf ( "  negative_binomial_cdf_values() looks up some values.\n" );
  printf ( "\n" );
  printf ( "   F   S    Pr       CDF           CDF\n" );
  printf ( "                     (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    negative_binomial_cdf_values ( &n_data, &f, &s, &pr, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ompr = 1.0 - pr;

    f_double = ( double ) f;
    s_double = ( double ) s;

    cumnbn ( &f_double, &s_double, &pr, &ompr, &cdf_compute, &ccdf_compute );

    printf ( "  %10d  %10d  %10g  %10g  %10g\n",
      f, s, pr, cdf_lookup, cdf_compute );
  }

  printf ( "\n" );
  printf ( "   F   S    Pr       1-CDF         CCDF\n" );
  printf ( "                     (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    negative_binomial_cdf_values ( &n_data, &f, &s, &pr, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    ompr = 1.0 - pr;

    f_double = ( double ) f;
    s_double = ( double ) s;

    cumnbn ( &f_double, &s_double, &pr, &ompr, &cdf_compute, &ccdf_compute );

    printf ( "  %10d  %10d  %10g  %10g  %10g\n",
      f, s, pr, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void cumnor_test ( )

/******************************************************************************/
/*
  Purpose:

    cumnor_test tests CUMNOR.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "cumnor_test\n" );
  printf ( "  CUMNOR computes the Normal CDF\n" );
  printf ( "  and the complementary CDF.\n" );
  printf ( "  NORMAL_CDF_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    X         CDF           CDF\n" );
  printf ( "              (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    normal_cdf_values ( &n_data, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    cumnor ( &x, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10g  %10g\n",
      x, cdf_lookup, cdf_compute );
  }

  printf ( "\n" );
  printf ( "    X         1-CDF         CCDF\n" );
  printf ( "              (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    normal_cdf_values ( &n_data, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    cumnor ( &x, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10g  %10g\n",
      x, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void cumpoi_test ( )

/******************************************************************************/
/*
  Purpose:

    cumpoi_test tests CUMPOI, POISSON_CDF_VALUES.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double  cdf_lookup;
  double lambda;
  int n_data;
  int x;
  double x_double;

  printf ( "\n" );
  printf ( "cumpoi_test\n" );
  printf ( "  CUMPOI computes the Poisson CDF\n" );
  printf ( "  and the complementary CDF.\n" );
  printf ( "  POISSON_CDF_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "     X    LAMBDA    CDF           CDF\n" );
  printf ( "                   (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    poisson_cdf_values ( &n_data, &lambda, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    x_double = ( double ) x;

    cumpoi ( &x_double, &lambda, &cdf_compute, &ccdf_compute );

    printf ( "  %10d  %10g  %10g  %10g\n",
      x, lambda, cdf_lookup, cdf_compute );
  }

  printf ( "\n" );
  printf ( "     X    LAMBDA    1-CDF         CCDF\n" );
  printf ( "                   (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    poisson_cdf_values ( &n_data, &lambda, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    x_double = ( double ) x;
    ccdf_lookup = 1.0 - cdf_lookup;

    cumpoi ( &x_double, &lambda, &cdf_compute, &ccdf_compute );

    printf ( "  %10d  %10g  %10g  %10g\n",
      x, lambda, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void cumt_test ( )

/******************************************************************************/
/*
  Purpose:

    cumt_test tests CUMT.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int df;
  double df_double;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "cumt_test\n" );
  printf ( "  CUMT computes the Student T CDF\n" );
  printf ( "  and the complementary CDF.\n" );
  printf ( "  STUDENT_CDF_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    X       DF    CDF           CDF\n" );
  printf ( "                 (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    student_cdf_values ( &n_data, &df, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }
    df_double = ( double ) df;

    cumt ( &x, &df_double, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10d  %10g  %10g\n",
      x, df, cdf_lookup, cdf_compute );
  }

  printf ( "\n" );
  printf ( "    X       DF    1-CDF         CCDF\n" );
  printf ( "                 (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    student_cdf_values ( &n_data, &df, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    df_double = ( double ) df;

    cumt ( &x, &df_double, &cdf_compute, &ccdf_compute );

    printf ( "  %10g  %10d  %10g  %10g\n",
      x, df, ccdf_lookup, ccdf_compute );
  }

  return;
}
/******************************************************************************/

void error_f_test ( )

/******************************************************************************/
/*
  Purpose:

    error_f_test tests ERROR_F, ERROR_FC, ERF_VALUES..

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 November 2006

  Author:

    John Burkardt
*/
{
  double erf_compute;
  double erf_lookup;
  double erfc_compute;
  double erfc_lookup;
  int ind;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "error_f_test\n" );
  printf ( "  ERROR_F computes the error function ERF;\n" );
  printf ( "  ERROR_FC the complementary error function ERFC.\n" );
  printf ( "  ERF_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    X         ERF           ERF\n" );
  printf ( "              (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    erf_values ( &n_data, &x, &erf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    erf_compute = error_f ( &x );

    printf ( "  %10g  %10g  %10g\n",
      x, erf_lookup, erf_compute );
  }

  printf ( "\n" );
  printf ( "    X         ERFC          ERFC\n" );
  printf ( "              (Lookup)      (Computed)\n" );
  printf ( "\n" );

  ind = 0;
  n_data = 0;

  for ( ; ; )
  {
    erf_values ( &n_data, &x, &erf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    erfc_lookup = 1.0 - erf_lookup;
    erfc_compute = error_fc ( &ind, &x );

    printf ( "  %10g  %10g  %10g\n",
      x, erfc_lookup, erfc_compute );
  }

  return;
}
/******************************************************************************/

void gamma_x_test ( )

/******************************************************************************/
/*
  Purpose:

    gamma_x_test tests GAMMA_X.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double tgamma_compute;
  double gamma_lookup;
  double gamma_x_compute;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "gamma_x_test\n" );
  printf ( "  GAMMA_X computes the Gamma function;\n" );
  printf ( "  tgamma() computes the Gamma function (math library);\n" );
  printf ( "  GAMMA_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    X         GAMMA         tgamma         GAMMA_X\n" );
  printf ( "              (Lookup)                    (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    gamma_values ( &n_data, &x, &gamma_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    tgamma_compute = tgamma ( x );

    gamma_x_compute = gamma_x ( &x );

    printf ( "  %10g  %10g  %10g  %10g\n",
      x, gamma_lookup, tgamma_compute, gamma_x_compute );
  }

  return;
}
/******************************************************************************/

void gamma_inc_test ( )

/******************************************************************************/
/*
  Purpose:

    gamma_inc_test tests GAMMA_INC, GAMMA_INC_INV.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double a;
  int i;
  int ierror;
  int ind;
  double p;
  double q;
  int test_num = 10;
  double x;
  double x0;
  double x2;

  a = 3.0;
  ind = 1;
  x0 = 0;

  printf ( "\n" );
  printf ( "gamma_inc_test\n" );
  printf ( "  GAMMA_INC evaluates the incomplete Gamma ratio;\n" );
  printf ( "  GAMMA_INC_INV inverts it.\n" );
  printf ( "\n" );
  printf ( "  Parameters:\n" );
  printf ( "\n" );
  printf ( "    A = %g\n", a );
  printf ( "\n" );
  printf ( "    X             P             Q             Inverse\n" );
  printf ( "\n" );

  for ( i = 0; i <= test_num; i++ )
  {
    x = ( double ) i / ( double ) test_num;

    gamma_inc ( &a, &x, &p, &q, &ind );

    gamma_inc_inv ( &a, &x2, &x0, &p, &q, &ierror );

    printf ( "  %10g  %10g  %10g  %10g\n",
      x, p, q, x2 );
  }

  return;
}
/******************************************************************************/

void psi_test ( )

/******************************************************************************/
/*
  Purpose:

    psi_test tests PSI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 April 2007

  Author:

    John Burkardt
*/
{
  double psi_compute;
  double psi_lookup;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "psi_test\n" );
  printf ( "  PSI computes the Psi function;\n" );
  printf ( "  PSI_VALUES looks up some values.\n" );
  printf ( "\n" );
  printf ( "    X         PSI           PSI\n" );
  printf ( "              (Lookup)      (Computed)\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    psi_values ( &n_data, &x, &psi_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    psi_compute = psi ( &x );

    printf ( "  %10g  %10g  %10g\n",
      x, psi_lookup, psi_compute );
  }

  return;
}
