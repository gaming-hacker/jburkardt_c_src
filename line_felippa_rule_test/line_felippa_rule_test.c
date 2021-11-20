# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "line_felippa_rule.h"

int main ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for LINE_FELIPPA_RULE_TEST.

  Discussion:

    LINE_FELIPPA_RULE_TEST tests the LINE_FELIPPA_RULE library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 September 2014

  Author:

    John Burkardt
*/
{
  int degree_max;

  timestamp ( );
  printf ( "\n" );
  printf ( "LINE_FELIPPA_RULE_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the LINE_FELIPPA_RULE library.\n" );

  degree_max = 4;
  line_monomial_test ( degree_max );

  degree_max = 11;
  line_quad_test ( degree_max );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "LINE_FELIPPA_RULE_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
