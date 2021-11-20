# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "asa005.h"

int main ( );
void test01 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ASA005_TEST.

  Discussion:

    ASA005_TEST tests the ASA005 library.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2010

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ASA005_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the ASA005 library.\n" );

  test01 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ASA005_TEST:\n" );
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

    TEST01 demonstrates the use of PRNCST.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    23 October 2010

  Author:

    John Burkardt
*/
{
  int df;
  double fx;
  double fx2;
  int ifault;
  double lambda;
  int n_data;
  double x;

  printf ( "\n" );
  printf ( "TEST01:\n" );
  printf ( "  PRNCST computes the noncentral Student's\n" );
  printf ( "  Cumulative Density Function.\n" );
  printf ( "  Compare to tabulated values.\n" );
  printf ( "\n" );
  printf ( "      X   LAMBDA  DF     " );
  printf ( " CDF                       CDF                     DIFF\n" );
  printf ( "                         " );
  printf ( " Tabulated                 PRNCST\n" );
  printf ( "\n" );

  n_data = 0;

  for ( ; ; )
  {
    student_noncentral_cdf_values ( &n_data, &df, &lambda, &x, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = prncst ( x, df, lambda, &ifault );

    printf ( "  %6.2f  %6.2f  %2d  %24.16f  %24.16f  %10.4e\n",
      x, lambda, df, fx, fx2, fabs ( fx - fx2 ) );
  }

  return;
}
