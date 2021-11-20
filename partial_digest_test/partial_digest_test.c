# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "partial_digest.h"

int main ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for PARTIAL_DIGEST_TEST.

  Discussion:

    PARTIAL_DIGEST_TEST tests PARTIAL_DIGEST.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 January 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "PARTIAL_DIGEST_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test PARTIAL_DIGEST.\n" );

  find_distances_test ( );
  i4_uniform_ab_test ( );
  i4vec_max_last_test ( );
  i4vec_print_test ( );
  partial_digest_recur_test01 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "PARTIAL_DIGEST_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
