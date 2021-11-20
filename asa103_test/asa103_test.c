# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "asa103.h"

int main ( );
void digamma_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ASA103_TEST.

  Discussion:

    ASA103_TEST tests the ASA103 library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2010

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ASA103_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the ASA103 library.\n" );

  digamma_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ASA103_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void digamma_test ( )

/******************************************************************************/
/*
  Purpose:

    DIGAMMA_TEST tests DIGAMMA.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    04 November 2010

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  int ifault;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "DIGAMMA_TEST:\n" );
  printf ( "  DIGAMMA computes the Digama or Psi function. \n" );
  printf ( "  Compare the result to tabulated values.\n" );
  printf ( "\n" );
  printf ( "          X       " );
  printf ( "FX                        FX2\n" );
  printf ( "                  " );
  printf ( "(Tabulated)               (DIGAMMA)                DIFF\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    psi_values ( &n_data, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = digamma ( x, &ifault );

    printf ( "  %10.4g  %24.16g  %24.16g  %10.4e\n",
      x, fx, fx2, fabs ( fx - fx2 ) );
  }

  return;
}
