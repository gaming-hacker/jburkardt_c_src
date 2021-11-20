# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "asa063.h"

int main ( );
void test01 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ASA063_TEST.

  Discussion:

    ASA063_TEST tests the ASA063 library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 January 2008

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ASA063_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the ASA063 library.\n" );

  test01 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ASA063_TEST:\n" );
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

    TEST01 demonstrates the use of BETAIN.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    25 January 2008

  Author:

    John Burkardt
*/
{
  double a;
  double b;
  double beta_log;
  double fx;
  double fx2;
  int ifault;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "TEST01:\n" );
  printf ( "  BETAIN computes the incomplete Beta function.\n" );
  printf ( "  Compare to tabulated values.\n" );
  printf ( "\n" );
  printf ( "           A           B           X      "  );
  printf ( "    FX                        FX2\n" );
  printf ( "                                          " );
  printf ( "    (Tabulated)               (BETAIN)            DIFF\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    beta_inc_values ( &n_data, &a, &b, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    beta_log = lgamma ( a )
             + lgamma ( b )
             - lgamma ( a + b );

    fx2 = betain ( x, a, b, beta_log, &ifault );

    printf ( "  %10.4g  %10.4g  %10.4g  %24.16g  %24.16g  %10.4e\n",
      a, b, x, fx, fx2, fabs ( fx - fx2 ) );
  }

  return;
}
