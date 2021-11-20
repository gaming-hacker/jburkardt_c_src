# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "legendre_shifted_polynomial.h"

int main ( );
void p01_polynomial_value_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for LEGENDRE_SHIFTED_POLYNOMIAL_TEST.

  Discussion:

    LEGENDRE_SHIFTED_POLYNOMIAL_TEST tests the LEGENDRE_SHIFTED_POLYNOMIAL library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 March 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "LEGENDRE_SHIFTED_POLYNOMIAL_TEST:\n" );
  printf ( "  C version.\n" );
  printf ( "  Test the LEGENDRE_SHIFTED_POLYNOMIAL library.\n" );

  p01_polynomial_value_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "LEGENDRE_SHIFTED_POLYNOMIAL_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void p01_polynomial_value_test ( )

/******************************************************************************/
/*
  Purpose:

    P01_POLYNOMIAL_VALUE_TEST tests P01_POLYNOMIAL_VALUE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 March 2016

  Author:

    John Burkardt
*/
{
  int n_data;
  double e;
  double fx1;
  double fx2;
  double *fx2_vec;
  int n;
  double x;
  double x_vec[1];

  printf ( "\n" );
  printf ( "P01_POLYNOMIAL_VALUE_TEST:\n" );
  printf ( "  P01_POLYNOMIAL_VALUE evaluates the shifted Legendre polynomial P01(n,x).\n" );
  printf ( "\n" );
  printf ( "                        Tabulated                 Computed\n" );
  printf ( "     N        X          P01(N,X)                 P01(N,X)                     Error\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    p01_polynomial_values ( &n_data, &n, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    x_vec[0] = x;
    fx2_vec = p01_polynomial_value ( 1, n, x_vec );
    fx2 = fx2_vec[n];
    free ( fx2_vec );

    e = fx1 - fx2;

    printf ( "  %4d  %12g  %24.16g  %24.16g  %8e\n", n, x, fx1, fx2, e );
  }

  return;
}

