# include <stdio.h>
# include <stdlib.h>

# include "walker_sample.h"

int main ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for WALKER_SAMPLE_TEST.

  Discussion:

    WALKER_SAMPLE_TEST tests WALKER_SAMPLE.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    20 February 2016

  Author:

    John Burkardt
*/
{ 
  timestamp ( );
  printf ( "\n" );
  printf ( "WALKER_SAMPLE_TEST:\n" );
  printf ( "  C version.\n" );
  printf ( "  Test the WALKER_SAMPLE library.\n" );

  walker_sampler_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "WALKER_SAMPLE_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
