# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "grid.h"

int main ( );
void grid_generate_test ( int center, int *seed );
void grid_side_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for GRID_TEST.

  Discussion:

    GRID_TEST tests the GRID library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 August 2016

  Author:

    John Burkardt
*/
{
  int center;
  int seed;

  timestamp ( );
  printf ( "\n" );
  printf ( "GRID_TEST:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the GRID library.\n" );

  center = 1;
  seed = 123456789;

  grid_generate_test ( center, &seed );

  printf ( "\n" );
  printf ( "  Repeat with a different seed from the first run.\n" );

  seed = 987654321;
  grid_generate_test ( center, &seed );

  printf ( "\n" );
  printf ( "  Repeat with the same seed as the first run.\n" );

  seed = 123456789;
  grid_generate_test ( center, &seed );

  printf ( "\n" );
  printf ( "  Repeat with different centering values.\n" );

  for ( center = 1; center <= 5; center ++ )
  {
    seed = 123456789;
    grid_generate_test ( center, &seed );
  }

  grid_side_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "GRID_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void grid_generate_test ( int center, int *seed )

/******************************************************************************/
/*
  Purpose:

    TEST01 tests GRID.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    21 August 2016

  Author:

    John Burkardt
*/
{
  int m = 2;
  int n = 10;
  double *x;

  printf ( "\n" );
  printf ( "GRID_GENERATE_TEST\n" );
  printf ( "  GRID_GENERATE randomly chooses a given number of\n" );
  printf ( "  points on a uniform grid.\n" );
  printf ( "\n" );
  printf ( "  Spatial dimension =  %d\n", m );
  printf ( "  Number of points =   %d\n", n );
  printf ( "  Random number SEED = %d\n", *seed );
  printf ( "  Centering option =   %d\n", center );

  x = grid_generate ( m, n, center, seed );

  r8mat_transpose_print ( m, n, x, "  The grid points:" );

  free ( x );

  return;
}
/******************************************************************************/

void grid_side_test ( )

/******************************************************************************/
/*
  Purpose:

    GRID_SIDE_TEST tests GRID_SIDE.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 August 2016

  Author:

    John Burkardt
*/
{
  int m;
  int n;
  int n_log10;
  int n_side;

  printf ( "\n" );
  printf ( "GRID_SIDE_TEST\n" );
  printf ( "  GRID_SIDE returns the smallest N_SIDE, such that\n" );
  printf ( "  N <= NSIDE^M\n" );

  printf ( "\n" );
  printf ( "  M      N  NSIDE  NSIDE^M\n" );

  for ( m = 2; m <= 4; m++ )
  {
    printf ( "\n" );
    for ( n_log10 = 1; n_log10 <= 4; n_log10++ )
    {
      n = i4_power ( 10, n_log10 );
      n_side = grid_side ( m, n );
      printf ( "  %1d  %5d  %5d  %5d\n", m, n, n_side, i4_power ( n_side, m ) );
    }
  }

  return;
}
