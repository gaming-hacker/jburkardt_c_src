# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "subset_sum.h"

int main ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for SUBSET_SUM_TEST.

  Discussion:

    SUBSET_SUM_TEST tests the SUBSET_SUM library.

  Licensing:

    I don't care what you do with this code.

  Modified:

    15 July 2017

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "SUBSET_SUM_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the SUBSET_SUM library.\n" );

  subset_sum_count_tests ( );
  subset_sum_find_tests ( );
  subset_sum_next_tests ( );
  subset_sum_table_tests ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SUBSET_SUM_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
