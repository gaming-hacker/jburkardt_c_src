# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "owen.h"

int main ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for OWEN_TEST.

  Discussion:

    OWEN_TEST tests the OWEN library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    14 July 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "OWEN_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the OWEN library.\n" );

  bivnor_test ( );
  t_test ( );
  znorm1_test ( );
  znorm2_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "OWEN_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}

