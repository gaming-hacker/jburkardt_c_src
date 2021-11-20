# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "asa226.h"

int main ( );
void test01 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ASA226_TEST.

  Discussion:

    ASA226_TEST tests the ASA226 library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 November 2010

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ASA226_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the ASA226 library.\n" );

  test01 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ASA226_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( )

/******************************************************************************/
/*
  Purpose:

    TEST01 demonstrates the use of BETANC.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    13 November 2010

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double fx;
  double fx2;
  int ifault;
  double lambda;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "TEST01:\n" );
  printf ( "  BETANC computes the noncentral incomplete Beta function.\n" );
  printf ( "  Compare to tabulated values.\n" );
  printf ( "\n" );
  printf ( "      A        B     LAMBDA        X      " );
  printf ( "    FX                        FX2\n" );
  printf ( "                                          " );
  printf ( "    (Tabulated)               (BETANC)            DIFF\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    beta_noncentral_cdf_values ( &n_data, &a, &b, &lambda, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = betanc ( x, a, b, lambda, &ifault );

    printf ( "  %7.2f  %7.2f  %7.2f  %10.4f  %24.16g  %24.16g  %10.4e\n",
      a, b, lambda, x, fx, fx2, fabs ( fx - fx2 ) );
  }

  return;
}
