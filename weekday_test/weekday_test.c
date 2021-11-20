# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "weekday.h"

int main ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for WEEKDAY_TEST.

  Discussion:

    WEEKDAY_TEST tests the WEEKDAY library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 May 2012

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "WEEKDAY_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the WEEKDAY library.\n" );

  jed_to_weekday_test ( );
  ymd_to_weekday_common_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "WEEKDAY_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
