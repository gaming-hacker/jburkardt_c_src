# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "random_sorted.h"

int main ( );
void r8vec_normal_01_sorted_test ( );
void r8vec_uniform_01_test ( );
void r8vec_uniform_01_sorted1_test ( );
void r8vec_uniform_01_sorted2_test ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    RANDOM_SORTED_TEST tests the RANDOM_SORTED library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2016

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "RANDOM_SORTED_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  Test the RANDOM_SORTED library.\n" );

  r8vec_normal_01_sorted_test ( );
  r8vec_uniform_01_test ( );
  r8vec_uniform_01_sorted1_test ( );
  r8vec_uniform_01_sorted2_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "RANDOM_SORTED_TEST:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void r8vec_normal_01_sorted_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_NORMAL_01_SORTED_TEST tests R8VEC_NORMAL_01_SORTED_TEST,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 March 2016

  Author:

    John Burkardt
*/
{
  int i;
  int n = 5;
  double *r8vec;
  int seed;

  printf ( "\n" );
  printf ( "R8VEC_NORMAL_01_SORTED_TEST:\n" );
  printf ( "  R8VEC_NORMAL_01_SORTED generates a vector of N normal 01\n" );
  printf ( "  random values in ascending sorted order.\n" );
  printf ( "\n" );
  printf ( "  Generate several examples:\n" );
  printf ( "\n" );

  seed = 123456789;

  for ( i = 1; i <= 10; i++ )
  {
    r8vec = r8vec_normal_01_sorted ( n, &seed );
    r8vec_transpose_print ( n, r8vec, "  R8VEC:" );
    free ( r8vec );
  }

  return;
}
/******************************************************************************/

void r8vec_uniform_01_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_TEST tests R8VEC_UNIFORM_01.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2016

  Author:

    John Burkardt
*/
{
  int i;
  int n = 10;
  double *r8vec;
  int seed;

  printf ( "\n" );
  printf ( "R8VEC_UNIFORM_01_TEST\n" );
  printf ( "  R8VEC_UNIFORM_01 returns a random R8VEC\n" );
  printf ( "  with entries in [ 0.0, 1.0 ]\n" );

  seed = 123456789;

  for ( i = 1; i <= 3; i++ )
  {
    printf ( "\n" );
    printf ( "  Input SEED = %d\n", seed );
    r8vec = r8vec_uniform_01_new ( n, &seed );
    r8vec_print ( n, r8vec, "  Random R8VEC:" );
    free ( r8vec );
  }

  return;
}
/******************************************************************************/

void r8vec_uniform_01_sorted1_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_SORTED1_TEST tests R8VEC_UNIFORM_01_SORTED1_TEST,

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2016

  Author:

    John Burkardt
*/
{
  int i;
  int n = 5;
  double *r8vec;
  int seed;

  printf ( "\n" );
  printf ( "R8VEC_UNIFORM_01_SORTED1_TEST:\n" );
  printf ( "  R8VEC_UNIFORM_01_SORTED1 generates a vector of N random\n" );
  printf ( "  values in ascending sorted order.\n" );
  printf ( "\n" );
  printf ( "  Generate several examples:\n" );
  printf ( "\n" );

  seed = 123456789;

  for ( i = 1; i <= 10; i++ )
  {
    r8vec = r8vec_uniform_01_sorted1 ( n, &seed );
    r8vec_transpose_print ( n, r8vec, "  R8VEC:" );
    free ( r8vec );
  }

  return;
}
/******************************************************************************/

void r8vec_uniform_01_sorted2_test ( )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_SORTED2_TEST tests R8VEC_UNIFORM_01_SORTED2_TEST.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    29 March 2016

  Author:

    John Burkardt
*/
{
  int i;
  int n = 5;
  double *r8vec;
  int seed;

  printf ( "\n" );
  printf ( "R8VEC_UNIFORM_01_SORTED2_TEST:\n" );
  printf ( "  R8VEC_UNIFORM_01_SORTED2 generates a vector of N random\n" );
  printf ( "  values in ascending sorted order.\n" );
  printf ( "\n" );
  printf ( "  Generate several examples:\n" );
  printf ( "\n" );

  seed = 123456789;

  for ( i = 1; i <= 10; i++ )
  {
    r8vec = r8vec_uniform_01_sorted2 ( n, &seed );
    r8vec_transpose_print ( n, r8vec, "  R8VEC:" );
    free ( r8vec );
  }

  return;
}
