# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "clausen.h"

int main ( );
void clausen_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for CLAUSEN_TEST.

  Discussion:

    CLAUSEN_TEST tests the CLAUSEN library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    12 December 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "CLAUSEN_TEST:\n" );
  printf ( "  C version,\n" );
  printf ( "  Test the CLAUSEN library.\n" );

  clausen_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "CLAUSEN_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void clausen_test ( )

/******************************************************************************/
/*
  Purpose:

    CLAUSEN_TEST compares the CLAUSEN function to some tabulated values.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 December 2016

  Author:

    John Burkardt
*/
{
  double diff;
  double fx1;
  double fx2;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "CLAUSEN_TEST:\n" );
  printf ( "  CLAUSEN evaluates the Clausen function.\n" );
  printf ( "  Compare its results to tabulated data.\n" );
  printf ( "\n" );
  printf ( "                               Tabulated               Computed\n" );
  printf ( "           X                          FX                     FX        Diff\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    clausen_values ( &n_data, &x, &fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = clausen ( x );

    diff = fabs ( fx1 - fx2 );

    printf ( "  %12.6f  %24.16g  %24.16g  %6.1e\n", x, fx1, fx2, diff );
  }
  return;
}
